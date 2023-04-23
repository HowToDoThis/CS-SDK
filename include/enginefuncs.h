// basetypes
typedef int qboolean;
// mathlib
typedef float vec_t;
typedef vec_t vec3_t[3];

// eiface.h
enum ALERT_TYPE
{
	at_notice,
	at_console,		// same as at_notice, but forces a ConPrintf, not a message box
	at_aiconsole,	// same as at_console, but only shown if developer level is 2!
	at_warning,
	at_error,
	at_logged		// Server print to console ( only in multiplayer games ).
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
	force_exactfile,					// File on client must exactly match server's file
	force_model_samebounds,				// For model files only, the geometry must fit in the same bbox
	force_model_specifybounds,			// For model files only, the geometry must fit in the specified bbox
	force_model_specifybounds_if_avail,	// For Steam model files only, the geometry must fit in the specified bbox (if the file is available)
};
// Returned by TraceLine
struct TraceResult
{
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

void PF_makevectors_I(const float *rgflVector);
float PF_Time(void);
void PF_setorigin_I(struct edict_t *e, const float *org);
void SetMinMaxSize(struct edict_t *e, const float *min, const float *max, qboolean rotate);
void PF_setsize_I(struct edict_t *e, const float *rgflMin, const float *rgflMax);
void PF_setmodel_I(struct edict_t *e, const char *m);
int PF_modelindex(const char *pstr);
int ModelFrames(int modelIndex);
int SV_LookupModelIndex(const char *name);
void PF_bprint(char *s);
void PF_sprint(char *s, int entnum);
void ServerPrint(const char *szMsg);
void ClientPrintf(struct edict_t *pEdict, PRINT_TYPE ptype, const char *szMsg);
float PF_vectoyaw_I(const float *rgflVector);
void PF_vectoangles_I(const float *rgflVectorIn, float *rgflVectorOut);
void PF_particle_I(const float *org, const float *dir, float color, float count);
void PF_ambientsound_I(struct edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch);
void PF_sound_I(struct edict_t *entity, int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch);
void PF_traceline_Shared(const float *v1, const float *v2, int nomonsters, struct edict_t *ent);
void PF_traceline_DLL(const float *v1, const float *v2, int fNoMonsters, struct edict_t *pentToSkip, TraceResult *ptr);
void TraceHull(const float *v1, const float *v2, int fNoMonsters, int hullNumber, struct edict_t *pentToSkip, TraceResult *ptr);
void TraceSphere(const float *v1, const float *v2, int fNoMonsters, float radius, struct edict_t *pentToSkip, TraceResult *ptr);
void TraceModel(const float *v1, const float *v2, int hullNumber, struct edict_t *pent, TraceResult *ptr);
struct msurface_t *SurfaceAtPoint(struct model_t *pModel, struct mnode_t *node, vec_t *start, vec_t *end);
const char *TraceTexture(struct edict_t *pTextureEntity, const float *v1, const float *v2);
void PF_TraceToss_Shared(struct edict_t *ent, struct edict_t *ignore);
void SV_SetGlobalTrace(struct trace_t *ptrace);
void PF_TraceToss_DLL(struct edict_t *pent, struct edict_t *pentToIgnore, TraceResult *ptr);
int TraceMonsterHull(struct edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, struct edict_t *pentToSkip, TraceResult *ptr);
int PF_newcheckclient(int check);
struct edict_t *PF_checkclient_I(struct edict_t *pEdict);
struct mnode_t *PVSNode(struct mnode_t *node, vec_t *emins, vec_t *emaxs);
void PVSMark(model_t *pmodel, unsigned char *ppvs);
struct edict_t *PVSFindEntities(struct edict_t *pplayer);
qboolean ValidCmd(const char *pCmd);
void PF_stuffcmd_I(edict_t *pEdict, const char *szFmt, ...);
void PF_localcmd_I(const char *str);
void PF_localexec_I(void);
struct edict_t *FindEntityInSphere(struct edict_t *pEdictStartSearchAfter, const float *org, float rad);
struct edict_t *PF_Spawn_I(void);
struct edict_t *CreateNamedEntity(int className);
void PF_Remove_I(struct edict_t *ed);
void PF_Remove_I_internal(struct edict_t *ed);
struct edict_t *PF_find_Shared(int eStartSearchAfter, int iFieldToMatch, const char *szValueToFind);
int iGetIndex(const char *pszField);
struct edict_t *FindEntityByString(struct edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue);
int GetEntityIllum(struct edict_t *pEnt);
qboolean PR_IsEmptyString(const char *s);
int PF_precache_sound_I(const char *s);
int PF_precache_sound_I_internal(const char *s);
unsigned short EV_Precache(int type, const char *psz);
unsigned short EV_Precache_internal(int type, const char *psz);
void EV_PlayReliableEvent_api(struct IGameClient *cl, int entindex, unsigned short eventindex, float delay, struct event_args_t *pargs);
void EV_PlayReliableEvent(struct client_t *cl, int entindex, unsigned short eventindex, float delay, struct event_args_t *pargs);
void EV_PlayReliableEvent_internal(struct client_t *cl, int entindex, unsigned short eventindex, float delay, struct event_args_t *pargs);
void EV_Playback(int flags, const struct edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
void EV_SV_Playback(int flags, int clientindex, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
int PF_precache_model_I(const char *s);
int PF_precache_model_I_internal(const char *s);
int PF_precache_generic_I(const char *s);
int PF_precache_generic_I_internal(const char *s);
int PF_IsMapValid_I(const char *mapname);
int PF_NumberOfEntities_I(void);
char *PF_GetInfoKeyBuffer_I(struct edict_t *e);
char *PF_InfoKeyValue_I(char *infobuffer, const char *key);
void PF_SetKeyValue_I(char *infobuffer, const char *key, const char *value);
void PF_RemoveKey_I(char *s, const char *key);
void PF_SetClientKeyValue_I(int clientIndex, char *infobuffer, const char *key, const char *value);
int PF_walkmove_I(struct edict_t *ent, float yaw, float dist, int iMode);
int PF_droptofloor_I(struct edict_t *ent);
int PF_DecalIndex(const char *name);
void PF_lightstyle_I(int style, const char *val);
int PF_checkbottom_I(struct edict_t *pEdict);
int PF_pointcontents_I(const float *rgflVector);
void PF_aim_I(struct edict_t *ent, float speed, float *rgflReturn);
void PF_changeyaw_I(struct edict_t *ent);
void PF_changepitch_I(struct edict_t *ent);
void PF_setview_I(const struct edict_t *clientent, const struct edict_t *viewent);
void PF_crosshairangle_I(const struct edict_t *clientent, float pitch, float yaw);
struct edict_t *PF_CreateFakeClient_I(const char *netname);
struct edict_t *CreateFakeClient_internal(const char *netname);
void PF_RunPlayerMove_I(struct edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, unsigned char impulse, unsigned char msec);
struct sizebuf_t *WriteDest_Parm(int dest);
void PF_MessageBegin_I(int msg_dest, int msg_type, const float *pOrigin, struct edict_t *ed);
void PF_MessageEnd_I(void);
void PF_WriteByte_I(int iValue);
void PF_WriteChar_I(int iValue);
void PF_WriteShort_I(int iValue);
void PF_WriteLong_I(int iValue);
void PF_WriteAngle_I(float flValue);
void PF_WriteCoord_I(float flValue);
void PF_WriteString_I(const char *sz);
void PF_WriteEntity_I(int iValue);
void PF_makestatic_I(struct edict_t *ent);
void PF_StaticDecal(const float *origin, int decalIndex, int entityIndex, int modelIndex);
void PF_setspawnparms_I(struct edict_t *ent);
void PF_changelevel_I(const char *s1, const char *s2);
void SeedRandomNumberGenerator(void);
int ran1(void);
float fran1(void);
float RandomFloat(float flLow, float flHigh);
int RandomLong(int lLow, int lHigh);
void PF_FadeVolume(const struct edict_t *clientent, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds);
void PF_SetClientMaxspeed(struct edict_t *clientent, float fNewMaxspeed);
int PF_GetPlayerUserId(struct edict_t *e);
unsigned int PF_GetPlayerWONId(struct edict_t *e);
const char *PF_GetPlayerAuthId(struct edict_t *e);
void PF_BuildSoundMsg_I(struct edict_t *entity, int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, struct edict_t *ed);
void PF_BuildSoundMsg_I_internal(struct edict_t *entity, int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, struct edict_t *ed);
int PF_IsDedicatedServer(void);
const char *PF_GetPhysicsInfoString(const struct edict_t *pClient);
const char *PF_GetPhysicsKeyValue(const struct edict_t *pClient, const char *key);
void PF_SetPhysicsKeyValue(const struct edict_t *pClient, const char *key, const char *value);
int PF_GetCurrentPlayer(void);
int PF_CanSkipPlayer(const struct edict_t *pClient);
void PF_SetGroupMask(int mask, int op);
int PF_CreateInstancedBaseline(int classname, struct entity_state_s *baseline);
void PF_Cvar_DirectSet(struct cvar_s *var, const char *value);
void PF_ForceUnmodified(FORCE_TYPE type, float *mins, float *maxs, const char *filename);
void PF_GetPlayerStats(const edict_t *pClient, int *ping, int *packet_loss);
void QueryClientCvarValueCmd(void);
void QueryClientCvarValueCmd2(void);
void QueryClientCvarValue(const struct edict_t *player, const char *cvarName);
void QueryClientCvarValue2(const struct edict_t *player, const char *cvarName, int requestID);
int hudCheckParm(char *parm, char **ppnext);
int EngCheckParm(const char *pchCmdLineToken, char **pchNextVal);

// pr_edict.h
void SaveSpawnParms(struct edict_t *pEdict);
void CVarSetFloat(const char *szVarName, float flValue);
void CVarSetString(const char *szVarName, const char *szValue);
void CVarRegister(struct cvar_t *pCvar);
float CVarGetFloat(const char *szVarName);
const char *CVarGetString(const char *szVarName);
struct cvar_t *CVarGetPointer(const char *szVarName);
void *PvAllocEntPrivateData(struct edict_t *pEdict, int cb);
void *PvEntPrivateData(struct edict_t *pEdict);
void FreeEntPrivateData(struct edict_t *pEdict);
const char *SzFromIndex(int iString);
int AllocEngineString(const char *szValue);
struct entvars_t *GetVarsOfEnt(struct edict_t *pEdict);
struct edict_t *PEntityOfEntOffset(int iEntOffset);
int EntOffsetOfPEntity(const struct edict_t *pEdict);
int IndexOfEdict(const struct edict_t *pEdict);
struct edict_t *PEntityOfEntIndex(int iEntIndex);
struct edict_t *FindEntityByVars(struct entvars_t *pvars);
void *GetModelPtr(struct edict_t *pEdict);

// sv_move.h
void SV_MoveToOrigin_I(struct edict_t *ent, const float *pflGoal, float dist, int iMoveType);

// mathlib_e.h
void AngleVectors_ext(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);

// sys_dll.h
void EngineFprintf(void *pfile, const char *szFmt, ...);
void AlertMessage(ALERT_TYPE atype, const char *szFmt, ...);
int FunctionFromName(const char *pName);
const char *NameForFunction(int function);
qboolean Voice_GetClientListening(int iReceiver, int iSender);
qboolean Voice_SetClientListening(int iReceiver, int iSender, qboolean bListen);

// server.h
int RegUserMsg(const char *pszName, int iSize);

// studio_rehlds.h
void AnimationAutomove(const struct edict_t *pEdict, float flTime);
void GetBonePosition(const struct edict_t *pEdict, int iBone, float *rgflOrigin, float *rgflAngles);
void GetAttachment(const struct edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles);

// cmd.h
int Cmd_Argc(void);
const char *Cmd_Argv(int arg);
const char *Cmd_Args(void);

// crc.h
typedef unsigned int CRC32_t;
void CRC32_Init(CRC32_t *pulCRC);
CRC32_t CRC32_Final(CRC32_t pulCRC);
void CRC32_ProcessByte(CRC32_t *pulCRC, unsigned char ch);
void CRC32_ProcessBuffer(CRC32_t *pulCRC, void *pBuffer, int nBuffer);

// common.h
unsigned char *COM_LoadFileForMe(const char *filename, int *pLength);
void COM_FreeFile(void *buffer);
int COM_CompareFileTime(char *filename1, char *filename2, int *iCompare);
void COM_GetGameDir(char *szGameDir);
unsigned int COM_GetApproxWavePlayLength(const char *filepath);
int COM_FileSize(const char *filename);

// cvar.h
void Cvar_RegisterVariable(cvar_t *variable);

// cmd.h
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
void Cmd_AddGameCommand(const char *cmd_name, xcommand_t function);

// host.h
void Host_EndSection(const char *pszSection);

// server.h
unsigned char *SV_FatPVS(float *org);
unsigned char *SV_FatPAS(float *org);
int SV_CheckVisibility(struct edict_t *entity, unsigned char *pset);

// delta.h
void DELTA_SetField(struct delta_s *pFields, const char *fieldname);
void DELTA_UnsetField(struct delta_s *pFields, const char *fieldname);
void DELTA_AddEncoder(const char *name, void(*conditionalencode)(struct delta_s *, const unsigned char *, const unsigned char *));
int  DELTA_FindFieldIndex(struct delta_s *pFields, const char *fieldname);
void DELTA_SetFieldByIndex(struct delta_s *pFields, int fieldNumber);
void DELTA_UnsetFieldByIndex(struct delta_s *pFields, int fieldNumber);

// client.h
int VGuiWrap2_IsInCareerMatch();
int VGuiWrap2_GetLocalizedStringLength(const char *label);
void RegisterTutorMessageShown(int mid);
int GetTimesTutorMessageShown(int id);
void ConstructTutorMessageDecayBuffer(int *buffer, int bufferLength);
void ProcessTutorMessageDecayBuffer(int *buffer, int bufferLength);
void ResetTutorMessageDecayData();

enginefuncs_t g_engfuncsExportedToDlls = {
	PF_precache_model_I, PF_precache_sound_I,
	PF_setmodel_I, PF_modelindex,
	ModelFrames, PF_setsize_I,
	PF_changelevel_I, PF_setspawnparms_I,
	SaveSpawnParms, PF_vectoyaw_I,
	PF_vectoangles_I, SV_MoveToOrigin_I,
	PF_changeyaw_I, PF_changepitch_I,
	FindEntityByString, GetEntityIllum,
	FindEntityInSphere, PF_checkclient_I,
	PVSFindEntities, PF_makevectors_I,
	AngleVectors_ext, PF_Spawn_I,
	PF_Remove_I, CreateNamedEntity,
	PF_makestatic_I, PF_checkbottom_I,
	PF_droptofloor_I, PF_walkmove_I,
	PF_setorigin_I, PF_sound_I,
	PF_ambientsound_I, PF_traceline_DLL,
	PF_TraceToss_DLL, TraceMonsterHull,
	TraceHull, TraceModel,
	TraceTexture, TraceSphere,
	PF_aim_I, PF_localcmd_I,
	PF_localexec_I, PF_stuffcmd_I,
	PF_particle_I, PF_lightstyle_I,
	PF_DecalIndex, PF_pointcontents_I,
	PF_MessageBegin_I, PF_MessageEnd_I,
	PF_WriteByte_I, PF_WriteChar_I,
	PF_WriteShort_I, PF_WriteLong_I,
	PF_WriteAngle_I, PF_WriteCoord_I,
	PF_WriteString_I, PF_WriteEntity_I,
	CVarRegister, CVarGetFloat,
	CVarGetString, CVarSetFloat,
	CVarSetString, AlertMessage,
	EngineFprintf, PvAllocEntPrivateData,
	PvEntPrivateData, FreeEntPrivateData,
	SzFromIndex, AllocEngineString,
	GetVarsOfEnt, PEntityOfEntOffset,
	EntOffsetOfPEntity, IndexOfEdict,
	PEntityOfEntIndex, FindEntityByVars,
	GetModelPtr, RegUserMsg,
	AnimationAutomove, GetBonePosition,
	FunctionFromName, NameForFunction,
	ClientPrintf, ServerPrint,
	Cmd_Args, Cmd_Argv, Cmd_Argc,
	GetAttachment, CRC32_Init,
	CRC32_ProcessBuffer, CRC32_ProcessByte,
	CRC32_Final, RandomLong,
	RandomFloat, PF_setview_I,
	PF_Time, PF_crosshairangle_I,
	COM_LoadFileForMe, COM_FreeFile,
	Host_EndSection, COM_CompareFileTime,
	COM_GetGameDir, Cvar_RegisterVariable,
	PF_FadeVolume, PF_SetClientMaxspeed,
	PF_CreateFakeClient_I,
	PF_RunPlayerMove_I,
	PF_NumberOfEntities_I,
	PF_GetInfoKeyBuffer_I, PF_InfoKeyValue_I,
	PF_SetKeyValue_I, PF_SetClientKeyValue_I,
	PF_IsMapValid_I, PF_StaticDecal,
	PF_precache_generic_I,
	PF_GetPlayerUserId, PF_BuildSoundMsg_I,
	PF_IsDedicatedServer, CVarGetPointer,
	PF_GetPlayerWONId, PF_RemoveKey_I,
	PF_GetPhysicsKeyValue,
	PF_SetPhysicsKeyValue,
	PF_GetPhysicsInfoString, EV_Precache,
	EV_Playback, SV_FatPVS, SV_FatPAS,
	SV_CheckVisibility, DELTA_SetField,
	DELTA_UnsetField, DELTA_AddEncoder,
	PF_GetCurrentPlayer, PF_CanSkipPlayer,
	DELTA_FindFieldIndex,
	DELTA_SetFieldByIndex,
	DELTA_UnsetFieldByIndex, PF_SetGroupMask,
	PF_CreateInstancedBaseline,
	PF_Cvar_DirectSet, PF_ForceUnmodified,
	PF_GetPlayerStats, Cmd_AddGameCommand,
	Voice_GetClientListening,
	Voice_SetClientListening,
	PF_GetPlayerAuthId, 0,
	0, COM_FileSize,
	COM_GetApproxWavePlayLength,
	VGuiWrap2_IsInCareerMatch,
	VGuiWrap2_GetLocalizedStringLength,
	RegisterTutorMessageShown,
	GetTimesTutorMessageShown,
	ProcessTutorMessageDecayBuffer,
	ConstructTutorMessageDecayBuffer,
	ResetTutorMessageDecayData,
	QueryClientCvarValue, QueryClientCvarValue2,
	EngCheckParm
};