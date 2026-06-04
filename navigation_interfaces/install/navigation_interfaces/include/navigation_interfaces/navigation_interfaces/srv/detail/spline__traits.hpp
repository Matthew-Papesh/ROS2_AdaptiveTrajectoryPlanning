// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/srv/spline.hpp"


#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__TRAITS_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "navigation_interfaces/srv/detail/spline__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints_path'
#include "nav_msgs/msg/detail/path__traits.hpp"

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Spline_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: waypoints_path
  {
    out << "waypoints_path: ";
    to_flow_style_yaml(msg.waypoints_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Spline_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: waypoints_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "waypoints_path:\n";
    to_block_style_yaml(msg.waypoints_path, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Spline_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::srv::Spline_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::Spline_Request & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::Spline_Request>()
{
  return "navigation_interfaces::srv::Spline_Request";
}

template<>
inline const char * name<navigation_interfaces::srv::Spline_Request>()
{
  return "navigation_interfaces/srv/Spline_Request";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Spline_Request>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::Path>::value> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::Spline_Request>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::Path>::value> {};

template<>
struct is_message<navigation_interfaces::srv::Spline_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'spline_path'
// already included above
// #include "nav_msgs/msg/detail/path__traits.hpp"

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Spline_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: spline_path
  {
    out << "spline_path: ";
    to_flow_style_yaml(msg.spline_path, out);
    out << ", ";
  }

  // member: sd_steps
  {
    if (msg.sd_steps.size() == 0) {
      out << "sd_steps: []";
    } else {
      out << "sd_steps: [";
      size_t pending_items = msg.sd_steps.size();
      for (auto item : msg.sd_steps) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: cumulative_sd_steps
  {
    if (msg.cumulative_sd_steps.size() == 0) {
      out << "cumulative_sd_steps: []";
    } else {
      out << "cumulative_sd_steps: [";
      size_t pending_items = msg.cumulative_sd_steps.size();
      for (auto item : msg.cumulative_sd_steps) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Spline_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: spline_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spline_path:\n";
    to_block_style_yaml(msg.spline_path, out, indentation + 2);
  }

  // member: sd_steps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sd_steps.size() == 0) {
      out << "sd_steps: []\n";
    } else {
      out << "sd_steps:\n";
      for (auto item : msg.sd_steps) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: cumulative_sd_steps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cumulative_sd_steps.size() == 0) {
      out << "cumulative_sd_steps: []\n";
    } else {
      out << "cumulative_sd_steps:\n";
      for (auto item : msg.cumulative_sd_steps) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Spline_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::srv::Spline_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::Spline_Response & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::Spline_Response>()
{
  return "navigation_interfaces::srv::Spline_Response";
}

template<>
inline const char * name<navigation_interfaces::srv::Spline_Response>()
{
  return "navigation_interfaces/srv/Spline_Response";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Spline_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::Spline_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navigation_interfaces::srv::Spline_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Spline_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Spline_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Spline_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::srv::Spline_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::Spline_Event & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::Spline_Event>()
{
  return "navigation_interfaces::srv::Spline_Event";
}

template<>
inline const char * name<navigation_interfaces::srv::Spline_Event>()
{
  return "navigation_interfaces/srv/Spline_Event";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Spline_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::Spline_Event>
  : std::integral_constant<bool, has_bounded_size<navigation_interfaces::srv::Spline_Request>::value && has_bounded_size<navigation_interfaces::srv::Spline_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<navigation_interfaces::srv::Spline_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<navigation_interfaces::srv::Spline>()
{
  return "navigation_interfaces::srv::Spline";
}

template<>
inline const char * name<navigation_interfaces::srv::Spline>()
{
  return "navigation_interfaces/srv/Spline";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Spline>
  : std::integral_constant<
    bool,
    has_fixed_size<navigation_interfaces::srv::Spline_Request>::value &&
    has_fixed_size<navigation_interfaces::srv::Spline_Response>::value
  >
{
};

template<>
struct has_bounded_size<navigation_interfaces::srv::Spline>
  : std::integral_constant<
    bool,
    has_bounded_size<navigation_interfaces::srv::Spline_Request>::value &&
    has_bounded_size<navigation_interfaces::srv::Spline_Response>::value
  >
{
};

template<>
struct is_service<navigation_interfaces::srv::Spline>
  : std::true_type
{
};

template<>
struct is_service_request<navigation_interfaces::srv::Spline_Request>
  : std::true_type
{
};

template<>
struct is_service_response<navigation_interfaces::srv::Spline_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__TRAITS_HPP_
