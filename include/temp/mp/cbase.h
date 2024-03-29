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
#define MAX_AMMO_SLOTS 32
#define MAX_SBAR_STRING 128
#define MAX_TEAM_NAME_LENGTH 16
#define MAX_AUTOBUY_LENGTH 256
#define MaxLocationLen 32

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
    // For easier access to the elements through the debugger
    // it's in release builds so this can be used in libraries correctly
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
    SBAR_END
};
enum MusicState { SILENT, CALM, INTENSE };

struct RebuyStruct {
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

enum TrackCommands
{
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

struct CBaseEntity_vt {
    void (__thiscall* Function1)(struct CBaseEntity* this); // unk ptr
    void (__thiscall* Function2)(struct CBaseEntity* this); // null most
    void (__thiscall* Spawn)(struct CBaseEntity* this);
    void (__thiscall* Precache)(struct CBaseEntity* this);
    void (__thiscall* Restart)(struct CBaseEntity* this);
    void (__thiscall* KeyValue)(struct CBaseEntity* this);
    void (__thiscall* Save)(struct CBaseEntity* this);
    void (__thiscall* Restore)(struct CBaseEntity* this);
    void (__thiscall* ObjectCaps)(struct CBaseEntity* this);
    void (__thiscall* Activate)(struct CBaseEntity* this);
    void (__thiscall* SetObjectCollisionBox)(struct CBaseEntity* this);
    void (__thiscall* Classify)(struct CBaseEntity* this);
    void (__thiscall* DeathNotice)(struct CBaseEntity* this, struct entvars_t*);
    void (__thiscall* TraceAttack)(struct CBaseEntity* this);
    void (__thiscall* TraceAttack_Proxy)(struct CBaseEntity* this);
    bool (__thiscall* TakeDamage)(struct CBaseEntity* this, entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
    bool (__thiscall* TakeHealth)(struct CBaseEntity* this);
    void (__thiscall* Killed)(struct CBaseEntity* this, entvars_t *pevAttacker, int iGib);
    int  (__thiscall* BloodColor)(struct CBaseEntity* this);
    void (__thiscall* TraceBleed)(struct CBaseEntity* this, float flDamage, vec3_t vecDir, struct TraceResult *ptr, int bitsDamageType);
    BOOL (__thiscall* IsTriggered)(struct CBaseEntity* this);
    class CBaseMonster*  (__thiscall* MyMonsterPointer)(struct CBaseEntity* this);
    class CSquadMonster* (__thiscall* MySquadMonsterPointer)(struct CBaseEntity* this);
    void (__thiscall* GetToggleState)(struct CBaseEntity* this);
    void (__thiscall* AddPoints)(struct CBaseEntity* this);
    void (__thiscall* AddPointsToTeam)(struct CBaseEntity* this);
    BOOL (__thiscall* AddPlayerItem)(struct CBaseEntity* this);
    BOOL (__thiscall* RemovePlayerItem)(struct CBaseEntity* this);
    void (__thiscall* GiveAmmo)(struct CBaseEntity* this);
    void (__thiscall* GetDelay)(struct CBaseEntity* this);
    void (__thiscall* IsMoving)(struct CBaseEntity* this);
    void (__thiscall* OverrideReset)(struct CBaseEntity* this);
    void (__thiscall* DamageDecal)(struct CBaseEntity* this, int bitsDamageType);
    void (__thiscall* SetToggleState)(struct CBaseEntity* this);
    void (__thiscall* StartSneaking)(struct CBaseEntity* this);
    void (__thiscall* StopSneaking)(struct CBaseEntity* this);
    void (__thiscall* OnControls)(struct CBaseEntity* this);
    BOOL (__thiscall* IsSneaking)(struct CBaseEntity* this);
    BOOL (__thiscall* IsAlive)(struct CBaseEntity* this);
    BOOL (__thiscall* IsBSPModel)(struct CBaseEntity* this);
    BOOL (__thiscall* ReflectGauss)(struct CBaseEntity* this);
    BOOL (__thiscall* HasTarget)(struct CBaseEntity* this);
    BOOL (__thiscall* IsInWorld)(struct CBaseEntity* this);
    BOOL (__thiscall* IsPlayer)(struct CBaseEntity* this);
    BOOL (__thiscall* IsNetClient)(struct CBaseEntity* this);
    void (__thiscall* TeamID)(struct CBaseEntity* this);
    void (__thiscall* GetKnockbackData)(struct CBaseEntity* this);
    void (__thiscall* GetArmorData)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_1)(struct CBaseEntity* this);
    struct CBaseEntity* (__thiscall* GetNextTarget)(struct CBaseEntity* this);
    void (__thiscall* Think)(struct CBaseEntity* this);
    void (__thiscall* Touch)(struct CBaseEntity* this, CBaseEntity *pOther);
    void (__thiscall* Use)(struct CBaseEntity* this, CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
    void (__thiscall* Blocked)(struct CBaseEntity* this, CBaseEntity *pOther);
    void (__thiscall* UpdateOnRemove)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_2)(struct CBaseEntity* this);
    struct CBaseEntity* (__thiscall* Respawn)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_3)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_4)(struct CBaseEntity* this);
    vec_t* (__thiscall* Center)(struct CBaseEntity* this, vec_t*);
    vec_t* (__thiscall* EyePosition)(struct CBaseEntity* this, vec_t*);
    vec_t* (__thiscall* EarPosition)(struct CBaseEntity* this, vec_t*);
    vec_t* (__thiscall* BodyTarget)(struct CBaseEntity* this, vec_t*);
    void (__thiscall* CSO_ADD_5)(struct CBaseEntity* this);
    void (__thiscall* Illumination)(struct CBaseEntity* this);
    void (__thiscall* FVisibleV)(struct CBaseEntity* this);
    void (__thiscall* FVisibleE)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_6)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_7)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_8)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_9)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_10)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_11)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_12)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_13)(struct CBaseEntity* this); // UTIL_GetGlobalTrace
    void (__thiscall* CSO_ADD_14)(struct CBaseEntity* this);
    
    void (__thiscall* CBaseAnimating__HandleAnimEvent)(struct CBaseEntity* this, struct MonsterEvent_t* pEvent);

    // Start from here, splited with CBaseMonster and CBasePlayerItem

#define GoPlayerItem
//#define GoMonster

#ifdef GoPlayerItem
    // CBasePlayerItem
    void (__thiscall* CBasePlayerItem::AddToPlayer)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::AddDuplicate)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::GetItemInfo)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::CanDeploy)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::CanDrop)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Deploy)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown1)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::IsWeapon)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::CanHolster)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Holster)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::UpdateItemInfo)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::ItemPreFrame)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::ItemPostFrame)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Drop)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Kill)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::AttachToPlayer)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::PrimaryAmmoIndex)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::SecondaryAmmoIndex)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::UpdateClientData)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::GetWeaponPtr)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::GetMaxSpeed)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown2)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::GetWeaponType)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::GetUnk12)(struct CBaseEntity* this);
    bool (__thiscall* CBasePlayerItem::IsWeaponFlag0x400)(struct CBaseEntity* this);
    bool (__thiscall* CBasePlayerItem::IsWeaponFlag0x800)(struct CBaseEntity* this);
    bool (__thiscall* CBasePlayerItem::IsWeaponFlag0x8000)(struct CBaseEntity* this);
    bool (__thiscall* CBasePlayerItem::IsWeaponFlag0x10000)(struct CBaseEntity* this);
    bool (__thiscall* CBasePlayerItem::IsWeaponFlag0x1000)(struct CBaseEntity* this);
    bool (__thiscall* CBasePlayerItem::IsWeaponFlag0x40000)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown3)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown4)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown5)(struct CBaseEntity* this, float* a, float* b);
    double (__thiscall* CBasePlayerItem::Unknown6)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown7)(struct CBaseEntity* this, float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7);
    void (__thiscall* CBasePlayerItem::Unknown8)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown9)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown10)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown11)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown12)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown13)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown14)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown15)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown16)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerItem::Unknown17)(struct CBaseEntity* this);

    // CBasePlayerWeapon
    void (__thiscall* CBasePlayerWeapon::Unknown1)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown2)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown3)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown4)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::PlayEmptySound)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::ResetEmptySound)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::SendWeaponAnim)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::IsUseable)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown5)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown6)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown7)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown8)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::RetireWeapon)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown9)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown10)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown11)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown12)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown13)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown14)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::IsWeaponFlag0x2000)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::IsWeaponFlag0x4000)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::GetAmmoClip)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::GetAmmoClip2)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown15)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::Unknown16)(struct CBaseEntity* this);
    void (__thiscall* CBasePlayerWeapon::FireRemaining)(struct CBaseEntity* this,int *shotsFired, float *shootTime, int bIsGlock);
    void (__thiscall* CBasePlayerWeapon::ItemPostFrame)(struct CBaseEntity* this);

    // Weapon Own
    void (__thiscall* CWeapon::FireEvent)(struct CBaseEntity* this, float flSpread, float flCycleTime, BOOL fUseAutoAim);
    void (__thiscall* CWeapon::GetDamage)(struct CBaseEntity* this, float flSpread, float flCycleTime, BOOL fUseAutoAim);
#elif defined GoMonster
    // CBaseMonster
    void (__thiscall* CBaseMonster::ChangeYaw)(struct CBaseEntity* this, int speed);
    BOOL (__thiscall* CBaseMonster::HasHumanGibs)(struct CBaseEntity* this);
    BOOL (__thiscall* CBaseMonster::HasAlienGibs)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::FadeMonster)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::GibMonster)(struct CBaseEntity* this);
    Activity (__thiscall* CBaseMonster::GetDeathActivity)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::BecomeDead)(struct CBaseEntity* this);
    BOOL (__thiscall* CBaseMonster::ShouldFadeOnDeath)(struct CBaseEntity* this);
    int (__thiscall* CBaseMonster::IRelationship)(struct CBaseEntity* this, CBaseEntity *pTarget);
    void (__thiscall* CBaseMonster::PainSound)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::ResetMaxSpeed)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::ReportAIState)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::MonsterInitDead)(struct CBaseEntity* this);
    void (__thiscall* CBaseMonster::Look)(struct CBaseEntity* this, int iDistance);
    CBaseEntity* (__thiscall* CBaseMonster::BestVisibleEnemy)(struct CBaseEntity* this);
    BOOL (__thiscall* CBaseMonster::FInViewCone_Vector)(struct CBaseEntity* this, vec_t* pOrigin);
    BOOL (__thiscall* CBaseMonster::FInViewCone_Entity)(struct CBaseEntity* this, struct CBaseEntity*);
    int (__thiscall* CBaseMonster::CSO_ADD_15)(struct CBaseEntity* this);

    // CBasePlayer has lots of shits :/ TODO: FIND OUT EVERY SHITS
    // ret 0
    void Pain(int iLastHitGroup, bool bHasArmour);
    
#endif
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

    int u1[65];

    int cso_add1;
    int cso_add2;
    int cso_add3;
    int cso_add4;

    int m_LastHitGroup;

    // client has left the game
    bool has_disconnected;

    TeamName m_iTeam;
    int u2[4];
};

struct CBaseDelay : CBaseEntity {
    float m_flDelay;
    string_t m_iszKillTarget;
};

struct CBaseAnimating : CBaseDelay {
    // animation needs
    float m_flFrameRate;    // computed FPS for current sequence
    float m_flGroundSpeed;    // computed linear movement rate for current sequence
    float m_flLastEventCheck;// last time the event list was checked
    BOOL m_fSequenceFinished;// flag set when StudioAdvanceFrame moves across a frame boundry
    BOOL m_fSequenceLoops;    // true if the sequence loops
};

// Things that toggle (buttons/triggers/doors) need this
enum TOGGLE_STATE { TS_AT_TOP, TS_AT_BOTTOM, TS_GOING_UP, TS_GOING_DOWN };

struct EHANDLE {
    edict_t *m_pent;
    int m_serialnumber;
};

struct CBaseToggle : CBaseAnimating {
    TOGGLE_STATE m_toggle_state;
    float m_flActivateFinished;// like attack_finished, but for doors
    float m_flMoveDistance;    // how far a door should slide or rotate
    float m_flWait;
    float m_flLip;
    float m_flTWidth;        // for plats
    float m_flTLength;        // for plats
    vec3_t m_vecPosition1;
    vec3_t m_vecPosition2;
    vec3_t m_vecAngle1;
    vec3_t m_vecAngle2;

    int m_cTriggersLeft;    // trigger_counter only, # of activations remaining
    float m_flHeight;
    EHANDLE m_hActivator;

    void* m_pfnCallWhenMoveDone;

    vec3_t m_vecFinalDest;
    vec3_t m_vecFinalAngle;

    int m_bitsDamageInflict;// DMG_ damage type that the door or tigger does

    /*
    If this button has a master switch, this is the targetname.
    A master switch must be of the multisource type. If all
    of the switches in the multisource have been triggered, then
    the button will be allowed to operate. Otherwise, it will be
    deactivated.
    */
    string_t m_sMaster; 
};

enum
{
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

enum MONSTERSTATE
{
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

struct CBaseMonster : CBaseToggle {
    Activity m_Activity;        // what the monster is doing (animation)
    Activity m_IdealActivity;    // monster should switch to this activity
    int m_LastHitGroup;            // the last body region that took damage
    int m_bitsDamageType;        // what types of damage has monster (player) taken
    char m_rgbTimeBasedDamage[4]; // TODO: why 4 on CSO??

    MONSTERSTATE m_MonsterState;    // monster's current state
    MONSTERSTATE m_IdealMonsterState;// monster should change to this state
    int m_afConditions;
    int m_afMemory;

    float m_flNextAttack;// cannot attack again until this time
    EHANDLE m_hEnemy;    // the entity that the monster is fighting.
    EHANDLE m_hTargetEnt;// the entity that the monster is trying to reach
    float m_flFieldOfView;// width of monster's field of view (dot product)
    int m_bloodColor;    // color of blood particless
    vec3_t m_HackedGunPos;// HACK until we can query end of gun
    vec3_t m_vecEnemyLKP;// last known position of enemy. (enemy's origin)

    unsigned char cso_added1;
};

enum WeaponIdType
{
    WEAPON_NONE,
    WEAPON_P228,
    WEAPON_GLOCK,
    WEAPON_SCOUT,
    WEAPON_HEGRENADE,
    WEAPON_XM1014,
    WEAPON_C4,
    WEAPON_MAC10,
    WEAPON_AUG,
    WEAPON_SMOKEGRENADE,
    WEAPON_ELITE,
    WEAPON_FIVESEVEN,
    WEAPON_UMP45,
    WEAPON_SG550,
    WEAPON_GALIL,
    WEAPON_FAMAS,
    WEAPON_USP,
    WEAPON_GLOCK18,
    WEAPON_AWP,
    WEAPON_MP5N,
    WEAPON_M249,
    WEAPON_M3,
    WEAPON_M4A1,
    WEAPON_TMP,
    WEAPON_G3SG1,
    WEAPON_FLASHBANG,
    WEAPON_DEAGLE,
    WEAPON_SG552,
    WEAPON_AK47,
    WEAPON_KNIFE,
    WEAPON_P90,
    WEAPON_SHIELDGUN = 99,

    WEAPON_XM8 = 34,
    WEAPON_SVD = 35,
    WEAPON_VSK94 = 40,
    WEAPON_TRG42 = 47,
    WEAPON_AWP_XMAS = 51,
    WEAPON_M400 = 53,
    WEAPON_SL8 = 57,
    WEAPON_SL8G = 64,
    WEAPON_M24 = 66,
    WEAPON_AWPCAMO = 71,
    WEAPON_CARTBLUE = 92,
    WEAPON_M249EX = 96,
    WEAPON_WA2000 = 98,
    WEAPON_TRG42G = 100,
    WEAPON_AT4 = 101,
    WEAPON_M95 = 103,
    WEAPON_SKULL5 = 112,
    WEAPON_MG36 = 115,
    WEAPON_WA2000G = 117,
    WEAPON_XM2010 = 119,
    WEAPON_SL8EX = 120,
    WEAPON_AS50 = 122,
    WEAPON_AT4EX = 133,
    WEAPON_M95XMAS = 140,
    WEAPON_M82 = 148,
    WEAPON_SCOUTRED = 164,
    WEAPON_KINGCOBRA = 173,
    WEAPON_BALROG5 = 177,
    WEAPON_AS50G = 179,
    WEAPON_SFSNIPER = 181,
    WEAPON_MG36XMAS = 188,
    WEAPON_MG36G = 198,
    WEAPON_ZGUN = 206,
    WEAPON_PSG1 = 208,
    WEAPON_SKULL6 = 216,
    WEAPON_SPRIFLE = 227,
    WEAPON_BALROG5B = 243,
    WEAPON_BENDITA = 250,
    WEAPON_MOSIN = 252,
    WEAPON_SKULL5WC = 272,
    WEAPON_SKULL7WC = 273,
    WEAPON_SFSNIPERM = 280,
    WEAPON_VULCANUS5 = 299,
    WEAPON_BUFFAWP = 311,
    WEAPON_DESTROYER = 320,
};

struct CBasePlayer : CBaseMonster {
    int cso_u1;
    int random_seed;
    unsigned short m_usPlayerBleed;
    EHANDLE m_hObserverTarget;
    float m_flNextObserverInput;
    int m_iObserverWeapon;
    int cso_u2;
    int cso_u3;
    int m_iObserverC4State;
    bool m_bObserverHasDefuser;
    int m_iObserverLastMode;
    float m_flFlinchTime;
    float m_flAnimTime;
    bool m_bHighDamage;
    float m_flVelocityModifier;
    int m_iLastZoom;
    bool m_bResumeZoom;
    float m_flEjectBrass;
    ArmorType m_iKevlar;
    bool m_bNotKilled;
    TeamName m_iTeam;
    int m_iAccount;
    bool m_bHasPrimary;
    float m_flDeathThrowTime;
    int m_iThrowDirection;
    float m_flLastTalk;
    bool m_bJustConnected;
    bool m_bContextHelp;
    JoinState m_iJoiningState;
    CBaseEntity *m_pIntroCamera;
    float m_fIntroCamTime;
    float m_fLastMovement;
    bool m_bMissionBriefing;
    bool m_bTeamChanged;
    ModelName m_iModelName;
    int m_iTeamKills;
    IgnoreChatMsg m_iIgnoreGlobalChat;
    bool m_bHasNightVision;
    bool m_bNightVisionOn;
    vec3_t m_vRecentPath[MAX_RECENT_PATH];
    float m_flIdleCheckTime;
    float m_flRadioTime;
    int m_iRadioMessages;
    bool m_bIgnoreRadio;
    bool m_bHasC4;
    bool m_bHasDefuser;
    bool m_bKilledByBomb;
    vec3_t m_vBlastVector;
    bool m_bKilledByGrenade;
    CHintMessageQueue m_hintMessageQueue;
    int m_flDisplayHistory;
    _Menu m_iMenu;
    int m_iChaseTarget;
    CBaseEntity *m_pChaseTarget;
    float m_fCamSwitch;
    bool m_bEscaped;
    bool m_bIsVIP;
    float m_tmNextRadarUpdate;
    vec3_t m_vLastOrigin;
    int m_iCurrentKickVote;
    float m_flNextVoteTime;
    bool m_bJustKilledTeammate;
    int m_iHostagesKilled;
    int m_iMapVote;
    bool m_bCanShoot;
    float m_flLastFired;
    float m_flLastAttackedTeammate;
    bool m_bHeadshotKilled;
    bool m_bPunishedForTK;
    bool m_bReceivesNoMoneyNextRound;
    int m_iTimeCheckAllowed;
    bool m_bHasChangedName;
    char m_szNewName[MAX_PLAYER_NAME_LENGTH];
    bool m_bIsDefusing;
    float m_tmHandleSignals;
    CUnifiedSignals m_signals;
    edict_t *m_pentCurBombTarget;
    int m_iPlayerSound;
    int m_iTargetVolume;
    int cso_baseplayer_1;
    int cso_baseplayer_2;
    int m_iWeaponVolume;
    int m_iExtraSoundTypes;
    int m_iWeaponFlash;
    float m_flStopExtraSoundTime;
    float m_flFlashLightTime;
    int m_iFlashBattery;
    int m_afButtonLast;
    int m_afButtonPressed;
    int m_afButtonReleased;
    int m_afButtonPressed2; // ADDED
    edict_t *m_pentSndLast;
    float m_flSndRoomtype;
    float m_flSndRange;
    float m_flFallVelocity;
    int m_rgItems[MAX_ITEMS];
    int m_fNewAmmo;
    unsigned int m_afPhysicsFlags;
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
    int m_iStepLeft;
    char m_szTextureName[MAX_TEXTURENAME_LENGHT];
    char m_chTextureType;
    int m_idrowndmg;
    int m_idrownrestored;
    int m_bitsHUDDamage;
    BOOL m_fInitHUD;
    BOOL m_fGameHUDInitialized;
    int m_iTrain;
    BOOL m_fWeapon;
    EHANDLE m_pTank;
    float m_fDeadTime;
    BOOL m_fNoPlayerSound;
    BOOL m_fLongJump;
    float m_tSneaking;
    int m_iUpdateTime;
    int m_iClientHealth;
    int m_iClientBattery;
    int m_iHideHUD;
    int m_iClientHideHUD;
    int m_iFOV;
    int m_iClientFOV;
    int m_iNumSpawns;
    CBaseEntity *m_pObserver;
    CBasePlayerItem *m_rgpPlayerItems[MAX_ITEM_TYPES];
    CBasePlayerItem *m_pActiveItem;
    CBasePlayerItem *m_pClientActiveItem;
    CBasePlayerItem *m_pLastItem;
    int m_rgAmmo[MAX_AMMO_SLOTS];
    int m_rgAmmoLast[MAX_AMMO_SLOTS];

    int cso_add_b[551];

    vec3_t m_vecAutoAim;
    BOOL m_fOnTarget;
    int m_iDeaths;
    int m_izSBarState[SBAR_END];
    float m_flNextSBarUpdateTime;
    float m_flStatusBarDisappearDelay;
    char m_SbarString0[MAX_SBAR_STRING];
    int m_lastx;
    int m_lasty;
    int m_nCustomSprayFrames;
    float m_flNextDecalTime;
    char m_szTeamName[MAX_TEAM_NAME_LENGTH];
    int m_modelIndexPlayer;
    char m_szAnimExtention[32];
    int m_iGaitsequence;
    float m_flGaitframe;
    float m_flGaityaw;
    vec3_t m_prevgaitorigin;
    float m_flPitch;
    float m_flYaw;
    float m_flGaitMovement;
    int m_iAutoWepSwitch;
    bool m_bVGUIMenus;
    bool m_bShowHints;
    bool m_bShieldDrawn;
    bool m_bOwnsShield;
    bool m_bWasFollowing;
    float m_flNextFollowTime;
    float m_flYawModifier;
    float m_blindUntilTime;
    float m_blindStartTime;
    float m_blindHoldTime;
    float m_blindFadeTime;
    int m_blindAlpha;
    float m_allowAutoFollowTime;
    char m_autoBuyString[MAX_AUTOBUY_LENGTH];
    char *m_rebuyString;
    RebuyStruct m_rebuyStruct;
    bool m_bIsInRebuy;
    float m_flLastUpdateTime;
    char m_lastLocation[MaxLocationLen];
    float m_progressStart;
    float m_progressEnd;
    bool m_bObserverAutoDirector;
    bool m_canSwitchObserverModes;
    float m_heartBeatTime;
    float m_intenseTimestamp;
    float m_silentTimestamp;
    MusicState m_musicState;
    float m_flLastCommandTime[COMMANDS_TO_TRACK];
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

struct CBasePlayerItem : CBaseAnimating {
    struct CBasePlayer *m_pPlayer;
    CBasePlayerItem *m_pNext;
    int m_iId; // WEAPON_???
    int m_iModelIndex;
    int cso_baseplayeritem_1;
};

struct CBasePlayerWeapon : CBasePlayerItem {
    int m_iPlayEmptySound;
    int m_fFireOnEmpty;
    int cso_baseplayer_weapon_1;
    int cso_baseplayer_weapon_2;
    float m_flNextPrimaryAttack;	// soonest time ItemPostFrame will call PrimaryAttack
    float m_flNextSecondaryAttack;	// soonest time ItemPostFrame will call SecondaryAttack
    float m_flTimeWeaponIdle;		// soonest time ItemPostFrame will call WeaponIdle    
    int m_iPrimaryAmmoType;			// "primary" ammo index into players m_rgAmmo[]
    int m_iSecondaryAmmoType;		// "secondary" ammo index into players m_rgAmmo[]
    int cso_baseplayer_weapon_3;
    int m_iClip;					// number of shots left in the primary weapon clip, -1 it not used
    int m_iClientClip;				// the last version of m_iClip sent to hud dll
    int cso_baseplayer_weapon_4;
    int cso_baseplayer_weapon_5;
    int m_iClientWeaponState;		// the last version of the weapon state sent to hud dll (is current weapon, is on target)
    int m_fInReload;				// Are we in the middle of a reload;
    int m_fInSpecialReload;			// Are we in the middle of a reload for the shotguns
    int m_iDefaultAmmo;				// how much ammo you get when you pick up this weapon as placed by a level designer.
    int cso_baseplayer_weapon_6;
    int m_iShellId;
    float m_fMaxSpeed;
    bool m_bDelayFire;
    BOOL m_iDirection;
    bool m_bSecondarySilencerOn;
    float m_flAccuracy;
    float m_flLastFire;
    int m_iShotsFired;
    vec3_t m_vVecAiming;
    string_t model_name;
    float m_flFamasShoot;
    int m_iFamasShotsFired;
    float m_fBurstSpread;
    int m_iWeaponState;
    float m_flNextReload;

    int m_iShell;
    int iShellOn;
    unsigned short m_usFireAK47;
};