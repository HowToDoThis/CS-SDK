// CHN160531 Size 1D8 (472)
struct CUDPHolePuncherUnknown
{
    int unk1;
    sockaddr_in server;
    int unkSwitch;
    unsigned int localIP1; // holepunch7
    int udpType;
    unsigned int localIP2;
    int userID;
    SOCKET sockA;
    SOCKET sockB;
    unsigned short clientPortA;
    unsigned short serverPortA;
    unsigned short clientPortB;
    unsigned short serverPortB;
    short somethingTickA;
    short somethingTickB;
    unsigned short unkCount;
    short unk15;
    int unk16;
    // prob command buffer?
    const char somethingCBuf[256];
};

struct CUDPHolePuncherUnknown2
{
    sockaddr addr;
    int unknown[24];
};

struct CUDPHolePuncher
{
    void* vfptr;
    CUDPHolePuncherUnknown base;
    int unk1;
    int unk2; // array
    int unk3;
    int unk4; // array
    int unk5;
    int unk6;
    int iUnk2[28]; // related lock
    short unk7A;
    short unk7B;
    int unk8;
    int unk9;
    int unk10;
};