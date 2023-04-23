struct CSocket_vtable
{

};
struct CSocket
{
    CSocket_vtable* vfptr;
    SOCKET socket;
    sockaddr_in socketInfo; // original sockaddr
    SSL* ssl;
    char crypt;
    char crypt2;
    int unk8;  // optval
    int unk9;  // buffSize
    char* szSendBuffer; // optval
    char* bufferB; // buffSize
    int iSent; // optval
    int unk13; // buffSize
    char unk14A;
    char unk14B;
    char sequence;
    int optVal;
    int bufferSize;
    char unk17;
    char unk18A;
    char unk18B;
    char unk18C;
    struct EVP_CIPHER_CTX* ctx2;
    char szUnk1[121];
    // related EVP or ENCRYPT
    int tempa;
    int tempb;
    int tempc;
    struct EVP_CIPHER_CTX* ctx;
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
    char* header;
    char* lastError; // related string, prob lastError
};

struct CLogFile
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

// can reference as PacketID
struct CSocketManagerPacket
{
    struct CPacket* gVersion; // 0
    struct CPacket* gReply;
    struct CPacket* gTransfer;
    struct CPacket* gLogin;
    struct CPacket* unk4;
    struct CPacket* gServerList; // 5
    struct CPacket* gCreateCharacter;
    struct CPacket* gRequestRoomList;
    struct CPacket* unk8[2];
    struct CPacket* gChannelList; // 10
    struct CPacket* unk11;
    struct CPacket* gRecvCrypt;
    struct CPacket* unk13[2];
    struct CPacket* gMileageBingo; // 15
    struct CPacket* gStatistics;
    struct CPacket* unk14;
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
    struct CPacket* gUnk75;
    struct CPacket* gOption;
    struct CPacket* gFavourite;
    struct CPacket* gItem; // 78
    struct CPacket* unk79a;
    struct CPacket* gSearchRoom; // 80
    struct CPacket* gHostServer;
    struct CPacket* gHShield;
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
    struct CPacket* iunk2[47];
    struct CPacket* gUserStart; // 150
    struct CPacket* gRoomList;
    struct CPacket* gInventory_Default;
    struct CPacket* gLobby;
    struct CPacket* gInventory;
    struct CPacket* gInventory_ClanStock; // 155
    struct CPacket* gInventory_CafeItems;
    struct CPacket* gUserInfo;
    struct CPacket* gInventory_FabItems;
    struct CPacket* gEvent;
    struct CPacket* gInventory_Costume; // 160
    struct CPacket* gZombieScenarioMaps;
    struct CPacket* gInventory_RotationWeapon;
    struct CPacket* unkb;
    struct CPacket* gAlarm; // 164
    struct CPacket* iunk3[35]; // 49 + gUserStart
    struct CPacket* iunk4[55];
    struct CPacket* iunk5;
};

struct TestStuff
{
    TestStuff* prev;
    TestStuff* next;
    int unk3;
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
    TestStuff* unk9; // some holder
    CLogFile* log;
    CRITICAL_SECTION critical;
};