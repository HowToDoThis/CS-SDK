#define BIT(n) (1<<(n))

typedef enum _IN_BUTTONS {
    IN_ATTACK    = BIT(0),
    IN_JUMP      = BIT(1),
    IN_DUCK      = BIT(2),
    IN_FORWARD   = BIT(3),
    IN_BACK      = BIT(4),
    IN_USE       = BIT(5),
    IN_CANCEL    = BIT(6),
    IN_LEFT      = BIT(7),
    IN_RIGHT     = BIT(8),
    IN_MOVELEFT  = BIT(9),
    IN_MOVERIGHT = BIT(10),
    IN_ATTACK2   = BIT(11),
    IN_RUN       = BIT(12),
    IN_RELOAD    = BIT(13),
    IN_ALT1      = BIT(14),
    IN_SCORE     = BIT(15),
    
    IN_ACTIVE = IN_ATTACK | IN_ATTACK2 | IN_JUMP | IN_DUCK | IN_FORWARD | IN_BACK | IN_MOVELEFT | IN_MOVERIGHT,
} IN_BUTTONS;

typedef enum _CLASSIFY {
    CLASS_NONE,
    CLASS_MACHINE,
    CLASS_PLAYER,
    CLASS_HUMAN_PASSIVE,
    CLASS_HUMAN_MILITARY,
    CLASS_ALIEN_PASSIVE,
    CLASS_ALIEN_MILITARY,
    CLASS_ALIEN_MONSTER,
    CLASS_ALIEN_PREY,
    CLASS_ALIEN_PREDATOR,
    CLASS_INSECT,
    CLASS_PLAYER_ALLY,
    CLASS_PLAYER_BIOWEAPON,
    CLASS_ALIEN_BIOWEAPON,
    CLASS_VEHICLES,
    // CSO added
    CLASS_15,

    CLASS_BARNACLE = 99,
} CLASSIFY;

struct TraceResult {
    int      fAllSolid;       // if true, plane is not valid
    int      fStartSolid;     // if true, the initial point was in a solid area
    int      fInOpen;
    int      fInWater;
    float    flFraction;      // time completed, 1.0 = didn't hit anything
    vec3_t   vecEndPos;       // final position
    float    flPlaneDist;
    vec3_t   vecPlaneNormal;  // surface normal at impact
    edict_t* pHit;            // entity the surface is on
    int      iHitgroup;       // 0 == generic, non zero is specific body part
};