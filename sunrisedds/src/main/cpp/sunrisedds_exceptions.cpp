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
#include <string>

#include <dds/dds.h>

#include "sunrisedds_exceptions.h"

jint
sunrisedds_throw_exception(JNIEnv * env, const std::string & error_message)
{
  jclass exception_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/DDSException");
  jmethodID exception_constructor =
    env->GetMethodID(exception_class, "<init>", "(Ljava/lang/String;)V");
  jstring jmessage = env->NewStringUTF(error_message.c_str());
  jthrowable exception =
    static_cast<jthrowable>(env->NewObject(exception_class, exception_constructor, jmessage));
  return env->Throw(exception);
}
