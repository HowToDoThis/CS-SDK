struct AnnounceTable_vfptr {
    void (__thiscall* Function1)(struct AnnounceTable* this);
    void (__thiscall* Function2)(struct AnnounceTable* this);
    void (__thiscall* Function3)(struct AnnounceTable* this);
    void (__thiscall* Function4)(struct AnnounceTable* this);
    void (__thiscall* Function5)(struct AnnounceTable* this);
    void (__thiscall* Function6)(struct AnnounceTable* this);
};

struct AnnounceTable {
    AnnounceTable_vfptr* vfptr;
    vector vRibbon;
    vector vCategory;
};