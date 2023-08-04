struct AuthManager_vtables
{
    void (__thiscall* desctructor)(struct AuthManager* this, int unk);
    void (__thiscall* PacketFunction)(struct AuthManager* this);
};

struct AuthManager
{
    struct AuthManager_vtables* vfptr;
    char unk1; // captcha
    int unk2;
    int unk3;
    int unk4;
    char bIsAge18;
    char unk5B;
    char unk6A;
    char unk6B;
    const char* Username;
    const char* Password;
    struct CNMRealUserInfo* ruiUserInfo; // CNMRealUserInfo
    int unk9;
};