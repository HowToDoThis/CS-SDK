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
    virtual void Func2_Save();
    virtual void Func3_Read();
    virtual int  Func4(int,int);
    virtual int  Func5(int,int);
    virtual void Func6();
    virtual bool ClientCommand_DeadOrAlive(class CBasePlayer* pPlayer, const char* pcmd);
    virtual int  Func7(int,int);
    virtual void Func8();
    virtual void Func9();
    virtual void Func10();
    virtual void Func11();
    virtual void InitHUD(class CBasePlayer* pPlayer);
    virtual void Think();
    virtual void RestartRoundCheck();
    virtual void OnRoundFreezeEnd(); // func15
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
    virtual void RestartRound();
    virtual void TeamBalance();
    virtual void Reset();
    virtual void SetRoundStartTime();
    virtual void Func49(); // related CBasePlayer
    virtual void Func50();
    virtual void Func51(); // unk
    virtual void Func52();
    virtual void BalanceTeams();
    virtual void InitializePlayerCounts();
    virtual void Func56(int);
    virtual bool CheckWinConditions();
    virtual void Func58();
    virtual void Broadcast(const char* sentence);
    virtual void Func60();
    virtual void Func61();
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
    // has 160 funcs

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