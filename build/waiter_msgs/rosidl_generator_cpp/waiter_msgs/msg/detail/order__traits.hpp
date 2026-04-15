// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from waiter_msgs:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "waiter_msgs/msg/order.hpp"


#ifndef WAITER_MSGS__MSG__DETAIL__ORDER__TRAITS_HPP_
#define WAITER_MSGS__MSG__DETAIL__ORDER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "waiter_msgs/msg/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace waiter_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Order & msg,
  std::ostream & out)
{
  out << "{";
  // member: table_id
  {
    out << "table_id: ";
    rosidl_generator_traits::value_to_yaml(msg.table_id, out);
    out << ", ";
  }

  // member: item_name
  {
    out << "item_name: ";
    rosidl_generator_traits::value_to_yaml(msg.item_name, out);
    out << ", ";
  }

  // member: note
  {
    out << "note: ";
    rosidl_generator_traits::value_to_yaml(msg.note, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Order & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: table_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "table_id: ";
    rosidl_generator_traits::value_to_yaml(msg.table_id, out);
    out << "\n";
  }

  // member: item_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "item_name: ";
    rosidl_generator_traits::value_to_yaml(msg.item_name, out);
    out << "\n";
  }

  // member: note
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "note: ";
    rosidl_generator_traits::value_to_yaml(msg.note, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Order & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace waiter_msgs

namespace rosidl_generator_traits
{

[[deprecated("use waiter_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const waiter_msgs::msg::Order & msg,
  std::ostream & out, size_t indentation = 0)
{
  waiter_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use waiter_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const waiter_msgs::msg::Order & msg)
{
  return waiter_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<waiter_msgs::msg::Order>()
{
  return "waiter_msgs::msg::Order";
}

template<>
inline const char * name<waiter_msgs::msg::Order>()
{
  return "waiter_msgs/msg/Order";
}

template<>
struct has_fixed_size<waiter_msgs::msg::Order>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<waiter_msgs::msg::Order>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<waiter_msgs::msg::Order>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAITER_MSGS__MSG__DETAIL__ORDER__TRAITS_HPP_
