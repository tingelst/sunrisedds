#include <string>

#include <dds/dds.h>

#include "exceptions.hpp"

void
sunrisedds_throw_exception(JNIEnv * env, int retcode)
{
  jclass exception_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/DDSException");
  jmethodID exception_constructor =
    env->GetMethodID(exception_class, "<init>", "(Ljava/lang/String;)V");
  jstring jmessage = env->NewStringUTF(dds_strretcode(-retcode));
  jthrowable exception =
    static_cast<jthrowable>(env->NewObject(exception_class, exception_constructor, jmessage));
  env->Throw(exception);
}
