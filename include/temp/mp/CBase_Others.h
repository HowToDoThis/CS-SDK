struct CCycler : CBaseMonster {
    int uf_cycler1;
    char m_animate;
};

struct CBaseTrigger : CBaseToggle {

};

struct CBasePlatTrain : CBaseToggle {
    char m_bMoveSnd;
    char m_bStopSnd;
    float m_volume;
};

typedef struct locksounds
{
	string_t sLockedSound;
	string_t sLockedSentence;
	string_t sUnlockedSound;
	string_t sUnlockedSentence;
	int iLockedSentence;
	int iUnlockedSentence;
	float flwaitSound;
	float flwaitSentence;
	byte bEOFLocked;
	byte bEOFUnlocked;
} locksound_t;
typedef enum { BUTTON_NOTHING, BUTTON_ACTIVATE, BUTTON_RETURN } BUTTON_CODE;
struct CBaseButton : CBaseToggle {
    BOOL m_fStayPushed; // ok
	BOOL m_fRotating;
	string_t m_strChangeTarget;
	locksound_t m_ls;
	byte m_bLockedSound;
	byte m_bLockedSentence;
	byte m_bUnlockedSound;
	byte m_bUnlockedSentence;
	int m_sounds;
};

struct CWorld : CBaseEntity {
};