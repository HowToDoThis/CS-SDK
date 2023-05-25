struct CGameUserManager_vtables
{
    void (__thiscall* desctuctor)(struct CGameUserManager* this);
    void (__thiscall* PacketIn)(struct CGameUserManager* this);
};

struct CGameUserManager
{
    CGameUserManager_vtables* vfptr;
    struct CGamePlayer* player;

    //int* iNewUnk1; // vector/string
    //int* iNewUnk2; // vector/string

    vector unk2;

    int unk5;
    int unk6;
    int unk7;
    int unk8[12];

    vector unk9;

    int unk12;
    //int iNewUnk3;
    //int iNewUnk4;

    //unsigned long long iNewUnk5;
    //int iNewUnk7;
    //int iNewUnk8;
    //int iNewUnk9;
    //int iNewUnk10;
    //int iNewUnk11;
    //int iNewUnk12;
};

struct Packet_UserUpdateInfo
{
    void* vfptr;
    struct CPacketBase base;
    struct CGameUser user;
    int flag;
    int unk2;
    int unk3;
    int unk4;
};

struct Packet_Lobby : CPacket
{
    int subType;
    CGameUser user;
};