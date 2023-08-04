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