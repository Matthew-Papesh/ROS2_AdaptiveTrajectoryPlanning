// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice
#include "navigation_interfaces/srv/detail/spline__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "navigation_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "navigation_interfaces/srv/detail/spline__struct.h"
#include "navigation_interfaces/srv/detail/spline__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "nav_msgs/msg/detail/path__functions.h"  // waypoints_path

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_serialize_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_deserialize_nav_msgs__msg__Path(
  eprosima::fastcdr::Cdr & cdr,
  nav_msgs__msg__Path * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t max_serialized_size_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_serialize_key_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t get_serialized_size_key_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t max_serialized_size_key_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path)();


using _Spline_Request__ros_msg_type = navigation_interfaces__srv__Spline_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_serialize_navigation_interfaces__srv__Spline_Request(
  const navigation_interfaces__srv__Spline_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: waypoints_path
  {
    cdr_serialize_nav_msgs__msg__Path(
      &ros_message->waypoints_path, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_deserialize_navigation_interfaces__srv__Spline_Request(
  eprosima::fastcdr::Cdr & cdr,
  navigation_interfaces__srv__Spline_Request * ros_message)
{
  // Field name: waypoints_path
  {
    cdr_deserialize_nav_msgs__msg__Path(cdr, &ros_message->waypoints_path);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t get_serialized_size_navigation_interfaces__srv__Spline_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Spline_Request__ros_msg_type * ros_message = static_cast<const _Spline_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: waypoints_path
  current_alignment += get_serialized_size_nav_msgs__msg__Path(
    &(ros_message->waypoints_path), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t max_serialized_size_navigation_interfaces__srv__Spline_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: waypoints_path
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = navigation_interfaces__srv__Spline_Request;
    is_plain =
      (
      offsetof(DataType, waypoints_path) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_serialize_key_navigation_interfaces__srv__Spline_Request(
  const navigation_interfaces__srv__Spline_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: waypoints_path
  {
    cdr_serialize_key_nav_msgs__msg__Path(
      &ros_message->waypoints_path, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t get_serialized_size_key_navigation_interfaces__srv__Spline_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Spline_Request__ros_msg_type * ros_message = static_cast<const _Spline_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: waypoints_path
  current_alignment += get_serialized_size_key_nav_msgs__msg__Path(
    &(ros_message->waypoints_path), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t max_serialized_size_key_navigation_interfaces__srv__Spline_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: waypoints_path
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = navigation_interfaces__srv__Spline_Request;
    is_plain =
      (
      offsetof(DataType, waypoints_path) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Spline_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const navigation_interfaces__srv__Spline_Request * ros_message = static_cast<const navigation_interfaces__srv__Spline_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_navigation_interfaces__srv__Spline_Request(ros_message, cdr);
}

static bool _Spline_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  navigation_interfaces__srv__Spline_Request * ros_message = static_cast<navigation_interfaces__srv__Spline_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_navigation_interfaces__srv__Spline_Request(cdr, ros_message);
}

static uint32_t _Spline_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_navigation_interfaces__srv__Spline_Request(
      untyped_ros_message, 0));
}

static size_t _Spline_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_navigation_interfaces__srv__Spline_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Spline_Request = {
  "navigation_interfaces::srv",
  "Spline_Request",
  _Spline_Request__cdr_serialize,
  _Spline_Request__cdr_deserialize,
  _Spline_Request__get_serialized_size,
  _Spline_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Spline_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Spline_Request,
  get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Request__get_type_hash,
  &navigation_interfaces__srv__Spline_Request__get_type_description,
  &navigation_interfaces__srv__Spline_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Request)() {
  return &_Spline_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "navigation_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "nav_msgs/msg/detail/path__functions.h"  // spline_path
#include "rosidl_runtime_c/primitives_sequence.h"  // cumulative_sd_steps, sd_steps
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // cumulative_sd_steps, sd_steps

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_serialize_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_deserialize_nav_msgs__msg__Path(
  eprosima::fastcdr::Cdr & cdr,
  nav_msgs__msg__Path * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t max_serialized_size_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_serialize_key_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t get_serialized_size_key_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t max_serialized_size_key_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path)();


using _Spline_Response__ros_msg_type = navigation_interfaces__srv__Spline_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_serialize_navigation_interfaces__srv__Spline_Response(
  const navigation_interfaces__srv__Spline_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: spline_path
  {
    cdr_serialize_nav_msgs__msg__Path(
      &ros_message->spline_path, cdr);
  }

  // Field name: sd_steps
  {
    size_t size = ros_message->sd_steps.size;
    auto array_ptr = ros_message->sd_steps.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: cumulative_sd_steps
  {
    size_t size = ros_message->cumulative_sd_steps.size;
    auto array_ptr = ros_message->cumulative_sd_steps.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_deserialize_navigation_interfaces__srv__Spline_Response(
  eprosima::fastcdr::Cdr & cdr,
  navigation_interfaces__srv__Spline_Response * ros_message)
{
  // Field name: spline_path
  {
    cdr_deserialize_nav_msgs__msg__Path(cdr, &ros_message->spline_path);
  }

  // Field name: sd_steps
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->sd_steps.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->sd_steps);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->sd_steps, size)) {
      fprintf(stderr, "failed to create array for field 'sd_steps'");
      return false;
    }
    auto array_ptr = ros_message->sd_steps.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: cumulative_sd_steps
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->cumulative_sd_steps.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->cumulative_sd_steps);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->cumulative_sd_steps, size)) {
      fprintf(stderr, "failed to create array for field 'cumulative_sd_steps'");
      return false;
    }
    auto array_ptr = ros_message->cumulative_sd_steps.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t get_serialized_size_navigation_interfaces__srv__Spline_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Spline_Response__ros_msg_type * ros_message = static_cast<const _Spline_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: spline_path
  current_alignment += get_serialized_size_nav_msgs__msg__Path(
    &(ros_message->spline_path), current_alignment);

  // Field name: sd_steps
  {
    size_t array_size = ros_message->sd_steps.size;
    auto array_ptr = ros_message->sd_steps.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cumulative_sd_steps
  {
    size_t array_size = ros_message->cumulative_sd_steps.size;
    auto array_ptr = ros_message->cumulative_sd_steps.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t max_serialized_size_navigation_interfaces__srv__Spline_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: spline_path
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: sd_steps
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: cumulative_sd_steps
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = navigation_interfaces__srv__Spline_Response;
    is_plain =
      (
      offsetof(DataType, cumulative_sd_steps) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_serialize_key_navigation_interfaces__srv__Spline_Response(
  const navigation_interfaces__srv__Spline_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: spline_path
  {
    cdr_serialize_key_nav_msgs__msg__Path(
      &ros_message->spline_path, cdr);
  }

  // Field name: sd_steps
  {
    size_t size = ros_message->sd_steps.size;
    auto array_ptr = ros_message->sd_steps.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: cumulative_sd_steps
  {
    size_t size = ros_message->cumulative_sd_steps.size;
    auto array_ptr = ros_message->cumulative_sd_steps.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t get_serialized_size_key_navigation_interfaces__srv__Spline_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Spline_Response__ros_msg_type * ros_message = static_cast<const _Spline_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: spline_path
  current_alignment += get_serialized_size_key_nav_msgs__msg__Path(
    &(ros_message->spline_path), current_alignment);

  // Field name: sd_steps
  {
    size_t array_size = ros_message->sd_steps.size;
    auto array_ptr = ros_message->sd_steps.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cumulative_sd_steps
  {
    size_t array_size = ros_message->cumulative_sd_steps.size;
    auto array_ptr = ros_message->cumulative_sd_steps.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t max_serialized_size_key_navigation_interfaces__srv__Spline_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: spline_path
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: sd_steps
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: cumulative_sd_steps
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = navigation_interfaces__srv__Spline_Response;
    is_plain =
      (
      offsetof(DataType, cumulative_sd_steps) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Spline_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const navigation_interfaces__srv__Spline_Response * ros_message = static_cast<const navigation_interfaces__srv__Spline_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_navigation_interfaces__srv__Spline_Response(ros_message, cdr);
}

static bool _Spline_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  navigation_interfaces__srv__Spline_Response * ros_message = static_cast<navigation_interfaces__srv__Spline_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_navigation_interfaces__srv__Spline_Response(cdr, ros_message);
}

static uint32_t _Spline_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_navigation_interfaces__srv__Spline_Response(
      untyped_ros_message, 0));
}

static size_t _Spline_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_navigation_interfaces__srv__Spline_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Spline_Response = {
  "navigation_interfaces::srv",
  "Spline_Response",
  _Spline_Response__cdr_serialize,
  _Spline_Response__cdr_deserialize,
  _Spline_Response__get_serialized_size,
  _Spline_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Spline_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Spline_Response,
  get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Response__get_type_hash,
  &navigation_interfaces__srv__Spline_Response__get_type_description,
  &navigation_interfaces__srv__Spline_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Response)() {
  return &_Spline_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "navigation_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_navigation_interfaces__srv__Spline_Request(
  const navigation_interfaces__srv__Spline_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_navigation_interfaces__srv__Spline_Request(
  eprosima::fastcdr::Cdr & cdr,
  navigation_interfaces__srv__Spline_Request * ros_message);

size_t get_serialized_size_navigation_interfaces__srv__Spline_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_navigation_interfaces__srv__Spline_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_navigation_interfaces__srv__Spline_Request(
  const navigation_interfaces__srv__Spline_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_navigation_interfaces__srv__Spline_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_navigation_interfaces__srv__Spline_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Request)();

bool cdr_serialize_navigation_interfaces__srv__Spline_Response(
  const navigation_interfaces__srv__Spline_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_navigation_interfaces__srv__Spline_Response(
  eprosima::fastcdr::Cdr & cdr,
  navigation_interfaces__srv__Spline_Response * ros_message);

size_t get_serialized_size_navigation_interfaces__srv__Spline_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_navigation_interfaces__srv__Spline_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_navigation_interfaces__srv__Spline_Response(
  const navigation_interfaces__srv__Spline_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_navigation_interfaces__srv__Spline_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_navigation_interfaces__srv__Spline_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_navigation_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _Spline_Event__ros_msg_type = navigation_interfaces__srv__Spline_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_serialize_navigation_interfaces__srv__Spline_Event(
  const navigation_interfaces__srv__Spline_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_navigation_interfaces__srv__Spline_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_navigation_interfaces__srv__Spline_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_deserialize_navigation_interfaces__srv__Spline_Event(
  eprosima::fastcdr::Cdr & cdr,
  navigation_interfaces__srv__Spline_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      navigation_interfaces__srv__Spline_Request__Sequence__fini(&ros_message->request);
    }
    if (!navigation_interfaces__srv__Spline_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_navigation_interfaces__srv__Spline_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      navigation_interfaces__srv__Spline_Response__Sequence__fini(&ros_message->response);
    }
    if (!navigation_interfaces__srv__Spline_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_navigation_interfaces__srv__Spline_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t get_serialized_size_navigation_interfaces__srv__Spline_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Spline_Event__ros_msg_type * ros_message = static_cast<const _Spline_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_navigation_interfaces__srv__Spline_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_navigation_interfaces__srv__Spline_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t max_serialized_size_navigation_interfaces__srv__Spline_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_navigation_interfaces__srv__Spline_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_navigation_interfaces__srv__Spline_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = navigation_interfaces__srv__Spline_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
bool cdr_serialize_key_navigation_interfaces__srv__Spline_Event(
  const navigation_interfaces__srv__Spline_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_navigation_interfaces__srv__Spline_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_navigation_interfaces__srv__Spline_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t get_serialized_size_key_navigation_interfaces__srv__Spline_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Spline_Event__ros_msg_type * ros_message = static_cast<const _Spline_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_navigation_interfaces__srv__Spline_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_navigation_interfaces__srv__Spline_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_navigation_interfaces
size_t max_serialized_size_key_navigation_interfaces__srv__Spline_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_navigation_interfaces__srv__Spline_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_navigation_interfaces__srv__Spline_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = navigation_interfaces__srv__Spline_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Spline_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const navigation_interfaces__srv__Spline_Event * ros_message = static_cast<const navigation_interfaces__srv__Spline_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_navigation_interfaces__srv__Spline_Event(ros_message, cdr);
}

static bool _Spline_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  navigation_interfaces__srv__Spline_Event * ros_message = static_cast<navigation_interfaces__srv__Spline_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_navigation_interfaces__srv__Spline_Event(cdr, ros_message);
}

static uint32_t _Spline_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_navigation_interfaces__srv__Spline_Event(
      untyped_ros_message, 0));
}

static size_t _Spline_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_navigation_interfaces__srv__Spline_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Spline_Event = {
  "navigation_interfaces::srv",
  "Spline_Event",
  _Spline_Event__cdr_serialize,
  _Spline_Event__cdr_deserialize,
  _Spline_Event__get_serialized_size,
  _Spline_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Spline_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Spline_Event,
  get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Event__get_type_hash,
  &navigation_interfaces__srv__Spline_Event__get_type_description,
  &navigation_interfaces__srv__Spline_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Event)() {
  return &_Spline_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "navigation_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "navigation_interfaces/srv/spline.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Spline__callbacks = {
  "navigation_interfaces::srv",
  "Spline",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline_Response)(),
};

static rosidl_service_type_support_t Spline__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Spline__callbacks,
  get_service_typesupport_handle_function,
  &_Spline_Request__type_support,
  &_Spline_Response__type_support,
  &_Spline_Event__type_support,
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

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, navigation_interfaces, srv, Spline)() {
  return &Spline__handle;
}

#if defined(__cplusplus)
}
#endif
