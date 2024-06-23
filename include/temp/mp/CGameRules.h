struct CVoiceGameMgr {
    void* vfptr;

	int voice_nf1;
    int m_msgPlayerVoiceMask;
    int m_msgRequestState;
    struct IVoiceGameMgrHelper *m_pHelper;
    int m_nMaxPlayers;
    double m_UpdateInterval;
};

struct CGameRules {
    void* vfptr;

    int cso_add1[102];

    BOOL m_bFreezePeriod;
    BOOL m_bBombDropped;

    // custom
    char *m_GameDesc;
    bool m_bGameOver;
};

#define MAX_VOTE_MAPS 100
#define MAX_VIP_QUEUES 5

struct CHalfLifeMultiplay : CGameRules {
    CVoiceGameMgr m_VoiceGameMgr;
    float m_flRestartRoundTime;
    float m_flCheckWinConditions;
    float m_fRoundStartTime;
    int m_iRoundTime;
    int m_iRoundTimeSecs;
    int m_iIntroRoundTime;
    float m_fRoundStartTimeReal;
    int m_iAccountTerrorist;
    int m_iAccountCT;
    int m_iNumTerrorist;
    int m_iNumCT;
    int m_iNumSpawnableTerrorist;
    int m_iNumSpawnableCT;
    int m_iSpawnPointCount_Terrorist;
    int m_iSpawnPointCount_CT;

	char m_bIsCareer;
	char multi_nf1a;
	char multi_nf1c;
	char multi_nf1d;

    int m_iHostagesRescued;
    int m_iHostagesTouched;
    int m_iRoundWinStatus;

    short m_iNumCTWins;
    short m_iNumTerroristWins;

    bool m_bTargetBombed;
    bool m_bBombDefused;

    bool m_bMapHasBombTarget;
    bool m_bMapHasBombZone;
    bool m_bMapHasBuyZone;
    bool m_bMapHasRescueZone;
    bool m_bMapHasEscapeZone;

    BOOL m_bMapHasVIPSafetyZone;
    BOOL m_bMapHasCameras;
    int m_iC4Timer;
    int m_iC4Guy;
    int m_iLoserBonus;
    int m_iNumConsecutiveCTLoses;
    int m_iNumConsecutiveTerroristLoses;

    float m_fMaxIdlePeriod;    
    
    int m_iLimitTeams;
    bool m_bLevelInitialized;
    bool m_bRoundTerminating;
    bool m_bCompleteReset;
    float m_flRequiredEscapeRatio;
    int m_iNumEscapers;
    int m_iHaveEscaped;
    bool m_bCTCantBuy;
    bool m_bTCantBuy;
    float m_flBombRadius;
    int m_iConsecutiveVIP;
    int m_iTotalGunCount;
    int m_iTotalGrenadeCount;
    int m_iTotalArmourCount;
    int m_iUnBalancedRounds;
    int m_iNumEscapeRounds;
    int m_iMapVotes[MAX_VOTE_MAPS];
    int m_iLastPick;
    int m_iMaxMapTime;
    int m_iMaxRounds;
    int m_iTotalRoundsPlayed;
    int m_iMaxRoundsWon;
    int m_unk1;
    float m_unk2;
    float m_unk3;
    float m_unk4;
    struct CBasePlayer *m_pVIP;
    struct CBasePlayer *m_pVIPQueue[MAX_VIP_QUEUES];

    float m_flIntermissionEndTime;
    float m_flIntermissionStartTime;
    BOOL m_iEndIntermissionButtonHit;
    float m_tmNextPeriodicThink;
    bool m_bGameStarted;
    bool m_bInCareerGame;
    float m_fCareerRoundMenuTime;
    int m_iCareerMatchWins;
    int m_iStoredSpectValue; // ok
    float m_flForceCameraValue;
    float m_flForceChaseCamValue;
    float m_flFadeToBlackValue;
};