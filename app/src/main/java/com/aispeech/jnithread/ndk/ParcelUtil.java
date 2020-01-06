package com.aispeech.jnithread.ndk;

/**
 * @创建者 luhaisheng
 * @创建时间 2020/1/6 16:12
 * @描述
 */
public class ParcelUtil {

    static {
        System.loadLibrary("native-lib");
    }
    private native long nativeCreate();
    private native void nativeWriteInt(long ptr,int val);
    private native void nativeWriteString(long ptr,String val);
    private native String nativeReadString(long ptr);
    private native int nativeReadInt(long ptr);
    private native void nativeSetDataPosition(long ptr,int pos);
    private native void nativeDestory(long ptr);
    public ParcelUtil(){
        create();
    }

    long mNativePtr = 0;
    private void create(){
        mNativePtr = nativeCreate();
    }


    public void writeString(String val){
        if (mNativePtr!=0){
            nativeWriteString(mNativePtr,val);
        }
    }

    public String readString(){
        if (mNativePtr!=0){
            return nativeReadString(mNativePtr);
        }
        return null;
    }

    public void writeInt(int val){
        if (mNativePtr!=0){
            nativeWriteInt(mNativePtr,val);
        }
    }

    public int readInt(){
        if (mNativePtr!=0){
            return nativeReadInt(mNativePtr);
        }
        return -1;
    }

    public void setPos(int pos){
        if (mNativePtr!=0){
            nativeSetDataPosition(mNativePtr,pos);
        }
    }

    public void destory(){
        if (mNativePtr!=0){
            nativeDestory(mNativePtr);
        }
    }
}
