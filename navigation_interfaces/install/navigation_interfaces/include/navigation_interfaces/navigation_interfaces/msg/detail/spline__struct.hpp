// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/msg/spline.hpp"


#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__STRUCT_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__msg__Spline __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__msg__Spline __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Spline_
{
  using Type = Spline_<ContainerAllocator>;

  explicit Spline_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Spline_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::msg::Spline_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::msg::Spline_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::msg::Spline_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::msg::Spline_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__msg__Spline
    std::shared_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__msg__Spline
    std::shared_ptr<navigation_interfaces::msg::Spline_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Spline_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Spline_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Spline_

// alias to use template instance with default allocator
using Spline =
  navigation_interfaces::msg::Spline_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__STRUCT_HPP_
