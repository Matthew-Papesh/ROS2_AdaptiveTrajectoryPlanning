#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "navigation_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__navigation_interfaces__msg__Spline() -> *const std::ffi::c_void;
}

#[link(name = "navigation_interfaces__rosidl_generator_c")]
extern "C" {
    fn navigation_interfaces__msg__Spline__init(msg: *mut Spline) -> bool;
    fn navigation_interfaces__msg__Spline__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Spline>, size: usize) -> bool;
    fn navigation_interfaces__msg__Spline__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Spline>);
    fn navigation_interfaces__msg__Spline__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Spline>, out_seq: *mut rosidl_runtime_rs::Sequence<Spline>) -> bool;
}

// Corresponds to navigation_interfaces__msg__Spline
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Spline {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Spline {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !navigation_interfaces__msg__Spline__init(&mut msg as *mut _) {
        panic!("Call to navigation_interfaces__msg__Spline__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Spline {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__msg__Spline__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__msg__Spline__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__msg__Spline__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Spline {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Spline where Self: Sized {
  const TYPE_NAME: &'static str = "navigation_interfaces/msg/Spline";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__navigation_interfaces__msg__Spline() }
  }
}


