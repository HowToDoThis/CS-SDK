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

struct ItemCSV
{
    struct ItemCSV_tables* vfptr;
    int unk0;
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
};