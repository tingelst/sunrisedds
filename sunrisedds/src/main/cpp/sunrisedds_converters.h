#pragma once

#include <jni.h>
#include <string>

void * convert_object_field(
  JNIEnv * env, jobject message, const char * name, const char * signature);

std::string convert_string_field(JNIEnv * env, jobject message, const std::string & name);

double convert_double_field(JNIEnv * env, jobject message, const std::string & name);

int convert_int_field(JNIEnv * env, jobject message, const std::string & name);