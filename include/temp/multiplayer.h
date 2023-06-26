typedef int BOOL;
typedef int qboolean;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef unsigned short word;

typedef __int8 int8;
typedef unsigned __int8 uint8;
typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

typedef float vec_t;
typedef vec_t vec3_t[3];
typedef vec3_t Vector;
typedef unsigned int string_t;

typedef struct {
    float time;
    float frametime;
    float force_retouch;
    string_t mapname;
    string_t startspot;
    float deathmatch;
    float coop;
    float teamplay;
    float serverflags;
    float found_secrets;
    Vector v_forward;
    Vector v_up;
    Vector v_right;
    float trace_allsolid;
    float trace_startsolid;
    float trace_fraction;
    Vector trace_endpos;
    Vector trace_plane_normal;
    float trace_plane_dist;
    struct edict_t *trace_ent;
    float trace_inopen;
    float trace_inwater;
    int trace_hitgroup;
    int trace_flags;
    int msg_entity;
    int cdAudioTrack;
    int maxClients;
    int maxEntities;
    const char *pStringBase;
    void *pSaveData;
    Vector vecLandmarkOffset;
} globalvars_t;

typedef struct KeyValueData_s {
    char		*szClassName;	// in: entity classname
    char		*szKeyName;		// in: name of key
    char		*szValue;		// in: value of key
    qboolean	fHandled;		// out: DLL sets to true if key-value pair was understood
} KeyValueData;

// Returned by TraceLine
struct TraceResult {
    int		fAllSolid;			// if true, plane is not valid
    int		fStartSolid;		// if true, the initial point was in a solid area
    int		fInOpen;
    int		fInWater;
    float	flFraction;			// time completed, 1.0 = didn't hit anything
    vec3_t	vecEndPos;			// final position
    float	flPlaneDist;
    vec3_t	vecPlaneNormal;		// surface normal at impact
    struct edict_t	*pHit;				// entity the surface is on
    int		iHitgroup;			// 0 == generic, non zero is specific body part
};

typedef struct MULTIDAMAGE_s {
	class CBaseEntity *pEntity;
	float amount;
	int type;
} MULTIDAMAGE;