#define BIT(n) (1<<(n))
#define MAX_QPATH 64

#define MAX_MSGLEN 8186
#define NET_MAX_MESSAGE 8250

#define FRAGMENT_MAX_SIZE 1400
#define MAX_PATH 260
#define MAX_LATENT 32
#define MAX_DATAGRAM 8000
#define MAX_PHYSINFO_STRING 256
#define MAX_EVENT_QUEUE 64
#define	MAX_ENT_LEAFS 48
#define MAX_INFO_STRING 512
#define MAX_RESOURCE_LIST 4140
#define MAX_CONSISTENCY_LIST 512
#define MAX_MODELS 2048
#define MAX_EVENTS 510
#define MAX_SOUNDS 1324
#define MAX_GENERIC 2048
#define MAX_SOUNDS_HASHLOOKUP_SIZE 2647
#define MAX_LIGHTSTYLES 64

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

typedef unsigned int CRC32_t;

typedef struct { byte r, g, b; } color24;

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

// common.h
typedef struct sizebuf_s {
	const char *buffername;
	unsigned short flags;
	unsigned char *data;
	int maxsize;
	int cursize;
} sizebuf_t;

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
	float		takedamage;
	int			deadflag;
	vec3_t		view_ofs;	// eye position
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
	string_t	netname;
	string_t	message;
	float		dmg_take;
	float		dmg_save;
	float		dmg;
	float		dmgtime;
	string_t	noise;
	string_t	noise1;
	string_t	noise2;
	string_t	noise3;
	float		speed;
	float		air_finished;
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
	struct edict_t		*euser1;
	struct edict_t		*euser2;
	struct edict_t		*euser3;
	struct edict_t		*euser4;
} entvars_t;

typedef struct USERID_s {
	int idtype;
	uint64 m_SteamID;
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

// zone.h
typedef struct hunk_s {
	int sentinel;
	int size;
	char name[64];
} hunk_t;

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

	int unk1;
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

typedef struct packetlag_s {
	unsigned char *pPacketData;	// Raw stream data is stored.
	int nSize;
	netadr_t net_from_;
	float receivedTime;
	int unk5;
	int unk6;
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

// md5.h
typedef struct {
	unsigned int buf[4];
	unsigned int bits[2];
	unsigned char in[64];
} MD5Context_t;

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
	int                 cso_unk[6];
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
	char physinfo[MAX_INFO_STRING];
	qboolean m_bLoopback;
	uint32 m_VoiceStreams[2];
	double m_lastvoicetime;
	int m_sendrescount;
	qboolean m_bSentNewResponse;
} client_t;

typedef struct server_s {
	qboolean active;
	qboolean paused;
	qboolean loadgame;
	double time;
	double oldtime;
	int lastcheck;
	double lastchecktime;
	char name[260];
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