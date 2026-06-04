// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/srv/spline.hpp"


#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__BUILDER_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "navigation_interfaces/srv/detail/spline__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_Spline_Request_waypoints_path
{
public:
  Init_Spline_Request_waypoints_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navigation_interfaces::srv::Spline_Request waypoints_path(::navigation_interfaces::srv::Spline_Request::_waypoints_path_type arg)
  {
    msg_.waypoints_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::Spline_Request>()
{
  return navigation_interfaces::srv::builder::Init_Spline_Request_waypoints_path();
}

}  // namespace navigation_interfaces


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_Spline_Response_cumulative_sd_steps
{
public:
  explicit Init_Spline_Response_cumulative_sd_steps(::navigation_interfaces::srv::Spline_Response & msg)
  : msg_(msg)
  {}
  ::navigation_interfaces::srv::Spline_Response cumulative_sd_steps(::navigation_interfaces::srv::Spline_Response::_cumulative_sd_steps_type arg)
  {
    msg_.cumulative_sd_steps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Response msg_;
};

class Init_Spline_Response_sd_steps
{
public:
  explicit Init_Spline_Response_sd_steps(::navigation_interfaces::srv::Spline_Response & msg)
  : msg_(msg)
  {}
  Init_Spline_Response_cumulative_sd_steps sd_steps(::navigation_interfaces::srv::Spline_Response::_sd_steps_type arg)
  {
    msg_.sd_steps = std::move(arg);
    return Init_Spline_Response_cumulative_sd_steps(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Response msg_;
};

class Init_Spline_Response_spline_path
{
public:
  Init_Spline_Response_spline_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spline_Response_sd_steps spline_path(::navigation_interfaces::srv::Spline_Response::_spline_path_type arg)
  {
    msg_.spline_path = std::move(arg);
    return Init_Spline_Response_sd_steps(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::Spline_Response>()
{
  return navigation_interfaces::srv::builder::Init_Spline_Response_spline_path();
}

}  // namespace navigation_interfaces


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_Spline_Event_response
{
public:
  explicit Init_Spline_Event_response(::navigation_interfaces::srv::Spline_Event & msg)
  : msg_(msg)
  {}
  ::navigation_interfaces::srv::Spline_Event response(::navigation_interfaces::srv::Spline_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Event msg_;
};

class Init_Spline_Event_request
{
public:
  explicit Init_Spline_Event_request(::navigation_interfaces::srv::Spline_Event & msg)
  : msg_(msg)
  {}
  Init_Spline_Event_response request(::navigation_interfaces::srv::Spline_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Spline_Event_response(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Event msg_;
};

class Init_Spline_Event_info
{
public:
  Init_Spline_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spline_Event_request info(::navigation_interfaces::srv::Spline_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Spline_Event_request(msg_);
  }

private:
  ::navigation_interfaces::srv::Spline_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::Spline_Event>()
{
  return navigation_interfaces::srv::builder::Init_Spline_Event_info();
}

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__BUILDER_HPP_
