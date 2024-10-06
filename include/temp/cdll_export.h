#define MAX_ALIAS_NAME 32

typedef int BOOL;
typedef int qboolean;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int string_t;

typedef struct rect_s { int left, right, top, bottom; } wrect_t;

typedef struct cmdalias_s {
    struct cmdalias_s* next;
    char    name[MAX_ALIAS_NAME];
    char* value;
} cmdalias_t;

typedef struct cvar_s {
    char *name;
    char	*string;
    int flags;
    float	value;
    struct cvar_s *next;
} cvar_t;

typedef int (__cdecl*pfnUserMsgHook)(const char* pszName, int iSize, void* pbuf);
typedef int SptiteHandle_t;	// handle to a graphic

typedef struct original_cl_enginefuncs_s {
    // sprite handlers
    SptiteHandle_t(__cdecl*pfnSPR_Load)           (const char* szPicName);
    //SptiteHandle_t              (__cdecl*pfnSPR_Load2)          ( const char *szPicName );
    int                         (__cdecl*pfnSPR_Frames)         (SptiteHandle_t hPic);
    int                         (__cdecl*pfnSPR_Height)         (SptiteHandle_t hPic, int frame);
    int                         (__cdecl*pfnSPR_Width)          (SptiteHandle_t hPic, int frame);
    void                        (__cdecl*pfnSPR_Set)            (SptiteHandle_t hPic, int r, int g, int b);

    void                        (__cdecl*pfnSPR_Draw)           (int frame, int x, int y, const wrect_t* prc);
    void                        (__cdecl*pfnSPR_DrawHoles)      (int frame, int x, int y, const wrect_t* prc);
    void                        (__cdecl*pfnSPR_DrawAdditive)   (int frame, int x, int y, const wrect_t* prc);
    void                        (__cdecl*pfnSPR_EnableScissor)  (int x, int y, int width, int height);
    void                        (__cdecl*pfnSPR_DisableScissor) (void);
    struct client_sprite_t* (__cdecl*pfnSPR_GetList)        (char* psz, int* piCount);
    void                        (__cdecl*pfnFillRGBA)            (int x, int y, int width, int height, int r, int g, int b, int a);
    int                         (__cdecl*pfnGetScreenInfo)       (struct SCREENINFO* pscrinfo);
    void                        (__cdecl*pfnSetCrosshair)        (SptiteHandle_t hspr, wrect_t rc, int r, int g, int b);
    struct cvar_s* (__cdecl*pfnRegisterVariable)    (char* szName, char* szValue, int flags);
    float                       (__cdecl*pfnGetCvarFloat)        (char* szName);
    char* (__cdecl*pfnGetCvarString)       (char* szName);
    int                         (__cdecl*pfnAddCommand)          (char* cmd_name, void (__cdecl*function)(void));
    int                         (__cdecl*pfnHookUserMsg)         (char* szMsgName, pfnUserMsgHook pfn);
    int                         (__cdecl*pfnServerCmd)           (char* szCmdString);
    int                         (__cdecl*pfnClientCmd)           (char* szCmdString);
    void                        (__cdecl*pfnGetPlayerInfo)       (int ent_num, struct hud_player_info_t* pinfo);
    void                        (__cdecl*pfnPlaySoundByName)     (char* szSound, float volume);
    void                        (__cdecl*pfnPlaySoundByIndex)    (int iSound, float volume);
    void                        (__cdecl*pfnAngleVectors)        (const float* vecAngles, float* forward, float* right, float* up);
    struct client_textmessage_t* (__cdecl*pfnTextMessageGet)      (const char* pName);
    int                         (__cdecl*pfnDrawCharacter)       (int x, int y, int number, int r, int g, int b);
    int                         (__cdecl*pfnDrawConsoleString)   (int x, int y, char* string);
    void                        (__cdecl*pfnDrawSetTextColor)    (float r, float g, float b);
    void                        (__cdecl*pfnDrawConsoleStringLen)(const char* string, int* length, int* height);
    void                        (__cdecl*pfnConsolePrint)        (const char* string);
    void                        (__cdecl*pfnCenterPrint)         (const char* string);
    int                         (__cdecl*GetWindowCenterX)       (void);
    int                         (__cdecl*GetWindowCenterY)       (void);
    void                        (__cdecl*GetViewAngles)          (float*);
    void                        (__cdecl*SetViewAngles)          (float*);
    int                         (__cdecl*GetMaxClients)          (void);
    void                        (__cdecl*Cvar_SetValue)          (char* cvar, float value);
    int                         (__cdecl*Cmd_Argc)               (void);
    char* (__cdecl*Cmd_Argv)               (int arg);
    void                        (__cdecl*Con_Printf)             (char* fmt, ...);
    void                        (__cdecl*Con_DPrintf)            (char* fmt, ...);
    void                        (__cdecl*Con_NPrintf)            (int pos, char* fmt, ...);
    void                        (__cdecl*Con_NXPrintf)           (struct con_nprint_s* info, char* fmt, ...);
    const char* (__cdecl*PhysInfo_ValueForKey)   (const char* key);
    const char* (__cdecl*ServerInfo_ValueForKey) (const char* key);
    float                       (__cdecl*GetClientMaxspeed)      (void);
    int                         (__cdecl*CheckParm)              (char* parm, char** ppnext);
    void                        (__cdecl*Key_Event)              (int key, int down);
    void                        (__cdecl*GetMousePosition)       (int* mx, int* my);
    int                         (__cdecl*IsNoClipping)           (void);
    struct cl_entity_s* (__cdecl*GetLocalPlayer)         (void);
    struct cl_entity_s* (__cdecl*GetViewModel)           (void);
    struct cl_entity_s* (__cdecl*GetEntityByIndex)       (int idx);
    float                       (__cdecl*GetClientTime)          (void);
    void                        (__cdecl*V_CalcShake)            (void);
    void                        (__cdecl*V_ApplyShake)           (float* origin, float* angles, float factor);
    int                         (__cdecl*PM_PointContents)       (float* point, int* truecontents);
    int                         (__cdecl*PM_WaterEntity)         (float* p);
    struct pmtrace_s* (__cdecl*PM_TraceLine)           (float* start, float* end, int flags, int usehull, int ignore_pe);
    struct model_s* (__cdecl*CL_LoadModel)           (const char* modelname, int* index);
    int                         (__cdecl*CL_CreateVisibleEntity) (int type, struct cl_entity_s* ent);
    const struct model_s* (__cdecl*GetSpritePointer)       (SptiteHandle_t hSprite);
    void                        (__cdecl*pfnPlaySoundByNameAtLocation) (char* szSound, float volume, float* origin);
    unsigned short              (__cdecl*pfnPrecacheEvent)       (int type, const char* psz);
    void                        (__cdecl*pfnPlaybackEvent)       (int flags, const struct edict_s* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
    void                        (__cdecl*pfnWeaponAnim)          (int iAnim, int body);
    float                       (__cdecl*pfnRandomFloat)         (float flLow, float flHigh);
    long                        (__cdecl*pfnRandomLong)          (long lLow, long lHigh);
    void                        (__cdecl*pfnHookEvent)           (char* name, void (__cdecl*pfnEvent)(struct event_args_s* args));
    int                         (__cdecl*Con_IsVisible)          ();
    const char* (__cdecl*pfnGetGameDirectory)    (void);
    struct cvar_s* (__cdecl*pfnGetCvarPointer)      (const char* szName);
    const char* (__cdecl*Key_LookupBinding)      (const char* pBinding);
    const char* (__cdecl*pfnGetLevelName)        (void);
    void                        (__cdecl*pfnGetScreenFade)       (struct screenfade_s* fade);
    void                        (__cdecl*pfnSetScreenFade)       (struct screenfade_s* fade);
    void* (__cdecl*VGui_GetPanel)          ();
    void                        (__cdecl*VGui_ViewportPaintBackground) (int extents[4]);
    byte* (__cdecl*COM_LoadFile)           (char* path, int usehunk, int* pLength);
    char* (__cdecl*COM_ParseFile)          (char* data, char* token);
    void                        (__cdecl*COM_FreeFile)           (void* buffer);
    struct triangleapi_s* pTriAPI;
    struct efx_api_s* pEfxAPI;
    struct event_api_s* pEventAPI;
    struct demo_api_s* pDemoAPI;
    struct net_api_s* pNetAPI;
    struct IVoiceTweak_s* pVoiceTweak;
    int                         (__cdecl*IsSpectateOnly)         (void);
    struct model_s* (__cdecl*LoadMapSprite)          (const char* filename);
    void                        (__cdecl*COM_AddAppDirectoryToSearchPath) (const char* pszBaseDir, const char* appName);
    int                         (__cdecl*COM_ExpandFilename)              (const char* fileName, char* nameOutBuffer, int nameOutBufferSize);
    const char* (__cdecl*PlayerInfo_ValueForKey)          (int playerNum, const char* key);
    void                        (__cdecl*PlayerInfo_SetValueForKey)       (const char* key, const char* value);
    qboolean(__cdecl*GetPlayerUniqueID)      (int iPlayer, char playerID[16]);
    int                         (__cdecl*GetTrackerIDForPlayer)  (int playerSlot);
    int                         (__cdecl*GetPlayerForTrackerID)  (int trackerID);
    int                         (__cdecl*pfnServerCmdUnreliable) (char* szCmdString);
    void                        (__cdecl*pfnGetMousePos)         (struct tagPOINT* ppt);
    void                        (__cdecl*pfnSetMousePos)         (int x, int y);
    void                        (__cdecl*pfnSetMouseEnable)      (qboolean fEnable);
    struct cvar_s* (__cdecl*pfnGetCvarList)         (void);
    struct cmd_s* (__cdecl*pfnGetCmdList)          (void);
    char* (__cdecl*pfnGetCvarName)         (struct cvar_s* cvar);
    char* (__cdecl*pfnGetCmdName)          (struct cmd_s* cmd);
    float                       (__cdecl*pfnGetServerTime)       (void);
    float                       (__cdecl*pfnGetGravity)          (void);
    const struct model_s* (__cdecl*pfnPrecacheSprite)      (SptiteHandle_t spr);
    void                        (__cdecl*OverrideLightmap)       (int override);
    void                        (__cdecl*SetLightmapColor)       (float r, float g, float b);
    void                        (__cdecl*SetLightmapDarkness)    (float dark);
    int                         (__cdecl*pfnGetSequenceByName)   (int flags, const char* seq);
    void                        (__cdecl*pfnSPR_DrawGeneric)     (int frame, int x, int y, const wrect_t* prc, int blendsrc, int blenddst, int unknown1, int unknown2);
    void                        (__cdecl*pfnLoadSentence)        (void);
    int                         (__cdecl*pfnDrawLocalizedHudString)    (int x, int y, const char* str, int r, int g, int b);
    int                         (__cdecl*pfnDrawLocalizedConsoleString)(int x, int y, const char* str);
    const char* (__cdecl*LocalPlayerInfo_ValueForKey)  (const char* key);
    void                        (__cdecl*pfnDrawText_0)                (int x, int y, const wchar_t* text, unsigned long font);
    int                         (__cdecl*pfnDrawUnicodeCharacter)      (int x, int y, short number, int r, int g, int b, unsigned long hfont);
    int                         (__cdecl*pfnCheckSoundFile)            (const char* path);
    void* (__cdecl*GetCareerGameInterface)       (void);
    void                        (__cdecl*pfnCvar_Set)                  (const char* cvar, const char* value);
    int                         (__cdecl*IsSinglePlayer)               (void);
    void                        (__cdecl*pfnPlaySound)                 (const char* sound, float vol, float pitch);
    void                        (__cdecl*pfnPlayMp3)                   (const char* mp3, int flags);
    float                       (__cdecl*Sys_FloatTime)                (void);
    void                        (__cdecl*pfnSetArray)                  (int* array, int size);
    void                        (__cdecl*pfnSetClearArray)             (int* array, int size);
    void                        (__cdecl*pfnClearArray)                (void);
    void                        (__cdecl*pfnPlaySound2)                (const char* sound, float vol, float pitch);
    void                        (__cdecl*pfnTintRGBA)                  (int x, int y, int width, int height, int r, int g, int b, int a);
} original_cl_enginefuncs_t;

typedef struct confirmed_cl_enginefuncs_s : original_cl_enginefuncs_t
{
    int   (__cdecl*GetGameAppID)              ();
    cmdalias_t* (__cdecl*GetCurrentAlias)     ();
    void  (__cdecl*SPR_DrawHolesScaled)       (int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    void  (__cdecl*SPR_Replace)               (int a2, int a3);
    void  (__cdecl*SPR_DrawAdditiveScaled)    (int a1, int a2, int a3, int a4, int a5, int a6, int a7); // CHN151208 after not exists
    void  (__cdecl*LeaveGameRoom)             (int type);
    bool  (__cdecl*CheckBadWord)           (wchar_t* msg);
    int   (__cdecl*CheckServerChannelMgr)     (); // result != 0??
    bool  (__cdecl*CheckServerChannelMgr2)    (); // check 2 8 7 type?
} confirmed_cl_enginefuncs_t;

// Reverse engineered by Jusic (06.12.18)
// Updated by Neko (20.05.2024)
typedef struct new_cl_enginefuncs_s : confirmed_cl_enginefuncs_t
{
    void  (__cdecl*PlaySound3)                (const char* sound, float vol, float pitch); // CHN141219 after exists
    void* (__cdecl*GetInventory)              ();
    void* (__cdecl*GetIGClassMenuMgr)         ();
    void* (__cdecl*GetIGBuyMenuMgr)           ();
    class CChattingManager* (__cdecl*GetChatManager)      ();
    class GamePlayerManager* (__cdecl*GetGamePlayerManager)();
    class GameOptionManager* (__cdecl*GetGameOptionManager)();
    void* (__cdecl*GetBuyMenuManager)         ();
    void* (__cdecl*LoadItemCSV)               ();
    void* (__cdecl*GetCFavoriteWeaponsManager)();
    void* (__cdecl*GetMenuQueueMgr)           ();
    void* (__cdecl*GetCrossHairMgr)           ();
    void* (__cdecl*GetSharedDataMgr)          ();
    void* (__cdecl*GetGameRoomManager)        ();
    void* (__cdecl*GetClanMgr)                ();
    void* (__cdecl*GetItemShop)               ();
    void  (__cdecl*Unknown25)                 (BYTE* a1);
    void* (__cdecl*LoadLocationCSV)           ();
    void* (__cdecl*GetRankingManager)         ();
    void  (__cdecl*GetStrGen)                 ();
    void* (__cdecl*GetVideoMode)              ();
    void* (__cdecl*GetUserFacade)             ();
    void* (__cdecl*GetCSOFacade)              ();
    void  (__cdecl*IsKeyBind)                 (char*); // Something Key
    void* (__cdecl*GetClanStorage)            ();
    void  (__cdecl*Pbuf_AddText)              (const char* text);
    void* (__cdecl*GetGameConsoleVariables)   ();
    cvar_s* (__cdecl*RegisterVariable4GameConsole)    (char* szName, char* szValue, int flags);
    void  (__cdecl*MainGameOptionManager)     ();
    void* (__cdecl*GiftBox)                   ();
    void* (__cdecl*Unknown38)                 ();
    void  (__cdecl*SomethingScreen)           (int a1, int a2, int a3, int a4, int a5);
    void* (__cdecl*GetLocalClientState)       ();
    void* (__cdecl*GetCBanManager)            ();
    void* (__cdecl*GetCZBEnhanceManager)      ();
    void* (__cdecl*GetCUserSurveyManager)     ();
    void* (__cdecl*GetCQuestManager)          ();
    void* (__cdecl*GetCUMsgManager)           ();
    void* (__cdecl*GetCMiniGameManager)       ();
    void* (__cdecl*CEventMgr)                 ();
    void* (__cdecl*WeaponMgr)                 ();
    int   (__cdecl*Unknown52)                 (); // return 0
    void* (__cdecl*CFriendManager)            ();
    void* (__cdecl*CComradeManager)           ();
    void* (__cdecl*C2ndPassword)              ();
    void  (__cdecl*Unknown53)                 (); // Rendering Something
    void* (__cdecl*ClanMatchMgr)              ();
    // CHN141219 after exists
    void  (__cdecl*Unknown54)                 (); // return 0 // CHN150430 not exists
    int   (__cdecl*CMileageBingoMgr)          ();
    // CHN150430 starts exists
    void* (__cdecl*Unknown55)                 (); // return ptr(unknown)
    int   (__cdecl*SetUnknown56)              (int size, int offset, int a3, int a4, int a5); // size cannot over 1024
    int   (__cdecl*GetUnknown56)              (int size, int offset, int* a3, int* a4, int* a5); // size cannot over 1024
    void* (__cdecl*CSOCoreSDM)                ();
    int   (__cdecl*Unknown58)                 (); // return 0
    void* (__cdecl*CMonthlyWeaponManager)     ();
    bool  (__cdecl*Unknown59)                 (void* ptr); // a1[791] == 3 && a1[844]
} new_cl_enginefunc_t;

typedef struct cl_exportfuncs_s {
    int (__cdecl*INITIALIZE_FUNC)( new_cl_enginefunc_t*, int );
    void (__cdecl*HUD_INIT_FUNC)( void );
    int (__cdecl*HUD_VIDINIT_FUNC)( void );
    int (__cdecl*HUD_REDRAW_FUNC)( float, int );
    int (__cdecl*HUD_UPDATECLIENTDATA_FUNC) ( struct client_data_s*, float );
    void (__cdecl*HUD_RESET_FUNC)( void );
    void (__cdecl*HUD_CLIENTMOVE_FUNC)( struct playermove_s *ppmove, qboolean server );
    void (__cdecl*HUD_CLIENTMOVEINIT_FUNC)( struct playermove_s *ppmove );
    char (__cdecl*HUD_TEXTURETYPE_FUNC)( char *name );
    void (__cdecl*HUD_IN_ACTIVATEMOUSE_FUNC) ( void );
    void (__cdecl*HUD_IN_DEACTIVATEMOUSE_FUNC)( void );
    void (__cdecl*HUD_IN_MOUSEEVENT_FUNC)( int mstate );
    void (__cdecl*HUD_IN_CLEARSTATES_FUNC)( void );
    void (__cdecl*HUD_IN_ACCUMULATE_FUNC )( void );
    void (__cdecl*HUD_CL_CREATEMOVE_FUNC)( float frametime, struct usercmd_s *cmd, int active );
    int (__cdecl*HUD_CL_ISTHIRDPERSON_FUNC) ( void );
    void (__cdecl*HUD_CL_GETCAMERAOFFSETS_FUNC )( float *ofs );
    struct kbutton_s * (__cdecl*HUD_KB_FIND_FUNC) ( const char *name );
    void (__cdecl*HUD_CAMTHINK_FUNC )( void );
    void (__cdecl*HUD_CALCREF_FUNC ) ( struct ref_params_s *pparams );
    int	 (__cdecl*HUD_ADDENTITY_FUNC ) ( int type, struct cl_entity_s *ent, const char *modelname );
    void (__cdecl*HUD_CREATEENTITIES_FUNC ) ( void );
    void (__cdecl*HUD_DRAWNORMALTRIS_FUNC ) ( void );
    void (__cdecl*HUD_DRAWTRANSTRIS_FUNC ) ( void );
    void (__cdecl*HUD_STUDIOEVENT_FUNC ) ( const struct mstudioevent_s *event, const struct cl_entity_s *entity );
    void (__cdecl*HUD_POSTRUNCMD_FUNC ) ( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed );
    void (__cdecl*HUD_SHUTDOWN_FUNC ) ( void );
    void (__cdecl*HUD_TXFERLOCALOVERRIDES_FUNC )( struct entity_state_s *state, const struct clientdata_s *client );
    void (__cdecl*HUD_PROCESSPLAYERSTATE_FUNC )( struct entity_state_s *dst, const struct entity_state_s *src );
    void (__cdecl*HUD_TXFERPREDICTIONDATA_FUNC ) ( struct entity_state_s *ps, const struct entity_state_s *pps, struct clientdata_s *pcd, const struct clientdata_s *ppcd, struct weapon_data_s *wd, const struct weapon_data_s *pwd );
    
    void (__cdecl*HUD_DEMOREAD_FUNC ) ( int size, unsigned char *buffer );
    int (__cdecl*HUD_CONNECTIONLESS_FUNC )( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
    int	( *HUD_GETHULLBOUNDS_FUNC ) ( int hullnumber, float *mins, float *maxs );
    void (__cdecl*HUD_FRAME_FUNC)		( double );
    int (__cdecl*HUD_KEY_EVENT_FUNC ) ( int eventcode, int keynum, const char *pszCurrentBinding );
    void (__cdecl*HUD_TEMPENTUPDATE_FUNC) ( double frametime, double client_time, double cl_gravity, struct tempent_s **ppTempEntFree, struct tempent_s **ppTempEntActive, 	int (__cdecl*Callback_AddVisibleEntity )( struct cl_entity_s *pEntity ),	void (__cdecl*Callback_TempEntPlaySound)(struct tempent_s *pTemp, float damp));
    struct cl_entity_s *(__cdecl*HUD_GETUSERENTITY_FUNC ) ( int index );
    void (__cdecl*HUD_VOICESTATUS_FUNC)(int entindex, qboolean bTalking);
    void (__cdecl*HUD_DIRECTORMESSAGE_FUNC)( int iSize, void *pbuf );
    int ( *HUD_STUDIO_INTERFACE_FUNC )( int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio );
    void (__cdecl*HUD_CHATINPUTPOSITION_FUNC)( int *x, int *y );
    int (__cdecl*HUD_GETPLAYERTEAM)(int iplayer);
    void* (__cdecl*CLIENTFACTORY)();
} cl_exportfuncs_t;

typedef struct new_exportfuncs_s : cl_exportfuncs_t {
    void (__cdecl*HUD_VidSetMode)();
    void (__cdecl*HUD_NoticePrint)(const char* source, void* a2); // unknown
    void (__cdecl*CL_ClearKeyState)();
    int  (__cdecl*ProcessCLByEngine)(int a1, unsigned int a2, int a3, int a4, int a5); // unknown
    void (__cdecl*HUD_CreateBeams)();
} new_exportfuncs_t;