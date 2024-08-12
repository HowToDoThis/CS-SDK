#include "IBaseInterface.h"

#include "../eiface.h"

class IBaseUI : public IBaseInterface
{
public:
    virtual void Initialize(CreateInterfaceFn* factories, int count);
    virtual void Start(cl_enginefunc_t* engineFuncs, int interfaceVersion);
    virtual void Shutdown();
    virtual int  Key_Event(int down, int keynum, const char* pszCurrentBinding);
    virtual void CallEngineSurfaceAppHandler(void* pEvent, void* pUserData);
    virtual void Paint(int x, int y, int right, int bottom);
    virtual void HideGameUI();
    virtual void ActivateGameUI();
    virtual void HideConsole();
    virtual void ShowConsole();
};

class CBaseUI : public IBaseUI {
public:
    CreateInterfaceFn mFactoryList[6];
    int iNumFactories;

    HMODULE* m_hGameUIModule;
    bool m_bHidingGameUI;
};
