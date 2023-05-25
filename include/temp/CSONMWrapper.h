struct CSONMWrapperEventHandler_vtables
{
    void (__thiscall* OnNMEvent)(struct CSONMWrapperEventHandler* this, struct CNMEvent* pEvent);
    void (__thiscall* Function2)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function3)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function4)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function5)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function6)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function7)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function8)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function9)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function10)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function11)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function12)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function13)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function14)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function15)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function16)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function17)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function18)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function19)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function20)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function21)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function22)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function23)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function24)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function25)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function26)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function27)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function28)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function29)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function30)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function31)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function32)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function33)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function34)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function35)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function36)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function37)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function38)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function39)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function40)(struct CSONMWrapperEventHandler* this);
    void (__thiscall* Function41)(struct CSONMWrapperEventHandler* this);
};

struct CSONMWrapperEventHandler
{
    CSONMWrapperEventHandler_vtables* vfptr;
    struct CSONMWrapper* wrapper;
};

struct CSONMWrapper_vtables
{
    void (__thiscall* Function1)(struct CSONMWrapper* this);
};

struct CSONMEventListener_vtables
{
    void (__thiscall* FindAuthReply)(struct CSONMEventListener* this, NMLoginAuthReplyCode loginCode, int socketError);
    void (__thiscall* Function2)(struct CSONMEventListener* this);
    void (__thiscall* Function3)(struct CSONMEventListener* this);
    void (__thiscall* Function4)(struct CSONMEventListener* this);
    void (__thiscall* Function5)(struct CSONMEventListener* this);
    void (__thiscall* Function6)(struct CSONMEventListener* this);
    void (__thiscall* Function7)(struct CSONMEventListener* this);
    void (__thiscall* Function8)(struct CSONMEventListener* this);
    void (__thiscall* Function9)(struct CSONMEventListener* this);
    void (__thiscall* Function10)(struct CSONMEventListener* this);
    void (__thiscall* Function11)(struct CSONMEventListener* this);
    void (__thiscall* Function12)(struct CSONMEventListener* this);
    void (__thiscall* Function13)(struct CSONMEventListener* this);
    void (__thiscall* Function14)(struct CSONMEventListener* this);
    void (__thiscall* Function15)(struct CSONMEventListener* this);
};

struct CSONMEventListener
{
    CSONMEventListener_vtables* vfptr;
};

struct CSONMWrapper
{
    CSONMWrapper_vtables* vfptr;
    int unk1;
    struct CSONMWrapperEventHandler* eventHandler;
    struct CSONMEventListener* eventListener;
    int unk4; // loginCode?
    NMGameCode gameCode; // gameCode? 126983, 16850953(0x1012009)
    int region;
    int unk7;
    int unk8;
    int unk9;
    const char* unk10; // userName?
    char unk11;
    HWND window;
    int unk12;
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

struct StreamCrypto
{
    struct map map;
    int unk3;
};

struct CStreamCryptor_v0_vt
{
    void (__thiscall* destructor)(struct CStreamCryptor_v0* this);
    void (__thiscall* Function2)(struct CStreamCryptor_v0* this, int a, int b, int c);
    void (__thiscall* Function3)(struct CStreamCryptor_v0* this, int a, int b, int c);
    void (__thiscall* return0)(struct CStreamCryptor_v0* this);
    void (__thiscall* return0x1FCA34)(struct CStreamCryptor_v0* this);
    void (__thiscall* return0x8A119E)(struct CStreamCryptor_v0* this);
    void (__thiscall* returnA)(struct CStreamCryptor_v0* this, int a);
};

struct CStreamCryptor_v0
{
    CStreamCryptor_v0_vt* vfptr;
};

struct CStreamCryptor_v1_vt
{
    void (__thiscall* destructor)(struct CStreamCryptor_v1* this);
    void (__thiscall* Function2)(struct CStreamCryptor_v1* this, int a, int b, int c);
    void (__thiscall* Function3)(struct CStreamCryptor_v1* this, int a, int b, int c);
    void (__thiscall* return1)(struct CStreamCryptor_v1* this);
    void (__thiscall* return0xA98C32A)(struct CStreamCryptor_v1* this);
    void (__thiscall* return0x820A9E12)(struct CStreamCryptor_v1* this);
    void (__thiscall* returnAadd10)(struct CStreamCryptor_v1* this, int a);
};

struct CStreamCryptor_v1
{
    CStreamCryptor_v1_vt* vfptr;
};

struct CNMManager
{
    void* vfptr;
    unsigned char* pRetData;
    CRITICAL_SECTION cs;
    int unk1;
};
