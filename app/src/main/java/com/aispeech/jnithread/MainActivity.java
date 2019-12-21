package com.aispeech.jnithread;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;


public class MainActivity extends AppCompatActivity {

    JniUtil mJniUtil = new JniUtil();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


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

    }
}
