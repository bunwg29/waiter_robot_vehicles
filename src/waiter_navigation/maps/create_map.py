#!/usr/bin/env python3
from pathlib import Path
import struct

W, H = 160, 120
RES = 0.05
OX, OY = -4.0, -3.0

FREE = 254
OCC = 0
UNK = 205

def world_to_pixel(wx, wy):
    return int((wx - OX) / RES), int((wy - OY) / RES)

def fill_rect(grid, x1, y1, x2, y2, val=OCC):
    px1, py1 = world_to_pixel(x1, y1)
    px2, py2 = world_to_pixel(x2, y2)
    px1, px2 = sorted([px1, px2])
    py1, py2 = sorted([py1, py2])
    for y in range(max(0, py1), min(H, py2 + 1)):
        for x in range(max(0, px1), min(W, px2 + 1)):
            grid[y][x] = val

def main():
    grid = [[FREE] * W for _ in range(H)]
    wall_t = 0.1
    # Outer walls
    fill_rect(grid, -4.05, -3.05, 4.05, -3.05 + wall_t)   # South
    fill_rect(grid, -4.05, 3.05 - wall_t, 4.05, 3.05)      # North
    fill_rect(grid, -4.05, -3.05, -4.05 + wall_t, 3.05)     # West
    fill_rect(grid, 4.05 - wall_t, -3.05, 4.05, 3.05)       # East
    # Kitchen counter (unchanged)
    fill_rect(grid, -3.8, -2.5, -2.2, -1.9)
    # Kitchen wall — SHORTENED: pose (-2.1, -1.7), size 0.1 x 0.8
    # spans x: -2.15 to -2.05, y: -2.1 to -1.3
    fill_rect(grid, -2.15, -2.1, -2.05, -1.3)
    # Table legs only (tables are above robot height, only legs matter)
    tables = [(-1.0, 1.5), (2.0, 1.5), (-1.0, -0.3), (2.0, -0.3)]
    leg_off = 0.28
    leg_r = 0.04
    for tx, ty in tables:
        for dx in [-leg_off, leg_off]:
            for dy in [-leg_off, leg_off]:
                lx, ly = tx + dx, ty + dy
                fill_rect(grid, lx - leg_r, ly - leg_r, lx + leg_r, ly + leg_r)
    out_dir = Path(__file__).parent
    pgm_path = out_dir / "restaurant.pgm"
    with open(pgm_path, 'wb') as f:
        header = f"P5\n{W} {H}\n255\n".encode()
        f.write(header)
        for row in reversed(grid):
            f.write(struct.pack(f'{W}B', *row))
    yaml_path = out_dir / "restaurant.yaml"
    yaml_path.write_text(
        f"image: restaurant.pgm\n"
        f"resolution: {RES}\n"
        f"origin: [{OX}, {OY}, 0.0]\n"
        f"occupied_thresh: 0.65\n"
        f"free_thresh: 0.196\n"
        f"negate: 0\n"
    )
    print("Map generated")

if __name__ == "__main__":
    main()
