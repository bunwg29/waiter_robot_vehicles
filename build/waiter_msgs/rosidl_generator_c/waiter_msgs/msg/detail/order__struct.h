// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from waiter_msgs:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "waiter_msgs/msg/order.h"


#ifndef WAITER_MSGS__MSG__DETAIL__ORDER__STRUCT_H_
#define WAITER_MSGS__MSG__DETAIL__ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'item_name'
// Member 'note'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Order in the package waiter_msgs.
typedef struct waiter_msgs__msg__Order
{
  int32_t table_id;
  rosidl_runtime_c__String item_name;
  rosidl_runtime_c__String note;
} waiter_msgs__msg__Order;

// Struct for a sequence of waiter_msgs__msg__Order.
typedef struct waiter_msgs__msg__Order__Sequence
{
  waiter_msgs__msg__Order * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__msg__Order__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAITER_MSGS__MSG__DETAIL__ORDER__STRUCT_H_
