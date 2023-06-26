struct IBaseInterface_vtbl
{
  void (__thiscall *~IBaseInterface)(struct IBaseInterface *this);
};

struct __cppobj IBaseInterface
{
  IBaseInterface_vtbl* __vftable;
};

typedef IBaseInterface *(*CreateInterfaceFn)(const char *pName, int *pReturnCode);

struct CGame_vfunc : IBaseInterface
{
    bool  (__thiscall* CGame::Init)(struct CGame* this, void *pvInstance);
    void  (__thiscall* CGame::Function1)(struct CGame* this, int unk);
    void  (__thiscall* CGame::Function2)(struct CGame* this);
    bool  (__thiscall* CGame::Shutdown)(struct CGame* this);
    void  (__thiscall* CGame::ShutdownCSO)(struct CGame* this);
    bool  (__thiscall* CGame::CreateGameWindow)(struct CGame* this);
    void  (__thiscall* CGame::SleepUntilInput)(struct CGame* this, int time);
    HWND  (__thiscall* CGame::GetMainWindow)(struct CGame* this);
    HWND* (*CGame::GetMainWindowAddress)();
    void  (__thiscall* CGame::SetWindowXY)(struct CGame* this, int x, int y);
    void  (__thiscall* CGame::SetWindowSize)(struct CGame* this, int w, int h);
    void  (__thiscall* CGame::GetWindowRect)(struct CGame* this, int *x, int *y, int *w, int *h);
    bool  (*CGame::IsActiveApp)();
    bool  (*CGame::IsMultiplayer)();
    void  (*CGame::PlayStartupVideos)();
    void  (__thiscall* CGame::PlayAVIAndWait)(struct CGame* this, const char *aviFile);
};

struct CGame
{
    CGame_vfunc* vfptr;
    char unk0;
    HANDLE handle;
    HWND window;
    HINSTANCE instance;
    int x;
    int y;
    int width;
    int height;
    bool m_bActiveApp;
    bool m_bMultiplayer;
    int mouseWheelMessage;
    char unk7;
};

struct CBaseUI_vt : IBaseInterface
{
    void (__thiscall* Initialize)(struct CBaseUI* this, CreateInterfaceFn* factories, int count);
    void (__thiscall* Start)(struct CBaseUI* this, cl_enginefunc_t* engineFuncs, int interfaceVersion);
    void (__thiscall* Shutdown)(struct CBaseUI* this);
    int  (__thiscall* Key_Event)(struct CBaseUI* this, int down, int keynum, const char* pszCurrentBinding);
    void (__thiscall* CallEngineSurfaceAppHandler)(struct CBaseUI* this, void* pEvent, void* pUserData);
    void (__thiscall* Paint)(struct CBaseUI* this, int x, int y, int right, int bottom);
    void (__thiscall* HideGameUI)(struct CBaseUI* this);
    void (__thiscall* ActivateGameUI)(struct CBaseUI* this);
    void (__thiscall* HideConsole)(struct CBaseUI* this);
    void (__thiscall* ShowConsole)(struct CBaseUI* this);
};

struct CBaseUI
{
    CBaseUI_vt* vfptr;
    CreateInterfaceFn mFactoryList[6];
    int iNumFactories;

    HMODULE* m_hGameUIModule;
    bool m_bHidingGameUI;
};

struct CGameUI_vt : IBaseInterface
{
    void (__thiscall* Initialize)(struct CGameUI* this, CreateInterfaceFn* factories, int count);
    void (__thiscall* Start)(struct CGameUI* this, cl_enginefunc_t* engineFuncs, int interfaceVersion, struct IBaseSystem* system);
    void (__thiscall* Shutdown)(struct CGameUI* this);
    void (__thiscall* ActivateGameUI)(struct CGameUI* this);
    void (__thiscall* ActivateDemoUI)(struct CGameUI* this);
    void (__thiscall* HasExclusiveInput)(struct CGameUI* this);
    void (__thiscall* RunFrame)(struct CGameUI* this);
    void (__thiscall* ConnectToServer)(struct CGameUI* this, const char* game, int IP, int port);
    void (__thiscall* DisconnectFromServer)(struct CGameUI* this);
    void (__thiscall* HideGameUI)(struct CGameUI* this);
    void (__thiscall* IsGameUIActive)(struct CGameUI* this);
    void (__thiscall* LoadingStarted)(struct CGameUI* this, const char* resourceType, const char* resourceName);
    void (__thiscall* LoadingFinished)(struct CGameUI* this, const char* resourceType, const char* resourceName);
    void (__thiscall* StartProgressBar)(struct CGameUI* this, const char* progressType, int progressSteps);
    int  (* ContinueProgressBar)(int progressPoint, float progressFraction);
    void (__thiscall* StopProgressBar)(struct CGameUI* this, bool bError, const char* failureReason, const char* extendedReason);
    int  (__thiscall* SetProgressBarStatusText)(struct CGameUI* this, const char* statusText);
    void (__thiscall* SetSecondaryProgressBar)(struct CGameUI* this, float progress);
    void (__thiscall* SetSecondaryProgressBarText)(struct CGameUI* this, const char* statusText);
    void (__thiscall* ValidateCDKey)(struct CGameUI* this, bool force, bool inConnect);
    void (__thiscall* OnDisconnectFromServer)(struct CGameUI* this, int eSteamLoginFailure, const char* username);
    // CSO ADDED
    void (__thiscall* Func1)(struct CGameUI* this);
    void (__thiscall* Func2)(struct CGameUI* this);
    void (__thiscall* Func3)(struct CGameUI* this);
    void (__thiscall* Func4)(struct CGameUI* this, int unk);
    void (__thiscall* Func5)(struct CGameUI* this);
    void (__thiscall* Func6)(struct CGameUI* this);
    int  (__thiscall* Func7)(struct CGameUI* this);
    void (__thiscall* Func8)(struct CGameUI* this);
    void (__thiscall* Func9)(struct CGameUI* this);
    void (__thiscall* Func10)(struct CGameUI* this);
    void (__thiscall* Func11)(struct CGameUI* this);
    void (__thiscall* Func12)(struct CGameUI* this);
    void (__thiscall* Func13)(struct CGameUI* this);
    void (__thiscall* Func14)(struct CGameUI* this);
    void (__thiscall* Func15)(struct CGameUI* this);
    void (__thiscall* Func16)(struct CGameUI* this);
    void (__thiscall* Func17)(struct CGameUI* this);
    void (__thiscall* Func18)(struct CGameUI* this);
    void (__thiscall* Func19)(struct CGameUI* this);
    void (__thiscall* Func20)(struct CGameUI* this);
    void (__thiscall* Func21)(struct CGameUI* this, const char* title, const char* message, int code);
};

struct CGameUI
{
    CGameUI_vt* vfptr;
    void* vfptr2; // IBuffListener
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9;
    char unk10;
    
    int big1[71];
    
    int unk11;
    int unk12;
    char unk13;
    int unk14; // not showing
    int unk15; // string
    int unk16;

    int big2[4];

    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    char unk28;
};

struct CGameConsole_vt : IBaseInterface
{
    void (__thiscall* Activate)(struct CGameConsole* this);
    void (__thiscall* Initialize)(struct CGameConsole* this);
    void (__thiscall* Hide)(struct CGameConsole* this);
    void (__thiscall* Clear)(struct CGameConsole* this);
    void (__thiscall* IsConsoleVisible)(struct CGameConsole* this);
    void (__thiscall* Printf)(struct CGameConsole* this, const char* format, ...);
    void (__thiscall* DPrintf)(struct CGameConsole* this, const char* format, ...);
    void (__thiscall* SetParent)(struct CGameConsole* this, struct vgui2::VPANEL* parent);
};

struct CGameConsole
{
    CGameConsole_vt* vfptr;
};

struct CThread_vt
{

};

struct CThread
{
    CThread_vt* vfptr;
    HANDLE event;
    CRITICAL_SECTION critical;
    char unk2;
    char unk3;
    short unk4;
    int undef2[68];
    HANDLE thread;
    int unk6;
};

struct CEngine_vt : IBaseInterface
{
    void (__thiscall* Load)(struct CEngine* this, bool dedicated, char* basedir, char* cmdline);
    void (__thiscall* Unload)(struct CEngine* this);
    void (__thiscall* SetState)(struct CEngine* this, int state);
    void (__thiscall* GetState)(struct CEngine* this);
    void (__thiscall* SetSubState)(struct CEngine* this);
    void (__thiscall* GetSubState)(struct CEngine* this);
    void (__thiscall* Frame)(struct CEngine* this);
    void (__thiscall* GetFrameTime)(struct CEngine* this);
    void (__thiscall* GetCurTime)(struct CEngine* this);
    void (__thiscall* TrapKey_Event)(struct CEngine* this, int key, bool down);
    void (__thiscall* TrapMouse_Event)(struct CEngine* this);
    void (__thiscall* StartTrapMode)(struct CEngine* this);
    bool (__thiscall* IsTrapping)(struct CEngine* this);
    void (__thiscall* CheckDoneTrapping)(struct CEngine* this);
    int  (__thiscall* GetQuitting)(struct CEngine* this);
    void (__thiscall* SetQuitting)(struct CEngine* this, int quitType);
};

struct CEngine
{
    CEngine_vt* vfptr;
    int m_nQuitting;
    int m_nDLLState;
    int m_nSubState;
    double m_fCurTime;
    double m_fFrameTime;
    double m_fOldTime;
    char m_bTrapMode;
    char m_bDoneTrapping;
    short unk5;
    int m_nTrapKey;
    int m_nTrapButtons;
    int undef3;
};

struct CSOCoreSDM_vt : IBaseInterface
{
    void (__thiscall* Init)(struct CSOCoreSDM* this);
    void (__thiscall* Shutdown)(struct CSOCoreSDM* this);
    void (__thiscall* CallServerChannelMgr3)(struct CSOCoreSDM* this);
    void (__thiscall* CallServerChannelMgr3_2)(struct CSOCoreSDM* this);
    void (__thiscall* Function5)(struct CSOCoreSDM* this);
    void (__thiscall* CallFriendMgr2)(struct CSOCoreSDM* this);
    void (__thiscall* SetFriendMgr)(struct CSOCoreSDM* this);
    void (__thiscall* DeleteFriend)(struct CSOCoreSDM* this);
    void (__thiscall* CallFriendMgrUnk)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMGetNoteBox2)(struct CSOCoreSDM* this);
    void (__thiscall* CallUnk1)(struct CSOCoreSDM* this);
    void (__thiscall* CallUnk2)(struct CSOCoreSDM* this);
    void (__thiscall* GetNMCO7)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMSendNoteMsgFunc)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMProcessNote)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMProcessNoteShit1)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMProcessNoteShit2)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMProcessNoteShit3)(struct CSOCoreSDM* this);
    void (__thiscall* SetServerChannelMgr5)(struct CSOCoreSDM* this, int);
    void (__thiscall* SetServerChannelMgr6)(struct CSOCoreSDM* this, int serverID, int channelID);
    void (__thiscall* SendJoinRoom)(struct CSOCoreSDM* this, int roomID,int);
    void (__thiscall* SetServerChannelMgr7)(struct CSOCoreSDM* this, int);
    void (__thiscall* SetServerChannelMgr8)(struct CSOCoreSDM* this, int);
    void (__thiscall* SendCreateRoom)(struct CSOCoreSDM* this, void* keyValues, int unk);
    void (__thiscall* CallGameRoomList)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoomStart)(struct CSOCoreSDM* this);
    void (__thiscall* SendLeaveRoom)(struct CSOCoreSDM* this, int,int,int);
    void (__thiscall* CallServerChannelMgr3_0)(struct CSOCoreSDM* this);
    void (__thiscall* SendSearchRoom)(struct CSOCoreSDM* this);
    void (__thiscall* SendCreateCharacter)(struct CSOCoreSDM* this);
    void (__thiscall* CallFriendMgrShit2)(struct CSOCoreSDM* this);
    void (__thiscall* Set8)(struct CSOCoreSDM* this);
    void (__thiscall* SetGameUser20)(struct CSOCoreSDM* this);
    void (__thiscall* SetGameUser7)(struct CSOCoreSDM* this, int);
    void (__thiscall* SetGameRoomList32)(struct CSOCoreSDM* this);
    void (__thiscall* SetAuthMgr36)(struct CSOCoreSDM* this);
    void (__thiscall* GetUser1__668)(struct CSOCoreSDM* this);
    void (__thiscall* SetUserOption)(struct CSOCoreSDM* this);
    bool (__thiscall* GetAuthMgr20)(struct CSOCoreSDM* this, void* ptr);
    class CGamePlayer* (__thiscall* GetCurrentUser)(struct CSOCoreSDM* this);
    void (__thiscall* GetUser32)(struct CSOCoreSDM* this);
    void (__thiscall* SetUserUnk1)(struct CSOCoreSDM* this);
    void (__thiscall* GetUserCheck2)(struct CSOCoreSDM* this);
    void (__thiscall* SendReport5orUnk)(struct CSOCoreSDM* this);
    void (__thiscall* SendReport5or8orUnk)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoomInviteList)(struct CSOCoreSDM* this);
    void (__thiscall* GetUserFromVector)(struct CSOCoreSDM* this);
    void (__thiscall* SetUserUnk2)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoom16)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoomInvite)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoom18)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoomUnk1)(struct CSOCoreSDM* this);
    void (__thiscall* SendRoomUnk2)(struct CSOCoreSDM* this);
    void (__thiscall* SendUpdateInfoCafe)(struct CSOCoreSDM* this);
    void (__thiscall* SendUpdateInfo1)(struct CSOCoreSDM* this);
    void (__thiscall* UpdateRate)(struct CSOCoreSDM* this);
    void (__thiscall* GetNetworkConfig)(struct CSOCoreSDM* this);
    int  (__thiscall* GetLanguage)(struct CSOCoreSDM* this);
    int  (__thiscall* GetServerCategory)(struct CSOCoreSDM* this);
    int  (__thiscall* GetLanguageCode)(struct CSOCoreSDM* this);
    void (__thiscall* Login)(struct CSOCoreSDM* this);
    void (__thiscall* VerifyCaptcha)(struct CSOCoreSDM* this);
    void (__thiscall* SetAuthManager4)(struct CSOCoreSDM* this);
    void (__thiscall* CallUploadCheck)(struct CSOCoreSDM* this);
    void (__thiscall* CallTopup)(struct CSOCoreSDM* this); // maybe call topup..
    void (__thiscall* Function66)(struct CSOCoreSDM* this);
    void (__thiscall* UpdateLocation)(struct CSOCoreSDM* this);
    void (__thiscall* GetAuthManager22)(struct CSOCoreSDM* this);
    void (__thiscall* GetTypeCode)(struct CSOCoreSDM* this);
    void (__thiscall* GetAuthManager23)(struct CSOCoreSDM* this);
    void (__thiscall* Function71)(struct CSOCoreSDM* this);
    void (__thiscall* Function72)(struct CSOCoreSDM* this);
    void (__thiscall* GetMapList)(struct CSOCoreSDM* this);
    void (__thiscall* GetClientTable)(struct CSOCoreSDM* this);
    void (__thiscall* Return01)(struct CSOCoreSDM* this);
    void (__thiscall* Function76)(struct CSOCoreSDM* this);
    void (__thiscall* Unknown20)(struct CSOCoreSDM* this);
    void (__thiscall* Return02)(struct CSOCoreSDM* this);
    void (__thiscall* Function79)(struct CSOCoreSDM* this);
    void (__thiscall* UnkCallToLeaveRoom)(struct CSOCoreSDM* this);
    void (__thiscall* Return03)(struct CSOCoreSDM* this);
    void (__thiscall* SendCleanSystem)(struct CSOCoreSDM* this);
    void (__thiscall* GetUser673)(struct CSOCoreSDM* this);
    void (__thiscall* GetStatisticMgr)(struct CSOCoreSDM* this);
};

struct CSOCoreSDM
{
    CSOCoreSDM_vt* vfptr;
};

typedef int HKeySymbol;
struct IKeyValues_vt : IBaseInterface
{
    void (__thiscall* RegisterSizeofKeyValues)(struct IKeyValues* this, int size);
    void* (__thiscall* AllocKeyValuesMemory)(struct IKeyValues* this, int size);
    void (__thiscall* FreeKeyValuesMemory)(struct IKeyValues* this, void* kv);
    HKeySymbol  (__thiscall* GetSymbolForString)(struct IKeyValues* this, const char *name);
    const char* (__thiscall* GetStringForSymbol)(struct IKeyValues* this, HKeySymbol symbol);
    void (__thiscall* GetLocalizedFromANSI)(struct IKeyValues* this);
    void (__thiscall* GetANSIFromLocalized)(struct IKeyValues* this);
    void (__thiscall* AddKeyValuesToMemoryLeakList)(struct IKeyValues* this);
    void (__thiscall* RemoveKeyValuesFromMemoryLeakList)(struct IKeyValues* this);
};

struct IKeyValues
{
    IKeyValues_vt* vfptr;
};

typedef enum KeyValues::types_t
{
    TYPE_NONE = 0,
    TYPE_STRING,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_PTR,
    TYPE_WSTRING,
    TYPE_COLOR,
    TYPE_UINT64,
    TYPE_NUMTYPES, 
};

struct KeyValues_vt
{
    void (__thiscall* GetName)(struct KeyValues* this);
    int  (__thiscall* GetNameSymbol)(struct KeyValues* this);
    void (__thiscall* Function3)(struct KeyValues* this);
    void (__thiscall* SaveToFile)(struct KeyValues* this);
    struct KeyValues* (__thiscall* FindKey1)(struct KeyValues* this, int keySymbol);
    struct KeyValues* (__thiscall* FindKey2)(struct KeyValues* this, const char *keyName, bool bCreate);
    struct KeyValues* (__thiscall* CreateNewKey)(struct KeyValues* this);
    void (__thiscall* AddSubKey)(struct KeyValues* this, struct KeyValues* pSubkey);
    struct KeyValues* (__thiscall* GetFirstSubKey)(struct KeyValues* this);
    struct KeyValues* (__thiscall* GetNextKey)(struct KeyValues* this);
    int (__thiscall* GetInt)(struct KeyValues* this, const char *keyName, int defaultValue);
    float (__thiscall* GetFloat)(struct KeyValues* this, const char *keyName, float defaultValue);
    const char* (__thiscall* GetString)(struct KeyValues* this, const char *keyName, const char defaultValue);
    const wchar_t* (__thiscall* GetWString)(struct KeyValues* this, const char *keyName, const wchar_t defaultValue);
    void* (__thiscall* GetPtr)(struct KeyValues* this, const char *keyName, void* defaultValue);
    bool (__thiscall* IsEmpty)(struct KeyValues* this, int keySymbol);
    void (__thiscall* SetWString)(struct KeyValues* this, const char *keyName, const wchar_t *value);
    void (__thiscall* SetString)(struct KeyValues* this, const char *keyName, const char *value);
    void (__thiscall* SetInt)(struct KeyValues* this, const char *keyName, int value);
    void (__thiscall* SetFloat)(struct KeyValues* this, const char *keyName, float value);
    void (__thiscall* SetPtr)(struct KeyValues* this, const char *keyName, void *value);
    struct KeyValues* (__thiscall* MakeCopy)(struct KeyValues* this);
    void (__thiscall* Function23)(struct KeyValues* this);
    KeyValues::types_t (__thiscall* GetDataType)(struct KeyValues* this, const char *keyName);
    void (__thiscall* deleteThis)(struct KeyValues* this);
};

struct KeyValues
{
    KeyValues_vt* vfptr;
    int m_iKeyName;
    void* m_pValue;
    short m_iDataType;
    short m_iAllocationSize;
    KeyValues* m_pPeer;
    KeyValues* m_pSub;
};

struct CServerChannelManager_vtables : IBaseInterface
{
    void (__thiscall* Init)(struct CServerChannelManager* this);
    void (__thiscall* Shutdown)(struct CServerChannelManager* this);
    void (__thiscall* SendRequestChannel)(struct CServerChannelManager* this);
    void (__thiscall* RegisterChannels)(struct CServerChannelManager* this);
    void (__thiscall* Function6)(struct CServerChannelManager* this, int a2);
    void (__thiscall* SendRequestRoomList)(struct CServerChannelManager* this, int serverID, int serverChannelID);
    void (__thiscall* Function8)(struct CServerChannelManager* this, int a2);
    void (__thiscall* Function9)(struct CServerChannelManager* this);
};

struct CServerChannelManager
{
    CServerChannelManager_vtables* vfptr;
    void* vfptr2; // packetListener

    int unk1;
    int unk2;
    int unk3;

    int unk4; // serverInfo
    int unk5;
    int unk6;
    int unk7;
    int serverID;
    int serverChannelID;
    int serverCategory;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
};