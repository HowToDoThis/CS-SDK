class CSOGameRules {
public:
    virtual ~CSOGameRules();

public:
    int rules_nf1;
    int rules_nf2;
    int rules_nf3;
    int rules_nf4;
    int rules_nf5;
    int rules_nf6;
    char rules_nf7;
    short rules_nf8[160];
    int rules_nf9;
    int rules_nf10;
};

class CInGameKillLog {
public:
    virtual ~CInGameKillLog();

public:
    char killlog_nf1;
    int killlog_nf2; // vector
    int killlog_nf3;
    int killlog_nf4;
    int killlog_nf5;
};

// size 0x16C
class CSOGameRulesORI : public CSOGameRules {
public:
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