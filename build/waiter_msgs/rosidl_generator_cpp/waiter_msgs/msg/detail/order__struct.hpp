// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from waiter_msgs:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "waiter_msgs/msg/order.hpp"


#ifndef WAITER_MSGS__MSG__DETAIL__ORDER__STRUCT_HPP_
#define WAITER_MSGS__MSG__DETAIL__ORDER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__waiter_msgs__msg__Order __attribute__((deprecated))
#else
# define DEPRECATED__waiter_msgs__msg__Order __declspec(deprecated)
#endif

namespace waiter_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Order_
{
  using Type = Order_<ContainerAllocator>;

  explicit Order_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_id = 0l;
      this->item_name = "";
      this->note = "";
    }
  }

  explicit Order_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : item_name(_alloc),
    note(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_id = 0l;
      this->item_name = "";
      this->note = "";
    }
  }

  // field types and members
  using _table_id_type =
    int32_t;
  _table_id_type table_id;
  using _item_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _item_name_type item_name;
  using _note_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _note_type note;

  // setters for named parameter idiom
  Type & set__table_id(
    const int32_t & _arg)
  {
    this->table_id = _arg;
    return *this;
  }
  Type & set__item_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->item_name = _arg;
    return *this;
  }
  Type & set__note(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->note = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    waiter_msgs::msg::Order_<ContainerAllocator> *;
  using ConstRawPtr =
    const waiter_msgs::msg::Order_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<waiter_msgs::msg::Order_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<waiter_msgs::msg::Order_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      waiter_msgs::msg::Order_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<waiter_msgs::msg::Order_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      waiter_msgs::msg::Order_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<waiter_msgs::msg::Order_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<waiter_msgs::msg::Order_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<waiter_msgs::msg::Order_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__waiter_msgs__msg__Order
    std::shared_ptr<waiter_msgs::msg::Order_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__waiter_msgs__msg__Order
    std::shared_ptr<waiter_msgs::msg::Order_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Order_ & other) const
  {
    if (this->table_id != other.table_id) {
      return false;
    }
    if (this->item_name != other.item_name) {
      return false;
    }
    if (this->note != other.note) {
      return false;
    }
    return true;
  }
  bool operator!=(const Order_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Order_

// alias to use template instance with default allocator
using Order =
  waiter_msgs::msg::Order_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace waiter_msgs

#endif  // WAITER_MSGS__MSG__DETAIL__ORDER__STRUCT_HPP_
