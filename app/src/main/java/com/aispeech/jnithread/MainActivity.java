package com.aispeech.jnithread;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    JniUtil mJniUtil = new JniUtil();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mJniUtil.setOnErrerListener(new JniUtil.OnErrerListener() {
            @Override
            public void onError(int code, String msg) {
                Toast.makeText(MainActivity.this,""+msg,Toast.LENGTH_SHORT).show();
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
}
