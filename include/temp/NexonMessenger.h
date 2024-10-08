typedef unsigned long long NMIDCode;
typedef unsigned long long NMGuildKey;
typedef unsigned int NMGameServerCode;

typedef enum NMEVENTCODE {
    // control
    kNMEventCode_ControlStart_                 = 0x1000,
    kNMEventCode_MessengerReply                = 0x1001,
    kNMEventCode_MsgConnectionClosed           = 0x1002,
    kNMEventCode_Refresh                       = 0x1003,
    kNMEventCode_Special                       = 0x1004,
    kNMEventCode_RequestNewFriend              = 0x1005,
    kNMEventCode_ServerMessage                 = 0x1006,
    kNMEventCode_CustomMessage                 = 0x1007,
    kNMEventCode_NoteInstantMsg                = 0x1008, // original note version
    kNMEventCode_RefreshMessage                = 0x1009,
    kNMEventCode_FindUserReply                 = 0x100A,
    kNMEventCode_InviteVirtualUser             = 0x100B,
    kNMEventCode_UserInfo                      = 0x100C,
    kNMEventCode_GuildOnlineInfo               = 0x100D, // REMOVED
    kNMEventCode_RealFriendInfoChanged         = 0x100E,
    kNMEventCode_VirtualFriendInfoChanged      = 0x100F,
    kNMEventCode_FriendInfoChanged             = 0x1010,
    kNMEventCode_Notify                        = 0x1011,
    kNMEventCode_GuildOnlineInfoEx             = 0x1012,
    kNMEventCode_GuildChatMessage              = 0x1013,
    kNMEventCode_CustomNotify                  = 0x1014,
    kNMEventCode_RejectedUserListChanged       = 0x1015,
    kNMEventCode_NoteInfo                      = 0x1016, // new note version
    kNMEventCode_AuthConnectionClosed          = 0x1017,
    kNMEventCode_AuthSecondaryConnectionClosed = 0x1018,
    // chat room
    kNMEventCode_ChatRoomStart_            = 0x9000,
    kNMEventCode_CRChatRoomCreated         = 0x9001, // REMOVED //
    kNMEventCode_CRChatRoomEstablished     = 0x9002, // REMOVED //
    kNMEventCode_CRChatRoomError           = 0x9003,
    kNMEventCode_CRChatRoomMember          = 0x9004,
    kNMEventCode_CRChatRoomInfo            = 0x9005, // REMOVED //
    kNMEventCode_CRChatRoomMessageReceived = 0x9006,
    kNMEventCode_CRChatRoomCreatedEx       = 0x9007,
    kNMEventCode_CRChatRoomEstablishedEx   = 0x9008,
    kNMEventCode_CRChatRoomInfoEx          = 0x9009,
    // general session
    kNMEventCode_GeneralSessionStart_ = 0xA000,
    kNMEventCode_GSSessionCreated     = 0xA001,
    kNMEventCode_GSSessionEstablished = 0xA002,
    kNMEventCode_GSSessionFailed      = 0xA003,
    kNMEventCode_GSSessionClosed      = 0xA004,
    kNMEventCode_GSSessionInfoChanged = 0xA005,
    kNMEventCode_GSNewMemberJoined    = 0xA006,
    kNMEventCode_GSMemberLeaved       = 0xA007,
    kNMEventCode_GSMemberInfoChanged  = 0xA008,
    kNMEventCode_GSSessionInfo        = 0xA009,
    kNMEventCode_GSInviteRejected     = 0xA00A,
    // chat session
    kNMEventCode_ChatSessionStart_     = 0xA100,
    kNMEventCode_CSChatMessageReceived = 0xA101,
    kNMEventCode_CSMultiChatCreated    = 0xA102,
    // file upload session
    kNMEventCode_FileUploadSessionStart_    = 0xA200,
    kNMEventCode_FUSFileUploadEventReceived = 0xA201,
    // file download session
    kNMEventCode_FileDownloadSessionStart_    = 0xA300,
    kNMEventCode_FDSFileDownloadEventReceived = 0xA301,
    // white-board session
    kNMEventCode_WhiteboardSessionStart_ = 0xA400,
    kNMEventCode_WSWhiteBoardMsgReceived = 0xA401,
    kNMEventCode_WSWhiteBoardAckReceived = 0xA402,
    kNMEventCode_WSAssocSerialKey        = 0xA403,
    // 이벤트 (출석체크 이벤트 등) | Events (e.g., attendance check events)
    kNMEventCode_EventStart_     = 0xB000,
    kNMEventCode_AttendanceEvent = 0xB001,
    kNMEventCode_KartDormant     = 0xB002,
    // channel
    kNMEventCode_ChannelStart_					= 0xC000,
    kNMEventCode_ChannelError					= 0xC001,
    kNMEventCode_ChannelCreated					= 0xC002,
    kNMEventCode_ChannelEstablished				= 0xC003,
    kNMEventCode_ChannelInfo					= 0xC004,
    kNMEventCode_ChannelMemberInfo				= 0xC005,
    kNMEventCode_ChannelMemberInfoList			= 0xC006,
    kNMEventCode_ChannelMessage					= 0xC007,
    // client util
    kNMEventCode_ClientUtilStart_				= 0xD000,
    kNMEventCode_LogReportSync					= 0xD001,
    // P2P
    kNMEventCode_P2PStart_						= 0xE000,
    kNMEventCode_P2PLoginReply					= 0xE001,
    kNMEventCode_P2PSendDataReply				= 0xE002,
    kNMEventCode_P2PMessage						= 0xE003,
    kNMEventCode_P2PConnectionClosed			= 0xE004,
};

typedef enum NMLOCALEID {
    kLocaleID_Null          = 0x00000000,
    kLocaleID_KR            = 0x00000001, // Korea, Republic of
    kLocaleID_KR_Test       = 0x10000001, // Test
    kLocaleID_JP            = 0x00000100, // Japan
    kLocaleID_CN            = 0x00000101, // China Kart/CSO
    kLocaleID_TW            = 0x00000102, // Taiwan
    kLocaleID_TH            = 0x00000103, // Thailand
    kLocaleID_VN            = 0x00000104, // Vietnam
    kLocaleID_SG            = 0x00000105, // Singapore
    kLocaleID_ID            = 0x00000106, // Indonesia
    kLocaleID_CN2           = 0x00000107, // China BF(Shanda)
    kLocaleID_US            = 0x00000200, // United States
    kLocaleID_EU            = 0x00000300, // Europe
    kLocaleID_RU            = 0x00000301, // Russia
    kLocaleID_BR            = 0x00000400, // Brazil
    
    // DO NOT USE THIS CODE! (Only for backward compatibility)
    kLocaleID_CN_CNC        = 0x00000111, // China / CNC
    kLocaleID_CN_CT         = 0x00000112, // China / CT
};

// Messenger Service Support Flag
typedef enum NMSUPPORTFLAG {
    kSupportFlag_ChatSession                = 1 << 0,
    kSupportFlag_FileUpDnSession            = 1 << 1,
    kSupportFlag_WBSession                  = 1 << 2,
    kSupportFlag_AddFriendConfirm           = 1 << 3,
    kSupportFlag_ServerMessage              = 1 << 4,
    kSupportFlag_GeneralNoteMsg             = 1 << 5,
    kSupportFlag_GameInviteNoteMsg          = 1 << 6,
    kSupportFlag_ItemGiftNoteMsg            = 1 << 7,
    kSupportFlag_RequestSession             = 1 << 8,
    kSupportFlag_GuildNoticeNoteMsg         = 1 << 9,
    kSupportFlag_GuildChatRoomInviteNoteMsg = 1 << 10,
    kSupportFlag_WarningNoteMsg             = 1 << 11,
    kSupportFlag_GuildChatRoom              = 1 << 12,
    kSupportFlag_GuildNote                  = 1 << 13,
    kSupportFlag_GuildWarInviteNote         = 1 << 14,
    kSupportFlag_CustomNotify               = 1 << 15,
    kSupportFlag_NexonEvent                 = 1 << 16, // 경품행사 등 각종 이벤트 | Various events such as giveaway events, etc
    kSupportFlag_All                        = 0x7FFFFFFF,
    kSupportFlag_FromGameCode               = 0x80000000,
};

// Main Game Codes
typedef enum NMMainGameCode{
    kMainGameCode_NULL              = 0,
    kMainGameCode_Start             = 0x0001,
    kMainGameCode_nexoncom          = 0x0001,
    kMainGameCode_baram             = 0x0002,
    kMainGameCode_lod               = 0x0003,
    kMainGameCode_elan              = 0x0004,
    kMainGameCode_asgard            = 0x0006,
    kMainGameCode_mabi              = 0x0007,
    kMainGameCode_tales             = 0x0008,
    kMainGameCode_maplestory        = 0x0009,
    kMainGameCode_ca                = 0x000B,
    kMainGameCode_qplay             = 0x000C,
    kMainGameCode_zera              = 0x000D,
    kMainGameCode_zeratest          = 0x000E,
    kMainGameCode_zeratest_internal = 0x000F,
    kMainGameCode_lunia             = 0x0010,
    kMainGameCode_planb             = 0x0011,
    kMainGameCode_ndoors            = 0x0012,

    kMainGameCode_nexon_jp          = 0x0100,
    kMainGameCode_nexon_cn          = 0x0101,
    kMainGameCode_nexon_tw          = 0x0102,
    kMainGameCode_nexon_th          = 0x0103,
    kMainGameCode_nexon_vn          = 0x0104,
    kMainGameCode_nexon_sg          = 0x0105,
    kMainGameCode_nexon_id          = 0x0106,
    kMainGameCode_nexon_cn2         = 0x0107,
    kMainGameCode_nexon_us          = 0x0200,
    kMainGameCode_nexon_eu          = 0x0300,
    kMainGameCode_nexon_ru          = 0x0301,
    kMainGameCode_nexon_br          = 0x0400,

    // old style (not commended)
    kMainGameCode_nexonjp           = kMainGameCode_nexon_jp,
    kMainGameCode_nexoncn           = kMainGameCode_nexon_cn,
    kMainGameCode_nexontw           = kMainGameCode_nexon_tw,

    kMainGameCode_guild             = 0x1000,
    kMainGameCode_gworld            = 0x1001,
    kMainGameCode_reservedid        = 0x1002,
    kMainGameCode_guildzera         = 0x1003,
    kMainGameCode_navertoolbar      = 0x1004,
};

typedef enum NMSubGameCode {
    kSubGameCode_NULL                = 0,
    // for Application Login
    kSubGameCode_messenger           = 0x0001,
    kSubGameCode_plug                = 0x0002,
    kSubGameCode_gamesummary         = 0x0003,
    kSubGameCode_nexonsticklauncher  = 0x0004,
    kSubGameCode_nexonstickmanager   = 0x0005,
    // for Web Login
    kSubGameCode_web_main            = 0x1001,
    // for Nx Game Login
    //kSubGameCode_nxgame_start        = 0x2001,
    //kSubGameCode_gostop              = 0x2001,
    //kSubGameCode_matgo               = 0x2002,
    //kSubGameCode_starmatgo           = 0x2003,
    //kSubGameCode_poker               = 0x2004,
    //kSubGameCode_thiefnyang          = 0x2005,
    //kSubGameCode_webbz               = 0x2006,
    //kSubGameCode_onecard             = 0x2007,
    //kSubGameCode_sachun              = 0x2008,
    //kSubGameCode_omok                = 0x2009,
    //kSubGameCode_jangki              = 0x200A,
    //kSubGameCode_manmani             = 0x200B,
    //kSubGameCode_nxgame_common       = 0x20FF,
    //kSubGameCode_nxgame_end          = 0x20FF,
    // for Kart Related Game
    kSubGameCode_kartrider           = 0x2101,
    kSubGameCode_karttest            = 0x2102,
    // for Nexon Game
    //kSubGameCode_pucca               = 0x2201,
    kSubGameCode_zera                = 0x2202,
    kSubGameCode_bigshot             = 0x2203,
    //kSubGameCode_mabikiz             = 0x2204,
    kSubGameCode_mabinogi            = 0x2205,
    kSubGameCode_nexonbyul           = 0x2206,
    kSubGameCode_combatarms          = 0x2207,
    kSubGameCode_talesweaver         = 0x2208,
    kSubGameCode_cso                 = 0x2009,
    kSubGameCode_ca                  = 0x200A,
    kSubGameCode_heroes              = 0x200B,
    kSubGameCode_husky               = 0x200C,
    kSubGameCode_air					= 0x200D,
    kSubGameCode_trashbuster			= 0x220E,
    kSubGameCode_bubblefighter			= 0x220F,
    kSubGameCode_kavatina				= 0x2210,
    kSubGameCode_df						= 0x2211,
    kSubGameCode_projectb				= 0x2212,
    kSubGameCode_maple					= 0x2213,
    kSubGameCode_lob					= 0x2214,
    kSubGameCode_apex					= 0x2215,
    kSubGameCode_projectearth			= 0x2216,
    kSubGameCode_quizquiz				= 0x2217,
    kSubGameCode_cyphers				= 0x2218,
    kSubGameCode_desktopheroes			= 0x2219,
    kSubGameCode_mlb2k11				= 0x221A,
    kSubGameCode_mabinogi2				= 0x221B,
    kSubGameCode_cso2					= 0x221C,
    kSubGameCode_baram					= 0x2220,
    // for Channeling Game
    kSubGameCode_maple_hangame			= 0x6001,
    kSubGameCode_goonzu_gamania			= 0x6002,
    // for Publishing Game
    kSubGameCode_warrock           = 0x7004,
    kSubGameCode_lunia             = 0x7005,
    kSubGameCode_ninedragons       = 0x7006,
    kSubGameCode_nanaimo           = 0x7007,
    kSubGameCode_kickoff           = 0x7008, // 94216
    kSubGameCode_koongpa           = 0x7009,
    kSubGameCode_fighterstory      = 0x700A,
    kSubGameCode_slapshot          = 0x700B, // 94219
    kSubGameCode_elsword           = 0x7010,
    kSubGameCode_sp1               = 0x7011,
    kSubGameCode_rxsg					= 0x7012,
    kSubGameCode_suddenattack			= 0x7013,
    kSubGameCode_dekaron				= 0x7014,
    kSubGameCode_metalrage				= 0x7015,
    kSubGameCode_immortal				= 0x7016,
    kSubGameCode_freestylefootball		= 0x7017,
    kSubGameCode_sd3					= 0x7018,
    kSubGameCode_ageofocean				= 0x7019,
    kSubGameCode_kingdoms				= 0x701A,
    // for NPNA Games : 0x8101 ~ 0x8199
    kSubGameCode_npna_start_			= 0x8101,
    kSubGameCode_motoloco				= 0x8101,
    kSubGameCode_sugarrush				= 0x8102,
    kSubGameCode_nxopp					= 0x8103,
    kSubGameCode_golf					= 0x8104,
    kSubGameCode_npna_end_				= 0x8199,
    // for Nexon Japan
    kSubGameCode_tenvi					= 0x8201,
    kSubGameCode_atlantica				= 0x8202,
    kSubGameCode_tenvitest				= 0x8203,
    kSubGameCode_goonzu					= 0x8204,
    kSubGameCode_druaga					= 0x8205,
    kSubGameCode_dragonica				= 0x8206,
    kSubGameCode_pachimachi				= 0x8207,
    kSubGameCode_corum					= 0x8208,
    kSubGameCode_7souls					= 0x8209,
    kSubGameCode_edda					= 0x820A,
    kSubGameCode_nexon777				= 0x820B,
    // for Not Game
    kSubGameCode_navertoolbar      = 0xE001,
    kSubGameCode_scrapper          = 0xE002,
    kSubGameCode_p2app             = 0xE003,
    // for TEST
    kSubGameCode_testgame          = 0xF001,
    kSubGameCode_zeratest          = 0xF002,
    kSubGameCode_luniatest         = 0xF003,
    kSubGameCode_zeratest_internal = 0xF004,
    kSubGameCode_kickofftest       = 0xF005,
    kSubGameCode_nanaimotest       = 0xF006,
    kSubGameCode_csotest           = 0xF007,
    kSubGameCode_csointernal       = 0xF008,
    kSubGameCode_csodevelopment    = 0xF009,
    kSubGameCode_elswordtest       = 0xF00A,
    kSubGameCode_elswordtest_internal	= 0xF00B,
    kSubGameCode_slapshotinternal		= 0xF00C,
    kSubGameCode_zone4internal			= 0xF00D,
    kSubGameCode_heroestest				= 0xF00E,
    kSubGameCode_heroesdevelopment		= 0xF00F,
    kSubGameCode_airtest				= 0xF010,
    kSubGameCode_everplanet_test		= 0xF011,
    kSubGameCode_everplanet_dev			= 0xF012,
    kSubGameCode_husky_dev				= 0xF013,
    kSubGameCode_dragonnest_test		= 0xF014,
    kSubGameCode_dragonnest_dev			= 0xF015,
    kSubGameCode_kavatina_light			= 0xF016,
    kSubGameCode_mabitest				= 0xF017,
    kSubGameCode_mabilocaltest			= 0xF018,
    kSubGameCode_dftest					= 0xF019,
    kSubGameCode_catest					= 0xF01A,
    kSubGameCode_mapletest				= 0xF01B,
    kSubGameCode_heroesgm				= 0xF01C,
    kSubGameCode_talesweavertest		= 0xF01D,
    kSubGameCode_mapletespia			= 0xF01E,
    kSubGameCode_dragonnest_opentest	= 0xF01F,
    kSubGameCode_suddenattack_test		= 0xF020,
    kSubGameCode_dekaron_test			= 0xF021,
    kSubGameCode_metalrage_test			= 0xF022,
    kSubGameCode_suddenattack_dev		= 0xF023,
    kSubGameCode_dekaron_dev			= 0xF024,
    kSubGameCode_metalrage_dev			= 0xF025,
    kSubGameCode_p2_test				= 0xF026,
    kSubGameCode_7souls_test			= 0xF027,
    kSubGameCode_dragonica_test			= 0xF028,
    kSubGameCode_edda_test				= 0xF029,
    kSubGameCode_baram_test				= 0xF02A,
    kSubGameCode_nexon777_test			= 0xF02B,
    kSubGameCode_7souls_dev				= 0xF02C,
    kSubGameCode_nexon777_dev			= 0xF02D,
    kSubGameCode_edda_test2				= 0xF02E,
    kSubGameCode_mabinogi2_dev			= 0xF02F,

    // NOT USEFULL....

    // for MapleStory
    kSubGameCode_maple_install			= 0x0001,
    kSubGameCode_maplet_install			= 0x0002,

    // for Qplay
    kSubGameCode_qplay_install			= 0x0001,

    // for Crazy Arcade
    kSubGameCode_ca_install				= 0x0001,

    // for Legend Of Darkness
    kSubGameCode_lod_install			= 0x0001,

    // for PlanB
    kSubGameCode_planb					= 0x0001,
};

#define MAKE_GAMECODE(maincode, subcode) ((maincode << 16) | subcode)
#define MAKE_GUILDCODE(subcode) MAKE_GAMECODE(kMainGameCode_guild, subcode)

typedef enum NMSubGuildCode {
    // Sub Guild Codes
    kSubGuildCode_NULL              = 0,
    // for game guild
    kSubGuildCode_kart              = 2,
    kSubGuildCode_warrock           = 3,
    kSubGuildCode_bigshot           = 4,
    kSubGuildCode_zera              = 5,
    kSubGuildCode_zeratest          = 0x03E9,
    kSubGuildCode_zeratest_internal = 0x03EA,
    kSubGuildCode_lunia             = 6,
    kSubGuildCode_manmani           = 7,
    kSubGuildCode_luniatest         = 8,
    kSubGuildCode_koongpa           = 9,
    kSubGuildCode_combatarms			= 10,
    kSubGuildCode_cso					= 11,
    kSubGuildCode_slapshot				= 12,
    kSubGuildCode_bubblefighter			= 14,
    kSubGuildCode_heroes				= 15,
    kSubGuildCode_heroes_xe				= 16,
    // for friendship guild
    kSubGuildCode_friendship        = 511,
    // fo all guild
    kSubGuildCode_all               = 0xF000,
};

typedef enum NMGuildCode {
    // Guild Code List
    kGuildCode_NULL              = MAKE_GUILDCODE(kSubGuildCode_NULL),

    kGuildCode_kart              = MAKE_GUILDCODE(kSubGuildCode_kart),
    kGuildCode_warrock           = MAKE_GUILDCODE(kSubGuildCode_warrock),
    kGuildCode_bigshot           = MAKE_GUILDCODE(kSubGuildCode_bigshot),
    kGuildCode_zera              = MAKE_GUILDCODE(kSubGuildCode_zera),
    kGuildCode_zeratest          = MAKE_GUILDCODE(kSubGuildCode_zeratest),
    kGuildCode_zeratest_internal = MAKE_GUILDCODE(kSubGuildCode_zeratest_internal),
    kGuildCode_lunia             = MAKE_GUILDCODE(kSubGuildCode_lunia),
    kGuildCode_manmani           = MAKE_GUILDCODE(kSubGuildCode_manmani),
    kGuildCode_luniatest         = MAKE_GUILDCODE(kSubGuildCode_luniatest),
    kGuildCode_koongpa           = MAKE_GUILDCODE(kSubGuildCode_koongpa),
    kGuildCode_cso               = MAKE_GUILDCODE(kSubGuildCode_cso),
    kGuildCode_combatarms        = MAKE_GUILDCODE(kSubGuildCode_combatarms),
    kGuildCode_slapshot          = MAKE_GUILDCODE(kSubGuildCode_slapshot),
    kGuildCode_bubblefighter     = MAKE_GUILDCODE(kSubGuildCode_bubblefighter),
    kGuildCode_heroes            = MAKE_GUILDCODE(kSubGuildCode_heroes),
    kGuildCode_heroes_xe         = MAKE_GUILDCODE(kSubGuildCode_heroes_xe),

    kGuildCode_friendship        = MAKE_GUILDCODE(kSubGuildCode_friendship),

    kGuildCode_all               = MAKE_GUILDCODE(kSubGuildCode_all),
};

typedef enum NMGameCode {
    kCategoryCode_NULL          = 0,

    kGameCode_NULL              = MAKE_GAMECODE(kMainGameCode_NULL, kSubGameCode_NULL),

    // new style (commended)
    kGameCode_nexoncom					= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_NULL),
    kGameCode_nexon_jp					= MAKE_GAMECODE(kMainGameCode_nexon_jp, kSubGameCode_NULL),
    kGameCode_nexon_cn					= MAKE_GAMECODE(kMainGameCode_nexon_cn, kSubGameCode_NULL),
    kGameCode_nexon_tw					= MAKE_GAMECODE(kMainGameCode_nexon_tw, kSubGameCode_NULL),
    kGameCode_nexon_th					= MAKE_GAMECODE(kMainGameCode_nexon_th, kSubGameCode_NULL),
    kGameCode_nexon_vn					= MAKE_GAMECODE(kMainGameCode_nexon_vn, kSubGameCode_NULL),
    kGameCode_nexon_sg					= MAKE_GAMECODE(kMainGameCode_nexon_sg, kSubGameCode_NULL),
    kGameCode_nexon_cn2					= MAKE_GAMECODE(kMainGameCode_nexon_cn2, kSubGameCode_NULL),
    kGameCode_nexon_us					= MAKE_GAMECODE(kMainGameCode_nexon_us, kSubGameCode_NULL),
    kGameCode_nexon_eu					= MAKE_GAMECODE(kMainGameCode_nexon_eu, kSubGameCode_NULL),
    kGameCode_nexon_ru					= MAKE_GAMECODE(kMainGameCode_nexon_ru, kSubGameCode_NULL),
    kGameCode_nexon_br					= MAKE_GAMECODE(kMainGameCode_nexon_br, kSubGameCode_NULL),

    // old style (not commended)
    kGameCode_nexonjp					= kGameCode_nexon_jp,
    kGameCode_nexoncn					= kGameCode_nexon_cn,
    kGameCode_nexontw					= kGameCode_nexon_tw,
    kGameCode_nexonus					= kGameCode_nexon_us,
    kGameCode_nexoneu					= kGameCode_nexon_eu,

    kGameCode_messenger					= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_messenger),
    kGameCode_messenger_cn				= MAKE_GAMECODE(kMainGameCode_nexon_cn, kSubGameCode_messenger),
    kGameCode_messenger_cn2				= MAKE_GAMECODE(kMainGameCode_nexon_cn2, kSubGameCode_messenger),
    kGameCode_plug						= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_plug),
    kGameCode_gamesummary				= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_gamesummary),
    kGameCode_nexonsticklauncher		= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_nexonsticklauncher),
    kGameCode_nexonstickmanager			= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_nexonstickmanager),
    kGameCode_web						= MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_web_main),

    kGameCode_navertoolbar      = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_navertoolbar),
    kGameCode_scrapper          = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_scrapper),    
    kGameCode_p2app             = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_p2app),    
    
    kGameCode_testgame          = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_testgame),
    kGameCode_testgame_cn       = MAKE_GAMECODE(kMainGameCode_nexon_cn, kSubGameCode_testgame),

    kGameCode_guild             = MAKE_GAMECODE(kMainGameCode_guild, kSubGameCode_NULL),
    kGameCode_gworld            = MAKE_GAMECODE(kMainGameCode_gworld, kSubGameCode_NULL),
    kGameCode_reservedid        = MAKE_GAMECODE(kMainGameCode_reservedid, kSubGameCode_NULL),

    kGameCode_baram             = MAKE_GAMECODE(kMainGameCode_baram, kSubGameCode_NULL),
    kGameCode_lod               = MAKE_GAMECODE(kMainGameCode_lod, kSubGameCode_NULL),
    kGameCode_elan              = MAKE_GAMECODE(kMainGameCode_elan, kSubGameCode_NULL),
    kGameCode_asgard            = MAKE_GAMECODE(kMainGameCode_asgard, kSubGameCode_NULL),
    kGameCode_mabi              = MAKE_GAMECODE(kMainGameCode_mabi, kSubGameCode_NULL),
    kGameCode_tales             = MAKE_GAMECODE(kMainGameCode_tales, kSubGameCode_NULL),
    kGameCode_maplestory        = MAKE_GAMECODE(kMainGameCode_maplestory, kSubGameCode_NULL),
    kGameCode_qplay             = MAKE_GAMECODE(kMainGameCode_qplay, kSubGameCode_NULL),

    kGameCode_ca                = MAKE_GAMECODE(kMainGameCode_ca, kSubGameCode_NULL),
    kGameCode_ca_jp             = MAKE_GAMECODE(kMainGameCode_nexonjp, kSubGameCode_ca),

    kGameCode_kartrider         = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_kartrider),
    kGameCode_kartrider_cn      = MAKE_GAMECODE(kMainGameCode_nexon_cn, kSubGameCode_kartrider),
    kGameCode_kartrider_tw      = MAKE_GAMECODE(kMainGameCode_nexon_tw, kSubGameCode_kartrider),
    kGameCode_kartrider_us      = MAKE_GAMECODE(kMainGameCode_nexon_us, kSubGameCode_kartrider),
    kGameCode_karttest          = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_karttest),
    kGameCode_karttest_cn       = MAKE_GAMECODE(kMainGameCode_nexoncn, kSubGameCode_karttest),
    kGameCode_karttest_tw       = MAKE_GAMECODE(kMainGameCode_nexon_tw, kSubGameCode_karttest),
    kGameCode_karttest_us       = MAKE_GAMECODE(kMainGameCode_nexon_us, kSubGameCode_karttest),    

    kGameCode_zera              = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_zera),
    kGameCode_zeratest          = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_zeratest),
    kGameCode_zeratest_internal = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_zeratest_internal),

    kGameCode_bigshot           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_bigshot),
    kGameCode_bigshot_cn        = MAKE_GAMECODE(kMainGameCode_nexoncn, kSubGameCode_bigshot),
    
    kGameCode_nexonbyul         = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_nexonbyul),
    kGameCode_combatarms        = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_combatarms),
    kGameCode_heroes            = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_heroes),
    kGameCode_warrock           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_warrock),
    kGameCode_ninedragons       = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_ninedragons),
    kGameCode_koongpa           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_koongpa),
    kGameCode_fighterstory      = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_fighterstory),
    kGameCode_slapshot          = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_slapshot),
    kGameCode_sp1               = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_sp1),

    kGameCode_talesweaver       = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_talesweaver),
    kGameCode_talesweaver_cn    = MAKE_GAMECODE(kMainGameCode_nexoncn, kSubGameCode_talesweaver),
    
    kGameCode_lunia             = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_lunia),
    kGameCode_lunia_jp          = MAKE_GAMECODE(kMainGameCode_nexonjp, kSubGameCode_lunia),
    kGameCode_luniatest         = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_luniatest),
    kGameCode_luniatest_jp      = MAKE_GAMECODE(kMainGameCode_nexonjp, kSubGameCode_luniatest),

    kGameCode_kickoff           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_kickoff),
    kGameCode_kickofftest       = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_kickofftest),

    kGameCode_elsword           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_elsword),
    kGameCode_elswordtest       = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_elswordtest),    

    kGameCode_nanaimo           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_nanaimo),
    kGameCode_nanaimotest       = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_nanaimotest),

    kGameCode_cso               = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_cso),
    kGameCode_cso_cn            = MAKE_GAMECODE(kMainGameCode_nexoncn, kSubGameCode_cso),
    kGameCode_cso_tw            = MAKE_GAMECODE(kGameCode_nexontw, kSubGameCode_cso),
    kGameCode_csotest           = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_csotest),
    kGameCode_csointernal       = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_csointernal),
    kGameCode_csodevelopment    = MAKE_GAMECODE(kMainGameCode_nexoncom, kSubGameCode_csodevelopment),
};

// Reply code for login result to authentication server
typedef enum NMLoginAuthReplyCode {
    kLoginAuth_OK,                                // 성공
    kLoginAuth_ServerFailed           = 20000,    // 인증서버 실패 | authentication server failed
    kLoginAuth_ServiceShutdown        = 20002,    // 서비스 종료 | Service Shutdown
    kLoginAuth_NotAllowedLocale       = 20003,    // 시스템에 맞지 않는 로케일 | Not Allowed Locale
    kLoginAuth_WrongID                = 20006,    // 해당 아이디가 없거나 오류가 있음 | username/nexonid incorrect
    kLoginAuth_BlockedIP              = 20007,    // 제한된 아이피 | Blocked IP
    kLoginAuth_TempBlockedByLoginFail = 20008,    // 여러 차례 로그인 실패로 인해 임시로 사용 제한 | Temporarily Restricted Due to Multiple Login Failures
    kLoginAuth_TempBlockedByWarning   = 20009,    // 운영자에 의해 임시로 사용 제한 | temporarily restricted by operator
    kLoginAuth_BlockedByAdmin         = 20010,    // 운영자에 의해 사용 제한 | Restricted by Operator
    kLoginAuth_InvalidPassport        = 20015,    // 패스포트가 맞지 않음 | Passport incorrect
    kLoginAuth_NotAllowedServer       = 20021,    // 인증서버에서 받아들이지 않음 | Not accepted by authentication server
    kLoginAuth_UserNotExists          = 20025,    // 존재하지 않는 아이디 | User Not Exists
    kLoginAuth_WrongPassword          = 20026,    // 암호가 맞지 않음 | password incorrect
    kLoginAuth_WithdrawnUser          = 20027,    // 탈퇴한 회원 | removed user
    kLoginAuth_WrongOwner             = 20028,    // 본인 아님 인증된 유저 | Wrong Owner

    kLoginAuth_ModuleNotInitialized   = 30002,    // 메신저 모듈 초기화가 안되어 있음 | Messenger module not initialized
    kLoginAuth_ModuleInitializeFailed = 30003,    // 메신저 모듈 초기화에 실패 | Messenger module initialization failed
};

// Result Code for Messenger Reply
typedef enum NMMessengerReplyCode {
    kMessengerReplyOK                                    = 0,
    kMessengerReplyNewUser                               = 1,

    kMessengerReplyNotMine                               = -1,
    kMessengerReplyWrongId                               = -2,
    kMessengerReplyWrongPwd                              = -3,
    kMessengerReplyWrongClientVersion                    = -4,
    kMessengerReplyWrongMsgVersion                       = -5,
    kMessengerReplyServiceShutdown                       = -6,
    kMessengerReplyLockedByAnotherProcess                = -7,
    kMessengerReplySwitchSA                              = -8,
    kMessengerReplyWrongOwner                            = -9,
    kMessengerReplyBlockByAdmin                          = -10,
    kMessengerReplyTempBlockByWarning                    = -11,
    kMessengerReplyTempBlockByLoginFail                  = -12,
    kMessengerReplyMabiInfoSoapFail                      = -13,
    kMessengerReplyWrongPassport                         = -14,
    kMessengerReplyBlockedIp                             = -15,
    kMessengerReplyTempUser                              = -16,
    kMessengerReplyNotAuthenticated                      = -17,
    
    kMessengerReplyInvalidExternalPassportType           = -18,
    kMessengerReplyExternalPassportDecoderNotImplemented = -19,
    kMessengerReplyExternalPassportDecodingFailed        = -20,
    kMessengerReplyWrongExternalPassport                 = -21,

    kMessengerReplyServerFailed                          = -99,
};

typedef enum NMREFRESHTYPE {
    kRefresh_NULL      = 0,

    kRefresh_Avatar    = 1,
    kRefresh_GameMoney = 2,
    kRefresh_NickName  = 3,
    kRefresh_Config    = 4,

    kRefresh_GuildInfo = 100,
    kRefresh_GuildList = 101,
};

typedef enum NMCONFIRMCODE {
    kConfirmUnknown					= 0,
    kConfirmOK						= 1,
    kConfirmDenied					= 2,
    kConfirmLater					= 3,
    kConfirmNext					= 4,
};

// Enumeration Types
typedef enum NMUSERSTATUS {
    kStatus_Unknown			= 0,

    kStatus_Online			= 10,		//	인증 OK, 메신저 OK
    kStatus_Busy			= 11,
    kStatus_Away			= 12,
    kStatus_AppearOffline	= 13,
    kStatus_Offline			= 14,		//	인증 --, 메신저 --
    kStatus_GameOnline		= 15,
    kStatus_Error			= 16,
    kStatus_Authenticated	= 17,		//	인증 OK, 메신저 --
};

typedef enum NMSYSTEMMSGCODE
{
    kSystemMsgCode_NULL					= 0,

    kSystemMsgCode_AdminNotice			= 1,
    kSystemMsgCode_Advertisement		= 2,
    kSystemMsgCode_ErrorMessage			= 3,
    kSystemMsgCode_GeneralMessage		= 4,
    kSystemMsgCode_WebNotice			= 5,
    kSystemMsgCode_Notify				= 6,
    kSystemMsgCode_ConnectionClose		= 7,

    kCustomMsgCode_RequestFriendOK		= 1,
    kCustomMsgCode_RequestFriendFailed	= 2,
    kCustomMsgCode_NoteReply			= 3,
};

struct NMGuildID {
    int nGameCode;
    int nServerCode;
    int nGuildSN;
};

// CNMSimpleStream
struct CNMSimpleStream {
    unsigned char* buf;
    int bReference;
    unsigned int bufLen;
    unsigned int bufMaxLen;
    unsigned int bufPtr;
    int bIsValid;
    char unk1;
    int unk2;
};

// CNMSimpleStreamDecoder
struct CNMSimpleStreamDecoder {
    struct CNMSerializableDecoder_vfptr* vftables;
    CNMSimpleStream* stream;
    void* mTempStr;
    void* mTempAscStr;
};

// CNMSimpleStreamEncoder
struct CNMSimpleStreamEncoder {
    CNMSimpleStream* stream;
};

// CNMSerializableEncoder
struct CNMSerializableEncoderTable {

};

struct CNMSerializableEncoder {
    CNMSerializableEncoderTable* vfptr;
    unsigned int uObjectLen;
    unsigned int uLenPtr;
};

// CNMSerializableDecoder
struct CNMSerializableDecoder_vfptr {
    unsigned int       (__thiscall* CNMSerializableDecoder__DecodeLen)(struct CNMSerializableDecoder* ptr);
    unsigned char      (__thiscall* CNMSerializableDecoder__Decode1)(struct CNMSerializableDecoder* ptr);
    unsigned short     (__thiscall* CNMSerializableDecoder__Decode2)(struct CNMSerializableDecoder* ptr);
    unsigned int       (__thiscall* CNMSerializableDecoder__Decode4)(struct CNMSerializableDecoder* ptr);
    unsigned long long (__thiscall* CNMSerializableDecoder__Decode8)(struct CNMSerializableDecoder* ptr);
    const wchar_t*     (__thiscall* CNMSerializableDecoder__DecodeStringW)(struct CNMSerializableDecoder* ptr);
    const wchar_t*     (__thiscall* CNMSerializableDecoder__DecodeStringW1)(struct CNMSerializableDecoder* ptr, const wchar_t* buf, unsigned int strLen);
    const char*        (__thiscall* CNMSerializableDecoder__DecodeStringA)(struct CNMSerializableDecoder* ptr);
    const char*        (__thiscall* CNMSerializableDecoder__DecodeStringA1)(struct CNMSerializableDecoder* ptr, const char* buf, unsigned int strLen);
    // ANSI
    //void               (__thiscall* CNMSerializableDecoder__DecodeString1)(CNMSerializableDecoder* ptr, const char* buf, unsigned int strLen);
    void               (__thiscall* CNMSerializableDecoder__DecodeString)(CNMSerializableDecoder* ptr, wchar_t* buf, unsigned int strLen);
    unsigned int       (__thiscall* CNMSerializableDecoder__DecodeBinary)(CNMSerializableDecoder* ptr, void* buf, unsigned int strLen);
};

struct CNMSerializableDecoder : CNMSimpleStreamDecoder {
    unsigned int uObjectLen;
    int bIsValid;
    unsigned char uDecodedVersion;
    unsigned int uStartPtr;
};

// ============== Vectors shit ==============
struct vector_NMSessionMemberList {
    struct CNMSessionMemberInfo* first;
    struct CNMSessionMemberInfo* last;
    struct CNMSessionMemberInfo* end;
};

struct vector_CNMGuildInfoEx {
    struct CNMGuildInfoEx* first;
    struct CNMGuildInfoEx* last;
    struct CNMGuildInfoEx* end;
};

typedef enum NMSEXTYPE {
    kSex_Unknown = 0,
    kSex_Male    = 1,
    kSex_Female  = 2,
};
typedef enum NMEMOTION {
    kEmotion_NULL     = 0,
    kEmotion_Normal   = 1,
    kEmotion_Smile    = 2,
    kEmotion_Cry      = 3,
    kEmotion_Angry    = 4,
    kEmotion_Nonsense = 5,
};

typedef enum NMALLOWTYPE {
    kConfigAllowValue_Unknown             = 0,
    kConfigAllowValue_FromAll             = 1,
    kConfigAllowValue_FromFriend          = 2,
    kConfigAllowValue_FromNoBody          = 3,
    kConfigAllowValue_FromFriendOrMatched = 4,
};

struct CNMSelfUserInfo : CNMRealUserInfo {
};

struct CNMChatRoomMemberInfo : CNMRealUserInfo {
    char szTel[0x20];
    NMVirtualKey keyVirtual;
    unsigned int uLevel;
    char szLevelName[0x40];
    unsigned int uFlag;
    unsigned int uIpAddr;
};

struct NMVirtualKey {
    int uGameCode;
    int uVirtualIDCode;
};

struct CNMVirtualUserInfo : CNMSerializable {
    NMVirtualKey vKey;
    wchar_t szNickName[32];
    wchar_t szPosition[256];
    wchar_t szMetaData[1000];
    int isVirtualOnline;
    int isStealth;
    int uLoginTick;
    int uLevel;
};

// ============== CNMSerializable ==============
struct CNMSessionMemberInfo : CNMSerializable {
    int unk1;
    unsigned long long uIDCode;
    wchar_t szLoginID[32];
    wchar_t szWord[32];

    NMVirtualKey keyVirtual;
    wchar_t szNickname[32];
    unsigned int uStatus;
    CNMAvatarFullInfo avatarInfo;
};

struct CNMCOClientObject_vt {
};
struct CNMCOClientObject {
    CNMCOClientObject_vt* vfptr;
    CRITICAL_SECTION critical;
    CNMRealUserInfo mRealUserInfo;
    vector mGOI;
    unsigned long long mSessionKeyHigh;
    unsigned long long mSessionKeyLow;
    unsigned int mUnreadNoteCount;
};

struct CNMGuildMemberInfo : CNMSerializable {
    unsigned long long uIdCode;
    char szLoginId[64];
    char szNickname[64];
    CNMAvatarItemInfo aiAvatarInfo;
    int bIsGameOnline;
    unsigned int uLevel;
    unsigned int uGameLevel;
    unsigned int uVirtualIdCode;
};

struct CNMGuildOnlineInfoEx : CNMSerializable {
    unsigned long long NMGuildKey;
    unsigned int uChatRoomSerialNo;
    unsigned int uChatRoomMemberCount;
    char szChatServerIP[32];
    unsigned short uChatServerPort;
    struct vector aOnlineGuildMembers;
    int unk;
};

struct CNMGuildOnlineInfo : CNMSerializable {
    unsigned long long uGuildSerialNo;
    unsigned int uChatRoomSerialNo;
    unsigned int uChatRoomMemberCount;
    char szChatServerIP[32];
    unsigned short uChatServerPort;
    struct vector aOnlineGuildMembers;
    int unk;
};

struct CNMEvent : CNMSerializable {
    NMEVENTCODE uCode;
    int bHandled;
    int bPassThrough;
    int bHasResult;
    int uRemainingCount;
    int uFlag;
};

struct CNMRequestNewFriendData : CNMSerializable {
    unsigned int uSerialNo;
    char szRequestID[0x40];
    NMGameCode uRequesteeGameCode;
    NMVirtualKey keyToVirtual;

    char szFromLoginID[0x40];
    NMVirtualKey keyFromVirtual;
    char szFromNickName[0x40];

    unsigned int uInsertCategoryCode;
    char szMessage[0x100];

    BOOL bAddToNxFriend;
};

struct CNMMessageData : CNMSerializable {
    signed int nCode;
    char szMessage[64];
};

struct CNMChatRoomInfoEx : CNMSerializable {
    unsigned int uRoomType;
    unsigned long long uGuildKey;
    unsigned int uRoomSerialNo;

    NMGameCode uGameCode;
    char szGuildTitle[0x40];
    char szRoomTitle[0x400];
    unsigned int uLimitLevel;
    unsigned int uMaxSize;
    unsigned int uFlag;
    char szPassword[0x40];

    unsigned long long uOwnerIdCode;
    struct vector aLevelInfo; // std::vector<CNMGuildMemberLevelInfo>

    unsigned int uStatus;
    unsigned int uRequestProcId;
};

struct CNMChatMessage : CNMSerializable {
    NMVirtualKey keyVirtual;
    CNMAvatarItemInfo aiAvatarItemInfo;

    char szSenderName[0x40];
    char szChatHeader[0x100];
    char szFontHeader[0x100];
    char szChatMessage[0x400];
    int uFlag;
};

typedef enum NMSESSIONTYPE {
    kSessionType_General			= 0,
    kSessionType_Chat				= 1,
    kSessionType_FileUpload			= 2,
    kSessionType_FileDownload		= 3,
    kSessionType_WhiteBoard			= 4,
};

struct NMFriendCode {
    NMIDCode uIDCode;
    NMVirtualKey keyVirtual;
};

struct CNMSessionInfo : CNMSerializable {
    NMSESSIONTYPE uType;
    NMVirtualKey keyVirtual;
    BOOL bPassive;

    unsigned int uInviteMode;
    unsigned int uMode;
    unsigned long long uId;
    NMFriendCode fcAssocFriend;

    unsigned int uStatus;
    unsigned int uServingProcessID;
};

struct CNMGuildInfoEx : CNMSerializable {
    NMGuildKey uGuildKey;

    char szName[64];
    char szId[32];
    NMGameCode uGameCode;

    char szHomeUrl[256];
    unsigned int uLevel;
    unsigned int uMemberCount;
    BOOL bHasNewContent;
    BOOL bIsMaster;
};


struct CNMGuildListExInfo : CNMSerializable {
    vector_CNMGuildInfoEx aGuilds; // vector<CNMGuildInfoEx>
};

struct CNMMyGameInfo : CNMSerializable {
    NMGameCode aGameCodes[10];
};

struct CNMChannelInfo : CNMSerializable {
    int channelSN;
    int userType;
    int channelType;
    int gameCode;
    int serverCode;
    void* title;
    void* password;
    int maxUserCount;
    unsigned int flag;
    int masterUserSN;
    int masterCharacterSN;
    int guildSN;
    void* guildName;
};
struct CNMClientChannelInfo : CNMChannelInfo {
    int nStatus;
    unsigned int uRequestProcessId;
};
struct CNMChannelMemberInfo : CNMChannelInfo {
    int userSN;
    int characterSN;

    void* name;
    void* metaData;
    unsigned int flag;
};

// ============== CNMEvent ==============
struct CNMMsgConnectionClosedEvent : CNMEvent {
    int iType;
};
struct CNMGuildOnlineInfoExEvent : CNMEvent {
    struct CNMGuildOnlineInfoEx goiInfo;
};
struct CNMUserInfoEvent : CNMEvent {
    CNMRealUserInfo ruiInfo;
};
struct CNMFriendInfoChangedEvent : CNMEvent {
    CNMFriendInfo friendInfo;
    int bAvatarInfoValid;
    CNMAvatarFullInfo avatarInfo;
};
struct CNMRealFriendInfoChangedEvent : CNMEvent {
    unsigned int uChangeFlag;
    CNMRealFriendInfo friendInfo;
    int bAvatarInfoValid;
    CNMAvatarFullInfo avatarInfo;
};
struct CNMMessengerReplyEvent : CNMEvent {
    NMMessengerReplyCode nResultCode;
};
struct CNMServerMessageEvent : CNMEvent {
    CNMMessageData msgData;
};
struct CNMCustomMessageEvent : CNMEvent {
    CNMMessageData msgData;
};

struct CNMRefreshEvent : CNMEvent {
    unsigned int uType;
};

struct CNMLogReportSyncEvent : CNMEvent {
    unsigned short uLogType;
};

struct CNMGSSessionCreatedEvent : CNMEvent {
    unsigned int uSerialKey;
    CNMSessionInfo siInfo;
    struct vector_NMSessionMemberList aMembers; // vector<CNMSessionMemberInfo>
    BOOL bHWNCreated;
    BOOL bByMsgRecv;
};

struct CNMCSChatMessageReceivedEvent : CNMEvent {
    unsigned int uSerialKey;
    CNMChatMessage cmMessage;
    BOOL bIsHandled;
};

struct CNMCRChatRoomMessageReceivedEvent : CNMEvent {
    unsigned int uSerialKey;
    CNMChatMessage cmMessage;
    BOOL bIsWhisper;
    BOOL bIsHandled;
};

struct CNMRequestNewFriendEvent : CNMEvent {
    CNMRequestNewFriendData rnfData;
};

struct CNMGSSessionClosedEvent : CNMEvent {
    unsigned int uSerialKey;
    CNMSessionInfo siInfo;
};

struct CNMChannelCreatedEvent : CNMEvent {
    unsigned int uSerialKey;
    CNMClientChannelInfo clientChannelInfo;
    CNMChannelMemberInfo channelMemberInfo;
};

struct CNMCRChatRoomCreatedExEvent : CNMEvent {
    unsigned int uSerialKey;
    CNMChatRoomInfoEx criInfo;
    CNMChatRoomMemberInfo crmiMyInfo;
};

struct CNMCRChatRoomErrorEvent : CNMEvent {
    unsigned int uSerialKey;
    unsigned int uType;
};

struct CNMGSSessionEstablishedEvent : CNMEvent {
	// event data
	unsigned int uSerialKey;
	CNMSessionInfo siInfo;
	vector_NMSessionMemberList aMembers;
	bool bWndCreated;
};

struct CNMGSSessionFailedEvent : CNMEvent {
	// event data
	unsigned int uSerialKey;
	CNMSessionInfo siInfo;
};
struct CNMGSSessionClosedEvent : CNMEvent {
	// event data
	unsigned int uSerialKey;
	CNMSessionInfo siInfo;
};

// ============== FUNC ==============
struct CNMSetLocaleFunc : CNMFunc {
    NMLOCALEID uLocaleID;
    unsigned int uRegionCode;
};

struct CNMInitializeFunc : CNMFunc {
    NMGameCode    uGameCode;
    NMSUPPORTFLAG uSupportFlag;
};

struct CNMRegisterCallbackFunc : CNMFunc {
    HWND         hWnd;
    unsigned int uMsg;
};

// 0x2540...
struct CNMLoginAuthFunc : CNMFunc {
    int uLoginType;
    char szPassport[8192];
    char szNexonID[512];
    char szPassword[256];
    int bSecondary;
    int nRegionCode;
    char szMID[512];
    int uFromSite;
    int nErrorCode;
};

struct CNMLogoutAuthFunc : CNMFunc {
    int bApplyToAllSession;
    int bSecondary;
};

struct CNMLoginAuthSecurityCNFunc : CNMFunc {
    void* szPassport;
    void* szSecurityData;
    int nErrorCode;
};

struct CNMGetMyInfoFunc : CNMFunc {
    CNMRealUserInfo nmUserInfo;
    unsigned long long uSessionKeyHigh;
    unsigned long long uSessionKeyLow;
    unsigned int uUnreadNoteCount;
    unsigned int uUnreadMailCount;
    const char szPassport[4096];
};

struct CNMGetFriendListFunc : CNMFunc {
    NMVirtualKey keyVirtual;
    vector_NMCategoryUserList aCateUserList; // std::vector<CNMCateFriendInfo>
    vector_NMFriendInfo aUnrelated;    // std::vector<CNMFriendInfo>
};

struct CNMRequestNewFriendFunc : CNMFunc {
    CNMRequestNewFriendData rnfData;
};

struct CNMLoginVirtualFunc : CNMFunc {
    char szUserId[64];
    NMVirtualKey keyUser;
    char szPosition[64];
};

struct CNMChangeMyPositionFunc : CNMFunc {
    NMVirtualKey keyUser;
    char szPosition[64];
};

struct CNMChangeNicknameFunc : CNMFunc {
    NMVirtualKey keyCharacter;
    char szNickname[0x40];
};

struct CNMGetGameShortNameFunc : CNMFunc {
    NMGameCode uGameCode;
    char szGameNameShort[128];
};

struct CNMResetCallbackFunc : CNMFunc {
    HWND hHWND;
};

struct CNMLogoutVirtualFunc : CNMFunc {
    NMVirtualKey keyUser;
};

struct CNMLogReportSyncFunc : CNMFunc {
    unsigned short uLogType;
};

struct CNMGetConfigFunc : CNMFunc {
    unsigned int uFlag;
    NMALLOWTYPE uAllowChatType;
    NMALLOWTYPE uAllowNoteTYpe;
    NMALLOWTYPE uAllowGameInviteType;
    NMALLOWTYPE uAllowRequestFriendType;
    CNMMyGameInfo mgiGameInfo;
};

struct CNMGetMyGuildListExFunc : CNMFunc {
    CNMGuildListExInfo gliGuildList;
};

struct CNMConfirmNewFriendFunc : CNMFunc {
    unsigned int uSerialNo;
    NMCONFIRMCODE uConfirmCode;
    unsigned int uInsertCategoryCode;
};

struct CNMDeleteFriendFromCategoryFunc : CNMFunc {
    NMFriendKey keyFriend;
    unsigned int uCategoryCode;
    BOOL bSystemCall;
};

struct CNMMonitorGuildOnlineInfoExFunc : CNMFunc {
    NMGuildKey uGuildKey;
    BOOL bMonitorAttach;
    unsigned int uServingProcessID;
    unsigned int uGameCode;
    unsigned int uVirtualIDCode;
};

struct CNMGSWantCloseFunc : CNMFunc {
    BOOL bForceClose;
};

struct CNMCRGetMemberInfoFunc : CNMFunc {
    unsigned int uType;
    CNMChatRoomMemberInfo crmiInfo;
};

struct CNMCRSendChatMessageFunc : CNMFunc {
    unsigned long long aToIdCode[10];
    CNMChatMessage chatMsg;
};

struct CNMCRCloseFunc : CNMFunc {
};

struct CNMSendRefreshMessageFunc : CNMFunc {
    NMREFRESHTYPE uRefreshType;
};

struct CNMGSGetSessionInfoFunc : CNMFunc {
    CNMSessionInfo siInfo;
    struct vector_NMSessionMemberList aMembers; // vector<CNMSessionMemberInfo>
};

struct CNMCSSendChatMessageFunc : CNMFunc {
    CNMChatMessage chatMsg;
};

struct CNMGSWantCloseFunc : CNMFunc {
    BOOL bForceClose;
};

struct CNMGSRegisterCallbackFunc : CNMFunc {
    HWND hHWND;
    unsigned int uMSG;
};

struct CNMGSInviteUserExFunc : CNMFunc {
    NMFriendCode keyFriend;
    int unk;
};

struct CNMRequestChatSessionExFunc : CNMFunc {
    NMFriendKey keyFriend;
    unsigned int uServingProcessID;

    unsigned int uExistingSerialKey;
    unsigned int uCreatedSerialKey;
};

struct CNMGSGetMemberListFunc : CNMFunc {
    struct vector_NMSessionMemberList aMembers; // std::vector<CNMSessionMemberInfo>
};

struct CNMLogoutMessengerFunc : CNMFunc {
    
};

struct CNMCRRegisterCallbackFunc : CNMFunc {
    HWND hWnd;
    unsigned int uMsg;
};

// ============== Others ==============
struct CNMCRChatRoom {
    void* vfptr;
    int unk1;
    unsigned int m_uSerialKey;
    int unk2;
    CNMChatRoomInfoEx m_criInfo;
};

struct CNMGSGeneralSession {
    void** vfptr;
    
    int NMManagerptr;
    BOOL bNicknameValid;
    char szTempBuffer[256];
    char szMyNickname[64];
    char szOppositeNickname[64];
    unsigned int uSerialKey;
    CNMSessionInfo siInfo;
};

struct CNMCSChatSession : CNMGSGeneralSession {

};

