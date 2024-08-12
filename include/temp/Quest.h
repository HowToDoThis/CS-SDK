struct CSO_32_struct {
    map u1;
    vector u2;
    int u6;
    int u7;
    float u8;
};

struct TempQuestString {
    wstring name;
    vector_string specials;
};

struct map_quest_info_pair {
    int ID;
    short flag;
    // packet
    char type;
    short npcID;
    TempQuestString name;
    TempQuestString desc;
    char status;
    char isFav;
    // HUH? 3731EBD0
    int nf1;
    int nf2;
    int nf3;
    int nf4;
};

struct TempQuestInfo {
    int ID;
    short flag;
    // packet
    char type;
    short npcID;
    TempQuestString name;
    TempQuestString desc;
    char status;
    char isFav;
};

class Packet_Quest : public Packet
{
public:
    int type;
    map map;
};

struct QuestStats {
    short flag;
    int honorPoints;
    short special;
    short specialBest;
    char daily;
    char nf1;
    short dailyTotal;
    char nf2;
    char nf3;
    char nf4;
    char nf5;
    char pcBang;
};

// CHN160531 0xBC
class CQuestMgr
{
public:
    virtual void Init();
    virtual void Func1(int size);
    virtual void Delete(int a);
    virtual void SendQuest31();
    virtual void SendQuest41(int a, int b);
    virtual void SendQuest42(int a, int b);
    virtual void SendQuest51(int a, int b);
    virtual void SendQuest52(int a);
    virtual void* Func2(); // return u1
    virtual QuestStats* GetStats();
    virtual int Func4(int a = 0); // ???? u1
    virtual map_quest_info_pair* Func5(int a); // return Func4??
    virtual void* Func6(); // return something
    virtual void* Func7(); // return something
    virtual int Func8(int a); // int a=0 ??? u2
    virtual int Func9(int a); // int a=0 ??? u3
    virtual int Func10(int a); // int a=0 ??? u4
    virtual char GetU40(); // return u40
    virtual void SetU40(bool a);
    virtual bool IsQuestDebug();
    virtual bool IsSpecial(); // u1
    virtual int GetU14C();
    virtual void CountU41U42();
    virtual int GetU41();
    virtual int GetU42();
    virtual int GetU14B();
    virtual void SendQuest32();
    virtual int Func11();
    virtual int GetU43();
    virtual int GetU44();
    virtual void SetU45(int a);
    virtual void SetU43(int a);
    virtual void SetU44(int a);
    virtual int Func12(); // return Func4(u45)
    virtual int GetU15();

public:
    PacketListener* listener; // WHY IMPLEMENT THIS HW??? NULL FUNC
    Packet_Quest* packet;

    CSO_32_struct u1;

    QuestStats stats;

    CSO_32_struct u2;
    CSO_32_struct u3;
    CSO_32_struct u4;

    char u40;
    int u41; // u1 + 18 | !0
    int u42; // u1 + 18 | == 10
    int u43;
    int u44;
    int u45;
};