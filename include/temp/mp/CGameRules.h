#define MAX_VOTE_MAPS 100
#define MAX_VIP_QUEUES 5

class IVoiceGameMgrHelper {
public:
	virtual ~IVoiceGameMgrHelper();
	virtual bool CanPlayerHearPlayer(class CBasePlayer *pListener, class CBasePlayer *pTalker);
};

class CCStrikeGameMgrHelper: public IVoiceGameMgrHelper {

};

struct CVoiceGameMgr {
    void* vfptr;

	int voice_nf1;
    int m_msgPlayerVoiceMask;
    int m_msgRequestState;
    IVoiceGameMgrHelper *m_pHelper;
    int m_nMaxPlayers;
    double m_UpdateInterval;
};

struct skilldata_t
{
	int iSkillLevel;
	float plrDmg9MM;
	float plrDmg357;
	float plrDmgMP5;
	float plrDmgM203Grenade;
	float plrDmgBuckshot;
	float plrDmgCrossbowClient;
	float plrDmgRPG;
	float monDmg9MM;
	float monDmgMP5;
	float monDmg12MM;
	float suitchargerCapacity;
	float batteryCapacity;
	float healthchargerCapacity;
	float healthkitCapacity;
};

class CZBSItemListener {
public:
    virtual void Func(int, uint16_t, uint8_t);

public:
    class CGameRules* gGameRules;
};

class CGameRules {
public:
    virtual ~CGameRules();
    virtual void RefreshSkillData();
    virtual void Think();

public:
    BOOL m_bFreezePeriod; // ok
    BOOL m_bBombDropped; // ok

    int* gMonsterManager; // size 0x14DC(5340)

    int rules_nf1[3];
    int* rules_vec1_a;
    int* rules_vec1_b;
    int* rules_vec1_c;

    int rules_unk[85];
    class GameOptionManager* gOption; // ok
    class CSharedDataMgr* gSharedDataMgr; // ok
    class IGBuyMenuMgr* gBuyMenuMgr; // ok
    class IGClassMenuMgr* gClassMenuMgr; // ok
    class CSOFacade* gCSOFacade; // ok
    class GamePlayerManager* gGamePlayerMgr; // ok
    class StrGen* gStrGen; // ok
    char rules_nf92;
    class CZBSItemListener* gCZBSItemListener; // ok
    int rules_nf94;
    int rules_nf95;

    bool m_bGameOver;
    char mp_movingshot;
};

// 0x4E8 (1256)
class CHalfLifeMultiplay : CGameRules {
public:

public:
    CVoiceGameMgr m_VoiceGameMgr; // ok
    float m_flRestartRoundTime;
    float m_flCheckWinConditions;
    float m_fRoundStartTime; // ok
    int m_iRoundTime;
    int m_iRoundTimeSecs; // ok
    int m_iIntroRoundTime; // ok
    float m_fRoundStartTimeReal;
    int m_iNumTR;
    int m_iNumCT; // ok
    int m_iAccountCT;
    int m_iNumTerrorist;
    char m_iNumSpawnableTerrorist;
    int m_iNumSpawnableCT;
    int m_iRoundWinStatus;
    int m_iSpawnPointCount_CT;

	char m_bIsCareer;
	char multi_nf1a;
	char multi_nf1c;
	char multi_nf1d;

    int m_iHostagesRescued;
    int m_iHostagesTouched;
    int multi_nf22;

    float multi_nf23;
    short multi_nf24;
    char multi_nf25;
    char multi_nf26;
    int multi_nf27;
    int multi_nf28;
    float multi_32;
    float multi_33;
    float multi_34;
    float multi_35;    
    float multi_37;
    float multi_38;
    float multi_39;    
    
    int undef7;
    bool m_bLevelInitialized;
    bool m_bRoundTerminating;
    bool m_bCompleteReset;
    float m_flRequiredEscapeRatio;
    int m_iNumEscapers;
    int m_iHaveEscaped;
    bool m_bCTCantBuy;
    bool m_bTCantBuy;
    float m_flBombRadius;
    int undef8[2];

    // ok
	bool m_bMapHasBombTarget;
	bool m_bMapHasBombZone;
	bool m_bMapHasBuyZone;
    char m_bMapHasRescueZone;
    char m_bMapHasEscapeZone;
    int m_bMapHasVIPSafetyZone;
    int multi_nf50; // unk
	int m_iC4Timer;
	int m_iC4Guy;
	int m_iLoserBonus;
	int m_iNumConsecutiveCTLoses;
	int m_iNumConsecutiveTerroristLoses;
    float m_fMaxIdlePeriod;
	int m_iLimitTeams;

    int undef_4[4];
	char m_iConsecutiveVIP; // ok
	int m_iTotalGunCount;
	int m_iTotalGrenadeCount;
	int m_iTotalArmourCount;
	int m_iUnBalancedRounds;
	int m_iNumEscapeRounds;

    int m_iMapVotes[MAX_VOTE_MAPS]; // ok

	int m_iLastPick;
	int m_iMaxMapTime;
	int m_iMaxRounds; // ok
	int m_iTotalRoundsPlayed;
	int m_iMaxRoundsWon; // ok
	int m_iStoredSpectValue; // ok
	float m_flForceCameraValue;
	float m_flForceChaseCamValue;
	float m_flFadeToBlackValue;

    int undef_2;
    int multi_nf1;
    float multi_nf2;
    int iGameMode;
    int iGameMode2;
    int multi_nf5;
    int mp_endfrags;
    int multi_nf7;
    CBasePlayer* m_pVIP;
    int m_pVIP_Index;
	CBasePlayer* m_pVIPQueue[MAX_VIP_QUEUES];

protected:
    float m_flIntermissionEndTime;
    float m_flIntermissionStartTime;
    int multi_nf18;
    int multi_nf19;
    int multi_nf20;
    char m_bInCareerGame;
	float m_fCareerRoundMenuTime;
    int m_iCareerMatchWins;
    int m_iRoundWinDifference;
    float m_fCareerMatchMenuTime;
    char m_bSkipSpawn;
    int multi_proc_1;
    int multi_proc_2;
};

// 0x500 (1280)
class CHalfLifeTraining : public CHalfLifeMultiplay {
public:
    int training_nf1;
    int training_nf2;
    int training_nf3;
    int training_nf4;
    int training_nf5;
};