//
// Created by haisheng.lu on 2020/1/6.
//

#include <android/log.h>
#include "com_aispeech_jnithread_ndk_ParcelUtil.h"
#include "Parcel.h"
#include "AndroidLog.h"
extern "C"
JNIEXPORT jlong JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeCreate
        (JNIEnv *env, jobject jobj){
    return reinterpret_cast<jlong>(new Parcel());
}

extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeWriteInt
        (JNIEnv *env, jobject jobj,jlong ptr, jint val){
    Parcel* parcel = reinterpret_cast<Parcel*>(ptr);
    if (parcel){
        parcel->writeInt(val);
    }
}

extern "C"
JNIEXPORT jint JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeReadInt
        (JNIEnv *env, jobject jobj,jlong ptr){
    Parcel* parcel = reinterpret_cast<Parcel*>(ptr);
    if (parcel){
        return parcel->readInt();
    }
    return -1;
}

extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeSetDataPosition
        (JNIEnv *, jobject,jlong ptr,jint pos){
    Parcel* parcel = reinterpret_cast<Parcel*>(ptr);
    if (parcel){
        return parcel->setPos(pos);
    }
}

extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeDestory
        (JNIEnv *env, jobject jobj,jlong ptr){
    Parcel* parcel = reinterpret_cast<Parcel*>(ptr);
    if (parcel){
        delete parcel;
        parcel = NULL;
    }
}

extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeWriteString
        (JNIEnv *env, jobject jobj, jlong ptr, jstring jval){

    const char*  val = env->GetStringUTFChars(jval,0);
    int len = env->GetStringLength(jval);
    LOGD("len %d,val %s",len,val);
    Parcel* parcel = reinterpret_cast<Parcel*>(ptr);
    if (parcel){
        parcel->writeString(val,len);
    }
    env->ReleaseStringUTFChars(jval,val);
}

extern "C"
JNIEXPORT jstring JNICALL Java_com_aispeech_jnithread_ndk_ParcelUtil_nativeReadString
        (JNIEnv *env, jobject jobj, jlong ptr){
    Parcel* parcel = reinterpret_cast<Parcel*>(ptr);
    if (parcel){
        char temp[100];
        parcel->readString(temp);
        LOGD("val11 %s",temp);
        jstring val = env->NewStringUTF(temp);
        return val;
    }
    return NULL;
}