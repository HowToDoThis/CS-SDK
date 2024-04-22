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
    const char somethingCBuf[252];
    struct vector unk17;
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
    int u3;
    struct list u4;
    int u6;
    int iU1[27]; // related lock
    int u7;
    short u7A;
    short u7B;
    int u8;
    int u9;
    int u10;
};