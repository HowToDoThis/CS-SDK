class CSVLocalized {
public:
    virtual void Init(unsigned int size, unsigned int count);
    virtual int  Func2(); // call func5
    virtual void Delete();
    virtual ~CSVLocalized();
    virtual int  Func5(int, int, char*);
    virtual bool Load(const char* szPath);
    virtual char* ReadString(int, int, char*, int);
    virtual bool LoadEncrypt(const char* szPath, int);
    virtual bool Parse(int,int);

public:
    int   iBufferSize; // 256
    int   unk2;
    int   unk3;
    char  unk4;
    void* unk5; // array
};

class StringTable : CSVLocalized {
    int   nf1;
    void* nf2;
};

struct StringTableWrapper_vtable
{
    void (__thiscall* Function1)(struct StringTableWrapper* this);
    int (__thiscall* Function2)(struct StringTableWrapper* this, char*);
    void* (__thiscall* Function3)(struct StringTableWrapper* this, int, int);
    void (__thiscall* Function4)(struct StringTableWrapper* this);
    int (__thiscall* CSVReadInt)(struct StringTableWrapper* this, int, int, int*);
    void (__thiscall* CSVReadFloat)(struct StringTableWrapper* this, int, int, int*);
    int (__thiscall* Function7)(struct StringTableWrapper* this, int, int, int);
    void (__thiscall* Function8)(struct StringTableWrapper* this);
    void (__thiscall* Function9)(struct StringTableWrapper* this);
    void (__thiscall* Function10)(struct StringTableWrapper* this);
    void (__thiscall* Function11)(struct StringTableWrapper* this);
    int (__thiscall* Function12)(struct StringTableWrapper* this);
    int (__thiscall* Function13)(struct StringTableWrapper* this);
    void (__thiscall* Function14)(struct StringTableWrapper* this);
    void (__thiscall* Function15)(struct StringTableWrapper* this);
};

struct StringTableWrapper
{
    StringTableWrapper_vtable* vfptr;
    CSVLocalizedBase localized;
    int unk1;
};

struct CCSVMapList : StringTable
{
    char map1;
    char map2;
};

struct CCSVClientTable : CCSVMapList
{
};

struct RelationProductVtables
{
    void  (__thiscall* Function01)(struct RelationProduct* this);
    void  (__thiscall* Function02)(struct RelationProduct* this);
    void* (__thiscall* Function03)(struct RelationProduct* this);
    void  (__thiscall* Function04)(struct RelationProduct* this);
    void  (__thiscall* Function05)(struct RelationProduct* this);
    void  (__thiscall* Function06)(struct RelationProduct* this);
    void  (__thiscall* Function07)(struct RelationProduct* this);
    void  (__thiscall* Function08)(struct RelationProduct* this);
    void  (__thiscall* Function09)(struct RelationProduct* this);
    void  (__thiscall* Function10)(struct RelationProduct* this);
    void  (__thiscall* Function11)(struct RelationProduct* this);
    void  (__thiscall* Function12)(struct RelationProduct* this);
    void* (__thiscall* Function13)(struct RelationProduct* this);
    void  (__thiscall* Function14)(struct RelationProduct* this);
    void  (__thiscall* Function15)(struct RelationProduct* this);
    void  (__thiscall* Function16)(struct RelationProduct* this);
    void  (__thiscall* Function17)(struct RelationProduct* this);
    void  (__thiscall* Function18)(struct RelationProduct* this);
    void  (__thiscall* Function19)(struct RelationProduct* this);
    void  (__thiscall* Function20)(struct RelationProduct* this);
    void  (__thiscall* Function21)(struct RelationProduct* this);
    void  (__thiscall* Function22)(struct RelationProduct* this);
};

// CHN160531 Size 120
struct RelationProduct
{
    RelationProductVtables* vfptr;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
};

struct GiftVtables
{
    void  (__thiscall* Function01)(struct Gift* this);
    void  (__thiscall* Function02)(struct Gift* this);
    void* (__thiscall* Function03)(struct Gift* this);
    void  (__thiscall* Function04)(struct Gift* this);
    void  (__thiscall* Function05)(struct Gift* this);
    void  (__thiscall* Function06)(struct Gift* this);
    void  (__thiscall* Function07)(struct Gift* this);
    void  (__thiscall* Function08)(struct Gift* this);
    void  (__thiscall* Function09)(struct Gift* this);
    void  (__thiscall* Function10)(struct Gift* this);
    void  (__thiscall* Function11)(struct Gift* this);
    void  (__thiscall* Function12)(struct Gift* this);
};

// CHN160531 Size 96
struct Gift
{
    GiftVtables* vfptr;
    RelationProduct* unk;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
};

class map_GiftBox_Node_Pair
{
    long long first;
    int* second;
};

class map_GiftBox_Node
{
    map_GiftBox_Node_Pair* _Left;
    map_GiftBox_Node_Pair* _Parent;
    map_GiftBox_Node_Pair* _Right;
    char _Color;
    char _Isnil;
    map_GiftBox_Node_Pair _Myval;
};

class map_GiftBox
{
    map_GiftBox_Node* _Myhead;
    int _Mysize;
};

class GiftBox
{
public:
    virtual void Function1();
    virtual void Function2();
    virtual void Function3();
    virtual void Function4();
    virtual void Function5(int);
    virtual void Shop7(bool, int);
    virtual void Function6(vector);
    virtual void Shop3(); // unk1
    virtual void Shop4();
    virtual void Shop5();
    virtual void Shop10();
    virtual void Function7();
    virtual void Shop6();
    virtual void Function8();
    virtual void Function9();
    virtual void Function10();

public:
    char unk1;

    map_GiftBox u2;
    vector u3;

    short unk6A;
    int unkA[3];
    int unk7;
    int unk8;

    bool bCouponInquiry;
};

class ItemTable : CSVLocalized {
    int nf1; // custom?
    int unk1;

    int unk2; // std::map
    int unk3;

    int unk4; // std::map
    int unk5;

    int unk6; // std::map
    int unk7;

    int unk8;
    int unk9;
    int unk10;
    int unk11;
};
