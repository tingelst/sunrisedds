#pragma once

#include <jni.h>

using convert_from_java_signature = void * (*)(jobject, void *);
using convert_to_java_signature = jobject (*)(void *, jobject);
using destroy_message_signature = void (*)(void *);