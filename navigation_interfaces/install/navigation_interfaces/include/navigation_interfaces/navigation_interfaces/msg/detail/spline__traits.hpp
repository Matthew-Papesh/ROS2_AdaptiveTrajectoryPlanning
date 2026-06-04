// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/msg/spline.hpp"


#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__TRAITS_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "navigation_interfaces/msg/detail/spline__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace navigation_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Spline & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Spline & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Spline & msg, bool use_flow_style = false)
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

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::msg::Spline & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::msg::Spline & msg)
{
  return navigation_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::msg::Spline>()
{
  return "navigation_interfaces::msg::Spline";
}

template<>
inline const char * name<navigation_interfaces::msg::Spline>()
{
  return "navigation_interfaces/msg/Spline";
}

template<>
struct has_fixed_size<navigation_interfaces::msg::Spline>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<navigation_interfaces::msg::Spline>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<navigation_interfaces::msg::Spline>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__TRAITS_HPP_
