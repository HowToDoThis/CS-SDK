struct CBaseEntity_vt {
    void (__thiscall* Function1)(struct CBaseEntity* this);
    void (__thiscall* Function2)(struct CBaseEntity* this);
    void (__thiscall* Spawn)(struct CBaseEntity* this);
    void (__thiscall* Function4)(struct CBaseEntity* this);
    void (__thiscall* Function5)(struct CBaseEntity* this);
    void (__thiscall* Function6)(struct CBaseEntity* this);
    void (__thiscall* Function7)(struct CBaseEntity* this);
    void (__thiscall* Function8)(struct CBaseEntity* this);
    void (__thiscall* Function9)(struct CBaseEntity* this);
    void (__thiscall* Function10)(struct CBaseEntity* this);
    void (__thiscall* Function11)(struct CBaseEntity* this);
    void (__thiscall* Function12)(struct CBaseEntity* this);
    void (__thiscall* Function13)(struct CBaseEntity* this);
    void (__thiscall* Function14)(struct CBaseEntity* this);
    void (__thiscall* Function15)(struct CBaseEntity* this);
    void (__thiscall* Function16)(struct CBaseEntity* this);
    void (__thiscall* Function17)(struct CBaseEntity* this);
    void (__thiscall* Function18)(struct CBaseEntity* this);
    void (__thiscall* Function19)(struct CBaseEntity* this);
    void (__thiscall* Function20)(struct CBaseEntity* this);
    void (__thiscall* Function21)(struct CBaseEntity* this);
    void (__thiscall* Function22)(struct CBaseEntity* this);
    void (__thiscall* Function23)(struct CBaseEntity* this);
    void (__thiscall* Function24)(struct CBaseEntity* this);
    void (__thiscall* Function25)(struct CBaseEntity* this);
    void (__thiscall* Function26)(struct CBaseEntity* this);
    void (__thiscall* Function27)(struct CBaseEntity* this);
    void (__thiscall* Function28)(struct CBaseEntity* this);
    void (__thiscall* Function29)(struct CBaseEntity* this);
    void (__thiscall* Function30)(struct CBaseEntity* this);
    void (__thiscall* Function31)(struct CBaseEntity* this);
    void (__thiscall* Function32)(struct CBaseEntity* this);
    void (__thiscall* Function33)(struct CBaseEntity* this);
    void (__thiscall* Function34)(struct CBaseEntity* this);
    void (__thiscall* Function35)(struct CBaseEntity* this);
    void (__thiscall* Function36)(struct CBaseEntity* this);
    void (__thiscall* Function37)(struct CBaseEntity* this);
    void (__thiscall* Function38)(struct CBaseEntity* this);
    void (__thiscall* Function39)(struct CBaseEntity* this);
    void (__thiscall* Function40)(struct CBaseEntity* this);
    void (__thiscall* Function41)(struct CBaseEntity* this);
    void (__thiscall* Function42)(struct CBaseEntity* this);
    void (__thiscall* Function43)(struct CBaseEntity* this);
    void (__thiscall* Function44)(struct CBaseEntity* this);
    void (__thiscall* Function45)(struct CBaseEntity* this);
    void (__thiscall* Function46)(struct CBaseEntity* this);
    void (__thiscall* Function47)(struct CBaseEntity* this);
    void (__thiscall* Function48)(struct CBaseEntity* this);
    void (__thiscall* Function49)(struct CBaseEntity* this);
    void (__thiscall* Function50)(struct CBaseEntity* this);
    void (__thiscall* Function51)(struct CBaseEntity* this);
    void (__thiscall* Function52)(struct CBaseEntity* this);
    void (__thiscall* Function53)(struct CBaseEntity* this);
    void (__thiscall* Function54)(struct CBaseEntity* this);
    void (__thiscall* Function55)(struct CBaseEntity* this);
    void (__thiscall* Function56)(struct CBaseEntity* this);
    void (__thiscall* Function57)(struct CBaseEntity* this);
    void (__thiscall* Function58)(struct CBaseEntity* this);
    void (__thiscall* Function59)(struct CBaseEntity* this);
    void (__thiscall* Function60)(struct CBaseEntity* this);
    void (__thiscall* Function61)(struct CBaseEntity* this);
    void (__thiscall* Function62)(struct CBaseEntity* this);
    void (__thiscall* Function63)(struct CBaseEntity* this);
    void (__thiscall* Function64)(struct CBaseEntity* this);
    void (__thiscall* Function65)(struct CBaseEntity* this);
    void (__thiscall* Function66)(struct CBaseEntity* this);
    void (__thiscall* Function67)(struct CBaseEntity* this);
    void (__thiscall* Function68)(struct CBaseEntity* this);
    void (__thiscall* Function69)(struct CBaseEntity* this);
    void (__thiscall* Function70)(struct CBaseEntity* this);
    void (__thiscall* Function71)(struct CBaseEntity* this);
    void (__thiscall* Function72)(struct CBaseEntity* this);
    void (__thiscall* Function73)(struct CBaseEntity* this);
    void (__thiscall* Function74)(struct CBaseEntity* this);
    void (__thiscall* Function75)(struct CBaseEntity* this);
    void (__thiscall* Function76)(struct CBaseEntity* this);
};

struct CBaseEntity {
    CBaseEntity_vt* vfptr;

    struct entvars_t* pev;
    CBaseEntity* m_pGoalEnt;
    CBaseEntity* m_pLink;

    // TYPEDESCRIPTION
    int undef1[4];

    void* m_pfnThink;
    void* m_pfnTouch;
    void* m_pfnUse;
    void* m_pfnBlocked;

    // Special stuff for grenades and knife.
    float m_flStartThrow;
    float m_flReleaseThrow;
    int m_iSwing;

    // client has left the game
    bool has_disconnected;
};