struct CGameUserManager_vtables
{
    void (__thiscall* desctuctor)(struct CGameUserManager* this);
    void (__thiscall* PacketIn)(struct CGameUserManager* this);
};

struct CGameUserManager
{
    CGameUserManager_vtables* vfptr;
    CGamePlayer* player;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8[12];
    int unk9;
    int unk10;
    int unk11;
    int unk12;
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