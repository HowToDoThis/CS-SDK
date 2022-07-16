struct CRoomSetting
{
    int status;
	const char* roomName;
	char unka3;
	int unka4;
	char unka5;
	int unka6;
	int unka7;
    char unk00;
    char unk01;
    char unk02;
    char unk03;
	int unk04;
    char maxPlayer;
    char unka01;
    char unka02;
    char unka03;

	const char* password;
	int unkb2;
	short unkb3;
    char unkb3a;
    char unkb3b;
	short unkb4;
    char unkb4a;
    char unkb4b;
	short unkb5;
    char unkb5a;
    char unkb5b;
	int unkb6;
    char killDeathRules;
    char unkb7b;
    char unkb7c;
    char unkb7d;
	int unkb8;
    char levelLimit;
    char unk07;
    char gameMode;
    char mapID;
	int unkb10;

    char winLimit;
    char unkc01;
    char unkc02;
    char unkc03;
	int killsToWin;
	char gameTime;
	float roundTime;
	char unk57;
	int bannedZB; // bannedZB
	int unkc7;
    short unkc8;
    char unkc8a; // why ??? 256?
    char unkc8b;

	char wpnRestricts;
    char hostageKillLimit;
    char freezeTime;
    float buyTime;
    char displayName;
    char teamBalance;
    char unk21;
    char friendlyFire;
    char flashlight;
    char footsteps;
    char unk25;
    char unk26;
    char unk27;
    char unk28;
    char unk29;
    char unk30;
    char voiceChat;
    char unkB0;
    short startMoney;
    char movingShot;
    char unk46;
    
    char randomMap;
    char mapPoolCount;
    int* mapPool;

    int unkB3;
    int unk1;
    short unk2;
    short unk3;
    int unkC[3];
    int unk4;
    int unk5;
    short unk5A;
    char unkd1;
    char unkd2;
    char unk50;
    char roomStatus;
    char wpnEnhanceLimit;
    char isSoySD;
    // 0x2000
    char zbsDifficulty;
    int unkd01;
    int unkd02;

    char unkb27;
    char leagueRule;
    char mannerLimit;
    char unkb30;

    int unk7;
    short unk7A;
    int unkE[3];
    int unk8;
    int unk9;
    short unk9A;
    int unkF[3];
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;

    int fuck[13];
};

struct CRoom
{
    int unk;
    short unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    short unk7;
    char unk7B;
    int unk8;
    int unk9;
    short unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15; // 7

    int unkA1;
    int unkA2;

    CRoomSetting setting; // some stuff

    int unk16;
    short unk17;

    int unkC[3];
    int unkC1;
    int unkC2;
    short unk18;
    char unk19;

    int unk20;
    int unk21;
    int unk22;
    int unk23;
};

struct CGameRoomManager
{
    void* vfptr;

    int unk1; // array?
    int unk2;
    int unk3;

    int unk4;
    char unk5a;
    char unk5b;
    int unk6;
    short unk7;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    int unk12;
    short unk13;
    char unk13a;
    char unk13b;

    int unk14; // array?
    int unk15;
    int unk16;

    int unk17;
    int unk18;
    int unk19;
    int unk20;
};

struct CGameRoom
{
    void* vfptr;
    int unk01;
    char* roomName;
    int maxLevel;
    int unk04;
    char* password;
    int unk06;
    int unk07;
    int maxPlayers;
    int gameMode;
    int mapID;
    int unk11;
    int unk12;
    short unk13;
    int unk14;
    short unk15;
    char unk15a;
    char clanMatch; // bool
    char banList; // bool
    char quickStart; // bool
    char unk18;
    char unk19a;
    char overDeath; // bool
    char unk19aa;
    char unk19ab;
    int winLimit;
    int killLimit;
    int timeLimit;
    int roundTime;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int clanMatchMode;
    int startingCash;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37; // 128?? or longlong
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42; // 128?? or long long
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int difficulty;
    int unk51;
    int unk52;
    int unk53;
    int unk54; // QWORD
    int unk55;
    int unk56;
    int unk57;
};