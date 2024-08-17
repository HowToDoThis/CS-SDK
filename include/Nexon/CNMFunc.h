#include "CNMSerialize.h"

typedef enum NMFUNCCODE {
    // control
    kNMFuncCode_ControlStart_                = 0x1000,
    kNMFuncCode_Init,
    kNMFuncCode_RegisterCallback,
    kNMFuncCode_ResetCallback,
    kNMFuncCode_AttachToNMCOServer,
    kNMFuncCode_DetachFromNMCOServer,
    kNMFuncCode_BringForwardStandAloneMsg,
    kNMFuncCode_StartStandAloneMsg,
    kNMFuncCode_InitClientObject,
    // session control
    kNMFuncCode_SessionControlStart_        = 0x1100,
    kNMFuncCode_Login,                        // DEPRECATED
    kNMFuncCode_Logout,                       // DEPRECATED
    kNMFuncCode_LoginVirtual,
    kNMFuncCode_LogoutVirtual,
    kNMFuncCode_GetMyVirtualUserList,
    kNMFuncCode_ChangeMyPosition,
    kNMFuncCode_SendRefreshMessage,
    kNMFuncCode_ChangeMyLevel,
    kNMFuncCode_RemoveMyVirtualUser,
    kNMFuncCode_LoginPassport,                // NOT IN KOREA
    kNMFuncCode_RetryLogin,                   // REMOVED
    kNMFuncCode_LoginNexonPassport,           // INTERNAL
    kNMFuncCode_LoginMessenger,
    kNMFuncCode_LogoutMessenger,
    kNMFuncCode_LoginAuth,
    kNMFuncCode_LogoutAuth,
    kNMFuncCode_Initialize,
    kNMFuncCode_SecurityAuth,
    kNMFuncCode_GetGameToken,
    kNMFuncCode_Close,                        // TODO: FIND
    // user info
    kNMFuncCode_UserInfoStart_                = 0x2000,
    kNMFuncCode_GetMyInfo,
    kNMFuncCode_GetUserDataList,
    kNMFuncCode_ChangeMyInfo,
    kNMFuncCode_GetConfig,
    kNMFuncCode_ChangeConfig,
    kNMFuncCode_GetLocalConfig,
    kNMFuncCode_ChangeLocalConfig,
    kNMFuncCode_GetCount,
    kNMFuncCode_SetCount,
    kNMFuncCode_ChangeNickname,
    kNMFuncCode_ChangeMetaData,
    // 행사 등 각종 이벤트나 뉴스 | Events and news
    kNMFuncCode_RequestNews,
    kNMFuncCode_CheckNews,
    // client info
    kNMFuncCode_ClientInfoStart_            = 0x2100,
    kNMFuncCode_GetDomain,
    kNMFuncCode_GetVersion,
    kNMFuncCode_SetStatInfo,
    kNMFuncCode_SetLocale,
    kNMFuncCode_GetNexonPassport,
    kNMFuncCode_GetSecurityQuestion,
    kNMFuncCode_GetNxHWID,
    kNMFuncCode_GetSecurityCodeCN,
    // P2P
    kNMFuncCode_P2PStart_                   = 0x3000,
    kNMFuncCode_P2PLogin,
    kNMFuncCode_P2PSendData,
    kNMFuncCode_P2PLogout,
    kNMFuncCode_P2PMultiSendData,
    // friend
    kNMFuncCode_FriendStart_                = 0x4000,
    kNMFuncCode_GetFriendList,
    kNMFuncCode_GetFriendInfo,
    kNMFuncCode_RequestNewFriend,
    kNMFuncCode_ConfirmNewFriend,
    kNMFuncCode_BlockFriend,
    kNMFuncCode_ChangeFriendMemo,
    kNMFuncCode_AddFriendToCategory,
    kNMFuncCode_DeleteFriendFromCategory,
    kNMFuncCode_MoveFriendCategory,
    kNMFuncCode_ChangeFriendMemoEx,
    // category
    kNMFuncCode_CategoryStart_                = 0x4100,
    kNMFuncCode_AddCategory,
    kNMFuncCode_DeleteCategory,
    kNMFuncCode_ChangeCategoryName,
    kNMFuncCode_ChangeCategoryProperty,
    kNMFuncCode_ChangeCategoryAllowType,
    // black-list (obsolete)
    kNMFuncCode_BlackListStart_                = 0x5000,
    kNMFuncCode_GetBlackList,
    kNMFuncCode_AddToBlackList,
    kNMFuncCode_DeleteFromBlackList,
    // reject-list (obsolete)
    kNMFuncCode_RejectListStart_            = 0x5100,
    kNMFuncCode_GetRejectList,
    kNMFuncCode_AddToRejectList,
    kNMFuncCode_DeleteFromRejectList,
    // new rejected user list
    kNMFuncCode_RejectedUserListStart_        = 0x5200,
    kNMFuncCode_GetRejectedUserList,
    kNMFuncCode_AppendRejectedUser,
    kNMFuncCode_RemoveRejectedUser,
    // note
    kNMFuncCode_NoteStart_                    = 0x6000,
    kNMFuncCode_GetNoteBox,
    kNMFuncCode_SendNoteMsg,
    kNMFuncCode_ProcessNote,
    kNMFuncCode_SendNoteInfo,
    kNMFuncCode_GetNoteBox2,
    kNMFuncCode_SendAccuseNoteMsg,
    // guild
    kNMFuncCode_GuildStart_                    = 0x7000,
    kNMFuncCode_GetMyGuildList,                // REMOVED //
    kNMFuncCode_MonitorGuildOnlineInfo,        // REMOVED //
    kNMFuncCode_GetMyGuildListEx,
    kNMFuncCode_MonitorGuildOnlineInfoEx,
    kNMFuncCode_SendGuildChatMessage,
    kNMFuncCode_GetGuildList,                  // OBSOLETE //
    // client util
    kNMFuncCode_ClientUtilStart_            = 0x8000,
    kNMFuncCode_ExecutePatcher,
    kNMFuncCode_ExecuteLauncher,
    kNMFuncCode_ExecuteCommon,
    kNMFuncCode_GetUrl,                     // REMOVED //
    kNMFuncCode_GetPath,
    kNMFuncCode_SetSessionValue,
    kNMFuncCode_GetSessionValue,
    kNMFuncCode_GetGameList,
    kNMFuncCode_GetUrlEx,
    kNMFuncCode_DownloadFile,
    kNMFuncCode_UploadFile,
    kNMFuncCode_GetSupportGameList,
    kNMFuncCode_GetGameServerList,
    kNMFuncCode_GetGameFullName,
    kNMFuncCode_GetGameShortName,
    kNMFuncCode_GetGameFriendTitle,
    kNMFuncCode_GetGameServerName,
    kNMFuncCode_GetConnConfig,
    kNMFuncCode_SetConnConfig,
    kNMFuncCode_DownloadGameList,           // REMOVED //
    kNMFuncCode_ExecuteNGMPatcher,
    kNMFuncCode_ExecuteNGMLauncher,
    kNMFuncCode_IsNGMInstalled,
    kNMFuncCode_RestrictedWords,
    kNMFuncCode_MinimizeAll,
    kNMFuncCode_LogReportSync,
    kNMFuncCode_IsGuestIDPassport,
    kNMFuncCode_SetServerInfo,
    kNMFuncCode_DownloadGuildMarkFile,
    kNMFuncCode_GetServerInfo,
    kNMFuncCode_WriteToWiselog,
    kNMFuncCode_ExecuteNGMInstaller,
    kNMFuncCode_OpenGameSummary,
    kNMFuncCode_ClientUtilEnd_,
    // server util
    kNMFuncCode_ServerUtilStart_            = 0x9000,
    kNMFuncCode_GetUserInfo,
    kNMFuncCode_FindUser,
    kNMFuncCode_GetFindUserResult,
    kNMFuncCode_SendNoteExMsg,
    kNMFuncCode_SendReportMsg,
    kNMFuncCode_CustomNotify,
    // create session
    kNMFuncCode_CreateSessionStart_            = 0xA000,
    kNMFuncCode_RequestChatSession,
    kNMFuncCode_RequestMultiChatSession,
    kNMFuncCode_RequestFileUploadSession,
    kNMFuncCode_RequestWBSession,
    kNMFuncCode_ReplySessionRequest,
    kNMFuncCode_CreateChatRoom,                // REMOVED //
    kNMFuncCode_JoinToChatRoom,                // REMOVED //
    kNMFuncCode_RequestSessionToOther,
    kNMFuncCode_CreateChatRoomEx,
    kNMFuncCode_JoinToChatRoomEx,
    kNMFuncCode_RequestChatSessionEx,
    kNMFuncCode_RequestMultiChatSessionEx,
    kNMFuncCode_RequestFileUploadSessionEx,
    kNMFuncCode_RequestWBSessionEx,
    kNMFuncCode_JoinToDefaultGuildChatRoom,
    kNMFuncCode_CreateChannel,
    kNMFuncCode_JoinChannel,
    // chat room
    kNMFuncCode_ChatRoomStart_                = 0xB000,
    kNMFuncCode_CRRegisterCallback,
    kNMFuncCode_CRClose,
    kNMFuncCode_CRGetRoomInfo,                // REMOVED //
    kNMFuncCode_CRChangeRoomInfo,
    kNMFuncCode_CRChangeMyInfo,
    kNMFuncCode_CRGetMemberList,
    kNMFuncCode_CRInviteUser,
    kNMFuncCode_CRBanUser,
    kNMFuncCode_CRSendChatMessage,
    kNMFuncCode_CRGetMemberInfo,
    kNMFuncCode_CRGetRoomInfoEx,
    // general session
    kNMFuncCode_GenralSessionStart_            = 0xC000,
    kNMFuncCode_GSRegisterCallback,
    kNMFuncCode_GSWantClose,
    kNMFuncCode_GSGetSessionInfo,
    kNMFuncCode_GSSetServingProcessID,
    kNMFuncCode_GSGetMemberList,
    kNMFuncCode_GSInviteUser,
    kNMFuncCode_GSGetInviteCandidateList,
    kNMFuncCode_GSInviteUserEx,
    // chat session
    kNMFuncCode_ChatSessionStart_            = 0xC100,
    kNMFuncCode_CSSendChatMessage,
    // file upload session
    kNMFuncCode_FileUploadSessionStart_      = 0xC200,
    kNMFuncCode_FUDSGetFileEvent,
    kNMFuncCode_FUSSendFile,
    kNMFuncCode_FUSControl,
    // file download session
    kNMFuncCode_FileDownloadSessionStart_    = 0xC300,
    kNMFuncCode_FDSControl,
    kNMFuncCode_FDSGetDownloadDir,
    kNMFuncCode_FDSSetDownloadDir,
    // white-board session
    kNMFuncCode_WhiteboardSessionStart_        = 0xC400,
    kNMFuncCode_WSSendWBMessage,
    kNMFuncCode_WSGetAssocSerialKey,
    // channel
    kNMFuncCode_ChannelStart_                  = 0xD000,
    kNMFuncCode_CHClose,
    kNMFuncCode_CHGetChannelInfo,
    kNMFuncCode_CHChangeChannelInfo,
    kNMFuncCode_CHGetMemberInfoList,
    kNMFuncCode_CHChangeMyInfo,
    kNMFuncCode_CHInviteUser,
    kNMFuncCode_CHBanUser,
    kNMFuncCode_CHSendChannelMessage,
    // for event
    kNMFuncCode_EventStart_                    = 0xE000,
    kNMFuncCode_KartComeback,
    // for character
    kNMFuncCode_CharacterLogin                 = 0xF000,
    kNMFuncCode_CharacterLogout,
    kNMFuncCode_CharacterRemove,
    kNMFuncCode_CharacterChangeName,
    kNMFuncCode_CharacterLogin64,
    kNMFuncCode_CharacterLogout64,
    kNMFuncCode_CharacterRemove64,
    kNMFuncCode_CharacterChangeName64,
    kNMFuncCode_CharacterSync,
    kNMFuncCode_CharacterSync64,
    // for game log
    kNMFuncCode_GameLogInitialize             = 0xF010,
    kNMFuncCode_GameLogFinalize,
    kNMFuncCode_GameLogWriteStageLog,
    kNMFuncCode_GameLogWriteErrorLog,
    kNMFuncCode_GameLogGetSessionID,
    // for play feed
    kNMFuncCode_PlayFeedWritePlayLog          = 0xF0A0,
    kNMFuncCode_PlayFeedPublishPlayFeed,
    // for p2 linker
    kNMFuncCode_P2LinkerWriteChat             = 0xF100,
};

class CNMFunc : public CNMSerializable {
public:
    virtual char* GetName();

public:
    // private
    NMFUNCCODE iCode;
    int  bCalling;
    int  bHandled;
    int  bPassThrough;
    int  bUseEncrypt;
    int  iProcID;
    // public
    int  iSerialKey;
    int  bSuccess;
};
