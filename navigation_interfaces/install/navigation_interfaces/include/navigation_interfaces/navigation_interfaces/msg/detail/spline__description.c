// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice

#include "navigation_interfaces/msg/detail/spline__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
const rosidl_type_hash_t *
navigation_interfaces__msg__Spline__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x93, 0xf0, 0x0a, 0x5b, 0x43, 0xfe, 0xf5, 0xd9,
      0xd7, 0x94, 0x0f, 0x3a, 0xf7, 0xe1, 0x70, 0x99,
      0xf3, 0x2d, 0x12, 0x26, 0x9f, 0xc6, 0xa0, 0x1b,
      0x0a, 0x2f, 0xf2, 0x62, 0xed, 0xfd, 0xc1, 0x4f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char navigation_interfaces__msg__Spline__TYPE_NAME[] = "navigation_interfaces/msg/Spline";

// Define type names, field names, and default values
static char navigation_interfaces__msg__Spline__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field navigation_interfaces__msg__Spline__FIELDS[] = {
  {
    {navigation_interfaces__msg__Spline__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
navigation_interfaces__msg__Spline__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {navigation_interfaces__msg__Spline__TYPE_NAME, 32, 32},
      {navigation_interfaces__msg__Spline__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}


static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
navigation_interfaces__msg__Spline__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {navigation_interfaces__msg__Spline__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
navigation_interfaces__msg__Spline__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *navigation_interfaces__msg__Spline__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
