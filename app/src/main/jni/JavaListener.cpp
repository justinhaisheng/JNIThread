//
// Created by haisheng.lu on 2019/12/21.
//

#include "JavaListener.h"


JavaListener::JavaListener(JavaVM *vm, JNIEnv *env, jobject obj) {
    this->jvm = vm;
    this->jenv = env;
    this->jobj = obj;

    jclass jcls = env->GetObjectClass(jobj);
    if(!jcls)
    {
        LOGE("JavaListener !jcls");
        return;
    }

    jmid = env->GetMethodID(jcls,"onError", "(ILjava/lang/String;)V");

    if(!jmid){
        LOGE("JavaListener !jmid");
        return;
    }

}

void JavaListener::onError(int type, int code, const char *msg) {
    LOGD("onError");
    if (type == 1){//主线程
        jstring  jmsgj = this->jenv->NewStringUTF(msg);
        LOGD("onError %s",msg);
        this->jenv->CallVoidMethod(this->jobj,this->jmid,code,jmsgj);
        LOGD("onError2 %s",msg);
        jenv->DeleteLocalRef(jmsgj);
        LOGD("onError3");
    }else{
        JNIEnv *env;
        jvm->AttachCurrentThread(&env,0);
        LOGD("onError4");
        jstring  jmsgj = env->NewStringUTF(msg);
        env->CallVoidMethod(this->jobj,this->jmid,code,jmsgj);
        env->DeleteLocalRef(jmsgj);
        LOGD("onError5");
        jvm->DetachCurrentThread();
        LOGD("onError6");
    }
}

JavaListener::~JavaListener(){
    LOGD("析构函数");




}