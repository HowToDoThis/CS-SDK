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
    int unk7;
    int unk8;
};

struct ShareDict
{
    ShareDictSys* sys;
};
