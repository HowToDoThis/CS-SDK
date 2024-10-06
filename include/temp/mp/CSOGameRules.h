struct CSOGameRules_unknown_1 {
    int* mapHead;
    unsigned int mapSize;
    int nf1;
    int nf2;
    int nf3;
    char nf4;
};

class CSOGameRules {
public:
    virtual ~CSOGameRules();
    virtual void Func1();
    virtual void Save();
    virtual void Restore();
    virtual int  Func5(int,int);
    virtual int  Func6(int,int);
    virtual bool ClientCommand_DeadOrAlive(class CBasePlayer* pPlayer, const char* pcmd);
    virtual int  Func7(int,int);
    virtual void Func8();
    virtual void Func9();
    virtual int  Func10(int,int,int,int);
    virtual void Func11();
    virtual void InitHUD(class CBasePlayer* pPlayer);
    virtual void Think();
    virtual void RestartRoundCheck();
    virtual void OnRoundStart(); // func15
    virtual void SendMsgAllowSpec();
    virtual void SendMsgForceCam();
    virtual void SendMsgMHRSt();
    virtual void Func19(); // set lose, give defitems
    virtual void Func20(); // gmsgRemainTime
    virtual void Func21(); // gmsgRemainTime
    virtual void Func22(); // force end? 승수 채워서 종료
    virtual void OnRoundFreezeEnd();
    virtual void Func24(); // empty
    virtual void Func25(int); // empty
    virtual void CheckLevelInitialized();
    virtual void Func27();
    virtual void ClientDisconnected(edict_t* pClient);
    virtual void Func29();
    virtual void Func30();
    virtual char Func31(); // related VIP
    virtual char Func32();
    virtual char Func33(); // ret multi_nf1a;
    virtual void GoToIntermission();
    virtual int  Return16000();
    virtual int  Return800(int);
    virtual int  Func37(int);
    virtual char Func38();
    virtual char Func39();
    virtual char Func40();
    virtual double Func41(); // return 3.0
    virtual char Func42(int, const char*,int,int*);
    virtual void Func43(int,int,int);
    virtual void Func44(); // FlyerFlock
    virtual void RestartRound(); // func45
    virtual void TeamBalance();
    virtual void Reset();
    virtual void SetRoundStartTime();
    virtual void Func49(); // related CBasePlayer
    virtual void Func50();
    virtual void Func51(); // unk
    virtual void Func52();
    virtual void BalanceTeams();
    virtual void InitializePlayerCounts(); // func55
    virtual void Func56(int);
    virtual bool CheckWinConditions();
    virtual void Func58();
    virtual void Broadcast(const char* sentence);
    virtual void Func60();
    virtual void Func61(); // call Func110(2,0,0)
    virtual char Func62(int);
    virtual void Func63(CBaseEntity*); // drop cmd_argv(1)
    virtual char Func64(int,int);
    virtual char Func65(int,int,int);
    virtual void Func66(CBasePlayer*,edict_t*,entvars_t*);
    virtual void Func67();
    virtual void PlayerKilled();
    virtual void Func69(int,int,int*,int*);
    virtual void Func70(int,int,CBasePlayer*); // send host7
    virtual void KilledVIP(CBasePlayer*,int,CBasePlayer*,int);
    virtual void Func72(int,int,CBasePlayer*); // send host7
    virtual void Func73(int);
    virtual void Func74(int,int,int);
    virtual void SendDeathMessage(CBaseEntity *pKiller, CBasePlayer *pVictim, CBasePlayer *pAssister, entvars_t *pevInflictor);
    virtual void Func76(int,int,int,int,int);
    virtual void SendKillInfo();
    virtual void Func78(int,int);
    virtual void Func79(int,int);
    virtual void Func80(int,int);
    virtual void Func81(int);
    virtual void Func82(int);
    virtual void Func83(CBasePlayer*, int*); // related FL_ONGROUND
    virtual void Func84(CBasePlayer*); // related think
    virtual void Func85(int); // buy_spawn
    virtual void Func86(int,int);
    virtual void Func87(int,int);
    virtual void SetMaxSpeed(CBasePlayer*, float);
    virtual void IsNotJump(CBasePlayer*);
    virtual void Func90(int,int,int,int,int);
    virtual void Func91(int,int,int,int,int);
    virtual void Func92(CBasePlayer*); // think?
    virtual void PlayerThink(CBasePlayer*);
    virtual void Func94(CBasePlayer*); // CSO_MR
    virtual void Func95(CBasePlayer*); // CSO_WaitEnemy / CSO_WaitOppTeam
    virtual void Func96(CBasePlayer*);
    virtual void Func97(int);
    virtual void Func98(int,int,int,int,int);
    virtual void Func99(int,int,int,int,int);
    virtual void Func100(int,int);
    virtual void Func101(CBasePlayer*,int*);
    virtual void Func102(CBasePlayer*);
    virtual void Func103();
    virtual void Func104(int,int,int,int,int,int);
    virtual void Func105(CBaseEntity*); // firetargets?
    virtual void Func106();
    virtual void Func107();
    virtual void Func108();
    virtual void Func109();
    virtual void Func110(int,int,int);
    virtual void Func111();
    virtual void Func112(); // return 600.0
    virtual void Func113();
    virtual void Func114();
    virtual void Func115();
    virtual void Func116();
    virtual void Func117();
    virtual void Func118();
    virtual void Func119();
    virtual void Func120();
    virtual void Func121();
    virtual void Func122();
    virtual void Func123();
    virtual void Func124();
    virtual void Func125();
    virtual void Func126();
    virtual void Func127();
    virtual void Func128();
    virtual void Func129();
    virtual void Func130();
    virtual void Func131();
    virtual void Func132();
    virtual void Func133();
    virtual void Func134();
    virtual void Func135();
    virtual void Func136();
    virtual void Func137();
    virtual void Func138();
    virtual void Func139();
    virtual void Func140();
    virtual void Func141();
    virtual void Func142();
    virtual void Func143();
    virtual void Func144();
    virtual void Func145();
    virtual void Func146();
    virtual void Func147();
    virtual void Func148();
    virtual void Func149();
    virtual void Func150();
    virtual void Func151();
    virtual void Func152();
    virtual void Func153();
    virtual void Func154();
    virtual void Func155();
    virtual void Func156();
    virtual void Func157();
    virtual void Func158();
    virtual void Func159();
    virtual void Func160();

public:
    CSOGameRules_unknown_1 rules_nf1;
    char rules_nf7;
    short rules_nf8[160];
};

class CInGameKillLog {
public:
    virtual ~CInGameKillLog();

public:
    char killlog_nf1;

    int killlog_nf2; // map
    int killlog_nf3;

    int killlog_nf4;
    int killlog_nf5;
};

// size 0x164 (356)
class CSOGameRulesDM : public CSOGameRules {
public:
    CInGameKillLog* m_KillLog; // CInGameKillLog
};

class CSOGameRulesTDM : public CSOGameRulesDM {
};

// size 0x16C
class CSOGameRulesORI : public CSOGameRules {
public:
    EHANDLE unk;
    CInGameKillLog* m_KillLog; // CInGameKillLog
};

// size 0x184
class CSOGameRulesLightOri : public CSOGameRulesORI {
public:
    int lightOri_nf1;
    int lightOri_nf2;
    int lightOri_nf3;
    char lightOri_nf4;
    EHANDLE lightOri_nf5;
};

// size 1476 / 0x5C4
class CSOGameRulesIceWorld : public CSOGameRulesORI {
public:
    int iceWorld_nf1;
    int iceWorld_nf2;
    int iceWorld_nf3[63][4];
    int iceWorld_nf4;
    int iceWorld_nf5;
    int iceWorld_nf6;
    int iceWorld_nf7;
    int iceWorld_nf8;
    int iceWorld_nf9;
    int iceWorld_nf10;
    int iceWorld_nf11;
    int iceWorld_nf12;
    int iceWorld_nf13;
    int iceWorld_nf14;
    int iceWorld_nf15;
    int iceWorld_nf16;
    int iceWorld_nf17;
    int iceWorld_nf18;
    int iceWorld_nf19;
    int iceWorld_nf20;
    int iceWorld_nf21;
    int iceWorld_nf22;
    int iceWorld_nf23;
    int iceWorld_nf24;
    int iceWorld_nf25;
    int iceWorld_nf26;
    int iceWorld_nf27;
};

struct ZombiUnk {
    int nf1;
    int nf2;
    int nf3;
    int nf4;
    int nf5;
};

// size 4A4
class CSOGameRulesZombi : public CSOGameRules {
public:
    virtual void Zombi_Func1(CBasePlayer *,CBasePlayer *);
    virtual bool Zombi_Func2(); // call func3
    virtual void Zombi_Func3(); // Countdown
    virtual void Zombi_Func4();
    virtual void Zombi_Func5(CBasePlayer *,CBasePlayer *,char*);
    virtual void Zombi_Func6();

public:
    short zombi_nf1;
    int zombi_nf2;
    int zombi_nf3;

    void* zombi_nf4; // std::map
    int zombi_nf5;
    
    int zombi_undef1[34];
    ZombiUnk zombi_unk1[33];
    int zombi_undef2[5];
};

// size 4B4
class CSOGameRulesZombi2 : public CSOGameRulesZombi {
public:
    virtual void ZombieSelect(CBasePlayer*, char*); // selzmb
    virtual void Zombi2_Func2();
    virtual void Zombi2_Func3(); // Supplybox, weaponbox2_zombie

public:
    void* zombi2_nf1; // std::map
    int zombi2_nf2;

    void* zombi2_nf3; // std::map
    int zombi2_nf4;
};

// size 4E4
class CSOGameRulesZombi3 : public CSOGameRulesZombi2 {
public:
    virtual void Zombi3_Func1();
    virtual void Zombi3_Func2(CBasePlayer*,int,float* a3); // a3 = vector
    virtual void Zombi3_Func3();
    virtual void Zombi3_Func4();
    virtual void Zombi3_Func5();

public:
    int zombi3_nf1;
    int zombi3_nf2;

    int zombi3_nf3;

    int zombi3_nf4;
    int zombi3_nf5;
    int zombi3_nf6;
    int zombi3_nf7;


    int  zombi3_nf8;
    int  zombi3_nf9;

    char zombi3_nf10;

    void* zombi3_nf11; // std::map
    int   zombi3_nf12;
};