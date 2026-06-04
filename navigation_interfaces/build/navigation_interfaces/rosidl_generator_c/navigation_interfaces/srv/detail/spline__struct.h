// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/srv/spline.h"


#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__STRUCT_H_
#define NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoints_path'
#include "nav_msgs/msg/detail/path__struct.h"

/// Struct defined in srv/Spline in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__Spline_Request
{
  nav_msgs__msg__Path waypoints_path;
} navigation_interfaces__srv__Spline_Request;

// Struct for a sequence of navigation_interfaces__srv__Spline_Request.
typedef struct navigation_interfaces__srv__Spline_Request__Sequence
{
  navigation_interfaces__srv__Spline_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__Spline_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'spline_path'
// already included above
// #include "nav_msgs/msg/detail/path__struct.h"
// Member 'sd_steps'
// Member 'cumulative_sd_steps'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Spline in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__Spline_Response
{
  nav_msgs__msg__Path spline_path;
  rosidl_runtime_c__double__Sequence sd_steps;
  rosidl_runtime_c__double__Sequence cumulative_sd_steps;
} navigation_interfaces__srv__Spline_Response;

// Struct for a sequence of navigation_interfaces__srv__Spline_Response.
typedef struct navigation_interfaces__srv__Spline_Response__Sequence
{
  navigation_interfaces__srv__Spline_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__Spline_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  navigation_interfaces__srv__Spline_Event__request__MAX_SIZE = 1
};
// response
enum
{
  navigation_interfaces__srv__Spline_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Spline in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__Spline_Event
{
  service_msgs__msg__ServiceEventInfo info;
  navigation_interfaces__srv__Spline_Request__Sequence request;
  navigation_interfaces__srv__Spline_Response__Sequence response;
} navigation_interfaces__srv__Spline_Event;

// Struct for a sequence of navigation_interfaces__srv__Spline_Event.
typedef struct navigation_interfaces__srv__Spline_Event__Sequence
{
  navigation_interfaces__srv__Spline_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__Spline_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__SPLINE__STRUCT_H_
