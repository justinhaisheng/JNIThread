package com.aispeech.jnithread;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

import com.aispeech.jnithread.ndk.PthreadUtil;

public class PthradActivity extends AppCompatActivity {

    PthreadUtil mJniUtil = new PthreadUtil();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pthrad);
        mJniUtil.setOnErrerListener(new PthreadUtil.OnErrerListener() {
            @Override
            public void onError(int code, final String msg) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(PthradActivity.this,""+msg,Toast.LENGTH_SHORT).show();
                    }
                });

            }
        });
    }

    public void normal(View view){
        mJniUtil.normalThread();
    }

    /*
     *生产者消费者
     *@author luhaisheng
     *@time 2019/12/20 20:16
     */
    public void mutexThread(View view){
        mJniUtil.mutexThread();
    }

    /*
     *C 调用java方法
     *@author luhaisheng
     *@time 2019/12/20 20:17
     */
    public void calbackThread(View view){
        mJniUtil.callbackFromC();
    }

    public void subCalbackThread(View view){
        mJniUtil.subCalbackThread();
    }
}
