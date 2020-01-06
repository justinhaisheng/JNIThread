//
// Created by haisheng.lu on 2020/1/6.
//

#ifndef JNITHREAD_PARCEL_H
#define JNITHREAD_PARCEL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Parcel {
public:
    char* mData;//指针地址
    int offset_pos = 0;//偏移量

    Parcel();
    ~Parcel();

    void writeInt(int val);
    int readInt();
    void setPos(int pos);

    void writeString(const char* val,int len);
    char* readString(char* out);
};


#endif //JNITHREAD_PARCEL_H
