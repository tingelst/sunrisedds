// Copyright 2022 Norwegian University of Science and Technology.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <dds/dds.h>
#include <jni.h>
#include <string>

#ifndef DDS_SEQUENCE_STRING_DEFINED
#define DDS_SEQUENCE_STRING_DEFINED
typedef struct dds_sequence_string
{
  uint32_t _maximum;
  uint32_t _length;
  char ** _buffer;
  bool _release;
} dds_sequence_string;

#define dds_sequence_string__alloc() \
  ((dds_sequence_string *)dds_alloc(sizeof(dds_sequence_string)));

#define dds_sequence_string_allocbuf(l) ((char **)dds_alloc((l) * sizeof(char *)))
#endif /* DDS_SEQUENCE_STRING_DEFINED */

#ifndef DDS_SEQUENCE_DOUBLE_DEFINED
#define DDS_SEQUENCE_DOUBLE_DEFINED
typedef struct dds_sequence_double
{
  uint32_t _maximum;
  uint32_t _length;
  double * _buffer;
  bool _release;
} dds_sequence_double;

#define dds_sequence_double__alloc() \
  ((dds_sequence_double *)dds_alloc(sizeof(dds_sequence_double)));

#define dds_sequence_double_allocbuf(l) ((double *)dds_alloc((l) * sizeof(double)))
#endif /* DDS_SEQUENCE_DOUBLE_DEFINED */

void * get_object_field(JNIEnv * env, jobject message, const char * name, const char * signature);

std::string get_string_field(JNIEnv * env, jobject message, const std::string & name);

double get_double_field(JNIEnv * env, jobject message, const std::string & name);

int get_int_field(JNIEnv * env, jobject message, const std::string & name);

void get_string_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_string * out);

void set_string_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_string * field);

void get_double_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_double * out);

void set_double_array_field(
  JNIEnv * env, jobject jmessage, const std::string & name, dds_sequence_double * field);

void set_object_field(
  JNIEnv * env, jobject jmessage, const std::string & name, const std::string & signature,
  void * field);

void set_string_field(
  JNIEnv * env, jobject jmessage, const std::string & name, const std::string & field);

void set_double_field(JNIEnv * env, jobject jmessage, const std::string & name, double field);

void set_int_field(JNIEnv * env, jobject jmessage, const std::string & name, int field);
