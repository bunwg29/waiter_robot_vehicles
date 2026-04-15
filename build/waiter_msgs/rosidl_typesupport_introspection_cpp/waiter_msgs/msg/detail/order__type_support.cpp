// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from waiter_msgs:msg/Order.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "waiter_msgs/msg/detail/order__functions.h"
#include "waiter_msgs/msg/detail/order__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace waiter_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Order_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) waiter_msgs::msg::Order(_init);
}

void Order_fini_function(void * message_memory)
{
  auto typed_message = static_cast<waiter_msgs::msg::Order *>(message_memory);
  typed_message->~Order();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Order_message_member_array[3] = {
  {
    "table_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(waiter_msgs::msg::Order, table_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "item_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(waiter_msgs::msg::Order, item_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "note",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(waiter_msgs::msg::Order, note),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Order_message_members = {
  "waiter_msgs::msg",  // message namespace
  "Order",  // message name
  3,  // number of fields
  sizeof(waiter_msgs::msg::Order),
  false,  // has_any_key_member_
  Order_message_member_array,  // message members
  Order_init_function,  // function to initialize message memory (memory has to be allocated)
  Order_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Order_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Order_message_members,
  get_message_typesupport_handle_function,
  &waiter_msgs__msg__Order__get_type_hash,
  &waiter_msgs__msg__Order__get_type_description,
  &waiter_msgs__msg__Order__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace waiter_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<waiter_msgs::msg::Order>()
{
  return &::waiter_msgs::msg::rosidl_typesupport_introspection_cpp::Order_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, waiter_msgs, msg, Order)() {
  return &::waiter_msgs::msg::rosidl_typesupport_introspection_cpp::Order_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
