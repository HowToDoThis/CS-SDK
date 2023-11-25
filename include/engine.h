// SERVER.h

#define MAX_DATAGRAM 8000
#define MAX_INFO_STRING 512

typedef struct client_frame_s {
	double senttime;
	float ping_time;
	clientdata_t clientdata;
	weapon_data_t weapondata[64];
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
	// NETCHAN INCORRECT
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


// SERVER_STATIC.h
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
	struct client_s *clients;
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

// EIFACE.h
#define MAX_LEVEL_CONNECTIONS	16		// These are encoded in the lower 16bits of ENTITYTABLE->flags

typedef struct KeyValueData_s {
	char		*szClassName;	// in: entity classname
	char		*szKeyName;		// in: name of key
	char		*szValue;		// in: value of key
	qboolean	fHandled;		// out: DLL sets to true if key-value pair was understood
} KeyValueData;

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
	LEVELLIST	levelList[ MAX_LEVEL_CONNECTIONS ];		// List of connections from this level

	// smooth transition
	int			fUseLandmark;
	char		szLandmarkName[20];// landmark we'll spawn near in next level
	vec3_t		vecLandmarkOffset;// for landmark transitions
	float		time;
	char		szCurrentMapName[32];	// To check global entities

} SAVERESTOREDATA;

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

typedef struct 
{
	// Initialize/shutdown the game (one-time call after loading of game .dll )
	void			(__cdecl*pfnGameInit)			( void );				
	int				(__cdecl*pfnSpawn)				( edict_t *pent );
	void			(__cdecl*pfnThink)				( edict_t *pent );
	void			(__cdecl*pfnUse)				( edict_t *pentUsed, edict_t *pentOther );
	void			(__cdecl*pfnTouch)				( edict_t *pentTouched, edict_t *pentOther );
	void			(__cdecl*pfnBlocked)			( edict_t *pentBlocked, edict_t *pentOther );
	void			(__cdecl*pfnKeyValue)			( edict_t *pentKeyvalue, KeyValueData *pkvd );
	void			(__cdecl*pfnSave)				( edict_t *pent, SAVERESTOREDATA *pSaveData );
	int 			(__cdecl*pfnRestore)			( edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity );
	void			(__cdecl*pfnSetAbsBox)			( edict_t *pent );

	void			(__cdecl*pfnSaveWriteFields)	( SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int );
	void			(*pfnSaveReadFields)	( SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int );

	void			(__cdecl*pfnSaveGlobalState)		( SAVERESTOREDATA * );
	void			(__cdecl*pfnRestoreGlobalState)	( SAVERESTOREDATA * );
	void			(__cdecl*pfnResetGlobalState)		( void );

	qboolean		(__cdecl*pfnClientConnect)		( edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[ 128 ] );
	
	void			(__cdecl*pfnClientDisconnect)	( edict_t *pEntity );
	void			(__cdecl*pfnClientKill)		( edict_t *pEntity );
    void            (__cdecl*pfnClientUnknown1)    ( edict_t* pEntity );
	void			(__cdecl*pfnClientPutInServer)	( edict_t *pEntity );
	void			(__cdecl*pfnClientCommand)		( edict_t *pEntity );
	void			(__cdecl*pfnClientUserInfoChanged)( edict_t *pEntity, char *infobuffer );

	void			(__cdecl*pfnServerActivate)	( edict_t *pEdictList, int edictCount, int clientMax );
	void			(__cdecl*pfnServerDeactivate)	( void );

	void			(__cdecl*pfnPlayerPreThink)	( edict_t *pEntity );
	void			(__cdecl*pfnPlayerPostThink)	( edict_t *pEntity );

	void			(__cdecl*pfnStartFrame)		( void );
	void			(__cdecl*pfnParmsNewLevel)		( void );
	void			(__cdecl*pfnParmsChangeLevel)	( void );

	 // Returns string describing current .dll.  E.g., TeamFotrress 2, Half-Life
	const char     *(__cdecl*pfnGetGameDescription)( void );     

	// Notify dll about a player customization.
	void            (__cdecl*pfnPlayerCustomization) ( edict_t *pEntity, customization_t *pCustom );  

	// Spectator funcs
	void			(__cdecl*pfnSpectatorConnect)		( edict_t *pEntity );
	void			(__cdecl*pfnSpectatorDisconnect)	( edict_t *pEntity );
	void			(__cdecl*pfnSpectatorThink)		( edict_t *pEntity );

	// Notify game .dll that engine is going to shut down.  Allows mod authors to set a breakpoint.
	void			(__cdecl*pfnSys_Error)			( const char *error_string );

	void			(__cdecl*pfnPM_Move) ( struct playermove_s *ppmove, qboolean server );
	void			(__cdecl*pfnPM_Init) ( struct playermove_s *ppmove );
	char			(__cdecl*pfnPM_FindTextureType)( char *name );
	void			(__cdecl*pfnSetupVisibility)( struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas );
	void			(__cdecl*pfnUpdateClientData) ( const struct edict_s *ent, int sendweapons, struct clientdata_s *cd );
	int				(__cdecl*pfnAddToFullPack)( struct entity_state_s *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, unsigned char *pSet );
	void			(__cdecl*pfnCreateBaseline) ( int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, vec3_t player_mins, vec3_t player_maxs );
	void			(__cdecl*pfnRegisterEncoders)	( void );
	int				(__cdecl*pfnGetWeaponData)		( struct edict_s *player, struct weapon_data_s *info );

	void			(__cdecl*pfnCmdStart)			( const edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed );
	void			(__cdecl*pfnCmdEnd)			( const edict_t *player );

	// Return 1 if the packet is valid.  Set response_buffer_size if you want to send a response packet.  Incoming, it holds the max
	//  size of the response_buffer, so you must zero it out if you choose not to respond.
	int				(__cdecl*pfnConnectionlessPacket )	( const struct netadr_s *net_from_, const char *args, char *response_buffer, int *response_buffer_size );

	// Enumerates player hulls.  Returns 0 if the hull number doesn't exist, 1 otherwise
	int				(__cdecl*pfnGetHullBounds)	( int hullnumber, float *mins, float *maxs );

	// Create baselines for certain "unplaced" items.
	void			(__cdecl*pfnCreateInstancedBaselines) ( void );

	// One of the pfnForceUnmodified files failed the consistency check for the specified player
	// Return 0 to allow the client to continue, 1 to force immediate disconnection ( with an optional disconnect message of up to 256 characters )
	int				(__cdecl*pfnInconsistentFile)( const struct edict_s *player, const char *filename, char *disconnect_message );

	// The game .dll should return 1 if lag compensation should be allowed ( could also just set
	//  the sv_unlag cvar.
	// Most games right now should return 0, until client-side weapon prediction code is written
	//  and tested for them.
	int				(__cdecl*pfnAllowLagCompensation)( void );
} DLL_FUNCTIONS;

typedef struct {
	// Called right before the object's memory is freed. 
	// Calls its destructor.
	void			(*pfnOnFreeEntPrivateData)(edict_t *pEnt);
	void			(*pfnGameShutdown)(void);
	int				(*pfnShouldCollide)( edict_t *pentTouched, edict_t *pentOther );
	void			(*pfnCvarValue)( const edict_t *pEnt, const char *value );
    void            (*pfnCvarValue2)( const edict_t *pEnt, int requestID, const char *cvarName, const char *value );
} NEW_DLL_FUNCTIONS;

// DELTAS.h
typedef void(*encoder_t)(struct delta_t *, const unsigned char *, const unsigned char *);

union delta_marked_mask_t {
	uint8 u8[8];
	uint32 u32[2];
	uint64 u64;
};

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

typedef struct delta_info_s
{
	delta_info_s *next;
	char *name;
	char *loadfile;
	delta_t *delta;
} delta_info_t;

typedef struct delta_encoder_s
{
	struct delta_encoder_t *next;
	char *name;
	encoder_t conditionalencode;
} delta_encoder_t;

// R_STUDIOINT.h
typedef struct sv_blending_interface_s {
	int	version;
	void	( *SV_StudioSetupBones )( struct model_s *pModel, float frame, int sequence, const vec3_t angles, const vec3_t origin, const byte *pcontroller, const byte *pblending, int iBone, const edict_t *pEdict );
} sv_blending_interface_t;

// INST_BASELINE.h
#define NUM_BASELINES 64
typedef struct extra_baselines_s {
	int number;
	int classname[NUM_BASELINES];
	entity_state_t baseline[NUM_BASELINES];
} extra_baselines_t;

// Server.h
typedef enum server_state_e {
	ss_dead = 0,
	ss_loading = 1,
	ss_active = 2,
} server_state_t;

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
	resource_t resourcelist[4140];
	int num_resources;
	consistency_t consistency_list[512];
	int num_consistency;
	const char *model_precache[2048];
	struct model_s *models[2048];
	unsigned char model_precache_flags[2048];
	struct event_s event_precache[512];
	const char *sound_precache[1324];
	short int sound_precache_hashedlookup[2647];
	qboolean sound_precache_hashedlookup_built;
	const char *generic_precache[2048];
	char generic_precache_names[2048][64];
	int num_generic_names;
	const char *lightstyles[1<<6];
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
	unsigned char signon_data[0x8000];
	sizebuf_t sigon_wpnlist;
	unsigned char sigon_wpnlist_data[0x8000];
} server_t;

// NET_WS.h
#define NET_MAX_MESSAGE 4037
// Max size of udp packet payload
#define MAX_UDP_PACKET	4010 // 9 bytes SPLITHEADER + 4000 payload?

// Create general message queues
#define NUM_MSG_QUEUES 40
#define MSG_QUEUE_SIZE 1536

typedef struct loopmsg_s {
	unsigned char data[NET_MAX_MESSAGE];
	int datalen;
} loopmsg_t;

#define MAX_LOOPBACK 4

typedef struct loopback_s {
	loopmsg_t msgs[MAX_LOOPBACK];
	int get;
	int send;
} loopback_t;

typedef struct packetlag_s {
	unsigned char *pPacketData;	// Raw stream data is stored.
	int nSize;
	netadr_t net_from_;
	float receivedTime;
	struct packetlag_s *pNext;
	struct packetlag_s *pPrev;
} packetlag_t;

//  NETADR_T Error? Required 44, only has 24
typedef struct net_messages_s {
	struct net_messages_s *next; // 4
	qboolean preallocated; // 4
	unsigned char *buffer; // 4
	netadr_t from;  // netadr_t size
	int buffersize; // 4
} net_messages_t;

// Split long packets. Anything over 1460 is failing on some routers.
typedef struct LONGPACKET_t {
	int currentSequence;
	int splitCount;
	int totalSize;
	// TODO: It should be NET_MAX_MESSAGE, but value differs
	char buffer[8250];	// This has to be big enough to hold the largest message
} LONGPACKET;

typedef struct SPLITPACKET_t {
	int netID;
	int sequenceNumber;
	unsigned char packetID;
} SPLITPACKET;

// CMD.H
typedef void(*xcommand_t)(void);
typedef struct cmd_function_s
{
	struct cmd_function_s *next;
	const char *name;
	xcommand_t function;
	int flags;
} cmd_function_t;

typedef enum cmd_source_s
{
	src_client = 0,		// came in over a net connection as a clc_stringcmd. host_client will be valid during this state.
	src_command = 1,	// from the command buffer.
} cmd_source_t;
