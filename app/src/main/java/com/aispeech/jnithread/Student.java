package com.aispeech.jnithread;

import android.os.Parcel;
import android.os.Parcelable;

/**
 * @创建者 luhaisheng
 * @创建时间 2020/1/6 17:49
 * @描述
 */
public class Student implements Parcelable {
    public String name;

    protected Student(Parcel in) {
        name = in.readString();
    }

    public static final Creator<Student> CREATOR = new Creator<Student>() {
        @Override
        public Student createFromParcel(Parcel in) {
            return new Student(in);
        }

        @Override
        public Student[] newArray(int size) {
            return new Student[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(name);
    }
}
