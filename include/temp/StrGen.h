struct StrGen_vtables {
    void (__thiscall* Function1)(struct StrGen* this);
    const wchar_t* (__thiscall* Localize_ConvertANSIToUnicode)(struct StrGen* this, const char* format);
    void (__thiscall* Function3)(struct StrGen* this);
    void (__thiscall* Function4)(struct StrGen* this);
    void (__thiscall* Function5)(struct StrGen* this);
    void (__thiscall* Function6)(struct StrGen* this);
    void (__thiscall* Function7)(struct StrGen* this);
    void (__thiscall* Function8)(struct StrGen* this);
    void (__thiscall* Function9)(struct StrGen* this);
    void (__thiscall* Function10)(struct StrGen* this);
    void (__thiscall* Function11)(struct StrGen* this);
    const char* (__thiscall* Function12)(struct StrGen* this, int, int, int, const wchar_t*);
    void (__thiscall* Function13)(struct StrGen* this);
    void (__thiscall* Function14)(struct StrGen* this);
    void (__thiscall* Function15)(struct StrGen* this);
    void (__thiscall* Function16)(struct StrGen* this);
    void (__thiscall* Function17)(struct StrGen* this);
    void (__thiscall* Function18)(struct StrGen* this);
    void (__thiscall* Function19)(struct StrGen* this);
    void (__thiscall* Function20)(struct StrGen* this);
    void (__thiscall* Function21)(struct StrGen* this);
    void (__thiscall* Function22)(struct StrGen* this);
    void (__thiscall* Function23)(struct StrGen* this);
    void (__thiscall* Function24)(struct StrGen* this);
    void (__thiscall* Function25)(struct StrGen* this);
    void (__thiscall* Function26)(struct StrGen* this);
    void (__thiscall* Function27)(struct StrGen* this);
    void (__thiscall* Function28)(struct StrGen* this);
    void (__thiscall* Function29)(struct StrGen* this);
    void (__thiscall* Function30)(struct StrGen* this);
    void (__thiscall* Function31)(struct StrGen* this);
    void (__thiscall* Function32)(struct StrGen* this);
    void (__thiscall* Function33)(struct StrGen* this);
    void (__thiscall* Function34)(struct StrGen* this);
    void (__thiscall* Function35)(struct StrGen* this);
    void (__thiscall* Function36)(struct StrGen* this);
    void (__thiscall* Function37)(struct StrGen* this);
    void (__thiscall* Function38)(struct StrGen* this);
    void (__thiscall* Function39)(struct StrGen* this);
    void (__thiscall* Function40)(struct StrGen* this);
    void (__thiscall* Function41)(struct StrGen* this);
    void (__thiscall* Function42)(struct StrGen* this);
    void (__thiscall* Function43)(struct StrGen* this);
    void (__thiscall* Function44)(struct StrGen* this);
    void (__thiscall* Function45)(struct StrGen* this);
};

struct StrGen
{
    StrGen_vtables* vfptr;
    int unk[122];
    vector unkVec1;
};