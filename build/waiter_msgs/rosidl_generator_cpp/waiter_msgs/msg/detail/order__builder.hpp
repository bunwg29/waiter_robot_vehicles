// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from waiter_msgs:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "waiter_msgs/msg/order.hpp"


#ifndef WAITER_MSGS__MSG__DETAIL__ORDER__BUILDER_HPP_
#define WAITER_MSGS__MSG__DETAIL__ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "waiter_msgs/msg/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace waiter_msgs
{

namespace msg
{

namespace builder
{

class Init_Order_note
{
public:
  explicit Init_Order_note(::waiter_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::msg::Order note(::waiter_msgs::msg::Order::_note_type arg)
  {
    msg_.note = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::msg::Order msg_;
};

class Init_Order_item_name
{
public:
  explicit Init_Order_item_name(::waiter_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_note item_name(::waiter_msgs::msg::Order::_item_name_type arg)
  {
    msg_.item_name = std::move(arg);
    return Init_Order_note(msg_);
  }

private:
  ::waiter_msgs::msg::Order msg_;
};

class Init_Order_table_id
{
public:
  Init_Order_table_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_item_name table_id(::waiter_msgs::msg::Order::_table_id_type arg)
  {
    msg_.table_id = std::move(arg);
    return Init_Order_item_name(msg_);
  }

private:
  ::waiter_msgs::msg::Order msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::msg::Order>()
{
  return waiter_msgs::msg::builder::Init_Order_table_id();
}

}  // namespace waiter_msgs

#endif  // WAITER_MSGS__MSG__DETAIL__ORDER__BUILDER_HPP_
