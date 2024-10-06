// CHN160531: 01A49920
class CHudBase {
public:
    virtual int  Init();
    virtual int  Reset();
    virtual void Redraw(float);
    virtual void CHudBase_Func4();
    virtual void CHudBase_Func5();
    virtual void CHudBase_Func6();
    virtual void CHudBase_Func7();

public:
    int base_nf1;
    int base_nf2;
    int base_nf3;
    int base_nf4;
};

struct PointerLinker {
    CHudBase* prev;
    PointerLinker* next;
};

// is he really depends on CHudBase????
// CHN160531: 01A49940
class CHudCustomBase : CHudBase {
public:
    virtual ~CHudCustomBase();

public:
    PointerLinker* hcb_link;
};

class CHudImage : CHudBase {
public:
    virtual ~CHudImage();
    virtual void CHudImage_Reset();
    virtual void CHudImage_Func2(char*);
    virtual void CHudImage_Func3(char a2, char a3, char a4, char a5);
    virtual void  CHudImage_Set9(int a2);
    virtual float CHudImage_Get9();
    virtual void  CHudImage_Set10(int a2);
    virtual float CHudImage_Get10();
    virtual void  CHudImage_Set11(int a2);
    virtual float CHudImage_Get11();
    virtual void  CHudImage_Set12(int a2);
    virtual float CHudImage_Get12();
    virtual void  CHudImage_Set15(int a2);
    virtual float CHudImage_Get15();
    virtual void  CHudImage_Set16(int a2);
    virtual int CHudImage_Get16();

public:
    int hi_nf1;
    int hi_nf2; // flag
    int hi_nf3;
    int hi_nf4;
    int hi_nf5;
    int hi_nf6;
    int hi_nf7;
    int hi_nf8;
    float hi_nf9; // func4
    float hi_nf10; // func6
    float hi_nf11; // func8
    float hi_nf12; // func10
    char hi_nf13_a;
    char hi_nf13_b;
    char hi_nf13_c;
    char hi_nf13_d;
    int hi_nf14;
    float hi_nf15; // func12
    int hi_nf16; // func14
    char hi_nf17;
};

class CHudFadeImage : CHudImage {
public:
    char  fi_nf1;
    float fi_nf2;
    float fi_nf3;
    int   fi_nf4;
};

class CHudSlideImage : CHudImage {
public:
    char  si_nf1;
    float si_nf2;
    float si_nf3;
    int   si_nf4;
    int   si_nf5;
    int   si_nf6;
    int   si_nf7;
    int   si_nf8;
};

class CInGameKillLog_cl {
public:
    virtual ~CInGameKillLog_cl();

public:
    char kl_nf1; // init?

    int kl_nf2; // std::map (size 24)
    int kl_nf3;
};

// CHN160531 size 0x988,0xF4(244 per 1)
struct mem_1E55E80_244 {
    char szKiller[32];
    char szUnk2[32];
    char szVictim[32];
    char szUnk4[32];
    char szUnk5[32];
    char szUnk6[32];
    int  nf1;
    int  nf2;
    int  nf3;
    int  nf4; // unk
    int  nf5;
    int  nf6;
    int  nf7;
    int  nf8;
    int  nf9;
    float  nf10;
    float  nf11;
    float* nf12;
    int  nf13;
};

// CHN141219 size 0x6E0,0xB0(176 per 1)
struct mem_1D869C0 {
    char szKiller[32];
    char szUnk2[32];
    char szVictim[32];
    char szUnk4[32];
    int  nf1;
    int  nf2;
    int  nf3;
    int  nf4; // unk
    int  nf5;
    int  nf6;
    int  nf7;
    int  nf8;
    int  nf9;
    int  nf10;
    int  nf11;
    float* nf12;
};

// size 0xAC （not sure)
class IImage;
class CHudDeathNotice : CHudCustomBase {
public:
    int d_skull;
    
    int dn_scheme_16;
    int dn_scheme_100;
    int dn_scheme_5;
    int dn_scheme_12;

    IImage* dn_KillBg_left;
    IImage* dn_KillBg_center;
    IImage* dn_KillBg_right;
    IImage* dn_DeathBg_left;
    IImage* dn_DeathBg_center;
    IImage* dn_DeathBg_right;

    int dn_KM_Number0;
    int dn_KM_Number1;
    int dn_KM_Number2;
    int dn_KM_Number3;
    int dn_KM_KillText;
    int dn_KM_Icon_Head;
    int dn_KM_Icon_Knife;
    int dn_KM_Icon_Frag;
    int dn_KM_Icon_adrenalineshot;

    char dn_nf1;
    int dn_nf2;
    int dn_nf3;
    char dn_nf4;
    int dn_nf5;
    int dn_nf6;

    float dn_nf7;
    float dn_nf8;
    float dn_nf9;
    float dn_nf10;
    float dn_nf11;
    float dn_nf12;

    int dn_nf13;
    int dn_nf14;
    
    CInGameKillLog_cl* pKillLog;
    CHudFadeImage*  pFadeImage;
    CHudSlideImage* pSlideImage;
};

class CHudAmmo : CHudCustomBase {
    int nf41[29];
};
class CHudHealth : CHudCustomBase {
    int nf42[228];
};
class CHudSpectator : CHudCustomBase {
    int nf43[1002];
};
class CHudGeiger : CHudCustomBase {
};
class CHudBattery : CHudCustomBase {
    int nf45[6];
};
class CHudTrain : CHudCustomBase {
};
class CHudFlashlight : CHudCustomBase {
    int nf46[11];
};
class CHudMessage : CHudCustomBase {
    int nf47[152];
};
class CHudStatusBar : CHudCustomBase {
    int nf48[45];
};
class CHudSayText : CHudCustomBase {
    int nf49;
};
class CHudMenu : CHudCustomBase {
    int nf50[3];
};
class CHudAmmoSecondary : CHudCustomBase {
    int nf51[5];
};
class CHudTextMessage : CHudCustomBase {
    int nf[8];
};
class CHudStatusIcons : CHudCustomBase {
    int nf[54];
};
class CHudAccountBalance : CHudCustomBase {
    int nf[9];
};
class CHudRoundTimer : CHudCustomBase {
    int nf[9];
};
class CHudProgressBar : CHudCustomBase {
    int nf[9];
};
class CHudNightVision : CHudCustomBase {
    int nf[7];
};
class CHudCareerTaskTimer : CHudCustomBase {
    int nf[8];
};
class CHudScenarioStatus : CHudCustomBase {
    int nf[9];
};
class CHudSniperScope : CHudCustomBase {
    int nf[17];
};
class CHudVGUI2Print : CHudCustomBase {
    int nf[263];
};
class CHudFirst : CHudCustomBase {
    int nf[145];
};
class CHudInGame : CHudCustomBase {
    int nf[6];
};

class IRibbonSystemListener {
public:
    virtual void Func1();
    virtual void Func2();
    virtual void Func3();
};

// CHN160531 0xE0(224)
class CHudIngameAnnounce : CHudCustomBase {
    IRibbonSystemListener pListener;

    int nf1_map; // std::map
    int nf1_size;

    int nf2[35];

    int nf3;
    int nf4;
    int nf5;
    int nf6;
    int nf7;

    int nf8;
    CHudFadeImage* pImage1;
    CHudFadeImage* pImage2;
    CHudFadeImage* pImage3;

    float nf9;
    float nf10;

    char nf11;
};

class CInterpolation {
public:
    virtual void Func1();

public:
    int nf[526];
};

class CParticleEmitter : CHudCustomBase {
public:
    virtual void Func1();

public:
    int nf[20484];
};

class CVisionColor : CHudCustomBase {
public:
    virtual void Func1();

public:
    int nf[1215];
};

class CHud2 {
public:
    virtual int  Func1();
    virtual void Func2();
    virtual void Func3();
};

class CHud {
public:
    virtual void Func1();
    virtual void Func2();
    virtual void Func3();
    virtual void Func4();
    virtual void Func5();

public:
    CHud2* nf1;
    PointerLinker* nf2;
    int nf3;
    int nf4;
    client_sprite_t* pHud;
    int nf6;
    int iSpriteCount;
    int nf7_2[3];
    float fTime;
    int nf7_0[14];
    int nf7_1;
    int nf7_a[67];
    char nf7_b;
    int nf7_c[4];

    int nf8[64][3];
    int nf9[64][3];
    int nf10[128][3];

    int nf11;
    int nf12;
    int nf13;
    int nf14;
    int nf15;
    int nf16;
    int nf17;
    int nf18;
    int nf19;
    int nf20;
    int nf21;
    int nf22;

    int nf23_a[8];
    int nf23_b;
    int nf23_c[19];

    int nf24;
    int nf25;
    int nf26;
    int nf27;
    int nf28;
    int nf29;

    int nf30;
    int nf31;
    int nf32;
    int nf33;
    int nf34;
    int nf35;
    int nf36;
    int nf37;
    int nf38;

    int nf39_a[444];
    int nf39_b;
    int nf39_c[150];
    int nf39_d;
    int nf39_e;
    int nf39_f;

    int nf40[5];
    int* nf40_c;
    int* nf40_d;
    char* nf40_a;
    int nf40_b;

    CHudAmmo CHudAmmo;
    CHudHealth CHudHealth;
    CHudSpectator CHudSpectator;

    CInterpolation pInterpolation;

    CHudGeiger CHudGeiger;
    CHudBattery CHudBattery;
    CHudTrain CHudTrain;
    CHudFlashlight CHudFlashlight;
    CHudMessage CHudMessage;
    CHudStatusBar CHudStatusBar;
    CHudDeathNotice CHudDeathNotice;
    CHudSayText CHudSayText;
    CHudMenu CHudMenu;
    CHudAmmoSecondary CHudAmmoSecondary;
    CHudTextMessage CHudTextMessage;
    CHudStatusIcons CHudStatusIcons;
    CHudAccountBalance CHudAccountBalance;
    CHudRoundTimer CHudRoundTimer;
    CHudProgressBar CHudProgressBar;
    CHudNightVision CHudNightVision;
    CHudCareerTaskTimer CHudCareerTaskTimer;
    CHudScenarioStatus CHudScenarioStatus;
    CHudSniperScope CHudSniperScope;
    CHudVGUI2Print CHudVGUI2Print;
    CHudFirst CHudFirst;
    CHudInGame CHudInGame;

    int nf41[222];
    int nf42[28];
    int nf43[15];
    int nf44[10];
    int nf45[5];
    int nf46[105];
    int nf47[5];
    int nf48[69];
    int nf49[123];
    int nf50[89];
    int nf51[18];
    int nf52[6];
    int nf53[8];

    CHudIngameAnnounce* CHudIngameAnnounce;
    CParticleEmitter CParticleEmitter;
    CVisionColor CVisionColor;

    int nf54;
    int nf55;
    int nf56;
    int nf57;

    int nf58[29];

    int nf59_map; // std::map
    int nf59_mapSize;

    int nf61_a[20];
    float nf61_b;
    int nf61_c;

    int nf62;
    int nf63;
    int nf64;
    int nf65;
    int nf66;
};
