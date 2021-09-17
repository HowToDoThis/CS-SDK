// BASETYPES.h
typedef int BOOL;
typedef int qboolean;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef unsigned short word;

// ARCHTYPES.h
typedef __int8 int8;
typedef unsigned __int8 uint8;
typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;
typedef __int32 intp;				// intp is an integer that can accomodate a pointer
typedef unsigned __int32 uintp;		// (ie, sizeof(intp) >= sizeof(int) && sizeof(intp) >= sizeof(void *)


// CONST.h
typedef unsigned int string_t;

typedef struct edict_s edict_t;

typedef struct {
	byte r, g, b;
} color24;

typedef struct {
	unsigned r, g, b, a;
} colorVec;

typedef struct {
	unsigned short r, g, b, a;
} PackedColorVec;

typedef struct link_s {
	struct link_s	*prev, *next;
} link_t;

typedef struct {
	vec3_t	normal;
	float	dist;
} plane_t;

typedef struct {
	qboolean	allsolid;		// if true, plane is not valid
	qboolean	startsolid;		// if true, the initial point was in a solid area
	qboolean	inopen, inwater;
	float		fraction;		// time completed, 1.0 = didn't hit anything
	vec3_t		endpos;			// final position
	plane_t		plane;			// surface normal at impact
	edict_t	*	ent;			// entity the surface is on
	int			hitgroup;		// 0 == generic, non zero is specific body part
} trace_t;

// FILESYSTEM.h
typedef FILE *FileHandle_t;

// CRC.h
typedef unsigned int CRC32_t;
