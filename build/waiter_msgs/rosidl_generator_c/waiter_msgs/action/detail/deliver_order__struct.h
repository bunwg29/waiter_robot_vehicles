// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from waiter_msgs:action/DeliverOrder.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "waiter_msgs/action/deliver_order.h"


#ifndef WAITER_MSGS__ACTION__DETAIL__DELIVER_ORDER__STRUCT_H_
#define WAITER_MSGS__ACTION__DETAIL__DELIVER_ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_Goal
{
  int32_t table_id;
  geometry_msgs__msg__PoseStamped target_pose;
} waiter_msgs__action__DeliverOrder_Goal;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_Goal.
typedef struct waiter_msgs__action__DeliverOrder_Goal__Sequence
{
  waiter_msgs__action__DeliverOrder_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_Result
{
  bool success;
  rosidl_runtime_c__String message;
} waiter_msgs__action__DeliverOrder_Result;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_Result.
typedef struct waiter_msgs__action__DeliverOrder_Result__Sequence
{
  waiter_msgs__action__DeliverOrder_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'state'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_Feedback
{
  rosidl_runtime_c__String state;
  float progress;
} waiter_msgs__action__DeliverOrder_Feedback;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_Feedback.
typedef struct waiter_msgs__action__DeliverOrder_Feedback__Sequence
{
  waiter_msgs__action__DeliverOrder_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "waiter_msgs/action/detail/deliver_order__struct.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  waiter_msgs__action__DeliverOrder_Goal goal;
} waiter_msgs__action__DeliverOrder_SendGoal_Request;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_SendGoal_Request.
typedef struct waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence
{
  waiter_msgs__action__DeliverOrder_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} waiter_msgs__action__DeliverOrder_SendGoal_Response;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_SendGoal_Response.
typedef struct waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence
{
  waiter_msgs__action__DeliverOrder_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  waiter_msgs__action__DeliverOrder_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  waiter_msgs__action__DeliverOrder_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence request;
  waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence response;
} waiter_msgs__action__DeliverOrder_SendGoal_Event;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_SendGoal_Event.
typedef struct waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence
{
  waiter_msgs__action__DeliverOrder_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} waiter_msgs__action__DeliverOrder_GetResult_Request;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_GetResult_Request.
typedef struct waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence
{
  waiter_msgs__action__DeliverOrder_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "waiter_msgs/action/detail/deliver_order__struct.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_GetResult_Response
{
  int8_t status;
  waiter_msgs__action__DeliverOrder_Result result;
} waiter_msgs__action__DeliverOrder_GetResult_Response;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_GetResult_Response.
typedef struct waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence
{
  waiter_msgs__action__DeliverOrder_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  waiter_msgs__action__DeliverOrder_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  waiter_msgs__action__DeliverOrder_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence request;
  waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence response;
} waiter_msgs__action__DeliverOrder_GetResult_Event;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_GetResult_Event.
typedef struct waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence
{
  waiter_msgs__action__DeliverOrder_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "waiter_msgs/action/detail/deliver_order__struct.h"

/// Struct defined in action/DeliverOrder in the package waiter_msgs.
typedef struct waiter_msgs__action__DeliverOrder_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  waiter_msgs__action__DeliverOrder_Feedback feedback;
} waiter_msgs__action__DeliverOrder_FeedbackMessage;

// Struct for a sequence of waiter_msgs__action__DeliverOrder_FeedbackMessage.
typedef struct waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence
{
  waiter_msgs__action__DeliverOrder_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAITER_MSGS__ACTION__DETAIL__DELIVER_ORDER__STRUCT_H_
