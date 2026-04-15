// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from waiter_msgs:action/DeliverOrder.idl
// generated code does not contain a copyright notice
#include "waiter_msgs/action/detail/deliver_order__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
waiter_msgs__action__DeliverOrder_Goal__init(waiter_msgs__action__DeliverOrder_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // table_id
  // target_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->target_pose)) {
    waiter_msgs__action__DeliverOrder_Goal__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_Goal__fini(waiter_msgs__action__DeliverOrder_Goal * msg)
{
  if (!msg) {
    return;
  }
  // table_id
  // target_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->target_pose);
}

bool
waiter_msgs__action__DeliverOrder_Goal__are_equal(const waiter_msgs__action__DeliverOrder_Goal * lhs, const waiter_msgs__action__DeliverOrder_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // table_id
  if (lhs->table_id != rhs->table_id) {
    return false;
  }
  // target_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->target_pose), &(rhs->target_pose)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_Goal__copy(
  const waiter_msgs__action__DeliverOrder_Goal * input,
  waiter_msgs__action__DeliverOrder_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // table_id
  output->table_id = input->table_id;
  // target_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->target_pose), &(output->target_pose)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_Goal *
waiter_msgs__action__DeliverOrder_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Goal * msg = (waiter_msgs__action__DeliverOrder_Goal *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_Goal));
  bool success = waiter_msgs__action__DeliverOrder_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_Goal__destroy(waiter_msgs__action__DeliverOrder_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_Goal__Sequence__init(waiter_msgs__action__DeliverOrder_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Goal * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_Goal *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_Goal__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_Goal__Sequence__fini(waiter_msgs__action__DeliverOrder_Goal__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_Goal__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_Goal__Sequence *
waiter_msgs__action__DeliverOrder_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Goal__Sequence * array = (waiter_msgs__action__DeliverOrder_Goal__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_Goal__Sequence__destroy(waiter_msgs__action__DeliverOrder_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_Goal__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_Goal__Sequence * lhs, const waiter_msgs__action__DeliverOrder_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_Goal__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_Goal__Sequence * input,
  waiter_msgs__action__DeliverOrder_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_Goal * data =
      (waiter_msgs__action__DeliverOrder_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
waiter_msgs__action__DeliverOrder_Result__init(waiter_msgs__action__DeliverOrder_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    waiter_msgs__action__DeliverOrder_Result__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_Result__fini(waiter_msgs__action__DeliverOrder_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
waiter_msgs__action__DeliverOrder_Result__are_equal(const waiter_msgs__action__DeliverOrder_Result * lhs, const waiter_msgs__action__DeliverOrder_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_Result__copy(
  const waiter_msgs__action__DeliverOrder_Result * input,
  waiter_msgs__action__DeliverOrder_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_Result *
waiter_msgs__action__DeliverOrder_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Result * msg = (waiter_msgs__action__DeliverOrder_Result *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_Result));
  bool success = waiter_msgs__action__DeliverOrder_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_Result__destroy(waiter_msgs__action__DeliverOrder_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_Result__Sequence__init(waiter_msgs__action__DeliverOrder_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Result * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_Result *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_Result__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_Result__Sequence__fini(waiter_msgs__action__DeliverOrder_Result__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_Result__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_Result__Sequence *
waiter_msgs__action__DeliverOrder_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Result__Sequence * array = (waiter_msgs__action__DeliverOrder_Result__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_Result__Sequence__destroy(waiter_msgs__action__DeliverOrder_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_Result__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_Result__Sequence * lhs, const waiter_msgs__action__DeliverOrder_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_Result__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_Result__Sequence * input,
  waiter_msgs__action__DeliverOrder_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_Result * data =
      (waiter_msgs__action__DeliverOrder_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
waiter_msgs__action__DeliverOrder_Feedback__init(waiter_msgs__action__DeliverOrder_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    waiter_msgs__action__DeliverOrder_Feedback__fini(msg);
    return false;
  }
  // progress
  return true;
}

void
waiter_msgs__action__DeliverOrder_Feedback__fini(waiter_msgs__action__DeliverOrder_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // state
  rosidl_runtime_c__String__fini(&msg->state);
  // progress
}

bool
waiter_msgs__action__DeliverOrder_Feedback__are_equal(const waiter_msgs__action__DeliverOrder_Feedback * lhs, const waiter_msgs__action__DeliverOrder_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_Feedback__copy(
  const waiter_msgs__action__DeliverOrder_Feedback * input,
  waiter_msgs__action__DeliverOrder_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // progress
  output->progress = input->progress;
  return true;
}

waiter_msgs__action__DeliverOrder_Feedback *
waiter_msgs__action__DeliverOrder_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Feedback * msg = (waiter_msgs__action__DeliverOrder_Feedback *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_Feedback));
  bool success = waiter_msgs__action__DeliverOrder_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_Feedback__destroy(waiter_msgs__action__DeliverOrder_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_Feedback__Sequence__init(waiter_msgs__action__DeliverOrder_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Feedback * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_Feedback *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_Feedback__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_Feedback__Sequence__fini(waiter_msgs__action__DeliverOrder_Feedback__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_Feedback__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_Feedback__Sequence *
waiter_msgs__action__DeliverOrder_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_Feedback__Sequence * array = (waiter_msgs__action__DeliverOrder_Feedback__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_Feedback__Sequence__destroy(waiter_msgs__action__DeliverOrder_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_Feedback__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_Feedback__Sequence * lhs, const waiter_msgs__action__DeliverOrder_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_Feedback__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_Feedback__Sequence * input,
  waiter_msgs__action__DeliverOrder_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_Feedback * data =
      (waiter_msgs__action__DeliverOrder_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "waiter_msgs/action/detail/deliver_order__functions.h"

bool
waiter_msgs__action__DeliverOrder_SendGoal_Request__init(waiter_msgs__action__DeliverOrder_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!waiter_msgs__action__DeliverOrder_Goal__init(&msg->goal)) {
    waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(waiter_msgs__action__DeliverOrder_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  waiter_msgs__action__DeliverOrder_Goal__fini(&msg->goal);
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Request__are_equal(const waiter_msgs__action__DeliverOrder_SendGoal_Request * lhs, const waiter_msgs__action__DeliverOrder_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!waiter_msgs__action__DeliverOrder_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Request__copy(
  const waiter_msgs__action__DeliverOrder_SendGoal_Request * input,
  waiter_msgs__action__DeliverOrder_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!waiter_msgs__action__DeliverOrder_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_SendGoal_Request *
waiter_msgs__action__DeliverOrder_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Request * msg = (waiter_msgs__action__DeliverOrder_SendGoal_Request *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Request));
  bool success = waiter_msgs__action__DeliverOrder_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Request__destroy(waiter_msgs__action__DeliverOrder_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__init(waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Request * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_SendGoal_Request *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__fini(waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence *
waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * array = (waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__destroy(waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * lhs, const waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * input,
  waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_SendGoal_Request * data =
      (waiter_msgs__action__DeliverOrder_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
waiter_msgs__action__DeliverOrder_SendGoal_Response__init(waiter_msgs__action__DeliverOrder_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    waiter_msgs__action__DeliverOrder_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Response__fini(waiter_msgs__action__DeliverOrder_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Response__are_equal(const waiter_msgs__action__DeliverOrder_SendGoal_Response * lhs, const waiter_msgs__action__DeliverOrder_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Response__copy(
  const waiter_msgs__action__DeliverOrder_SendGoal_Response * input,
  waiter_msgs__action__DeliverOrder_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_SendGoal_Response *
waiter_msgs__action__DeliverOrder_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Response * msg = (waiter_msgs__action__DeliverOrder_SendGoal_Response *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Response));
  bool success = waiter_msgs__action__DeliverOrder_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Response__destroy(waiter_msgs__action__DeliverOrder_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__init(waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Response * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_SendGoal_Response *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_SendGoal_Response__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__fini(waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_SendGoal_Response__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence *
waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * array = (waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__destroy(waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * lhs, const waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * input,
  waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_SendGoal_Response * data =
      (waiter_msgs__action__DeliverOrder_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_SendGoal_Response__copy(
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
// #include "waiter_msgs/action/detail/deliver_order__functions.h"

bool
waiter_msgs__action__DeliverOrder_SendGoal_Event__init(waiter_msgs__action__DeliverOrder_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(waiter_msgs__action__DeliverOrder_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Event__are_equal(const waiter_msgs__action__DeliverOrder_SendGoal_Event * lhs, const waiter_msgs__action__DeliverOrder_SendGoal_Event * rhs)
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
  if (!waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Event__copy(
  const waiter_msgs__action__DeliverOrder_SendGoal_Event * input,
  waiter_msgs__action__DeliverOrder_SendGoal_Event * output)
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
  if (!waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_SendGoal_Event *
waiter_msgs__action__DeliverOrder_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Event * msg = (waiter_msgs__action__DeliverOrder_SendGoal_Event *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Event));
  bool success = waiter_msgs__action__DeliverOrder_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Event__destroy(waiter_msgs__action__DeliverOrder_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__init(waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Event * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_SendGoal_Event *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__fini(waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence *
waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * array = (waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__destroy(waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * lhs, const waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * input,
  waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_SendGoal_Event * data =
      (waiter_msgs__action__DeliverOrder_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
waiter_msgs__action__DeliverOrder_GetResult_Request__init(waiter_msgs__action__DeliverOrder_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    waiter_msgs__action__DeliverOrder_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Request__fini(waiter_msgs__action__DeliverOrder_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Request__are_equal(const waiter_msgs__action__DeliverOrder_GetResult_Request * lhs, const waiter_msgs__action__DeliverOrder_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Request__copy(
  const waiter_msgs__action__DeliverOrder_GetResult_Request * input,
  waiter_msgs__action__DeliverOrder_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_GetResult_Request *
waiter_msgs__action__DeliverOrder_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Request * msg = (waiter_msgs__action__DeliverOrder_GetResult_Request *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_GetResult_Request));
  bool success = waiter_msgs__action__DeliverOrder_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Request__destroy(waiter_msgs__action__DeliverOrder_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__init(waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Request * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_GetResult_Request *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_GetResult_Request__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__fini(waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_GetResult_Request__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence *
waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * array = (waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__destroy(waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * lhs, const waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * input,
  waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_GetResult_Request * data =
      (waiter_msgs__action__DeliverOrder_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "waiter_msgs/action/detail/deliver_order__functions.h"

bool
waiter_msgs__action__DeliverOrder_GetResult_Response__init(waiter_msgs__action__DeliverOrder_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!waiter_msgs__action__DeliverOrder_Result__init(&msg->result)) {
    waiter_msgs__action__DeliverOrder_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Response__fini(waiter_msgs__action__DeliverOrder_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  waiter_msgs__action__DeliverOrder_Result__fini(&msg->result);
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Response__are_equal(const waiter_msgs__action__DeliverOrder_GetResult_Response * lhs, const waiter_msgs__action__DeliverOrder_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!waiter_msgs__action__DeliverOrder_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Response__copy(
  const waiter_msgs__action__DeliverOrder_GetResult_Response * input,
  waiter_msgs__action__DeliverOrder_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!waiter_msgs__action__DeliverOrder_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_GetResult_Response *
waiter_msgs__action__DeliverOrder_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Response * msg = (waiter_msgs__action__DeliverOrder_GetResult_Response *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_GetResult_Response));
  bool success = waiter_msgs__action__DeliverOrder_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Response__destroy(waiter_msgs__action__DeliverOrder_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__init(waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Response * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_GetResult_Response *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_GetResult_Response__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__fini(waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_GetResult_Response__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence *
waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * array = (waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__destroy(waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * lhs, const waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * input,
  waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_GetResult_Response * data =
      (waiter_msgs__action__DeliverOrder_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "waiter_msgs/action/detail/deliver_order__functions.h"

bool
waiter_msgs__action__DeliverOrder_GetResult_Event__init(waiter_msgs__action__DeliverOrder_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    waiter_msgs__action__DeliverOrder_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__init(&msg->request, 0)) {
    waiter_msgs__action__DeliverOrder_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__init(&msg->response, 0)) {
    waiter_msgs__action__DeliverOrder_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Event__fini(waiter_msgs__action__DeliverOrder_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__fini(&msg->request);
  // response
  waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__fini(&msg->response);
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Event__are_equal(const waiter_msgs__action__DeliverOrder_GetResult_Event * lhs, const waiter_msgs__action__DeliverOrder_GetResult_Event * rhs)
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
  if (!waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Event__copy(
  const waiter_msgs__action__DeliverOrder_GetResult_Event * input,
  waiter_msgs__action__DeliverOrder_GetResult_Event * output)
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
  if (!waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_GetResult_Event *
waiter_msgs__action__DeliverOrder_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Event * msg = (waiter_msgs__action__DeliverOrder_GetResult_Event *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_GetResult_Event));
  bool success = waiter_msgs__action__DeliverOrder_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Event__destroy(waiter_msgs__action__DeliverOrder_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__init(waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Event * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_GetResult_Event *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_GetResult_Event__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__fini(waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_GetResult_Event__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence *
waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * array = (waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__destroy(waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * lhs, const waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * input,
  waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_GetResult_Event * data =
      (waiter_msgs__action__DeliverOrder_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "waiter_msgs/action/detail/deliver_order__functions.h"

bool
waiter_msgs__action__DeliverOrder_FeedbackMessage__init(waiter_msgs__action__DeliverOrder_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!waiter_msgs__action__DeliverOrder_Feedback__init(&msg->feedback)) {
    waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(waiter_msgs__action__DeliverOrder_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  waiter_msgs__action__DeliverOrder_Feedback__fini(&msg->feedback);
}

bool
waiter_msgs__action__DeliverOrder_FeedbackMessage__are_equal(const waiter_msgs__action__DeliverOrder_FeedbackMessage * lhs, const waiter_msgs__action__DeliverOrder_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!waiter_msgs__action__DeliverOrder_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_FeedbackMessage__copy(
  const waiter_msgs__action__DeliverOrder_FeedbackMessage * input,
  waiter_msgs__action__DeliverOrder_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!waiter_msgs__action__DeliverOrder_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

waiter_msgs__action__DeliverOrder_FeedbackMessage *
waiter_msgs__action__DeliverOrder_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_FeedbackMessage * msg = (waiter_msgs__action__DeliverOrder_FeedbackMessage *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(waiter_msgs__action__DeliverOrder_FeedbackMessage));
  bool success = waiter_msgs__action__DeliverOrder_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
waiter_msgs__action__DeliverOrder_FeedbackMessage__destroy(waiter_msgs__action__DeliverOrder_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__init(waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_FeedbackMessage * data = NULL;

  if (size) {
    data = (waiter_msgs__action__DeliverOrder_FeedbackMessage *)allocator.zero_allocate(size, sizeof(waiter_msgs__action__DeliverOrder_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = waiter_msgs__action__DeliverOrder_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(&data[i - 1]);
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
waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__fini(waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * array)
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
      waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(&array->data[i]);
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

waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence *
waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * array = (waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence *)allocator.allocate(sizeof(waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__destroy(waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__are_equal(const waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * lhs, const waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__copy(
  const waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * input,
  waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(waiter_msgs__action__DeliverOrder_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    waiter_msgs__action__DeliverOrder_FeedbackMessage * data =
      (waiter_msgs__action__DeliverOrder_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!waiter_msgs__action__DeliverOrder_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          waiter_msgs__action__DeliverOrder_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!waiter_msgs__action__DeliverOrder_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
