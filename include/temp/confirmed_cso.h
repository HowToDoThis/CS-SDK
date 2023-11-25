typedef enum LanguageCode {
    kr0,
    kr1,
    chn,
    tw,
    jpn,
    sgp,
    idn,
    th,
    tur,
    vn,
};

struct Language
{
    char langName[16];
    unsigned int langCode;
};

struct CRegistry_vfptr {
    void (__thiscall* Init)(struct CRegistry* this);
    void (__thiscall* Shutdown)(struct CRegistry* this);
    int (__thiscall* ReadInt)(struct CRegistry* this, const char *key, int defaultValue = 0);
    void (__thiscall* WriteInt)(struct CRegistry* this, const char *key, int value);
    const char* (__thiscall* ReadString)(struct CRegistry* this, const char *key, const char *defaultValue = NULL);
    void (__thiscall* WriteString)(struct CRegistry* this, const char *key, const char *value);
    void (__thiscall* destructor)(struct CRegistry* this, int);
};

struct CRegistry {
    CRegistry_vfptr* vfptr;
    bool bValid;
    HKEY hKey;
};

typedef struct parms_s {
    char *basedir;
    char *cachedir;
    int argc;
    char **argv;
    void *membase;
    int memsize;
} parms_t;

typedef enum CareerStateType_e {
    CAREER_NONE = 0,
    CAREER_LOADING = 1,
    CAREER_PLAYING = 2,
} CareerStateType;

typedef struct GAME_HEADER_s {
    char mapName[32];
    char comment[80];
    int mapCount;
} GAME_HEADER;