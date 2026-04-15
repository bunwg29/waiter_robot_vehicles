// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from waiter_msgs:action/DeliverOrder.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "waiter_msgs/action/deliver_order.hpp"


#ifndef WAITER_MSGS__ACTION__DETAIL__DELIVER_ORDER__BUILDER_HPP_
#define WAITER_MSGS__ACTION__DETAIL__DELIVER_ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "waiter_msgs/action/detail/deliver_order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_Goal_target_pose
{
public:
  explicit Init_DeliverOrder_Goal_target_pose(::waiter_msgs::action::DeliverOrder_Goal & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_Goal target_pose(::waiter_msgs::action::DeliverOrder_Goal::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_Goal msg_;
};

class Init_DeliverOrder_Goal_table_id
{
public:
  Init_DeliverOrder_Goal_table_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_Goal_target_pose table_id(::waiter_msgs::action::DeliverOrder_Goal::_table_id_type arg)
  {
    msg_.table_id = std::move(arg);
    return Init_DeliverOrder_Goal_target_pose(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_Goal>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_Goal_table_id();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_Result_message
{
public:
  explicit Init_DeliverOrder_Result_message(::waiter_msgs::action::DeliverOrder_Result & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_Result message(::waiter_msgs::action::DeliverOrder_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_Result msg_;
};

class Init_DeliverOrder_Result_success
{
public:
  Init_DeliverOrder_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_Result_message success(::waiter_msgs::action::DeliverOrder_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DeliverOrder_Result_message(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_Result>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_Result_success();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_Feedback_progress
{
public:
  explicit Init_DeliverOrder_Feedback_progress(::waiter_msgs::action::DeliverOrder_Feedback & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_Feedback progress(::waiter_msgs::action::DeliverOrder_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_Feedback msg_;
};

class Init_DeliverOrder_Feedback_state
{
public:
  Init_DeliverOrder_Feedback_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_Feedback_progress state(::waiter_msgs::action::DeliverOrder_Feedback::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_DeliverOrder_Feedback_progress(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_Feedback>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_Feedback_state();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_SendGoal_Request_goal
{
public:
  explicit Init_DeliverOrder_SendGoal_Request_goal(::waiter_msgs::action::DeliverOrder_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_SendGoal_Request goal(::waiter_msgs::action::DeliverOrder_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Request msg_;
};

class Init_DeliverOrder_SendGoal_Request_goal_id
{
public:
  Init_DeliverOrder_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_SendGoal_Request_goal goal_id(::waiter_msgs::action::DeliverOrder_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DeliverOrder_SendGoal_Request_goal(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_SendGoal_Request>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_SendGoal_Request_goal_id();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_SendGoal_Response_stamp
{
public:
  explicit Init_DeliverOrder_SendGoal_Response_stamp(::waiter_msgs::action::DeliverOrder_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_SendGoal_Response stamp(::waiter_msgs::action::DeliverOrder_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Response msg_;
};

class Init_DeliverOrder_SendGoal_Response_accepted
{
public:
  Init_DeliverOrder_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_SendGoal_Response_stamp accepted(::waiter_msgs::action::DeliverOrder_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_DeliverOrder_SendGoal_Response_stamp(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_SendGoal_Response>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_SendGoal_Response_accepted();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_SendGoal_Event_response
{
public:
  explicit Init_DeliverOrder_SendGoal_Event_response(::waiter_msgs::action::DeliverOrder_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_SendGoal_Event response(::waiter_msgs::action::DeliverOrder_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Event msg_;
};

class Init_DeliverOrder_SendGoal_Event_request
{
public:
  explicit Init_DeliverOrder_SendGoal_Event_request(::waiter_msgs::action::DeliverOrder_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_DeliverOrder_SendGoal_Event_response request(::waiter_msgs::action::DeliverOrder_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DeliverOrder_SendGoal_Event_response(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Event msg_;
};

class Init_DeliverOrder_SendGoal_Event_info
{
public:
  Init_DeliverOrder_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_SendGoal_Event_request info(::waiter_msgs::action::DeliverOrder_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DeliverOrder_SendGoal_Event_request(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_SendGoal_Event>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_SendGoal_Event_info();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_GetResult_Request_goal_id
{
public:
  Init_DeliverOrder_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::waiter_msgs::action::DeliverOrder_GetResult_Request goal_id(::waiter_msgs::action::DeliverOrder_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_GetResult_Request>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_GetResult_Request_goal_id();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_GetResult_Response_result
{
public:
  explicit Init_DeliverOrder_GetResult_Response_result(::waiter_msgs::action::DeliverOrder_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_GetResult_Response result(::waiter_msgs::action::DeliverOrder_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_GetResult_Response msg_;
};

class Init_DeliverOrder_GetResult_Response_status
{
public:
  Init_DeliverOrder_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_GetResult_Response_result status(::waiter_msgs::action::DeliverOrder_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_DeliverOrder_GetResult_Response_result(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_GetResult_Response>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_GetResult_Response_status();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_GetResult_Event_response
{
public:
  explicit Init_DeliverOrder_GetResult_Event_response(::waiter_msgs::action::DeliverOrder_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_GetResult_Event response(::waiter_msgs::action::DeliverOrder_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_GetResult_Event msg_;
};

class Init_DeliverOrder_GetResult_Event_request
{
public:
  explicit Init_DeliverOrder_GetResult_Event_request(::waiter_msgs::action::DeliverOrder_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_DeliverOrder_GetResult_Event_response request(::waiter_msgs::action::DeliverOrder_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DeliverOrder_GetResult_Event_response(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_GetResult_Event msg_;
};

class Init_DeliverOrder_GetResult_Event_info
{
public:
  Init_DeliverOrder_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_GetResult_Event_request info(::waiter_msgs::action::DeliverOrder_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DeliverOrder_GetResult_Event_request(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_GetResult_Event>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_GetResult_Event_info();
}

}  // namespace waiter_msgs


namespace waiter_msgs
{

namespace action
{

namespace builder
{

class Init_DeliverOrder_FeedbackMessage_feedback
{
public:
  explicit Init_DeliverOrder_FeedbackMessage_feedback(::waiter_msgs::action::DeliverOrder_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::waiter_msgs::action::DeliverOrder_FeedbackMessage feedback(::waiter_msgs::action::DeliverOrder_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_FeedbackMessage msg_;
};

class Init_DeliverOrder_FeedbackMessage_goal_id
{
public:
  Init_DeliverOrder_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeliverOrder_FeedbackMessage_feedback goal_id(::waiter_msgs::action::DeliverOrder_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DeliverOrder_FeedbackMessage_feedback(msg_);
  }

private:
  ::waiter_msgs::action::DeliverOrder_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::waiter_msgs::action::DeliverOrder_FeedbackMessage>()
{
  return waiter_msgs::action::builder::Init_DeliverOrder_FeedbackMessage_goal_id();
}

}  // namespace waiter_msgs

#endif  // WAITER_MSGS__ACTION__DETAIL__DELIVER_ORDER__BUILDER_HPP_
