typedef bool (*pfnMatchDataFunc)(class Packet_Match* ptr, struct CPacketReader* reader);

struct map_Match_Data {
    pfnMatchDataFunc func;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
};

struct pair_Packet_Match {
    int first;
    map_Match_Data second;
};

struct mapNode_Packet_Match {
    pair_Packet_Match* _Left;
    pair_Packet_Match* _Parent;
    pair_Packet_Match* _Right;
    char _Color;
    char _Isnil;
    pair_Packet_Match _Myval;
};

struct map_Packet_Match {
    mapNode_Packet_Match* _Myhead;
    unsigned int _Mysize;
};

class Packet_Match : public Packet
{
public:
    CClanMatchManager* mgr; // some func
    struct KeyValues* kv;
    map_Packet_Match map;
    int unk3;
    int type;
};

struct Match_u1 {
    wstring u01;
    int u07;
    char level;
    char u08;
    int u09;
    wstring u10;

    int u16; // map
    int u17;

    short u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int u23;
};

struct Match_u2 {
    int u00;
    short u01;
    int u02;
    int u03;
    int u04;
    int u05;
    int u06;
    int u07;
    short u08;
    int u09;
    int u10;
    int u11;
    int u12;
    int u13;
    short u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;

    int u22[6];

    char u28;
    int u29;
    int u30;
    int u31;
    int u32;
    int u33;
    int u34;
    int u35;
    char u36;
    int u37;
    int u38;
    int u39;
    int u40;

    int u41; // map
    int u42;
};

struct Match_u3 {
    int userID;
    int u01;
    int u02;
    int serverID;
    int channelID;
    int u05;
    int u06;
    int max;
    char u08;
    int u09;
    int u10;
    int u11;
    short u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    short u23;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    int u30;
    int u31;
};

// 0x300
class CClanMatchManager {
public:
    virtual void Init();
    virtual void Function2(int); // unk003
    virtual void Function3(int); // unk003
    virtual bool IsServerCategory13();
    virtual void Set001(int);
    virtual int Get001();
    virtual void Function7();
    virtual void Get029();
    virtual void Function9(); // call func12
    virtual void Function10(int, int*);
    virtual Match_u1* Function11(wstring*);
    virtual Match_u1* Function12();
    virtual Match_u2* Get031();
    virtual void SendGameMatch0_1();
    virtual void SendGameMatch0_2();
    virtual void SendGameMatch0_3();
    virtual void SendGameMatch0_12();
    virtual void SendGameMatch0_4();
    virtual void SendGameMatch0_5();
    virtual void SendGameMatch0_9or10();
    virtual void SendGameMatch0_6();
    virtual void SendGameMatch0_11();
    virtual void Function23(); // unk031.u22 >= 2
    virtual void Function24(); // unk031.u28 >= 2
    virtual void SendGameMatch0_15();
    virtual void SendGameMatch0_16();
    virtual void SendGameMatch0_17();
    virtual void SendGameMatch1_0();
    virtual void SendGameMatch1_1();
    virtual void SendGameMatch1_2();
    virtual void SendGameMatch1_6();
    virtual void Send2ndPassword1_3();
    virtual void SendGameMatch1_5();
    virtual void Function34(int*);
    virtual unsigned char Get077();
    virtual wstring* Function36(wstring*);
    virtual void Function37();
    virtual char* Get078();
    virtual void SendGameMatch3_0();
    virtual void SendGameMatch3_1();
    virtual void SendGameMatch3_2();
    virtual void SendGameMatch4_1();
    virtual void SendGameMatch4_16();
    virtual void SendGameMatch4_13();
    virtual void SendGameMatch3_3();
    virtual char Get103();
    virtual void Set103();
    virtual void GetTime(); // return 032[43]
    virtual char* Get090();
    virtual Match_u3* Get096();
    virtual void SendGameMatch2_4();
    virtual void SendGameMatch2_2();
    virtual void SendGameMatch2_0();
    virtual void SendGameMatch2_5or6or7();
    virtual int  Get108or104(int); // if 1 or 3 or 4, return 108 else return 104
    virtual int  Get105or116(int);
    virtual void Get119or122else109(); // if 6 return 118 else if 7 return 121 else return 109
    virtual Match_u2* Get112();
    virtual Match_u1* Function59(wstring*);
    virtual Match_u1* Function60();

public:
    void* packetListener;

    int unk001;
    struct Packet_Match* gPacket_Match;
    vector unk003;

    Match_u1 unk006;

    char unk029;
    int unk030;

    Match_u2 unk031;
    int unk032;
    long long iTime;

    char unk077;

    // some struct??
    int unk078;
    int unk079;
    wstring unk080;
    int unk086;

    int unk087;
    int unk088;

    int unk089;

    // some struct??
    short unk090;
    int unk091;
    int unk092;
    int unk093;
    int unk094;
    int unk095;

    Match_u3 unk096;

    char unk103;
    int unk104;
    int unk105;
    int unk106;
    int unk107;
    int unk108;
    int unk109;
    int unk110;
    int unk111;

    Match_u2 unk112;

    int unk115;
    int unk116;
    int unk117;
    int unk118;
    int unk119;
    int unk120;
    int unk121;
    int unk122;
    int unk123;
    int unk124;
    int unk125;
};

