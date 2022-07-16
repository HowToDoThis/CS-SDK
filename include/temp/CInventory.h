struct Packet_Inventory_vtables
{
    void (__thiscall* Function1)(struct Packet_Inventory* this);
    void (__thiscall* Function2)(struct Packet_Inventory* this);
    void (__thiscall* Function3)(struct Packet_Inventory* this);
    void (__thiscall* Function4)(struct Packet_Inventory* this);
    void (__thiscall* Function5)(struct Packet_Inventory* this);
    void (__thiscall* Function6)(struct Packet_Inventory* this);
    void (__thiscall* Function7)(struct Packet_Inventory* this);
};

struct Packet_Inventory
{
    Packet_Inventory_vtables* vfptr;
    struct CPacketBase base;
    int type;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
};

struct Packet_Item
{
    void* vfptr;
    struct CPacketBase base;
    byte type;
    byte unk1;
    short unk2a;
    short unk2b;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    byte unk7;
};

struct Inventory_vtables
{
    void (__thiscall* Function1)(struct Inventory* this);
    void (__thiscall* Function2)(struct Inventory* this);
    void (__thiscall* Function3)(struct Inventory* this);
    void (__thiscall* Function4)(struct Inventory* this);
    void (__thiscall* Function5)(struct Inventory* this);
    void (__thiscall* Function6)(struct Inventory* this);
    void (__thiscall* Function7)(struct Inventory* this);
    void (__thiscall* Function8)(struct Inventory* this);
    void (__thiscall* Function9)(struct Inventory* this);
    int (__thiscall* OnUseItem)(struct Inventory* this, int itemID);
    int (__thiscall* IsUserInventoryExists)(struct Inventory* this, int itemID);
    void (__thiscall* Function12)(struct Inventory* this);
    void (__thiscall* Function13)(struct Inventory* this);
    void (__thiscall* Function14)(struct Inventory* this);
    void (__thiscall* Function15)(struct Inventory* this);
    void (__thiscall* Function16)(struct Inventory* this);
    void (__thiscall* Function17)(struct Inventory* this);
    void (__thiscall* Function18)(struct Inventory* this);
    void (__thiscall* Function19)(struct Inventory* this);
    void (__thiscall* Function20)(struct Inventory* this);
    void (__thiscall* Function21)(struct Inventory* this);
    void (__thiscall* Function22)(struct Inventory* this);
    void (__thiscall* Function23)(struct Inventory* this);
    void (__thiscall* Function24)(struct Inventory* this);
    void (__thiscall* Function25)(struct Inventory* this);
    void (__thiscall* Function26)(struct Inventory* this);
    void (__thiscall* Function27)(struct Inventory* this);
    void (__thiscall* Function28)(struct Inventory* this);
    void (__thiscall* Function29)(struct Inventory* this);
    void (__thiscall* Function30)(struct Inventory* this);
    void (__thiscall* Function31)(struct Inventory* this);
    void (__thiscall* Function32)(struct Inventory* this);
    void (__thiscall* Function33)(struct Inventory* this);
    void (__thiscall* Function34)(struct Inventory* this);
    void (__thiscall* Function35)(struct Inventory* this);
    void (__thiscall* NoticeGachapon)(struct Inventory* this);
    void (__thiscall* OpenDecoder)(struct Inventory* this, int* shit);
    void (__thiscall* NoticeGiftbox)(struct Inventory* this);
    void (__thiscall* NoticeFabendu)(struct Inventory* this, int unk);
    void (__thiscall* Function40)(struct Inventory* this);
    void (__thiscall* Function41)(struct Inventory* this);
    void (__thiscall* WeaponAssembly)(struct Inventory* this, int* shit);
    void (__thiscall* MaterialAssembly)(struct Inventory* this, int* shit);
    void (__thiscall* Enhance)(struct Inventory* this, int* enhanceInfo);
    void (__thiscall* Function45)(struct Inventory* this);
    void (__thiscall* Function46)(struct Inventory* this);
    void (__thiscall* Function47)(struct Inventory* this);
    void (__thiscall* Function48)(struct Inventory* this);
    void (__thiscall* Function49)(struct Inventory* this);
    void (__thiscall* Function50)(struct Inventory* this);
    void (__thiscall* Function51)(struct Inventory* this);
    void (__thiscall* WeaponPaint)(struct Inventory* this, bool unk1, int unk2);
    void (__thiscall* Function53)(struct Inventory* this);
    void (__thiscall* Function54)(struct Inventory* this);
    void (__thiscall* Function55)(struct Inventory* this);
    void (__thiscall* Function56)(struct Inventory* this);
    void (__thiscall* Function57)(struct Inventory* this);
    void (__thiscall* RouletteUpdateRandomPrize)(struct Inventory* this, int isOpen, int unk, int* prizes);
    void (__thiscall* Roulette1_1)(struct Inventory* this, int* unk);
    void (__thiscall* RouletteUpdateDayPrize)(struct Inventory* this, int count, int day, int prizes);
    void (__thiscall* Roulette1_2)(struct Inventory* this, int unk1, int* shit);
    void (__thiscall* Function62)(struct Inventory* this);
    void (__thiscall* Function63)(struct Inventory* this);
    void (__thiscall* Function64)(struct Inventory* this);
    void (__thiscall* Function65)(struct Inventory* this);
    void (__thiscall* Function66)(struct Inventory* this);
    void (__thiscall* Function67)(struct Inventory* this);
    void (__thiscall* Function68)(struct Inventory* this);
    void (__thiscall* Function69)(struct Inventory* this);
    void (__thiscall* Function70)(struct Inventory* this);
    void (__thiscall* Function71)(struct Inventory* this);
    void (__thiscall* ItemExtend)(struct Inventory* this, bool unk1, int unk2);
    void (__thiscall* Function73)(struct Inventory* this);
    void (__thiscall* Function74)(struct Inventory* this);
    void (__thiscall* Function75)(struct Inventory* this);
    void (__thiscall* Function76)(struct Inventory* this);
    void (__thiscall* Function77)(struct Inventory* this);
    void (__thiscall* Function78)(struct Inventory* this);
};

struct TestInventoryUnk7
{
    TestInventoryUnk7* next;
    int unk1;
    int unk2;
    char unk3a;
    char unk3b;
    int unk4;
    int unk5; // functions?
    int unk6;
};

struct Inventory
{
    Inventory_vtables* vfptr;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    TestInventoryUnk7* unk7;
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
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    short unk27;
};
