// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "navigation_interfaces/msg/spline.h"


#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__STRUCT_H_
#define NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Spline in the package navigation_interfaces.
typedef struct navigation_interfaces__msg__Spline
{
  uint8_t structure_needs_at_least_one_member;
} navigation_interfaces__msg__Spline;

// Struct for a sequence of navigation_interfaces__msg__Spline.
typedef struct navigation_interfaces__msg__Spline__Sequence
{
  navigation_interfaces__msg__Spline * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__msg__Spline__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__SPLINE__STRUCT_H_
