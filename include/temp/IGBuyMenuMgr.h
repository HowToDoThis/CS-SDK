struct struct_372ED870 {
    list u1;
    vector u2;
    int unk4;
    int unk5;
    float unk6;
};

// CHN160531: 375A3C18 (407 + 5 + 15 + 3 + 5 + 3 + 10)
struct unkwpnstruct {
    int id;
    const char* szUnk1;
    const char* szUnk2;
    const char* szUnk3;
    const char* szCSOWeaponName;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
};

// CHN160531: 375A9160 (46)
struct unkknifestruct {
    int id;
    int inGameID;
    int itemID;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    const char* szKnifeName;
    int u9;
};

// CHN160531: 375A8F58 (13)
struct WpnGrenadeStruct {
    int id;
    int inGameID;
    int itemID;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    const char* szName1;
    const char* szName2;
};

// 0x4690
class IGBuyMenuMgr {
public:
    virtual void Func01(); // called func05
    virtual unkwpnstruct* Func02(); // return unkwpnstruct
    virtual void Func03(); // 0x384933A8 + (62 * a) | char a[305][68] leftover 33(0x21)
    virtual void Init(); // 372F2720 | 80 3D ? ? ? ? ? 56 8B F1 0F 85
    virtual void Func05();
    virtual void Func06();
    virtual int  Func07(int,int);
    virtual char Func08(int,int);
    virtual const char* Func09(); // return unkwpnstruct->szUnk1
    virtual const char* Func10(); // return unkwpnstruct->szUnk3
    virtual void Func11();
    virtual void Func12();
    virtual void Func13();
    virtual void Func14();
    virtual bool Func15(int a, int b, int inGameID, int d = 0);
    virtual void Func16(); // called func15
    virtual void Func17();
    virtual int  Func18(); // return unkwpnstruct->u4
    virtual void Func19();
    virtual int  Func20(const char*); // return unkwpnstruct->id
    virtual int  Func21(int); // return unkknifestruct->inGameID
    virtual int  Func22(int); // return unkknifestruct->itemID
    virtual int  Func23(int); // return unkknifestruct->id
    virtual int  Func24(int); // return unkknifestruct->id
    virtual int  KnifeCount(); // return 46
    virtual unkknifestruct* GetKnife(int);
    virtual unkknifestruct* Func27(int);
    virtual int  Func28(int); // return WpnGrenadeStruct->inGameID
    virtual int  Func29(int); // return WpnGrenadeStruct->itemID
    virtual int  Func30(int); // return WpnGrenadeStruct->id
    virtual int  Func31(int); // return WpnGrenadeStruct->id
    virtual int  GrenadeCount();
    virtual void Func33(int*, int);
    virtual void Func34();
    virtual void Func35();
    virtual void Func36();
    virtual void Func37();
    virtual void Func38();
    virtual void Set_nf1_4();
    virtual void Get_nf1_4();
    virtual void Func41(); /// set undef1, undef2
    virtual void Func42();
    virtual int  Func43(int);
    virtual void Func44();
    virtual void Func45();
    virtual char Get_nf2();
    virtual void Set_nf2_2(char);
    virtual char Get_nf2_2();
    virtual void Func49();
    virtual void Func50();
    virtual void Func51();
    virtual void Func52();
    virtual void Func53();
    virtual void Func54();
    virtual void Func55();
    virtual void Func56();
    virtual void Func57();
    virtual const char* Func58(int); // return unkwpnstruct->szUnk1
    virtual int  Func59(int); // return unkwpnstruct->u2
    virtual void Func60(); // something with 18
    virtual void Func61();
    virtual const char* GetCommand(); // return "item_XXX"
    virtual void Func63();
    virtual void Func64();

public:
    int nf1_1;
    int nf1_2;
    int nf1_3;
    int nf1_4;
    char undef1[15360]; // 7680 (x = 8, y = 10)
    char nf2;
    char nf2_1[3];
    char undef2[2240];
    char nf2_2;
    char nf2_3[3];
    char undef3[64];
    int nf3_1;
    int nf3_2;
    int nf3_3;
    int nf3_4;
    int nf3_5;
    int nf3_6;
    int nf3_7[2];

    int nf4; // 3716F6A0
    int nf5[7];

    struct_372ED870 nf6;

    int nf8;
    int nf9[7];

    int nf10;
    int nf11[7];

    int nf12;
    int nf13[7];

    int nf14;
    int nf15[7];

    int nf16;
    int nf17[7];

    int nf18;
    int nf19[7];

    int nf20;
    int nf21[7];

    int nf22;
    int nf23[7];

    int nf24;
    int nf25;
    int nf26;

    int nf27; // map
    int nf28;
};
