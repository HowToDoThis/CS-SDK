enum AmmoType
{
    // AMMO_
    AMMO_NONE,
    AMMO_BUCKSHOT,
    AMMO_9MM,
    AMMO_556NATO,
    AMMO_556NATOBOX,
    AMMO_762NATO,
    AMMO_45ACP,
    AMMO_50AE,
    AMMO_338MAGNUM,
    AMMO_57MM,
    AMMO_357SIG,
    AMMO_46MM,
    AMMO_58MM,
    AMMO_BUCKSHOT2,
    AMMO_SVDEXGRENADES,
    AMMO_M79GRENADE,
    AMMO_BOLTS,
    AMMO_556AZ,
    AMMO_AT4ROCKET,
    AMMO_50BMG,
    AMMO_545MM,
    AMMO_FLAMEGAS,
    AMMO_IRONBEAD,
    AMMO_792KURZ,
    AMMO_762NATOBOX,
    AMMO_50AZ,
    AMMO_45ACPAZ,
    AMMO_CANNON,
    AMMO_BUCKSHOTAZ,
    AMMO_FIRECRACKER,
    AMMO_MOUNTGUN,
    AMMO_ETHER,
    AMMO_M32GRENADES,
    AMMO_POISONGUN,
    AMMO_762NATOBOXEX,
    AMMO_556LVB,
    AMMO_556AAP,
    AMMO_OCIWGRENADES,
    AMMO_RAILBEAM,
    AMMO_556NATOBOXICE,
    AMMO_473CASELESS,
    AMMO_50BCS,
    AMMO_CHAINSAW,
    AMMO_FGLAUNCHER_ROCKET,
    AMMO_COIL,
    AMMO_BUCKBCS,
    AMMO_BUCKSHOTB,
    AMMO_PLASMA,
    AMMO_FROSTGAS,
    AMMO_TKNIFE,
    AMMO_BOWARROW,
    AMMO_DRILL,
    AMMO_JANUS1,
    AMMO_9X39MM,
    AMMO_BUCKSHOTSNOW,
    AMMO_SPEAR,
    AMMO_50BMGBOX,
    AMMO_ENERGYCELL,
    AMMO_PETROLBOOMER,
    AMMO_50BMGHOLY,
    AMMO_DEPLETEDALLOY,
    AMMO_BLOCKBULLET,
    AMMO_BLOCKMISSILE,
    AMMO_556NATOBOX2,
    AMMO_THANATOSSCYTHE,
    AMMO_GUILLOTINEAMMO,
    AMMO_9MMPARABELLUM,
    AMMO_DARTBOMB,
    AMMO_THANATOS5GRENADES,
    AMMO_VULCANUS7ROCKET,
    AMMO_COILMG,
    AMMO_H20,
    AMMO_H202,
    AMMO_AIRGAS,
    AMMO_BLOCKASBULLET,
    AMMO_BLOCKASMISSLE,
    AMMO_SMARTBULLET,
    AMMO_9MM_2,
    AMMO_LASER,
    AMMO_THANATOS1BLADE,
    AMMO_BUFFBULLET,
    AMMO_50BMG_2,
    AMMO_THANATOS3BLADE,
    AMMO_BUCKSHOTV,
    AMMO_THANATOS3_46MM,
    AMMO_SGDRILL_BUCKSHOT,
    AMMO_20MM,
    AMMO_BLOCKMGMISSLE,
    AMMO_BLOODHUNTER45ACP,
    AMMO_MAX_TYPES,
};

// CHN160531
// Total: 88
struct AmmoInfoStruct
{
    AmmoType ammoType;
    int clipCost;
    int buyClipSize;
    int maxRounds;
    const char *ammoName2;
    const char *ammoName1;
};

struct CWeaponData
{
    int inGameID;
    char* szWpnName;
    char* szResourceName;
    char* szWpnCommand;
    char* szWpnModelV;
    char* szWpnModelP;
    char* szWpnModelW;
    AmmoInfoStruct* pAmmoInfo1;
    int iAmmoType2;
    int iAmmoClip;
    int iWeight; // CBasePlayerWeapon::GetItemInfo
    int iWeaponType;
    int iPosition; // CBasePlayerWeapon::GetItemInfo
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
    int iFlags; // CBasePlayerWeapon::GetItemInfo
};

struct CWeaponMgrTable
{
    void (__thiscall* AddWeapon)(struct CWeaponMgr* ptr, struct CWeaponData* data);
    struct CWeaponData* (__thiscall* FindByID)(struct CWeaponMgr* ptr, int a2);
    struct CWeaponData* (__thiscall* FindByCommand)(struct CWeaponMgr* ptr, const char* a2);
    struct CWeaponData* (__thiscall* FindByResource)(struct CWeaponMgr* ptr, const char* a2);
    bool (__thiscall* IsSomething)(struct CWeaponMgr* ptr, int a2);
    void (__thiscall* GetSomething)(struct CWeaponMgr* ptr, int weaponID, float *fGround, float *fAir, float *fFly, float *fDuck, float *fStun, bool *fFlagUnk);
    void (__thiscall* FindByUnk)(struct CWeaponMgr* ptr, const char* a2);
    void (__thiscall* desctuctor)(struct CWeaponMgr* ptr);
};

struct CWeaponMgr
{
    struct CWeaponMgrTable* vfptr;
    struct vector weaponData;
};