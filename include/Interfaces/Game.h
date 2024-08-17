#include "IBaseInterface.h"

class IGame : public IBaseInterface {
public:
    virtual bool  Init(HINSTANCE hInstance);
    virtual bool  InitCSONMWrapper();
    virtual void  InitCSOCoreSDM();
    virtual bool  ShutdownCSOCoreSDM1();
    virtual void  ShutdownCSOCoreSDM2();
#ifdef CHN240411
    virtual void  ShutdownGameWindow(); // newest
#endif
    virtual bool  CreateGameWindow();
    virtual void  SleepUntilInput(int time);
    virtual HWND  GetMainWindow();
    virtual HWND* GetMainWindowAddress();
    virtual void  SetWindowXY(int x, int y);
    virtual void  SetWindowSize(int w, int h);
    virtual void  GetWindowRect(int *x, int *y, int *w, int *h);
    virtual bool  IsActiveApp();
    virtual bool  IsMultiplayer();
    virtual int   PlayStartupVideos();
    virtual void  PlayAVIAndWait(const char *aviFile);

};

class CGame : public IGame {
public:
    char unk0;
    HANDLE handle;
    HWND window;
    HINSTANCE instance;
    int x;
    int y;
    int width;
    int height;
    bool m_bActiveApp;
    bool m_bMultiplayer;
    int mouseWheelMessage;
    char unk7;
};