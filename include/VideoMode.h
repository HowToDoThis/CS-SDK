struct vmode_t {
    int width;
    int height;
    int bpp;
};

class IVideoMode {
public:
    virtual const char* GetName();

    virtual bool Init(void* pvInstance);
    virtual void Shutdown();

    virtual bool AddMode(int width, int height, int bpp);
    virtual vmode_t* GetCurrentMode();
    virtual vmode_t* GetMode( int num );
    virtual int GetModeCount();

    virtual bool IsWindowedMode();

    virtual bool GetInitialized();
    virtual void SetInitialized(bool init);

    virtual void UpdateWindowPosition();

    virtual void FlipScreen();

    virtual void RestoreVideo();
    virtual void ReleaseVideo();
};

struct bimage_t {
    byte *buffer;
    int x;
    int y;
    int width;
    int height;
    bool scaled;
};

class CUtlMemory_bimage_t {
	bimage_t* m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
};

class CUtlVector_bimage_t {
    CUtlMemory_bimage_t m_Memory;
    int m_Size;
    bimage_t* m_pElements;
};

class CVideoMode_Common : public IVideoMode {
public:
    virtual void Unknown1(int width, int height, int bpp, bool isWindow);
    virtual void Unknown2(int,int,int);
    virtual void Unknown3();
    virtual void LoadStartupGraphic(int a2);
    virtual void PlayStartupVideo(int a2);
    virtual void Unknown4();
    virtual void Unknown5(); // related window mode
    virtual void Unknown6(); // update?
    virtual void VIDEOMODE_ERROR();
    virtual ~CVideoMode_Common();
    virtual int  MaxBitsPerPixel();
    virtual void Minimize();
    virtual void FullScreen();

public:
    vmode_t modeSafe;
    char m_bInitialized;
    CUtlVector_bimage_t m_ImageID;
    int m_iBaseResX;
    int m_iBaseResY;
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