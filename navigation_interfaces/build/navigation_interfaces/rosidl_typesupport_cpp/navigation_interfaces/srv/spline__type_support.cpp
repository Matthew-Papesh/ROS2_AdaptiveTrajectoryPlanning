// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from navigation_interfaces:srv/Spline.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "navigation_interfaces/srv/detail/spline__functions.h"
#include "navigation_interfaces/srv/detail/spline__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace navigation_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spline_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spline_Request_type_support_ids_t;

static const _Spline_Request_type_support_ids_t _Spline_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spline_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spline_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spline_Request_type_support_symbol_names_t _Spline_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, navigation_interfaces, srv, Spline_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, navigation_interfaces, srv, Spline_Request)),
  }
};

typedef struct _Spline_Request_type_support_data_t
{
  void * data[2];
} _Spline_Request_type_support_data_t;

static _Spline_Request_type_support_data_t _Spline_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spline_Request_message_typesupport_map = {
  2,
  "navigation_interfaces",
  &_Spline_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Spline_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Spline_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spline_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spline_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Request__get_type_hash,
  &navigation_interfaces__srv__Spline_Request__get_type_description,
  &navigation_interfaces__srv__Spline_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<navigation_interfaces::srv::Spline_Request>()
{
  return &::navigation_interfaces::srv::rosidl_typesupport_cpp::Spline_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, navigation_interfaces, srv, Spline_Request)() {
  return get_message_type_support_handle<navigation_interfaces::srv::Spline_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace navigation_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spline_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spline_Response_type_support_ids_t;

static const _Spline_Response_type_support_ids_t _Spline_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spline_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spline_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spline_Response_type_support_symbol_names_t _Spline_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, navigation_interfaces, srv, Spline_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, navigation_interfaces, srv, Spline_Response)),
  }
};

typedef struct _Spline_Response_type_support_data_t
{
  void * data[2];
} _Spline_Response_type_support_data_t;

static _Spline_Response_type_support_data_t _Spline_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spline_Response_message_typesupport_map = {
  2,
  "navigation_interfaces",
  &_Spline_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Spline_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Spline_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spline_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spline_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Response__get_type_hash,
  &navigation_interfaces__srv__Spline_Response__get_type_description,
  &navigation_interfaces__srv__Spline_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<navigation_interfaces::srv::Spline_Response>()
{
  return &::navigation_interfaces::srv::rosidl_typesupport_cpp::Spline_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, navigation_interfaces, srv, Spline_Response)() {
  return get_message_type_support_handle<navigation_interfaces::srv::Spline_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__functions.h"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace navigation_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spline_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spline_Event_type_support_ids_t;

static const _Spline_Event_type_support_ids_t _Spline_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spline_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spline_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spline_Event_type_support_symbol_names_t _Spline_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, navigation_interfaces, srv, Spline_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, navigation_interfaces, srv, Spline_Event)),
  }
};

typedef struct _Spline_Event_type_support_data_t
{
  void * data[2];
} _Spline_Event_type_support_data_t;

static _Spline_Event_type_support_data_t _Spline_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spline_Event_message_typesupport_map = {
  2,
  "navigation_interfaces",
  &_Spline_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Spline_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Spline_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Spline_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spline_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &navigation_interfaces__srv__Spline_Event__get_type_hash,
  &navigation_interfaces__srv__Spline_Event__get_type_description,
  &navigation_interfaces__srv__Spline_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<navigation_interfaces::srv::Spline_Event>()
{
  return &::navigation_interfaces::srv::rosidl_typesupport_cpp::Spline_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, navigation_interfaces, srv, Spline_Event)() {
  return get_message_type_support_handle<navigation_interfaces::srv::Spline_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "navigation_interfaces/srv/detail/spline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace navigation_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Spline_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Spline_type_support_ids_t;

static const _Spline_type_support_ids_t _Spline_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Spline_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Spline_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Spline_type_support_symbol_names_t _Spline_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, navigation_interfaces, srv, Spline)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, navigation_interfaces, srv, Spline)),
  }
};

typedef struct _Spline_type_support_data_t
{
  void * data[2];
} _Spline_type_support_data_t;

static _Spline_type_support_data_t _Spline_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Spline_service_typesupport_map = {
  2,
  "navigation_interfaces",
  &_Spline_service_typesupport_ids.typesupport_identifier[0],
  &_Spline_service_typesupport_symbol_names.symbol_name[0],
  &_Spline_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Spline_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Spline_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<navigation_interfaces::srv::Spline_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<navigation_interfaces::srv::Spline_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<navigation_interfaces::srv::Spline_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<navigation_interfaces::srv::Spline>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<navigation_interfaces::srv::Spline>,
  &navigation_interfaces__srv__Spline__get_type_hash,
  &navigation_interfaces__srv__Spline__get_type_description,
  &navigation_interfaces__srv__Spline__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<navigation_interfaces::srv::Spline>()
{
  return &::navigation_interfaces::srv::rosidl_typesupport_cpp::Spline_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, navigation_interfaces, srv, Spline)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<navigation_interfaces::srv::Spline>();
}

#ifdef __cplusplus
}
#endif
