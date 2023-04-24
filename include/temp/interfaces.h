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
	bool  (*CGame::Shutdown)();
    void  (__thiscall* CGame::ShutdownCSO)(struct CGame* this);
	bool  (*CGame::CreateGameWindow)();
	void  (__thiscall* CGame::SleepUntilInput)(struct CGame* this, int time);
	HWND  (*CGame::GetMainWindow)();
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
    char m_bActiveApp;
    HANDLE handle;
    HWND window;
    HINSTANCE instance;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    short unk5;
    int unk6;
    char unk7;
};

struct CBaseUI_vt : IBaseInterface
{
    void (__thiscall* Initialize)(struct CBaseUI* this, CreateInterfaceFn* factories, int count);
    void (__thiscall* Start)(struct CBaseUI* this, cl_enginefunc_t* engineFuncs, int interfaceVersion);
    void (__thiscall* Shutdown)(struct CBaseUI* this);
    bool (__thiscall* Key_Event)(struct CBaseUI* this, int down, int keynum, const char* pszCurrentBinding);
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
    int (* ContinueProgressBar)(int progressPoint, float progressFraction);
    void (__thiscall* StopProgressBar)(struct CGameUI* this, bool bError, const char* failureReason, const char* extendedReason);
    void (__thiscall* SetProgressBarStatusText)(struct CGameUI* this, const char* statusText);
    void (__thiscall* SetSecondaryProgressBar)(struct CGameUI* this, float progress);
    void (__thiscall* SetSecondaryProgressBarText)(struct CGameUI* this, const char* statusText);
    void (__thiscall* ValidateCDKey)(struct CGameUI* this, bool force, bool inConnect);
    void (__thiscall* OnDisconnectFromServer)(struct CGameUI* this, int eSteamLoginFailure, const char* username);
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