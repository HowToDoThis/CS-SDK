struct AuthManager_vtables
{
    void (__thiscall* desctructor)(struct AuthManager* this, int unk);
    void (__thiscall* Function1)(struct AuthManager* this);
};

struct AuthManager
{
    struct AuthManager_vtables* vfptr;
    char unk1;
    int unk2;
    int unk3;
    int unk4;
    char unk5A; // CNMRealUserInfo ret
    char unk5B;
    char unk6A;
    char unk6B;
    const char* unk6; // string?
    const char* unk7; // string
    int unk8; // CNMRealUserInfo
    int unk9;
};