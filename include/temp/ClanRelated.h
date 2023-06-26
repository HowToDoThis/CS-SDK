struct Packet_Match : CPacket
{
    int unk1; // a2
    struct KeyValues* kv;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
};

struct CClanMatchManager_tables
{
    void (__thiscall* InitPacket)(struct CClanMatchManager* this);
    void (__thiscall* Function2)(struct CClanMatchManager* this);
    void (__thiscall* Function3)(struct CClanMatchManager* this);
    bool (__thiscall* IsServerCategory13)(struct CClanMatchManager* this);
    void (__thiscall* Function5)(struct CClanMatchManager* this);
    void (__thiscall* Get001)(struct CClanMatchManager* this);
    void (__thiscall* Function7)(struct CClanMatchManager* this);
    void (__thiscall* Get029)(struct CClanMatchManager* this);
    void (__thiscall* Function9)(struct CClanMatchManager* this);
    void (__thiscall* Function10)(struct CClanMatchManager* this);
    void (__thiscall* Function11)(struct CClanMatchManager* this);
    void (__thiscall* Function12)(struct CClanMatchManager* this);
    void (__thiscall* Get031)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_1)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_2)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_3)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_12)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_4)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_5)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_9or10)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_6)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_11)(struct CClanMatchManager* this);
    void (__thiscall* Function23)(struct CClanMatchManager* this); // check 032[21] >= 2
    void (__thiscall* Function24)(struct CClanMatchManager* this); // check 032[27] >= 2
    void (__thiscall* SendGameMatch0_15)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_16)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch0_17)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch1_0)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch1_1)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch1_2)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch1_6)(struct CClanMatchManager* this);
    void (__thiscall* Send2ndPassword1_3)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch1_5)(struct CClanMatchManager* this);
    void (__thiscall* Function34)(struct CClanMatchManager* this);
    void (__thiscall* Get077)(struct CClanMatchManager* this);
    void (__thiscall* Function36)(struct CClanMatchManager* this);
    void (__thiscall* Function37)(struct CClanMatchManager* this);
    void (__thiscall* Get078)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch3_0)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch3_1)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch3_2)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch4_1)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch4_16)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch4_13)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch3_3)(struct CClanMatchManager* this);
    void (__thiscall* Get103)(struct CClanMatchManager* this);
    void (__thiscall* Reset103)(struct CClanMatchManager* this);
    void (__thiscall* Get032_43)(struct CClanMatchManager* this); // return 032[43]
    void (__thiscall* Get090)(struct CClanMatchManager* this);
    void (__thiscall* Get096)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch2_4)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch2_2)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch2_0)(struct CClanMatchManager* this);
    void (__thiscall* SendGameMatch2_5or6or7)(struct CClanMatchManager* this);
    void (__thiscall* Function55)(struct CClanMatchManager* this, int); // if 1 or 3 or 4, return 108 else return 104
    void (__thiscall* Function56)(struct CClanMatchManager* this);
    void (__thiscall* Function57)(struct CClanMatchManager* this); // if 6 return 118 else if 7 return 121 else return 109
    void (__thiscall* Get112)(struct CClanMatchManager* this);
    void (__thiscall* Function59)(struct CClanMatchManager* this);
    void (__thiscall* Function60)(struct CClanMatchManager* this);
};

struct CClanMatchManager
{
    struct CClanMatchManager_tables* vfptr; // main
    void* packetListener;

    int unk001;
    struct Packet_Match* gPacket_Match;
    int unk003;
    int unk004;
    int unk005;

    int unk006; // some shits
    int unk007[22];

    char unk029;
    int unk030;

    int unk031; // some shits
    int unk032[45];

    char unk077;
    int unk078;
    int unk079;
    short unk080;
    int unk081;
    int unk082;
    int unk083;
    int unk084;
    int unk085;
    int unk086;
    int unk087;
    int unk088;
    int unk089;
    short unk090;
    int unk091;
    int unk092;
    int unk093;
    int unk094;
    int unk095;

    int unk096; // some shit
    int unk097[31];

    char unk103;
    int unk104;
    int unk105;
    int unk106;
    int unk107;
    int unk108;
    int unk109;
    int unk110;
    int unk111;

    int unk112; // some shit
    int unk113[43];

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
};
