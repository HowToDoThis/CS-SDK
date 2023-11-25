struct IBaseInterface_vtbl
{
  void (__thiscall *~IBaseInterface)(struct IBaseInterface *this);
};

struct __cppobj IBaseInterface
{
  IBaseInterface_vtbl* __vftable;
};

typedef IBaseInterface *(*CreateInterfaceFn)(const char *pName, int *pReturnCode);

struct PacketListener_vtbl
{
    void (__thiscall* ~PacketListener)(struct PacketListener* ptr);
};

struct __cppobj PacketListener
{
    PacketListener_vtbl* __vftable;
};

typedef void *FileHandle_t;
typedef int FileFindHandle_t;
typedef int WaitForResourcesHandle_t;

typedef enum
{
	FILESYSTEM_SEEK_HEAD,
	FILESYSTEM_SEEK_CURRENT,
	FILESYSTEM_SEEK_TAIL,
} FileSystemSeek_t;
typedef enum
{
	FILESYSTEM_WARNING = -1,					// A problem!
	FILESYSTEM_WARNING_QUIET,				// Don't print anything
	FILESYSTEM_WARNING_REPORTUNCLOSED,			// On shutdown, report names of files left unclosed
	FILESYSTEM_WARNING_REPORTUSAGE,				// Report number of times a file was opened, closed
	FILESYSTEM_WARNING_REPORTALLACCESSES		// Report all open/close events to console (!slow!)
} FileWarningLevel_t;
typedef void (*WarningFunc_t)(const char *fmt, ...);

struct IFileSystem : IBaseInterface
{
	void (* Mount)(void);
	void (* Unmount)(void);
	void (* RemoveAllSearchPaths)(void);
	void (__thiscall* AddSearchPath)(struct CFileSystem_Nar* ptr, const char *pPath, const char *pathID);
	bool (__thiscall* RemoveSearchPath)(struct CFileSystem_Nar* ptr, const char *pPath);
	void (__thiscall* RemoveFile)(struct CFileSystem_Nar* ptr, const char *pRelativePath, const char *pathID);
	void (__thiscall* CreateDirHierarchy)(struct CFileSystem_Nar* ptr, const char *path, const char *pathID);
	bool (__thiscall* FileExists)(struct CFileSystem_Nar* ptr, const char *pFileName);
	bool (__thiscall* IsDirectory)(struct CFileSystem_Nar* ptr, const char *pFileName);
	FileHandle_t (__thiscall* Open)(struct CFileSystem_Nar* ptr, const char *pFileName, const char *pOptions, const char *pathID);
	void (__thiscall* Close)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	void (__thiscall* Seek)(struct CFileSystem_Nar* ptr, FileHandle_t file, int pos, FileSystemSeek_t seekType);
	unsigned (__thiscall* Tell)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	unsigned (__thiscall* Size)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	unsigned (__thiscall* Size2)(struct CFileSystem_Nar* ptr, const char *pFileName);
	long (__thiscall* GetFileTime)(struct CFileSystem_Nar* ptr, const char *pFileName);
	void (__thiscall* FileTimeToString)(struct CFileSystem_Nar* ptr, char *pStrip, int maxCharsIncludingTerminator, long fileTime);
	bool (__thiscall* IsOk)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	void (__thiscall* Flush)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	bool (__thiscall* EndOfFile)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	int (__thiscall* Read)(struct CFileSystem_Nar* ptr, void *pOutput, int size, FileHandle_t file);
	int (__thiscall* Write)(struct CFileSystem_Nar* ptr, void const *pInput, int size, FileHandle_t file);
	char *(__thiscall* ReadLine)(struct CFileSystem_Nar* ptr, char *pOutput, int maxChars, FileHandle_t file);
	int (__thiscall* FPrintf)(struct CFileSystem_Nar* ptr, FileHandle_t file, char *pFormat, ...);
	char *(__thiscall* GetReadBuffer)(struct CFileSystem_Nar* ptr, FileHandle_t file, char *pBuffer);
	void (__thiscall* ReleaseReadBuffer)(struct CFileSystem_Nar* ptr, FileHandle_t file, char *pBuffer);
	const char *(__thiscall* FindFirst)(struct CFileSystem_Nar* ptr, const char *pWildCard, FileFindHandle_t *pHandle, const char *pathID);
	const char *(__thiscall* FindNext)(struct CFileSystem_Nar* ptr, FileFindHandle_t handle);
	bool (__thiscall* FindIsDirectory)(struct CFileSystem_Nar* ptr, FileFindHandle_t handle);
	void (__thiscall* FindClose)(struct CFileSystem_Nar* ptr, FileFindHandle_t handle);
	void (__thiscall* GetLocalCopy)(struct CFileSystem_Nar* ptr, const char *pFileName);
	const char *(__thiscall* GetLocalPath)(struct CFileSystem_Nar* ptr, const char *pFileName, char *pLocalPath, int maxlen);
	char *(__thiscall* ParseFile)(struct CFileSystem_Nar* ptr, char *data, char *token, bool *wasquoted);
	bool (__thiscall* FullPathToRelativePath)(struct CFileSystem_Nar* ptr, const char *pFullpath, char *pRelative);
	bool (__thiscall* GetCurrentDirectory)(struct CFileSystem_Nar* ptr, char *pDirectory, int maxlen);
	void (* PrintOpenedFiles)(void);
	void (__thiscall* SetWarningFunc)(struct CFileSystem_Nar* ptr, void (*pfnWarning)(const char *fmt, ...));
	void (__thiscall* SetWarningLevel)(struct CFileSystem_Nar* ptr, FileWarningLevel_t level);
	void (__thiscall* LogLevelLoadStarted)(struct CFileSystem_Nar* ptr, const char *name);
	void (__thiscall* LogLevelLoadFinished)(struct CFileSystem_Nar* ptr, const char *name);
	int (__thiscall* HintResourceNeed)(struct CFileSystem_Nar* ptr, const char *hintlist, int forgetEverything);
	int (* PauseResourcePreloading)(void);
	int (* ResumeResourcePreloading)(void);
	int (__thiscall* SetVBuf)(struct CFileSystem_Nar* ptr, FileHandle_t stream, char *buffer, int mode, long size);
	void (__thiscall* GetInterfaceVersion)(struct CFileSystem_Nar* ptr, char *p, int maxlen);
	bool (__thiscall* IsFileImmediatelyAvailable)(struct CFileSystem_Nar* ptr, const char *path);
	void *(__thiscall* WaitForResources)(struct CFileSystem_Nar* ptr, const char *pFileName);
	bool (__thiscall* GetWaitForResourcesProgress)(struct CFileSystem_Nar* ptr, WaitForResourcesHandle_t handle, float *progress, bool *complete);
	void (__thiscall* CancelWaitForResources)(struct CFileSystem_Nar* ptr, WaitForResourcesHandle_t handle);
	bool (* IsAppReadyForOfflinePlay)(void);
	void (__thiscall* AddPackFile)(struct CFileSystem_Nar* ptr, const char *pPath, const char *pathID);
	void *(__thiscall* OpenFromCacheForRead)(struct CFileSystem_Nar* ptr, const char *pFileName, const char *pOptions, const char *pathID);
	// CSO Functions
	void  (__thiscall* LoadNar)(struct CFileSystem_Nar* ptr, const char* pFileName, const char* pathID);
	void  (__thiscall* SetNarFilePath)(struct CFileSystem_Nar* ptr, const char* dataPath);
	void  (__thiscall* Unknown03)(struct CFileSystem_Nar* ptr, const char* pFileName, char* a1);
	int   (__thiscall* GetChecksum)(struct CFileSystem_Nar* ptr);
	void  (__thiscall* NarOpen)(struct CFileSystem_Nar* ptr, const char* filePath, const char* mode, const char* pathID);
	int   (__thiscall* Unknown05)(struct CFileSystem_Nar* ptr, int(__thiscall*** a1)(void*, int));
	void  (__thiscall* NarSeek)(struct CFileSystem_Nar* ptr, int a1, int a2, int a3, int a4);
	void  (__thiscall* NarTell)(struct CFileSystem_Nar* ptr, int a1);
	void  (__thiscall* Unknown08)(struct CFileSystem_Nar* ptr, int a1);
	void  (__thiscall* Unknown09)(struct CFileSystem_Nar* ptr, int a1, int a2, int a3, int a4);
	void  (__thiscall* Unknown10)(struct CFileSystem_Nar* ptr, int a1, int a2, int a3, void* a4);
	void  (* Unknown11)();
	void  (* Unknown12)();
	void  (* Unknown13)();
	char* (__thiscall* NarReadLine)(struct CFileSystem_Nar* ptr, char* a1, int a2, int a3);
	void  (__thiscall* NarStat)(struct CFileSystem_Nar* ptr, char* FileName, struct _stat32* Stat);
	void  (__thiscall* FindFirstFile2)(struct CFileSystem_Nar* ptr, LPCSTR lpFileName, void* lpFindFileData);
	void  (__thiscall* FindNextFile2)(struct CFileSystem_Nar* ptr, HANDLE hFindFile, void* lpFindFileData);
	void  (__thiscall* FindClose2)(struct CFileSystem_Nar* ptr, HANDLE hFile);
	void  (__thiscall* Unknown15)(struct CFileSystem_Nar* ptr, void* a1);
};

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
    void (__thiscall* Func17)(struct CGameUI* this, int);
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

struct CGameUIFunc_vfunc : IBaseInterface {
    bool (__thiscall* IsKeyDown)(struct CGameUIFunc* this, const char* keyname, bool& isdown);
    const char* (__thiscall* Key_NameForKey)(struct CGameUIFunc* this, int keynum);
    const char* (__thiscall* Key_BindingForKey)(struct CGameUIFunc* this, int keynum);
    void (__thiscall* GetVGUI2KeyCodeForBind)(struct CGameUIFunc* this, const char* bind);
    void (__thiscall* GetVideoModes)(struct CGameUIFunc* this, struct vmode_s** liststart, int* count);
    void (__thiscall* GetCurrentVideoMode)(struct CGameUIFunc* this, int* wide, int* tall, int* bpp);
    void (__thiscall* GetCurrentRenderer)(struct CGameUIFunc* this, char* name, int namelen, int* windowed);
    void (__thiscall* IsConnectedToVACSecureServer)(struct CGameUIFunc* this);
};

struct CGameUIFunc {
    CGameUIFunc_vfunc* vfptr;
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
    BOOL (__thiscall* Load)(struct CEngine* this, BOOL dedicated, char* basedir, char* cmdline);
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
    void (__thiscall* AddFriend)(struct CSOCoreSDM* this);
    void (__thiscall* DeleteFriend)(struct CSOCoreSDM* this);
    void (__thiscall* CallFriendMgrUnk)(struct CSOCoreSDM* this);
    void (__thiscall* CallCNMGetNoteBox2)(struct CSOCoreSDM* this);
    void (__thiscall* CallUnk1)(struct CSOCoreSDM* this);
    void (__thiscall* CallUnk2)(struct CSOCoreSDM* this);
    void (__thiscall* GetNMCO7)(struct CSOCoreSDM* this);
    void (__thiscall* SendNoteMsg)(struct CSOCoreSDM* this);
    void (__thiscall* SetNoteReadFlag)(struct CSOCoreSDM* this);
    void (__thiscall* DeleteNote)(struct CSOCoreSDM* this);
    void (__thiscall* DeleteNoteAll)(struct CSOCoreSDM* this);
    void (__thiscall* DeleteNoteAndReload)(struct CSOCoreSDM* this);
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
    void (__thiscall* SetAuthMgr9)(struct CSOCoreSDM* this, void ***);
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
    void (__thiscall* VerifyCaptcha)(struct CSOCoreSDM* this, const char* userName);
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
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    char unk6;
    int unk7;
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
    bool (__thiscall* LoadFromFile)(struct KeyValues* this, struct CFileSystem_Nar* filesystem, const char* resourceName, const char* pathID = NULL);
    bool (__thiscall* SaveToFile)(struct KeyValues* this);
    struct KeyValues* (__thiscall* FindKey1)(struct KeyValues* this, int keySymbol);
    struct KeyValues* (__thiscall* FindKey2)(struct KeyValues* this, const char *keyName, bool bCreate);
    struct KeyValues* (__thiscall* CreateNewKey)(struct KeyValues* this);
    void (__thiscall* AddSubKey)(struct KeyValues* this, struct KeyValues* pSubkey);
    struct KeyValues* (__thiscall* GetFirstSubKey)(struct KeyValues* this);
    struct KeyValues* (__thiscall* GetNextKey)(struct KeyValues* this);
    int (__thiscall* GetInt)(struct KeyValues* this, const char *keyName, int defaultValue);
    float (__thiscall* GetFloat)(struct KeyValues* this, const char *keyName, float defaultValue);
    char*    (__thiscall* GetString) (struct KeyValues* this, const char *keyName, const char* defaultValue);
    wchar_t* (__thiscall* GetWString)(struct KeyValues* this, const char *keyName, const wchar_t* defaultValue);
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

// direct references to localized strings
typedef unsigned long StringIndex_t;
struct ILocalize : IBaseInterface {
    bool (__thiscall* AddFile)(struct ILocalize* ptr, IFileSystem *fileSystem, const char *fileName);
    void (__thiscall* RemoveAll)(struct ILocalize* this);
    wchar_t* (__thiscall* Find)(struct ILocalize* this, const char* tokenName);
    int (__thiscall* ConvertANSIToUnicode)(struct ILocalize* this, const char *ansi, wchar_t *unicode, int unicodeBufferSizeInBytes);
    int (__thiscall* ConvertUnicodeToANSI)(struct ILocalize* this, const wchar_t *unicode, char *ansi, int ansiBufferSize);
    StringIndex_t (__thiscall* FindIndex)(struct ILocalize* this, const char *tokenName);
    void (__thiscall* ConstructString)(struct ILocalize* this);
    void (__thiscall* GetNameByIndex)(struct ILocalize* this);
    void (__thiscall* GetValueByIndex)(struct ILocalize* this);
    void (__thiscall* GetFirstStringIndex)(struct ILocalize* this);
    void (__thiscall* GetNextStringIndex)(struct ILocalize* this);
    void (__thiscall* AddString)(struct ILocalize* this);
    void (__thiscall* SetValueByIndex)(struct ILocalize* this);
    void (__thiscall* SaveToFile)(struct ILocalize* this);
    void (__thiscall* GetLocalizationFileCount)(struct ILocalize* this);
    void (__thiscall* GetLocalizationFileName)(struct ILocalize* this);
    void (__thiscall* GetFileNameByIndex)(struct ILocalize* this);
    void (__thiscall* ReloadLocalizationFiles)(struct ILocalize* this);
    void (__thiscall* ConstructString1)(struct ILocalize* this);
    void (__thiscall* ConstructString2)(struct ILocalize* this);
};

struct CLocalizedStringTable
{
    ILocalize* vfptr;
};

struct ISystem : IBaseInterface {
    void (__thiscall* Shutdown)(struct ISystem* this);
    void (__thiscall* RunFrame)(struct ISystem* this);
    void (__thiscall* ShellExecute)(struct ISystem* this, const char *command, const char *file);
    double (__thiscall* GetFrameTime)(struct ISystem* this);
    double (__thiscall* GetCurrentTime)(struct ISystem* this);
    void (__thiscall* GetTimeMillis)(struct ISystem* this);
    void (__thiscall* Function7)(struct ISystem* this);
    void (__thiscall* Function8)(struct ISystem* this);
    void (__thiscall* Function9)(struct ISystem* this);
    void (__thiscall* Function10)(struct ISystem* this);
    void (__thiscall* Function11)(struct ISystem* this);
    void (__thiscall* Function12)(struct ISystem* this);
    void (__thiscall* Function13)(struct ISystem* this);
    void (__thiscall* Function14)(struct ISystem* this);
    void (__thiscall* Function15)(struct ISystem* this);
    void (__thiscall* Function16)(struct ISystem* this);
    void (__thiscall* Function17)(struct ISystem* this);
    void (__thiscall* Function18)(struct ISystem* this);
    void (__thiscall* Function19)(struct ISystem* this);
    void (__thiscall* Function20)(struct ISystem* this);
    void (__thiscall* Function21)(struct ISystem* this);
    void (__thiscall* Function22)(struct ISystem* this);
    void (__thiscall* Function23)(struct ISystem* this);
    void (__thiscall* Function24)(struct ISystem* this);
    void (__thiscall* Function25)(struct ISystem* this);
    void (__thiscall* Function26)(struct ISystem* this);
    void (__thiscall* Function27)(struct ISystem* this);
    void (__thiscall* Function28)(struct ISystem* this);
    void (__thiscall* Function29)(struct ISystem* this);
    void (__thiscall* Function30)(struct ISystem* this);
    void (__thiscall* Function31)(struct ISystem* this);
    void (__thiscall* Function32)(struct ISystem* this);
    void (__thiscall* Function33)(struct ISystem* this);
    void (__thiscall* Function34)(struct ISystem* this);
    void (__thiscall* Function35)(struct ISystem* this);
    void (__thiscall* Function36)(struct ISystem* this);
};

struct CSystem {
    ISystem* vfptr;
};

struct ChattingManager_vt
{
    void (__thiscall* FormatClanMsg)(struct ChattingManager* this, wchar_t* msg, int a3); // CSONMEventListener::Func11, etc
    void (__thiscall* InitUnk5)(struct ChattingManager* this);
    void (__thiscall* ChatFilter)(struct ChattingManager* this);
    void (__thiscall* Function4)(struct ChattingManager* this);
    void (__thiscall* Function5)(struct ChattingManager* this);
    void (__thiscall* Function6)(struct ChattingManager* this);
    void (__thiscall* RegisterFunction)(struct ChattingManager* this);
    void (__thiscall* Function8)(struct ChattingManager* this);
    void (__thiscall* Function9)(struct ChattingManager* this);
    void (__thiscall* FormatMsg)(struct ChattingManager* this, const char* gameName, const char* message, char a4, int type);
    void (__thiscall* Function11)(struct ChattingManager* this);
    void (__thiscall* Function12)(struct ChattingManager* this);
    void (__thiscall* ReturnThis296)(struct ChattingManager* this);
    void (__thiscall* Function14)(struct ChattingManager* this);
    void (__thiscall* IsInventoryHasChannelChat)(struct ChattingManager* this, int *type);
    void (__thiscall* IsInventoryHasServerYell)(struct ChattingManager* this, int *type);
    void (__thiscall* Function17)(struct ChattingManager* this);
    void (__thiscall* UseServerYell)(struct ChattingManager* this, int a2);
    void (__thiscall* Function19)(struct ChattingManager* this);
    void (__thiscall* SendSomethingAsServerYell)(struct ChattingManager* this);
    void (__thiscall* ReturnUnkShits)(struct ChattingManager* this);
    void (__thiscall* ShowMessageBox)(struct ChattingManager* this, wchar_t* msg, int a3 = 0);
    void (__thiscall* CheckWords)(struct ChattingManager* this);
    void (__thiscall* CNMRequestChatSessionEx)(struct ChattingManager* this);
    int  (__thiscall* Function25)(struct ChattingManager* this); // CSONMEventListener::Func13
    void (__thiscall* CNMCSSendChatMessage)(struct ChattingManager* this);
    int  (__thiscall* Function27)(struct ChattingManager* this);
    int  (__thiscall* Function28)(struct ChattingManager* this);
    void (__thiscall* CNMGSWantClose)(struct ChattingManager* this);
    void (__thiscall* FriendRelated1)(struct ChattingManager* this);
    void (__thiscall* FriendRelated2)(struct ChattingManager* this);
};

struct ChattingManager_PacketListener_vtbl : PacketListener
{};

struct ChattingManager
{
    ChattingManager_vt* vfptr;
    ChattingManager_PacketListener_vtbl* vfptr_listener;

    vector unk1;

    int unk2;
    struct BadWordsManager* gBadWordsManager;
    struct AbuseMessageBlocker* gAbuseMessageBlocker;
    int unk5;
    int unk6; // something uses 16524 size...????
    wchar_t msg[0x80];    
    short unk7;
};