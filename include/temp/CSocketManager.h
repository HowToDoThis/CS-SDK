struct CSocket;
struct CSocket_vtable
{

};
struct CSocket
{
    CSocket_vtable* vfptr;
    SOCKET socket;
    sockaddr_in socketInfo; // original sockaddr
    int* ssl;  // encrypt related
    char unk7A; // encrypt related
    char unk7B;
    int unk8;  // optval
    int unk9;  // buffSize
    char* bufferA; // optval
    char* bufferB; // buffSize
    int unk12; // optval
    int unk13; // buffSize
    char unk14A;
    char unk14B;
    char unk15;
    int optVal;
    int bufferSize;
    char unk17;
    char szUnk1[128];
    // related EVP or ENCRYPT
    int tempa;
    int tempb;
    int tempc;
    int ctx;
    int tempe;
    int tempf;
    int tempg;
    int temph;
    char temp1[64];
    char temp2[32];
    char szUnk1b[256];
    char szUnk2[32];
    char szUnk3[16];
    int unk18;
    int unk19;
    char* lastError; // related string, prob lastError
};

struct CLogFile
{
    FILE* file;
    char flush; // flush
    LPCRITICAL_SECTION critical;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8; // function pointer?
    int unk9;
    int unk10;
    int unk11;
};

struct CSocketManager;
struct CSocketManager_vtable
{
    
};

// can reference as PacketID
struct CSocketManagerPacket
{
    int gVersion; // 0
    int gReply;
    int gTransfer;
    int gLogin;
    int unk4;
    int gServerList; // 5
    int gCreateCharacter;
    int gRequestRoomList;
    int unk8[2];
    int gChannelList; // 10
    int unk11;
    int gRecvCrypt;
    int unk13[2];
    int gMileageBingo; // 15
    int gStatistics;
    int unk14;
    int gMobile; // 18
    int unka[46];
    int gRoom; // 65
    int gClientCheck;
    int gUMSG;
    int gHost;
    int gUpdateInfo; // 69
    int gUDP; // 70
    int gClan;
    int gShop;
    int gRank;
    int gBan;
    int gOption;
    int gFavourite;
    int gItem; // 78
    int gItem2;
    int unk79a;
    int gSearchRoom; // 80
    int gHostServer;
    int gHShield;
    int gReport;
    int gTitle;
    int gBuff;       // 85
    int gQuickStart; // 86
    int gUserSurvey;
    int gQuest;
    int gMinigame;
    int gHack; // 90
    int gMetadata;
    int gSNS;
    int gMessenger;
    int gComrade;
    int gWeeklyClanLeague; // 95
    int gGiftItem;
    int g2ndPassword;
    int g2ndPassword2;
    int gGameMatch;
    int gZBEnhance; // 100
    int gCleanSystem;
    int gRibbonSystem; // 102
    int iunk2[47];
    int gUserStart; // 150
    int gRoomList;
    int gInventory_Default;
    int gLobby;
    int gInventory;
    int gInventory_ClanStock; // 155
    int gInventory_CafeItems;
    int gUserInfo;
    int gInventory_FabItems;
    int gEvent;
    int gInventory_Costume; // 160
    int gZombieScenarioMaps;
    int gInventory_RotationWeapon;
    int unkb;
    int gAlarm; // 164
    int iunk4[35]; // 49 + gUserStart
    int iunk3[56];
};

struct CSocketManager
{
    CSocketManager_vtable* vfptr;
    CSocket* socket;
    int unk2;
    HWND windowHandle;
    CSocketManagerPacket packets;
    char encrypt;
    char unk6;
    int unk7;
    int unk8;
    int* unk9; // some holder
    CLogFile* log;
    LPCRITICAL_SECTION* critical;
};