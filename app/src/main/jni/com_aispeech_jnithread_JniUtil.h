/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_aispeech_jnithread_JniUtil */

#ifndef _Included_com_aispeech_jnithread_JniUtil
#define _Included_com_aispeech_jnithread_JniUtil
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_aispeech_jnithread_JniUtil
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_aispeech_jnithread_JniUtil_stringFromJNI
  (JNIEnv *, jobject);

/*
 * Class:     com_aispeech_jnithread_JniUtil
 * Method:    normalThread
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_JniUtil_normalThread
  (JNIEnv *, jobject);

/*
 * Class:     com_aispeech_jnithread_JniUtil
 * Method:    mutexThread
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_JniUtil_mutexThread
  (JNIEnv *, jobject);




JNIEXPORT void JNICALL
Java_com_aispeech_jnithread_JniUtil_callbackFromC(JNIEnv *, jobject );

#ifdef __cplusplus
}
#endif
#endif
