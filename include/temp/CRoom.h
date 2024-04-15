struct RoomMatchSettingsUnk {
    int unk1;
    int unk2;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    int unk7;
    char unk8;
    char unk9;
};

struct MapPool {
    char randomType;
    int mapID;
};

struct CRoomSettingPart {
    // 0x10
    char levelLimit;
    // 0x20
    char unk10;
    // 0x40
    char gameMode;
    // 0x80, High 0x10000
    char mapID;

    //CRoomSetting setting; // some stuff
    int unk16; // ??

    // 0x200
    char winLimit;
    // 0x400
    int needKills;
    // 0x800
    char gameTime;
    // 0x1000
    float roundTime;
    // High 0x20000
    char zombieLimit;
    int bannedZombie[3];
    // 0x2000
    char weaponRestriction;
    // 0x4000
    char hostagePenalty;
    // 0x8000
    char freezeTime;
    // 0x10000
    float buyTime;
    // 0x20000
    char displayName;
    // 0x40000
    char teamBalance;
    // 0x80000
    char unk21;
    // 0x100000
    char friendlyFire;
    // 0x200000
    char flashlight;
    // 0x400000
    char footsteps;
    // 0x800000
    char unk25;
    // 0x1000000
    char unk26;
    // 0x2000000
    char unk27;
    // 0x4000000
    char unk28;
    // 0x8000000
    char unk29;
    // 0x10000000
    char unk30;
    // 0x20000000
    char voiceChat;
    // High 0x2
    char bombTimer;
    // High 0x10
    short startCash;
    // High 0x20
    char movingShot;
    // High 0x40
    char unk46;
    // High 0x100
    char randomMap;
    // High 0x200
    char mapPoolCount;
    MapPool mapPools[5];
    // High 0x400
    char unk50;

    char unk51;

    // High 0x800
    char wpnRestriction;
    // High 0x1000
    char isSoySD;
    // High 0x2000
    char zsDiff;
    float zsExps;
    float zsPoints;
    // High 0 < 0
    char unk52;

    // High 0x4000
    char leagueRule;
    // High 0x8000
    char mannerLimit;

    // idk what the fuck
    int undef3[34]; // startCash = 50, MapPools = 39

    // flag < 0
    char unk31;
    int unk32[12];
};

struct CRoom
{
    // 0x40000000
    int roomState;

    // 0x1
    struct wstring roomName;
    // 0x2
    char unk2;
    // 0x4
    char unk3;
    char unk4;
    int unk5;
    // 0x100
    char maxPlayers;
    char unk6b;
    char unk6c;
    char unk6d;

    // 0x8
    struct wstring password;

    // High 0x8
    char killDeathRules;

    //int unk7; // ?
    int unk8; // ?

    CRoomSettingPart settings;

    // High Flags
    // 0x1
    int unk33;
    struct wstring unk34;
    char unk35;
    char unk36;
    char unk37;
    // 0x4
    int botDiff;
    int botCT;
    int botTR;
    int botBalance;

    // Unknown
    int nf0;
    char flags;
    int usersCount;
    int vUserID[32];
    // CGameUser????
};

struct CGameRoomManagerVfptr
{
    void (__thiscall* Init)(struct CGameRoomManager* this);
    void (__thiscall* Shutdown)(struct CGameRoomManager* this);
    void (__thiscall* Function3)(struct CGameRoomManager* this);
    void (__thiscall* Function4)(struct CGameRoomManager* this);
    void (__thiscall* SendVoteKick)(struct CGameRoomManager* this,int,int,char*,char);
    void (__thiscall* SendVoteSelect)(struct CGameRoomManager* this);
    void (__thiscall* SendRoom20)(struct CGameRoomManager* this);
    void (__thiscall* SendRoom10)(struct CGameRoomManager* this);
    void (__thiscall* Function9)(struct CGameRoomManager* this);
    void (__thiscall* Function10)(struct CGameRoomManager* this);
    void (__thiscall* Function11)(struct CGameRoomManager* this);
    int  (__thiscall* Function12)(struct CGameRoomManager* this);
    char (__thiscall* GetRoomState)(struct CGameRoomManager* this);
    void (__thiscall* Function14)(struct CGameRoomManager* this);
    void (__thiscall* Function15)(struct CGameRoomManager* this);
    void (__thiscall* SendRoom4)(struct CGameRoomManager* this);
    void (__thiscall* Function17)(struct CGameRoomManager* this);
    void (__thiscall* NULLFUNC18)(struct CGameRoomManager* this);
    void (__thiscall* NULLFUNC19)(struct CGameRoomManager* this);
    void (__thiscall* Function20)(struct CGameRoomManager* this);
};

// CHN160531
// size 68 (44)
struct CGameRoomManager
{
    CGameRoomManagerVfptr* vfptr;

    int unk1; // array?
    int unk2;
    int unk3;

    int unk4;
    char roomState;
    char unk5b;
    int unk6;
    short unk7;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    int unk12;
    short unk13;
    char unk13a;
    char unk13b;

    int unk14; // array?
    int unk15;
    int unk16;
};

struct CGameRoom
{
    void* vfptr;
    int unk01;
    char* password;
    int maxLevel;
    int unk04;
    char* roomName;
    int unk06;
    int unk07;
    int maxPlayers;
    int gameMode;
    int mapID;
    int unk11;
    int unk12;
    short unk13;
    int unk14;
    short unk15;
    char unk15a;
    char clanMatch; // bool
    char banList; // bool
    char quickStart; // bool
    char unk18;
    char unk19a;
    char overDeath; // bool
    char unk19aa;
    char unk19ab;
    int winLimit;
    int killLimit;
    int timeLimit;
    int roundTime;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int clanMatchMode;
    int startingCash;
    int unk31;
    int unk32;
    int unk33;
    char unk34;
    int unk35;
    int unk36;
    int unk37; // 128?? or longlong
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42; // 128?? or long long
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int difficulty;
    int unk51;
    int unk52;
    int unk53;
    long long unk54; // QWORD
    int unk56;
    char unk57;
};