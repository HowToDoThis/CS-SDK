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

// for StringTableWrapper only...
struct StringTableBase
{
    CSVLocalizedBase localized;
    int unk1;
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
    StringTableBase base;
};

struct CCSVMapList : StringTable
{
    char map1;
    char map2;
};

struct CCSVClientTable : CCSVMapList
{
};