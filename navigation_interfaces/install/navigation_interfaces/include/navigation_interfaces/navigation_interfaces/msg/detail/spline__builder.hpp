// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/msg/spline.hpp"


#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__BUILDER_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "navigation_interfaces/msg/detail/spline__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace navigation_interfaces
{

namespace msg
{


}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::msg::Spline>()
{
  return ::navigation_interfaces::msg::Spline(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__BUILDER_HPP_
