// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "navigation_interfaces/msg/detail/spline__rosidl_typesupport_introspection_c.h"
#include "navigation_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "navigation_interfaces/msg/detail/spline__functions.h"
#include "navigation_interfaces/msg/detail/spline__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navigation_interfaces__msg__Spline__init(message_memory);
}

void navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_fini_function(void * message_memory)
{
  navigation_interfaces__msg__Spline__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__msg__Spline, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_members = {
  "navigation_interfaces__msg",  // message namespace
  "Spline",  // message name
  1,  // number of fields
  sizeof(navigation_interfaces__msg__Spline),
  false,  // has_any_key_member_
  navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_member_array,  // message members
  navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_init_function,  // function to initialize message memory (memory has to be allocated)
  navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_type_support_handle = {
  0,
  &navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_members,
  get_message_typesupport_handle_function,
  &navigation_interfaces__msg__Spline__get_type_hash,
  &navigation_interfaces__msg__Spline__get_type_description,
  &navigation_interfaces__msg__Spline__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navigation_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, msg, Spline)() {
  if (!navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_type_support_handle.typesupport_identifier) {
    navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &navigation_interfaces__msg__Spline__rosidl_typesupport_introspection_c__Spline_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
