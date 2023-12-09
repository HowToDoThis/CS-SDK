enum GameEventType {
    EVENT_INVALID = 0,
    EVENT_WEAPON_FIRED,                    // tell bots the player is attack (argumens: 1 = attacker, 2 = NULL)
    EVENT_WEAPON_FIRED_ON_EMPTY,        // tell bots the player is attack without clip ammo (argumens: 1 = attacker, 2 = NULL)
    EVENT_WEAPON_RELOADED,                // tell bots the player is reloading his weapon (argumens: 1 = reloader, 2 = NULL)

    EVENT_HE_GRENADE_EXPLODED,            // tell bots the HE grenade is exploded (argumens: 1 = grenade thrower, 2 = NULL)
    EVENT_FLASHBANG_GRENADE_EXPLODED,    // tell bots the flashbang grenade is exploded (argumens: 1 = grenade thrower, 2 = explosion origin)
    EVENT_SMOKE_GRENADE_EXPLODED,        // tell bots the smoke grenade is exploded (argumens: 1 = grenade thrower, 2 = NULL)
    EVENT_GRENADE_BOUNCED,

    EVENT_BEING_SHOT_AT,
    EVENT_PLAYER_BLINDED_BY_FLASHBANG,    // tell bots the player is flashed (argumens: 1 = flashed player, 2 = NULL)
    EVENT_PLAYER_FOOTSTEP,                // tell bots the player is running (argumens: 1 = runner, 2 = NULL)
    EVENT_PLAYER_JUMPED,                // tell bots the player is jumped (argumens: 1 = jumper, 2 = NULL)
    EVENT_PLAYER_DIED,                    // tell bots the player is killed (argumens: 1 = victim, 2 = killer)
    EVENT_PLAYER_LANDED_FROM_HEIGHT,    // tell bots the player is fell with some damage (argumens: 1 = felled player, 2 = NULL)
    EVENT_PLAYER_TOOK_DAMAGE,            // tell bots the player is take damage (argumens: 1 = victim, 2 = attacker)
    EVENT_HOSTAGE_DAMAGED,                // tell bots the player has injured a hostage (argumens: 1 = hostage, 2 = injurer)
    EVENT_HOSTAGE_KILLED,                // tell bots the player has killed a hostage (argumens: 1 = hostage, 2 = killer)

    EVENT_DOOR,                            // tell bots the door is moving (argumens: 1 = door, 2 = NULL)
    EVENT_BREAK_GLASS,                    // tell bots the glass has break (argumens: 1 = glass, 2 = NULL)
    EVENT_BREAK_WOOD,                    // tell bots the wood has break (argumens: 1 = wood, 2 = NULL)
    EVENT_BREAK_METAL,                    // tell bots the metal/computer has break (argumens: 1 = metal/computer, 2 = NULL)
    EVENT_BREAK_FLESH,                    // tell bots the flesh has break (argumens: 1 = flesh, 2 = NULL)
    EVENT_BREAK_CONCRETE,                // tell bots the concrete has break (argumens: 1 = concrete, 2 = NULL)

    EVENT_BOMB_PLANTED,                    // tell bots the bomb has been planted (argumens: 1 = planter, 2 = NULL)
    EVENT_BOMB_DROPPED,                    // tell bots the bomb has been dropped (argumens: 1 = NULL, 2 = NULL)
    EVENT_BOMB_PICKED_UP,                // let the bots hear the bomb pickup (argumens: 1 = player that pickup c4, 2 = NULL)
    EVENT_BOMB_BEEP,                    // let the bots hear the bomb beeping (argumens: 1 = c4, 2 = NULL)
    EVENT_BOMB_DEFUSING,                // tell the bots someone has started defusing (argumens: 1 = defuser, 2 = NULL)
    EVENT_BOMB_DEFUSE_ABORTED,            // tell the bots someone has aborted defusing (argumens: 1 = NULL, 2 = NULL)
    EVENT_BOMB_DEFUSED,                    // tell the bots the bomb is defused (argumens: 1 = defuser, 2 = NULL)
    EVENT_BOMB_EXPLODED,                // let the bots hear the bomb exploding (argumens: 1 = NULL, 2 = NULL)

    EVENT_HOSTAGE_USED,                    // tell bots the hostage is used (argumens: 1 = user, 2 = NULL)
    EVENT_HOSTAGE_RESCUED,                // tell bots the hostage is rescued (argumens: 1 = rescuer (CBasePlayer *), 2 = hostage (CHostage *))
    EVENT_ALL_HOSTAGES_RESCUED,            // tell bots the all hostages are rescued (argumens: 1 = NULL, 2 = NULL)

    EVENT_VIP_ESCAPED,                    // tell bots the VIP is escaped (argumens: 1 = NULL, 2 = NULL)
    EVENT_VIP_ASSASSINATED,                // tell bots the VIP is assassinated (argumens: 1 = NULL, 2 = NULL)
    EVENT_TERRORISTS_WIN,                // tell bots the terrorists won the round (argumens: 1 = NULL, 2 = NULL)
    EVENT_CTS_WIN,                        // tell bots the CTs won the round (argumens: 1 = NULL, 2 = NULL)
    EVENT_ROUND_DRAW,                    // tell bots the round was a draw (argumens: 1 = NULL, 2 = NULL)
    EVENT_ROUND_WIN,                    // tell carreer the round was a win (argumens: 1 = NULL, 2 = NULL)
    EVENT_ROUND_LOSS,                    // tell carreer the round was a loss (argumens: 1 = NULL, 2 = NULL)
    EVENT_ROUND_START,                    // tell bots the round was started (when freeze period is expired) (argumens: 1 = NULL, 2 = NULL)
    EVENT_PLAYER_SPAWNED,                // tell bots the player is spawned (argumens: 1 = spawned player, 2 = NULL)
    EVENT_CLIENT_CORPSE_SPAWNED,
    EVENT_BUY_TIME_START,
    EVENT_PLAYER_LEFT_BUY_ZONE,
    EVENT_DEATH_CAMERA_START,
    EVENT_KILL_ALL,
    EVENT_ROUND_TIME,
    EVENT_DIE,
    EVENT_KILL,
    EVENT_HEADSHOT,
    EVENT_KILL_FLASHBANGED,
    EVENT_TUTOR_BUY_MENU_OPENNED,
    EVENT_TUTOR_AUTOBUY,
    EVENT_PLAYER_BOUGHT_SOMETHING,
    EVENT_TUTOR_NOT_BUYING_ANYTHING,
    EVENT_TUTOR_NEED_TO_BUY_PRIMARY_WEAPON,
    EVENT_TUTOR_NEED_TO_BUY_PRIMARY_AMMO,
    EVENT_TUTOR_NEED_TO_BUY_SECONDARY_AMMO,
    EVENT_TUTOR_NEED_TO_BUY_ARMOR,
    EVENT_TUTOR_NEED_TO_BUY_DEFUSE_KIT,
    EVENT_TUTOR_NEED_TO_BUY_GRENADE,
    EVENT_CAREER_TASK_DONE,

    EVENT_START_RADIO_1,
    EVENT_RADIO_COVER_ME,
    EVENT_RADIO_YOU_TAKE_THE_POINT,
    EVENT_RADIO_HOLD_THIS_POSITION,
    EVENT_RADIO_REGROUP_TEAM,
    EVENT_RADIO_FOLLOW_ME,
    EVENT_RADIO_TAKING_FIRE,
    EVENT_START_RADIO_2,
    EVENT_RADIO_GO_GO_GO,
    EVENT_RADIO_TEAM_FALL_BACK,
    EVENT_RADIO_STICK_TOGETHER_TEAM,
    EVENT_RADIO_GET_IN_POSITION_AND_WAIT,
    EVENT_RADIO_STORM_THE_FRONT,
    EVENT_RADIO_REPORT_IN_TEAM,
    EVENT_START_RADIO_3,
    EVENT_RADIO_AFFIRMATIVE,
    EVENT_RADIO_ENEMY_SPOTTED,
    EVENT_RADIO_NEED_BACKUP,
    EVENT_RADIO_SECTOR_CLEAR,
    EVENT_RADIO_IN_POSITION,
    EVENT_RADIO_REPORTING_IN,
    EVENT_RADIO_GET_OUT_OF_THERE,
    EVENT_RADIO_NEGATIVE,
    EVENT_RADIO_ENEMY_DOWN,
    EVENT_END_RADIO,

    EVENT_NEW_MATCH,                // tell bots the game is new (argumens: 1 = NULL, 2 = NULL)
    EVENT_PLAYER_CHANGED_TEAM,        // tell bots the player is switch his team (also called from ClientPutInServer()) (argumens: 1 = switcher, 2 = NULL)
    EVENT_BULLET_IMPACT,            // tell bots the player is shoot at wall (argumens: 1 = shooter, 2 = shoot trace end position)
    EVENT_GAME_COMMENCE,            // tell bots the game is commencing (argumens: 1 = NULL, 2 = NULL)
    EVENT_WEAPON_ZOOMED,            // tell bots the player is switch weapon zoom (argumens: 1 = zoom switcher, 2 = NULL)
    EVENT_HOSTAGE_CALLED_FOR_HELP,    // tell bots the hostage is talking (argumens: 1 = listener, 2 = NULL)
    NUM_GAME_EVENTS,
};

struct CBotManager_vfptr {
    void (__thiscall* Function1)(struct CBotManager* this);
    void (__thiscall* Function2)(struct CBotManager* this);
    void (__thiscall* Function3)(struct CBotManager* this);
    void (__thiscall* Function4)(struct CBotManager* this);
    void (__thiscall* Function5)(struct CBotManager* this);
    void (__thiscall* Function6)(struct CBotManager* this);
    void (__thiscall* Function7)(struct CBotManager* this);
    void (__thiscall* DestroyAllGrenades)(struct CBotManager* this);
    void (__thiscall* StartFrame)(struct CBotManager* this);
    void (__thiscall* OnEvent)(struct CBotManager* this, GameEventType event, CBaseEntity *pEntity, CBaseEntity *pOther);
    void (__thiscall* Function11)(struct CBotManager* this);
};

struct CBotManager {
    CBotManager_vfptr* vfptr;
    struct list m_activeGrenadeList;
};

enum GameScenarioType
{
    SCENARIO_DEATHMATCH,
    SCENARIO_DEFUSE_BOMB,
    SCENARIO_RESCUE_HOSTAGES,
    SCENARIO_ESCORT_VIP,
};

struct Extent {
    vec3_t lo;
    vec3_t hi;
};

enum { MAX_ZONES = 4 };                        // max # of zones in a map
enum { MAX_ZONE_NAV_AREAS = 16 };            // max # of nav areas in a zone

struct Zone {
    struct CBaseEntity *m_entity;                    // the map entity
    struct CNavArea *m_area[MAX_ZONE_NAV_AREAS];    // nav areas that overlap this zone
    int m_areaCount;
    vec3_t m_center;
    bool m_isLegacy;                        // if true, use pev->origin and 256 unit radius as zone
    int m_index;
    Extent m_extent;
};

enum NavEditCmdType {
    EDIT_NONE,
    EDIT_DELETE,                // delete current area
    EDIT_SPLIT,                    // split current area
    EDIT_MERGE,                    // merge adjacent areas
    EDIT_JOIN,                    // define connection between areas
    EDIT_BREAK,                    // break connection between areas
    EDIT_MARK,                    // mark an area for further operations
    EDIT_ATTRIB_CROUCH,            // toggle crouch attribute on current area
    EDIT_ATTRIB_JUMP,            // toggle jump attribute on current area
    EDIT_ATTRIB_PRECISE,        // toggle precise attribute on current area
    EDIT_ATTRIB_NO_JUMP,        // toggle inhibiting discontinuity jumping in current area
    EDIT_BEGIN_AREA,            // begin creating a new nav area
    EDIT_END_AREA,                // end creation of the new nav area
    EDIT_CONNECT,                // connect marked area to selected area
    EDIT_DISCONNECT,            // disconnect marked area from selected area
    EDIT_SPLICE,                // create new area in between marked and selected areas
    EDIT_TOGGLE_PLACE_MODE,        // switch between normal and place editing
    EDIT_TOGGLE_PLACE_PAINTING,    // switch between "painting" places onto areas
    EDIT_PLACE_FLOODFILL,        // floodfill areas out from current area
    EDIT_PLACE_PICK,            // "pick up" the place at the current area
    EDIT_MARK_UNNAMED,            // mark an unnamed area for further operations
    EDIT_WARP_TO_MARK,            // warp a spectating local player to the selected mark
    EDIT_SELECT_CORNER,            // select a corner on the current area
    EDIT_RAISE_CORNER,            // raise a corner on the current area
    EDIT_LOWER_CORNER,            // lower a corner on the current area
};

struct CountdownTimer {
    float m_duration;
    float m_timestamp;
};

struct CCSBotManager : CBotManager {
    GameScenarioType m_gameScenario;            // what kind of game are we playing

    Zone m_zone[MAX_ZONES];
    int m_zoneCount;

    bool m_isBombPlanted;                        // true if bomb has been planted
    float m_bombPlantTimestamp;                    // time bomb was planted
    float m_earliestBombPlantTimestamp;            // don't allow planting until after this time has elapsed
    struct CBasePlayer *m_bombDefuser;                    // the player currently defusing a bomb
    struct EHANDLE m_looseBomb;                        // will be non-NULL if bomb is loose on the ground
    struct CNavArea *m_looseBombArea;                    // area that bomb is is/near

    bool m_isRoundOver;                            // true if the round has ended

    float m_radioMsgTimestamp[24][2];

    float m_lastSeenEnemyTimestamp;
    float m_roundStartTimestamp;                // the time when the current round began

    bool m_isDefenseRushing;                    // whether defensive team is rushing this round or not

    static NavEditCmdType m_editCmd;
    unsigned int m_navPlace;
    CountdownTimer m_respawnTimer;
    bool m_isRespawnStarted;
    bool m_canRespawn;
    bool m_bServerActive;
};

typedef unsigned int Place;
struct IntervalTimer {
    float m_timestamp;
};
struct PlaceTimeInfo
{
	Place placeID;
	IntervalTimer timer;
};
#define MAX_PLACES_PER_MAP 63

typedef unsigned int PlaceCriteria;
typedef unsigned int CountCriteria;

struct BotPhrase {
    char *m_name;
    Place m_id;
    bool m_isPlace; // true if this is a Place phrase
    GameEventType m_radioEvent;
    bool m_isImportant; // mission-critical statement
    vector m_voiceBank;
    vector m_count;
    vector m_index;
    int m_numVoiceBanks;
    PlaceCriteria m_placeCriteria;
	CountCriteria m_countCriteria;
};

struct BotSpeakable {
	char *m_phrase;
	float m_duration;
	PlaceCriteria m_place;
	CountCriteria m_count;
};

struct BotPhraseManager {
    list m_list;
    list m_placeList;

    PlaceTimeInfo m_placeStatementHistory[MAX_PLACES_PER_MAP];

    int unk2;
    int unk3;
    
    int m_placeCount;
};

enum{ FirstCustomSkin = 100, NumCustomSkins = 100, LastCustomSkin = FirstCustomSkin + NumCustomSkins - 1, };

struct BotProfileManager {
    list m_profileList;
    int u1;
    //int u2;
    //vector m_voiceBanks;

    char *m_skins[NumCustomSkins];
	char *m_skinModelnames[NumCustomSkins];
	char *m_skinFilenames[NumCustomSkins];

	int m_nextSkin;
};
