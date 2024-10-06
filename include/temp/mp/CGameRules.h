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

struct skilldata_t {
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
    virtual void Func(int, unsigned short, unsigned char);

public:
    class CGameRules* gGameRules;
};

class CGameRules {
public:
    virtual ~CGameRules();
    virtual void RefreshSkillData();
    virtual void Think();
    virtual bool IsAllowedToSpawn(int);
    virtual bool AllowFlashlight(); // mp_flashlight
    virtual bool ShouldSwitchWeapon(CBasePlayer*,CBasePlayerWeapon*);
    virtual bool GetNextBestWeapon(CBasePlayer*,CBasePlayerWeapon*);
    virtual bool IsMultiplayer(); // return 1
    virtual bool IsDeathmatch(); // return 1
    virtual bool IsTeamplay(); // return 0
    virtual bool IsCoop(); // return gpGlobal->coop
    virtual const char* GetGameDescription();
    virtual bool ClientConnected(edict_t *pEntity, const char *pszName, const char *pszAddress, char *szRejectReason); // CSOGameRules->Func10
    virtual void InitHUD(); // CSOGameRules->Func11
    virtual void ClientDisconnected(); // CSOGameRules->Func27
    virtual void UpdateGameMode(); // msgGameMode = 1
    virtual void Func17(); // CSOGameRules->Func102
    virtual void Func18(); // CSOGameRules->Func101
    virtual void Func19(CBasePlayer *a2, CBasePlayer *a3, entvars_t *a4, int a5);
    virtual int  PlayerCanTakeDamage(CBasePlayer*, CBasePlayer*); // maybe
    virtual int  Func21(CBasePlayer*, CBasePlayer*);
    virtual void Func22(); // CSOGameRules->Func106
    virtual int  Func23(); // CSOGameRules->Func92
    virtual bool PlayerCanRespawn(CBasePlayer*);
    virtual float PlayerSpawnTime(CBasePlayer*);
    virtual int  Func26(CBasePlayer*); // CSOGameRules->Func105
    virtual int  Func27(); // return 0
    virtual void ClientUserInfoChanged(CBasePlayer *a1, char *a2);
    virtual int  Func29();
    virtual int  Func30(); // CSOGameRules->Func66
    virtual int  Func31(); // CSOGameRules->Func75, SendDeathMessage
    virtual int  Func32(CBasePlayer*, CBasePlayerWeapon*);

public:
    BOOL m_bFreezePeriod;// ok
    BOOL m_bBombDropped;// ok

    int* gMonsterManager; // size 0x14DC(5340)

    int rules_nf1[3];
    int* rules_vec1_a;
    int* rules_vec1_b;
    int* rules_vec1_c;

    int rules_nf2[85];
    class GameOptionManager* gOption;// ok
    class CSharedDataMgr* gSharedDataMgr;// ok
    class IGBuyMenuMgr* gBuyMenuMgr;// ok
    class IGClassMenuMgr* gClassMenuMgr;// ok
    class CSOFacade* gCSOFacade;// ok
    class GamePlayerManager* gGamePlayerMgr;// ok
    class StrGen* gStrGen;// ok
    char rules_nf3;
    class CZBSItemListener* gCZBSItemListener;// ok
    char m_iNumAliveCT; // ok
    char m_iNumAliveTR; // ok
    char m_iNumDeadCT; // ok
    char m_iNumDeadTR; // ok

    char rules_nf4;
    bool bPlayGameStart; // audio GameStart?
    char rules_nf6;
    char rules_nf7;

    bool m_bGameOver;// ok
    char mp_movingshot; // ok
};

// 0x4E8 (1256)
class CHalfLifeMultiplay : CGameRules {
public:

public:
    CVoiceGameMgr m_VoiceGameMgr; // ok
    float m_flRestartRoundTime;
    float m_flCheckWinConditions;
    float m_fRoundStartTime; // ok
    int m_iRoundTime; // ok
    int m_iRoundTimeSecs; // ok
    int m_iIntroRoundTime; // ok
    float m_fRoundStartTimeReal;
    int __undef9;
    char m_iNumTR; // ok
    char m_iNumCT; // ok
    char m_iNumSpawnableTerrorist; // ok
    char m_iNumSpawnableCT; // ok
    int m_iSpawnPointCount_TR; // ok
    int m_iSpawnPointCount_CT; // ok
    char m_iHostagesRescued; // ok
    int  m_iHostagesTouched; // ok
    int m_iRoundWinStatus; // ok
    short m_iNumCTWins; // ok
    short m_iNumTerroristWins; // ok

    char m_bIsCareer; // ok
    char multi_nf1a; // related timeout, #CSO_GameEndByTimeLimit
    char multi_nf1c;
    char multi_nf1d;

    short __undef25;
    short __undef26;
    short __undef27;
    short __undef28;
    short m_iNumSpectator;
    short m_iNumUnassigned;

    float multi_nf23;
    char multi_nf24_a;
    char multi_nf24_b;
    bool m_bNextRound; // CSO_MR
    char multi_nf26;
    int multi_nf27;
    short multi_nf28_a;
    short multi_nf28_b;
    float multi_32;
    float multi_33;
    float multi_34;
    float multi_35;
    float sv_accelerate;
    float sv_friction;
    float sv_stopspeed;
    
    int undef7;
    bool undef10;
    bool undef12;
    bool undef9;
    float m_flRequiredEscapeRatio;
    int m_iNumEscapers;
    int u4;
    bool u2;
    bool u3;
    float u1;
    int undef8[2];

    bool m_bTargetBombed; // ok
    bool m_bBombDefused; // ok
    
    bool m_bMapHasBombTarget; // ok
    bool m_bMapHasBombZone; // ok
    bool m_bMapHasBuyZone; // ok
    bool m_bMapHasRescueZone; // ok
    bool m_bMapHasEscapeZone; // ok
    int m_bMapHasVIPSafetyZone; // ok

    int undef;
    int m_iC4Timer;
    int m_iC4Guy;
    int m_iLoserBonus;
    int m_iNumConsecutiveCTLoses;
    int m_iNumConsecutiveTerroristLoses;
    float m_fMaxIdlePeriod;
    int m_iLimitTeams;

    bool m_bLevelInitialized; // ok
    char m_bRoundTerminating; // ok
    bool m_bCompleteReset; // ok
    char undef10_1;
    int undef_4_a;
    char undef_4_b_a;
    char m_iHaveEscaped; // ok
    char bCTCantBuy; // ok
    char bTCantBuy; // ok
    float m_flBombRadius; // ok
    char m_iConsecutiveVIP; // ok
    int m_iTotalGunCount;
    int m_iTotalGrenadeCount;
    int m_iTotalArmourCount;
    int m_iUnBalancedRounds;
    int m_iNumEscapeRounds;

    int m_iMapVotes[MAX_VOTE_MAPS];// ok

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
    int multi_nf18;
    float m_flIntermissionEndTime;
    float m_flIntermissionStartTime;
    int multi_nf19; // m_iEndIntermissionButtonHit?
    int multi_nf20;
    char m_bInCareerGame;
    float m_fCareerRoundMenuTime;// ok
    int m_iCareerMatchWins;
    int m_iRoundWinDifference;
    float m_fCareerMatchMenuTime;// ok
    char m_bSkipSpawn;// ok
    int multi_proc_1;
    int multi_proc_2;
};
#ifndef IDA
static_assert(sizeof(CHalfLifeMultiplay) == 0x4E8, "CHalfLifeMultiplay");
#endif

// 0x500 (1280)
class CHalfLifeTraining : public CHalfLifeMultiplay {
public:
    int training_nf1;
    int training_nf2;
    int training_nf3;
    int training_nf4;
    int training_nf5;
};
#ifndef IDA
static_assert(sizeof(CHalfLifeTraining) == 0x500, "CHalfLifeTraining");
#endif
