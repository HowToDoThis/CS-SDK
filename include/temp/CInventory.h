struct Item // sizeof(128)
{
    void* vfptr;
    int unk02;
    int unk03; // sizeof(104)
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10; // 40
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    short unk16a;
    short unk16b;
    int unk17;
    int unk18;
    int unk19;
    int unk20; // 80
    int unk21;
    int unk22;
    char unk23a;
    char unk23b;
    short unk23c;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29; // sizeof(12)
    int unk30; // 120
    int unk31;
    int unk32;
};

struct InventoryItem
{
    short slot;
    int exists;
    int itemId;
    int count;
    int status;
    int unk1;
    int unk2;
    int unk3;
    int expiryDate;
    int unk4;
    int unk5; // set 2???
    char inUse;
    int enhance;
    char unk6;
    char isClanItem;
    long long unk7;
};

struct Packet_Inventory_vtables
{
    void (__thiscall* Function1)(struct Packet_Inventory* this);
    void (__thiscall* descructor)(struct Packet_Inventory* this);
    void (__thiscall* Parse)(struct Packet_Inventory* this);
    void (__thiscall* nullfunc)(struct Packet_Inventory* this);
    void (__thiscall* SetInventoryItemUnk)(struct Packet_Inventory* this, InventoryItem* item);
    void (__thiscall* Function6)(struct Packet_Inventory* this, InventoryItem* item);
    void (*CallInventory_InventoryStuff)();
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
    void (__thiscall* GetUnk8)(struct Inventory* this);
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
    void (__thiscall* OnTattoo)(struct Inventory* this);
    void (__thiscall* Function20)(struct Inventory* this);
    void (__thiscall* Function21)(struct Inventory* this);
    void (__thiscall* Function22)(struct Inventory* this);
    void (__thiscall* Function23)(struct Inventory* this);
    void (__thiscall* Function24)(struct Inventory* this);
    void (__thiscall* SendItem02)(struct Inventory* this, int a, int b);
    void (__thiscall* UseItemIdk)(struct Inventory* this, int unk);
    void (__thiscall* RotationItemStuff)(struct Inventory* this, int unk = 0);
    void (__thiscall* SendUpdateInfoName)(struct Inventory* this);
    void (__thiscall* Function29)(struct Inventory* this);
    void (__thiscall* Function30)(struct Inventory* this);
    void (__thiscall* InventoryStuff)(struct Inventory* this);
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
    void (__thiscall* SendItem5Caller)(struct Inventory* this);
    void (__thiscall* SendItem6Caller)(struct Inventory* this);
    void (__thiscall* SendItem7Caller)(struct Inventory* this);
    void (__thiscall* SendItem14Caller)(struct Inventory* this);
    void (__thiscall* SendItem17Caller)(struct Inventory* this);
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
    void (__thiscall* SendItem8_0Caller)(struct Inventory* this);
    void (__thiscall* SendItem8_1Caller)(struct Inventory* this);
    void (__thiscall* SendItem9Caller)(struct Inventory* this);
    void (__thiscall* SendItem15Caller)(struct Inventory* this);
    void (__thiscall* Function66)(struct Inventory* this);
    void (__thiscall* Function67)(struct Inventory* this);
    void (__thiscall* GiftItem)(struct Inventory* this, int code);
    void (__thiscall* Function69)(struct Inventory* this);
    void (__thiscall* Function70)(struct Inventory* this);
    void (__thiscall* Function71)(struct Inventory* this);
    void (__thiscall* ItemExtend)(struct Inventory* this, bool unk1, int unk2);
    void (__thiscall* Function73)(struct Inventory* this);
    void (__thiscall* FabItemStuff1)(struct Inventory* this, int unk);
    void (__thiscall* FabItemStuff2)(struct Inventory* this, int unk);
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
    int unk15; // std::vector
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
