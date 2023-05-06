#define ZombieCount 14
#define ZombieSkillCount 7

struct CZBEnhanceMgr_vtables
{
    void (__thiscall* Init)(struct CZBEnhanceMgr* this);
    void (__thiscall* InitList)(struct CZBEnhanceMgr* this);
    void (__thiscall* DeleteList)(struct CZBEnhanceMgr* this);
    void (__thiscall* SendEvolveInfo)(struct CZBEnhanceMgr* this);
    void (__thiscall* SendEvolveExp)(struct CZBEnhanceMgr* this);
    void (__thiscall* SendEvolveRequest)(struct CZBEnhanceMgr* this, int zbType);
    void (__thiscall* GetZombieEnhance)(struct CZBEnhanceMgr* this);
    void (__thiscall* GetZombieSkill)(struct CZBEnhanceMgr* this);
    void (__thiscall* GetZombieSkillExp)(struct CZBEnhanceMgr* this);
    void (__thiscall* SetZombieEnhance)(struct CZBEnhanceMgr* this, int a2, int a3);
    void (__thiscall* SetZombieSkill)(struct CZBEnhanceMgr* this, int a2, int a3, int a4);
    void (__thiscall* SetZombieSkillExp)(struct CZBEnhanceMgr* this, int a, int b, int c);
    void (__thiscall* SendDNARequest)(struct CZBEnhanceMgr* this, bool remove, char dnaSkill);
    void (__thiscall* SendDNAReset)(struct CZBEnhanceMgr* this);
    void (__thiscall* GetDNAPoint)(struct CZBEnhanceMgr* this);
    void (__thiscall* SetDNAPoint)(struct CZBEnhanceMgr* this, int a);
    void (__thiscall* GetDNASkill)(struct CZBEnhanceMgr* this);
    void (__thiscall* SetDNASkill)(struct CZBEnhanceMgr* this, int a, bool b, int c = 0);
};

struct CZBEnhanceMgr
{
    CZBEnhanceMgr_vtables* vfptr;
    void* vfptr2; // another table? related PacketListener
    struct CPacket_ZBEnhance* packetZBEnhance;
    int iZombie[ZombieCount];
    int iZombieSkill[ZombieCount][ZombieSkillCount];
    int iZombieSkillExp[ZombieCount][ZombieSkillCount];
    int dnaPoints;
    char dnaSkill[18];
    char unk7;
};