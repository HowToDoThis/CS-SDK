struct UnkBuffer2Hack
{
    void* data;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
};

struct UnkBuffer2WithCritical
{
    UnkBuffer2Hack hack;
    CRITICAL_SECTION critical;
};

struct UnkBuffer
{
    UnkBuffer2Hack hack1;
    CRITICAL_SECTION critical1;

    UnkBuffer2Hack hack2;
    CRITICAL_SECTION critical2;

    UnkBuffer2WithCritical hack3;

    UnkBuffer2WithCritical hack4;

    UnkBuffer2WithCritical hack5;
};

struct UnkBuffer2
{
    UnkBuffer2Hack hack[11];
};

struct FuckBuffer
{
    int unk1;     // 0000 (00-04)
    int unk2;     // 0000 (04-08)
    int unk3;     // 2000 (08-12) volatile
    int buffer;   // 0000 (12-16)
    int unk5;     // 0000 (16-20)
    int unk6;     // 1000 (20-24) volatile
};