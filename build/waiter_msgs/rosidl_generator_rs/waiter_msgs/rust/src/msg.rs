#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to waiter_msgs__msg__Order

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Order {

    // This member is not documented.
    #[allow(missing_docs)]
    pub table_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub item_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub note: std::string::String,

}



impl Default for Order {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Order::default())
  }
}

impl rosidl_runtime_rs::Message for Order {
  type RmwMsg = super::msg::rmw::Order;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        table_id: msg.table_id,
        item_name: msg.item_name.as_str().into(),
        note: msg.note.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      table_id: msg.table_id,
        item_name: msg.item_name.as_str().into(),
        note: msg.note.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      table_id: msg.table_id,
      item_name: msg.item_name.to_string(),
      note: msg.note.to_string(),
    }
  }
}


