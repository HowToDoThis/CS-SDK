#define BIT(n)          (1 << (n))

#define MAX_QPATH       64
#define MSG_QUEUE_SIZE  1536
#define MAX_MSGLEN      8186
#define NET_MAX_MESSAGE 8234
#define MAX_LOOPBACK    4
#define NUM_MSG_QUEUES  40

#define FRAGMENT_MAX_SIZE          1400
#define MAX_PATH                    260
#define MAX_LATENT                   32
#define MAX_DATAGRAM               8000
#define MAX_PHYSINFO_STRING         256
#define MAX_EVENT_QUEUE              64
#define	MAX_ENT_LEAFS                48
#define MAX_INFO_STRING             512
#define MAX_RESOURCE_LIST          4140
#define MAX_CONSISTENCY_LIST        512
#define MAX_MODELS                 2048
#define MAX_EVENTS                  512
#define MAX_SOUNDS                 1324
#define MAX_GENERIC                2048
#define MAX_SOUNDS_HASHLOOKUP_SIZE 2647
#define MAX_LIGHTSTYLES              64
#define MIPLEVELS	                  4
#define MAX_MODEL_NAME	             64
#define MAX_MAP_HULLS	              4
#define MAXLIGHTMAPS	              4
#define CON_MAX_NOTIFY_STRING        80
#define MAX_KNOWN_MODELS           4096
#define NUM_AMBIENTS                  4
#define MAX_DEMOS                    32
#define MAX_ALIAS_NAME               32

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
struct fVector { float x; float y; float z; };

typedef unsigned int string_t;

typedef unsigned int CRC32_t;

typedef struct { byte r, g, b; }        color24;
typedef struct { unsigned r, g, b, a; } colorVec;

typedef enum netsrc_s {
    NS_CLIENT = 0,
    NS_SERVER,
    NS_MULTICAST,	// xxxMO
    NS_MAX
} netsrc_t;

enum {
    FRAG_NORMAL_STREAM = 0,
    FRAG_FILE_STREAM,
    MAX_STREAMS
};

enum {
    FLOW_OUTGOING = 0,
    FLOW_INCOMING,
    MAX_FLOWS
};

typedef enum redirect_e {
    RD_NONE = 0,
    RD_CLIENT = 1,
    RD_PACKET = 2,
} redirect_t;

typedef enum server_state_e {
    ss_dead = 0,
    ss_loading = 1,
    ss_active = 2,
} server_state_t;

typedef enum svc_commands_e {
    svc_bad,
    svc_nop,
    svc_disconnect,
    svc_event,
    svc_version,
    svc_setview,
    svc_sound,
    svc_time,
    svc_print,
    svc_stufftext,
    svc_setangle,
    svc_serverinfo,
    svc_lightstyle,
    svc_updateuserinfo,
    svc_deltadescription,
    svc_clientdata,
    svc_stopsound,
    svc_pings,
    svc_particle,
    svc_damage,
    svc_spawnstatic,
    svc_event_reliable,
    svc_spawnbaseline,
    svc_temp_entity,
    svc_setpause,
    svc_signonnum,
    svc_centerprint,
    svc_killedmonster,
    svc_foundsecret,
    svc_spawnstaticsound,
    svc_intermission,
    svc_finale,
    svc_cdtrack,
    svc_restore,
    svc_cutscene,
    svc_weaponanim,
    svc_decalname,
    svc_roomtype,
    svc_addangle,
    svc_newusermsg,
    svc_packetentities,
    svc_deltapacketentities,
    svc_choke,
    svc_resourcelist,
    svc_newmovevars,
    svc_resourcerequest,
    svc_customization,
    svc_crosshairangle,
    svc_soundfade,
    svc_filetxferfailed,
    svc_hltv,
    svc_director,
    svc_voiceinit,
    svc_voicedata,
    svc_sendextrainfo,
    svc_timescale,
    svc_resourcelocation,
    svc_sendcvarvalue,
    svc_sendcvarvalue2,
    svc_exec,
    svc_reserve60,
    svc_reserve61,
    svc_reserve62,
    svc_reserve63,
    svc_startofusermessages = svc_exec,
    svc_endoflist = 255,
} svc_commands_t;

typedef enum {
    FEV_NOTHOST  = BIT(0),
    FEV_RELIABLE = BIT(1),
    FEV_GLOBAL   = BIT(2),
    FEV_UPDATE   = BIT(3),
    FEV_HOSTONLY = BIT(4),
    FEV_SERVER   = BIT(5),
    FEV_CLIENT   = BIT(6),
} FEV;

typedef enum {
    BOTH = 0,
    SINGLEPLAYER_ONLY,
    MULTIPLAYER_ONLY,
} MOD_GAMEPLAY_TYPE_E;

typedef struct modinfo_s {
    qboolean bIsMod;
    char szInfo[256];
    char szDL[256];
    char szHLVersion[32];
    int version;
    int size;
    qboolean svonly;
    qboolean cldll;
    MOD_GAMEPLAY_TYPE_E type;
    int num_edicts;
} modinfo_t;

typedef enum modtype_e {
    mod_bad = -1,
    mod_brush,
    mod_sprite,
    mod_alias,
    mod_studio,
} modtype_t;

typedef enum AUTH_IDTYPE {
    AUTH_IDTYPE_UNKNOWN	= 0,
    AUTH_IDTYPE_STEAM	= 1,
    AUTH_IDTYPE_VALVE	= 2,
    AUTH_IDTYPE_LOCAL	= 3
};

typedef enum DeltaType {
    DT_BYTE				= BIT(0),	// A byte
    DT_SHORT			= BIT(1),	// 2 byte field
    DT_FLOAT			= BIT(2),	// A floating point field
    DT_INTEGER			= BIT(3),	// 4 byte integer
    DT_ANGLE			= BIT(4),	// A floating point angle
    DT_TIMEWINDOW_8		= BIT(5),	// A floating point timestamp relative to server time
    DT_TIMEWINDOW_BIG	= BIT(6),	// A floating point timestamp relative to server time (with more precision and custom multiplier)
    DT_STRING			= BIT(7),	// A null terminated string, sent as 8 byte chars
    DT_SIGNED			= BIT(31)	// sign modificator
};

const int MAX_EXTENSION_DLL = 50;

typedef struct functiontable_s {
    unsigned int pFunction;
    char *pFunctionName;
} functiontable_t;

typedef struct extensiondll_s {
    void *lDLLHandle;
    functiontable_t *functionTable;
    int functionCount;
} extensiondll_t;

typedef void(*ENTITYINIT)(struct entvars_s *);
typedef void(*DISPATCHFUNCTION)(struct entvars_s *, void *);
typedef void(*FIELDIOFUNCTION)(struct SAVERESTOREDATA *, const char *, void *, struct TYPEDESCRIPTION *, int);

typedef int(*pfnUserMsgHook)(const char *pszName, int iSize, void *pbuf);

// common.h
typedef struct sizebuf_s {
    const char *buffername;
    unsigned short flags;
    unsigned char *data;
    int maxsize;
    int cursize;
} sizebuf_t;

typedef struct bf_write_s {
    int nCurOutputBit;
    unsigned char *pOutByte;
    sizebuf_t *pbuf;
} bf_write_t;

typedef struct bf_read_s {
    int nMsgReadCount;	// was msg_readcount
    sizebuf_t *pbuf;
    int nBitFieldReadStartByte;
    int nBytesRead;
    int nCurInputBit;
    unsigned char *pInByte;
} bf_read_t;

typedef struct mplane_s {
    vec3_t			normal;			// surface normal
    float			dist;			// closest appoach to origin
    byte			type;			// for texture axis selection and fast side tests
    byte			signbits;		// signx + signy<<1 + signz<<1
    byte			pad[2];
} mplane_t;

typedef struct mnode_s {
    int				contents;		// 0, to differentiate from leafs
    int				visframe;		// node needs to be traversed if current
    short			minmaxs[6];		// for bounding box culling
    int undef[3];
    struct mnode_s	*parent;
    mplane_t		*plane;
    struct mnode_s	*children[2];
    unsigned short	firstsurface;
    unsigned short	numsurfaces;
} mnode_t;

typedef struct entvars_s {
    string_t	classname;
    string_t	globalname;
    vec3_t		origin;
    vec3_t		oldorigin;
    vec3_t		velocity;
    vec3_t		basevelocity;
    vec3_t      clbasevelocity;  // Base velocity that was passed in to server physics so 
    vec3_t		movedir;
    vec3_t		angles;			// Model angles
    vec3_t		avelocity;		// angle velocity (degrees per second)
    vec3_t		punchangle;		// auto-decaying view angle adjustment
    vec3_t		v_angle;		// Viewing angle (player only)
    vec3_t		endpos;
    vec3_t		startpos;
    float		impacttime;
    float		starttime;
    int			fixangle;		// 0:nothing, 1:force view angles, 2:add avelocity
    float		idealpitch;
    float		pitch_speed;
    float		ideal_yaw;
    float		yaw_speed;
    int			modelindex;
    string_t	model;
    int			viewmodel;		// player's viewmodel
    int			weaponmodel;	// what other players see
    vec3_t		absmin;		// BB max translated to world coord
    vec3_t		absmax;		// BB max translated to world coord
    vec3_t		mins;		// local BB min
    vec3_t		maxs;		// local BB max
    vec3_t		size;		// maxs - mins
    float		ltime;
    float		nextthink;
    int			movetype;
    int			solid;
    int			skin;			
    int			body;			// sub-model selection for studiomodels
    int 		effects;
    float		gravity;		// % of "normal" gravity
    float		friction;		// inverse elasticity of MOVETYPE_BOUNCE
    int			light_level;
    int			sequence;		// animation sequence
    int			gaitsequence;	// movement animation sequence for player (0 for none)
    float		frame;			// % playback position in animation sequences (0..255)
    float		animtime;		// world time when frame was set
    float		framerate;		// animation playback rate (-8x to 8x)
    byte		controller[4];	// bone controller setting (0..255)
    byte		blending[2];	// blending amount between sub-sequences (0..255)
    float		scale;			// sprite rendering scale (0..255)
    int			rendermode;
    float		renderamt;
    vec3_t		rendercolor;
    int			renderfx;
    float		health;
    float		frags;

    int			weapons;  // bit mask for available weapons
    int			deadflag;
    float view_ofs[2];
    float		takedamage; // ok
    
    int cso_add0;
    int cso_add1;
    int cso_add2;
    int cso_add3;

    int			button;
    int			impulse;
    struct edict_t		*chain;			// Entity pointer when linked into a linked list
    struct edict_t		*dmg_inflictor;
    struct edict_t		*enemy;
    struct edict_t		*aiment;		// entity pointer when MOVETYPE_FOLLOW
    struct edict_t		*owner;
    struct edict_t		*groundentity;
    int			spawnflags;
    int			flags;
    int         cso_add4;
    int			colormap;		// lowbyte topcolor, highbyte bottomcolor
    int			team;
    float		max_health;
    float		teleport_time;
    float		armortype;
    float		armorvalue;
    int			waterlevel;
    int			watertype;
    string_t	target;
    string_t	targetname;
    float		dmg_take;
    float		dmg_save;
    string_t	message;
    string_t	netname;
    float		dmg; // ok
    float		dmgtime;
    string_t	noise;
    string_t	noise1;
    string_t	noise2;
    string_t	noise3;
    float		speed;
    float		air_finished; // ok
    float		pain_finished;
    float		radsuit_finished;
    struct edict_t		*pContainingEntity;
    int			playerclass;
    float		maxspeed;
    float		fov;
    int			weaponanim;
    int			pushmsec;
    int			bInDuck;
    int			flTimeStepSound;
    int			flSwimTime;
    int			flDuckTime;
    int			iStepLeft;
    float		flFallVelocity;
    int			gamestate;
    int			oldbuttons;
    int			groupinfo;

    // For mods
    int			iuser1; // ok
    int			iuser2;
    int			iuser3;
    int			iuser4;
    float		fuser1;
    float		fuser2;
    float		fuser3;
    float		fuser4;
    vec3_t		vuser1;
    vec3_t		vuser2;
    vec3_t		vuser3;
    vec3_t		vuser4;
    struct edict_t		*euser1;
    struct edict_t		*euser2;
    struct edict_t		*euser3;
    struct edict_t		*euser4;

    int cso_add5;
} entvars_t;

typedef struct USERID_s {
    int idtype;
    unsigned int clientip;
} USERID_t;

typedef struct customization_s {
    qboolean bInUse;     // Is this customization in use;
    resource_t resource; // The resource_t for this customization
    qboolean bTranslated; // Has the raw data been translated into a useable format? (e.g., raw decal .wad make into texture_t *)
    int nUserData1; // Customization specific data
    int nUserData2; // Customization specific data
    void *pInfo;          // Buffer that holds the data structure that references the data (e.g., the cachewad_t)
    void *pBuffer;       // Buffer that holds the data for the customization (the raw .wad data)
    struct customization_s *pNext; // Next in chain
} customization_t;

typedef struct lump_s {
    int				fileofs;
    int				filelen;
} lump_t;

typedef struct cache_user_s {
    void	*data;
} cache_user_t;

typedef struct cachepic_s {
    char			name[64];
    cache_user_t	cache;
} cachepic_t;

typedef enum synctype_e {
    ST_SYNC = 0,
    ST_RAND = 1,
} synctype_t;

typedef enum cactive_t {
    ca_dedicated = 0,	// This is a dedicated server, client code is inactive
    ca_disconnected,	// full screen console with no connection
    ca_connecting,		// netchan_t established, waiting for svc_serverdata
    ca_connected,		// processing data lists, donwloading, etc
    ca_uninitialized,
    ca_active			// everything is in, so frames can be rendered
};

typedef void(*PFNCACHE)(struct cachewad_t *, unsigned char *);
typedef struct cachewad_s {
    char			*name;
    cachepic_t		*cache;
    int				cacheCount;
    int				cacheMax;
    struct lumpinfo_s *lumps;
    int				lumpCount;
    int				cacheExtra;
    PFNCACHE		pfnCacheBuild;
    int				numpaths;
    char			**basedirs;
    int				*lumppathindices;
    int				tempWad;
} cachewad_t;

typedef struct texture_s {
    char			name[16];
    unsigned		width, height;
    int			gl_texturenum;
    struct msurface_s *	texturechain;
    int				anim_total;			// total tenths in sequence ( 0 = no)
    int				anim_min, anim_max;	// time for this frame min <=time< max
    struct texture_s *anim_next;		// in the animation sequence
    struct texture_s *alternate_anims;	// bmodels in frame 1 use these
    unsigned		offsets[MIPLEVELS];	// four mip maps stored
    byte *pPal;
} texture_t;

typedef struct dmodel_s {
    float			mins[3], maxs[3];
    float			origin[3];
    int				headnode[MAX_MAP_HULLS];
    int				visleafs;		// not including the solid leaf 0
    int				firstface, numfaces;
} dmodel_t;

typedef struct dheader_s {
    int				version;
    lump_t			lumps[15];
} dheader_t;

typedef struct mvertex_s {
    vec3_t			position;
} mvertex_t;

typedef struct medge_s {
    unsigned short	v[2];
    unsigned int	cachededgeoffset;
} medge_t;

typedef struct mtexinfo_s {
    float			vecs[2][4];
    float			mipadjust;		// ?? mipmap limits for very small surfaces
    texture_t		*texture;
    int				flags;			// sky or slime, no lightmap or 256 subdivision
} mtexinfo_t;

typedef struct decal_s {
    struct decal_t	*pnext;			// linked list for each surface
    struct msurface_t	*psurface;		// Surface id for persistence / unlinking
    short			dx;				// Offsets into surface texture (in texture coordinates, so we don't need floats)
    short			dy;
    short			texture;		// Decal texture
    byte			scale;			// Pixel scale
    byte			flags;			// Decal flags

    short			entityIndex;	// Entity this is attached to
} decal_t;

typedef struct msurface_s {
    int				visframe;		// should be drawn when node is crossed
    int				dlightframe;	// last frame the surface was checked by an animated light
    int				dlightbits;
    mplane_t		*plane;			// pointer to shared plane
    int				flags;			// see SURF_ #defines
    int				firstedge;	// look up in model->surfedges[], negative numbers
    int				numedges;	// are backwards edges
    struct surfcache_s *cachespots[MIPLEVELS];
    short			texturemins[2]; // smallest s/t position on the surface.
    short			extents[2];		// ?? s/t texture size, 1..256 for all non-sky surfaces
    mtexinfo_t		*texinfo;
    byte			styles[MAXLIGHTMAPS];
    color24			*samples;
    decal_t			*pdecals;
} msurface_t;

typedef struct mleaf_s {
    int			contents;		// wil be a negative contents number
    int			visframe;		// node needs to be traversed if current
    short		minmaxs[6];		// for bounding box culling // TODO: float for gl quake render
    struct mnode_s	*parent;
    byte		*compressed_vis;
    struct efrag_s *efrags;
    msurface_t	**firstmarksurface;
    int			nummarksurfaces;
    int			key;			// BSP sequence number for leaf's contents
    byte		ambient_sound_level[NUM_AMBIENTS];
} mleaf_t;

typedef struct dclipnode_s {
    int				planenum;
    short			children[2];	// negative numbers are contents
} dclipnode_t;

typedef struct hull_s {
    dclipnode_t		*clipnodes;
    mplane_t		*planes;
    int				firstclipnode;
    int				lastclipnode;
    vec3_t			clip_mins, clip_maxs;
} hull_t;

typedef struct model_s {
    char			name[MAX_MODEL_NAME];
    int		needload;		// bmodels and sprites don't cache normally
    modtype_t		type;
    int				numframes;
    synctype_t		synctype;
    int				flags;
    vec3_t			mins, maxs;
    float			radius;
    int				firstmodelsurface, nummodelsurfaces;
    int				numsubmodels;
    dmodel_t		*submodels;
    int				numplanes;
    mplane_t		*planes;
    int				numleafs;		// number of visible leafs, not counting 0
    struct mleaf_s	*leafs;
    int				numvertexes;
    mvertex_t		*vertexes;
    int				numedges;
    medge_t			*edges;
    int				numnodes;
    mnode_t			*nodes;
    int				numtexinfo;
    mtexinfo_t		*texinfo;
    int				numsurfaces;
    msurface_t		*surfaces;
    int				numsurfedges;
    int				*surfedges;
    int				numclipnodes;
    dclipnode_t		*clipnodes;
    int				nummarksurfaces;
    msurface_t		**marksurfaces;
    hull_t			hulls[MAX_MAP_HULLS];
    int				numtextures;
    texture_t		**textures;
    byte			*visdata;
    color24			*lightdata;
    char			*entities;
    int unk[8];
    cache_user_t	cache;			// only access through Mod_Extradata
} model_t;

typedef struct mod_known_info_s {
    qboolean		shouldCRC;
    qboolean		firstCRCDone;
    CRC32_t			initialCRC;
} mod_known_info_t;

typedef enum synctype_e {
    ST_SYNC = 0,
    ST_RAND = 1,
} synctype_t;

typedef struct dsprite_s {
    int				ident;
    int				version;
    int				type;
    int				texFormat;
    float			boundingradius;
    int				width;
    int				height;
    int				numframes;
    float			beamlength;
    synctype_t		synctype;
    int unk;
} dsprite_t;

typedef struct dspriteframe_s {
    int				origin[2];
    int				width;
    int				height;
} dspriteframe_t;

typedef struct mspriteframe_t {
    int				width;
    int				height;
    void			*pcachespot;
    float			up, down, left, right;
    byte			pixels[4];
} mspriteframe_s;

typedef struct mdl_s {
    int				ident;
    int				version;
    vec3_t			scale;
    vec3_t			scale_origin;
    float			boundingradius;
    vec3_t			eyeposition;
    int				numskins;
    int				skinwidth;
    int				skinheight;
    int				numverts;
    int				numtris;
    int				numframes;
    synctype_t		synctype;
    int				flags;
    float			size;
    //int unk;
} mdl_t;

typedef struct event_hook_s {
    event_hook_s* next;
    char* name;
    void (*pfnEvent)(event_args_s*);
} event_hook_t;

typedef struct ipfilter_s {
    unsigned int mask;
    union {
        uint32 u32;
        uint8 octets[4];
    } compare;
    float banEndTime;
    float banTime;
} ipfilter_t;

typedef struct userfilter_s {
    USERID_t userid;
    float banEndTime;
    float banTime;
} userfilter_t;

typedef struct client_data_s {
    vec3_t unk;
    // fields that cannot be modified  (ie. have no effect if changed)
    vec3_t origin;
    // fields that can be changed by the cldll
    vec3_t viewangles;
    int		iWeaponBits;
    float	fov;	// field of view
} client_data_t;

// dalias
typedef enum aliasframetype_s {
    ALIAS_SINGLE = 0,
    ALIAS_GROUP = 1,
} aliasframetype_t;
typedef enum aliasskintype_s {
    ALIAS_SKIN_SINGLE = 0,
    ALIAS_SKIN_GROUP = 1,
} aliasskintype_t;

typedef struct trivertx_s {
    byte			v[3];
    byte			lightnormalindex;
} trivertx_t;

typedef struct daliasframe_s {
    trivertx_t		bboxmin, bboxmax;
    char			name[16];
} daliasframe_t;

typedef struct daliasgroup_s {
    int				numframes;
    trivertx_t		bboxmin, bboxmax;
} daliasgroup_t;

typedef struct daliasskingroup_s {
    int				numskins;
} daliasskingroup_t;

typedef struct daliasinterval_s {
    float			interval;
} daliasinterval_t;

typedef struct daliasskininterval_s {
    float			interval;
} daliasskininterval_t;

typedef struct daliasframetype_s {
    aliasframetype_t type;
} daliasframetype_t;

typedef struct daliasskintype_s {
    aliasskintype_t type;
} daliasskintype_t;

// 
typedef struct wadinfo_s {
    char identification[4];
    int numlumps;
    int infotableofs;
} wadinfo_t;

typedef struct lumpinfo_s {
    int filepos;
    int disksize;
    int size;
    char type;
    char compression;
    char pad1;
    char pad2;
    char name[16];
} lumpinfo_t;

typedef struct texlumpinfo_s {
    lumpinfo_t lump;
    int iTexFile;
} texlumpinfo_t;

struct da_notify_t {
    char szNotify[CON_MAX_NOTIFY_STRING];
    float expire;
    float color[3];
};

typedef struct {
    const char* name;
    int keynum;
} keyname_t;

typedef struct _UserMsg
{
    int iMsg;
    int iSize;
    char szName[16];
    struct _UserMsg *next;
    pfnUserMsgHook pfn;
} UserMsg;

// GL.h
typedef struct {
    const char *name;
    int minimize, maximize;
} glmode_t;

typedef struct {
    int texnum;
    char* identifier;
    int width, height;
    int unk;
    qboolean mipmap;
} gltexture_t;

// command.h
typedef void(*xcommand_t)(void);
typedef struct cmd_function_s {
    struct cmd_function_s *next;
    const char *name;
    xcommand_t function;
    int flags;
} cmd_function_t;

typedef enum cmd_source_s {
    src_client = 0,		// came in over a net connection as a clc_stringcmd. host_client will be valid during this state.
    src_command = 1,	// from the command buffer.
} cmd_source_t;

// zone.h
typedef struct hunk_s {
    int sentinel;
    int size;
    char name[64];
} hunk_t;

typedef struct cache_system_s {
    int size; // including this header
    cache_user_t *user;
    char name[64];
    struct cache_system_s *prev, *next;
    struct cache_system_s *lru_prev, *lru_next; // for LRU flushing
} cache_system_t;

// delta.h
typedef enum {
    DT_BYTE				= BIT(0),	// A byte
    DT_SHORT			= BIT(1),	// 2 byte field
    DT_FLOAT			= BIT(2),	// A floating point field
    DT_INTEGER			= BIT(3),	// 4 byte integer
    DT_ANGLE			= BIT(4),	// A floating point angle
    DT_TIMEWINDOW_8		= BIT(5),	// A floating point timestamp relative to server time
    DT_TIMEWINDOW_BIG	= BIT(6),	// A floating point timestamp relative to server time (with more precision and custom multiplier)
    DT_STRING			= BIT(7),	// A null terminated string, sent as 8 byte chars
    DT_BYTES            = BIT(8),   // CSO ADDED??
    DT_SIGNED			= BIT(31)	// sign modificator
} delta_type;

typedef void(*encoder_t)(struct delta_t *, const unsigned char *, const unsigned char *);

typedef struct delta_stats_s {
    int sendcount;
    int receivedcount;
} delta_stats_t;

typedef struct delta_description_s {
    int fieldType;
    char fieldName[32];
    int fieldOffset;
    short int fieldSize;
    int significant_bits;
    float premultiply;
    float postmultiply;
    short int flags;
    delta_stats_t stats;
} delta_description_t;

typedef struct delta_s {
    int dynamic;
    int fieldCount;
    char conditionalencodename[32];
    encoder_t conditionalencode;
    delta_description_t *pdd;
} delta_t;

typedef struct delta_link_s {
    struct delta_link_t *next;
    delta_description_t *delta;
} delta_link_t;

typedef struct delta_definition_s {
    char *fieldName;
    size_t fieldOffset;
} delta_definition_t;

typedef struct delta_info_s {
    delta_info_s *next;
    char *name;
    char *loadfile;
    delta_t *delta;
} delta_info_t;

typedef struct delta_definition_list_s {
    delta_definition_list_s *next;
    char *ptypename;
    int numelements;
    delta_definition_t *pdefinition;
} delta_definition_list_t;

typedef struct delta_registry_s {
    delta_registry_s *next;
    char *name;
    delta_t *pdesc;
} delta_registry_t;

// entity_state.h
typedef struct entity_state_s {
// Fields which are filled in by routines outside of delta compression
    int			entityType;
    // Index into cl_entities array for this entity.
    int			number;
    float		msg_time;
    // Message number last time the player/entity state was updated.
    int			messagenum;
    // Fields which can be transitted and reconstructed over the network stream
    vec3_t		origin;
    vec3_t		angles;
    int			modelindex;
    int			sequence;
    float		frame;
    int			colormap;
    short		skin;
    short		solid;
    int			effects;
    float		scale;
    byte		eflags;	
    // Render information
    int			rendermode;
    int			renderamt;
    color24		rendercolor;
    int			renderfx;
    int			movetype;
    float		animtime;
    float		framerate;
    int			body;
    byte		controller[4];
    byte		blending[4];
    vec3_t		velocity;
    // Send bbox down to client for use during prediction.
    vec3_t		mins;
    vec3_t		maxs;
    int			aiment;
    // If owned by a player, the index of that player ( for projectiles ).
    int			owner;
    // Friction, for prediction.
    float		friction;
    // Gravity multiplier
    float		gravity;
    // PLAYER SPECIFIC
    int			team;
    int			playerclass;
    int         unk1;
    int			health;
    qboolean	spectator;
    int			weaponmodel;
    int			gaitsequence;
    // If standing on conveyor, e.g.
    vec3_t		basevelocity;
    // Use the crouched hull, or the regular player hull.
    int			usehull;
    // Latched buttons last time state updated.
    int			oldbuttons;
    // -1 = in air, else pmove entity number
    int			onground;
    int			iStepLeft;
    // How fast we are falling
    float		flFallVelocity;
    float		fov;
    int			weaponanim;
    // Parametric movement overrides
    vec3_t		startpos;
    vec3_t		endpos;
    float		impacttime;
    float		starttime;
    // For mods
    int			iuser1;
    int			iuser2;
    int			iuser3;
    int			iuser4;
    float		fuser1;
    float		fuser2;
    float		fuser3;
    float		fuser4;
    vec3_t		vuser1;
    vec3_t		vuser2;
    vec3_t		vuser3;
    vec3_t		vuser4;
} entity_state_t;

typedef enum sv_delta_s {
    sv_packet_nodelta,
    sv_packet_delta,
} sv_delta_t;

typedef struct packet_entities_s {
    int num_entities;
    unsigned char flags[32];
    int unk1[11];
    entity_state_t *entities;
} packet_entities_t;

// net.h
typedef enum {
    NA_UNUSED,
    NA_LOOPBACK,
    NA_BROADCAST,
    NA_IP,
    NA_IPX,
    NA_BROADCAST_IPX,
} netadrtype_t;

typedef struct netadr_s {
    netadrtype_t type;     // 4
    unsigned char ipx[14]; // 16
    //unsigned short unk3;   // 18
    unsigned short port;   // 20
    int localIP;
    int unk5;
} netadr_t;

typedef struct challenge_s {
    netadr_t adr;
    int challenge;
    int time;
} challenge_t;

typedef struct packetlag_s {
    unsigned char *pPacketData;	// Raw stream data is stored.
    int nSize;
    netadr_t net_from_;
    float receivedTime;
    struct packetlag_s *pNext;
    struct packetlag_s *pPrev;
} packetlag_t;

typedef struct fragbuf_s {
    // Next buffer in chain
    fragbuf_s *next;
    // Id of this buffer
    int bufferid;
    // Message buffer where raw data is stored
    sizebuf_t frag_message;
    // The actual data sits here
    byte frag_message_buf[FRAGMENT_MAX_SIZE];
    // Is this a file buffer?
    qboolean isfile;
    // Is this file buffer from memory ( custom decal, etc. ).
    qboolean isbuffer;
    qboolean iscompressed;
    // Name of the file to save out on remote host
    char filename[MAX_PATH];
    // Offset in file from which to read data
    int foffset;
    // Size of data to read at that offset
    int size;
} fragbuf_t;

typedef struct fragbufwaiting_s {
    fragbufwaiting_s *next;
    int fragbufcount;
    fragbuf_t *fragbufs;
} fragbufwaiting_t;

typedef struct flowstats_s {
    int size;
    double time;
} flowstats_t;

typedef struct flow_s {
    flowstats_t stats[MAX_LATENT];
    int current;
    double nextcompute;
    float kbytespersec;
    float avgkbytespersec;
} flow_t;

typedef struct netchan_s {
    netsrc_t sock;
    netadr_t remote_address;
    int player_slot;
    float last_received;
    float connect_time;
    double rate;
    double cleartime;
    int incoming_sequence;
    int incoming_acknowledged;
    int incoming_reliable_acknowledged;
    int incoming_reliable_sequence;
    int outgoing_sequence;
    int reliable_sequence;
    int last_reliable_sequence;
    void *connection_status;
    int (*pfnNetchan_Blocksize)(void *);
    sizebuf_t message;
    byte message_buf[MAX_MSGLEN];
    int reliable_length;
    byte reliable_buf[MAX_MSGLEN];
    fragbufwaiting_t *waitlist[MAX_STREAMS];
    int reliable_fragment[MAX_STREAMS];
    unsigned int reliable_fragid[MAX_STREAMS];
    fragbuf_t *fragbufs[MAX_STREAMS];
    int fragbufcount[MAX_STREAMS];
    short int frag_startpos[MAX_STREAMS];
    short int frag_length[MAX_STREAMS];
    fragbuf_t *incomingbufs[MAX_STREAMS];
    qboolean incomingready[MAX_STREAMS];
    char incomingfilename[MAX_PATH];
    void *tempbuffer;
    int tempbuffersize;
    flow_t flow[MAX_FLOWS];
} netchan_t;

typedef struct loopmsg_s
{
    unsigned char data[NET_MAX_MESSAGE];
    int datalen;
} loopmsg_t;
typedef struct loopback_s
{
    loopmsg_t msgs[MAX_LOOPBACK];
    int get;
    int send;
} loopback_t;

typedef enum svc_commands_e {
    svc_bad,
    svc_nop,
    svc_disconnect,
    svc_event,
    svc_version,
    svc_setview,
    svc_sound,
    svc_time,
    svc_print,
    svc_stufftext,
    svc_setangle,
    svc_serverinfo,
    svc_lightstyle,
    svc_updateuserinfo,
    svc_deltadescription,
    svc_clientdata,
    svc_stopsound,
    svc_pings,
    svc_particle,
    svc_damage,
    svc_spawnstatic,
    svc_event_reliable,
    svc_spawnbaseline,
    svc_temp_entity,
    svc_setpause,
    svc_signonnum,
    svc_centerprint,
    svc_killedmonster,
    svc_foundsecret,
    svc_spawnstaticsound,
    svc_intermission,
    svc_finale,
    svc_cdtrack,
    svc_restore,
    svc_cutscene,
    svc_weaponanim,
    svc_decalname,
    svc_roomtype,
    svc_addangle,
    svc_newusermsg,
    svc_packetentities,
    svc_deltapacketentities,
    svc_choke,
    svc_resourcelist,
    svc_newmovevars,
    svc_resourcerequest,
    svc_customization,
    svc_crosshairangle,
    svc_soundfade,
    svc_filetxferfailed,
    svc_hltv,
    svc_director,
    svc_voiceinit,
    svc_voicedata,
    svc_sendextrainfo,
    svc_timescale,
    svc_resourcelocation,
    svc_sendcvarvalue,
    svc_sendcvarvalue2,
    svc_startrestoredgame,
    svc_updatemodel,
    svc_endoflist = 255,
};

struct svc_func_s {
    svc_commands_e opcode;
    char *pszname;
    void (__cdecl* func)();
};

// 11 + 1 end
typedef enum clc_commands {
    clc_bad,
    clc_nop,
    clc_move,
    clc_stringcmd,
    clc_delta,
    clc_resourcelist,
    clc_tmove,
    clc_fileconsistency,
    clc_voicedata,
    clc_hltv,
    clc_cvarvalue,
    clc_cvarvalue2,
    clc_endoflist = 255,
};
struct clc_func_s {
    clc_commands opcode;
    char *pszname;
    void (__cdecl* func)();
};

typedef struct cmdalias_s {
    struct cmdalias_s	*next;
    char	name[MAX_ALIAS_NAME];
    char	*value;
} cmdalias_t;

// hashpak.h
typedef enum {
    t_sound = 0,
    t_skin,
    t_model,
    t_decal,
    t_generic,
    t_eventscript,
    t_world,		// Fake type for world, is really t_model
    rt_unk,
    rt_max
} resourcetype_t;

typedef struct resource_s {
    char              szFileName[MAX_QPATH]; // File name to download/precache.
    resourcetype_t    type;                // t_sound, t_skin, t_model, t_decal.
    int               nIndex;              // For t_decals
    int               nDownloadSize;       // Size in Bytes if this must be downloaded.
    unsigned char     ucFlags;

    // For handling client to client resource propagation
    unsigned char     rgucMD5_hash[16];    // To determine if we already have it.
    unsigned char     playernum;           // Which player index this resource is associated with, if it's a custom resource.

    unsigned char	  rguc_reserved[ 32 ]; // For future expansion
    struct resource_s *pNext;              // Next in chain.
    struct resource_s *pPrev;
} resource_t;

typedef struct hash_pack_queue_s {
    char *pakname;
    resource_t resource;
    int datasize;
    void *data;
    struct hash_pack_queue_s *next;
} hash_pack_queue_t;

typedef struct hash_pack_entry_s {
    resource_t resource;
    int nOffset;
    int nFileLength;
} hash_pack_entry_t;

typedef struct hash_pack_directory_s {
    int nEntries;
    hash_pack_entry_t *p_rgEntries;
} hash_pack_directory_t;

// md5.h
typedef struct {
    unsigned int buf[4];
    unsigned int bits[2];
    unsigned char in[64];
} MD5Context_t;

// sound.h
typedef struct {
    qboolean gamealive;
    qboolean soundalive;
    qboolean splitbuffer;
    int channels;
    int samples;          // mono samples in buffer
    int submission_chunk; // don't mix less than this #
    int samplepos;        // in mono samples
    int samplebits;
    int speed;
    unsigned char *buffer;
    int unk1;
} dma_t;

typedef struct sfx_s {
    char name[MAX_QPATH];
    cache_user_t cache;
    int servercount;
} sfx_t;

typedef struct {
    int length;
    int loopstart;
    int speed;
    int width;
    int stereo;
    byte data[1]; // variable sized
} sfxcache_t;

typedef struct {
    sfx_t *sfx;      // sfx number
    int leftvol;     // 0-255 volume
    int rightvol;    // 0-255 volume
    int end;         // end time in global paintsamples
    int pos;         // sample position in sfx
    int looping;     // where to loop, -1 = no looping
    int entnum;      // to allow overriding a specific sound
    int entchannel;  //
    vec3_t origin;   // origin of sound effect
    vec_t dist_mult; // distance multiplier (attenuation/clipK)
    int master_vol;  // 0-255 master volume
    int iSentence;
    int iWord;
    int Pitch;
    int undef[2];
} channel_t;

struct voxword_t {
    int		volume;					// increase percent, ie: 125 = 125% increase
    int		pitch;					// pitch shift up percent
    int		start;					// offset start of wave percent
    int		end;					// offset end of wave percent
    int		cbtrim;					// end of wave after being trimmed to 'end'
    int		fKeepCached;			// 1 if this word was already in cache before sentence referenced it
    int		samplefrac;				// if pitch shifting, this is position into wav * 256
    int		timecompress;			// % of wave to skip during playback (causes no pitch shift)
    sfx_t*	sfx;					// name and cache pointer
};

struct wavinfo_t {
    int		rate;
    int		width;
    int		channels;
    int		loopstart;
    int		samples;
    int		dataofs;		// chunk starts this many bytes from file start
};

struct wavstream_t {
    int		csamplesplayed;
    int		csamplesinmem;
    FileHandle_t hFile;
    wavinfo_t info;
    int		lastposloaded;
};

// filesystem.h
typedef FILE* FileHandle_t;

typedef enum {
    FILESYSTEM_SEEK_HEAD = 0,
    FILESYSTEM_SEEK_CURRENT,
    FILESYSTEM_SEEK_TAIL,
} FileSystemSeek_t;

typedef enum {
    FILESYSTEM_WARNING = -1,					// A problem!
    FILESYSTEM_WARNING_QUIET = 0,				// Don't print anything
    FILESYSTEM_WARNING_REPORTUNCLOSED,			// On shutdown, report names of files left unclosed
    FILESYSTEM_WARNING_REPORTUSAGE,				// Report number of times a file was opened, closed
    FILESYSTEM_WARNING_REPORTALLACCESSES		// Report all open/close events to console (!slow!)
} FileWarningLevel_t;

// usercmd.h
typedef struct usercmd_s {
    short	lerp_msec;      // Interpolation time on client
    byte	msec;           // Duration in ms of command
    vec3_t	viewangles;     // Command view angles.
    float	forwardmove;    // Forward velocity.
    float	sidemove;       // Sideways velocity.
    float	upmove;         // Upward velocity.
    byte	lightlevel;     // Light level at spot where we are standing.
    unsigned short  buttons;  // Attack buttons
    byte    impulse;          // Impulse command issued.
    byte	weaponselect;	// Current weapon id
    int		impact_index;
    vec3_t	impact_position;
    int unk1;
} usercmd_t;

// entity_state.h
typedef struct clientdata_s {
    vec3_t				origin;
    vec3_t				velocity;
    int					viewmodel;
    vec3_t				punchangle;
    int					flags;
    int					waterlevel;
    int					watertype;
    vec3_t				view_ofs;
    float				health;
    int					bInDuck;
    int					weapons; // remove?
    int					flTimeStepSound;
    int					flDuckTime;
    int					flSwimTime;
    int					waterjumptime;
    float				maxspeed;
    float				fov;
    int					weaponanim;
    int					m_iId;
    int					ammo_shells;
    int					ammo_nails;
    int					ammo_cells;
    int					ammo_rockets;
    float				m_flNextAttack;
    int					tfstate;
    int					pushmsec;
    int					deadflag;
    double              cso_unk1;
    char				physinfo[ MAX_PHYSINFO_STRING ];
    // For mods
    int					iuser1;
    int					iuser2;
    int					iuser3;
    int					iuser4;
    float				fuser1;
    float				fuser2;
    float				fuser3;
    float				fuser4;
    vec3_t				vuser1;
    vec3_t				vuser2;
    vec3_t				vuser3;
    vec3_t				vuser4;

    float              cso_unk2;
    float              cso_unk3;
    float              cso_unk4;
    float              cso_unk5;
} clientdata_t;

// weaponinfo.h
typedef struct weapon_data_s {
    int			m_iId;
    int			m_iClip;
    float		m_flNextPrimaryAttack;
    float		m_flNextSecondaryAttack;
    float		m_flTimeWeaponIdle;
    int			m_fInReload;
    int			m_fInSpecialReload;
    float		m_flNextReload;
    float		m_flPumpTime;
    float		m_fReloadTime;
    float		m_fAimedDamage;
    float		m_fNextAimBonus;
    int			m_fInZoom;
    int			m_iWeaponState;
    int			iuser1;
    int			iuser2;
    int			iuser3;
    int			iuser4;
    float		fuser1;
    float		fuser2;
    float		fuser3;
    float		fuser4;
    int unk;
} weapon_data_t;

// edict.h
typedef struct link_s {
    struct link_s	*prev, *next;
} link_t;

typedef struct edict_s {
    qboolean	free;
    int			serialnumber;
    link_t		area;
    int			headnode;
    int			num_leafs;
    short		leafnums[MAX_ENT_LEAFS];
    float		freetime;
    void*		pvPrivateData;
    entvars_t	v;
} edict_t;

// event.h
typedef struct event_args_s {
    int		flags;
    int		entindex;
    float	origin[3];
    float	angles[3];
    float	velocity[3];
    int		ducking;
    float	fparam1;
    float	fparam2;
    int		iparam1;
    int		iparam2;
    int		bparam1;
    int		bparam2;
} event_args_t;

typedef struct event_info_s {
    unsigned short index;
    short packet_index;
    short entity_index;
    float fire_time;
    event_args_t args;
    int	  flags;
} event_info_t;

typedef struct event_state_s {
    struct event_info_s ei[MAX_EVENT_QUEUE];
} event_state_t;

typedef struct event_s {
    unsigned short index;
    const char *filename;
    int filesize;
    const char *pszScript;
} event_t;

// progdefs.h
typedef struct globalvars_s {	
    float		time;
    float		frametime;
    float		force_retouch;
    string_t	mapname;
    string_t	startspot;
    float		deathmatch_;
    float		coop_;
    float		teamplay;
    float		serverflags;
    float		found_secrets;
    vec3_t		v_forward;
    vec3_t		v_up;
    vec3_t		v_right;
    float		trace_allsolid;
    float		trace_startsolid;
    float		trace_fraction;
    vec3_t		trace_endpos;
    vec3_t		trace_plane_normal;
    float		trace_plane_dist;
    edict_t		*trace_ent;
    float		trace_inopen;
    float		trace_inwater;
    int			trace_hitgroup;
    int			trace_flags;
    int			msg_entity;
    int			cdAudioTrack;
    int			maxClients;
    int			maxEntities;
    const char	*pStringBase;
    void		*pSaveData;
    vec3_t		vecLandmarkOffset;
} globalvars_t;

// baseline.h
#define NUM_BASELINES 64
typedef struct extra_baselines_s {
    int number;
    int classname[NUM_BASELINES];
    entity_state_t baseline[NUM_BASELINES];
} extra_baselines_t;

// consistency.h
typedef struct consistency_s {
    char *filename;
    int issound;
    int orig_index;
    int value;
    int check_type;
    float mins[3];
    float maxs[3];
} consistency_t;

// sequence.h
typedef enum sequenceModifierBits {
    SEQUENCE_MODIFIER_EFFECT_BIT		= (1 << 1),
    SEQUENCE_MODIFIER_POSITION_BIT		= (1 << 2),
    SEQUENCE_MODIFIER_COLOR_BIT			= (1 << 3),
    SEQUENCE_MODIFIER_COLOR2_BIT		= (1 << 4),
    SEQUENCE_MODIFIER_FADEIN_BIT		= (1 << 5),
    SEQUENCE_MODIFIER_FADEOUT_BIT		= (1 << 6),
    SEQUENCE_MODIFIER_HOLDTIME_BIT		= (1 << 7),
    SEQUENCE_MODIFIER_FXTIME_BIT		= (1 << 8),
    SEQUENCE_MODIFIER_SPEAKER_BIT		= (1 << 9),
    SEQUENCE_MODIFIER_LISTENER_BIT		= (1 << 10),
    SEQUENCE_MODIFIER_TEXTCHANNEL_BIT	= (1 << 11),
} sequenceModifierBits_e;

typedef enum sequenceCommandEnum_ {
    SEQUENCE_COMMAND_ERROR = -1,
    SEQUENCE_COMMAND_PAUSE = 0,
    SEQUENCE_COMMAND_FIRETARGETS,
    SEQUENCE_COMMAND_KILLTARGETS,
    SEQUENCE_COMMAND_TEXT,
    SEQUENCE_COMMAND_SOUND,
    SEQUENCE_COMMAND_GOSUB,
    SEQUENCE_COMMAND_SENTENCE,
    SEQUENCE_COMMAND_REPEAT,
    SEQUENCE_COMMAND_SETDEFAULTS,
    SEQUENCE_COMMAND_MODIFIER,
    SEQUENCE_COMMAND_POSTMODIFIER,
    SEQUENCE_COMMAND_NOOP,

    SEQUENCE_MODIFIER_EFFECT,
    SEQUENCE_MODIFIER_POSITION,
    SEQUENCE_MODIFIER_COLOR,
    SEQUENCE_MODIFIER_COLOR2,
    SEQUENCE_MODIFIER_FADEIN,
    SEQUENCE_MODIFIER_FADEOUT,
    SEQUENCE_MODIFIER_HOLDTIME,
    SEQUENCE_MODIFIER_FXTIME,
    SEQUENCE_MODIFIER_SPEAKER,
    SEQUENCE_MODIFIER_LISTENER,
    SEQUENCE_MODIFIER_TEXTCHANNEL,
} sequenceCommandEnum_e;

typedef enum sequenceCommandType_ {
    SEQUENCE_TYPE_COMMAND,
    SEQUENCE_TYPE_MODIFIER,
} sequenceCommandType_e;

typedef struct sequenceCommandMapping_ {
    sequenceCommandEnum_e	commandEnum;
    const char*				commandName;
    sequenceCommandType_e	commandType;
} sequenceCommandMapping_s;

typedef struct client_textmessage_s {
    int		effect;
    byte	r1, g1, b1, a1;		// 2 colors for effects
    byte	r2, g2, b2, a2;
    float	x;
    float	y;
    float	fadein;
    float	fadeout;
    float	holdtime;
    float	fxtime;
    const char *pName;
    const char *pMessage;
} client_textmessage_t;

typedef struct sequenceCommandLine_ {
    int						commandType;		// Specifies the type of command
    client_textmessage_t	clientMessage;		// Text HUD message struct
    char*					speakerName;		// Targetname of speaking entity
    char*					listenerName;		// Targetname of entity being spoken to
    char*					soundFileName;		// Name of sound file to play
    char*					sentenceName;		// Name of sentences.txt to play
    char*					fireTargetNames;	// List of targetnames to fire
    char*					killTargetNames;	// List of targetnames to remove
    float					delay;				// Seconds 'till next command
    int						repeatCount;		// If nonzero, reset execution pointer to top of block (N times, -1 = infinite)
    int						textChannel;		// Display channel on which text message is sent
    int						modifierBitField;	// Bit field to specify what clientmessage fields are valid
    sequenceCommandLine_s*	nextCommandLine;	// Next command (linked list)
} sequenceCommandLine_s;

typedef struct sequenceEntry_ {
    char*					fileName;		// Name of sequence file without .SEQ extension
    char*					entryName;		// Name of entry label in file
    sequenceCommandLine_s*	firstCommand;	// Linked list of commands in entry
    sequenceEntry_s*		nextEntry;		// Next loaded entry
    qboolean				isGlobal;		// Is entry retained over level transitions?
} sequenceEntry_s;

typedef struct sentenceEntry_ {
    char*					data;			// sentence data (ie "We have hostiles" )
    sentenceEntry_s*		nextEntry;		// Next loaded entry
    qboolean				isGlobal;		// Is entry retained over level transitions?
    unsigned int			index;			// this entry's position in the file.
} sentenceEntry_s;

typedef struct sentenceGroupEntry_ {
    char*					groupName;		// name of the group (ie CT_ALERT )
    unsigned int			numSentences;	// number of sentences in group
    sentenceEntry_s*		firstSentence;	// head of linked list of sentences in group
    struct sentenceGroupEntry_s*	nextEntry;		// next loaded group
} sentenceGroupEntry_s;


// server.h
typedef struct client_frame_s {
    double senttime;
    float ping_time;
    clientdata_t clientdata;
    weapon_data_t weapondata[352];
    packet_entities_t entities;
} client_frame_t;

typedef struct client_s {
    qboolean active;
    qboolean spawned;
    qboolean fully_connected;
    qboolean connected;
    qboolean uploading;
    qboolean hasusrmsgs;
    qboolean has_force_unmodified;
    netchan_t netchan;
    int chokecount;
    int delta_sequence;
    qboolean fakeclient;
    qboolean proxy;
    usercmd_t lastcmd;
    double connecttime;
    double cmdtime;
    double ignorecmdtime;
    float latency;
    float packet_loss;
    double localtime;
    double nextping;
    double svtimebase;
    sizebuf_t datagram;
    byte datagram_buf[MAX_DATAGRAM];
    double connection_started;
    double next_messagetime;
    double next_messageinterval;
    qboolean send_message;
    qboolean skip_message;
    client_frame_t *frames;
    event_state_t events;
    edict_t *edict;
    const edict_t *pViewEntity;
    int userid;
    USERID_t network_userid;
    char userinfo[MAX_INFO_STRING];
    qboolean sendinfo;
    float sendinfo_time;
    char hashedcdkey[64];
    char name[32];
    int topcolor;
    int bottomcolor;
    int entityId;
    resource_t resourcesonhand;
    resource_t resourcesneeded;
    FileHandle_t upload;
    qboolean uploaddoneregistering;
    customization_t customdata;
    int crcValue;
    int lw;
    int lc;
    char physinfo[MAX_INFO_STRING / 2];
    qboolean m_bLoopback;
    uint32 m_VoiceStreams[2];
    char unk1[2048];
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
} client_t;

typedef struct server_s {
    qboolean active;
    qboolean paused;
    qboolean loadgame;
    double time;
    double oldtime;
    int lastcheck;
    double lastchecktime;
    char name[64];
    char oldname[64];
    char startspot[64];
    char modelname[64];
    struct model_s *worldmodel;
    CRC32_t worldmapCRC;
    unsigned char clientdllmd5[16];
    resource_t resourcelist[MAX_RESOURCE_LIST];
    int num_resources;
    consistency_t consistency_list[MAX_CONSISTENCY_LIST];
    int num_consistency;
    const char *model_precache[MAX_MODELS];
    struct model_s *models[MAX_MODELS];
    unsigned char model_precache_flags[MAX_MODELS];
    struct event_s event_precache[MAX_EVENTS];
    const char *sound_precache[MAX_SOUNDS];
    short int sound_precache_hashedlookup[MAX_SOUNDS_HASHLOOKUP_SIZE];
    qboolean sound_precache_hashedlookup_built;
    const char *generic_precache[MAX_GENERIC];
    char generic_precache_names[MAX_GENERIC][64];
    int num_generic_names;
    const char *lightstyles[MAX_LIGHTSTYLES];
    int num_edicts;
    int max_edicts;
    edict_t *edicts;
    struct entity_state_s *baselines;
    extra_baselines_t *instance_baselines;
    server_state_t state;
    sizebuf_t datagram;
    unsigned char datagram_buf[MAX_DATAGRAM];
    sizebuf_t reliable_datagram;
    unsigned char reliable_datagram_buf[MAX_DATAGRAM];
    sizebuf_t multicast;
    unsigned char multicast_buf[1024];
    sizebuf_t spectator;
    unsigned char spectator_buf[1024];
    sizebuf_t signon;
    unsigned char signon_data[32768];
    sizebuf_t sigon_wpnlist;
    unsigned char sigon_wpnlist_data[0x8000];
} server_t;

// eiface.h
#define MAX_LEVEL_CONNECTIONS 16

typedef struct {
    int			id;				// Ordinal ID of this entity (used for entity <--> pointer conversions)
    edict_t	*pent;			// Pointer to the in-game entity
    int			location;		// Offset from the base data of this entity
    int			size;			// Byte size of this entity's data
    int			flags;			// This could be a short -- bit mask of transitions that this entity is in the PVS of
    string_t	classname;		// entity class name

} ENTITYTABLE;

typedef struct {
    char		mapName[ 32 ];
    char		landmarkName[ 32 ];
    edict_t		*pentLandmark;
    vec3_t		vecLandmarkOrigin;
} LEVELLIST;

typedef struct saverestore_s {
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
    LEVELLIST	levelList[ MAX_LEVEL_CONNECTIONS ];		// List of connections from this level
    // smooth transition
    int			fUseLandmark;
    char		szLandmarkName[20];// landmark we'll spawn near in next level
    vec3_t		vecLandmarkOffset;// for landmark transitions
    float		time;
    char		szCurrentMapName[32];	// To check global entities

} SAVERESTOREDATA;

typedef struct SAVE_HEADER_s {
    int saveId;
    int version;
    int skillLevel;
    int entityCount;
    int connectionCount;
    int lightStyleCount;
    float time;
    char mapName[32];
    char skyName[32];
    int skyColor_r;
    int skyColor_g;
    int skyColor_b;
    float skyVec_x;
    float skyVec_y;
    float skyVec_z;
} SAVE_HEADER;

// server_static.h
typedef struct server_log_s {
    qboolean active;
    qboolean net_log_;
    netadr_t net_address_;
    void *file;
} server_log_t;

typedef struct server_stats_s {
    int num_samples;
    int at_capacity;
    int at_empty;
    float capacity_percent;
    float empty_percent;
    int minusers;
    int maxusers;
    float cumulative_occupancy;
    float occupancy;
    int num_sessions;
    float cumulative_sessiontime;
    float average_session_len;
    float cumulative_latency;
    float average_latency;
} server_stats_t;

typedef struct server_static_s {
    qboolean dll_initialized;
    client_t *clients;
    int maxclients;
    int maxclientslimit;
    int spawncount;
    int serverflags;
    server_log_t log;
    double next_cleartime;
    double next_sampletime;
    server_stats_t stats;
    qboolean isSecure;
} server_static_t;

typedef struct sv_adjusted_positions_s {
    int active;
    int needrelink;
    vec3_t neworg;
    vec3_t oldorg;
    vec3_t initial_correction_org;
    vec3_t oldabsmin;
    vec3_t oldabsmax;
    int deadflag;
    vec3_t temp_org;
    int temp_org_setflag;
} sv_adjusted_positions_t;

// client.h
typedef struct screenfade_s {
    float		fadeSpeed;		// How fast to fade (tics / second) (+ fade in, - fade out)
    float		fadeEnd;		// When the fading hits maximum
    float		fadeTotalEnd;	// Total End Time of the fade (used for FFADE_OUT)
    float		fadeReset;		// When to reset to not fading (for fadeout and hold)
    byte		fader, fadeg, fadeb, fadealpha;	// Fade color
    int			fadeFlags;		// Fading flags
} screenfade_t;

typedef struct {
    double receivedtime;
    double latency;
    qboolean invalid;
    qboolean choked;
    entity_state_t playerstate[32];
    double time;
    clientdata_t clientdata;
    weapon_data_t weapondata[352];
    packet_entities_t packet_entities;
    unsigned short clientbytes;
    unsigned short playerinfobytes;
    unsigned short packetentitybytes;
    unsigned short tentitybytes;
    unsigned short soundbytes;
    unsigned short eventbytes;
    unsigned short usrbytes;
    unsigned short voicebytes;
    unsigned short msgbytes;
} frame_t;

typedef struct efrag_s {
    struct mleaf_s		*leaf;
    struct efrag_s		*leafnext;
    struct cl_entity_s	*entity;
    struct efrag_s		*entnext;
} efrag_t;

typedef struct {
    byte					mouthopen;		// 0 = mouth closed, 255 = mouth agape
    byte					sndcount;		// counter for running average
    int						sndavg;			// running average
} mouth_t;

typedef struct {
    // Time stamp for this movement
    float					animtime;
    vec3_t					origin;
    vec3_t					angles;
} position_history_t;

typedef struct {
    float					prevanimtime;  
    float					sequencetime;
    byte					prevseqblending[2];
    vec3_t					prevorigin;
    vec3_t					prevangles;
    int						prevsequence;
    float					prevframe;
    byte					prevcontroller[4];
    byte					prevblending[2];
} latchedvars_t;

#define HISTORY_MAX 64
typedef struct {
    int						index;      // Index into cl_entities ( should match actual slot, but not necessarily )
    qboolean				player;     // True if this entity is a "player"
    entity_state_t			baseline;   // The original state from which to delta during an uncompressed message
    entity_state_t			prevstate;  // The state information from the penultimate message received from the server
    entity_state_t			curstate;   // The state information from the last message received from server
    int						current_position;  // Last received history update index
    position_history_t		ph[HISTORY_MAX];   // History of position and angle updates for this player
    mouth_t					mouth;			// For synchronizing mouth movements.
    latchedvars_t			latched;		// Variables used by studio model rendering routines
    // Information based on interplocation, extrapolation, prediction, or just copied from last msg received.
    float					lastmove;
    // Actual render position and angles
    vec3_t					origin;
    vec3_t					angles;
    // Attachment points
    vec3_t					attachment[4];
    // Other entity local information
    int						trivial_accept;
    struct model_s			*model;			// cl.model_precache[ curstate.modelindes ];  all visible entities have a model
    struct efrag_s			*efrag;			// linked list of efrags
    struct mnode_s			*topnode;		// for bmodels, first world node that splits bmodel, or NULL if not split
    float					syncbase;		// for client-side animations -- used by obsolete alias animation system, remove?
    int						visframe;		// last frame this entity was found in an active leaf
    colorVec				cvFloorColor;
} cl_entity_t;

typedef struct dlight_s {
    vec3_t	origin;
    float	radius;
    color24	color;
    float	die;				// stop lighting after this time
    float	decay;				// drop this each second
    float	minlight;			// don't add when contributing less
    int		key;
    qboolean	dark;			// subtracts light instead of adding
} dlight_t;

typedef struct player_info_s
{
    // User id on server
    int		userid;
    // User info string
    char	userinfo[ MAX_INFO_STRING ];
    // Name
    char	name[32];
    // Spectator or not, unused
    int		spectator;
    int		ping;
    int		packet_loss;
    // skin information
    char	model[MAX_QPATH];
    int		topcolor;
    int		bottomcolor;
    // last frame rendered
    int		renderframe;
    // Gait frame estimation
    int		gaitsequence;
    float	gaitframe;
    float	gaityaw;
    vec3_t	prevgaitorigin;
    customization_t customdata;
    //TODO: determine if constant needed - Solokiller
    char hashedcdkey[16];
    uint64 m_nSteamID;
} player_info_t;

typedef struct {
    int client; // ????
    resource_t resourcesonhand;
    resource_t resourcesneeded;
    resource_t resourcelist[4140];
    int num_resources;
    qboolean need_force_consistency_response;
    char serverinfo[512];
    int servercount;
    int validsequence;
    int parsecount;
    int parsecountmod;
    int stats[32];

    double cso_unk1;
    double cso_unk2;
    usercmd_t cmd;

    vec3_t viewangles;
    vec3_t punchangle;
    vec3_t crosshairangle;
    vec3_t simorg;
    vec3_t simvel;
    vec3_t simangles;
    vec_t predicted_origins[64][3];
    vec3_t prediction_error;
    float idealpitch;
    vec3_t viewheight;

    screenfade_t sf;
    bool paused;
    int onground;
    int moving;
    int waterlevel;
    int usehull;
    float maxspeed;
    int pushmsec;
    int light_level;
    int intermission;
    double mtime[2];
    double time;
    double oldtime;
    frame_t frames[64];

    char cso_unk3[80][64]; // its something like buffer, idk
    char cso_unk4[0x81CC][64]; // playerstate(0x158) + clientdata(0x1F4) + clientdata.vuser4[3](0x5C)
    int  cso_unk5;
    
    int playernum;
    event_t event_precache[MAX_EVENTS];
    model_t* model_precache[MAX_MODELS];
    int model_precache_count;
    sfx_t* sound_precache[MAX_SOUNDS];

    // CL_ParseConsistencyInfo
    int  cso_unk6;
    char cso_unk7[511 * 44]; // some stuff 44 size
    int  cso_unk8; // count of above
    
    int highentity;
    char levelname[40];
    int maxclients;
    model_t* worldmodel;
    efrag_t* free_efrags;
    int num_entities;
    int num_statics;
    cl_entity_t viewent;
    int cdtrack;
    int looptrack;
    CRC32_t serverCRC;
    byte clientdllmd5[16];
    float weaponstarttime;
    int weaponsequence;
    int fPrecaching;
    dlight_t* pLight;
    player_info_t players[32];
    entity_state_t instanced_baseline[64];
    int instanced_baseline_number;
    CRC32_t mapCRC;
    event_state_t events;
    char downloadUrl[128];
} client_state_t;

typedef struct downloadtime_s
{
    qboolean bUsed;
    float fTime;
    int nBytesRemaining;
} downloadtime_t;

typedef struct incomingtransfer_s
{
    qboolean doneregistering;
    int percent;
    qboolean downloadrequested;
    downloadtime_t rgStats[8];
    int nCurStat;
    int nTotalSize;
    int nTotalToTransfer;
    int nRemainingToTransfer;
    float fLastStatusUpdate;
    qboolean custom;
} incomingtransfer_t;

typedef struct soundfade_s
{
    int nStartPercent;
    int nClientSoundFadePercent;
    double soundFadeStartTime;
    int soundFadeOutTime;
    int soundFadeHoldTime;
    int soundFadeInTime;
} soundfade_t;

typedef struct client_static_s {
    cactive_t state;
    netchan_t netchan;
    sizebuf_t datagram;
    byte datagram_buf[MAX_DATAGRAM];
    double connect_time;
    int connect_retry;
    int challenge;
    byte authprotocol;
    int userid;
    char trueaddress[32];
    float slist_time;
    int signon;
    char servername[MAX_PATH];
    char mapstring[64];
    char spawnparms[2048];
    char userinfo[MAX_INFO_STRING];
    float nextcmdtime;
    int lastoutgoingcommand;
    int demonum;
    char demos[MAX_DEMOS][16];
    qboolean demorecording;
    qboolean demoplayback;
    qboolean timedemo;
    float demostarttime;
    int demostartframe;
    int forcetrack;
    FileHandle_t demofile;
    FileHandle_t demoheader;
    qboolean demowaiting;
    qboolean demoappending;
    char demofilename[MAX_PATH];
    int demoframecount;
    int td_lastframe;
    int td_startframe;
    float td_starttime;
    incomingtransfer_t dl;
    float packet_loss;
    double packet_loss_recalc_time;
    int playerbits;
    soundfade_t soundfade;
    char physinfo[MAX_PHYSINFO_STRING];
    unsigned char md5_clientdll[16];
    netadr_t game_stream;
    netadr_t connect_stream;
    qboolean passive;
    qboolean spectator;
    qboolean director;
    qboolean fSecureClient;
    qboolean isVAC2Secure;
    uint64 GameServerSteamID;
    int build_num;
} client_static_t;