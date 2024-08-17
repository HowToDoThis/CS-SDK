typedef int qboolean;

typedef int SptiteHandle_t;	// handle to a graphic

typedef int(*pfnUserMsgHook)(const char *pszName, int iSize, void *pbuf);

typedef struct rect_s { int left, right, top, bottom; } wrect_t;

typedef struct cvar_s {
    char *name;
    char	*string;
    int		flags;
    float	value;
    struct cvar_s *next;
} cvar_t;

typedef struct original_cl_enginefuncs_s {
    // sprite handlers
    SptiteHandle_t(*pfnSPR_Load)           (const char* szPicName);
    //SptiteHandle_t              (*pfnSPR_Load2)          ( const char *szPicName );
    int                         (*pfnSPR_Frames)         (SptiteHandle_t hPic);
    int                         (*pfnSPR_Height)         (SptiteHandle_t hPic, int frame);
    int                         (*pfnSPR_Width)          (SptiteHandle_t hPic, int frame);
    void                        (*pfnSPR_Set)            (SptiteHandle_t hPic, int r, int g, int b);

    void                        (*pfnSPR_Draw)           (int frame, int x, int y, const wrect_t* prc);
    void                        (*pfnSPR_DrawHoles)      (int frame, int x, int y, const wrect_t* prc);
    void                        (*pfnSPR_DrawAdditive)   (int frame, int x, int y, const wrect_t* prc);
    void                        (*pfnSPR_EnableScissor)  (int x, int y, int width, int height);
    void                        (*pfnSPR_DisableScissor) (void);
    struct client_sprite_t* (*pfnSPR_GetList)        (char* psz, int* piCount);

    // screen handlers
    void                        (*pfnFillRGBA)            (int x, int y, int width, int height, int r, int g, int b, int a);
    int                         (*pfnGetScreenInfo)       (struct SCREENINFO* pscrinfo);
    void                        (*pfnSetCrosshair)        (SptiteHandle_t hspr, wrect_t rc, int r, int g, int b);

    // cvar handlers
    struct cvar_s* (*pfnRegisterVariable)    (char* szName, char* szValue, int flags);
    float                       (*pfnGetCvarFloat)        (char* szName);
    char* (*pfnGetCvarString)       (char* szName);

    // command handlers
    int                         (*pfnAddCommand)          (char* cmd_name, void (*function)(void));
    int                         (*pfnHookUserMsg)         (char* szMsgName, pfnUserMsgHook pfn);
    int                         (*pfnServerCmd)           (char* szCmdString);
    int                         (*pfnClientCmd)           (char* szCmdString);

    void                        (*pfnGetPlayerInfo)       (int ent_num, struct hud_player_info_t* pinfo);

    // sound handlers
    void                        (*pfnPlaySoundByName)     (char* szSound, float volume);
    void                        (*pfnPlaySoundByIndex)    (int iSound, float volume);

    // vector helpers
    void                        (*pfnAngleVectors)        (const float* vecAngles, float* forward, float* right, float* up);

    // text message system
    struct client_textmessage_t* (*pfnTextMessageGet)      (const char* pName);
    int                         (*pfnDrawCharacter)       (int x, int y, int number, int r, int g, int b);
    int                         (*pfnDrawConsoleString)   (int x, int y, char* string);
    void                        (*pfnDrawSetTextColor)    (float r, float g, float b);
    void                        (*pfnDrawConsoleStringLen)(const char* string, int* length, int* height);

    void                        (*pfnConsolePrint)        (const char* string);
    void                        (*pfnCenterPrint)         (const char* string);


    // Added for user input processing
    int                         (*GetWindowCenterX)       (void);
    int                         (*GetWindowCenterY)       (void);
    void                        (*GetViewAngles)          (float*);
    void                        (*SetViewAngles)          (float*);
    int                         (*GetMaxClients)          (void);
    void                        (*Cvar_SetValue)          (char* cvar, float value);

    int                         (*Cmd_Argc)               (void);
    char* (*Cmd_Argv)               (int arg);
    void                        (*Con_Printf)             (char* fmt, ...);
    void                        (*Con_DPrintf)            (char* fmt, ...);
    void                        (*Con_NPrintf)            (int pos, char* fmt, ...);
    void                        (*Con_NXPrintf)           (struct con_nprint_s* info, char* fmt, ...);

    const char* (*PhysInfo_ValueForKey)   (const char* key);
    const char* (*ServerInfo_ValueForKey) (const char* key);
    float                       (*GetClientMaxspeed)      (void);
    int                         (*CheckParm)              (char* parm, char** ppnext);
    void                        (*Key_Event)              (int key, int down);
    void                        (*GetMousePosition)       (int* mx, int* my);
    int                         (*IsNoClipping)           (void);

    struct cl_entity_s* (*GetLocalPlayer)         (void);
    struct cl_entity_s* (*GetViewModel)           (void);
    struct cl_entity_s* (*GetEntityByIndex)       (int idx);

    float                       (*GetClientTime)          (void);
    void                        (*V_CalcShake)            (void);
    void                        (*V_ApplyShake)           (float* origin, float* angles, float factor);

    int                         (*PM_PointContents)       (float* point, int* truecontents);
    int                         (*PM_WaterEntity)         (float* p);
    struct pmtrace_s* (*PM_TraceLine)           (float* start, float* end, int flags, int usehull, int ignore_pe);

    struct model_s* (*CL_LoadModel)           (const char* modelname, int* index);
    int                         (*CL_CreateVisibleEntity) (int type, struct cl_entity_s* ent);

    const struct model_s* (*GetSpritePointer)       (SptiteHandle_t hSprite);
    void                        (*pfnPlaySoundByNameAtLocation) (char* szSound, float volume, float* origin);

    unsigned short              (*pfnPrecacheEvent)       (int type, const char* psz);
    void                        (*pfnPlaybackEvent)       (int flags, const struct edict_s* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
    void                        (*pfnWeaponAnim)          (int iAnim, int body);
    float                       (*pfnRandomFloat)         (float flLow, float flHigh);
    long                        (*pfnRandomLong)          (long lLow, long lHigh);
    void                        (*pfnHookEvent)           (char* name, void (*pfnEvent)(struct event_args_s* args));
    int                         (*Con_IsVisible)          ();
    const char* (*pfnGetGameDirectory)    (void);
    struct cvar_s* (*pfnGetCvarPointer)      (const char* szName);
    const char* (*Key_LookupBinding)      (const char* pBinding);
    const char* (*pfnGetLevelName)        (void);
    void                        (*pfnGetScreenFade)       (struct screenfade_s* fade);
    void                        (*pfnSetScreenFade)       (struct screenfade_s* fade);
    void* (*VGui_GetPanel)          ();
    void                        (*VGui_ViewportPaintBackground) (int extents[4]);

    byte* (*COM_LoadFile)           (char* path, int usehunk, int* pLength);
    char* (*COM_ParseFile)          (char* data, char* token);
    void                        (*COM_FreeFile)           (void* buffer);

    struct triangleapi_s* pTriAPI;
    struct efx_api_s* pEfxAPI;
    struct event_api_s* pEventAPI;
    struct demo_api_s* pDemoAPI;
    struct net_api_s* pNetAPI;
    struct IVoiceTweak_s* pVoiceTweak;

    // returns 1 if the client is a spectator only (connected to a proxy), 0 otherwise or 2 if in dev_overview mode
    int                         (*IsSpectateOnly)         (void);
    struct model_s* (*LoadMapSprite)          (const char* filename);

    // file search functions
    void                        (*COM_AddAppDirectoryToSearchPath) (const char* pszBaseDir, const char* appName);
    int                         (*COM_ExpandFilename)              (const char* fileName, char* nameOutBuffer, int nameOutBufferSize);

    // User info
    // playerNum is in the range (1, MaxClients)
    // returns NULL if player doesn't exit
    // returns "" if no value is set
    const char* (*PlayerInfo_ValueForKey)          (int playerNum, const char* key);
    void                        (*PlayerInfo_SetValueForKey)       (const char* key, const char* value);

    // Gets a unique ID for the specified player. This is the same even if you see the player on a different server.
    // iPlayer is an entity index, so client 0 would use iPlayer=1.
    // Returns false if there is no player on the server in the specified slot.
    qboolean(*GetPlayerUniqueID)      (int iPlayer, char playerID[16]);

    // TrackerID access
    int                         (*GetTrackerIDForPlayer)  (int playerSlot);
    int                         (*GetPlayerForTrackerID)  (int trackerID);

    // Same as pfnServerCmd, but the message goes in the unreliable stream so it can't clog the net stream
    // (but it might not get there).
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

    //this will always fail with the current engine
    int                         (*pfnGetSequenceByName)   (int flags, const char* seq);

    void                        (*pfnSPR_DrawGeneric)     (int frame, int x, int y, const wrect_t* prc, int blendsrc, int blenddst, int unknown1, int unknown2);

    //this will always fail with engine, don't call
    //it actually has paramenters but i dunno what they do
    void                        (*pfnLoadSentence)        (void);

    //localizes hud string, uses Legacy font from skin def
    // also supports unicode strings
    int                         (*pfnDrawLocalizedHudString)    (int x, int y, const char* str, int r, int g, int b);

    //i can't get this to work for some reason, don't use this
    int                         (*pfnDrawLocalizedConsoleString)(int x, int y, const char* str);

    //gets keyvalue for local player, useful for querying vgui menus or autohelp
    const char* (*LocalPlayerInfo_ValueForKey)  (const char* key);

    //another vgui2 text drawing function, i dunno how it works
    //it doesn't localize though
    void                        (*pfnDrawText_0)                (int x, int y, const wchar_t* text, unsigned long font);

    int                         (*pfnDrawUnicodeCharacter)      (int x, int y, short number, int r, int g, int b, unsigned long hfont);

    //checks sound header of a sound file, determines if its a supported type
    int                         (*pfnCheckSoundFile)            (const char* path);

    //for condition zero, returns interface from GameUI
    void* (*GetCareerGameInterface)       (void);
    void                        (*pfnCvar_Set)                  (const char* cvar, const char* value);

    //this actually checks for if the CareerGameInterface is found
    //and if a server is being run
    int                         (*IsSinglePlayer)               (void);

    void                        (*pfnPlaySound)                 (const char* sound, float vol, float pitch);

    void                        (*pfnPlayMp3)                   (const char* mp3, int flags);

    //get the systems current time as a float
    float                       (*Sys_FloatTime)                (void);

    void                        (*pfnSetArray)                  (int* array, int size);
    void                        (*pfnSetClearArray)             (int* array, int size);
    void                        (*pfnClearArray)                (void);

    void                        (*pfnPlaySound2)                (const char* sound, float vol, float pitch);

    void                        (*pfnTintRGBA)                  (int x, int y, int width, int height, int r, int g, int b, int a);
} original_cl_enginefuncs_t;

// Reverse engineered by Jusic (06.12.18)
// Updated by Neko (21.10.2022)
typedef struct new_cl_enginefuncs_s : original_cl_enginefuncs_t {
    // CSO trash
    void  (*Unknown2)                  ();
    const char* (*GetCurrentAlias)     ();
    void  (*SPR_DrawHolesScaled)       (int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    void  (*SPR_Replace)               (int a2, int a3);
    void  (*SPR_DrawAdditiveScaled)    (int a1, int a2, int a3, int a4, int a5, int a6, int a7); // CHN151208 after not exists
    void  (*LeaveGameRoom)             (int a1, int a2);
    void  (*CheckForBadWord)           (int a1); // ????
    int   (*CheckServerChannelMgr)     (); // result != 0??
    bool  (*CheckServerChannelMgr2)    (); // check 2 8 7 type?
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
    void  (*Unknown25)                 (BYTE* a1);
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
} new_cl_enginefunc_t;