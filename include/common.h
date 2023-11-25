// COMMON.h
typedef struct sizebuf_s {
    const char *buffername;
    unsigned short flags;
    unsigned char *data;
    int maxsize;
    int cursize;
} sizebuf_t;

// CVARDEF.h
typedef struct cvar_s {
    char *name;
    char	*string;
    int		flags;
    float	value;
    struct cvar_s *next;
} cvar_t;

// USERCMD.h
typedef struct usercmd_s {
    short	lerp_msec;      // Interpolation time on client
    byte	msec;           // Duration in ms of command
    vec3_t	viewangles;     // Command view angles.

// intended velocities
    float	forwardmove;    // Forward velocity.
    float	sidemove;       // Sideways velocity.
    float	upmove;         // Upward velocity.
    byte	lightlevel;     // Light level at spot where we are standing.
    unsigned short  buttons;  // Attack buttons
    byte    impulse;          // Impulse command issued.
    byte	weaponselect;	// Current weapon id

// Experimental player impact stuff.
    int		impact_index;
    vec3_t	impact_position;
} usercmd_t;

// ENTITY_STATE.h
#define MAX_PHYSINFO_STRING 256

// REQUIRED 500 but only has 476
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
} clientdata_t;

typedef struct entity_state_s entity_state_t;
struct entity_state_s {
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
};

// DELTA_PACKET.h
typedef struct packet_entities_s {
    int num_entities;
    unsigned char flags[32];
    entity_state_t *entities;
} packet_entities_t;


// WEAPONINFO.h
// Info about weapons player might have in his/her possession
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
} weapon_data_t;

// EVENT_ARGS.h
typedef struct event_args_s {
    int		flags;

    // Transmitted
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


// PROGS.h
#define MAX_EVENT_QUEUE 64

struct event_info_s {
    unsigned short index;			  // 0 implies not in use

    short packet_index;      // Use data from state info for entity in delta_packet .  -1 implies separate info based on event
                             // parameter signature
    short entity_index;      // The edict this event is associated with

    float fire_time;        // if non-zero, the time when the event should be fired ( fixed up on the client )
    
    event_args_t args;

    // CLIENT ONLY	
    int	  flags;			// Reliable or not, etc.

};

typedef struct event_state_s event_state_t;

struct event_state_s {
    struct event_info_s ei[ MAX_EVENT_QUEUE ];
};

// PROGDEFS.h
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

// EDICT.h
#define	MAX_ENT_LEAFS	48

struct edict_s {
    qboolean	free;
    int			serialnumber;
    link_t		area;				// linked to a division node or leaf
    
    int			headnode;			// -1 to use normal leaf check
    int			num_leafs;
    short		leafnums[MAX_ENT_LEAFS];

    float		freetime;			// sv.time when the object was freed

    void*		pvPrivateData;		// Alloced and freed by engine, used by DLLs

    entvars_t	v;					// C exported fields from progs

    // other fields from progs come immediately after
};

// USERID.h
typedef struct USERID_s {
    int idtype;
    uint64 m_SteamID;
    unsigned int clientip;
} USERID_t;

// CUSTOM.h
#define MAX_QPATH 64    // Must match value in quakedefs.h

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

typedef struct resource_s
{
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

typedef struct customization_s
{
    qboolean bInUse;		// Is this customization in use;
    resource_t resource;	// The resource_t for this customization
    qboolean bTranslated;	// Has the raw data been translated into a useable format?
                            //  (e.g., raw decal .wad make into texture_t *)
    int nUserData1;			// Customization specific data
    int nUserData2;			// Customization specific data
    void *pInfo;			// Buffer that holds the data structure that references the data (e.g., the cachewad_t)
    void *pBuffer;			// Buffer that holds the data for the customization (the raw .wad data)
    struct customization_s *pNext; // Next in chain
} customization_t;

// PM_TRACE.h
typedef struct {
    vec3_t	normal;
    float	dist;
} pmplane_t;

typedef struct pmtrace_s
{
    qboolean	allsolid;	      // if true, plane is not valid
    qboolean	startsolid;	      // if true, the initial point was in a solid area
    qboolean	inopen, inwater;  // End point is in empty space or in water
    float		fraction;		  // time completed, 1.0 = didn't hit anything
    vec3_t		endpos;			  // final position
    pmplane_t	plane;		      // surface normal at impact
    int			ent;			  // entity at impact
    vec3_t      deltavelocity;    // Change in player's velocity caused by impact.  
                                  // Only run on server.
    int         hitgroup;
} pmtrace_t;


// PM_DEFS.h
#define	MAX_PHYSENTS 600 		  // Must have room for all entities in the world.
#define MAX_MOVEENTS 64

typedef struct physent_s {
    char			name[32];             // Name of model, or "player" or "world".
    int				player;
    vec3_t			origin;               // Model's origin in world coordinates.
    struct model_s	*model;		          // only for bsp models
    struct model_s	*studiomodel;         // SOLID_BBOX, but studio clip intersections.
    vec3_t			mins, maxs;	          // only for non-bsp models
    int				info;		          // For client or server to use to identify (index into edicts or cl_entities)
    vec3_t			angles;               // rotated entities need this info for hull testing to work.

    int				solid;				  // Triggers and func_door type WATER brushes are SOLID_NOT
    int				skin;                 // BSP Contents for such things like fun_door water brushes.
    int				rendermode;			  // So we can ignore glass

    // Complex collision detection.
    float			frame;
    int				sequence;
    byte			controller[4];
    byte			blending[2];

    int				movetype;
    int				takedamage;
    int				blooddecal;
    int				team;
    int				classnumber;

    // For mods
    int				iuser1;
    int				iuser2;
    int				iuser3;
    int				iuser4;
    float			fuser1;
    float			fuser2;
    float			fuser3;
    float			fuser4;
    vec3_t			vuser1;
    vec3_t			vuser2;
    vec3_t			vuser3;
    vec3_t			vuser4;
} physent_t;

typedef struct playermove_s {
    int				player_index;  // So we don't try to run the PM_CheckStuck nudging too quickly.
    qboolean		server;        // For debugging, are we running physics code on server side?

    qboolean		multiplayer;   // 1 == multiplayer server
    float			time;          // realtime on host, for reckoning duck timing
    float			frametime;	   // Duration of this frame

    vec3_t			forward, right, up; // Vectors for angles
    // player state
    vec3_t			origin;        // Movement origin.
    vec3_t			angles;        // Movement view angles.
    vec3_t			oldangles;     // Angles before movement view angles were looked at.
    vec3_t			velocity;      // Current movement direction.
    vec3_t			movedir;       // For waterjumping, a forced forward velocity so we can fly over lip of ledge.
    vec3_t			basevelocity;  // Velocity of the conveyor we are standing, e.g.

    // For ducking/dead
    vec3_t			view_ofs;      // Our eye position.
    float			flDuckTime;    // Time we started duck
    qboolean		bInDuck;       // In process of ducking or ducked already?

    // For walking/falling
    int				flTimeStepSound;  // Next time we can play a step sound
    int				iStepLeft;

    float			flFallVelocity;
    vec3_t			punchangle;

    float			flSwimTime;

    float			flNextPrimaryAttack;

    int				effects;		// MUZZLE FLASH, e.g.

    int				flags;         // FL_ONGROUND, FL_DUCKING, etc.
    int				usehull;       // 0 = regular player hull, 1 = ducked player hull, 2 = point hull
    float			gravity;       // Our current gravity and friction.
    float			friction;
    int				oldbuttons;    // Buttons last usercmd
    float			waterjumptime; // Amount of time left in jumping out of water cycle.
    qboolean		dead;          // Are we a dead player?
    int				deadflag;
    int				spectator;     // Should we use spectator physics model?
    int				movetype;      // Our movement type, NOCLIP, WALK, FLY

    int				onground;
    int				waterlevel;
    int				watertype;
    int				oldwaterlevel;

    char			sztexturename[256];
    char			chtexturetype;

    float			maxspeed;
    float			clientmaxspeed; // Player specific maxspeed

    // For mods
    int				iuser1;
    int				iuser2;
    int				iuser3;
    int				iuser4;
    float			fuser1;
    float			fuser2;
    float			fuser3;
    float			fuser4;
    vec3_t			vuser1;
    vec3_t			vuser2;
    vec3_t			vuser3;
    vec3_t			vuser4;
    // world state
    // Number of entities to clip against.
    int				numphysent;
    physent_t		physents[MAX_PHYSENTS];
    // Number of momvement entities (ladders)
    int				nummoveent;
    // just a list of ladders
    physent_t		moveents[MAX_MOVEENTS];

    // All things being rendered, for tracing against things you don't actually collide with
    int				numvisent;
    physent_t		visents[ MAX_PHYSENTS ];

    // input to run through physics.
    usercmd_t		cmd;

    // Trace results for objects we collided with.
    int				numtouch;
    pmtrace_t		touchindex[MAX_PHYSENTS];

    char			physinfo[ MAX_PHYSINFO_STRING ]; // Physics info string

    struct movevars_s *_movevars;
    vec3_t player_mins[MAX_MAP_HULLS];
    vec3_t player_maxs[MAX_MAP_HULLS];

    // Common functions
    const char		*(*PM_Info_ValueForKey) ( const char *s, const char *key );
    void			(*PM_Particle)( float *origin, int color, float life, int zpos, int zvel);
    int				(*PM_TestPlayerPosition) (float *pos, pmtrace_t *ptrace );
    void			(*Con_NPrintf)( int idx, const char *fmt, ... );
    void			(*Con_DPrintf)( const char *fmt, ... );
    void			(*Con_Printf)( const char *fmt, ... );
    double			(*Sys_FloatTime)( void );
    void			(*PM_StuckTouch)( int hitent, pmtrace_t *ptraceresult );
    int				(*PM_PointContents) (float *p, int *truecontents /*filled in if this is non-null*/ );
    int				(*PM_TruePointContents) (float *p);
    int				(*PM_HullPointContents) ( struct hull_s *hull, int num, float *p);
    pmtrace_t		(*PM_PlayerTrace) (float *start, float *end, int traceFlags, int ignore_pe );
    struct pmtrace_s *(*PM_TraceLine)( float *start, float *end, int flags, int usehulll, int ignore_pe );
    int32			(*RandomLong)( int32 lLow, int32 lHigh );
    float			(*RandomFloat)( float flLow, float flHigh );
    int				(*PM_GetModelType)( struct model_s *mod );
    void			(*PM_GetModelBounds)( struct model_s *mod, float *mins, float *maxs );
    struct hull_s	*(*PM_HullForBsp)( physent_t *pe, float *offset );
    float			(*PM_TraceModel)( physent_t *pEnt, float *start, float *end, trace_t *trace );
    int				(*COM_FileSize)(const char *filename);
    byte			*(*COM_LoadFile) (const char *path, int usehunk, int *pLength);
    void			(*COM_FreeFile) ( void *buffer );
    char			*(*memfgets)( byte *pMemFile, int fileSize, int *pFilePos, char *pBuffer, int bufferSize );

    // Functions
    // Run functions for this frame?
    qboolean		runfuncs;
    void			(*PM_PlaySound) ( int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch );
    const char		*(*PM_TraceTexture) ( int ground, float *vstart, float *vend );
    void			(*PM_PlaybackEventFull) ( int flags, int clientindex, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 );

    pmtrace_t		(*PM_PlayerTraceEx) (float *start, float *end, int traceFlags, int (*pfnIgnore)( physent_t *pe ) );
    int				(*PM_TestPlayerPositionEx) (float *pos, pmtrace_t *ptrace, int (*pfnIgnore)( physent_t *pe ) );
    struct pmtrace_s *(*PM_TraceLineEx)( float *start, float *end, int flags, int usehulll, int (*pfnIgnore)( physent_t *pe ) );
} playermove_t;

// MODINFO.h
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
    qboolean secure;
    MOD_GAMEPLAY_TYPE_E type;
    int num_edicts;
    qboolean clientcrccheck;
} modinfo_t;

// CONSISTENCY.h
#define MAX_CONSISTENCY_LIST 512
typedef struct consistency_s
{
    char *filename;
    int issound;
    int orig_index;
    int value;
    int check_type;
    float mins[3];
    float maxs[3];
} consistency_t;

// EVENT.h
typedef struct event_s {
    unsigned short index;
    const char *filename;
    int filesize;
    const char *pszScript;
} event_t;

// ZONE.H
typedef struct hunk_s {
    int sentinel;
    int size;
    char name[64];
} hunk_t;

typedef struct memblock_s
{
    int size;
    int tag;
    int id;
    struct memblock_t *next;
    struct memblock_t *prev;
    int pad;
} memblock_t;

typedef struct memzone_s
{
    int size;
    struct memblock_t blocklist;
    struct memblock_t *rover;
} memzone_t;

// APIProxy.h
typedef struct cmdalias_s
{
    struct cmdalias_s	*next;
    char	name[32];
    char	*value;
} cmdalias_t;

// DECAL.h
typedef struct decalname_s
{
    char name[16];
    unsigned char ucFlags;
} decalname_t;

typedef struct lumpinfo_s
{
    int filepos;
    int disksize;
    int size;
    char type;
    char compression;
    char pad1;
    char pad2;
    char name[16];
} lumpinfo_t;

typedef struct lumplist_s
{
    lumpinfo_t *lump;
    qboolean breplaced;
    lumplist_s *next;
} lumplist_t;
