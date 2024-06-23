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
    char iSequenceRecv;
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
    void (__thiscall* destcructor)(struct CSocketManager* ptr, int);
};

struct CSocketManagerPacket
{
    struct Packet* gVersion; // 0
    struct Packet* gReply;
    struct Packet* gTransfer;
    struct Packet* gLogin;
    struct Packet* unk4;
    struct Packet* gServerList; // 5
    struct Packet* gCreateCharacter;
    struct Packet* gCrypt;
    struct Packet* gUnk8;
    struct Packet* gUnk9;
    struct Packet* gChannelList; // 10
    struct Packet* gUnk11;
    struct Packet* gRecvCrypt;
    struct Packet* gUnk13;
    struct Packet* gUnk14;
    struct Packet* gMileageBingo; // 15
    struct Packet* gStatistics;
    struct Packet* gSessionID;
    struct Packet* gMobile; // 18
    struct Packet* unka[46];
    struct Packet* gRoom; // 65
    struct Packet* gClientCheck;
    struct Packet* gUMSG;
    struct Packet* gHost;
    struct Packet* gUpdateInfo; // 69
    struct Packet* gUDP; // 70
    struct Packet* gClan;
    struct Packet* gShop;
    struct Packet* gRank;
    struct Packet* gBan;
    struct Packet* gUnk75; // 75
    struct Packet* gOption;
    struct Packet* gFavourite;
    struct Packet* gItem; // 78
    struct Packet* gGameGuard;
    struct Packet* gSearchRoom; // 80
    struct Packet* gHostServer;
    struct Packet* gHackShield;
    struct Packet* gReport;
    struct Packet* gTitle;
    struct Packet* gBuff;       // 85
    struct Packet* gQuickStart; // 86
    struct Packet* gUserSurvey;
    struct Packet* gQuest;
    struct Packet* gMinigame;
    struct Packet* gHack; // 90
    struct Packet* gMetadata;
    struct Packet* gSNS;
    struct Packet* gMessenger;
    struct Packet* gComrade;
    struct Packet* gWeeklyClanLeague; // 95
    struct Packet* gGiftItem;
    struct Packet* g2ndPassword;
    struct Packet* g2ndPassword2;
    struct Packet* gGameMatch;
    struct Packet* gZBEnhance; // 100
    struct Packet* gCleanSystem;
    struct Packet* gRibbonSystem; // 102
    struct Packet* gVoxel; // Packet_VoxelGameSave & Packet_VoxelOutUI
    struct Packet* gWeaponAuctionEvent;
    struct Packet* gAnalysis; // 105
    struct Packet* gLiveStream;
    struct Packet* gCoDissamble;
    struct CPakcet* gMileageShop; // 108
    struct CPakcet* gHelp;
    struct Packet* gPopularInfo; // 110
    struct Packet* undefc;
    struct Packet* gKick;
    struct Packet* gHonorShop;
    struct Packet* gEpicPieceShop; // 114
    struct Packet* gAddon; // 115
    struct Packet* gQuestBadgeShop; // 116
    struct Packet* gundefi;
    struct Packet* gSeasonSystem;
    struct Packet* gundefj;
    struct Packet* gGuideQuest; // 120
    struct Packet* iunk2[29];
    struct Packet* gUserStart; // 150
    struct Packet* gRoomList;
    struct Packet* gInventory_Default;
    struct Packet* gLobby;
    struct Packet* gInventory;
    struct Packet* gInventory_ClanStock; // 155
    struct Packet* gInventory_CafeItems;
    struct Packet* gUserUpdateInfo;
    struct Packet* gInventory_FabItems;
    struct Packet* gEvent;
    struct Packet* gInventory_Costume; // 160
    struct Packet* gZombieScenarioMaps;
    struct Packet* gInventory_RotationWeapon;
    struct Packet* gSaleCoupon;
    struct Packet* gAlarm; // 164
    struct Packet* gInventory_MonthlyWeapon; // 165
    struct Packet* gInventory_LiveWeapon;
    struct Packet* gVIP;
    struct Packet* gInventory_FreePassWeapon;
    struct Packet* gServerLog;
    struct Packet* undefg; // 170
    struct Packet* gNxLog;
    struct Packet* gDictionary; // encyclopedia
    struct Packet* testpacket; // ???
    struct Packet* gZBSGoldenZB;
    struct Packet* gFriend; // 175
    struct Packet* gInventory_EventItem;
    struct Packet* gExpedition;
    struct Packet* gScenarioTX;
    struct Packet* gUserRestrict;
    struct Packet* gLeague; // 180
    struct Packet* gInventory_Class;
    struct Packet* gInventory_Parts;
    struct Packet* gInventory_Item;
    struct Packet* gSwitchConfig;
    struct Packet* iunk3[71];
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
    struct Packet* packetFunction[0x100];
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
    struct Packet* packet[0x100];
    char encrypt;
    char unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
};