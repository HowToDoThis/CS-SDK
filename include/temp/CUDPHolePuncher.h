// Ping Room
struct UDP_Packet_5 {
    char sign; // `
    char nf1;
    unsigned short port;
    char seq;
};

// Heartbeat?
struct UDP_Packet_7 {
    char sign; // W
    int userID;
    char type;
    char seq;
};

// Set UDP?
struct UDP_Packet_14 {
    char sign; // W
    int userID;
    char type;
    char socket;
    int localIP; // ~this->localIP
    short port;
    char seq;
};

// CHN160531 Size 1D8 (472)
struct CUDPHolePuncher
{
    void* vfptr;

    sockaddr_in server;
    int state;
    unsigned int nf3;
    int iUserID1;
    unsigned int localIP2;
    int iUserID2;
    SOCKET sockA;
    SOCKET sockB;
    unsigned short clientPort;
    unsigned short serverPort;
    int iLastSent;
    unsigned short iTickA;
    unsigned short iTickB;
    unsigned short unkCount;
    short unk15;
    
    int iTimer; // GetTickCount + 2000
    const char szCommand[252];
    
    struct vector unk17;

    int u3;
    struct list u4;
    int u6;

    int nf1[20];

    HANDLE hThread;

    int iU1[6];
    int u7;
    short u7A;
    short u7B;
    int u8;
    int u9;
    int u10;
};