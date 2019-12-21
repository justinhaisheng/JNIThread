//
// Created by haisheng.lu on 2019/12/21.
//

#include <jni.h>
#include <android/log.h>
#define LOGD(FORMAT,...) __android_log_print(ANDROID_LOG_DEBUG, "haisheng", FORMAT, ##__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR, "haisheng", FORMAT, ##__VA_ARGS__);


#ifndef JNITHREAD_JAVALISTENER_H
#define JNITHREAD_JAVALISTENER_H


class JavaListener {
public:
    JavaVM *jvm;//java 虚拟机
    JNIEnv *jenv;
    jobject jobj;
    jmethodID  jmid;

    JavaListener(JavaVM *vm, JNIEnv *env, jobject obj);
    ~JavaListener();


    /**
     * 1:主线程
     * 0：子线程
     * @param type
     * @param code
     * @param msg
     */
    void onError(int type, int code, const char *msg);
};


#endif //JNITHREAD_JAVALISTENER_H
