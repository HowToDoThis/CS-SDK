#include "cbase.h"

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

// 0x2D8
class CGrenade : public CBaseMonster {
public:
	virtual void Detonate();
	virtual void BounceSound();
	virtual void Grenade_unk03();

public:
	int grenade_nf1;
	int grenade_nf2;
	int grenade_nf3;
	bool grenade_nf4;
	bool m_bStartDefuse;
	bool m_bIsC4;
	EHANDLE m_pBombDefuser;
	float m_flDefuseCountDown;
	float m_flC4Blow;
	float m_flNextFreqInterval;
	float m_flNextBeep;
	float m_flNextFreq;
	char grenade_nf5;
	float m_fAttenu;
	float m_flNextBlink;
	float m_fNextDefuse;
	bool m_bJustBlew;
	int m_iTeam;
	int m_iCurWave;
	edict_t *m_pentCurBombTarget;
	int m_SGSmoke;
	int m_angle;
	unsigned short m_usEvent;
	bool m_bLightSmoke;
	bool m_bDetonated;
	Vector m_vSmokeDetonate;
	int m_iBounceCount;
	BOOL m_fRegisteredSound;
};

class CPointEntity : CBaseEntity {

};

// custom enum
enum InfoMapBuyParam {
	BUYING_EVERYONE = 0,
	BUYING_ONLY_CTS,
	BUYING_ONLY_TERRORISTS,
	BUYING_NO_ONE,
};

class CMapInfo : CPointEntity {
public:

public:
	short mi_nf1;
	InfoMapBuyParam m_iBuyingStatus;
	float m_flBombRadius;
};