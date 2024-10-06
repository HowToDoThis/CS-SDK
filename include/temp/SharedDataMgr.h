#include "tempstruct.h"

struct BoomerDeathTable_data {
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
};

struct vector_BoomerDeathTable {
    BoomerDeathTable_data* first;
    BoomerDeathTable_data* last;
    BoomerDeathTable_data* end;
};

struct BoomerDeathTable {
    void* vfptr;
    vector_BoomerDeathTable vec;
    int data[120];
};

struct FabItemTable {
    void* vfptr;
    vector vec1;
    vector vec2;
    vector vec3;
    vector vec4;
};

struct WeaponRecommandTable {
    void* vfptr;
};

// 540 bytes, 135 int
struct Unk108 {
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
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
    int u23;
    int u24;
    int u25;
    int u26;
    int u27;
};

// must based on Packet.h
// 1 + 233 (CHN160531)
class SharedDataMgr {
public:
    virtual void Function0();
    virtual void dtorRibbonSystem();
    virtual void GetUnk1();
    virtual void SetUnk1();
    virtual void GetGameUI_Func7();
    virtual void SetUnk234(int* a2); // 3 array
    virtual void GetUnk2();
    virtual void TestCSOLight(char a2); // set Unk5A
    virtual void GetUnk5A();
    virtual void Function9(); // set something float, 37652CB0
    virtual void SetIsAge18(char a2);
    virtual char GetIsAge18();
    virtual void SomethingException1();
    virtual void SomethingException2();
    virtual void SetUnk6A(char a2);
    virtual void GetUnk6A();
    virtual void Function16();
    virtual void Function17();
    virtual int  Function18(int,int,int,int,int,int,int); // DLL FUNC
    virtual void Function19(); // DLL FUNC
    virtual void SetUnk9(); // 20
    virtual void GetUnk9();
    virtual void RegistryReadInt(const char *key, int defaultValue);
    virtual void RegistryWriteInt(const char *key, int defaultValue);
    virtual void RegistryReadString(const char *key, const char *defaultValue);
    virtual void RegistryWriteString(const char *key, const char *defaultValue);
    virtual int  GetCSOFacade1(int, int); // set shit3
    virtual void GetShit3();
    virtual void SetUnk11Values(int,int);
    virtual void GetUnk11Values(int);
    virtual void Function30();
    virtual void Function31();
    virtual void Function32();
    virtual void Function33();
    virtual void Function34();
    virtual void Function35();
    virtual void Function36();
    virtual void Function37();
    virtual void Function38();
    virtual void Function39();
    virtual void Function40();
    virtual void Function41();
    virtual void Function42();
    virtual void Function43();
    virtual void Function44();
    virtual void Function45();
    virtual void Function46();
    virtual void Function47();
    virtual void Function48();
    virtual void Function49();
    virtual void Function50();
    virtual void Function51();
    virtual void Function52();
    virtual void Function53();
    virtual void Function54();
    virtual void Function55();
    virtual void Function56();
    virtual void Function57();
    virtual void Function58();
    virtual void Function59();
    virtual void Function60();
    virtual void SendHost11();
    virtual void SendHost13();
    virtual void SendHost14();
    virtual void SendHost15();
    virtual void SendHost100();
    virtual void SendHost101();
    virtual void SendHost103_0();
    virtual void SendHost103_1();
    virtual void SendHost103_2();
    virtual void SendHost103_3();
    virtual void SendHost102();
    virtual void AnnounceTable();
    virtual void SendHost21();
    virtual void SendRibbonSystem0();
    virtual void Function75();
    virtual void Function76();
    virtual void Function77();
    virtual void Function78();
    virtual void Function79();
    virtual void Function80();
    virtual void Function81();
    virtual void Function82();
    virtual void Function83();
    virtual void Function84();
    virtual void Function85();
    virtual void Function86();
    virtual void Function87();
    virtual void Function88();
    virtual void Function89();
    virtual void Function90();
    virtual void Function91();
    virtual void Function92();
    virtual void Function93();
    virtual void Function94();
    virtual void Function95();
    virtual void Function96();
    virtual void Function97();
    virtual void Function98();
    virtual void Function99();
    virtual void Function100();
    virtual void Function101();
    virtual void Function102();
    virtual void Function103();
    virtual void Function104();
    virtual void Function105();
    virtual void Function106();
    virtual void Function107();
    virtual void Function108();
    virtual void Function109();
    virtual void Function110();
    virtual void Function111();
    virtual void ZombieParamDump();
    virtual void Function113();
    virtual void Function114();
    virtual void Function115();
    virtual void Function116();
    virtual void Function117();
    virtual void Function118();
    virtual void SendHost19();
    virtual void Function120();
    virtual void Function121();
    virtual void Function122();
    struct StringTableWrapper* CreateStringTableWrapper();
    virtual void FreeStringTableWrapper(struct StringTableWrapper*);
    virtual void Function125();
    virtual void Function126();
    virtual void Function127();
    virtual void Function128();
    virtual void Function129();
    virtual void Function130();
    virtual void Function131();
    virtual void Function132();
    virtual void Function133();
    virtual void Function134();
    virtual void Function135();
    virtual void Function136();
    virtual void Function137();
    virtual void Function138();
    virtual void Function139();
    virtual void Function140();
    virtual void Function141();
    virtual void Function142();
    virtual void Function143();
    virtual void Function144();
    virtual void Function145();
    virtual void Function146();
    virtual void Function147();
    virtual void Function148();
    virtual void Function149();
    virtual void Function150();
    virtual void Function151();
    virtual void Function152();
    virtual void Function153();
    virtual void Function154();
    virtual void Function155();
    virtual void Function156();
    virtual void Function157();
    virtual void Function158();
    virtual void Function159();
    virtual void Function160();
    virtual void Function161();
    virtual void Function162();
    virtual void Function163();
    virtual void Function164();
    virtual void Function165();
    virtual void Function166();
    virtual void Function167();
    virtual void Function168();
    virtual void Function169();
    virtual void Function170();
    virtual void Function171();
    virtual void Function172();
    virtual void Function173();
    virtual void Function174();
    virtual void Function175();
    virtual void Function176();
    virtual void Function177();
    virtual void Function178();
    virtual void Function179();
    virtual void Function180(int);
    virtual void Function181();
    virtual void ZombieUX();
    virtual void HelpPageEvent();
    virtual void Function184();
    virtual void Function185(int);
    virtual void Function186();
    virtual void Function187();
    virtual void Function188();
    virtual void Function189();
    virtual void Function190();
    virtual void Function191();
    virtual void Function192();
    virtual void Function193();
    virtual void Function194();
    virtual void Function195();
    virtual void Function196();
    virtual void Function197();
    virtual void Function198();
    virtual void Function199();
    virtual void Function200();
    virtual void SendHost104_0();
    virtual void Function202();
    virtual void Function203();
    virtual void Function204();
    virtual void Function205();
    virtual void Function206();
    virtual void Function207();
    virtual void Function208();
    virtual void Function209();
    virtual void Function210();
    virtual void Function211();
    virtual void Function212();
    virtual void Function213();
    virtual void Function214();
    virtual void Function215();
    virtual void Function216();
    virtual void Function217();
    virtual void Function218();
    virtual void Function219();
    virtual void Function220();
    virtual void SendHost22();
    virtual void UpdateInfo9();
    virtual void Function223();
    virtual void Function224();
    virtual void Function225();
    virtual void SendHost23();
    virtual void Function227();
    virtual void Function228();
    virtual void Function229();
    virtual void Function230();
    virtual void Function231();
    virtual void Function232();
    virtual ~SharedDataMgr();

public:
char unk1; // func2 get func3 set
    char shit2[3];
    int unk2; // func5 set a2[0] func6 get
    int unk3; // func5 set a2[1]
    int unk4; // func5 set a2[2]
    char unk5A; // func7 set a2 func8 get
    char bIsAge18; // func10 set a2 func11 get
    char unk6A; // func14 set a2 func15 get
    char unk6B; // func16-17

    int shit; // fill

    int unk7;
    int unk8;

    int test[97]; // func16-17

    char unk9; // func20 set a2
    char shit3; // func26 a3 func27 get
    short iUnk1;

    int szUnk[32][14]; // func30 a2
    int unk11[12]; // func28-29 a2
    short u1;
    short u2;

    int wtf2[60]; // option, maplist? func31-35
    char unk14; // func43-44
    char unk15; // func7 c:\\cso_light_test.txt func40 get

    // precacheSwap func89
    tempStruct a1;
    string a1a;

    tempStruct a2;
    string a2a;

    tempStruct a3;
    string a3a;

    int unkA[3];
    // spray func77-86
    int unk25;
    int unk26;
    int unk27;

    int unkB[4];
    // MapLoadingTip.csv
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;

    int unkC[146]; // func94 func98-99
    int* unk35; // 10988... wtf 67 * 164b(41 int)
    int unk36;
    int unk37;

    int unkD[840];
    int unk38;
    int unk39;
    int unk40;

    int unkE[140];
    int unk41;
    int unk42;
    int unk43;
    
    ZombieSkillTable     gZombieSkillTable; // func111
    BoomerDeathTable     gBoomerDeathTable; // func112
    FabItemTable         gFabItemTable; // func113
    WeaponRecommandTable gWeaponRecommandTable; // func114

    int unkI[56];

    //Unk108 zb4data; 

    Unk108* vZB4_first; // 540b / 5(5 items) = 108b (27 int)
    Unk108* vZB4_last;
    Unk108* vZB4_end;

    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;

    int* unk53; // 240, ZB4 shits
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    int unk58;

    // ZbSpecUpList.csv
    int unkJ[210];

    // RibbonSystem Func1
    vector unk59; // vector, for ribbon system
    vector vDNA; // DNA used, size 16 structs, no more than 18

    int unkK[129]; // func55-60
    
    vector_string v_ZBS_Shit; // zbsbreak & zbstarget

    char i1;
    char szUnk6[255];

    char unkL[16];
    int unk68;

    int unkM[59];
    int unk69; // humansceneskill
    int unk70;
    int unk71;

    int unk72;
    int unk73; // enhanceinfo

    int unk74; // enhancetitle
    int unk75;
    int unk76;

    int unkN[4]; // related item

    int unk77;
    int unkO[7]; // costumezombie

    int unk78;
    int unkP[7];

    int unk79; // resfileindex?
    int unkQ[7];

    int unk80; // zsht_Building
    int unk81;
    int unk82;
    int unk83; // ZBS_BB
    int unk84;
    int unk85;
    int unk86; // ZBS_SB
    int unk87;
    int unk88;
    int unk89; // zsht_SkillTree
    int unk90;
    int unk91;
    int unk92; // zsht_WorkTable
    int unk93;
    int unk94;

    char unk95A; // func184 serverCategory?
    char unk95B; // func205
    short unk96; // func207

    short unk97;
    short unk98;

    int stupid1;
    int unkR1; // float?
    int unkR2; // float?
    int unkR3;
    int unkR4; // float?
    int unkR5; // float?

    int unk99; // StandAlone_BonusMission
    int unk100;
    int unk101;
    int unk102;
    int unk103;
    int unk104;
    int unk105;
    int unk106;
    int unk107; // StandAlone_AchievementRate
    int unk108;
    int unk109;

    int unk110;
    int unk111;

    int unkS[10];
    int unk112;
    int unk113;
    int unk114;
    int unk115;
    int unk116;
};
