// basetypes.h
typedef int qboolean;
typedef unsigned char byte;

// mathlib.h
typedef float vec_t;
typedef vec_t vec3_t[3];
// crc.h
typedef unsigned int CRC32_t;
// cvar.h
typedef struct cvar_s {
    char*          name;
    char*          string;
    int               flags;
    float           value;
    struct cvar_s* next;
} cvar_t;
// sequence.h
typedef struct client_textmessage_s
{
    int        effect;
    byte    r1, g1, b1, a1;        // 2 colors for effects
    byte    r2, g2, b2, a2;
    float    x;
    float    y;
    float    fadein;
    float    fadeout;
    float    holdtime;
    float    fxtime;
    const char *pName;
    const char *pMessage;
} client_textmessage_t;

typedef struct sequenceCommandLine_ sequenceCommandLine_s;
struct sequenceCommandLine_
{
    int                        commandType;        // Specifies the type of command
    client_textmessage_t    clientMessage;        // Text HUD message struct
    char*                    speakerName;        // Targetname of speaking entity
    char*                    listenerName;        // Targetname of entity being spoken to
    char*                    soundFileName;        // Name of sound file to play
    char*                    sentenceName;        // Name of sentences.txt to play
    char*                    fireTargetNames;    // List of targetnames to fire
    char*                    killTargetNames;    // List of targetnames to remove
    float                    delay;                // Seconds 'till next command
    int                        repeatCount;        // If nonzero, reset execution pointer to top of block (N times, -1 = infinite)
    int                        textChannel;        // Display channel on which text message is sent
    int                        modifierBitField;    // Bit field to specify what clientmessage fields are valid
    sequenceCommandLine_s*    nextCommandLine;    // Next command (linked list)
};

typedef struct sequenceEntry_ sequenceEntry_s;
struct sequenceEntry_
{
    char*                    fileName;        // Name of sequence file without .SEQ extension
    char*                    entryName;        // Name of entry label in file
    sequenceCommandLine_s*    firstCommand;    // Linked list of commands in entry
    sequenceEntry_s*        nextEntry;        // Next loaded entry
    qboolean                isGlobal;        // Is entry retained over level transitions?
};

typedef struct sentenceEntry_ sentenceEntry_s;
struct sentenceEntry_
{
    char*                    data;            // sentence data (ie "We have hostiles" )
    sentenceEntry_s*        nextEntry;        // Next loaded entry
    qboolean                isGlobal;        // Is entry retained over level transitions?
    unsigned int            index;            // this entry's position in the file.
};

// eiface.h
enum ALERT_TYPE
{
    at_notice,
    at_console,        // same as at_notice, but forces a ConPrintf, not a message box
    at_aiconsole,    // same as at_console, but only shown if developer level is 2!
    at_warning,
    at_error,
    at_logged        // Server print to console (only in multiplayer games ).
};

// 4-22-98  JOHN: added for use in pfnClientPrintf
enum PRINT_TYPE
{
    print_console,
    print_center,
    print_chat,
};

// For integrity checking of content on clients
enum FORCE_TYPE
{
    force_exactfile,                    // File on client must exactly match server's file
    force_model_samebounds,                // For model files only, the geometry must fit in the same bbox
    force_model_specifybounds,            // For model files only, the geometry must fit in the specified bbox
    force_model_specifybounds_if_avail,    // For Steam model files only, the geometry must fit in the specified bbox (if the file is available)
};

// Returned by TraceLine
struct TraceResult
{
    int        fAllSolid;            // if true, plane is not valid
    int        fStartSolid;        // if true, the initial point was in a solid area
    int        fInOpen;
    int        fInWater;
    float    flFraction;            // time completed, 1.0 = didn't hit anything
    vec3_t    vecEndPos;            // final position
    float    flPlaneDist;
    vec3_t    vecPlaneNormal;        // surface normal at impact
    struct edict_t    *pHit;                // entity the surface is on
    int        iHitgroup;            // 0 == generic, non zero is specific body part
};

// Engine hands this to DLLs for functionality callbacks
typedef struct enginefuncs_s
{
    int             (*pfnPrecacheModel)            (const char* s);
    int             (*pfnPrecacheSound)            (const char* s);
    void            (*pfnSetModel)                (struct edict_t *e, const char *m);
    int             (*pfnModelIndex)            (const char *m);
    int             (*pfnModelFrames)            (int modelIndex);
    void            (*pfnSetSize)                (struct edict_t *e, const float *rgflMin, const float *rgflMax);
    void            (*pfnChangeLevel)            (const char* s1, const char* s2);
    void            (*pfnGetSpawnParms)            (struct edict_t *ent);
    void            (*pfnSaveSpawnParms)        (struct edict_t *ent);
    float           (*pfnVecToYaw)                (const float *rgflVector);
    void            (*pfnVecToAngles)            (const float *rgflVectorIn, float *rgflVectorOut);
    void            (*pfnMoveToOrigin)            (struct edict_t *ent, const float *pflGoal, float dist, int iMoveType);
    void            (*pfnChangeYaw)                (struct edict_t* ent);
    void            (*pfnChangePitch)            (struct edict_t* ent);
    struct edict_t* (*pfnFindEntityByString)    (struct edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue);
    int             (*pfnGetEntityIllum)        (struct edict_t* pEnt);
    struct edict_t* (*pfnFindEntityInSphere)    (struct edict_t *pEdictStartSearchAfter, const float *org, float rad);
    struct edict_t* (*pfnFindClientInPVS)        (struct edict_t *pEdict);
    struct edict_t* (*pfnEntitiesInPVS)            (struct edict_t *pplayer);
    void            (*pfnMakeVectors)            (const float *rgflVector);
    void            (*pfnAngleVectors)            (const float *rgflVector, float *forward, float *right, float *up);
    struct edict_t* (*pfnCreateEntity)            (void);
    void            (*pfnRemoveEntity)            (struct edict_t* e);
    struct edict_t* (*pfnCreateNamedEntity)        (int className);
    void            (*pfnMakeStatic)            (struct edict_t *ent);
    int             (*pfnEntIsOnFloor)            (struct edict_t *e);
    int             (*pfnDropToFloor)            (struct edict_t* e);
    int             (*pfnWalkMove)                (struct edict_t *ent, float yaw, float dist, int iMode);
    void            (*pfnSetOrigin)                (struct edict_t *e, const float *rgflOrigin);
    void            (*pfnEmitSound)                (struct edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch);
    void            (*pfnEmitAmbientSound)        (struct edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch);
    void            (*pfnTraceLine)                (const float *v1, const float *v2, int fNoMonsters, struct edict_t *pentToSkip, TraceResult *ptr);
    void            (*pfnTraceToss)                (struct edict_t* pent, struct edict_t* pentToIgnore, TraceResult *ptr);
    int             (*pfnTraceMonsterHull)        (struct edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, struct edict_t *pentToSkip, TraceResult *ptr);
    void            (*pfnTraceHull)                (const float *v1, const float *v2, int fNoMonsters, int hullNumber, struct edict_t *pentToSkip, TraceResult *ptr);
    void            (*pfnTraceModel)            (const float *v1, const float *v2, int hullNumber, struct edict_t *pent, TraceResult *ptr);
    const char *    (*pfnTraceTexture)            (struct edict_t *pTextureEntity, const float *v1, const float *v2);
    void            (*pfnTraceSphere)            (const float *v1, const float *v2, int fNoMonsters, float radius, struct edict_t *pentToSkip, TraceResult *ptr);
    void            (*pfnGetAimVector)            (struct edict_t* ent, float speed, float *rgflReturn);
    void            (*pfnServerCommand)            (const char* str);
    void            (*pfnServerExecute)            (void); // 41
    void            (*pfnClientCommand)            (struct edict_t* pEdict, const char* szFmt, ...);
    void            (*pfnParticleEffect)        (const float *org, const float *dir, float color, float count);
    void            (*pfnLightStyle)            (int style, const char* val);
    int             (*pfnDecalIndex)            (const char *name);
    int             (*pfnPointContents)            (const float *rgflVector); // 46
    void            (*pfnMessageBegin)            (int msg_dest, int msg_type, const float *pOrigin, struct edict_t *ed);
    void            (*pfnMessageEnd)            (void);
    void            (*WRITE_BYTE)                (int iValue);
    void            (*WRITE_CHAR)                (int iValue);
    void            (*WRITE_SHORT)            (int iValue);
    void            (*PF_WriteLong_I)                (int iValue);
    void            (*PF_WriteFloat_I)                (int iValue);
    void            (*PF_WriteAngle_I)            (float flValue);
    void            (*PF_WriteCoord_I)            (float flValue);
    void            (*PF_WriteString_I)            (const char *sz);
    void            (*PF_WriteEntity_I)            (int iValue);
    void            (*pfnCVarRegister)            (cvar_t *pCvar);
    float           (*pfnCVarGetFloat)            (const char *szVarName);
    const char*     (*pfnCVarGetString)            (const char *szVarName);
    void            (*pfnCVarSetFloat)            (const char *szVarName, float flValue);
    void            (*pfnCVarSetString)            (const char *szVarName, const char *szValue);
    void            (*pfnAlertMessage)            (ALERT_TYPE atype, const char *szFmt, ...);
    void            (*pfnEngineFprintf)            (void *pfile, const char *szFmt, ...);
    void*           (*pfnPvAllocEntPrivateData)    (struct edict_t *pEdict, int cb);
    void*           (*pfnPvEntPrivateData)        (struct edict_t *pEdict);
    void            (*pfnFreeEntPrivateData)    (struct edict_t *pEdict);
    const char*     (*pfnSzFromIndex)            (int iString);
    int             (*pfnAllocString)            (const char *szValue);
    struct entvars_s* (*pfnGetVarsOfEnt)            (struct edict_t *pEdict);
    struct edict_t*   (*pfnPEntityOfEntOffset)    (int iEntOffset);
    int             (*pfnEntOffsetOfPEntity)    (const struct edict_t *pEdict);
    int             (*pfnIndexOfEdict)            (const struct edict_t *pEdict);
    struct edict_t*    (*pfnPEntityOfEntIndex)        (int iEntIndex);
    struct edict_t*    (*pfnFindEntityByVars)        (struct entvars_s* pvars);
    void*        (*pfnGetModelPtr)            (struct edict_t* pEdict);
    int            (*pfnRegUserMsg)            (const char *pszName, int iSize);
    void        (*pfnAnimationAutomove)        (const struct edict_t* pEdict, float flTime);
    void        (*pfnGetBonePosition)        (const struct edict_t* pEdict, int iBone, float *rgflOrigin, float *rgflAngles);
    int         (*pfnFunctionFromName)        (const char *pName);
    const char *(*pfnNameForFunction)        (int function);
    void        (*pfnClientPrintf)            (struct edict_t* pEdict, PRINT_TYPE ptype, const char *szMsg); // JOHN: engine callbacks so game DLL can print messages to individual clients
    void        (*pfnServerPrint)            (const char *szMsg);
    const char *(*pfnCmd_Args)                (void);        // these 3 added
    const char *(*pfnCmd_Argv)                (int argc);    // so game DLL can easily
    int            (*pfnCmd_Argc)                (void);        // access client 'cmd' strings
    void        (*pfnGetAttachment)            (const struct edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles);
    void        (*pfnCRC32_Init)            (CRC32_t *pulCRC);
    void        (*pfnCRC32_ProcessBuffer)   (CRC32_t *pulCRC, void *p, int len);
    void        (*pfnCRC32_Processchar)     (CRC32_t *pulCRC, unsigned char ch);
    CRC32_t        (*pfnCRC32_Final)            (CRC32_t pulCRC);
    int            (*pfnRandomLong)            (int  lLow,  int  lHigh);
    float        (*pfnRandomFloat)            (float flLow, float flHigh);
    void        (*pfnSetView)                (const struct edict_t *pClient, const struct edict_t *pViewent);
    float        (*pfnTime)                    (void);
    void        (*pfnCrosshairAngle)        (const struct edict_t *pClient, float pitch, float yaw);
    char *      (*pfnLoadFileForMe)         (const char *filename, int *pLength);
    void        (*pfnFreeFile)              (void *buffer);
    void        (*pfnEndSection)            (const char *pszSectionName); // trigger_endsection
    int         (*pfnCompareFileTime)       (char *filename1, char *filename2, int *iCompare); // 100
    void        (*pfnGetGameDir)            (char *szGetGameDir);
    void        (*pfnCvar_RegisterVariable) (cvar_t *variable); // 102
    void        (*PF_FadeVolume)      (const struct edict_t *pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds);
    void        (*PF_SetClientMaxspeed)     (struct edict_t *pEdict, float fNewMaxspeed);
    struct edict_t *    (*PF_CreateFakeClient)  (const char *netname);
    struct edict_t *    (*CSO_CreateFakeClient) (const char *netname);
    void        (*pfnRunPlayerMove)            (struct edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, char impulse, char msec);
    int            (*pfnNumberOfEntities)        (void);
    char*        (*pfnGetInfoKeyBuffer)        (struct edict_t *e);    // passing in NULL gets the serverinfo
    char*        (*pfnInfoKeyValue)            (char *infobuffer, const char *key);
    void        (*pfnSetKeyValue)            (char *infobuffer, const char *key, const char *value);
    void        (*pfnSetClientKeyValue)        (int clientIndex, char *infobuffer, const char *key, const char *value);
    int            (*pfnIsMapValid)            (const char *filename);
    void        (*pfnStaticDecal)            (const float *origin, int decalIndex, int entityIndex, int modelIndex);
    int            (*PF_precache_generic_I)        (const char* s);
    int            (*PF_GetPlayerUserId)        (struct edict_t *e); // returns the server assigned userid for this player.  useful for logging frags, etc.  returns -1 if the edict couldn't be found in the list of clients
    void        (*PF_BuildSoundMsg_I)            (struct edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, struct edict_t *ed);
    int            (*IS_DEDICATED_SERVER)        (void); // is this a dedicated server? 118
    cvar_t        *(*pfnCVarGetPointer)        (const char *szVarName);
    unsigned int (*pfnGetPlayerWONId)        (struct edict_t *e); // returns the server assigned WONid for this player.  useful for logging frags, etc.  returns -1 if the edict couldn't be found in the list of clients
    void        (*pfnInfo_RemoveKey)        (char *s, const char *key);
    const char *(*pfnGetPhysicsKeyValue)    (const struct edict_t *pClient, const char *key);
    void        (*pfnSetPhysicsKeyValue)    (const struct edict_t *pClient, const char *key, const char *value);
    const char *(*pfnGetPhysicsInfoString)    (const struct edict_t *pClient);
    unsigned short (*pfnPrecacheEvent)        (int type, const char*psz);
    void        (*pfnPlaybackEvent)            (int flags, const struct edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
    unsigned char *(*pfnSetFatPVS)            (float *org);
    unsigned char *(*pfnSetFatPAS)            (float *org);
    int            (*pfnCheckVisibility )        (struct edict_t *entity, unsigned char *pset);
    void        (*pfnDeltaSetField)            (struct delta_s *pFields, const char *fieldname);
    void        (*pfnDeltaUnsetField)        (struct delta_s *pFields, const char *fieldname);
    void        (*pfnDeltaAddEncoder)        (const char *name, void (*conditionalencode)(struct delta_s *pFields, const unsigned char *from, const unsigned char *to ));
    int            (*pfnGetCurrentPlayer)        (void);
    int            (*pfnCanSkipPlayer)            (const struct edict_t *player);
    int            (*pfnDeltaFindField)        (struct delta_s *pFields, const char *fieldname);
    void        (*pfnDeltaSetFieldByIndex)    (struct delta_s *pFields, int fieldNumber);
    void        (*pfnDeltaUnsetFieldByIndex)(struct delta_s *pFields, int fieldNumber);
    void        (*pfnSetGroupMask)            (int mask, int op);
    int            (*pfnCreateInstancedBaseline) (int classname, struct entity_state_s *baseline);
    void        (*pfnCvar_DirectSet)        (struct cvar_s *var, const char *value); // 140
    void        (*pfnForceUnmodified)        (FORCE_TYPE type, float *mins, float *maxs, const char *filename);
    void        (*pfnGetPlayerStats)        (const struct edict_t *pClient, int *ping, int *packet_loss);
    void        (*pfnAddServerCommand)        (const char *cmd_name, void (*function) (void));
    qboolean    (*pfnVoice_GetClientListening)(int iReceiver, int iSender);
    qboolean    (*pfnVoice_SetClientListening)(int iReceiver, int iSender, qboolean bListen);
    const char *(*pfnGetPlayerAuthId)        (struct edict_t *e);
    sequenceEntry_s*    (*pfnSequenceGet)                (const char* fileName, const char* entryName);
    sentenceEntry_s*    (*pfnSequencePickSentence)        (const char* groupName, int pickMethod, int *picked);
    int            (*pfnGetFileSize)                        (const char *filename);
    unsigned int (*pfnGetApproxWavePlayLen)                (const char *filepath);
    int            (*pfnIsCareerMatch)                        (void);
    int            (*pfnGetLocalizedStringLength)            (const char *label);
    void        (*pfnRegisterTutorMessageShown)            (int mid);
    int            (*pfnGetTimesTutorMessageShown)            (int mid);
    void        (*pfnProcessTutorMessageDecayBuffer)    (int *buffer, int bufferLength);
    void        (*pfnConstructTutorMessageDecayBuffer)    (int *buffer, int bufferLength);
    void        (*pfnResetTutorMessageDecayData)        (void);
    void (*pfnQueryClientCvarValue) (const struct edict_t *player, const char *cvarName);
    void (*pfnQueryClientCvarValue2) (const struct edict_t *player, const char *cvarName, int requestID);
    // CSO
    void* (*GetClassMenuManager)();
    void* (*GetBuyMenuManager)();
    void* (*GetOption)();
    void* (*GetGamePlayerManager)();
    void* (*GetCSOFacade)();
    void* (*GetGameRoomManager)();
    void* (*GetSharedDataManager)();
    void* (*GetInventory)();
    void* (*GetItemCSV)();
    void* (*GetGiftBox)();
    void* (*GetStrGen)();
    void* (*GetServerChannelCategory)();
    void* (*IsServerChannelCategory287)();
    void* (*GetWeaponManager)();
    void* (*GetFromUnkFunc)();
    void* (*UnkFunc)();
    void* (*GetLocalClientState)();
    void* (*SetLocalClientState)();
    void* (*IsUnkFunc5or4)();
    void* (*SendHost2)();
    void* (*SomethingPlayerRestore)();
    void* (*GetUserID)();
    void* (*CSOFunction1)();
    void* (*SendHost3)();
    void* (*SendHost16)();
    void* (*SendHost5)();
    void* (*SendHost4)();
    void* (*SendHost7)();
    void* (*SendHost8)();
    void* (*SendHost9)();
    void* (*SendHost10)();
    void* (*SendHost12)();
    void* (*SendHost17)();
    void* (*NUM_FOR_EDICT)();
    void* (*PrecacheModelDynamic)();
    void* (*SendHost24)();
    void* (*MonthlyWpnMgr)();
} enginefuncs_t;

typedef struct {
	void			(*pfnGameInit)			(void);
	int				(*pfnSpawn)				(struct edict_t *pent);
	void			(*pfnThink)				(struct edict_t *pent);
	void			(*pfnUse)				(struct edict_t *pentUsed, struct edict_t *pentOther);
	void			(*pfnTouch)				(struct edict_t *pentTouched, struct edict_t *pentOther);
	void			(*pfnBlocked)			(struct edict_t *pentBlocked, struct edict_t *pentOther);
	void			(*pfnKeyValue)			(struct edict_t *pentKeyvalue, struct KeyValueData *pkvd);
	void			(*pfnSave)				(struct edict_t *pent, struct SAVERESTOREDATA *pSaveData);
	int 			(*pfnRestore)			(struct edict_t *pent, struct SAVERESTOREDATA *pSaveData, int globalEntity);
	void			(*pfnSetAbsBox)			(struct edict_t *pent);
	void			(*pfnSaveWriteFields)	(struct SAVERESTOREDATA *, const char *, void *, struct TYPEDESCRIPTION *, int);
	void			(*pfnSaveReadFields)	(struct SAVERESTOREDATA *, const char *, void *, struct TYPEDESCRIPTION *, int);
	void			(*pfnSaveGlobalState)		(struct SAVERESTOREDATA *);
	void			(*pfnRestoreGlobalState)	(struct SAVERESTOREDATA *);
	void			(*pfnResetGlobalState)		(void);
	qboolean		(*pfnClientConnect)		(struct edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128]);	
	void			(*pfnClientDisconnect)	(struct edict_t *pEntity);
	void			(*pfnClientKill)		(struct edict_t *pEntity);
	void			(*pfnClientPutInServer)	(struct edict_t *pEntity);
	void			(*pfnClientCommand)		(struct edict_t *pEntity);
	void			(*pfnClientUserInfoChanged)(struct edict_t *pEntity, char *infobuffer);
	void			(*pfnServerActivate)	(struct edict_t *pEdictList, int edictCount, int clientMax);
	void			(*pfnServerDeactivate)	(void);
	void			(*pfnPlayerPreThink)	(struct edict_t *pEntity);
	void			(*pfnPlayerPostThink)	(struct edict_t *pEntity);
	void			(*pfnStartFrame)		(void);
	void			(*pfnParmsNewLevel)		(void);
    void            (*pfnUnknownLevel)      (void);
	void			(*pfnParmsChangeLevel)	(void);
	const char     *(*pfnGetGameDescription)(void);
	void            (*pfnPlayerCustomization) (struct edict_t *pEntity, struct customization_t *pCustom);  
	void			(*pfnSpectatorConnect)		(struct edict_t *pEntity);
	void			(*pfnSpectatorDisconnect)	(struct edict_t *pEntity);
	void			(*pfnSpectatorThink)		(struct edict_t *pEntity);
	void			(*pfnSys_Error)			(const char *error_string);
	void			(*pfnPM_Move) (struct playermove_s *ppmove, qboolean server);
	void			(*pfnPM_Init) (struct playermove_s *ppmove);
	char			(*pfnPM_FindTextureType)(char *name);
	void			(*pfnSetupVisibility)(struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas);
	void			(*pfnUpdateClientData) (const struct edict_s *ent, int sendweapons, struct clientdata_s *cd);
	int				(*pfnAddToFullPack)(struct entity_state_s *state, int e, struct edict_t *ent, struct edict_t *host, int hostflags, int player, unsigned char *pSet);
	void			(*pfnCreateBaseline) (int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, vec3_t player_mins, vec3_t player_maxs);
	void			(*pfnRegisterEncoders)	(void);
	int				(*pfnGetWeaponData)		(struct edict_s *player, struct weapon_data_s *info);
	void			(*pfnCmdStart)			(const struct edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed);
	void			(*pfnCmdEnd)			(const struct edict_t *player);
	int				(*pfnConnectionlessPacket )	(const struct netadr_s *net_from_, const char *args, char *response_buffer, int *response_buffer_size);
	int				(*pfnGetHullBounds)	(int hullnumber, float *mins, float *maxs);
	void			(*pfnCreateInstancedBaselines) (void);
	int				(*pfnInconsistentFile)(const struct edict_s *player, const char *filename, char *disconnect_message);
	int				(*pfnAllowLagCompensation)(void);
    // CSO
    int (__cdecl* CSOFunc01)();
    int (__cdecl* CSOFunc02)();
    int (__cdecl* CSOFunc03)(int, int, int, int, int, int, int);
    int (__cdecl* CSOFunc04)();
    int (__cdecl* CSOFunc05)();
    int (__cdecl* CSOFunc06)();
    int (__cdecl* CSOFunc07)();
    int (__cdecl* CSOFunc08)();
    int (__cdecl* CSOFunc09)();
    int (__cdecl* CSOFunc10)();
    int (__cdecl* CSOFunc11)();
    int (__cdecl* CSOFunc12)();
    void (__cdecl* CSOFunc13)(int userID);
    int (__cdecl* CSOFunc14)();
    int (__cdecl* CSOFunc15)();
    int (__cdecl* CSOFunc16)();
    int (__cdecl* CSOFunc17)();
} DLL_FUNCTIONS;

typedef struct {
	void (__cdecl*pfnOnFreeEntPrivateData)(struct edict_t *pEnt);
	void (__cdecl*pfnGameShutdown)(void);
	int  (__cdecl*pfnShouldCollide)(struct edict_t *pentTouched, struct edict_t *pentOther);
	void (__cdecl*pfnCvarValue)(const struct edict_t *pEnt, const char *value);
    void (__cdecl*pfnCvarValue2)(const struct edict_t *pEnt, int requestID, const char *cvarName, const char *value);
} NEW_DLL_FUNCTIONS;
typedef int(__cdecl* NEW_DLL_FUNCTIONS_FN)(NEW_DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion);

typedef int(__cdecl* APIFUNCTION )(DLL_FUNCTIONS *pFunctionTable, int interfaceVersion);
typedef int(__cdecl* APIFUNCTION2)(DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion);

typedef int(*pfnUserMsgHook)(const char *pszName, int iSize, void *pbuf);

// Reverse engineered by Jusic (06.12.18)
// Updated by Neko (21.10.2022)
typedef int SptiteHandle_t;	// handle to a graphic

typedef struct cl_enginefuncs_s
{
    SptiteHandle_t              (*pfnSPR_Load)           (const char* szPicName);
    int                         (*pfnSPR_Frames)         (SptiteHandle_t hPic);
    int                         (*pfnSPR_Height)         (SptiteHandle_t hPic, int frame);
    int                         (*pfnSPR_Width)          (SptiteHandle_t hPic, int frame);
    void                        (*pfnSPR_Set)            (SptiteHandle_t hPic, int r, int g, int b);
    void                        (*pfnSPR_Draw)           (int frame, int x, int y, const struct wrect_t* prc);
    void                        (*pfnSPR_DrawHoles)      (int frame, int x, int y, const struct wrect_t* prc);
    void                        (*pfnSPR_DrawAdditive)   (int frame, int x, int y, const struct wrect_t* prc);
    void                        (*pfnSPR_EnableScissor)  (int x, int y, int width, int height);
    void                        (*pfnSPR_DisableScissor) (void);
    struct client_sprite_t*     (*pfnSPR_GetList)        (char* psz, int* piCount);
    void                        (*pfnFillRGBA)            (int x, int y, int width, int height, int r, int g, int b, int a);
    int                         (*pfnGetScreenInfo)       (struct SCREENINFO* pscrinfo);
    void                        (*pfnSetCrosshair)        (SptiteHandle_t hspr, struct wrect_t rc, int r, int g, int b);
    struct cvar_s*              (*pfnRegisterVariable)    (char* szName, char* szValue, int flags);
    float                       (*pfnGetCvarFloat)        (char* szName);
    char*                       (*pfnGetCvarString)       (char* szName);
    int                         (*pfnAddCommand)          (char* cmd_name, void (*function)(void));
    int                         (*pfnHookUserMsg)         (char* szMsgName, pfnUserMsgHook pfn);
    int                         (*pfnServerCmd)           (char* szCmdString);
    int                         (*pfnClientCmd)           (char* szCmdString);
    void                        (*pfnGetPlayerInfo)       (int ent_num, struct hud_player_info_t* pinfo);
    void                        (*pfnPlaySoundByName)     (char* szSound, float volume);
    void                        (*pfnPlaySoundByIndex)    (int iSound, float volume);
    void                        (*pfnAngleVectors)        (const float* vecAngles, float* forward, float* right, float* up);
    struct client_textmessage_t* (*pfnTextMessageGet)      (const char* pName);
    int                         (*pfnDrawCharacter)       (int x, int y, int number, int r, int g, int b);
    int                         (*pfnDrawConsoleString)   (int x, int y, char* string);
    void                        (*pfnDrawSetTextColor)    (float r, float g, float b);
    void                        (*pfnDrawConsoleStringLen)(const char* string, int* length, int* height);
    void                        (*pfnConsolePrint)        (const char* string);
    void                        (*pfnCenterPrint)         (const char* string);
    int                         (*GetWindowCenterX)       (void);
    int                         (*GetWindowCenterY)       (void);
    void                        (*GetViewAngles)          (float*);
    void                        (*SetViewAngles)          (float*);
    int                         (*GetMaxClients)          (void);
    void                        (*Cvar_SetValue)          (char* cvar, float value);
    int                         (*Cmd_Argc)               (void);
    char*                       (*Cmd_Argv)               (int arg);
    void                        (*Con_Printf)             (char* fmt, ...);
    void                        (*Con_DPrintf)            (char* fmt, ...);
    void                        (*Con_NPrintf)            (int pos, char* fmt, ...);
    void                        (*Con_NXPrintf)           (struct con_nprint_s* info, char* fmt, ...);
    const char*                 (*PhysInfo_ValueForKey)   (const char* key);
    const char*                 (*ServerInfo_ValueForKey) (const char* key);
    float                       (*GetClientMaxspeed)      (void);
    int                         (__cdecl*CheckParm)       (char* parm, char** ppnext);
    void                        (*Key_Event)              (int key, int down);
    void                        (*GetMousePosition)       (int* mx, int* my);
    int                         (*IsNoClipping)           (void);
    struct cl_entity_s*         (*GetLocalPlayer)         (void);
    struct cl_entity_s*         (*GetViewModel)           (void);
    struct cl_entity_s*         (*GetEntityByIndex)       (int idx);
    float                       (*GetClientTime)          (void);
    void                        (*V_CalcShake)            (void);
    void                        (*V_ApplyShake)           (float* origin, float* angles, float factor);
    int                         (*PM_PointContents)       (float* point, int* truecontents);
    int                         (*PM_WaterEntity)         (float* p);
    struct pmtrace_s*           (*PM_TraceLine)           (float* start, float* end, int flags, int usehull, int ignore_pe);
    struct model_s*             (*CL_LoadModel)           (const char* modelname, int* index);
    int                         (*CL_CreateVisibleEntity) (int type, struct cl_entity_s* ent);
    const struct model_s*       (*GetSpritePointer)       (SptiteHandle_t hSprite);
    void                        (*pfnPlaySoundByNameAtLocation) (char* szSound, float volume, float* origin);
    unsigned short              (*pfnPrecacheEvent)       (int type, const char* psz);
    void                        (*pfnPlaybackEvent)       (int flags, const struct edict_s* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
    void                        (*pfnWeaponAnim)          (int iAnim, int body);
    float                       (*pfnRandomFloat)         (float flLow, float flHigh);
    long                        (*pfnRandomLong)          (long lLow, long lHigh);
    void                        (*pfnHookEvent)           (char* name, void (*pfnEvent)(struct event_args_s* args));
    int                         (*Con_IsVisible)          ();
    const char*                 (*pfnGetGameDirectory)    (void);
    struct cvar_s*              (*pfnGetCvarPointer)      (const char* szName);
    const char*                 (*Key_LookupBinding)      (const char* pBinding);
    const char*                 (*pfnGetLevelName)        (void);
    void                        (*pfnGetScreenFade)       (struct screenfade_s* fade);
    void                        (*pfnSetScreenFade)       (struct screenfade_s* fade);
    void*                       (*VGui_GetPanel)          ();
    void                        (*VGui_ViewportPaintBackground) (int extents[4]);
    byte*                       (*COM_LoadFile)           (char* path, int usehunk, int* pLength);
    char*                       (*COM_ParseFile)          (char* data, char* token);
    void                        (*COM_FreeFile)           (void* buffer);
    struct triangleapi_s* pTriAPI;
    struct efx_api_s* pEfxAPI;
    struct event_api_s* pEventAPI;
    struct demo_api_s* pDemoAPI;
    struct net_api_s* pNetAPI;
    struct IVoiceTweak_s* pVoiceTweak;
    int                         (*IsSpectateOnly)         (void);
    struct model_s* (*LoadMapSprite)          (const char* filename);
    void                        (*COM_AddAppDirectoryToSearchPath) (const char* pszBaseDir, const char* appName);
    int                         (__cdecl*COM_ExpandFilename)              (const char* fileName, char* nameOutBuffer, int nameOutBufferSize);
    const char* (*PlayerInfo_ValueForKey)          (int playerNum, const char* key);
    void                        (*PlayerInfo_SetValueForKey)       (const char* key, const char* value);
    qboolean(*GetPlayerUniqueID)      (int iPlayer, char playerID[16]);
    int                         (*GetTrackerIDForPlayer)  (int playerSlot);
    int                         (*GetPlayerForTrackerID)  (int trackerID);
    int                         (*pfnServerCmdUnreliable) (char* szCmdString);
    void                        (*pfnGetMousePos)         (struct tagPOINT* ppt);
    void                        (*pfnSetMousePos)         (int x, int y);
    void                        (*pfnSetMouseEnable)      (qboolean fEnable);
    struct cvar_s* (*pfnGetCvarList)         (void);
    struct cmd_s* (*pfnGetCmdList)          (void);
    char* (*pfnGetCvarName)         (struct cvar_s* cvar);
    char* (*pfnGetCmdName)          (struct cmd_s* cmd);
    float                       (*pfnGetServerTime)       (void);
    float                       (*pfnGetGravity)          (void);
    const struct model_s* (*pfnPrecacheSprite)      (SptiteHandle_t spr);
    void                        (*OverrideLightmap)       (int override);
    void                        (*SetLightmapColor)       (float r, float g, float b);
    void                        (*SetLightmapDarkness)    (float dark);
    int                         (*pfnGetSequenceByName)   (int flags, const char* seq);
    void                        (*pfnSPR_DrawGeneric)     (int frame, int x, int y, const struct wrect_t* prc, int blendsrc, int blenddst, int unknown1, int unknown2);
    void                        (*pfnLoadSentence)        (void);
    int                         (*pfnDrawLocalizedHudString)    (int x, int y, const char* str, int r, int g, int b);
    int                         (*pfnDrawLocalizedConsoleString)(int x, int y, const char* str);
    const char* (*LocalPlayerInfo_ValueForKey)  (const char* key);
    void                        (*pfnDrawText_0)                (int x, int y, const wchar_t* text, unsigned long font);
    int                         (*pfnDrawUnicodeCharacter)      (int x, int y, short number, int r, int g, int b, unsigned long hfont);
    int                         (*pfnCheckSoundFile)            (const char* path);
    void* (*GetCareerGameInterface)       (void);
    void                        (*pfnCvar_Set)                  (const char* cvar, const char* value);
    int                         (*IsSinglePlayer)               (void);
    void                        (*pfnPlaySound)                 (const char* sound, float vol, float pitch);
    void                        (*pfnPlayMp3)                   (const char* mp3, int flags);
    float                       (*Sys_FloatTime)                (void);
    void                        (*pfnSetArray)                  (int* array, int size);
    void                        (*pfnSetClearArray)             (int* array, int size);
    void                        (*pfnClearArray)                (void);
    void                        (*pfnPlaySound2)                (const char* sound, float vol, float pitch);
    void                        (*pfnTintRGBA)                  (int x, int y, int width, int height, int r, int g, int b, int a);
    // CSO trash
    void  (*Unknown2)                  ();
    const char* (*GetCurrentAlias)     ();
    void  (*SPR_DrawHolesScaled)       (int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    void  (*SPR_Replace)               (int a2, int a3);
    void  (*SPR_DrawAdditiveScaled)    (int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    void  (*LeaveGameRoom)             (int a1, int a2);
    void  (*CheckForBadWord)           (int a1); // ????
    int   (*CheckServerChannelMgr)     (); // result != 0??
    bool  (*CheckServerChannelMgr2)    (); // check 2 8 7 type?
    void  (*PlaySound3)                (const char* sound, float vol, float pitch);
    void* (*GetInventory)              ();
    void* (*GetIGClassMenuMgr)         ();
    void* (*GetIGBuyMenuMgr)           ();
    class CChattingManager* (*GetChatManager)      ();
    class GamePlayerManager* (*GetGamePlayerManager)();
    class GameOptionManager* (*GetGameOptionManager)();
    void* (*GetBuyMenuManager)         ();
    void* (*LoadItemCSV)               ();
    void* (*GetCFavoriteWeaponsManager)();
    void* (*GetMenuQueueMgr)           ();
    void* (*GetCrossHairMgr)           ();
    void* (*GetSharedDataMgr)          ();
    void* (*GetGameRoomManager)        ();
    void* (*GetClanMgr)                ();
    void* (*GetItemShop)               ();
    void  (*Unknown25)                 (unsigned char* a1);
    void* (*LoadLocationCSV)           ();
    void* (*GetRankingManager)         ();
    void  (*GetStrGen)                 ();
    void* (*GetVideoMode)              ();
    void* (*GetUserFacade)             ();
    void* (*GetCSOFacade)              ();
    void  (*IsKeyBind)                 (char*); // Something Key
    void* (*GetClanStorage)            ();
    void  (*Pbuf_AddText)              (const char* text);
    void* (*GetGameConsoleVariables)   ();
    cvar_s* (*RegisterVariable4GameConsole)    (char* szName, char* szValue, int flags);
    void  (*MainGameOptionManager)     ();
    void* (*GiftBox)                   ();
    void* (*Unknown38)                 ();
    void  (*SomethingScreen)           (int a1, int a2, int a3, int a4, int a5);
    void* (*GetLocalClientState)       ();
    void* (*GetCBanManager)            ();
    void* (*GetCZBEnhanceManager)      ();
    void* (*GetCUserSurveyManager)     ();
    void* (*GetCQuestManager)          ();
    void* (*GetCUMsgManager)           ();
    void* (*GetCMiniGameManager)       ();
    void* (*CEventMgr)                 ();
    void* (*WeaponMgr)                 ();
    int   (*Unknown52)                 (); // return 0
    void* (*CFriendManager)            ();
    void* (*CComradeManager)           ();
    void* (*C2ndPassword)              ();
    void  (*Unknown53)                 (); // Rendering Something
    void* (*ClanMatchMgr)              ();
    void  (*Unknown54)                 (); // return 0
    int   (*CMileageBingoMgr)          ();
    void* (*Unknown55)                 (); // return ptr(unknown)
    int   (*SetUnknown56)              (int size, int offset, int a3, int a4, int a5); // size cannot over 1024
    int   (*GetUnknown56)              (int size, int offset, int* a3, int* a4, int* a5); // size cannot over 1024
    void* (*CSOCoreSDM)                ();
    int   (*Unknown58)                 (); // return 0
    void* (*CMonthlyWeaponManager)     ();
    bool  (*Unknown59)                 (void* ptr); // a1[791] == 3 && a1[844]
} cl_enginefunc_t;

// APIProxy.h
typedef int (*INITIALIZE_FUNC)	( struct cl_enginefuncs_s*, int );
typedef void (*HUD_INIT_FUNC)		( void );
typedef int (*HUD_VIDINIT_FUNC)	( void );
typedef int (*HUD_REDRAW_FUNC)	( float, int );
typedef int (*HUD_UPDATECLIENTDATA_FUNC) ( struct client_data_s*, float );
typedef void (*HUD_RESET_FUNC)    ( void );
typedef void (*HUD_CLIENTMOVE_FUNC)( struct playermove_s *ppmove, qboolean server );
typedef void (*HUD_CLIENTMOVEINIT_FUNC)( struct playermove_s *ppmove );
typedef char (*HUD_TEXTURETYPE_FUNC)( char *name );
typedef void (*HUD_IN_ACTIVATEMOUSE_FUNC) ( void );
typedef void (*HUD_IN_DEACTIVATEMOUSE_FUNC)		( void );
typedef void (*HUD_IN_MOUSEEVENT_FUNC)		( int mstate );
typedef void (*HUD_IN_CLEARSTATES_FUNC)		( void );
typedef void (*HUD_IN_ACCUMULATE_FUNC ) ( void );
typedef void (*HUD_CL_CREATEMOVE_FUNC)		( float frametime, struct usercmd_s *cmd, int active );
typedef int (*HUD_CL_ISTHIRDPERSON_FUNC) ( void );
typedef void (*HUD_CL_GETCAMERAOFFSETS_FUNC )( float *ofs );
typedef struct kbutton_s * (*HUD_KB_FIND_FUNC) ( const char *name );
typedef void ( *HUD_CAMTHINK_FUNC )( void );
typedef void ( *HUD_CALCREF_FUNC ) ( struct ref_params_s *pparams );
typedef int	 ( *HUD_ADDENTITY_FUNC ) ( int type, struct cl_entity_s *ent, const char *modelname );
typedef void ( *HUD_CREATEENTITIES_FUNC ) ( void );
typedef void ( *HUD_DRAWNORMALTRIS_FUNC ) ( void );
typedef void ( *HUD_DRAWTRANSTRIS_FUNC ) ( void );
typedef void ( *HUD_STUDIOEVENT_FUNC ) ( const struct mstudioevent_s *event, const struct cl_entity_s *entity );
typedef void ( *HUD_POSTRUNCMD_FUNC ) ( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed );
typedef void ( *HUD_SHUTDOWN_FUNC ) ( void );
typedef void ( *HUD_TXFERLOCALOVERRIDES_FUNC )( struct entity_state_s *state, const struct clientdata_s *client );
typedef void ( *HUD_PROCESSPLAYERSTATE_FUNC )( struct entity_state_s *dst, const struct entity_state_s *src );
typedef void ( *HUD_TXFERPREDICTIONDATA_FUNC ) ( struct entity_state_s *ps, const struct entity_state_s *pps, struct clientdata_s *pcd, const struct clientdata_s *ppcd, struct weapon_data_s *wd, const struct weapon_data_s *pwd );
typedef void ( *HUD_DEMOREAD_FUNC ) ( int size, unsigned char *buffer );
typedef int ( *HUD_CONNECTIONLESS_FUNC )( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
typedef	int	( *HUD_GETHULLBOUNDS_FUNC ) ( int hullnumber, float *mins, float *maxs );
typedef void (*HUD_FRAME_FUNC)		( double );
typedef int (*HUD_KEY_EVENT_FUNC ) ( int eventcode, int keynum, const char *pszCurrentBinding );
typedef void (*HUD_TEMPENTUPDATE_FUNC) ( double frametime, double client_time, double cl_gravity, struct tempent_s **ppTempEntFree, struct tempent_s **ppTempEntActive, 	int ( *Callback_AddVisibleEntity )( struct cl_entity_s *pEntity ),	void ( *Callback_TempEntPlaySound )( struct tempent_s *pTemp, float damp ) );
typedef struct cl_entity_s *(*HUD_GETUSERENTITY_FUNC ) ( int index );
typedef void (*HUD_VOICESTATUS_FUNC)(int entindex, qboolean bTalking);
typedef void (*HUD_DIRECTORMESSAGE_FUNC)( int iSize, void *pbuf );
typedef int ( *HUD_STUDIO_INTERFACE_FUNC )( int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio );
typedef void (*HUD_CHATINPUTPOSITION_FUNC)( int *x, int *y );
typedef int (*HUD_GETPLAYERTEAM)(int iplayer);
typedef void *(*CLIENTFACTORY)();

typedef struct
{
	INITIALIZE_FUNC						pInitFunc;
	HUD_INIT_FUNC						pHudInitFunc;
	HUD_VIDINIT_FUNC					pHudVidInitFunc;
	HUD_REDRAW_FUNC						pHudRedrawFunc;
	HUD_UPDATECLIENTDATA_FUNC			pHudUpdateClientDataFunc;
	HUD_RESET_FUNC						pHudResetFunc;
	HUD_CLIENTMOVE_FUNC					pClientMove;
	HUD_CLIENTMOVEINIT_FUNC				pClientMoveInit;
	HUD_TEXTURETYPE_FUNC				pClientTextureType;
	HUD_IN_ACTIVATEMOUSE_FUNC			pIN_ActivateMouse;
	HUD_IN_DEACTIVATEMOUSE_FUNC			pIN_DeactivateMouse;
	HUD_IN_MOUSEEVENT_FUNC				pIN_MouseEvent;
	HUD_IN_CLEARSTATES_FUNC				pIN_ClearStates;
	HUD_IN_ACCUMULATE_FUNC				pIN_Accumulate;
	HUD_CL_CREATEMOVE_FUNC				pCL_CreateMove;
	HUD_CL_ISTHIRDPERSON_FUNC			pCL_IsThirdPerson;
	HUD_CL_GETCAMERAOFFSETS_FUNC		pCL_GetCameraOffsets;
	HUD_KB_FIND_FUNC					pFindKey;
	HUD_CAMTHINK_FUNC					pCamThink;
	HUD_CALCREF_FUNC					pCalcRefdef;
	HUD_ADDENTITY_FUNC					pAddEntity;
	HUD_CREATEENTITIES_FUNC				pCreateEntities;
	HUD_DRAWNORMALTRIS_FUNC				pDrawNormalTriangles;
	HUD_DRAWTRANSTRIS_FUNC				pDrawTransparentTriangles;
	HUD_STUDIOEVENT_FUNC				pStudioEvent;
	HUD_POSTRUNCMD_FUNC					pPostRunCmd;
	HUD_SHUTDOWN_FUNC					pShutdown;
	HUD_TXFERLOCALOVERRIDES_FUNC		pTxferLocalOverrides;
	HUD_PROCESSPLAYERSTATE_FUNC			pProcessPlayerState;
	HUD_TXFERPREDICTIONDATA_FUNC		pTxferPredictionData;
	HUD_DEMOREAD_FUNC					pReadDemoBuffer;
	HUD_CONNECTIONLESS_FUNC				pConnectionlessPacket;
	HUD_GETHULLBOUNDS_FUNC				pGetHullBounds;
	HUD_FRAME_FUNC						pHudFrame;
	HUD_KEY_EVENT_FUNC					pKeyEvent;
	HUD_TEMPENTUPDATE_FUNC				pTempEntUpdate;
	HUD_GETUSERENTITY_FUNC				pGetUserEntity;
	HUD_VOICESTATUS_FUNC				pVoiceStatus;		// Possibly null on old client dlls.
	HUD_DIRECTORMESSAGE_FUNC			pDirectorMessage;	// Possibly null on old client dlls.
	HUD_STUDIO_INTERFACE_FUNC			pStudioInterface;	// Not used by all clients
	HUD_CHATINPUTPOSITION_FUNC			pChatInputPosition;	// Not used by all clients
	HUD_GETPLAYERTEAM					pGetPlayerTeam; // Not used by all clients
	CLIENTFACTORY				        pClientFactory;
    void (__cdecl* Func1)();
    void (__cdecl* Func2)();
    void (__cdecl* Func3)();
    void (__cdecl* Func4)();
    void (__cdecl* Func5)();
} cldll_func_t;