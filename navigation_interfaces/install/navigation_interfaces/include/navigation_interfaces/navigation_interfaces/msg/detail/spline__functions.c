// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from navigation_interfaces:msg/Spline.idl
// generated code does not contain a copyright notice
#include "navigation_interfaces/msg/detail/spline__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
navigation_interfaces__msg__Spline__init(navigation_interfaces__msg__Spline * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
navigation_interfaces__msg__Spline__fini(navigation_interfaces__msg__Spline * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
navigation_interfaces__msg__Spline__are_equal(const navigation_interfaces__msg__Spline * lhs, const navigation_interfaces__msg__Spline * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
navigation_interfaces__msg__Spline__copy(
  const navigation_interfaces__msg__Spline * input,
  navigation_interfaces__msg__Spline * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

navigation_interfaces__msg__Spline *
navigation_interfaces__msg__Spline__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__msg__Spline * msg = (navigation_interfaces__msg__Spline *)allocator.allocate(sizeof(navigation_interfaces__msg__Spline), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__msg__Spline));
  bool success = navigation_interfaces__msg__Spline__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__msg__Spline__destroy(navigation_interfaces__msg__Spline * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__msg__Spline__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__msg__Spline__Sequence__init(navigation_interfaces__msg__Spline__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__msg__Spline * data = NULL;

  if (size) {
    data = (navigation_interfaces__msg__Spline *)allocator.zero_allocate(size, sizeof(navigation_interfaces__msg__Spline), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__msg__Spline__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__msg__Spline__fini(&data[i - 1]);
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
navigation_interfaces__msg__Spline__Sequence__fini(navigation_interfaces__msg__Spline__Sequence * array)
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
      navigation_interfaces__msg__Spline__fini(&array->data[i]);
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

navigation_interfaces__msg__Spline__Sequence *
navigation_interfaces__msg__Spline__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__msg__Spline__Sequence * array = (navigation_interfaces__msg__Spline__Sequence *)allocator.allocate(sizeof(navigation_interfaces__msg__Spline__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__msg__Spline__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__msg__Spline__Sequence__destroy(navigation_interfaces__msg__Spline__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__msg__Spline__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__msg__Spline__Sequence__are_equal(const navigation_interfaces__msg__Spline__Sequence * lhs, const navigation_interfaces__msg__Spline__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__msg__Spline__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__msg__Spline__Sequence__copy(
  const navigation_interfaces__msg__Spline__Sequence * input,
  navigation_interfaces__msg__Spline__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__msg__Spline);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__msg__Spline * data =
      (navigation_interfaces__msg__Spline *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__msg__Spline__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__msg__Spline__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__msg__Spline__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
