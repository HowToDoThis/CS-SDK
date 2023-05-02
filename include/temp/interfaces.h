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

typedef enum LanguageCode {
    kr0,
    kr1,
    chn,
    tw,
    jpn,
    sgp,
    idn,
    th,
    tur,
    vn,
};

struct CLanguage
{
    char langName[16];
    LanguageCode langCode;
};

struct CSOCoreSDM
{
    int unk1; // vector
    int unk2;
    int unk3;

    int unk4;

    int unk5; // vector
    int unk6;
    int unk7;

    int unk8;
};
