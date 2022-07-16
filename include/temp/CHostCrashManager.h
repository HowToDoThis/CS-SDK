struct CHostCrashManager_vtables
{
    void (__thiscall* Function1)(struct CHostCrashManager* this);
};

struct CHostCrashManager
{
    CHostCrashManager_vtables* vfptr;
    int unk1;
    int unk2; // unk
    int unk3;
    double unk4;
    ushort restore;
    ushort restored;
    void* compressedData;
    short compressedSize;
    char unk7B;
    int unk8;
    void* unk9;
    int unk10;
};