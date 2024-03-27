struct CVoiceGameMgr {
    void* vfptr;

    int m_msgPlayerVoiceMask;
	int m_msgRequestState;
	struct IVoiceGameMgrHelper *m_pHelper;
	int m_nMaxPlayers;
	double m_UpdateInterval; // How long since the last update.
};

struct CGameRules {
    void* vfptr;

    int cso_add1[102];

    BOOL m_bFreezePeriod;	// TRUE at beginning of round, set to FALSE when the period expires
	BOOL m_bBombDropped;

	// custom
	char *m_GameDesc;
	bool m_bGameOver; // intermission or finale (deprecated name g_fGameOver)
};

#define MAX_VOTE_MAPS 100
#define MAX_VIP_QUEUES 5

struct CHalfLifeMultiplay : CGameRules {
    CVoiceGameMgr m_VoiceGameMgr;
	float m_flRestartRoundTime;			// The global time when the round is supposed to end, if this is not 0 (deprecated name m_fTeamCount)
	float m_flCheckWinConditions;
	float m_fRoundStartTime;			// Time round has started (deprecated name m_fRoundCount)
	int m_iRoundTime;					// (From mp_roundtime) - How many seconds long this round is.
	int m_iRoundTimeSecs;
	int m_iIntroRoundTime;				// (From mp_freezetime) - How many seconds long the intro round (when players are frozen) is.
	float m_fRoundStartTimeReal;		// The global time when the intro round ends and the real one starts
										// wrote the original "m_flRoundTime" comment for this variable).
	int m_iAccountTerrorist;
	int m_iAccountCT;
	int m_iNumTerrorist;				// The number of terrorists on the team (this is generated at the end of a round)
	int m_iNumCT;						// The number of CTs on the team (this is generated at the end of a round)
	int m_iNumSpawnableTerrorist;
	int m_iNumSpawnableCT;
	int m_iSpawnPointCount_Terrorist;	// Number of Terrorist spawn points
	int m_iSpawnPointCount_CT;			// Number of CT spawn points
	int m_iHostagesRescued;
	int m_iHostagesTouched;
	int m_iRoundWinStatus;				// 1 == CT's won last round, 2 == Terrorists did, 3 == Draw, no winner

	short m_iNumCTWins;
	short m_iNumTerroristWins;

	bool m_bTargetBombed;				// whether or not the bomb has been bombed
	bool m_bBombDefused;				// whether or not the bomb has been defused

	bool m_bMapHasBombTarget;
	bool m_bMapHasBombZone;
	bool m_bMapHasBuyZone;
	bool m_bMapHasRescueZone;
	bool m_bMapHasEscapeZone;

	BOOL m_bMapHasVIPSafetyZone;			// TRUE = has VIP safety zone, FALSE = does not have VIP safetyzone
	BOOL m_bMapHasCameras;
	int m_iC4Timer;
	int m_iC4Guy;							// The current Terrorist who has the C4.
	int m_iLoserBonus;						// the amount of money the losing team gets. This scales up as they lose more rounds in a row
	int m_iNumConsecutiveCTLoses;			// the number of rounds the CTs have lost in a row.
	int m_iNumConsecutiveTerroristLoses;	// the number of rounds the Terrorists have lost in a row.

	float m_fMaxIdlePeriod;					// For the idle kick functionality. This is tha max amount of time that the player has to be idle before being kicked

	int m_iLimitTeams;
	bool m_bLevelInitialized;
	bool m_bRoundTerminating;
	bool m_bCompleteReset;					// Set to TRUE to have the scores reset next time round restarts
	float m_flRequiredEscapeRatio;
	int m_iNumEscapers;
	int m_iHaveEscaped;
	bool m_bCTCantBuy;
	bool m_bTCantBuy;					// Who can and can't buy.
	float m_flBombRadius;
	int m_iConsecutiveVIP;
	int m_iTotalGunCount;
	int m_iTotalGrenadeCount;
	int m_iTotalArmourCount;
	int m_iUnBalancedRounds;			// keeps track of the # of consecutive rounds that have gone by where one team outnumbers the other team by more than 2
	int m_iNumEscapeRounds;				// keeps track of the # of consecutive rounds of escape played.. Teams will be swapped after 8 rounds
	int m_iMapVotes[MAX_VOTE_MAPS];
	int m_iLastPick;
	int m_iMaxMapTime;
	int m_iMaxRounds;
	int m_iTotalRoundsPlayed;
	int m_iMaxRoundsWon;
	int m_iStoredSpectValue;
	float m_flForceCameraValue;
	float m_flForceChaseCamValue;
	float m_flFadeToBlackValue;
	struct CBasePlayer *m_pVIP;
	struct CBasePlayer *m_pVIPQueue[MAX_VIP_QUEUES];

    float m_flIntermissionEndTime;
	float m_flIntermissionStartTime;
	BOOL m_iEndIntermissionButtonHit;
	float m_tmNextPeriodicThink;
	bool m_bGameStarted;				// TRUE = the game commencing when there is at least one CT and T, FALSE = scoring will not start until both teams have players (deprecated name m_bFirstConnected)
	bool m_bInCareerGame;
	float m_fCareerRoundMenuTime;
	int m_iCareerMatchWins;
	int m_iRoundWinDifference;
	float m_fCareerMatchMenuTime;
	bool m_bSkipSpawn;

	// custom
	bool m_bSkipShowMenu;
	bool m_bNeededPlayers;
	float m_flEscapeRatio;
	float m_flTimeLimit;
	float m_flGameStartTime;
	bool m_bTeamBalanced;
};