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

struct CSONMWrapper
{
    CSONMWrapper_vtables* vfptr;
    int unk1;
    struct CSONMWrapperEventHandler* eventHandler;
    int unk3; // eventListener
    int unk4; // loginCode?
    int unk5; // gameCode? 126983
    int unk6; // region
    int unk7;
    int unk8;
    int unk9;
    const char* unk10; // userName?
    char unk11;
};