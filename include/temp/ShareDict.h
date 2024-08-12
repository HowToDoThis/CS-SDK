struct pair_ShareDict {
    int first;
    int second;
};

struct mapNode_ShareDict {
    pair_ShareDict* _Left;
    pair_ShareDict* _Parent;
    pair_ShareDict* _Right;
    char _Color;
    char _Isnil;
    pair_ShareDict _Myval;
};

struct map_ShareDict {
    mapNode_ShareDict* _Myhead;
    unsigned int _Mysize;
};

struct ShareDictSys
{
    void* mapPtr;
    int iSize;
    HANDLE hMap;
    int unk4;
    int dwFileOffsetLow;
    int dwFileOffsetHigh;
    int dwDesiredAccess;
    int unk6;
    map_ShareDict mMap;
};

struct ShareDictParse {
    char* mapPtr;
    int offset; // 8
    int u2; // INT_MAX
};

struct ShareDict
{
    ShareDictSys* sys;
};
