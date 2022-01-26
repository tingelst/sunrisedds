#pragma once

#include <jni.h>
#include <string>

void * get_object_field(JNIEnv * env, jobject message, const char * name, const char * signature);

std::string get_string_field(JNIEnv * env, jobject message, const std::string & name);

double get_double_field(JNIEnv * env, jobject message, const std::string & name);

int get_int_field(JNIEnv * env, jobject message, const std::string & name);

void set_object_field(
  JNIEnv * env, jobject jmessage, const std::string & name, const std::string & signature,
  void * field);

void set_string_field(
  JNIEnv * env, jobject jmessage, const std::string & name, const std::string & field);

void set_double_field(JNIEnv * env, jobject jmessage, const std::string & name, double field);

void set_int_field(JNIEnv * env, jobject jmessage, const std::string & name, int field);