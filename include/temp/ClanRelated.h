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
    void (__thiscall* Init)(struct CClanMatchManager* this);
    void (__thiscall* Function2)(struct CClanMatchManager* this);
    void (__thiscall* Function3)(struct CClanMatchManager* this);
    void (__thiscall* Function4)(struct CClanMatchManager* this);
    void (__thiscall* Function5)(struct CClanMatchManager* this);
    void (__thiscall* Function6)(struct CClanMatchManager* this);
    void (__thiscall* Function7)(struct CClanMatchManager* this);
    void (__thiscall* Function8)(struct CClanMatchManager* this);
    void (__thiscall* Function9)(struct CClanMatchManager* this);
    void (__thiscall* Function10)(struct CClanMatchManager* this);
    void (__thiscall* Function11)(struct CClanMatchManager* this);
    void (__thiscall* Function12)(struct CClanMatchManager* this);
    void (__thiscall* Function13)(struct CClanMatchManager* this);
    void (__thiscall* Function14)(struct CClanMatchManager* this);
    void (__thiscall* Function15)(struct CClanMatchManager* this);
    void (__thiscall* Function16)(struct CClanMatchManager* this);
    void (__thiscall* Function17)(struct CClanMatchManager* this);
    void (__thiscall* Function18)(struct CClanMatchManager* this);
    void (__thiscall* Function19)(struct CClanMatchManager* this);
    void (__thiscall* Function20)(struct CClanMatchManager* this);
    void (__thiscall* Function21)(struct CClanMatchManager* this);
    void (__thiscall* Function22)(struct CClanMatchManager* this);
    void (__thiscall* Function23)(struct CClanMatchManager* this);
    void (__thiscall* Function24)(struct CClanMatchManager* this);
    void (__thiscall* Function25)(struct CClanMatchManager* this);
    void (__thiscall* Function26)(struct CClanMatchManager* this);
    void (__thiscall* Function27)(struct CClanMatchManager* this);
    void (__thiscall* Function28)(struct CClanMatchManager* this);
    void (__thiscall* Function29)(struct CClanMatchManager* this);
    void (__thiscall* Function30)(struct CClanMatchManager* this);
    void (__thiscall* Function31)(struct CClanMatchManager* this);
    void (__thiscall* Function32)(struct CClanMatchManager* this);
    void (__thiscall* Function33)(struct CClanMatchManager* this);
    void (__thiscall* Function34)(struct CClanMatchManager* this);
    void (__thiscall* Function35)(struct CClanMatchManager* this);
    void (__thiscall* Function36)(struct CClanMatchManager* this);
    void (__thiscall* Function37)(struct CClanMatchManager* this);
    void (__thiscall* Function38)(struct CClanMatchManager* this);
    void (__thiscall* Function39)(struct CClanMatchManager* this);
    void (__thiscall* Function40)(struct CClanMatchManager* this);
    void (__thiscall* Function41)(struct CClanMatchManager* this);
    void (__thiscall* Function42)(struct CClanMatchManager* this);
    void (__thiscall* Function43)(struct CClanMatchManager* this);
    void (__thiscall* Function44)(struct CClanMatchManager* this);
    void (__thiscall* Function45)(struct CClanMatchManager* this);
    void (__thiscall* Function46)(struct CClanMatchManager* this);
    void (__thiscall* Function47)(struct CClanMatchManager* this);
    void (__thiscall* Function48)(struct CClanMatchManager* this);
    void (__thiscall* Function49)(struct CClanMatchManager* this);
    void (__thiscall* Function50)(struct CClanMatchManager* this);
    void (__thiscall* Function51)(struct CClanMatchManager* this);
    void (__thiscall* Function52)(struct CClanMatchManager* this);
    void (__thiscall* Function53)(struct CClanMatchManager* this);
    void (__thiscall* Function54)(struct CClanMatchManager* this);
    void (__thiscall* Function55)(struct CClanMatchManager* this);
    void (__thiscall* Function56)(struct CClanMatchManager* this);
    void (__thiscall* Function57)(struct CClanMatchManager* this);
    void (__thiscall* Function58)(struct CClanMatchManager* this);
    void (__thiscall* Function59)(struct CClanMatchManager* this);
};

struct CClanMatchManager
{
    struct CClanMatchManager_tables* vfptr; // main
    void* packetListener;

    int unk001;
    Packet_Match* gPacket_Match;
    int unk003;
    int unk004;
    int unk005;

    int unk006; // some shits
    int unk007;
    int unk008;
    int unk009;
    int unk010;
    int unk011;
    int unk012;
    int unk013;
    int unk014;
    int unk015;
    int unk016;
    int unk017;
    int unk018;
    int unk019;
    int unk020;
    int unk021;
    int unk022;
    int unk023;
    int unk024;
    int unk025;
    int unk026;
    int unk027;
    int unk028;

    char unk029;
    int unk030;

    int unk031; // some shits
    int unk032;
    int unk033;
    int unk034;
    int unk035;
    int unk036;
    int unk037;
    int unk038;
    int unk039;
    int unk040;
    int unk041;
    int unk042;
    int unk043;
    int unk044;
    int unk045;
    int unk046;
    int unk047;
    int unk048;
    int unk049;
    int unk050;
    int unk051;
    int unk052;
    int unk053;
    int unk054;
    int unk055;
    int unk056;
    int unk057;
    int unk058;
    int unk059;
    int unk060;
    int unk061;
    int unk062;
    int unk063;
    int unk064;
    int unk065;
    int unk066;
    int unk067;
    int unk068;
    int unk069;
    int unk070;
    int unk071;
    int unk072;
    int unk073;
    int unk074;
    int unk075;
    int unk076;

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