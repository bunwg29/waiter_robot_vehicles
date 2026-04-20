#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "waiter_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__msg__Order() -> *const std::ffi::c_void;
}

#[link(name = "waiter_msgs__rosidl_generator_c")]
extern "C" {
    fn waiter_msgs__msg__Order__init(msg: *mut Order) -> bool;
    fn waiter_msgs__msg__Order__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Order>, size: usize) -> bool;
    fn waiter_msgs__msg__Order__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Order>);
    fn waiter_msgs__msg__Order__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Order>, out_seq: *mut rosidl_runtime_rs::Sequence<Order>) -> bool;
}

// Corresponds to waiter_msgs__msg__Order
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Order {

    // This member is not documented.
    #[allow(missing_docs)]
    pub table_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub item_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub note: rosidl_runtime_rs::String,

}



impl Default for Order {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waiter_msgs__msg__Order__init(&mut msg as *mut _) {
        panic!("Call to waiter_msgs__msg__Order__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Order {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__msg__Order__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__msg__Order__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waiter_msgs__msg__Order__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Order {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Order where Self: Sized {
  const TYPE_NAME: &'static str = "waiter_msgs/msg/Order";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waiter_msgs__msg__Order() }
  }
}


