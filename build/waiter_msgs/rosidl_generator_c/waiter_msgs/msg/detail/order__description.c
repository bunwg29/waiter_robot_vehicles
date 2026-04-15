// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from waiter_msgs:msg/Order.idl
// generated code does not contain a copyright notice

#include "waiter_msgs/msg/detail/order__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_waiter_msgs
const rosidl_type_hash_t *
waiter_msgs__msg__Order__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2a, 0x39, 0x88, 0x3f, 0xde, 0xee, 0x08, 0x6e,
      0xe5, 0x3a, 0xd6, 0xdc, 0x17, 0xce, 0xa1, 0xd3,
      0x57, 0xdf, 0x44, 0x88, 0xe4, 0xb8, 0x30, 0x00,
      0x92, 0x83, 0xd7, 0x3d, 0xf8, 0x44, 0xa7, 0x29,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char waiter_msgs__msg__Order__TYPE_NAME[] = "waiter_msgs/msg/Order";

// Define type names, field names, and default values
static char waiter_msgs__msg__Order__FIELD_NAME__table_id[] = "table_id";
static char waiter_msgs__msg__Order__FIELD_NAME__item_name[] = "item_name";
static char waiter_msgs__msg__Order__FIELD_NAME__note[] = "note";

static rosidl_runtime_c__type_description__Field waiter_msgs__msg__Order__FIELDS[] = {
  {
    {waiter_msgs__msg__Order__FIELD_NAME__table_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {waiter_msgs__msg__Order__FIELD_NAME__item_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {waiter_msgs__msg__Order__FIELD_NAME__note, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
waiter_msgs__msg__Order__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {waiter_msgs__msg__Order__TYPE_NAME, 21, 21},
      {waiter_msgs__msg__Order__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 table_id\n"
  "string item_name\n"
  "string note";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
waiter_msgs__msg__Order__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {waiter_msgs__msg__Order__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 44, 44},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
waiter_msgs__msg__Order__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *waiter_msgs__msg__Order__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
