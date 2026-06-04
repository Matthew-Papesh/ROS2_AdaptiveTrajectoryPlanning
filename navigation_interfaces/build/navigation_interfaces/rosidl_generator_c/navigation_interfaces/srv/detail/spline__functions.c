// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice
#include "navigation_interfaces/srv/detail/spline__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `waypoints_path`
#include "nav_msgs/msg/detail/path__functions.h"

bool
navigation_interfaces__srv__Spline_Request__init(navigation_interfaces__srv__Spline_Request * msg)
{
  if (!msg) {
    return false;
  }
  // waypoints_path
  if (!nav_msgs__msg__Path__init(&msg->waypoints_path)) {
    navigation_interfaces__srv__Spline_Request__fini(msg);
    return false;
  }
  return true;
}

void
navigation_interfaces__srv__Spline_Request__fini(navigation_interfaces__srv__Spline_Request * msg)
{
  if (!msg) {
    return;
  }
  // waypoints_path
  nav_msgs__msg__Path__fini(&msg->waypoints_path);
}

bool
navigation_interfaces__srv__Spline_Request__are_equal(const navigation_interfaces__srv__Spline_Request * lhs, const navigation_interfaces__srv__Spline_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // waypoints_path
  if (!nav_msgs__msg__Path__are_equal(
      &(lhs->waypoints_path), &(rhs->waypoints_path)))
  {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__Spline_Request__copy(
  const navigation_interfaces__srv__Spline_Request * input,
  navigation_interfaces__srv__Spline_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // waypoints_path
  if (!nav_msgs__msg__Path__copy(
      &(input->waypoints_path), &(output->waypoints_path)))
  {
    return false;
  }
  return true;
}

navigation_interfaces__srv__Spline_Request *
navigation_interfaces__srv__Spline_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Request * msg = (navigation_interfaces__srv__Spline_Request *)allocator.allocate(sizeof(navigation_interfaces__srv__Spline_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__Spline_Request));
  bool success = navigation_interfaces__srv__Spline_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__Spline_Request__destroy(navigation_interfaces__srv__Spline_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__Spline_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__Spline_Request__Sequence__init(navigation_interfaces__srv__Spline_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Request * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__Spline_Request *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__Spline_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__Spline_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__Spline_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
navigation_interfaces__srv__Spline_Request__Sequence__fini(navigation_interfaces__srv__Spline_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      navigation_interfaces__srv__Spline_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

navigation_interfaces__srv__Spline_Request__Sequence *
navigation_interfaces__srv__Spline_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Request__Sequence * array = (navigation_interfaces__srv__Spline_Request__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__Spline_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__Spline_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__Spline_Request__Sequence__destroy(navigation_interfaces__srv__Spline_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__Spline_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__Spline_Request__Sequence__are_equal(const navigation_interfaces__srv__Spline_Request__Sequence * lhs, const navigation_interfaces__srv__Spline_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__Spline_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__Spline_Request__Sequence__copy(
  const navigation_interfaces__srv__Spline_Request__Sequence * input,
  navigation_interfaces__srv__Spline_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__Spline_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__Spline_Request * data =
      (navigation_interfaces__srv__Spline_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__Spline_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__Spline_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__Spline_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `spline_path`
// already included above
// #include "nav_msgs/msg/detail/path__functions.h"
// Member `sd_steps`
// Member `cumulative_sd_steps`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
navigation_interfaces__srv__Spline_Response__init(navigation_interfaces__srv__Spline_Response * msg)
{
  if (!msg) {
    return false;
  }
  // spline_path
  if (!nav_msgs__msg__Path__init(&msg->spline_path)) {
    navigation_interfaces__srv__Spline_Response__fini(msg);
    return false;
  }
  // sd_steps
  if (!rosidl_runtime_c__double__Sequence__init(&msg->sd_steps, 0)) {
    navigation_interfaces__srv__Spline_Response__fini(msg);
    return false;
  }
  // cumulative_sd_steps
  if (!rosidl_runtime_c__double__Sequence__init(&msg->cumulative_sd_steps, 0)) {
    navigation_interfaces__srv__Spline_Response__fini(msg);
    return false;
  }
  return true;
}

void
navigation_interfaces__srv__Spline_Response__fini(navigation_interfaces__srv__Spline_Response * msg)
{
  if (!msg) {
    return;
  }
  // spline_path
  nav_msgs__msg__Path__fini(&msg->spline_path);
  // sd_steps
  rosidl_runtime_c__double__Sequence__fini(&msg->sd_steps);
  // cumulative_sd_steps
  rosidl_runtime_c__double__Sequence__fini(&msg->cumulative_sd_steps);
}

bool
navigation_interfaces__srv__Spline_Response__are_equal(const navigation_interfaces__srv__Spline_Response * lhs, const navigation_interfaces__srv__Spline_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // spline_path
  if (!nav_msgs__msg__Path__are_equal(
      &(lhs->spline_path), &(rhs->spline_path)))
  {
    return false;
  }
  // sd_steps
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->sd_steps), &(rhs->sd_steps)))
  {
    return false;
  }
  // cumulative_sd_steps
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->cumulative_sd_steps), &(rhs->cumulative_sd_steps)))
  {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__Spline_Response__copy(
  const navigation_interfaces__srv__Spline_Response * input,
  navigation_interfaces__srv__Spline_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // spline_path
  if (!nav_msgs__msg__Path__copy(
      &(input->spline_path), &(output->spline_path)))
  {
    return false;
  }
  // sd_steps
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->sd_steps), &(output->sd_steps)))
  {
    return false;
  }
  // cumulative_sd_steps
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->cumulative_sd_steps), &(output->cumulative_sd_steps)))
  {
    return false;
  }
  return true;
}

navigation_interfaces__srv__Spline_Response *
navigation_interfaces__srv__Spline_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Response * msg = (navigation_interfaces__srv__Spline_Response *)allocator.allocate(sizeof(navigation_interfaces__srv__Spline_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__Spline_Response));
  bool success = navigation_interfaces__srv__Spline_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__Spline_Response__destroy(navigation_interfaces__srv__Spline_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__Spline_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__Spline_Response__Sequence__init(navigation_interfaces__srv__Spline_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Response * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__Spline_Response *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__Spline_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__Spline_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__Spline_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
navigation_interfaces__srv__Spline_Response__Sequence__fini(navigation_interfaces__srv__Spline_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      navigation_interfaces__srv__Spline_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

navigation_interfaces__srv__Spline_Response__Sequence *
navigation_interfaces__srv__Spline_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Response__Sequence * array = (navigation_interfaces__srv__Spline_Response__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__Spline_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__Spline_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__Spline_Response__Sequence__destroy(navigation_interfaces__srv__Spline_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__Spline_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__Spline_Response__Sequence__are_equal(const navigation_interfaces__srv__Spline_Response__Sequence * lhs, const navigation_interfaces__srv__Spline_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__Spline_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__Spline_Response__Sequence__copy(
  const navigation_interfaces__srv__Spline_Response__Sequence * input,
  navigation_interfaces__srv__Spline_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__Spline_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__Spline_Response * data =
      (navigation_interfaces__srv__Spline_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__Spline_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__Spline_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__Spline_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"

bool
navigation_interfaces__srv__Spline_Event__init(navigation_interfaces__srv__Spline_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    navigation_interfaces__srv__Spline_Event__fini(msg);
    return false;
  }
  // request
  if (!navigation_interfaces__srv__Spline_Request__Sequence__init(&msg->request, 0)) {
    navigation_interfaces__srv__Spline_Event__fini(msg);
    return false;
  }
  // response
  if (!navigation_interfaces__srv__Spline_Response__Sequence__init(&msg->response, 0)) {
    navigation_interfaces__srv__Spline_Event__fini(msg);
    return false;
  }
  return true;
}

void
navigation_interfaces__srv__Spline_Event__fini(navigation_interfaces__srv__Spline_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  navigation_interfaces__srv__Spline_Request__Sequence__fini(&msg->request);
  // response
  navigation_interfaces__srv__Spline_Response__Sequence__fini(&msg->response);
}

bool
navigation_interfaces__srv__Spline_Event__are_equal(const navigation_interfaces__srv__Spline_Event * lhs, const navigation_interfaces__srv__Spline_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!navigation_interfaces__srv__Spline_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!navigation_interfaces__srv__Spline_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
navigation_interfaces__srv__Spline_Event__copy(
  const navigation_interfaces__srv__Spline_Event * input,
  navigation_interfaces__srv__Spline_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!navigation_interfaces__srv__Spline_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!navigation_interfaces__srv__Spline_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

navigation_interfaces__srv__Spline_Event *
navigation_interfaces__srv__Spline_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Event * msg = (navigation_interfaces__srv__Spline_Event *)allocator.allocate(sizeof(navigation_interfaces__srv__Spline_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__srv__Spline_Event));
  bool success = navigation_interfaces__srv__Spline_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__srv__Spline_Event__destroy(navigation_interfaces__srv__Spline_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__srv__Spline_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__srv__Spline_Event__Sequence__init(navigation_interfaces__srv__Spline_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Event * data = NULL;

  if (size) {
    data = (navigation_interfaces__srv__Spline_Event *)allocator.zero_allocate(size, sizeof(navigation_interfaces__srv__Spline_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__srv__Spline_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__srv__Spline_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
navigation_interfaces__srv__Spline_Event__Sequence__fini(navigation_interfaces__srv__Spline_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      navigation_interfaces__srv__Spline_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

navigation_interfaces__srv__Spline_Event__Sequence *
navigation_interfaces__srv__Spline_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__srv__Spline_Event__Sequence * array = (navigation_interfaces__srv__Spline_Event__Sequence *)allocator.allocate(sizeof(navigation_interfaces__srv__Spline_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__srv__Spline_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__srv__Spline_Event__Sequence__destroy(navigation_interfaces__srv__Spline_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__srv__Spline_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__srv__Spline_Event__Sequence__are_equal(const navigation_interfaces__srv__Spline_Event__Sequence * lhs, const navigation_interfaces__srv__Spline_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__srv__Spline_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__srv__Spline_Event__Sequence__copy(
  const navigation_interfaces__srv__Spline_Event__Sequence * input,
  navigation_interfaces__srv__Spline_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__srv__Spline_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__srv__Spline_Event * data =
      (navigation_interfaces__srv__Spline_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__srv__Spline_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__srv__Spline_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__srv__Spline_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
