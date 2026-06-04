// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/srv/spline.hpp"


#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__STRUCT_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'waypoints_path'
#include "nav_msgs/msg/detail/path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__Spline_Request __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__Spline_Request __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Spline_Request_
{
  using Type = Spline_Request_<ContainerAllocator>;

  explicit Spline_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : waypoints_path(_init)
  {
    (void)_init;
  }

  explicit Spline_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : waypoints_path(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _waypoints_path_type =
    nav_msgs::msg::Path_<ContainerAllocator>;
  _waypoints_path_type waypoints_path;

  // setters for named parameter idiom
  Type & set__waypoints_path(
    const nav_msgs::msg::Path_<ContainerAllocator> & _arg)
  {
    this->waypoints_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::Spline_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::Spline_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__Spline_Request
    std::shared_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__Spline_Request
    std::shared_ptr<navigation_interfaces::srv::Spline_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Spline_Request_ & other) const
  {
    if (this->waypoints_path != other.waypoints_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const Spline_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Spline_Request_

// alias to use template instance with default allocator
using Spline_Request =
  navigation_interfaces::srv::Spline_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces


// Include directives for member types
// Member 'spline_path'
// already included above
// #include "nav_msgs/msg/detail/path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__Spline_Response __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__Spline_Response __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Spline_Response_
{
  using Type = Spline_Response_<ContainerAllocator>;

  explicit Spline_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : spline_path(_init)
  {
    (void)_init;
  }

  explicit Spline_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : spline_path(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _spline_path_type =
    nav_msgs::msg::Path_<ContainerAllocator>;
  _spline_path_type spline_path;
  using _sd_steps_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _sd_steps_type sd_steps;
  using _cumulative_sd_steps_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _cumulative_sd_steps_type cumulative_sd_steps;

  // setters for named parameter idiom
  Type & set__spline_path(
    const nav_msgs::msg::Path_<ContainerAllocator> & _arg)
  {
    this->spline_path = _arg;
    return *this;
  }
  Type & set__sd_steps(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->sd_steps = _arg;
    return *this;
  }
  Type & set__cumulative_sd_steps(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->cumulative_sd_steps = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::Spline_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::Spline_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__Spline_Response
    std::shared_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__Spline_Response
    std::shared_ptr<navigation_interfaces::srv::Spline_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Spline_Response_ & other) const
  {
    if (this->spline_path != other.spline_path) {
      return false;
    }
    if (this->sd_steps != other.sd_steps) {
      return false;
    }
    if (this->cumulative_sd_steps != other.cumulative_sd_steps) {
      return false;
    }
    return true;
  }
  bool operator!=(const Spline_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Spline_Response_

// alias to use template instance with default allocator
using Spline_Response =
  navigation_interfaces::srv::Spline_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__Spline_Event __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__Spline_Event __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Spline_Event_
{
  using Type = Spline_Event_<ContainerAllocator>;

  explicit Spline_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Spline_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<navigation_interfaces::srv::Spline_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<navigation_interfaces::srv::Spline_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::Spline_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::Spline_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Spline_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Spline_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__Spline_Event
    std::shared_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__Spline_Event
    std::shared_ptr<navigation_interfaces::srv::Spline_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Spline_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Spline_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Spline_Event_

// alias to use template instance with default allocator
using Spline_Event =
  navigation_interfaces::srv::Spline_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces

namespace navigation_interfaces
{

namespace srv
{

struct Spline
{
  using Request = navigation_interfaces::srv::Spline_Request;
  using Response = navigation_interfaces::srv::Spline_Response;
  using Event = navigation_interfaces::srv::Spline_Event;
};

}  // namespace srv

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__STRUCT_HPP_
