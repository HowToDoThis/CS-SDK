struct CGame_vfunc
{
    void  (__thiscall* CGame::desctructor)(struct CGame* this);
    bool  (__thiscall* CGame::Init)(struct CGame* this, void *pvInstance);
    void  (__thiscall* CGame::Function1)(struct CGame* this, int unk);
    void  (__thiscall* CGame::Function2)(struct CGame* this);
	bool  (*CGame::Shutdown)();
    void  (__thiscall* CGame::ShutdownCSO)(struct CGame* this);
	bool  (*CGame::CreateGameWindow)();
	void  (__thiscall* CGame::SleepUntilInput)(struct CGame* this, int time);
	HWND  (*CGame::GetMainWindow)();
	HWND* (*CGame::GetMainWindowAddress)();
	void  (__thiscall* CGame::SetWindowXY)(struct CGame* this, int x, int y);
	void  (__thiscall* CGame::SetWindowSize)(struct CGame* this, int w, int h);
	void  (__thiscall* CGame::GetWindowRect)(struct CGame* this, int *x, int *y, int *w, int *h);
	bool  (*CGame::IsActiveApp)();
	bool  (*CGame::IsMultiplayer)();
	void  (*CGame::PlayStartupVideos)();
	void  (__thiscall* CGame::PlayAVIAndWait)(struct CGame* this, const char *aviFile);
};

struct CGame
{
    CGame_vfunc* vfptr;
    char m_bActiveApp;
    HANDLE handle;
    HWND window;
    HINSTANCE instance;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    short unk5;
    int unk6;
    char unk7;
};