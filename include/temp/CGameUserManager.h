struct CGameUserManager_vtables
{
    void (__thiscall* dtor)(struct CGameUserManager* this);
    void (__thiscall* OnPacket)(struct CGameUserManager* this);
};

struct CGameUserManager
{
    CGameUserManager_vtables* vfptr;
    struct CGamePlayer* player;

    //int* iNewUnk1; // vector/string
    //int* iNewUnk2; // vector/string

    int unk1;
    int unk2;
    int unk3;
    
    int unk5;
    int unk6;
    int unk7;

    long long lExp;
    long long lPoints;

    int iBattles;
    int iWin;
    int iKills;
    int iDeaths;
    int iZombieKills;
    int iSurvived;

    int iLevel;
    int unk8;

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

struct Packet_Lobby : Packet
{
    int subType;
    CGameUser user;
};