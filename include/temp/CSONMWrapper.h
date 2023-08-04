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
    void (__thiscall* LoginAuthReply)(struct CSONMEventListener* ptr, struct NMLoginAuthReplyCode loginCode, int socketError);
    void (__thiscall* InitFriendList)(struct CSONMEventListener* ptr, int a2); // a2 > 2 execute FriendMgr stuffs
    void (__thiscall* NullFunc)(struct CSONMEventListener* ptr); // null
    void (__thiscall* Function4)(struct CSONMEventListener* ptr, int a2, const char* message); // #CSO_ServerMessage_Title
    void (__thiscall* Function5)(struct CSONMEventListener* ptr, int a2, const char* message); // 1 = #CSO_Request_Friend, 2 = #CSO_Send_Memo, default = #CSO_Message_RequestFriend_Success
    void (__thiscall* InitFriendList2)(struct CSONMEventListener* ptr);
    void (__thiscall* Function7)(struct CSONMEventListener* ptr, int* a2); // #CSO_FriendLogout | #CSO_FriendLogin
    void (__thiscall* Function8)(struct CSONMEventListener* ptr, int a2, int a3); // unk
    void (__thiscall* GetNoteBox2)(struct CSONMEventListener* ptr);
    void (__thiscall* GetGuildOnlineInfoEx)(struct CSONMEventListener* ptr);
    void (__thiscall* SendClanChat)(struct CSONMEventListener* ptr);
    void (__thiscall* SendClanChatError)(struct CSONMEventListener* ptr); // #CSO_Clan_ChatRoomError
    void (__thiscall* CallChattingManager_Func27)(struct CSONMEventListener* ptr);
    void (__thiscall* CallChattingManager_Func25)(struct CSONMEventListener* ptr);
    void (__thiscall* CallChattingManager_Func28)(struct CSONMEventListener* ptr);
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
    const char* unk10; // userName?
    char unk11;
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

struct CCrashUnk
{
    int unk1;
    int unk2;
    int unk3;
    char unk4[0x6400];
    int unk5;
    void* pNext;
};

struct CFriendManager_vtables
{
    void (__thiscall* AddFriend)(struct CFriendManager* ptr, wchar_t* gameName);
    void (__thiscall* SetSerialNo)(struct CFriendManager* ptr);
    void (__thiscall* ConfirmFriend_1)(struct CFriendManager* ptr);
    void (__thiscall* ConfirmFriend_2)(struct CFriendManager* ptr);
    void (__thiscall* ConfirmFriend_3)(struct CFriendManager* ptr);
    void (__thiscall* Function6)(struct CFriendManager* ptr);
    void (__thiscall* Function7)(struct CFriendManager* ptr);
    void (__thiscall* Function8)(struct CFriendManager* ptr);
};

struct CFriendManager
{
    struct CFriendManager_vtables* vfptr;
    vector vec1;
    unsigned int uFriendSerialNo;
    vector vec2;
};

struct StreamCrypto
{
    struct map map;
    int unk3;
};

struct CStreamCryptor_v0_vt
{
    void (__thiscall* destructor)(struct CStreamCryptor_v0* ptr);
    void (__thiscall* Function2)(struct CStreamCryptor_v0* ptr, int a, int b, int c);
    void (__thiscall* Function3)(struct CStreamCryptor_v0* ptr, int a, int b, int c);
    void (__thiscall* return0)(struct CStreamCryptor_v0* ptr);
    void (__thiscall* return0x1FCA34)(struct CStreamCryptor_v0* ptr);
    void (__thiscall* return0x8A119E)(struct CStreamCryptor_v0* ptr);
    void (__thiscall* returnA)(struct CStreamCryptor_v0* ptr, int a);
};

struct CStreamCryptor_v0
{
    CStreamCryptor_v0_vt* vfptr;
};

struct CStreamCryptor_v1_vt
{
    void (__thiscall* destructor)(struct CStreamCryptor_v1* ptr);
    void (__thiscall* Function2)(struct CStreamCryptor_v1* ptr, int a, int b, int c);
    void (__thiscall* Function3)(struct CStreamCryptor_v1* ptr, int a, int b, int c);
    void (__thiscall* return1)(struct CStreamCryptor_v1* ptr);
    void (__thiscall* return0xA98C32A)(struct CStreamCryptor_v1* ptr);
    void (__thiscall* return0x820A9E12)(struct CStreamCryptor_v1* ptr);
    void (__thiscall* returnAadd10)(struct CStreamCryptor_v1* ptr, int a);
};

struct CStreamCryptor_v1
{
    CStreamCryptor_v1_vt* vfptr;
};

struct CNMManager
{
    void* vfptr;
    unsigned char* pRetData;
    CRITICAL_SECTION cs;
    int unk1;
};
