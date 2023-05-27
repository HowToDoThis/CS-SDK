struct CSVLocalized_vtable
{
    void (__thiscall* Function1)(struct CSVLocalized* this);
    void (__thiscall* Function2)(struct CSVLocalized* this);
    void (__thiscall* DeleteArray)(struct CSVLocalized* this);
    void (__thiscall* destructor)(struct CSVLocalized* this);
    void (__thiscall* Function5)(struct CSVLocalized* this);
    void (__thiscall* Function6)(struct CSVLocalized* this);
    void (__thiscall* Function7)(struct CSVLocalized* this);
    void (__thiscall* Function8)(struct CSVLocalized* this);
    void (__thiscall* Function9)(struct CSVLocalized* this);
};

struct CSVLocalized
{
    CSVLocalized_vtable* vfptr;
    int probBuffer; // 256
    int unk2;
    int unk3;
    char unk4;
    void* unk5; // array
    int unk6;
};

struct StringTable : CSVLocalized
{
    void* unk1; // array
};

struct StringTableWrapper_vtable
{
    void (__thiscall* Function1)(struct StringTableWrapper* this);
    int (__thiscall* Function2)(struct StringTableWrapper* this, char*);
    void* (__thiscall* Function3)(struct StringTableWrapper* this, int, int);
    void (__thiscall* Function4)(struct StringTableWrapper* this);
    int (__thiscall* CSVReadInt)(struct StringTableWrapper* this, int, int, int*);
    void (__thiscall* CSVReadFloat)(struct StringTableWrapper* this, int, int, int*);
    int (__thiscall* Function7)(struct StringTableWrapper* this, int, int, int);
    void (__thiscall* Function8)(struct StringTableWrapper* this);
    void (__thiscall* Function9)(struct StringTableWrapper* this);
    void (__thiscall* Function10)(struct StringTableWrapper* this);
    void (__thiscall* Function11)(struct StringTableWrapper* this);
    int (__thiscall* Function12)(struct StringTableWrapper* this);
    int (__thiscall* Function13)(struct StringTableWrapper* this);
    void (__thiscall* Function14)(struct StringTableWrapper* this);
    void (__thiscall* Function15)(struct StringTableWrapper* this);
};

struct StringTableWrapper
{
    StringTableWrapper_vtable* vfptr;
    CSVLocalizedBase localized;
    int unk1;
};

struct CCSVMapList : StringTable
{
    char map1;
    char map2;
};

struct CCSVClientTable : CCSVMapList
{
};

struct RelationProductVtables
{
    void  (__thiscall* Function01)(struct RelationProduct* this);
    void  (__thiscall* Function02)(struct RelationProduct* this);
    void* (__thiscall* Function03)(struct RelationProduct* this);
    void  (__thiscall* Function04)(struct RelationProduct* this);
    void  (__thiscall* Function05)(struct RelationProduct* this);
    void  (__thiscall* Function06)(struct RelationProduct* this);
    void  (__thiscall* Function07)(struct RelationProduct* this);
    void  (__thiscall* Function08)(struct RelationProduct* this);
    void  (__thiscall* Function09)(struct RelationProduct* this);
    void  (__thiscall* Function10)(struct RelationProduct* this);
    void  (__thiscall* Function11)(struct RelationProduct* this);
    void  (__thiscall* Function12)(struct RelationProduct* this);
    void* (__thiscall* Function13)(struct RelationProduct* this);
    void  (__thiscall* Function14)(struct RelationProduct* this);
    void  (__thiscall* Function15)(struct RelationProduct* this);
    void  (__thiscall* Function16)(struct RelationProduct* this);
    void  (__thiscall* Function17)(struct RelationProduct* this);
    void  (__thiscall* Function18)(struct RelationProduct* this);
    void  (__thiscall* Function19)(struct RelationProduct* this);
    void  (__thiscall* Function20)(struct RelationProduct* this);
    void  (__thiscall* Function21)(struct RelationProduct* this);
    void  (__thiscall* Function22)(struct RelationProduct* this);
};

// CHN160531 Size 120
struct RelationProduct
{
    RelationProductVtables* vfptr;
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
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
};

struct GiftVtables
{
    void  (__thiscall* Function01)(struct Gift* this);
    void  (__thiscall* Function02)(struct Gift* this);
    void* (__thiscall* Function03)(struct Gift* this);
    void  (__thiscall* Function04)(struct Gift* this);
    void  (__thiscall* Function05)(struct Gift* this);
    void  (__thiscall* Function06)(struct Gift* this);
    void  (__thiscall* Function07)(struct Gift* this);
    void  (__thiscall* Function08)(struct Gift* this);
    void  (__thiscall* Function09)(struct Gift* this);
    void  (__thiscall* Function10)(struct Gift* this);
    void  (__thiscall* Function11)(struct Gift* this);
    void  (__thiscall* Function12)(struct Gift* this);
};

// CHN160531 Size 96
struct Gift
{
    GiftVtables* vfptr;
    RelationProduct* unk;
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
    int unk20;
    int unk21;
    int unk22;
};

struct GiftBoxVtables
{
    void  (__thiscall* Function01)(struct GiftBox* this);
    int   (__thiscall* Function02)(struct GiftBox* this);
    void* (__thiscall* Function03)(struct GiftBox* this);
    void  (__thiscall* Function04)(struct GiftBox* this);
    int   (__thiscall* Function05)(struct GiftBox* this, int);
    void  (__thiscall* SendShop7)(struct GiftBox* this);
    int   (__thiscall* Function07)(struct GiftBox* this);
    void  (__thiscall* SendShop3)(struct GiftBox* this);
    void  (__thiscall* SendShop4)(struct GiftBox* this);
    void  (__thiscall* SendShop5)(struct GiftBox* this);
    void  (__thiscall* SendShop10)(struct GiftBox* this);
    int   (__thiscall* Function12)(struct GiftBox* this);
    int   (__thiscall* SendShop6)(struct GiftBox* this);
    void  (__thiscall* Function14)(struct GiftBox* this);
    void  (__thiscall* Function15)(struct GiftBox* this);
    void  (__thiscall* Function16)(struct GiftBox* this);
};

struct GiftBox
{
    GiftBoxVtables* vfptr;
    char unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    short unk6A;
    int unkA[3];
    int unk7;
    int unk8;
    char unk9;
};

struct ItemCSV_tables
{
    void (__thiscall* Function1)(struct ItemCSV* this);
    void (__thiscall* Function2)(struct ItemCSV* this);
    void (__thiscall* Function3)(struct ItemCSV* this);
    void (__thiscall* Function4)(struct ItemCSV* this);
    void (__thiscall* Function5)(struct ItemCSV* this);
    void (__thiscall* Function6)(struct ItemCSV* this);
    void (__thiscall* Function7)(struct ItemCSV* this);
    void (__thiscall* Function8)(struct ItemCSV* this);
    void (__thiscall* Function9)(struct ItemCSV* this);
    void (__thiscall* Function10)(struct ItemCSV* this);
};

struct ItemCSV : CSVLocalized
{
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
};