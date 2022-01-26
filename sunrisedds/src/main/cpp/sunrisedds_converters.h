#pragma once

#include <jni.h>

void * convert_object_field(
  JNIEnv * env, jobject message, const char * name, const char * signature);