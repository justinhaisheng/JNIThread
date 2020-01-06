//
// Created by haisheng.lu on 2020/1/6.
//


#include <android/log.h>
#include "Parcel.h"
#include "AndroidLog.h"
Parcel::Parcel(){
    mData = static_cast<char *>(malloc(sizeof(int) * 1024));
}
Parcel::~Parcel(){
    if (mData){
        free(mData);
        mData = NULL;
    }
}

void Parcel::writeInt(int val){
    *(mData+offset_pos) = val;
    offset_pos+= sizeof(int);
}
int Parcel::readInt(){
    int val = *(mData+offset_pos);
    offset_pos+= sizeof(int);
    return val;
}
void Parcel::setPos(int pos){
    offset_pos = pos;
}

void Parcel::writeString(const char* val,int len){
    *(mData+offset_pos) = len;
    offset_pos+= sizeof(int);

    strcpy(mData+offset_pos,val);
    offset_pos+= sizeof(char)*len;
}

char* Parcel::readString(char* out) {
    int len = *(mData+offset_pos);
    offset_pos+= sizeof(int);
    LOGD("len %d",len);
    char temp[len+1];
    memcpy(temp,mData+offset_pos,sizeof(char)*len);
    offset_pos+= sizeof(char)*len;
    LOGD("temp %s",temp);
    strcpy(out,temp);
    return temp;
}