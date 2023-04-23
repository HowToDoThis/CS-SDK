struct CWeaponData
{
    int inGameID;
    char* szWpnName;
    char* szResourceName;
    char* szWpnCommand;
    char* szWpnModelV;
    char* szWpnModelP;
    char* szWpnModelW;
    int iAmmoType1;
    int iAmmoType2;
    int iAmmoClip;
    int iLevel;
    int iWeaponType;
    int unk12;
    float fArmor;
    float fMaxSpeed;
    int iCrosshairUnk1;
    int iCrosshairUnk2;
    int unk19;
    float fGround;
    float fAir;
    float fFly;
    float fDuck;
    float fStun;
    int iSpread;
    int iAccuracyFlag;
    int iWeaponFlag; // some flags
    int unk26;
};

struct CWeaponMgrTable
{
    void (__thiscall* AddWeapon)(struct CWeaponMgr* ptr, struct CWeaponData* data);
    struct CWeaponData* (__thiscall* FindByID)(struct CWeaponMgr* ptr, int a2);
    struct CWeaponData* (__thiscall* FindByCommand)(struct CWeaponMgr* ptr, const char* a2);
    struct CWeaponData* (__thiscall* FindByResource)(struct CWeaponMgr* ptr, const char* a2);
    bool (__thiscall* IsSomething)(struct CWeaponMgr* ptr, int a2);
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