#include <dds/dds.h>

#include "JointPosition.h"
#include "org_sunrisedds_sunrisedds_SunriseDDS.h"

#define MAX_SAMPLES 1

JavaVM *g_vm = nullptr;
jobject g_on_joint_position_data_available_callback;

JNIEXPORT jint JNICALL Java_org_sunrisedds_sunrisedds_SunriseDDS_nativeCreateDomainParticipant(JNIEnv *, jclass)
{
    dds_entity_t participant = dds_create_participant(DDS_DOMAIN_DEFAULT, NULL, NULL);
    return static_cast<jint>(participant);
}

JNIEXPORT jint JNICALL Java_org_sunrisedds_sunrisedds_SunriseDDS_nativeCreateSubscriber(JNIEnv *, jclass, jint jparticipant)
{
    dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
    dds_entity_t subscriber = dds_create_subscriber(participant, NULL, NULL);
    jint jsubscriber = static_cast<jint>(subscriber);
    return jsubscriber;
}

static void data_available_handler(dds_entity_t reader, void *arg)
{
    JNIEnv *env;
    assert(g_vm != nullptr);
    g_vm->AttachCurrentThread((void **)&env, NULL);

    sunrisedds_interfaces_msg_JointPosition *msg;
    void *samples[MAX_SAMPLES];
    dds_sample_info_t infos[MAX_SAMPLES];
    dds_return_t rc;

    samples[0] = sunrisedds_interfaces_msg_JointPosition__alloc();

    int samples_received = dds_take(reader, samples, infos, MAX_SAMPLES, MAX_SAMPLES);

    if (infos[0].valid_data)
    {
        msg = reinterpret_cast<sunrisedds_interfaces_msg_JointPosition *>(samples[0]);

        jclass callback_cls = env->GetObjectClass(g_on_joint_position_data_available_callback);
        jmethodID callback_mid = env->GetMethodID(callback_cls, "callback", "(F)V");
        env->CallVoidMethod(g_on_joint_position_data_available_callback, callback_mid, msg->position.a1);
    }

    sunrisedds_interfaces_msg_JointPosition_free(samples[0], DDS_FREE_ALL);

    g_vm->DetachCurrentThread();
}

JNIEXPORT jint JNICALL Java_org_sunrisedds_sunrisedds_SunriseDDS_nativeCreateJointPositionReader(JNIEnv *env, jclass, jint jparticipant, jint jsubscriber, jstring jtopic_name, jobject callback)
{
    dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
    dds_entity_t subscriber = static_cast<dds_entity_t>(jsubscriber);

    // Create topic
    const char *topic_name = env->GetStringUTFChars(jtopic_name, NULL);
    dds_entity_t topic = dds_create_topic(participant, &sunrisedds_interfaces_msg_JointPosition_desc, topic_name, NULL, NULL);
    env->ReleaseStringUTFChars(jtopic_name, topic_name);

    g_on_joint_position_data_available_callback = env->NewGlobalRef(callback); // TODO(tingelst): Maybe as a register callback method?

    dds_listener_t *listener = dds_create_listener(NULL);
    dds_lset_data_available(listener, data_available_handler);

    // Create a reliable reader
    dds_qos_t *qos = dds_create_qos();
    dds_qset_reliability(qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
    dds_entity_t reader = dds_create_reader(subscriber, topic, qos, listener);

    // dds_entity_t waitset = dds_create_waitset(participant);
    // dds_waitset_attach(waitset, reader, 0);
    // dds_waitset_wait(waitset, NULL, 0, DDS_INFINITY);

    dds_delete_qos(qos);
    dds_delete_listener(listener);

    jint jreader = static_cast<jint>(reader);
    return jreader;
}

JNIEXPORT void JNICALL Java_org_sunrisedds_sunrisedds_SunriseDDS_nativeJointPositionReaderRead(JNIEnv *, jclass, jint jreader)
{
    sunrisedds_interfaces_msg_JointPosition *msg;
    void *samples[MAX_SAMPLES];
    dds_sample_info_t infos[MAX_SAMPLES];
    dds_return_t rc;

    dds_entity_t reader = static_cast<dds_entity_t>(jreader);

    samples[0] = sunrisedds_interfaces_msg_JointPosition__alloc();

    while (true)
    {
        rc = dds_read(reader, samples, infos, MAX_SAMPLES, MAX_SAMPLES);

        if ((rc > 0) && (infos[0].valid_data))
        {
            msg = reinterpret_cast<sunrisedds_interfaces_msg_JointPosition *>(samples[0]);

            printf("Received message\n");
            break;
        }
        else
        {
            dds_sleepfor(DDS_MSECS(20));
        }
    }

    sunrisedds_interfaces_msg_JointPosition_free(samples[0], DDS_FREE_ALL);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *)
{
    // Can only call this once
    if (g_vm == nullptr)
    {
        g_vm = vm;
    }

    JNIEnv *env;
    if (g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *)
{
    assert(g_vm != nullptr);
    assert(g_vm == vm);

    JNIEnv *env;
    if (g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) == JNI_OK)
    {
        env->DeleteGlobalRef(g_on_joint_position_data_available_callback);
    }
}