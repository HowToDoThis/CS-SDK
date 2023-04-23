struct CSONMWrapperEventHandler_vtables
{
    void (__thiscall* Function1)(struct CSONMWrapperEventHandler* this);
};

struct CSONMWrapperEventHandler
{
    CSONMWrapper_vtables* vfptr;
    struct CSONMWrapper* wrapper;
};

struct CSONMWrapper_vtables
{
    void (__thiscall* Function1)(struct CSONMWrapper* this);
};

struct CSONMEventListener_vtables
{

};

struct CSONMEventListener
{
    struct CSONMEventListener_vtables* vfptr;
};

struct CSONMWrapper
{
    CSONMWrapper_vtables* vfptr;
    int unk1;
    struct CSONMWrapperEventHandler* eventHandler;
    struct CSONMEventListener* eventListener;
    int unk4; // loginCode?
    int gameCode; // gameCode? 126983, 16850953(0x1012009)
    int unk6; // region
    int unk7;
    int unk8;
    int unk9;
    const char* unk10; // userName?
    char unk11;
    HWND window;
};

// CLoginWrapper
struct CLoginUnk
{
    void* vguiPanel;
    void* vguiLogin;
    HMODULE libVGUI2;
    HMODULE libFileSystem_Nar;
};

struct CCrashUnk
{
    int unk1;
    int unk2;
    int unk3;
    char unk4[0x6400];
    int unk5;
    void* pNext;
};

struct CFriendManager_vtables
{

};

struct CFriendManager
{
    struct CFriendManager_vtables* vfptr;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
};
