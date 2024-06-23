struct AuthManager_vtables
{
    void (__thiscall* desctructor)(struct AuthManager* this, int unk);
    void (__thiscall* PacketFunction)(struct AuthManager* this);
};

typedef void(__thiscall*** pfnAuthManager9)(void*, int, int, const wchar_t*, int, int);

typedef struct ServerInfo_s {
    const char* ip;
    unsigned int port;
} ServerInfo;

struct vector_ServerInfo {
    ServerInfo* first;
    ServerInfo* last;
    ServerInfo* end;
};

struct AuthManager
{
    struct AuthManager_vtables* vfptr;
    char unk1; // captcha
    vector_ServerInfo serverinfo;
    char bIsAge18;
    char unk5B;
    char unk6A;
    char unk6B;
    const char* Username;
    const char* Password;
    struct CNMRealUserInfo* ruiUserInfo; // CNMRealUserInfo
    pfnAuthManager9 unk9;
};