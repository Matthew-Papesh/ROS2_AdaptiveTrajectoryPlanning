#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "navigation_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__navigation_interfaces__srv__Spline_Request() -> *const std::ffi::c_void;
}

#[link(name = "navigation_interfaces__rosidl_generator_c")]
extern "C" {
    fn navigation_interfaces__srv__Spline_Request__init(msg: *mut Spline_Request) -> bool;
    fn navigation_interfaces__srv__Spline_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Spline_Request>, size: usize) -> bool;
    fn navigation_interfaces__srv__Spline_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Spline_Request>);
    fn navigation_interfaces__srv__Spline_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Spline_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Spline_Request>) -> bool;
}

// Corresponds to navigation_interfaces__srv__Spline_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Spline_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_path: nav_msgs::msg::rmw::Path,

}



impl Default for Spline_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !navigation_interfaces__srv__Spline_Request__init(&mut msg as *mut _) {
        panic!("Call to navigation_interfaces__srv__Spline_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Spline_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__srv__Spline_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__srv__Spline_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__srv__Spline_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Spline_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Spline_Request where Self: Sized {
  const TYPE_NAME: &'static str = "navigation_interfaces/srv/Spline_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__navigation_interfaces__srv__Spline_Request() }
  }
}


#[link(name = "navigation_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__navigation_interfaces__srv__Spline_Response() -> *const std::ffi::c_void;
}

#[link(name = "navigation_interfaces__rosidl_generator_c")]
extern "C" {
    fn navigation_interfaces__srv__Spline_Response__init(msg: *mut Spline_Response) -> bool;
    fn navigation_interfaces__srv__Spline_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Spline_Response>, size: usize) -> bool;
    fn navigation_interfaces__srv__Spline_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Spline_Response>);
    fn navigation_interfaces__srv__Spline_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Spline_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Spline_Response>) -> bool;
}

// Corresponds to navigation_interfaces__srv__Spline_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Spline_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub spline_path: nav_msgs::msg::rmw::Path,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sd_steps: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cumulative_sd_steps: rosidl_runtime_rs::Sequence<f64>,

}



impl Default for Spline_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !navigation_interfaces__srv__Spline_Response__init(&mut msg as *mut _) {
        panic!("Call to navigation_interfaces__srv__Spline_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Spline_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__srv__Spline_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__srv__Spline_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { navigation_interfaces__srv__Spline_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Spline_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Spline_Response where Self: Sized {
  const TYPE_NAME: &'static str = "navigation_interfaces/srv/Spline_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__navigation_interfaces__srv__Spline_Response() }
  }
}






#[link(name = "navigation_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__navigation_interfaces__srv__Spline() -> *const std::ffi::c_void;
}

// Corresponds to navigation_interfaces__srv__Spline
#[allow(missing_docs, non_camel_case_types)]
pub struct Spline;

impl rosidl_runtime_rs::Service for Spline {
    type Request = Spline_Request;
    type Response = Spline_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__navigation_interfaces__srv__Spline() }
    }
}


