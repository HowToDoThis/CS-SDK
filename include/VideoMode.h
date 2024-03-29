struct CVideoMode_Common_vt
{
    const char* (__thiscall* GetVideoModeString)(struct CVideoMode_Common* this);
    bool (__thiscall* Init)(struct CVideoMode_Common* this, void* pvInstance);
    void (__thiscall* Shutdown)(struct CVideoMode_Common* this);
    void (__thiscall* AddMode)(struct CVideoMode_Common* this, int width, int height, int bit);
    vmode_t* (__thiscall* GetCurrentMode)(struct CVideoMode_Common* this);
    vmode_t* (__thiscall* GetMode)(struct CVideoMode_Common* this, int num);
    void (__thiscall* GetModeCount)(struct CVideoMode_Common* this);
    bool (__thiscall* IsWindowedMode)(struct CVideoMode_Common* this);
    bool (__thiscall* GetInitialized)(struct CVideoMode_Common* this);
    void (__thiscall* SetInitialized)(struct CVideoMode_Common* this, bool);
    void (__thiscall* UpdateWindowPosition)(struct CVideoMode_Common* this);
    void (__thiscall* FlipScreen)(struct CVideoMode_Common* this);
    void (__thiscall* RestoreVideo)(struct CVideoMode_Common* this);
    void (__thiscall* ReleaseVideo)(struct CVideoMode_Common* this);
    void (__thiscall* Function15)(struct CVideoMode_Common* this);
    void (__thiscall* Function16)(struct CVideoMode_Common* this);
    void (__thiscall* Function17)(struct CVideoMode_Common* this);
    void (__thiscall* BackgroundSomething)(struct CVideoMode_Common* this, int unk);
    void (__thiscall* PlayStartupVideo)(struct CVideoMode_Common* this, int unk);
    void (__thiscall* NULLFUNC3)(struct CVideoMode_Common* this);
    void (__thiscall* NULLFUNC4)(struct CVideoMode_Common* this); // related window mode
    void (__thiscall* NULLFUNC5)(struct CVideoMode_Common* this);
    void (__thiscall* VIDEOMODE_ERROR)(struct CVideoMode_Common* this);
    void (__thiscall* destruction)(struct CVideoMode_Common* this);
    int  (__thiscall* MaxBitsPerPixel)(struct CVideoMode_Common* this);
    void (__thiscall* NULLFUNC1)(struct CVideoMode_Common* this);
    void (__thiscall* NULLFUNC2)(struct CVideoMode_Common* this);
};

struct vmode_t
{
    int width; // 24 * unk2
    int height; // a3
    int bpp; // a2
};

// same as OpenGL, CSO
struct CVideoMode_Common
{
    CVideoMode_Common_vt* vfptr;
    vmode_t modeSafe;
    char m_bInitialized;
    vmode_t unkStuff;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    char m_bWindowed;
    vmode_t modes[32];
    int m_nNumModes;
    int m_nGameMode;
    int unk15;
};

struct CLauncherDirectDraw_vfptr {
    void (__thiscall* destructor)(struct CLauncherDirectDraw* this);
    bool (*Create)(); //bool (__thiscall* Create)(struct CLauncherDirectDraw* this);
    bool (__thiscall* Release)(struct CLauncherDirectDraw* this);
    HRESULT (__thiscall* EnumeratesDisplayMode)(struct CLauncherDirectDraw* this, int* unkStruct);
    const char* (__thiscall* GetErrorString)(struct CLauncherDirectDraw* this, HRESULT ddRetVal);
};

struct CLauncherDirectDraw {
    CLauncherDirectDraw_vfptr* vfptr;
    LPDIRECTDRAW lpDD;
};