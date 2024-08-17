class PacketListener {
public:
    virtual ~PacketListener() {}
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
class IKeyValues : public IBaseInterface {
public:
    virtual void RegisterSizeofKeyValues(int size);
    virtual void* AllocKeyValuesMemory(int size);
    virtual void FreeKeyValuesMemory(void* kv);
    virtual HKeySymbol  GetSymbolForString(const char *name);
    virtual const char* GetStringForSymbol(HKeySymbol symbol);
    virtual void GetLocalizedFromANSI();
    virtual void GetANSIFromLocalized();
    virtual void AddKeyValuesToMemoryLeakList();
    virtual void RemoveKeyValuesFromMemoryLeakList();
};

class KeyValues {
public:
    enum types_t
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

public:
    virtual void GetName();
    virtual int  GetNameSymbol();
    virtual bool LoadFromFile(struct CFileSystem_Nar* filesystem, const char* resourceName, const char* pathID = NULL);
    virtual bool SaveToFile();
    virtual struct KeyValues* FindKey1(int keySymbol);
    virtual struct KeyValues* FindKey2(const char *keyName, bool bCreate);
    virtual struct KeyValues* CreateNewKey();
    virtual void AddSubKey(struct KeyValues* pSubkey);
    virtual struct KeyValues* GetFirstSubKey();
    virtual struct KeyValues* GetNextKey();
    virtual int      GetInt(const char *keyName, int defaultValue);
    virtual float    GetFloat(const char *keyName, float defaultValue);
    virtual char*    GetString (const char *keyName, const char* defaultValue);
    virtual wchar_t* GetWString(const char *keyName, const wchar_t* defaultValue);
    virtual void*    GetPtr(const char *keyName, void* defaultValue);
    virtual bool IsEmpty(int keySymbol);
    virtual void SetWString(const char *keyName, const wchar_t *value);
    virtual void SetString(const char *keyName, const char *value);
    virtual void SetInt(const char *keyName, int value);
    virtual void SetFloat(const char *keyName, float value);
    virtual void SetPtr(const char *keyName, void *value);
    virtual struct KeyValues* MakeCopy();
    virtual void Clear();
    virtual types_t GetDataType(const char *keyName);
    virtual void deleteThis();

public:
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