struct BadWordsManagerImpl
{
    void* vftbl; // 1 only, descructor
    int unk1;
    struct StringTable* table1;
    struct StringTable* table2;
};

struct BadWordsManager
{
    void* vftbl;
    BadWordsManagerImpl* gBadWords;
};

struct AbuseMessageBlocker
{
    void* vftbl;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    double unk6;
    double unk7;
    double unk8;
    double unk9;
    double unk10[2];
};