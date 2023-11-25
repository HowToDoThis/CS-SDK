struct UnkBuffer2Hack
{
    char* data;
    int size;
    int unk3;
    int unk4;
    int unk5;
};

struct UnkBuffer2WithCritical : UnkBuffer2Hack
{
    CRITICAL_SECTION critical;
};

struct UnkBuffer
{
    UnkBuffer2WithCritical buf64;
    UnkBuffer2WithCritical buf128;
    UnkBuffer2WithCritical buf256;
    UnkBuffer2WithCritical buf512;
    UnkBuffer2WithCritical buf1024;
};

struct UnkBuffer2
{
    UnkBuffer2Hack buf16;
    UnkBuffer2Hack buf32;
    UnkBuffer2Hack buf64;
    UnkBuffer2Hack buf128;
    UnkBuffer2Hack buf256;
    UnkBuffer2Hack buf512;
    UnkBuffer2Hack buf1024;
    UnkBuffer2Hack buf2048;
    UnkBuffer2Hack buf4096;
    UnkBuffer2Hack buf8192;
    UnkBuffer2Hack buf16384;
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