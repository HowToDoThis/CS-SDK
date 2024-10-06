#include "STL-shit.h"

struct tempStruct_u1 {
    tempStruct_u1* next;
    tempStruct_u1* prev;
    char szName[16];
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
};

struct tempStruct_unk1 {
    void* u1;
    void* u2;
};

struct tempStruct {
    list u1;
    //void* u1_vals; // own structs
    //int u1_size;

    vector u3;
    //void* u3;
    //void* u4;
    //void* u5;

    int u6;
    int u7;
    float u8;
};