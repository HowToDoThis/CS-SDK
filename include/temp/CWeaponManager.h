struct CWeaponData
{
    int inGameID;
    char* szWpnName;
    char* szResourceName;
    char* szWpnCommand;
    char* szWpnModelV;
    char* szWpnModelP;
    char* szWpnModelW;
    int unk07;
    int unk08;
    int unk09; // ammo
    int unk10; // like ammo but idk
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
    int unk25; // some flags
    int unk26;
};

struct CWeaponMgrTable
{
    void (__thiscall* AddWeapon)(struct CWeaponMgr* ptr, struct CWeaponData* data);
    struct CWeaponData* (__thiscall* FindByID)(struct CWeaponMgr* ptr, int a2);
    struct CWeaponData* (__thiscall* FindByCommand)(struct CWeaponMgr* ptr, const char* a2);
    struct CWeaponData* (__thiscall* FindByResource)(struct CWeaponMgr* ptr, const char* a2);
    void (__thiscall* IsSomething)(struct CWeaponMgr* ptr, int a2);
    void (__thiscall* GetSomething)(struct CWeaponMgr* ptr);
    void (__thiscall* FindByUnk)(struct CWeaponMgr* ptr, const char* a2);
    void (__thiscall* desctuctor)(struct CWeaponMgr* ptr);
};

struct CWeaponMgr
{
    struct CWeaponMgrTable* vfptr;
    struct CWeaponData* weapons;
    int unk1;
    int unk2;
};