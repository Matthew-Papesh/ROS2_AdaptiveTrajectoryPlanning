// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "navigation_interfaces/srv/detail/spline__rosidl_typesupport_introspection_c.h"
#include "navigation_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "navigation_interfaces/srv/detail/spline__functions.h"
#include "navigation_interfaces/srv/detail/spline__struct.h"


// Include directives for member types
// Member `waypoints_path`
#include "nav_msgs/msg/path.h"
// Member `waypoints_path`
#include "nav_msgs/msg/detail/path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navigation_interfaces__srv__Spline_Request__init(message_memory);
}

void navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_fini_function(void * message_memory)
{
  navigation_interfaces__srv__Spline_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_member_array[1] = {
  {
    "waypoints_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Request, waypoints_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_members = {
  "navigation_interfaces__srv",  // message namespace
  "Spline_Request",  // message name
  1,  // number of fields
  sizeof(navigation_interfaces__srv__Spline_Request),
  false,  // has_any_key_member_
  navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_member_array,  // message members
  navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_type_support_handle = {
  0,
  &navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_members,
  get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Request__get_type_hash,
  &navigation_interfaces__srv__Spline_Request__get_type_description,
  &navigation_interfaces__srv__Spline_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navigation_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Request)() {
  navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Path)();
  if (!navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_type_support_handle.typesupport_identifier) {
    navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "navigation_interfaces/srv/detail/spline__rosidl_typesupport_introspection_c.h"
// already included above
// #include "navigation_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.h"


// Include directives for member types
// Member `spline_path`
// already included above
// #include "nav_msgs/msg/path.h"
// Member `spline_path`
// already included above
// #include "nav_msgs/msg/detail/path__rosidl_typesupport_introspection_c.h"
// Member `sd_steps`
// Member `cumulative_sd_steps`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navigation_interfaces__srv__Spline_Response__init(message_memory);
}

void navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_fini_function(void * message_memory)
{
  navigation_interfaces__srv__Spline_Response__fini(message_memory);
}

size_t navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__size_function__Spline_Response__sd_steps(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_const_function__Spline_Response__sd_steps(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_function__Spline_Response__sd_steps(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__fetch_function__Spline_Response__sd_steps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_const_function__Spline_Response__sd_steps(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__assign_function__Spline_Response__sd_steps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_function__Spline_Response__sd_steps(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__resize_function__Spline_Response__sd_steps(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__size_function__Spline_Response__cumulative_sd_steps(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_const_function__Spline_Response__cumulative_sd_steps(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_function__Spline_Response__cumulative_sd_steps(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__fetch_function__Spline_Response__cumulative_sd_steps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_const_function__Spline_Response__cumulative_sd_steps(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__assign_function__Spline_Response__cumulative_sd_steps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_function__Spline_Response__cumulative_sd_steps(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__resize_function__Spline_Response__cumulative_sd_steps(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_member_array[3] = {
  {
    "spline_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Response, spline_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sd_steps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Response, sd_steps),  // bytes offset in struct
    NULL,  // default value
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__size_function__Spline_Response__sd_steps,  // size() function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_const_function__Spline_Response__sd_steps,  // get_const(index) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_function__Spline_Response__sd_steps,  // get(index) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__fetch_function__Spline_Response__sd_steps,  // fetch(index, &value) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__assign_function__Spline_Response__sd_steps,  // assign(index, value) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__resize_function__Spline_Response__sd_steps  // resize(index) function pointer
  },
  {
    "cumulative_sd_steps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Response, cumulative_sd_steps),  // bytes offset in struct
    NULL,  // default value
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__size_function__Spline_Response__cumulative_sd_steps,  // size() function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_const_function__Spline_Response__cumulative_sd_steps,  // get_const(index) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__get_function__Spline_Response__cumulative_sd_steps,  // get(index) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__fetch_function__Spline_Response__cumulative_sd_steps,  // fetch(index, &value) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__assign_function__Spline_Response__cumulative_sd_steps,  // assign(index, value) function pointer
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__resize_function__Spline_Response__cumulative_sd_steps  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_members = {
  "navigation_interfaces__srv",  // message namespace
  "Spline_Response",  // message name
  3,  // number of fields
  sizeof(navigation_interfaces__srv__Spline_Response),
  false,  // has_any_key_member_
  navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_member_array,  // message members
  navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle = {
  0,
  &navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_members,
  get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Response__get_type_hash,
  &navigation_interfaces__srv__Spline_Response__get_type_description,
  &navigation_interfaces__srv__Spline_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navigation_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Response)() {
  navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Path)();
  if (!navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle.typesupport_identifier) {
    navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "navigation_interfaces/srv/detail/spline__rosidl_typesupport_introspection_c.h"
// already included above
// #include "navigation_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "navigation_interfaces/srv/spline.h"
// Member `request`
// Member `response`
// already included above
// #include "navigation_interfaces/srv/detail/spline__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navigation_interfaces__srv__Spline_Event__init(message_memory);
}

void navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_fini_function(void * message_memory)
{
  navigation_interfaces__srv__Spline_Event__fini(message_memory);
}

size_t navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__size_function__Spline_Event__request(
  const void * untyped_member)
{
  const navigation_interfaces__srv__Spline_Request__Sequence * member =
    (const navigation_interfaces__srv__Spline_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_const_function__Spline_Event__request(
  const void * untyped_member, size_t index)
{
  const navigation_interfaces__srv__Spline_Request__Sequence * member =
    (const navigation_interfaces__srv__Spline_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_function__Spline_Event__request(
  void * untyped_member, size_t index)
{
  navigation_interfaces__srv__Spline_Request__Sequence * member =
    (navigation_interfaces__srv__Spline_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__fetch_function__Spline_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const navigation_interfaces__srv__Spline_Request * item =
    ((const navigation_interfaces__srv__Spline_Request *)
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_const_function__Spline_Event__request(untyped_member, index));
  navigation_interfaces__srv__Spline_Request * value =
    (navigation_interfaces__srv__Spline_Request *)(untyped_value);
  *value = *item;
}

void navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__assign_function__Spline_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  navigation_interfaces__srv__Spline_Request * item =
    ((navigation_interfaces__srv__Spline_Request *)
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_function__Spline_Event__request(untyped_member, index));
  const navigation_interfaces__srv__Spline_Request * value =
    (const navigation_interfaces__srv__Spline_Request *)(untyped_value);
  *item = *value;
}

bool navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__resize_function__Spline_Event__request(
  void * untyped_member, size_t size)
{
  navigation_interfaces__srv__Spline_Request__Sequence * member =
    (navigation_interfaces__srv__Spline_Request__Sequence *)(untyped_member);
  navigation_interfaces__srv__Spline_Request__Sequence__fini(member);
  return navigation_interfaces__srv__Spline_Request__Sequence__init(member, size);
}

size_t navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__size_function__Spline_Event__response(
  const void * untyped_member)
{
  const navigation_interfaces__srv__Spline_Response__Sequence * member =
    (const navigation_interfaces__srv__Spline_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_const_function__Spline_Event__response(
  const void * untyped_member, size_t index)
{
  const navigation_interfaces__srv__Spline_Response__Sequence * member =
    (const navigation_interfaces__srv__Spline_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_function__Spline_Event__response(
  void * untyped_member, size_t index)
{
  navigation_interfaces__srv__Spline_Response__Sequence * member =
    (navigation_interfaces__srv__Spline_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__fetch_function__Spline_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const navigation_interfaces__srv__Spline_Response * item =
    ((const navigation_interfaces__srv__Spline_Response *)
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_const_function__Spline_Event__response(untyped_member, index));
  navigation_interfaces__srv__Spline_Response * value =
    (navigation_interfaces__srv__Spline_Response *)(untyped_value);
  *value = *item;
}

void navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__assign_function__Spline_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  navigation_interfaces__srv__Spline_Response * item =
    ((navigation_interfaces__srv__Spline_Response *)
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_function__Spline_Event__response(untyped_member, index));
  const navigation_interfaces__srv__Spline_Response * value =
    (const navigation_interfaces__srv__Spline_Response *)(untyped_value);
  *item = *value;
}

bool navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__resize_function__Spline_Event__response(
  void * untyped_member, size_t size)
{
  navigation_interfaces__srv__Spline_Response__Sequence * member =
    (navigation_interfaces__srv__Spline_Response__Sequence *)(untyped_member);
  navigation_interfaces__srv__Spline_Response__Sequence__fini(member);
  return navigation_interfaces__srv__Spline_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Event, request),  // bytes offset in struct
    NULL,  // default value
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__size_function__Spline_Event__request,  // size() function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_const_function__Spline_Event__request,  // get_const(index) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_function__Spline_Event__request,  // get(index) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__fetch_function__Spline_Event__request,  // fetch(index, &value) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__assign_function__Spline_Event__request,  // assign(index, value) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__resize_function__Spline_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(navigation_interfaces__srv__Spline_Event, response),  // bytes offset in struct
    NULL,  // default value
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__size_function__Spline_Event__response,  // size() function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_const_function__Spline_Event__response,  // get_const(index) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__get_function__Spline_Event__response,  // get(index) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__fetch_function__Spline_Event__response,  // fetch(index, &value) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__assign_function__Spline_Event__response,  // assign(index, value) function pointer
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__resize_function__Spline_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_members = {
  "navigation_interfaces__srv",  // message namespace
  "Spline_Event",  // message name
  3,  // number of fields
  sizeof(navigation_interfaces__srv__Spline_Event),
  false,  // has_any_key_member_
  navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_member_array,  // message members
  navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_type_support_handle = {
  0,
  &navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_members,
  get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Event__get_type_hash,
  &navigation_interfaces__srv__Spline_Event__get_type_description,
  &navigation_interfaces__srv__Spline_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navigation_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Event)() {
  navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Request)();
  navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Response)();
  if (!navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_type_support_handle.typesupport_identifier) {
    navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "navigation_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_members = {
  "navigation_interfaces__srv",  // service namespace
  "Spline",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_Request_message_type_support_handle,
  NULL,  // response message
  // navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle
  NULL  // event_message
  // navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle
};


static rosidl_service_type_support_t navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_type_support_handle = {
  0,
  &navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_members,
  get_service_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Request__rosidl_typesupport_introspection_c__Spline_Request_message_type_support_handle,
  &navigation_interfaces__srv__Spline_Response__rosidl_typesupport_introspection_c__Spline_Response_message_type_support_handle,
  &navigation_interfaces__srv__Spline_Event__rosidl_typesupport_introspection_c__Spline_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    navigation_interfaces,
    srv,
    Spline
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    navigation_interfaces,
    srv,
    Spline
  ),
  &navigation_interfaces__srv__Spline__get_type_hash,
  &navigation_interfaces__srv__Spline__get_type_description,
  &navigation_interfaces__srv__Spline__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navigation_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline)(void) {
  if (!navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_type_support_handle.typesupport_identifier) {
    navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, srv, Spline_Event)()->data;
  }

  return &navigation_interfaces__srv__detail__spline__rosidl_typesupport_introspection_c__Spline_service_type_support_handle;
}
