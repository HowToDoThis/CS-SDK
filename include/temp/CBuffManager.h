struct CBuffManager_vtables
{
    void (__thiscall* Function1)(struct CBuffManager* this);
    void (__thiscall* Function2)(struct CBuffManager* this);
    void (__thiscall* Function3)(struct CBuffManager* this);
    void (__thiscall* Function4)(struct CBuffManager* this);
    void (__thiscall* Function5)(struct CBuffManager* this);
    void (__thiscall* Function6)(struct CBuffManager* this);
    void (__thiscall* Function7)(struct CBuffManager* this);
    void (__thiscall* Function8)(struct CBuffManager* this);
};

struct CBuffManager
{
    CBuffManager_vtables* vfptr;
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
    int unk15; // some shit
    int unk16;
    int unk17; // some shit
    int unk18;
};