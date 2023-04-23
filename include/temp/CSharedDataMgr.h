// must based on CPacket.h
// 1 + 233 (CHN160531)
struct CSharedDataMgr_vtables
{
    void (__thiscall* Function0)(struct CSharedDataMgr* this);
    void (__thiscall* ShutdownRibbonSystem)(struct CSharedDataMgr* this);
    void (__thiscall* ReturnUnk1)(struct CSharedDataMgr* this);
    void (__thiscall* SetUnk1)(struct CSharedDataMgr* this);
    void (__thiscall* GetGameUI28)(struct CSharedDataMgr* this);
    void (__thiscall* SetUnk234)(struct CSharedDataMgr* this, int* a2); // 3 array
    void (__thiscall* GetUnk2)(struct CSharedDataMgr* this);
    void (__thiscall* TestCSOLight)(struct CSharedDataMgr* this, char a2); // set Unk5A
    void (__thiscall* GetUnk5A)(struct CSharedDataMgr* this);
    void (__thiscall* Function9)(struct CSharedDataMgr* this);
    void (__thiscall* SetUnk5B)(struct CSharedDataMgr* this, char a2);
    void (__thiscall* GetUnk5B)(struct CSharedDataMgr* this);
    void (__thiscall* SomethingException1)(struct CSharedDataMgr* this);
    void (__thiscall* SomethingException2)(struct CSharedDataMgr* this);
    void (__thiscall* SetUnk6A)(struct CSharedDataMgr* this, char a2);
    void (__thiscall* GetUnk6A)(struct CSharedDataMgr* this);
    void (__thiscall* Function16)(struct CSharedDataMgr* this);
    void (__thiscall* Function17)(struct CSharedDataMgr* this);
    int  (__thiscall* Function18)(struct CSharedDataMgr* this,int,int,int,int,int,int,int); // DLL FUNC
    void (__thiscall* Function19)(struct CSharedDataMgr* this); // DLL FUNC
    void (__thiscall* SetUnk9)(struct CSharedDataMgr* this);
    void (__thiscall* GetUnk9)(struct CSharedDataMgr* this);
    void (__thiscall* GetRegistry2)(struct CSharedDataMgr* this);
    void (__thiscall* GetRegistry3)(struct CSharedDataMgr* this);
    void (__thiscall* GetRegistry4)(struct CSharedDataMgr* this);
    void (__thiscall* GetRegistry5)(struct CSharedDataMgr* this);
    int (__thiscall* GetCSOFacade1)(struct CSharedDataMgr* this, int, int);
    void (__thiscall* Function27)(struct CSharedDataMgr* this);
    void (__thiscall* Function28)(struct CSharedDataMgr* this);
    void (__thiscall* Function29)(struct CSharedDataMgr* this);
    void (__thiscall* Function30)(struct CSharedDataMgr* this);
    void (__thiscall* Function31)(struct CSharedDataMgr* this);
    void (__thiscall* Function32)(struct CSharedDataMgr* this);
    void (__thiscall* Function33)(struct CSharedDataMgr* this);
    void (__thiscall* Function34)(struct CSharedDataMgr* this);
    void (__thiscall* Function35)(struct CSharedDataMgr* this);
    void (__thiscall* Function36)(struct CSharedDataMgr* this);
    void (__thiscall* Function37)(struct CSharedDataMgr* this);
    void (__thiscall* Function38)(struct CSharedDataMgr* this);
    void (__thiscall* Function39)(struct CSharedDataMgr* this);
    void (__thiscall* Function40)(struct CSharedDataMgr* this);
    void (__thiscall* Function41)(struct CSharedDataMgr* this);
    void (__thiscall* Function42)(struct CSharedDataMgr* this);
    void (__thiscall* Function43)(struct CSharedDataMgr* this);
    void (__thiscall* Function44)(struct CSharedDataMgr* this);
    void (__thiscall* Function45)(struct CSharedDataMgr* this);
    void (__thiscall* Function46)(struct CSharedDataMgr* this);
    void (__thiscall* Function47)(struct CSharedDataMgr* this);
    void (__thiscall* Function48)(struct CSharedDataMgr* this);
    void (__thiscall* Function49)(struct CSharedDataMgr* this);
    void (__thiscall* Function50)(struct CSharedDataMgr* this);
    void (__thiscall* Function51)(struct CSharedDataMgr* this);
    void (__thiscall* Function52)(struct CSharedDataMgr* this);
    void (__thiscall* Function53)(struct CSharedDataMgr* this);
    void (__thiscall* Function54)(struct CSharedDataMgr* this);
    void (__thiscall* Function55)(struct CSharedDataMgr* this);
    void (__thiscall* Function56)(struct CSharedDataMgr* this);
    void (__thiscall* Function57)(struct CSharedDataMgr* this);
    void (__thiscall* Function58)(struct CSharedDataMgr* this);
    void (__thiscall* Function59)(struct CSharedDataMgr* this);
    void (__thiscall* Function60)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost11)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost13)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost14)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost15)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost100)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost101)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost103_0)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost103_1)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost103_2)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost103_3)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost102)(struct CSharedDataMgr* this);
    void (__thiscall* AnnounceTable)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost21)(struct CSharedDataMgr* this);
    void (__thiscall* SendRibbonSystem0)(struct CSharedDataMgr* this);
    void (__thiscall* Function75)(struct CSharedDataMgr* this);
    void (__thiscall* Function76)(struct CSharedDataMgr* this);
    void (__thiscall* Function77)(struct CSharedDataMgr* this);
    void (__thiscall* Function78)(struct CSharedDataMgr* this);
    void (__thiscall* Function79)(struct CSharedDataMgr* this);
    void (__thiscall* Function80)(struct CSharedDataMgr* this);
    void (__thiscall* Function81)(struct CSharedDataMgr* this);
    void (__thiscall* Function82)(struct CSharedDataMgr* this);
    void (__thiscall* Function83)(struct CSharedDataMgr* this);
    void (__thiscall* Function84)(struct CSharedDataMgr* this);
    void (__thiscall* Function85)(struct CSharedDataMgr* this);
    void (__thiscall* Function86)(struct CSharedDataMgr* this);
    void (__thiscall* Function87)(struct CSharedDataMgr* this);
    void (__thiscall* Function88)(struct CSharedDataMgr* this);
    void (__thiscall* Function89)(struct CSharedDataMgr* this);
    void (__thiscall* Function90)(struct CSharedDataMgr* this);
    void (__thiscall* Function91)(struct CSharedDataMgr* this);
    void (__thiscall* Function92)(struct CSharedDataMgr* this);
    void (__thiscall* Function93)(struct CSharedDataMgr* this);
    void (__thiscall* Function94)(struct CSharedDataMgr* this);
    void (__thiscall* Function95)(struct CSharedDataMgr* this);
    void (__thiscall* Function96)(struct CSharedDataMgr* this);
    void (__thiscall* Function97)(struct CSharedDataMgr* this);
    void (__thiscall* Function98)(struct CSharedDataMgr* this);
    void (__thiscall* Function99)(struct CSharedDataMgr* this);
    void (__thiscall* Function100)(struct CSharedDataMgr* this);
    void (__thiscall* Function101)(struct CSharedDataMgr* this);
    void (__thiscall* Function102)(struct CSharedDataMgr* this);
    void (__thiscall* Function103)(struct CSharedDataMgr* this);
    void (__thiscall* Function104)(struct CSharedDataMgr* this);
    void (__thiscall* Function105)(struct CSharedDataMgr* this);
    void (__thiscall* Function106)(struct CSharedDataMgr* this);
    void (__thiscall* Function107)(struct CSharedDataMgr* this);
    void (__thiscall* Function108)(struct CSharedDataMgr* this);
    void (__thiscall* Function109)(struct CSharedDataMgr* this);
    void (__thiscall* Function110)(struct CSharedDataMgr* this);
    void (__thiscall* Function111)(struct CSharedDataMgr* this);
    void (__thiscall* ZombieParamDump)(struct CSharedDataMgr* this);
    void (__thiscall* Function113)(struct CSharedDataMgr* this);
    void (__thiscall* Function114)(struct CSharedDataMgr* this);
    void (__thiscall* Function115)(struct CSharedDataMgr* this);
    void (__thiscall* Function116)(struct CSharedDataMgr* this);
    void (__thiscall* Function117)(struct CSharedDataMgr* this);
    void (__thiscall* Function118)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost19)(struct CSharedDataMgr* this);
    void (__thiscall* Function120)(struct CSharedDataMgr* this);
    void (__thiscall* Function121)(struct CSharedDataMgr* this);
    void (__thiscall* Function122)(struct CSharedDataMgr* this);
    struct StringTableWrapper* (__thiscall* CreateStringTableWrapper)(struct CSharedDataMgr* this);
    void (__thiscall* FreeStringTableWrapper)(struct CSharedDataMgr* this, struct StringTableWrapper*);
    void (__thiscall* Function125)(struct CSharedDataMgr* this);
    void (__thiscall* Function126)(struct CSharedDataMgr* this);
    void (__thiscall* Function127)(struct CSharedDataMgr* this);
    void (__thiscall* Function128)(struct CSharedDataMgr* this);
    void (__thiscall* Function129)(struct CSharedDataMgr* this);
    void (__thiscall* Function130)(struct CSharedDataMgr* this);
    void (__thiscall* Function131)(struct CSharedDataMgr* this);
    void (__thiscall* Function132)(struct CSharedDataMgr* this);
    void (__thiscall* Function133)(struct CSharedDataMgr* this);
    void (__thiscall* Function134)(struct CSharedDataMgr* this);
    void (__thiscall* Function135)(struct CSharedDataMgr* this);
    void (__thiscall* Function136)(struct CSharedDataMgr* this);
    void (__thiscall* Function137)(struct CSharedDataMgr* this);
    void (__thiscall* Function138)(struct CSharedDataMgr* this);
    void (__thiscall* Function139)(struct CSharedDataMgr* this);
    void (__thiscall* Function140)(struct CSharedDataMgr* this);
    void (__thiscall* Function141)(struct CSharedDataMgr* this);
    void (__thiscall* Function142)(struct CSharedDataMgr* this);
    void (__thiscall* Function143)(struct CSharedDataMgr* this);
    void (__thiscall* Function144)(struct CSharedDataMgr* this);
    void (__thiscall* Function145)(struct CSharedDataMgr* this);
    void (__thiscall* Function146)(struct CSharedDataMgr* this);
    void (__thiscall* Function147)(struct CSharedDataMgr* this);
    void (__thiscall* Function148)(struct CSharedDataMgr* this);
    void (__thiscall* Function149)(struct CSharedDataMgr* this);
    void (__thiscall* Function150)(struct CSharedDataMgr* this);
    void (__thiscall* Function151)(struct CSharedDataMgr* this);
    void (__thiscall* Function152)(struct CSharedDataMgr* this);
    void (__thiscall* Function153)(struct CSharedDataMgr* this);
    void (__thiscall* Function154)(struct CSharedDataMgr* this);
    void (__thiscall* Function155)(struct CSharedDataMgr* this);
    void (__thiscall* Function156)(struct CSharedDataMgr* this);
    void (__thiscall* Function157)(struct CSharedDataMgr* this);
    void (__thiscall* Function158)(struct CSharedDataMgr* this);
    void (__thiscall* Function159)(struct CSharedDataMgr* this);
    void (__thiscall* Function160)(struct CSharedDataMgr* this);
    void (__thiscall* Function161)(struct CSharedDataMgr* this);
    void (__thiscall* Function162)(struct CSharedDataMgr* this);
    void (__thiscall* Function163)(struct CSharedDataMgr* this);
    void (__thiscall* Function164)(struct CSharedDataMgr* this);
    void (__thiscall* Function165)(struct CSharedDataMgr* this);
    void (__thiscall* Function166)(struct CSharedDataMgr* this);
    void (__thiscall* Function167)(struct CSharedDataMgr* this);
    void (__thiscall* Function168)(struct CSharedDataMgr* this);
    void (__thiscall* Function169)(struct CSharedDataMgr* this);
    void (__thiscall* Function170)(struct CSharedDataMgr* this);
    void (__thiscall* Function171)(struct CSharedDataMgr* this);
    void (__thiscall* Function172)(struct CSharedDataMgr* this);
    void (__thiscall* Function173)(struct CSharedDataMgr* this);
    void (__thiscall* Function174)(struct CSharedDataMgr* this);
    void (__thiscall* Function175)(struct CSharedDataMgr* this);
    void (__thiscall* Function176)(struct CSharedDataMgr* this);
    void (__thiscall* Function177)(struct CSharedDataMgr* this);
    void (__thiscall* Function178)(struct CSharedDataMgr* this);
    void (__thiscall* Function179)(struct CSharedDataMgr* this);
    void (__thiscall* Function180)(struct CSharedDataMgr* this, int);
    void (__thiscall* Function181)(struct CSharedDataMgr* this);
    void (__thiscall* ZombieUX)(struct CSharedDataMgr* this);
    void (__thiscall* HelpPageEvent)(struct CSharedDataMgr* this);
    void (__thiscall* Function184)(struct CSharedDataMgr* this);
    void (__thiscall* Function185)(struct CSharedDataMgr* this);
    void (__thiscall* Function186)(struct CSharedDataMgr* this);
    void (__thiscall* Function187)(struct CSharedDataMgr* this);
    void (__thiscall* Function188)(struct CSharedDataMgr* this);
    void (__thiscall* Function189)(struct CSharedDataMgr* this);
    void (__thiscall* Function190)(struct CSharedDataMgr* this);
    void (__thiscall* Function191)(struct CSharedDataMgr* this);
    void (__thiscall* Function192)(struct CSharedDataMgr* this);
    void (__thiscall* Function193)(struct CSharedDataMgr* this);
    void (__thiscall* Function194)(struct CSharedDataMgr* this);
    void (__thiscall* Function195)(struct CSharedDataMgr* this);
    void (__thiscall* Function196)(struct CSharedDataMgr* this);
    void (__thiscall* Function197)(struct CSharedDataMgr* this);
    void (__thiscall* Function198)(struct CSharedDataMgr* this);
    void (__thiscall* Function199)(struct CSharedDataMgr* this);
    void (__thiscall* Function200)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost104_0)(struct CSharedDataMgr* this);
    void (__thiscall* Function202)(struct CSharedDataMgr* this);
    void (__thiscall* Function203)(struct CSharedDataMgr* this);
    void (__thiscall* Function204)(struct CSharedDataMgr* this);
    void (__thiscall* Function205)(struct CSharedDataMgr* this);
    void (__thiscall* Function206)(struct CSharedDataMgr* this);
    void (__thiscall* Function207)(struct CSharedDataMgr* this);
    void (__thiscall* Function208)(struct CSharedDataMgr* this);
    void (__thiscall* Function209)(struct CSharedDataMgr* this);
    void (__thiscall* Function210)(struct CSharedDataMgr* this);
    void (__thiscall* Function211)(struct CSharedDataMgr* this);
    void (__thiscall* Function212)(struct CSharedDataMgr* this);
    void (__thiscall* Function213)(struct CSharedDataMgr* this);
    void (__thiscall* Function214)(struct CSharedDataMgr* this);
    void (__thiscall* Function215)(struct CSharedDataMgr* this);
    void (__thiscall* Function216)(struct CSharedDataMgr* this);
    void (__thiscall* Function217)(struct CSharedDataMgr* this);
    void (__thiscall* Function218)(struct CSharedDataMgr* this);
    void (__thiscall* Function219)(struct CSharedDataMgr* this);
    void (__thiscall* Function220)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost22)(struct CSharedDataMgr* this);
    void (__thiscall* UpdateInfo9)(struct CSharedDataMgr* this);
    void (__thiscall* Function223)(struct CSharedDataMgr* this);
    void (__thiscall* Function224)(struct CSharedDataMgr* this);
    void (__thiscall* Function225)(struct CSharedDataMgr* this);
    void (__thiscall* SendHost23)(struct CSharedDataMgr* this);
    void (__thiscall* Function227)(struct CSharedDataMgr* this);
    void (__thiscall* Function228)(struct CSharedDataMgr* this);
    void (__thiscall* Function229)(struct CSharedDataMgr* this);
    void (__thiscall* Function230)(struct CSharedDataMgr* this);
    void (__thiscall* Function231)(struct CSharedDataMgr* this);
    void (__thiscall* Function232)(struct CSharedDataMgr* this);
    void (__thiscall* desctructor)(struct CSharedDataMgr* this);
};

struct CSharedDataMgrWeird
{
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
};

struct CSharedDataMgrWeird2
{
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
};

struct CSharedDataMgr
{
    CSharedDataMgr_vtables* vfptr;
    char unk1; // func2 get func3 set
    char shit2[3];
    int unk2; // func5 set a2[0] func6 get
    int unk3; // func5 set a2[1]
    int unk4; // func5 set a2[2]
    char unk5A; // func7 set a2 func8 get
    char unk5B; // func10 set a2 func11 get
    char unk6A; // func14 set a2 func15 get
    char unk6B; // func16-17

    int shit; // fill

    int unk7;
    int unk8;

    int test[97]; // func16-17

    char unk9; // func20 set a2
    char shit3; // func26 a3 func27 get
    short iUnk1;
    char szUnk[700]; // func30 56*a2

    int szUnk1[273];
    char unk11[16]; // func28-29 4*a2
    char unk12[16];
    char unk13[8];

    int wtf2[63]; // option, maplist? func31-35
    char unk14; // func43-44
    char unk15; // func7 c:\\cso_light_test.txt func40 get

    // precacheSwap func89
    int wtf3[8];
    char unk16;
    int szUnk3[3];
    int unk17;
    int unk18;

    int wtf4[8];
    char unk19;
    int szUnk4[3];
    int unk20;
    int unk21;

    int wtf5[8];
    char unk22;
    int szUnk5[3];
    int unk23;
    int unk24;

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
    
    struct ZombieSkillTable* gZombieSkillTable; // func111

    int unkF[123];

    int* gBoomerDeathTable; // func112

    int unkG[123];

    int* gFabItemTable; // func113

    int unkH[12];

    int* gWeaponRecommandTable; // func114

    int unkI[56];
    void* unk44; // 540 / 108
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    void* unk53; // 240
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    int unk58;

    // ZbSpecUpList.csv
    int unkJ[210];

    // RibbonSystem Func1
    int unk59;
    int unk60;
    int unk61;
    int DNAStuff; // DNA used
    int unk63;
    int unk64;

    int unkK[129]; // func55-60
    int unk65; // zbsbreak & zbstarget
    int unk66;
    int unk67;

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

    byte unk95A; // func184 serverCategory?
    byte unk95B; // func205
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