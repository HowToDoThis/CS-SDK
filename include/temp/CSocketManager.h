struct CSocket_vtable
{

};
struct CSocket
{
    CSocket_vtable* vfptr;
    SOCKET socket;
    sockaddr_in socketInfo; // original sockaddr
    struct SSL* ssl;
    char crypt;
    char crypt2;
    int unk8;
    int unk9;
    unsigned char* szSendBuffer1;
    unsigned char* szSendBuffer2;
    unsigned char* szSendFinal;
    int unk13;
    char unk14A;
    char unk14B;
    char sequence;
    int iUnk1;
    int iUnk2;
    char bReadWithEVP;
    char bSendWithEVP;
    char unk18B;
    char unk18C;
    struct EVP_CIPHER_CTX ctxRecvEncrypt;
    struct EVP_CIPHER_CTX ctxRecvDecrypt;
    struct EVP_CIPHER_CTX ctxSendEncrypt;
    struct EVP_CIPHER_CTX ctxSendDecrypt;
    int unk18;
    char* packetData;
    char* lastError; // related string, prob lastError
};

struct LogFile
{
    FILE* fs;
    char flush; // flush
    CRITICAL_SECTION critical;
    void (__cdecl *function)(void*);
};

struct CSocketManager_vtable
{
    void (__thiscall* descructor)(struct CSocketManager* ptr, int);
};

struct CSocketManagerPacket
{
    struct CPacket* gVersion; // 0
    struct CPacket* gReply;
    struct CPacket* gTransfer;
    struct CPacket* gLogin;
    struct CPacket* unk4;
    struct CPacket* gServerList; // 5
    struct CPacket* gCreateCharacter;
    struct CPacket* gCrypt;
    struct CPacket* gUnk8;
    struct CPacket* gUnk9;
    struct CPacket* gChannelList; // 10
    struct CPacket* gUnk11;
    struct CPacket* gRecvCrypt;
    struct CPacket* gUnk13;
    struct CPacket* gUnk14;
    struct CPacket* gMileageBingo; // 15
    struct CPacket* gStatistics;
    struct CPacket* gSessionID;
    struct CPacket* gMobile; // 18
    struct CPacket* unka[46];
    struct CPacket* gRoom; // 65
    struct CPacket* gClientCheck;
    struct CPacket* gUMSG;
    struct CPacket* gHost;
    struct CPacket* gUpdateInfo; // 69
    struct CPacket* gUDP; // 70
    struct CPacket* gClan;
    struct CPacket* gShop;
    struct CPacket* gRank;
    struct CPacket* gBan;
    struct CPacket* gUnk75; // 75
    struct CPacket* gOption;
    struct CPacket* gFavourite;
    struct CPacket* gItem; // 78
    struct CPacket* gGameGuard;
    struct CPacket* gSearchRoom; // 80
    struct CPacket* gHostServer;
    struct CPacket* gHackShield;
    struct CPacket* gReport;
    struct CPacket* gTitle;
    struct CPacket* gBuff;       // 85
    struct CPacket* gQuickStart; // 86
    struct CPacket* gUserSurvey;
    struct CPacket* gQuest;
    struct CPacket* gMinigame;
    struct CPacket* gHack; // 90
    struct CPacket* gMetadata;
    struct CPacket* gSNS;
    struct CPacket* gMessenger;
    struct CPacket* gComrade;
    struct CPacket* gWeeklyClanLeague; // 95
    struct CPacket* gGiftItem;
    struct CPacket* g2ndPassword;
    struct CPacket* g2ndPassword2;
    struct CPacket* gGameMatch;
    struct CPacket* gZBEnhance; // 100
    struct CPacket* gCleanSystem;
    struct CPacket* gRibbonSystem; // 102
    struct CPacket* gVoxel; // Packet_VoxelGameSave & Packet_VoxelOutUI
    struct CPacket* gWeaponAuctionEvent;
    struct CPacket* gAnalysis; // 105
    struct CPacket* gLiveStream;
    struct CPacket* gCoDissamble;
    struct CPakcet* gMileageShop; // 108
    struct CPakcet* gHelp;
    struct CPacket* gPopularInfo; // 110
    struct CPacket* undefc;
    struct CPacket* gKick;
    struct CPacket* gHonorShop;
    struct CPacket* gEpicPieceShop; // 114
    struct CPacket* gAddon; // 115
    struct CPacket* gQuestBadgeShop; // 116
    struct CPacket* gundefi;
    struct CPacket* gSeasonSystem;
    struct CPacket* gundefj;
    struct CPacket* gGuideQuest; // 120
    struct CPacket* iunk2[29];
    struct CPacket* gUserStart; // 150
    struct CPacket* gRoomList;
    struct CPacket* gInventory_Default;
    struct CPacket* gLobby;
    struct CPacket* gInventory;
    struct CPacket* gInventory_ClanStock; // 155
    struct CPacket* gInventory_CafeItems;
    struct CPacket* gUserUpdateInfo;
    struct CPacket* gInventory_FabItems;
    struct CPacket* gEvent;
    struct CPacket* gInventory_Costume; // 160
    struct CPacket* gZombieScenarioMaps;
    struct CPacket* gInventory_RotationWeapon;
    struct CPacket* gSaleCoupon;
    struct CPacket* gAlarm; // 164
    struct CPacket* gInventory_MonthlyWeapon; // 165
    struct CPacket* gInventory_LiveWeapon;
    struct CPacket* gVIP;
    struct CPacket* gInventory_FreePassWeapon;
    struct CPacket* gServerLog;
    struct CPacket* undefg; // 170
    struct CPacket* gNxLog;
    struct CPacket* gDictionary; // encyclopedia
    struct CPacket* testpacket; // ???
    struct CPacket* gZBSGoldenZB;
    struct CPacket* gFriend; // 175
    struct CPacket* gInventory_EventItem;
    struct CPacket* gExpedition;
    struct CPacket* gScenarioTX;
    struct CPacket* gUserRestrict;
    struct CPacket* gLeague; // 180
    struct CPacket* gInventory_Class;
    struct CPacket* gInventory_Parts;
    struct CPacket* gInventory_Item;
    struct CPacket* gSwitchConfig;
    struct CPacket* iunk3[71];
};

struct TestStuff
{
    TestStuff* prev;
    TestStuff* next;
    int unk3;
};

struct CSocketManager
{
    struct CSocketManager_vtable* vfptr;
    struct CSocket* socket;
    int unk2;
    HWND windowHandle;
    //CSocketManagerPacket packets; // just a easier way to know packetID
    struct CPacket* packetFunction[0x100];
    //int unk10;
    char encrypt;
    char unk6;
    int unk7;
    int unk8;
    TestStuff* unk9; // some holder
    LogFile* log;
    CRITICAL_SECTION critical;
};

struct CSocketManagerOld
{
    void* vfptr; // only 1 desctructor
    int unk2;
    int unk3;
    int unk4;
    struct CPacket* packet[0x100];
    char encrypt;
    char unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
};