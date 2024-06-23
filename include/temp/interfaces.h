class IBaseInterface {
public:
    virtual ~IBaseInterface() {}
};

typedef IBaseInterface *(*CreateInterfaceFn)(const char *pName, int *pReturnCode);

class PacketListener {
public:
    virtual ~PacketListener() {}
};

typedef void *FileHandle_t;
typedef int FileFindHandle_t;
typedef int WaitForResourcesHandle_t;

typedef enum {
    FILESYSTEM_SEEK_HEAD,
    FILESYSTEM_SEEK_CURRENT,
    FILESYSTEM_SEEK_TAIL,
} FileSystemSeek_t;

typedef enum {
    FILESYSTEM_WARNING = -1,             // A problem!
    FILESYSTEM_WARNING_QUIET,            // Don't print anything
    FILESYSTEM_WARNING_REPORTUNCLOSED,   // On shutdown, report names of files left unclosed
    FILESYSTEM_WARNING_REPORTUSAGE,      // Report number of times a file was opened, closed
    FILESYSTEM_WARNING_REPORTALLACCESSES // Report all open/close events to console (!slow!)
} FileWarningLevel_t;

typedef void (*WarningFunc_t)(const char *fmt, ...);

class IFileSystem : IBaseInterface {
public:
    virtual void Mount(void);
    virtual void Unmount(void);
    virtual void RemoveAllSearchPaths(void);
    virtual void AddSearchPath(const char *pPath, const char *pathID);
    virtual bool RemoveSearchPath(const char *pPath);
    virtual void RemoveFile(const char *pRelativePath, const char *pathID);
    virtual void CreateDirHierarchy(const char *path, const char *pathID);
    virtual bool FileExists(const char *pFileName);
    virtual bool IsDirectory(const char *pFileName);
    virtual FileHandle_t Open(const char *pFileName, const char *pOptions, const char *pathID);
    virtual void Close(FileHandle_t file);
    virtual void Seek(FileHandle_t file, int pos, FileSystemSeek_t seekType);
    virtual unsigned Tell(FileHandle_t file);
    virtual unsigned Size(FileHandle_t file);
    virtual unsigned Size2(const char *pFileName);
    virtual long GetFileTime(const char *pFileName);
    virtual void FileTimeToString(char *pStrip, int maxCharsIncludingTerminator, long fileTime);
    virtual bool IsOk(FileHandle_t file);
    virtual void Flush(FileHandle_t file);
    virtual bool EndOfFile(FileHandle_t file);
    virtual int Read(void *pOutput, int size, FileHandle_t file);
    virtual int Write(void const *pInput, int size, FileHandle_t file);
    virtual char *ReadLine(char *pOutput, int maxChars, FileHandle_t file);
    virtual int FPrintf(FileHandle_t file, char *pFormat, ...);
    virtual char *GetReadBuffer(FileHandle_t file, char *pBuffer);
    virtual void ReleaseReadBuffer(FileHandle_t file, char *pBuffer);
    virtual const char *FindFirst(const char *pWildCard, FileFindHandle_t *pHandle, const char *pathID);
    virtual const char *FindNext(FileFindHandle_t handle);
    virtual bool FindIsDirectory(FileFindHandle_t handle);
    virtual void FindClose(FileFindHandle_t handle);
    virtual void GetLocalCopy(const char *pFileName);
    virtual const char *GetLocalPath(const char *pFileName, char *pLocalPath, int maxlen);
    virtual char *ParseFile(char *data, char *token, bool *wasquoted);
    virtual bool FullPathToRelativePath(const char *pFullpath, char *pRelative);
    virtual bool GetCurrentDirectory(char *pDirectory, int maxlen);
    virtual void PrintOpenedFiles(void);
    virtual void SetWarningFunc(void (*pfnWarning)(const char *fmt, ...));
    virtual void SetWarningLevel(FileWarningLevel_t level);
    virtual void LogLevelLoadStarted(const char *name);
    virtual void LogLevelLoadFinished(const char *name);
    virtual int HintResourceNeed(const char *hintlist, int forgetEverything);
    virtual int PauseResourcePreloading(void);
    virtual int ResumeResourcePreloading(void);
    virtual int SetVBuf(FileHandle_t stream, char *buffer, int mode, long size);
    virtual void GetInterfaceVersion(char *p, int maxlen);
    virtual bool IsFileImmediatelyAvailable(const char *path);
    virtual void *WaitForResources(const char *pFileName);
    virtual bool GetWaitForResourcesProgress(WaitForResourcesHandle_t handle, float *progress, bool *complete);
    virtual void CancelWaitForResources(WaitForResourcesHandle_t handle);
    virtual bool IsAppReadyForOfflinePlay(void);
    virtual void AddPackFile(const char *pPath, const char *pathID);
    virtual void *OpenFromCacheForRead(const char *pFileName, const char *pOptions, const char *pathID);
    // CSO Functions
    virtual void  LoadNar(const char* pFileName, const char* pathID);
    virtual void  SetNarFilePath(const char* dataPath);
    virtual void  Unknown03(const char* pFileName, char* a1);
    virtual int   GetChecksum(struct CFileSystem_Nar* ptr);
    virtual void  NarOpen(const char* filePath, const char* mode, const char* pathID);
    virtual int   Unknown05(int(__thiscall*** a1)(void*, int));
    virtual void  NarSeek(int a1, int a2, int a3, int a4);
    virtual void  NarTell(int a1);
    virtual void  Unknown08(int a1);
    virtual void  Unknown09(int a1, int a2, int a3, int a4);
    virtual void  Unknown10(int a1, int a2, int a3, void* a4);
    virtual void  Unknown11();
    virtual void  Unknown12();
    virtual void  Unknown13();
    virtual char* NarReadLine(char* a1, int a2, int a3);
    virtual void  NarStat(char* FileName, struct _stat32* Stat);
    virtual void  FindFirstFile2(LPCSTR lpFileName, void* lpFindFileData);
    virtual void  FindNextFile2(HANDLE hFindFile, void* lpFindFileData);
    virtual void  FindClose2(HANDLE hFile);
    virtual void  Unknown15(void* a1);
};

struct CGame : IBaseInterface {
public:
    virtual bool  Init(HINSTANCE hInstance);
    virtual bool  InitCSONMWrapper();
    virtual void  InitCSOCoreSDM();
    virtual bool  ShutdownCSOCoreSDM();
    virtual void  Shutdown();
    virtual bool  CreateGameWindow();
    virtual void  SleepUntilInput(int time);
    virtual HWND  GetMainWindow();
    virtual HWND* GetMainWindowAddress();
    virtual void  SetWindowXY(int x, int y);
    virtual void  SetWindowSize(int w, int h);
    virtual void  GetWindowRect(int *x, int *y, int *w, int *h);
    virtual bool  IsActiveApp();
    virtual bool  IsMultiplayer();
    virtual int   PlayStartupVideos();
    virtual void  PlayAVIAndWait(const char *aviFile);

public:
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

struct ServerChannelList {
    int nf1;
    int nf2;
};

struct vector_ServerChannelList {
    ServerChannelList* first;
    ServerChannelList* last;
    ServerChannelList* end;
};

struct CServerChannelManager
{
    CServerChannelManager_vtables* vfptr;
    void* vfptr2; // packetListener

    vector_ServerChannelList vServerList;
    struct vector vServerList2;

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