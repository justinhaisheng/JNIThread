#include "com_aispeech_jnithread_ndk_PthreadUtil.h"
#include <pthread.h>

#include "queue" //队列
#include "unistd.h" //休眠

#include "JavaListener.h"



extern "C"
JNIEXPORT jstring JNICALL Java_com_aispeech_jnithread_ndk_PthreadUtil_stringFromJNI
        (JNIEnv *env, jobject job){

}

pthread_t t;


void* normalCallBack(void* data){
    LOGD("normalCallBack");
    int rv;
    pthread_exit(&t);
}


extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_PthreadUtil_normalThread
        (JNIEnv *env, jobject job){
    pthread_create(&t,NULL,normalCallBack,NULL);
}


//生产者 、 消费者 模型

pthread_t product_t;//生产者线程
pthread_t custom_t;//消费者线程

pthread_mutex_t mutex;//锁
pthread_cond_t cond;//信号

std::queue<int> queue;//队列

//生产者函数
void *producCallback(void *data)
{
    while (1){
        pthread_mutex_lock(&mutex);
        queue.push(1);
        LOGD("生产者生产一个产品，通知消费者消费， 产品数量为 %d", queue.size());
        pthread_cond_signal(&cond);//发出信号
        pthread_mutex_unlock(&mutex);//解锁

        usleep(800 * 1000);
    }
    pthread_exit(&product_t);
}

//消费者函数
void *customCallback(void *data)
{
    while (1){
        pthread_mutex_lock(&mutex);
        if(queue.size() > 0)
        {
            queue.pop();
            LOGD("消费者消费产品，产品数量还剩余 %d ", queue.size());
        } else{
            LOGE("没有产品可以消费， 等待中...");
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        usleep(500 * 1000);
    }
    pthread_exit(&custom_t);
}


extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_PthreadUtil_mutexThread
        (JNIEnv *env, jobject job){

    for(int i = 0; i < 10; i++)
    {
        queue.push(1);
    }


   pthread_mutex_init(&mutex,NULL);//初始化锁
   pthread_cond_init(&cond,NULL);//初始化信号

   pthread_create(&product_t,NULL,producCallback,NULL);
   pthread_create(&custom_t,NULL,customCallback,NULL);

}



JavaVM *jvm;

JavaListener *javaListener;

pthread_t jlistener_t;

extern "C"
JNIEXPORT void JNICALL
Java_com_aispeech_jnithread_ndk_PthreadUtil_callbackFromC(JNIEnv *env, jobject thiz) {
    // TODO: implement callbackFromC()
    javaListener = new JavaListener(jvm, env, env->NewGlobalRef(thiz));
    javaListener->onError(1, 100, "c++ call java meid from main thread!");
    delete(javaListener);
    javaListener = NULL;
}

int* ret_val ;
void* post_thread(void* data){
    LOGD("post_thread ");
    JavaListener* listener = static_cast<JavaListener *>(data);
    LOGD("post_thread1 ");
    listener->onError(0,200,"c++ call java meid from sub thread!");
    LOGD("post_thread2 ");

    pthread_exit(&jlistener_t);

}

extern "C"
JNIEXPORT void JNICALL Java_com_aispeech_jnithread_ndk_PthreadUtil_subCalbackThread
        (JNIEnv *env, jobject job){
    javaListener = new JavaListener(jvm, env, env->NewGlobalRef(job));
    pthread_create(&jlistener_t,NULL,post_thread,javaListener);
    pthread_join(jlistener_t, NULL);
    LOGD("Java_com_aispeech_jnithread_PthreadUtil_subCalbackThread");
    delete(javaListener);
}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void* reserved)
{
    JNIEnv *env;
    jvm = vm;
    if(vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK)
    {
        return -1;
    }
    return JNI_VERSION_1_6;
}