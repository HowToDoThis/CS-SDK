struct CPacket_ZBEnhance
{
    void* vfptr;
    struct CPacketBase base;
    int type;
    int unk2; // some initialization
    int unk3;
    int unk4;
    int unk5;
};

struct Packet_Host
{
    void* vfptr;
    struct CPacketBase base;
    int hostID;
    int type;
    uint ip;
    int port;
    ushort gameDataSize;
    void* gameData; // array
    ushort playerCount;
    void* playerData; // array
    unsigned char crashFlag;

    int useScenUserID;
    short useScenItemID;
    char useScenUnk;
};

struct Packet_Transfer
{
    void* vfptr;
    struct CPacketBase base;
    uint serverIP;
    ushort port;
    int unk3;
    const char* userName;
    char unk5;
    char unk6;
};

struct Packet_Room
{
    void* vfptr;
    struct CPacketBase base;
    int unk1;
    int type;
    int roomID;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
};

struct Packet_UserStart
{
    void* vfptr;
    struct CPacketBase base;
    int type;
    const char* userName;
    const char* gameName;
    char unk4;
    int unk5;
    int unk6;
    int unk7;
};

struct Packet_ClientCheck
{
    void* vfptr;
    struct CPacketBase base;
    char* szCPUName;
    char* szGPUName;
    int iCPUHertz;
    int iShiftedMemory;
    int iUpload;
    int unk6;
    int iNetworkConfig;
    int unk8;
};
