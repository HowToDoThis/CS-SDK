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
    vec3_t v_forward;
    vec3_t v_up;
    vec3_t v_right;
    float trace_allsolid;
    float trace_startsolid;
    float trace_fraction;
    vec3_t trace_endpos;
    vec3_t trace_plane_normal;
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
    vec3_t vecLandmarkOffset;
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

typedef enum _fieldtypes {
	FIELD_FLOAT = 0,		// Any floating point value
	FIELD_STRING,			// A string ID (return from ALLOC_STRING)
	FIELD_ENTITY,			// An entity offset (EOFFSET)
	FIELD_CLASSPTR,			// CBaseEntity *
	FIELD_EHANDLE,			// Entity handle
	FIELD_EVARS,			// EVARS *
	FIELD_EDICT,			// edict_t *, or edict_t *  (same thing)
	FIELD_VECTOR,			// Any vector
	FIELD_POSITION_VECTOR,	// A world coordinate (these are fixed up across level transitions automagically)
	FIELD_POINTER,			// Arbitrary data pointer... to be removed, use an array of FIELD_CHARACTER
	FIELD_INTEGER,			// Any integer or enum
	FIELD_FUNCTION,			// A class function pointer (Think, Use, etc)
	FIELD_BOOLEAN,			// boolean, implemented as an int, I may use this as a hint for compression
	FIELD_SHORT,			// 2 byte integer
	FIELD_CHARACTER,		// a byte
	FIELD_TIME,				// a floating point time (these are fixed up automatically too!)
	FIELD_MODELNAME,		// Engine string that is a model name (needs precache)
	FIELD_SOUNDNAME,		// Engine string that is a sound name (needs precache)

	FIELD_TYPECOUNT,		// MUST BE LAST
} FIELDTYPE;

typedef struct {
	FIELDTYPE		fieldType;
	char			*fieldName;
	int				fieldOffset;
	short			fieldSize;
	short			flags;
} TYPEDESCRIPTION;

typedef struct {
	char		mapName[ 32 ];
	char		landmarkName[ 32 ];
	edict_t		*pentLandmark;
	vec3_t		vecLandmarkOrigin;
} LEVELLIST;

typedef struct {
	int			id;				// Ordinal ID of this entity (used for entity <--> pointer conversions)
	edict_t	*pent;              // Pointer to the in-game entity

	int			location;		// Offset from the base data of this entity
	int			size;			// Byte size of this entity's data
	int			flags;			// This could be a short -- bit mask of transitions that this entity is in the PVS of
	string_t	classname;		// entity class name

} ENTITYTABLE;

typedef struct saverestore_s
{
	char		*pBaseData;		// Start of all entity save data
	char		*pCurrentData;	// Current buffer pointer for sequential access
	int			size;			// Current data size
	int			bufferSize;		// Total space for data
	int			tokenSize;		// Size of the linear list of tokens
	int			tokenCount;		// Number of elements in the pTokens table
	char		**pTokens;		// Hash table of entity strings (sparse)
	int			currentIndex;	// Holds a global entity table ID
	int			tableCount;		// Number of elements in the entity table
	int			connectionCount;// Number of elements in the levelList[]
	ENTITYTABLE	*pTable;		// Array of ENTITYTABLE elements (1 for each entity)
	LEVELLIST	levelList[ 16 ];		// List of connections from this level

	// smooth transition
	int			fUseLandmark;
	char		szLandmarkName[20];// landmark we'll spawn near in next level
	vec3_t		vecLandmarkOffset;// for landmark transitions
	float		time;
	char		szCurrentMapName[32];	// To check global entities
} SAVERESTOREDATA;

struct CSaveRestoreBuffer {
    void* vfptr;
    SAVERESTOREDATA *m_pData;
};

struct CSave : CSaveRestoreBuffer {
};

struct CRestore : CSaveRestoreBuffer {
    BOOL m_global;
    BOOL m_precache;
};