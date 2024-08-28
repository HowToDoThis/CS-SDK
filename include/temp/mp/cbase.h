#define BIT(n) (1<<(n))

typedef enum TeamName_s {
    UNASSIGNED,
    TERRORIST,
    CT,
    SPECTATOR,
} TeamName;

typedef enum walkmove_s { WALKMOVE_NORMAL, WALKMOVE_WORLDONLY, WALKMOVE_CHECKONLY, } walkmove_t;
typedef enum dead_s { DEAD_NO, DEAD_DYING, DEAD_DEAD, DEAD_RESPAWNABLE, DEAD_DISCARDBODY, } dead_t;
typedef enum damage_s { DAMAGE_NO, DAMAGE_YES, DAMAGE_AIM, } damage_t;
typedef enum solid_s { SOLID_NOT, SOLID_TRIGGER, SOLID_BBOX, SOLID_SLIDEBOX, SOLID_BSP, } solid_t;
typedef enum movetype_s {
    MOVETYPE_NONE = 0,
    MOVETYPE_ANGLENOCLIP = 1,
    MOVETYPE_ANGLECLIP = 2,
    MOVETYPE_WALK = 3,
    MOVETYPE_STEP = 4,
    MOVETYPE_FLY = 5,
    MOVETYPE_TOSS = 6,
    MOVETYPE_PUSH = 7,
    MOVETYPE_NOCLIP = 8,
    MOVETYPE_FLYMISSLE = 9,
    MOVETYPE_BOUNCE = 10,
    MOVETYPE_BOUNCEMISSLE = 11,
    MOVETYPE_FOLLOW = 12,
    MOVETYPE_PUSHSTEP = 13,
} movetype_t;
typedef enum flags_s { FL_FLY = BIT(0), FL_SWIM = BIT(1), FL_CONVEYOR = BIT(2),
                       FL_CLIENT = BIT(3), FL_INWATER = BIT(4), FL_MONSTER = BIT(5), 
                       FL_GODMODE = BIT(6), FL_NOTARGET = BIT(7), FL_SKIPLOCALHOST = BIT(8), 
                       FL_ONGROUND = BIT(9), FL_PARTIALGROUND = BIT(10), FL_WATERJUMP = BIT(11),
                       FL_FROZEN = BIT(12), FL_FAKECLIENT = BIT(13), FL_DUCKING = BIT(14),
                       FL_FLOAT = BIT(15), FL_GRAPHED = BIT(16), FL_IMMUNE_WATER = BIT(17),
                       FL_IMMUNE_SLIME = BIT(18), FL_IMMUNE_LAVA = BIT(19), FL_PROXY = BIT(20),
                       FL_ALWAYSTHINK = BIT(21), FL_BASEVELOCITY = BIT(22), FL_MONSTERCLIP = BIT(23),
                       FL_ONTRAIN = BIT(24), FL_WORLDBRUSH = BIT(25), FL_SPECTATOR = BIT(26),
                       FL_CUSTOMENTITY = BIT(29), FL_KILLME = BIT(30), FL_DORMANT = BIT(31),
} flag_t;
typedef enum damage_s { DMG_GENERIC = 0,
                        DMG_CRUSH = BIT(0), DMG_BULLET = BIT(1), DMG_SLASH = BIT(2),
                        DMG_BURN = BIT(3), DMG_FREEZE = BIT(4), DMG_FALL = BIT(5), 
                        DMG_BLAST = BIT(6), DMG_CLUB = BIT(7), DMG_SHOCK = BIT(8), 
                        DMG_SONIC = BIT(9), DMG_ENERGYBEAM = BIT(10),
                        DMG_NEVERGIB = BIT(12), DMG_ALWAYSGIB = BIT(13), DMG_DROWN = BIT(14),
                        DMG_PARALYZE = BIT(15), DMG_NERVEGAS = BIT(16), DMG_POISON = BIT(17),
                        DMG_RADIATION = BIT(18), DMG_DROWNRECOVER = BIT(19), DMG_ACID = BIT(20),
                        DMG_SLOWBURN = BIT(21), DMG_SLOWFREEZE = BIT(22), DMG_MORTAR = BIT(23),
                        DMG_EXPLOSION = BIT(24),

                        DMG_GIB_CORPSE = (DMG_CRUSH | DMG_FALL | DMG_BLAST | DMG_SONIC | DMG_CLUB),
                        DMG_SHOWNHUD = (DMG_POISON | DMG_ACID | DMG_FREEZE | DMG_SLOWFREEZE | DMG_DROWN | DMG_BURN | DMG_SLOWBURN | DMG_NERVEGAS | DMG_RADIATION | DMG_SHOCK),
} damage_t;
typedef enum USE_TYPE_s { USE_OFF, USE_ON, USE_SET, USE_TOGGLE } USE_TYPE;

typedef struct MonsterEvent_s {
    int event;
    char *options;
} MonsterEvent_t;

typedef struct {
    int id;
    int version;
    char name[64];
    int length;
    vec3_t eyeposition;    // ideal eye position
    vec3_t min;        // ideal movement hull size
    vec3_t max;
    vec3_t bbmin;        // clipping bounding box
    vec3_t bbmax;
    int flags;
    int numbones;        // bones
    int boneindex;
    int numbonecontrollers;    // bone controllers
    int bonecontrollerindex;
    int numhitboxes;    // complex bounding boxes
    int hitboxindex;
    int numseq;        // animation sequences
    int seqindex;
    int numseqgroups;    // demand loaded sequences
    int seqgroupindex;
    int numtextures;    // raw textures
    int textureindex;
    int texturedataindex;
    int numskinref;        // replaceable textures
    int numskinfamilies;
    int skinindex;
    int numbodyparts;
    int bodypartindex;
    int numattachments;    // queryable attachable points
    int attachmentindex;
    int soundtable;
    int soundindex;
    int soundgroups;
    int soundgroupindex;
    int numtransitions;    // animation node to animation node transition graph
    int transitionindex;
} studiohdr_t;

// sequence descriptions
typedef struct {
    char label[32];        // sequence label
    float fps;        // frames per second
    int flags;        // looping/non-looping flags
    int activity;
    int actweight;
    int numevents;
    int eventindex;
    int numframes;        // number of frames per sequence
    int numpivots;        // number of foot pivots
    int pivotindex;
    int motiontype;
    int motionbone;
    vec3_t linearmovement;
    int automoveposindex;
    int automoveangleindex;
    vec3_t bbmin;        // per sequence bounding box
    vec3_t bbmax;
    int numblends;
    int animindex;        // mstudioanim_t pointer relative to start of sequence group data
    // [blend][bone][X, Y, Z, XR, YR, ZR]
    int blendtype[2];    // X, Y, Z, XR, YR, ZR
    float blendstart[2];    // starting value
    float blendend[2];    // ending value
    int blendparent;
    int seqgroup;        // sequence group for demand loading
    int entrynode;        // transition node at entry
    int exitnode;        // transition node at exit
    int nodeflags;        // transition rules
    int nextseq;        // auto advancing sequences
} mstudioseqdesc_t;

typedef struct mstudioevent_s {
    int frame;
    int event;
    int type;
    char options[64];
} mstudioevent_t;

enum ArmorType {
    ARMOR_NONE,     // No armor
    ARMOR_KEVLAR,   // Body vest only
    ARMOR_VESTHELM, // Vest and helmet
};
enum JoinState {
    JOINED,
    SHOWLTEXT,
    READINGLTEXT,
    SHOWTEAMSELECT,
    PICKINGTEAM,
    GETINTOGAME
};
enum ModelName {
    MODEL_UNASSIGNED,
    MODEL_URBAN,
    MODEL_TERROR,
    MODEL_LEET,
    MODEL_ARCTIC,
    MODEL_GSG9,
    MODEL_GIGN,
    MODEL_SAS,
    MODEL_GUERILLA,
    MODEL_VIP,
    MODEL_MILITIA,
    MODEL_SPETSNAZ,
    MODEL_AUTO
};
enum IgnoreChatMsg : int {
    IGNOREMSG_NONE,  // Nothing to do
    IGNOREMSG_ENEMY, // To ignore any chat messages from the enemy
    IGNOREMSG_TEAM   // Same as IGNOREMSG_ENEMY but ignore teammates
};
enum _Menu {
    Menu_OFF,
    Menu_ChooseTeam,
    Menu_IGChooseTeam,
    Menu_ChooseAppearance,
    Menu_Buy,
    Menu_BuyPistol,
    Menu_BuyRifle,
    Menu_BuyMachineGun,
    Menu_BuyShotgun,
    Menu_BuySubMachineGun,
    Menu_BuyItem,
    Menu_Radio1,
    Menu_Radio2,
    Menu_Radio3,
    Menu_ClientBuy
};

#define MAX_RECENT_PATH 20
#define MAX_PLAYER_NAME_LENGTH 32
#define MAX_ITEMS 4
#define MAX_SUIT_NOREPEAT 32
// max of 4 suit sentences queued up at any time
#define MAX_SUIT_PLAYLIST 4
// only load first n chars of name
#define MAX_TEXTURENAME_LENGHT 17
#define MAX_ITEM_TYPES 6
#define MAX_AMMO_SLOTS 93
#define MAX_SBAR_STRING 128
#define MAX_TEAM_NAME_LENGTH 16
#define MAX_AUTOBUY_LENGTH 256
#define MaxLocationLen 32

#define MAX_WEAPONS 352

struct AmmoInfo {
	const char *pszName;
	int iId;
};

struct ItemInfo {
	int iSlot;
	int iPosition;
	const char *pszAmmo1;
	int iMaxAmmo1;
	const char *pszAmmo2;
	int iMaxAmmo2;
	const char *pszName;
	int iMaxClip;
	int iId;
	int iFlags;
	int iWeight;
};

struct CUtlMemory {
    void* vfptr;
    CUtlMemory* m_pMemory;
    int m_nAllocationCount;
    int m_nGrowSize;
};

struct CUtlvec3_t {
    void* vfptr;
    CUtlMemory* m_memory;
    int m_Size;
    CUtlvec3_t *m_pElements;
};

struct CHintMessageQueue {
    void* vfptr;
    float m_tmMessageEnd;
    CUtlvec3_t m_messages;
};

struct CUnifiedSignals {
    int m_flSignal;
    int m_flState;
};

enum sbar_data {
    SBAR_ID_TARGETTYPE = 1,
    SBAR_ID_TARGETNAME,
    SBAR_ID_TARGETHEALTH,
    SBAR_END,
};
enum MusicState { SILENT, CALM, INTENSE };

struct RebuyStruct {
    void* vfptr;
    int m_primaryWeapon;
    int m_primaryAmmo;
    int m_secondaryWeapon;
    int m_secondaryAmmo;
    int m_heGrenade;
    int m_flashbang;
    int m_smokeGrenade;
    int m_defuser;
    int m_nightVision;
    ArmorType m_armor;
};

enum TrackCommands {
    CMD_SAY = 0,
    CMD_SAYTEAM,
    CMD_FULLUPDATE,
    CMD_VOTE,
    CMD_VOTEMAP,
    CMD_LISTMAPS,
    CMD_LISTPLAYERS,
    CMD_NIGHTVISION,
    COMMANDS_TO_TRACK,
};

class CBaseEntity {
public:
    virtual void Function1(); // unk ptr
    virtual void Function2(); // null most
    virtual void Spawn();
    virtual void Precache();
    virtual void Restart();
    virtual void KeyValue();
    virtual void Save();
    virtual void Restore();
    virtual void ObjectCaps();
    virtual void Activate();
    virtual void SetObjectCollisionBox();
    virtual CLASSIFY Classify();
    virtual void DeathNotice(struct entvars_t*);
    virtual void TraceAttack(entvars_t *pevAttacker, float flDamage, float vecDir0, float vecDir01, float vecDir2, TraceResult *ptra, int bitsDamageType);
    virtual void TraceAttack_Proxy(entvars_t *pevAttacker, float flDamage, float vecDir0, float vecDir1, float vecDir2, TraceResult *ptra, int bitsDamageType, int);
    virtual BOOL TakeDamage(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
    virtual BOOL TakeHealth();
    virtual void Killed(entvars_t *pevAttacker, int iGib);
    virtual int BloodColor();
    virtual void TraceBleed(float flDamage, vec3_t vecDir, struct TraceResult *ptr, int bitsDamageType);
    virtual BOOL IsTriggered();
    virtual class CBaseMonster*  MyMonsterPointer();
    virtual class CSquadMonster* MySquadMonsterPointer();
    virtual void GetToggleState();
    virtual void AddPoints();
    virtual void AddPointsToTeam();
    virtual BOOL AddPlayerItem();
    virtual BOOL RemovePlayerItem();
    virtual int GiveAmmo(int iCount, const char* szName, int iMax);
    virtual void GetDelay();
    virtual void IsMoving();
    virtual void OverrideReset();
    virtual void DamageDecal(int bitsDamageType);
    virtual void SetToggleState();
    virtual void StartSneaking();
    virtual void StopSneaking();
    virtual void OnControls();
    virtual BOOL IsSneaking();
    virtual BOOL IsAlive();
    virtual BOOL IsBSPModel();
    virtual BOOL ReflectGauss();
    virtual BOOL HasTarget();
    virtual BOOL IsInWorld();
    virtual BOOL IsPlayer();
    virtual BOOL IsNetClient();
    virtual void TeamID();
    virtual void GetKnockbackData();
    virtual void GetArmorData();
    virtual void CSO_ADD_1();
    virtual struct CBaseEntity* GetNextTarget();
    virtual void Think();
    virtual void Touch(CBaseEntity *pOther);
    virtual void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
    virtual void Blocked(CBaseEntity *pOther);
    virtual void UpdateOnRemove();
    virtual void CSO_ADD_2();
    virtual struct CBaseEntity* Respawn();
    virtual void CSO_ADD_3();
    virtual void CSO_ADD_4();
    virtual vec_t* Center(vec_t*);
    virtual vec_t* EyePosition(vec_t*);
    virtual vec_t* EarPosition(vec_t*);
    virtual vec_t* BodyTarget(vec_t*);
    virtual void CSO_ADD_5();
    virtual int Illumination();
    virtual BOOL FVisibleV();
    virtual BOOL FVisibleE();
    virtual void CSO_ADD_6();
    virtual void CSO_ADD_7();
    virtual void CSO_ADD_8();
    virtual void CSO_ADD_9();
    virtual void CSO_ADD_10();
    virtual int CSO_ADD_11();
    virtual int CSO_ADD_12(CBasePlayer*);
    virtual void CSO_ADD_13(); // UTIL_GetGlobalTrace
    virtual void CSO_ADD_14();

public:
    struct entvars_t* pev; // ok
    CBaseEntity* m_pGoalEnt;
    CBaseEntity* m_pLink;
    int undef1[4]; // TYPEDESCRIPTION
    void* m_pfnThink; // ok
    void* m_pfnTouch; // ok
    void* m_pfnUse; // ok
    void* m_pfnBlocked; // ok
    AmmoInventory ammoTypes[35]; // CBasePlayer::TabulateAmmo, maybe ok
    float m_flStartThrow; // ok
    float m_flReleaseThrow; // ok
    int m_iSwing;
    bool has_disconnected; // ok
    TeamName m_iTeam; // ok
    int m_LastHitGroup; // ok
    int entity_nf6;
    int entity_nf7;
    int entity_nf8;
};

class CBaseDelay : public CBaseEntity {
public:
    float m_flDelay; // ok
    string_t m_iszKillTarget; // ok
};

class CBaseAnimating : public CBaseDelay {
public:
    virtual void HandleAnimEvent(struct MonsterEvent_t* pEvent);

public:
    float m_flFrameRate; // ok
    float m_flGroundSpeed; // ok
    float m_flLastEventCheck; // ok
    BOOL m_fSequenceFinished; // ok
    BOOL m_fSequenceLoops; // ok
};

struct EHANDLE {
    edict_t *m_pent;
    int m_serialnumber;
};

// Things that toggle (buttons/triggers/doors) need this
enum TOGGLE_STATE { TS_AT_TOP, TS_AT_BOTTOM, TS_GOING_UP, TS_GOING_DOWN };

class CBaseToggle : public CBaseAnimating {
public:
    TOGGLE_STATE m_toggle_state; // ok
    float m_flActivateFinished; // ok
    float m_flMoveDistance; // ok
    float m_flWait; // ok
    float m_flLip; // ok
    float m_flTWidth;
    float m_flTLength;
    vec3_t m_vecPosition1;
    vec3_t m_vecPosition2;
    vec3_t m_vecAngle1;
    vec3_t m_vecAngle2;
    int m_cTriggersLeft; // ok
    float m_flHeight; // ok
    EHANDLE m_hActivator; // ok
    void* m_pfnCallWhenMoveDone;
    vec3_t m_vecFinalDest;
    vec3_t m_vecFinalAngle;
    int m_bitsDamageInflict; // ok
    string_t m_sMaster;  // ok
};

struct AmmoInventory {
    int iMaxAmmo;
    int iAmmo;
};

enum {
    ITBD_PARALYZE = 0,
    ITBD_NERVE_GAS,
    ITBD_POISON,
    ITBD_RADIATION,
    ITBD_DROWN_RECOVER,
    ITBD_ACID,
    ITBD_SLOW_BURN,
    ITBD_SLOW_FREEZE,
    ITBD_END,
};

enum MONSTERSTATE {
    MONSTERSTATE_NONE = 0,
    MONSTERSTATE_IDLE,
    MONSTERSTATE_COMBAT,
    MONSTERSTATE_ALERT,
    MONSTERSTATE_HUNT,
    MONSTERSTATE_PRONE,
    MONSTERSTATE_SCRIPT,
    MONSTERSTATE_PLAYDEAD,
    MONSTERSTATE_DEAD,
};

typedef enum Activity_s {
    ACT_INVALID = -1,

    ACT_RESET = 0,            // Set m_Activity to this invalid value to force a reset to m_IdealActivity
    ACT_IDLE,
    ACT_GUARD,
    ACT_WALK,
    ACT_RUN,
    ACT_FLY,                // Fly (and flap if appropriate)
    ACT_SWIM,
    ACT_HOP,                // vertical jump
    ACT_LEAP,                // long forward jump
    ACT_FALL,
    ACT_LAND,
    ACT_STRAFE_LEFT,
    ACT_STRAFE_RIGHT,
    ACT_ROLL_LEFT,            // tuck and roll, left
    ACT_ROLL_RIGHT,            // tuck and roll, right
    ACT_TURN_LEFT,            // turn quickly left (stationary)
    ACT_TURN_RIGHT,            // turn quickly right (stationary)
    ACT_CROUCH,                // the act of crouching down from a standing position
    ACT_CROUCHIDLE,            // holding body in crouched position (loops)
    ACT_STAND,                // the act of standing from a crouched position
    ACT_USE,
    ACT_SIGNAL1,
    ACT_SIGNAL2,
    ACT_SIGNAL3,
    ACT_TWITCH,
    ACT_COWER,
    ACT_SMALL_FLINCH,
    ACT_BIG_FLINCH,
    ACT_RANGE_ATTACK1,
    ACT_RANGE_ATTACK2,
    ACT_MELEE_ATTACK1,
    ACT_MELEE_ATTACK2,
    ACT_RELOAD,
    ACT_ARM,                // pull out gun, for instance
    ACT_DISARM,                // reholster gun
    ACT_EAT,                // monster chowing on a large food item (loop)
    ACT_DIESIMPLE,
    ACT_DIEBACKWARD,
    ACT_DIEFORWARD,
    ACT_DIEVIOLENT,
    ACT_BARNACLE_HIT,        // barnacle tongue hits a monster
    ACT_BARNACLE_PULL,        // barnacle is lifting the monster ( loop )
    ACT_BARNACLE_CHOMP,        // barnacle latches on to the monster
    ACT_BARNACLE_CHEW,        // barnacle is holding the monster in its mouth ( loop )
    ACT_SLEEP,
    ACT_INSPECT_FLOOR,        // for active idles, look at something on or near the floor
    ACT_INSPECT_WALL,        // for active idles, look at something directly ahead of you ( doesn't HAVE to be a wall or on a wall )
    ACT_IDLE_ANGRY,            // alternate idle animation in which the monster is clearly agitated. (loop)
    ACT_WALK_HURT,            // limp  (loop)
    ACT_RUN_HURT,            // limp  (loop)
    ACT_HOVER,                // Idle while in flight
    ACT_GLIDE,                // Fly (don't flap)
    ACT_FLY_LEFT,            // Turn left in flight
    ACT_FLY_RIGHT,            // Turn right in flight
    ACT_DETECT_SCENT,        // this means the monster smells a scent carried by the air
    ACT_SNIFF,                // this is the act of actually sniffing an item in front of the monster
    ACT_BITE,                // some large monsters can eat small things in one bite. This plays one time, EAT loops.
    ACT_THREAT_DISPLAY,        // without attacking, monster demonstrates that it is angry. (Yell, stick out chest, etc )
    ACT_FEAR_DISPLAY,        // monster just saw something that it is afraid of
    ACT_EXCITED,            // for some reason, monster is excited. Sees something he really likes to eat, or whatever.
    ACT_SPECIAL_ATTACK1,    // very monster specific special attacks.
    ACT_SPECIAL_ATTACK2,
    ACT_COMBAT_IDLE,        // agitated idle.
    ACT_WALK_SCARED,
    ACT_RUN_SCARED,
    ACT_VICTORY_DANCE,        // killed a player, do a victory dance.
    ACT_DIE_HEADSHOT,        // die, hit in head.
    ACT_DIE_CHESTSHOT,        // die, hit in chest
    ACT_DIE_GUTSHOT,        // die, hit in gut
    ACT_DIE_BACKSHOT,        // die, hit in back
    ACT_FLINCH_HEAD,
    ACT_FLINCH_CHEST,
    ACT_FLINCH_STOMACH,
    ACT_FLINCH_LEFTARM,
    ACT_FLINCH_RIGHTARM,
    ACT_FLINCH_LEFTLEG,
    ACT_FLINCH_RIGHTLEG,
    ACT_FLINCH,
    ACT_LARGE_FLINCH,
    ACT_HOLDBOMB,
    ACT_IDLE_FIDGET,
    ACT_IDLE_SCARED,
    ACT_IDLE_SCARED_FIDGET,
    ACT_FOLLOW_IDLE,
    ACT_FOLLOW_IDLE_FIDGET,
    ACT_FOLLOW_IDLE_SCARED,
    ACT_FOLLOW_IDLE_SCARED_FIDGET,
    ACT_CROUCH_IDLE,
    ACT_CROUCH_IDLE_FIDGET,
    ACT_CROUCH_IDLE_SCARED,
    ACT_CROUCH_IDLE_SCARED_FIDGET,
    ACT_CROUCH_WALK,
    ACT_CROUCH_WALK_SCARED,
    ACT_CROUCH_DIE,
    ACT_WALK_BACK,
    ACT_IDLE_SNEAKY,
    ACT_IDLE_SNEAKY_FIDGET,
    ACT_WALK_SNEAKY,
    ACT_WAVE,
    ACT_YES,
    ACT_NO,
} Activity;

typedef struct {
    int type;
    char *name;
} activity_map_t;

class CBaseMonster : public CBaseToggle {
public:
    virtual void ChangeYaw(int speed);
    virtual BOOL HasHumanGibs();
    virtual BOOL HasAlienGibs();
    virtual void FadeMonster();
    virtual void GibMonster();
    virtual Activity GetDeathActivity();
    virtual void BecomeDead();
    virtual BOOL ShouldFadeOnDeath();
    virtual int IRelationship(CBaseEntity *pTarget);
    virtual void PainSound();
    virtual void ResetMaxSpeed();
    virtual void ReportAIState();
    virtual void MonsterInitDead();
    virtual void Look(int iDistance);
    virtual CBaseEntity* BestVisibleEnemy();
    virtual BOOL FInViewCone_Vector(vec_t* pOrigin);
    virtual BOOL FInViewCone_Entity(struct CBaseEntity*);
    virtual int CSO_ADD_15();

public:
    Activity m_Activity; // ok
    Activity m_IdealActivity; // ok
    int m_bitsDamageType; // ok
    char m_rgbTimeBasedDamage[8]; // ok
    MONSTERSTATE m_MonsterState; // ok
    MONSTERSTATE m_IdealMonsterState; // ok
    
    int m_afConditions; // ok
    int m_afMemory; // ok

    float m_flNextAttack; // ok
    EHANDLE m_hEnemy; // ok
    EHANDLE m_hTargetEnt;
    float m_flFieldOfView;
    int m_bloodColor; // ok
    fVector m_HackedGunPos; // ok
    fVector m_vecEnemyLKP; // ok

    unsigned char monster_nf1;
};

enum WeaponIdType {
    WEAPON_NONE = 0,
    WEAPON_P228 = 1,
    WEAPON_UNK2 = 2,
    WEAPON_SCOUT = 3,
    WEAPON_HEGRENADE = 4,
    WEAPON_XM1014 = 5,
    WEAPON_C4 = 6,
    WEAPON_MAC10 = 7,
    WEAPON_AUG = 8,
    WEAPON_SMOKEGRENADE = 9,
    WEAPON_ELITE = 10,
    WEAPON_FIVESEVEN = 11,
    WEAPON_UMP45 = 12,
    WEAPON_SG550 = 13,
    WEAPON_GALIL = 14,
    WEAPON_FAMAS = 15,
    WEAPON_USP = 16,
    WEAPON_GLOCK18 = 17,
    WEAPON_AWP = 18,
    WEAPON_MP5 = 19,
    WEAPON_M249 = 20,
    WEAPON_M3 = 21,
    WEAPON_M4A1 = 22,
    WEAPON_TMP = 23,
    WEAPON_G3SG1 = 24,
    WEAPON_FLASHBANG = 25,
    WEAPON_DEAGLE = 26,
    WEAPON_SG552 = 27,
    WEAPON_AK47 = 28,
    WEAPON_KNIFE = 29,
    WEAPON_P90 = 30,
    WEAPON_SCARL = 31,
    WEAPON_SCARH = 32,
    WEAPON_XM8C = 33,
    WEAPON_XM8S = 34,
    WEAPON_SVD = 35,
    WEAPON_MP7A1P = 36,
    WEAPON_MP7A1C = 37,
    WEAPON_K1A = 38,
    WEAPON_USAS12 = 39,
    WEAPON_VSK94 = 40,
    WEAPON_QBB95 = 41,
    WEAPON_SCARA = 42,
    WEAPON_XM8A = 43,
    WEAPON_ZOMBIBOMB = 44,
    WEAPON_MG3 = 45,
    WEAPON_ANACONDA = 46,
    WEAPON_TRG42 = 47,
    WEAPON_MP7A1D = 48,
    WEAPON_DEAGLED = 49,
    WEAPON_AK47L = 50,
    WEAPON_AWPXMAS = 51,
    WEAPON_M249XMAS = 52,
    WEAPON_M400 = 53,
    WEAPON_M4A1G = 54,
    WEAPON_AK47G = 55,
    WEAPON_DEAGLEG = 56,
    WEAPON_SL8 = 57,
    WEAPON_M1887 = 58,
    WEAPON_M134 = 59,
    WEAPON_F2000 = 60,
    WEAPON_K1ASE = 61,
    WEAPON_UNK62 = 62,
    WEAPON_M1887G = 63,
    WEAPON_SL8G = 64,
    WEAPON_GUITAR = 65,
    WEAPON_M24 = 66,
    WEAPON_INFINITY = 67,
    WEAPON_WATERGUN = 68,
    WEAPON_M4A1GOLD = 69,
    WEAPON_INFINITYEX1 = 70,
    WEAPON_AWPCAMO = 71,
    WEAPON_SVDEX = 72,
    WEAPON_QBB95EX = 73,
    WEAPON_MP7A160R = 74,
    WEAPON_M79 = 75,
    WEAPON_M134XMAS = 76,
    WEAPON_MG3XMAS = 77,
    WEAPON_INFINITYEX2 = 78,
    WEAPON_HK23 = 79,
    WEAPON_M4A1DRAGON = 80,
    WEAPON_AK47DRAGON = 81,
    WEAPON_MP5TIGER = 82,
    WEAPON_CROSSBOW = 83,
    WEAPON_INFINITYSB = 84,
    WEAPON_INFINITYSR = 85,
    WEAPON_INFINITYSS = 86,
    WEAPON_M14EBR = 87,
    WEAPON_USAS12CAMO = 88,
    WEAPON_THOMPSONGOLD = 89,
    WEAPON_DBARREL = 90,
    WEAPON_CARTBLUEC = 91,
    WEAPON_CARTBLUES = 92,
    WEAPON_CARTREDL = 93,
    WEAPON_CARTREDH = 94,
    WEAPON_KRISS = 95,
    WEAPON_M249EX = 96,
    WEAPON_WATERPISTOL = 97,
    WEAPON_WA2000 = 98,
    WEAPON_LUGERG = 99,
    WEAPON_TRG42G = 100,
    WEAPON_AT4 = 101,
    WEAPON_TAR21 = 102,
    WEAPON_M95 = 103,
    WEAPON_MP5G = 104,
    WEAPON_DUALKRISS = 105,
    WEAPON_M60 = 106,
    WEAPON_AN94 = 107,
    WEAPON_M16A4 = 108,
    WEAPON_MG3G = 109,
    WEAPON_P90LAPIN = 110,
    WEAPON_GATLING = 111,
    WEAPON_SKULL5 = 112,
    WEAPON_THOMPSON = 113,
    WEAPON_LUGER = 114,
    WEAPON_MG36 = 115,
    WEAPON_SFGUN = 116,
    WEAPON_WA2000G = 117,
    WEAPON_FLAMETHROWER = 118,
    WEAPON_XM2010 = 119,
    WEAPON_SL8EX = 120,
    WEAPON_KSG12 = 121,
    WEAPON_AS50 = 122,
    WEAPON_QBARREL = 123,
    WEAPON_LUGERS = 124,
    WEAPON_M134EX = 125,
    WEAPON_RAINBOWGUN = 126,
    WEAPON_MUSKET = 127,
    WEAPON_STG44 = 128,
    WEAPON_HK23G = 129,
    WEAPON_SKULL1 = 130,
    WEAPON_QBZ95B = 131,
    WEAPON_M79G = 132,
    WEAPON_AT4EX = 133,
    WEAPON_PKM = 134,
    WEAPON_SFSMG = 135,
    WEAPON_CATAPULT = 136,
    WEAPON_SPAS12 = 137,
    WEAPON_SPAS12EX = 138,
    WEAPON_M14EBRGOLD = 139,
    WEAPON_M95XMAS = 140,
    WEAPON_BAZOOKA = 141,
    WEAPON_SKULL3 = 142,
    WEAPON_SKULL3D = 143,
    WEAPON_CANNON = 144,
    WEAPON_TMPDRAGON = 145,
    WEAPON_SPAS12EX2 = 146,
    WEAPON_MK48 = 147,
    WEAPON_M82 = 148,
    WEAPON_KSG12G = 149,
    WEAPON_SFMG = 150,
    WEAPON_STG44G = 151,
    WEAPON_SKULL11 = 152,
    WEAPON_FIRECRACKER = 153,
    WEAPON_MOUNTGUN = 154,
    WEAPON_M249CAMO = 155,
    WEAPON_XM1014RED = 156,
    WEAPON_DEAGLERED = 157,
    WEAPON_GLOCKRED = 158,
    WEAPON_USPRED = 159,
    WEAPON_FNC = 160,
    WEAPON_L85A2 = 161,
    WEAPON_AUTOMAG = 162,
    WEAPON_AKM = 163,
    WEAPON_SCOUTRED = 164,
    WEAPON_HK416 = 165,
    WEAPON_AW50 = 166,
    WEAPON_BLASER93 = 167,
    WEAPON_VIOLINGUN = 168,
    WEAPON_ETHEREAL = 169,
    WEAPON_M32 = 170,
    WEAPON_POISONGUN = 171,
    WEAPON_BALROG7 = 172,
    WEAPON_KINGCOBRA = 173,
    WEAPON_M16A1 = 174,
    WEAPON_LIGHTZG = 175,
    WEAPON_HEAVYZG = 176,
    WEAPON_BALROG5 = 177,
    WEAPON_UNK178 = 178,
    WEAPON_AS50G = 179,
    WEAPON_M60G = 180,
    WEAPON_SFSNIPER = 181,
    WEAPON_DBARRELG = 182,
    WEAPON_OICW = 183,
    WEAPON_AK47RED = 184,
    WEAPON_M4A1RED = 185,
    WEAPON_UTS15 = 186,
    WEAPON_M249EP = 187,
    WEAPON_MG36XMAS = 188,
    WEAPON_G11 = 189,
    WEAPON_M32BRBOT = 190,
    WEAPON_BALROG1 = 191,
    WEAPON_TBARREL = 192,
    WEAPON_CHAINSAW = 193,
    WEAPON_SNAKEGUN = 194,
    WEAPON_BALROG3 = 195,
    WEAPON_FGLAUNCHER = 196,
    WEAPON_K3 = 197,
    WEAPON_MG36G = 198,
    WEAPON_M16A1EP = 199,
    WEAPON_COILGUN = 200,
    WEAPON_SKULL4 = 201,
    WEAPON_KINGCOBRAG = 202,
    WEAPON_BALROG11 = 203,
    WEAPON_AK74U = 204,
    WEAPON_SKULL8 = 205,
    WEAPON_ZGUN = 206,
    WEAPON_PLASMAGUN = 207,
    WEAPON_PSG1 = 208,
    WEAPON_WATERCANNON = 209,
    WEAPON_BGALIL = 210,
    WEAPON_BFAMAS = 211,
    WEAPON_BQBB95 = 212,
    WEAPON_BGLOCK18 = 213,
    WEAPON_BUSP45 = 214,
    WEAPON_BMP5 = 215,
    WEAPON_SKULL6 = 216,
    WEAPON_UTS15G = 217,
    WEAPON_TKNIFE = 218,
    WEAPON_TKNIFEEX = 219,
    WEAPON_TKNIFEEX2 = 220,
    WEAPON_BOW = 221,
    WEAPON_ARX160 = 222,
    WEAPON_JANUSMK5 = 223,
    WEAPON_JANUS7 = 224,
    WEAPON_DRILLGUN = 225,
    WEAPON_G11G = 226,
    WEAPON_SPRIFLE = 227,
    WEAPON_JANUS1 = 228,
    WEAPON_GROZA = 229,
    WEAPON_M2 = 230,
    WEAPON_PKMG = 231,
    WEAPON_M1887XMAS = 232,
    WEAPON_SPEARGUN = 233,
    WEAPON_HORSEGUN = 234,
    WEAPON_SFPISTOL = 235,
    WEAPON_M60CRAFT = 236,
    WEAPON_MONKEYWPNSET1 = 237,
    WEAPON_MONKEYWPNSET2 = 238,
    WEAPON_SPAS12EXCRAFT = 239,
    WEAPON_JANUS11 = 240,
    WEAPON_SPMG = 241,
    WEAPON_BALROG7B = 242,
    WEAPON_BALROG5B = 243,
    WEAPON_BALROG1B = 244,
    WEAPON_BALROG3B = 245,
    WEAPON_BALROG11B = 246,
    WEAPON_GALILCRAFT = 247,
    WEAPON_M1887CRAFT = 248,
    WEAPON_PETROLBOOMER = 249,
    WEAPON_BENDITA = 250,
    WEAPON_MAUSERC96 = 251,
    WEAPON_MOSIN = 252,
    WEAPON_MG42 = 253,
    WEAPON_MP40 = 254,
    WEAPON_JANUS3 = 255,
    WEAPON_M1GARAND = 256,
    WEAPON_RAILCANNON = 257,
    WEAPON_CANNONM = 258,
    WEAPON_CHAINSAWM = 259,
    WEAPON_M1911A1 = 260,
    WEAPON_STENMK2 = 261,
    WEAPON_M1918BAR = 262,
    WEAPON_LASERGUIDE = 263,
    WEAPON_K1ACRAFT = 264,
    WEAPON_GILBOA = 265,
    WEAPON_GILBOAEX = 266,
    WEAPON_BLOCKAR = 267,
    WEAPON_OZWPNSET1 = 268,
    WEAPON_OZWPNSET2 = 269,
    WEAPON_FUNAT4 = 270,
    WEAPON_FUNCHAINSAW = 271,
    WEAPON_UNK272 = 272,
    WEAPON_UNK273 = 273,
    WEAPON_THANATOS7 = 274,
    WEAPON_RPG7 = 275,
    WEAPON_FIREEXTINGUISHER = 276,
    WEAPON_GUILLOTINE = 277,
    WEAPON_THANATOS11 = 278,
    WEAPON_CROSSBOWEX = 279,
    WEAPON_SFSNIPERM = 280,
    WEAPON_GATLINGM = 281,
    WEAPON_UZI = 282,
    WEAPON_M950 = 283,
    WEAPON_MK3A1 = 284,
    WEAPON_SPSMG = 285,
    WEAPON_FNP45 = 286,
    WEAPON_PGM = 287,
    WEAPON_NORINCO86S = 288,
    WEAPON_THANATOS5 = 289,
    WEAPON_DARTPISTOL = 290,
    WEAPON_DUALKRISSHERO = 291,
    WEAPON_M134HERO = 292,
    WEAPON_VULCANUS7 = 293,
    WEAPON_SAPIENTIA = 294,
    WEAPON_COILMG = 295,
    WEAPON_ZOMBIBOMB2 = 296,
    WEAPON_BLOCKAS = 297,
    WEAPON_AIRBURSTER = 298,
    WEAPON_VULCANUS5 = 299,
    WEAPON_UNK300 = 300,
    WEAPON_UNK301 = 301,
    WEAPON_DUALUZI = 302,
    WEAPON_LASERMINIGUN = 303,
    WEAPON_QBS09 = 304,
    WEAPON_THANATOS1 = 305,
    WEAPON_BUFFM4 = 306,
    WEAPON_BUFFAK = 307,
    WEAPON_NG7 = 308,
    WEAPON_CAMERAGUN = 309,
    WEAPON_FALCON = 310,
    WEAPON_BUFFAWP = 311,
    WEAPON_SKULL2 = 312,
    WEAPON_PYTHON = 313,
    WEAPON_THANATOS3 = 314,
    WEAPON_VULCANUS11 = 315,
    WEAPON_JANUS7XMAS = 316,
    WEAPON_CROW7 = 317,
    WEAPON_M950SE = 318,
    WEAPON_SGDRILL = 319,
    WEAPON_DESTROYER = 320,
    WEAPON_BAZOOKA_ZS2 = 321,
    WEAPON_HK121 = 322,
    WEAPON_HK121EX = 323,
    WEAPON_CROW5 = 324,
    WEAPON_VULCANUS1 = 325,
    WEAPON_PP2000 = 326,
    WEAPON_SPSG = 327,
    WEAPON_BLOCKMG = 328,
    WEAPON_BLOODHUNTER = 329,
    WEAPON_ULTIMAX100 = 330,
    WEAPON_VULCANUS3 = 331,
    WEAPON_BISON = 332,
    WEAPON_KH2002 = 333,
    WEAPON_UNK334 = 334,
    WEAPON_UNK335 = 335,
    WEAPON_FALCONEX = 336,
    WEAPON_UNK337 = 337,
    WEAPON_BUFFSG552 = 338,
    WEAPON_BROAD = 339,
    WEAPON_UNK340 = 340,
};

enum PLAYER_ANIM {
	PLAYER_IDLE,
	PLAYER_WALK,
	PLAYER_JUMP,
	PLAYER_SUPERJUMP,
	PLAYER_DIE,
	PLAYER_ATTACK1,
	PLAYER_ATTACK2,
	PLAYER_FLINCH,
	PLAYER_LARGE_FLINCH,
	PLAYER_RELOAD,
	PLAYER_HOLDBOMB
};

struct Player_ZBEnhance {
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
};

// GetClassPtr
// Size 0x2350
class CBasePlayer : public CBaseMonster {
public:
    // CBasePlayer has lots of shits :/ TODO: FIND OUT EVERY SHITS
    // ret 0
    virtual void Pain(int iLastHitGroup, bool bHasArmour);

public:
    int cso_u1;
    int random_seed; // ok
    unsigned short m_usPlayerBleed;
    EHANDLE m_hObserverTarget; // ok
    float m_flNextObserverInput; // ok
    int m_iObserverWeapon; // ok
    int cso_u2;
    int cso_u3;
    int m_iObserverC4State; // ok
    bool m_bObserverHasDefuser; // ok
    int m_iObserverLastMode; // ok
    float m_flFlinchTime;
    float m_flAnimTime;
    bool m_bHighDamage;
    float m_flVelocityModifier;
    int m_iLastZoom;
    bool m_bResumeZoom;
    float m_flEjectBrass; // ok
    int cso_u4;
    ArmorType m_iKevlar; // ok
    char m_bNotKilled; // ok
    int m_iAccount; // ok
    bool m_bHasPrimary;
    float m_flDeathThrowTime;
    int m_iThrowDirection;
    float m_flLastTalk; // ok
    bool m_bJustConnected;
    bool m_bContextHelp;
    JoinState m_iJoiningState; // ok
    CBaseEntity *m_pIntroCamera;
    float m_fIntroCamTime;
    float m_fLastMovement;
    bool m_bMissionBriefing; // ok
    bool m_bTeamChanged;
    ModelName m_iModelName;
    int m_iTeamKills; // ok
    IgnoreChatMsg m_iIgnoreGlobalChat; // ok
    bool m_bHasNightVision; // ok
    bool m_bNightVisionOn; // ok
    vec3_t m_vRecentPath[MAX_RECENT_PATH]; // ok
    float m_flIdleCheckTime; // ok
    float m_flRadioTime; // ok
    int m_iRadioMessages; // ok
    bool m_bIgnoreRadio; // ok
    bool m_bHasC4; // ok
    bool m_bHasDefuser; // ok
    bool m_bKilledByBomb;
    vec3_t m_vBlastVector;
    bool m_bKilledByGrenade;
    CHintMessageQueue m_hintMessageQueue;
    int m_flDisplayHistory; // ok
    _Menu m_iMenu; // ok
    int m_iChaseTarget;
    CBaseEntity *m_pChaseTarget;
    float m_fCamSwitch;
    bool m_bEscaped;
    bool m_bIsVIP; // ok
    float m_tmNextRadarUpdate;
    vec3_t m_vLastOrigin;
    int m_iCurrentKickVote;
    float m_flNextVoteTime;
    bool m_bJustKilledTeammate;
    int m_iHostagesKilled; // ok
    int m_iMapVote;
    bool m_bCanShoot; // ok
    float m_flLastFired;
    float m_flLastAttackedTeammate;
    bool m_bHeadshotKilled;
    bool m_bPunishedForTK;
    bool m_bReceivesNoMoneyNextRound;
    int m_iTimeCheckAllowed;
    bool m_bHasChangedName; // ok
    char m_szNewName[MAX_PLAYER_NAME_LENGTH]; // ok
    bool m_bIsDefusing; // ok
    float m_tmHandleSignals; // ok
    CUnifiedSignals m_signals;
    edict_t *m_pentCurBombTarget;
    int cso_baseplayer_1;
    int m_iPlayerSound; // ok
    int m_iTargetVolume; // ok
    int m_iWeaponVolume; // ok
    int m_iExtraSoundTypes; // ok
    int m_iWeaponFlash; // ok
    float m_flStopExtraSoundTime; // ok
    float m_flFlashLightTime; // ok
    int m_iFlashBattery; // ok
    int m_afButtonLast; // ok
    int m_afButtonPressed;
    int m_afButtonReleased;
    int m_afButtonPressed2; // ADDED
    int cso_baseplayer_2;
    edict_t *m_pentSndLast;
    float m_flSndRoomtype;
    float m_flSndRange;
    float m_flFallVelocity;
    int m_rgItems[MAX_ITEMS]; // ok
    unsigned int m_afPhysicsFlags; // ok
    int m_fNewAmmo;
    float m_fNextSuicideTime;
    float m_flTimeStepSound;
    float m_flTimeWeaponIdle;
    float m_flSwimTime;
    float m_flDuckTime;
    float m_flWallJumpTime;
    float m_flSuitUpdate;
    int m_rgSuitPlayList[MAX_SUIT_PLAYLIST];
    int m_iSuitPlayNext;
    int m_lastDamageAmount;
    float m_tbdPrev;
    float m_flgeigerRange;
    float m_flgeigerDelay;
    int m_igeigerRangePrev;
    char m_szTextureName[MAX_TEXTURENAME_LENGHT];
    char m_chTextureType;
    int m_idrowndmg; // ok
    int m_idrownrestored; // ok
    int m_bitsHUDDamage; // ok
    BOOL m_fInitHUD; // ok
    BOOL m_fGameHUDInitialized; // ok
    int m_iTrain; // ok
    BOOL m_fWeapon; // OK
    EHANDLE m_pTank;
    float m_fDeadTime; // OK
    BOOL m_fNoPlayerSound; // ok
    int ___unk1;
    int ___unk2;
    float m_tSneaking;
    int m_iClientHealth; // ok
    int m_iClientBattery; // ok
    int m_iHideHUD; // OK
    int m_iClientHideHUD; // ok
    int m_iFOV; // ok
    int m_iClientFOV; // ok
    short m_iNumSpawns; // ok
    CBaseEntity *m_pObserver;
    CBasePlayerItem *m_rgpPlayerItems[MAX_ITEM_TYPES]; // ok
    CBasePlayerItem *m_pActiveItem; // ok
    CBasePlayerItem *m_pClientActiveItem; // ok
    CBasePlayerItem *m_pLastItem; // ok
    int m_rgAmmo[MAX_AMMO_SLOTS]; // ok
    int m_rgAmmoLast[MAX_AMMO_SLOTS]; // ok
    fVector m_vecAutoAim; // ok
    BOOL m_fOnTarget; // ok
    int m_iDeaths;
    int m_izSBarState[SBAR_END];
    float m_flNextSBarUpdateTime;
    int cso_add_c[115];
    char player_undef1[1340]; // ClientPutInServer, memset
    int player_nfc[17];
    int m_nCustomSprayFrames;
    float m_flNextDecalTime;
    int m_modelIndexPlayer; // ok
    char m_szTeamName[13];
    char m_szAnimExtention[32]; // ok
    int undef9;
    int m_iGaitsequence;
    float m_flGaitframe;
    float m_flGaityaw;
    vec3_t m_prevgaitorigin;
    float m_flPitch;
    float m_flYaw;
    float m_flGaitMovement;
    bool m_bVGUIMenus;
    bool m_bShowHints;
    char m_bWasFollowing; // ok
    char undef7;
    float m_flNextFollowTime; // ok
    int undef8;
    float m_blindUntilTime; // ok
    float m_blindStartTime; // ok
    float m_blindHoldTime; // ok
    float m_blindFadeTime; // ok
    int m_blindAlpha; // OK
    float m_allowAutoFollowTime;
    int player_nfa[141];
    float m_flLastUpdateTime; // ok
    char m_lastLocation[32]; // ok
    float m_progressStart;
    float m_progressEnd;
    bool m_bObserverAutoDirector;
    bool m_canSwitchObserverModes;
    int player_nf[227];
    char player_nf2;
    char player_nf3;
    char player_nf4;
    char player_nf5;
    char player_nf6;
    char player_nf8;
    char player_nf9;
    int player_nfb[402];
    float player_nf10;
    int player_nff[56];

    char zbEnhance1[0x38];
    Player_ZBEnhance zbEnhance2[14];
    int player_nfd[40];
    int zbEnhanceDNA[18];
    int player_nfe[178];
};

struct AutoBuyInfoStruct {
	int m_class;
	char *m_command;
	char *m_classname;
};

struct ItemInfo {
	int iSlot;
	int iPosition;
	const char *pszAmmo1;
	int iMaxAmmo1;
	const char *pszAmmo2;
	int iMaxAmmo2;
	const char *pszName;
	int iMaxClip;
	int iId;
	int iFlags;
	int iWeight;
};

struct WeaponInfoStruct {
	int id;
	int clipCost;
	int buyClipSize;
	int gunClipSize;
	int maxRounds;
	AmmoType ammoType;
	char *entityName;
    int unk19;
};

class CBasePlayerItem : public CBaseAnimating {
public:
    virtual int AddToPlayer();
    virtual int AddDuplicate(struct CBasePlayerItem* pOriginal);
    virtual int GetItemInfo(struct ItemInfo* info);
    virtual void CanDeploy();
    virtual void CanDrop();
    virtual void Deploy();
    virtual void Unknown1();
    virtual void IsWeapon();
    virtual void CanHolster();
    virtual void Holster(int);
    virtual void UpdateItemInfo_ResetMaxSpeed();
    virtual void ItemPreFrame();
    virtual void ItemPostFrame();
    virtual void Drop();
    virtual void Kill();
    virtual void AttachToPlayer();
    virtual void PrimaryAmmoIndex();
    virtual void SecondaryAmmoIndex();
    virtual void UpdateClientData();
    virtual void GetWeaponPtr();
    virtual void GetMaxSpeed();
    virtual void Unknown2();
    virtual int GetItemSlot();
    virtual void GetUnk12();
    virtual BOOL IsWeaponFlag0x400__GetGunPosition();
    virtual BOOL IsWeaponFlag0x800();
    virtual BOOL IsWeaponFlag0x8000();
    virtual BOOL IsWeaponFlag0x10000();
    virtual BOOL IsWeaponFlag0x1000();
    virtual BOOL IsWeaponFlag0x40000__SetAnimation();
    virtual void BPI_Unknown3();
    virtual void BPI_Unknown4();
    virtual void GetAutoaimVector(float* a, float b);
    virtual double BPI_Unknown6();
    virtual void BPI_Unknown7(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7);
    virtual void BPI_Unknown8();
    virtual void BPI_Unknown9();
    virtual void BPI_Unknown10();
    virtual void BPI_Unknown11();
    virtual void BPI_Unknown12();
    virtual void BPI_Unknown13();
    virtual void BPI_Unknown14();
    virtual void BPI_Unknown15();
    virtual void BPI_Unknown16();
    virtual void BPI_Unknown17();

public:
    struct CBasePlayer *m_pPlayer;
    CBasePlayerItem *m_pNext;
    int m_iId; // ok, WEAPON_???
    int m_iModelIndex;
    int cso_baseplayeritem_1;
};

// CAK47 size 0x238
class CBasePlayerWeapon : public CBasePlayerItem {
public:
    virtual int ExtractAmmo(CBasePlayerWeapon *pWeapon);
    virtual int ExtractClipAmmo(CBasePlayerWeapon *pWeapon);
    virtual int AddWeapon();
    virtual void AddSpecialAmmo(struct CBasePlayer* pPlayer);
    virtual void PlayEmptySound();
    virtual void ResetEmptySound();
    virtual void SendWeaponAnim(int, bool);
    virtual void IsUseable();
    virtual void PrimaryAttack();
    virtual void SecondaryAttack();
    virtual void Reload();
    virtual void WeaponIdle();
    virtual void RetireWeapon();
    virtual void BPW_Unknown9(); // MPToCL
    virtual void BPW_Unknown10();
    virtual int UseDecrement();
    virtual void BPW_Unknown12();
    virtual void BPW_Unknown13();
    virtual void BPW_Unknown14();
    virtual void IsWeaponFlag0x2000();
    virtual void IsWeaponFlag0x4000();
    virtual void GetAmmoClip__iMaxClip();
    virtual void GetAmmoClip2();
    virtual void BPW_Unknown15();
    virtual void BPW_Unknown16();
    virtual void FireRemaining(int *shotsFired, float *shootTime, int bIsGlock);
    virtual void ItemPostFrame();

    // Weapon Own
    virtual void CWeapon__FireEvent(float flSpread, float flCycleTime, BOOL fUseAutoAim);
    // Fun fact
    // SIG: 56 FF 15 ? ? ? ? 8B C8 8B 10 FF 92 ? ? ? ? 8B F0 FF 15 ? ? ? ? 6A FE 6A 24 6A 23 6A 20 6A 1D 6A 18 6A 14 6A 0D 8B C8 6A 0B 6A 0E 6A 09 8B 01 6A 08 FF 90 ? ? ? ? 50 E8 ? ? ? ? 83 C4 34 84 C0 75 38 83 FE 1E 74
    virtual void CWeapon__GetDamage(float flSpread, float flCycleTime, BOOL fUseAutoAim);

public:
    int m_iPlayEmptySound; // ok
    int m_fFireOnEmpty; // ok
    int cso_baseplayer_weapon_1;
    int cso_baseplayer_weapon_2;
    float m_flNextPrimaryAttack; // ok
    float m_flNextSecondaryAttack; // ok
    float m_flTimeWeaponIdle; // ok
    int cso_baseplayer_weapon_3;
    int m_iPrimaryAmmoType; // ok
    int m_iSecondaryAmmoType; // ok
    int m_iClip; // ok
    int m_iClientClip; // ok
    int m_iSpecialAmmo; // ok
    int cso_baseplayer_weapon_5;
    int m_iClientWeaponState; // ok
    int m_fInReload;
    int m_fInSpecialReload; // ok
    int m_iDefaultPrimaryAmmo; // ok
    int m_iDefaultSecondaryAmmo; // ok
    int m_iShellId; // ok
    float m_fMaxSpeed;
    bool m_bDelayFire; // ok
    BOOL m_iDirection;
    bool m_bSecondarySilencerOn;
    float m_flAccuracy; // ok
    float m_flLastFire;
    int m_iShotsFired; // ok
    vec3_t m_vVecAiming;
    string_t model_name; // ok
    float m_flFamasShoot; // ok
    int m_iFamasShotsFired; // ok
    float m_fBurstSpread; // ok
    int m_iWeaponState; // ok
    float m_flNextReload; // ok
    float m_flDecreaseShotsFired; // ok    
    int nf_weapon2;

    unsigned short m_usFireWeapon; // temp var, some own class uses
};
