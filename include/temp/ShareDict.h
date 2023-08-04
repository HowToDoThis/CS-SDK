struct Unk24
{
    int unk0;
    int unk1;
    int unk2;
    short unk3A;
    short unk3B;
    int unk4;
    int unk5;
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
    int unk7;
};

struct ShareDict
{
    ShareDictSys* sys;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    Unk24* unk8;
    int unk9;
};
