package com.aispeech.jnithread;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import com.aispeech.jnithread.ndk.ParcelUtil;

public class ParcelActivity extends AppCompatActivity {

    private static final String TAG = ParcelActivity.class.getSimpleName();
    private ParcelUtil mParcelUtil;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_parcel);
    }

    public void read(View view) {
        if (mParcelUtil == null){
            mParcelUtil = new ParcelUtil();
        }else{
            mParcelUtil.setPos(0);
        }
        int anInt1 = mParcelUtil.readInt();
        int anInt2 = mParcelUtil.readInt();
        Log.d(TAG,"anInt1:"+anInt1+" anInt2:"+anInt2);
        String str1 = mParcelUtil.readString();
        Log.d(TAG,"str1:"+str1);
    }

    public void write(View view) {

        if (mParcelUtil == null){
            mParcelUtil = new ParcelUtil();
        }else{
            mParcelUtil.setPos(0);
        }
        mParcelUtil.writeInt(66);
        mParcelUtil.writeInt(77);
        mParcelUtil.writeString("abc");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mParcelUtil.destory();
    }
}
