struct CSONMWrapperEventHandler_vtables
{
    void (__thiscall* OnNMEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    
    void (__thiscall* OnMessengerReplyEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMMessengerReplyEvent* pEvent);
    void (__thiscall* OnAuthConnectionClosedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnAuthSecondaryConnectionClosedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnMsgConnectionClosedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnRefreshEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnSpecialEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnRequestNewFriendEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnServerMessageEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCustomMessageEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnNoteInstantMsgEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnRefreshMessageEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnFindUserReplyEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnInviteVirtualUserEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnUserInfoEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGuildOnlineInfoExEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGuildChatMessageEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnFriendInfoChangedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnNotifyEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCustomNotifyEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnNoteInfoEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnAttendanceEventEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);

    void (__thiscall* OnLogReportSyncEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    
    void (__thiscall* OnCRChatRoomCreatedExEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCRChatRoomEstablishedExEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCRChatRoomErrorEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCRChatRoomMemberEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCRChatRoomInfoExEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnCRChatRoomMessageReceivedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    
    void (__thiscall* OnGSSessionCreatedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSSessionEstablishedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSSessionFailedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSSessionClosedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSSessionInfoChangedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSNewMemberJoinedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSMemberLeavedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnGSMemberInfoChangedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    
    void (__thiscall* OnCSChatMessageReceivedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnFUSFileUploadEventReceivedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnFDSFileDownloadEventReceivedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnWSWhiteBoardMsgReceivedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
    void (__thiscall* OnWSWhiteBoardAckReceivedEvent)(struct CSONMWrapperEventHandler* ptr, struct CNMEvent* pEvent);
};

struct CSONMWrapperEventHandler
{
    CSONMWrapperEventHandler_vtables* vfptr;
    struct CSONMWrapper* wrapper;
};

struct CSONMWrapper_vtables
{
    void (__thiscall* Function1)(struct CSONMWrapper* ptr);
};

struct CSONMEventListener_vtables
{
    void (__thiscall* LoginAuthReply)(struct CSONMEventListener* ptr, struct NMLoginAuthReplyCode* loginCode, int socketError);
    void (__thiscall* OnMessengerReplyEvent)(struct CSONMEventListener* ptr, int b); // a2 > 2 execute FriendMgr stuffs
    void (__thiscall* OnMsgConnectionClosedEvent)(struct CSONMEventListener* ptr); // null
    void (__thiscall* OnServerMessageEvent)(struct CSONMEventListener* ptr, int type, const char* message); // #CSO_ServerMessage_Title
    void (__thiscall* OnCustomMessageEvent)(struct CSONMEventListener* ptr, int a2, const char* message); // 1 = #CSO_Request_Friend, 2 = #CSO_Send_Memo, default = #CSO_Message_RequestFriend_Success
    void (__thiscall* GetFriendList)(struct CSONMEventListener* ptr);
    void (__thiscall* OnFriendInfoChangedEvent)(struct CSONMEventListener* ptr, struct CNMFriendInfoChangedEvent* pEvent); // #CSO_FriendLogout | #CSO_FriendLogin
    void (__thiscall* OnRequestNewFriendEvent)(struct CSONMEventListener* ptr, char* nickname, char* msg, int serialNo);
    void (__thiscall* GetNoteBox2)(struct CSONMEventListener* ptr);
    void (__thiscall* GetGuildOnlineInfoEx)(struct CSONMEventListener* ptr);
    void (__thiscall* OnCRChatRoomMessageReceivedEvent)(struct CSONMEventListener* ptr, const char* senderName, const char* msg);
    void (__thiscall* OnCRChatRoomErrorEvent)(struct CSONMEventListener* ptr, const char* msg); // #CSO_Clan_ChatRoomError
    void (__thiscall* WriteToChatSession)(struct CSONMEventListener* ptr, int sessionID, char* senderName, char* msg);
    void (__thiscall* FindChatSession)(struct CSONMEventListener* ptr, int sessionID, int);
    void (__thiscall* ShowChatSession)(struct CSONMEventListener* ptr, int sessionID, char*, int, void*);
};

struct CSONMEventListener
{
    CSONMEventListener_vtables* vfptr;
};

struct CSONMWrapper
{
    struct CSONMWrapper_vtables* vfptr;
    void* steamPtr;
    struct CSONMWrapperEventHandler* eventHandler;
    struct CSONMEventListener* eventListener;
    int iIsLogin; // loginCode?
    int gameCode; // kGameCode_cso(0x12009, type 0), kGameCode_csointernal(0x1F008, type 1) kGameCode_csotest(0x1F007, type ?)
    int region;
    int unk7;
    int unk8;
    int unk9;
    const char* passport;
    char bLoginVirtual;
    HWND window;
    int unk12;
};

struct CLoginWrapper
{
    void* vguiPanel;
    void* vguiLogin;
    HMODULE libVGUI2;
    HMODULE libFileSystem_Nar;
};

// Fixed Size
// 0x6414
struct CCrashUnk
{
    int unk1;
    HWND hWnd;
    int unk3;
    char unk4[0x6400];
    int unk5;
    void* pNext;
};

// 0x48
struct CSOFriend {
    NMIDCode friendCode;
    int uOID;
    int uLevel;
    wstring szNickName;
    string szPosition;
    int uStatus;
    int uCategoryCode;
};

struct CFriend_Unknown2 {
    void* vfptr;
    int u2;
    int uOID;
    int uLevel;
    char* szNickName;
    char* szPosition;
    int uStatus;
    int u8;
};

struct vec_CSOFriend {
    CSOFriend* first;
    CSOFriend* last;
    CSOFriend* end;
};

class CFriendManager {
public:
    virtual void AddFriend(wchar_t* gameName);
    virtual void SetSerialNo(unsigned int sn);
    virtual void ConfirmFriend_1();
    virtual void ConfirmFriend_2();
    virtual void ConfirmFriend_3();
    virtual void Function6();
    virtual CSOFriend* Function7(CSOFriend*, int);
    virtual void Function8();

public:
    CSOFriend* u1;
    CSOFriend* u2;
    int u3;
    unsigned int uFriendSerialNo;
    CFriend_Unknown2* u4;
    CFriend_Unknown2* u5;
    int u6;
};

struct CStreamCryptorFactory
{
    struct map m_mapCryptor;
    char m_uLatestVersion;
};

struct CStreamCryptor_vtbl {
    void (__thiscall* dtor)(struct CStreamCryptor* ptr);
    uint (__thiscall* Encrypt)(struct CStreamCryptor* ptr, unsigned char* pBuf, unsigned int uBufMaxLen, unsigned int *uBufLen);
    uint (__thiscall* Decrypt)(struct CStreamCryptor* ptr, unsigned char* pBuf, unsigned int uBufMaxLen, unsigned int *uBufLen);
    char (__thiscall* GetVersion)(struct CStreamCryptor* ptr);
    uint (__thiscall* GetStartMarker)(struct CStreamCryptor* ptr);
    uint (__thiscall* GetEndMarker)(struct CStreamCryptor* ptr);
    uint (__thiscall* GetEncSize)(struct CStreamCryptor* ptr, unsigned int uBufLen);
};

struct CStreamCryptor {
    CStreamCryptor_vtbl* vfptr;
};

struct CStreamCryptor_v0 : CStreamCryptor {
};

struct CStreamCryptor_v1 : CStreamCryptor {
};

struct CNMManager
{
    void* vfptr;
    class CNMFunc* m_pRetData;
    CRITICAL_SECTION cs;
    int m_codePage;
};
