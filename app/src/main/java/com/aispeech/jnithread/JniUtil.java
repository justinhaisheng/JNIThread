package com.aispeech.jnithread;

/**
 * @创建者 luhaisheng
 * @创建时间 2019/12/20 20:07
 * @描述
 */
public class JniUtil {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    //主线程调用
    public native void normalThread();

    //子线程调用
    public native void mutexThread();

    public native  void callbackFromC();

    private OnErrerListener onErrerListener;

    public void setOnErrerListener(OnErrerListener onErrerListener) {
        this.onErrerListener = onErrerListener;
    }

    public void onError(int code, String msg)
    {
        if(onErrerListener != null)
        {
            onErrerListener.onError(code, msg);
        }
    }

    public interface OnErrerListener
    {
        void onError(int code, String msg);
    }

}
