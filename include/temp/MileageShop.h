struct Packet_MileageShop : CPacket
{
    int unk1;
    int unk2;
    int unk3;
};

struct MileageShop_vt
{
    void (__thiscall* Function1)(struct MileageShop* this);
    void (__thiscall* Function2)(struct MileageShop* this);
    void (__thiscall* Function3)(struct MileageShop* this);
    int  (__thiscall* returnPacketID)(struct MileageShop* this);
    void (__thiscall* Function5)(struct MileageShop* this);
    void (__thiscall* Function6)(struct MileageShop* this);
    void (__thiscall* Function7)(struct MileageShop* this);
    void (__thiscall* Function8)(struct MileageShop* this);
    void (__thiscall* Function9)(struct MileageShop* this);
    void (__thiscall* Function10)(struct MileageShop* this);
    void (__thiscall* Function11)(struct MileageShop* this);
    void (__thiscall* Function12)(struct MileageShop* this);
    void (__thiscall* Function13)(struct MileageShop* this);
    void (__thiscall* Function14)(struct MileageShop* this);
    void (__thiscall* Function15)(struct MileageShop* this);
    void (__thiscall* Function16)(struct MileageShop* this);
    void (__thiscall* Function17)(struct MileageShop* this);
    void (__thiscall* Function18)(struct MileageShop* this);
    void (__thiscall* Function19)(struct MileageShop* this);
    void (__thiscall* Function20)(struct MileageShop* this);
    void (__thiscall* Function21)(struct MileageShop* this);
    struct Packet_MileageShop* (__thiscall* GetPacket)(struct MileageShop* this);
};

struct MileageShop
{
    MileageShop_vt* vfptr;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    struct Packet_MileageShop gMileageShop;
    int unk20;
};

struct EpicPieceShopMgr : MileageShop
{
    struct Packet_MileageShop gEpicPieceShop;
};


struct QuestBadgeShopMgr : MileageShop
{
    struct Packet_MileageShop gQuestBadgeShop;
};