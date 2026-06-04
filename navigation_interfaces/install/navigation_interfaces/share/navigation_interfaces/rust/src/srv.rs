#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to navigation_interfaces__srv__Spline_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Spline_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_path: nav_msgs::msg::Path,

}



impl Default for Spline_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Spline_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Spline_Request {
  type RmwMsg = super::srv::rmw::Spline_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        waypoints_path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Owned(msg.waypoints_path)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        waypoints_path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Borrowed(&msg.waypoints_path)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      waypoints_path: nav_msgs::msg::Path::from_rmw_message(msg.waypoints_path),
    }
  }
}


// Corresponds to navigation_interfaces__srv__Spline_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Spline_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub spline_path: nav_msgs::msg::Path,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sd_steps: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cumulative_sd_steps: Vec<f64>,

}



impl Default for Spline_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Spline_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Spline_Response {
  type RmwMsg = super::srv::rmw::Spline_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        spline_path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Owned(msg.spline_path)).into_owned(),
        sd_steps: msg.sd_steps.into(),
        cumulative_sd_steps: msg.cumulative_sd_steps.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        spline_path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Borrowed(&msg.spline_path)).into_owned(),
        sd_steps: msg.sd_steps.as_slice().into(),
        cumulative_sd_steps: msg.cumulative_sd_steps.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      spline_path: nav_msgs::msg::Path::from_rmw_message(msg.spline_path),
      sd_steps: msg.sd_steps
          .into_iter()
          .collect(),
      cumulative_sd_steps: msg.cumulative_sd_steps
          .into_iter()
          .collect(),
    }
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


