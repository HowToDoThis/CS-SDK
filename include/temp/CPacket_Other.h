struct CPacket_ZBEnhance : Packet
{
    int type;
    int unk2; // some initialization
    int unk3;
    int unk4;
    int unk5;
};

struct Packet_Host : Packet
{
    int hostID;
    int type;
    uint ip;
    int port;
    ushort gameDataSize;
    void* gameData; // array
    ushort playerCount;
    void* playerData; // array
    unsigned char crashFlag;

    int useScenUserID;
    short useScenItemID;
    char useScenUnk;
    int unk1;
};

typedef enum ReplyCode_s {
    S_REPLY_YES = 0,
    InvalidName = 3,
    Playing = 4,
    WrongPassword = 7,
    InvalidPassword = 8,
    ServerDown = 9,
    SysError = 10,
    InvalidServer = 11,
    InvalidSlot = 12,
    ID_NOT_ALLOWD = 14,
    NEXONCOMERROR = 15,
    NEXONCOM_PASSPORTERROR = 16,
    NEXONCOM_INVALID_SESSION = 17,

    S_REPLY_CREATEOK = 1,
    INVALID_USERINFO = 18,
    TRANSFER_ERR = 19,
    ID_TOO_SHORT = 20,
    ID_TOO_LONG = 21,
    INVALID_CHAR = 22,
    ID_DIGIT_BEFORE_CHAR = 23,
    ID_EXCEED_CHAR_COUNT = 24,
    ALREADY_EXIST = 25,
    ID_PROHIBITED = 26,
    EXCEED_MAX_CONNECTION = 27,
    NEXONCOM_UNDER_AGE = 28,
    INVALID_CLIENT_VERSION = 38,
    OTP_ERROR = 46,
} ReplyCode_t;

struct Packet_Reply : Packet {
    ReplyCode_t subType;
    char* reply;
};

struct Packet_Version : Packet {
    int subType;
};

struct Packet_SearchRoom : Packet {
    char subType;
    int unk1; // 1
    int unk2; // 2
    int unk3; // 3 (2)

    // if unk7 == 1
    char* unk4;
    char* unk5;

    char* unk6;
    int unk7; // 0
    int unk8;
    int unk9;
    int unk10; // 5 (2)

    // room related
    int gameMode;
    int mapID;
    int playerCount;
    int maxPlayerCount;
    int friendly;
    int arms;
    int random;

    int unk11; // size (read 1b 1b, randomMap related)
    int unk12[10];

    int unk13;
    char* unk14;
};

struct Packet_QuickStart : Packet {
    int unk1;
    int unk2;
};

struct Packet_Transfer : Packet
{
    uint serverIP;
    ushort port;
    int unk3;
    const char* userName;
    char unk5;
    char unk6;
};

struct Packet_Room : Packet
{
    int unk1;
    int type;
    int roomID;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
};

struct Packet_UserStart : Packet
{
    int userID;
    const char* userName;
    const char* gameName;
    char bFirstTime;
    int iCountryCode;
    int iRegionCode;
    int iNexonOID;
};

struct Packet_ClientCheck : Packet
{
    char* szCPUName;
    char* szGPUName;
    int iCPUHertz;
    int iShiftedMemory;
    int iUpload;
    int unk6;
    int iNetworkConfig;
    int unk8;
};

struct Packet_UMsg : Packet {
    int u1;
    unsigned int iSubType;
    int szSender;
    int szMessage;

    int szUnkString;
    bool bIsReceiver;

    int iSubType2;

    wstring szRewardTitle;
    wstring szRewardDescription;

    vector vReward1;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
};

struct Packet_RoomList : Packet {
    int subType;
    struct CGameRoom pGameRoom;
    int u2;
};