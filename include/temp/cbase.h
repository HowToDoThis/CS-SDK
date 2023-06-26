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
    void (__thiscall* DeathNotice)(struct CBaseEntity* this);
    void (__thiscall* TraceAttack)(struct CBaseEntity* this);
    void (__thiscall* Function15)(struct CBaseEntity* this);
    bool (__thiscall* TakeDamage)(struct CBaseEntity* this, entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
    bool (__thiscall* TakeHealth)(struct CBaseEntity* this);
    void (__thiscall* Killed)(struct CBaseEntity* this, entvars_t *pevAttacker, int iGib);
    int  (__thiscall* BloodColor)(struct CBaseEntity* this);
    void (__thiscall* TraceBleed)(struct CBaseEntity* this, float flDamage, Vector vecDir, struct TraceResult *ptr, int bitsDamageType);
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
    void (__thiscall* CSO_ADD_0)(struct CBaseEntity* this);
    void (__thiscall* GetKnockbackData)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_1)(struct CBaseEntity* this);
    struct CBaseEntity* (__thiscall* GetNextTarget)(struct CBaseEntity* this);
    void (__thiscall* Think)(struct CBaseEntity* this);
    void (__thiscall* Touch)(struct CBaseEntity* this, CBaseEntity *pOther);
    void (__thiscall* Use)(struct CBaseEntity* this, CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
    void (__thiscall* Blocked)(struct CBaseEntity* this, CBaseEntity *pOther);
    void (__thiscall* UpdateOnRemove)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_2)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_3)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_4)(struct CBaseEntity* this);
    struct CBaseEntity* (__thiscall* Respawn)(struct CBaseEntity* this);
    vec_t* (__thiscall* Center)(struct CBaseEntity* this);
    vec_t* (__thiscall* EyePosition)(struct CBaseEntity* this);
    vec_t* (__thiscall* EarPosition)(struct CBaseEntity* this);
    vec_t* (__thiscall* BodyTarget)(struct CBaseEntity* this);
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
    void (__thiscall* CSO_ADD_13)(struct CBaseEntity* this);
    void (__thiscall* CSO_ADD_14)(struct CBaseEntity* this);
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

    TeamName m_iTeam;
    int m_LastHitGroup;
    int cso_add1;
    int cso_add2;
    int cso_add3;
};