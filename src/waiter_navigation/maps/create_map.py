#!/usr/bin/env python3
from pathlib import Path
import struct

W, H = 280, 200
RES = 0.05
OX, OY = -7.0, -5.0

FREE = 254
OCC = 0


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

    fill_rect(grid, -7.05, -5.05, 7.05, -4.95)
    fill_rect(grid, -7.05, 4.95, 7.05, 5.05)
    fill_rect(grid, -7.05, -5.05, -6.95, 5.05)
    fill_rect(grid, 6.95, -5.05, 7.05, 5.05)

    # quầy bếp
    fill_rect(grid, -6.85, -4.65, -5.15, -4.05)

    # vách trắng đã rút ngắn để robot đứng sau vách vẫn chạy ra được
    fill_rect(grid, -5.10, -4.25, -5.00, -3.55)

    tables = [
        (-4.8, 3.0), (-1.6, 3.0), (1.6, 3.0), (4.8, 3.0),
        (-4.8, 0.6), (-1.6, 0.6), (1.6, 0.6), (4.8, 0.6),
    ]

    for tx, ty in tables:
        for dx in [-0.30, 0.30]:
            for dy in [-0.30, 0.30]:
                fill_rect(
                    grid,
                    tx + dx - 0.04,
                    ty + dy - 0.04,
                    tx + dx + 0.04,
                    ty + dy + 0.04
                )

        # ghế sát bàn hơn
        d = 0.62
        chair_r = 0.16

        fill_rect(grid, tx - chair_r, ty + d - chair_r, tx + chair_r, ty + d + chair_r)
        fill_rect(grid, tx - chair_r, ty - d - chair_r, tx + chair_r, ty - d + chair_r)
        fill_rect(grid, tx + d - chair_r, ty - chair_r, tx + d + chair_r, ty + chair_r)
        fill_rect(grid, tx - d - chair_r, ty - chair_r, tx - d + chair_r, ty + chair_r)

    out_dir = Path(__file__).parent
    pgm_path = out_dir / "restaurant.pgm"

    with open(pgm_path, "wb") as f:
        f.write(f"P5\n{W} {H}\n255\n".encode())
        for row in reversed(grid):
            f.write(struct.pack(f"{W}B", *row))

    yaml_path = out_dir / "restaurant.yaml"
    yaml_path.write_text(
        "image: restaurant.pgm\n"
        f"resolution: {RES}\n"
        f"origin: [{OX}, {OY}, 0.0]\n"
        "occupied_thresh: 0.65\n"
        "free_thresh: 0.196\n"
        "negate: 0\n"
    )

    print("Map generated: restaurant.pgm + restaurant.yaml")


if __name__ == "__main__":
    main()