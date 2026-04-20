
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_Goal() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_Goal__init(msg: *mut DeliverOrder_Goal) -> bool;
    fn waiter_msgs__action__DeliverOrder_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Goal>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Goal>);
    fn waiter_msgs__action__DeliverOrder_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Goal>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub table_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_pose: geometry_msgs::msg::rmw::PoseStamped,

}



impl Default for DeliverOrder_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_Goal__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_Goal() }
  }
}


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_Result() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_Result__init(msg: *mut DeliverOrder_Result) -> bool;
    fn waiter_msgs__action__DeliverOrder_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Result>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Result>);
    fn waiter_msgs__action__DeliverOrder_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Result>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for DeliverOrder_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_Result__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_Result where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_Result() }
  }
}


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_Feedback__init(msg: *mut DeliverOrder_Feedback) -> bool;
    fn waiter_msgs__action__DeliverOrder_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Feedback>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Feedback>);
    fn waiter_msgs__action__DeliverOrder_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_Feedback>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub progress: f32,

}



impl Default for DeliverOrder_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_Feedback__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_Feedback() }
  }
}


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_FeedbackMessage__init(msg: *mut DeliverOrder_FeedbackMessage) -> bool;
    fn waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_FeedbackMessage>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_FeedbackMessage>);
    fn waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_FeedbackMessage>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::DeliverOrder_Feedback,

}



impl Default for DeliverOrder_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_FeedbackMessage() }
  }
}




#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_SendGoal_Request__init(msg: *mut DeliverOrder_SendGoal_Request) -> bool;
    fn waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Request>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Request>);
    fn waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Request>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::DeliverOrder_Goal,

}



impl Default for DeliverOrder_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_SendGoal_Request() }
  }
}


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_SendGoal_Response__init(msg: *mut DeliverOrder_SendGoal_Response) -> bool;
    fn waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Response>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Response>);
    fn waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_SendGoal_Response>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for DeliverOrder_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_SendGoal_Response() }
  }
}


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_GetResult_Request__init(msg: *mut DeliverOrder_GetResult_Request) -> bool;
    fn waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Request>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Request>);
    fn waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Request>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for DeliverOrder_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_GetResult_Request() }
  }
}


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__action__DeliverOrder_GetResult_Response__init(msg: *mut DeliverOrder_GetResult_Response) -> bool;
    fn waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Response>, size: usize) -> bool;
    fn waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Response>);
    fn waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DeliverOrder_GetResult_Response>) -> bool;
}

// Corresponds to waiter_msgs__action__DeliverOrder_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeliverOrder_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::DeliverOrder_Result,

}



impl Default for DeliverOrder_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__action__DeliverOrder_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__action__DeliverOrder_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeliverOrder_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__action__DeliverOrder_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeliverOrder_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeliverOrder_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/action/DeliverOrder_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__action__DeliverOrder_GetResult_Response() }
  }
}






#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__waiter_msgs__action__DeliverOrder_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to waiter_msgs__action__DeliverOrder_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct DeliverOrder_SendGoal;

impl rosidl_runtime_rs::Service for DeliverOrder_SendGoal {
    type Request = DeliverOrder_SendGoal_Request;
    type Response = DeliverOrder_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__waiter_msgs__action__DeliverOrder_SendGoal() }
    }
}




#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__waiter_msgs__action__DeliverOrder_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to waiter_msgs__action__DeliverOrder_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct DeliverOrder_GetResult;

impl rosidl_runtime_rs::Service for DeliverOrder_GetResult {
    type Request = DeliverOrder_GetResult_Request;
    type Response = DeliverOrder_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__waiter_msgs__action__DeliverOrder_GetResult() }
    }
}


