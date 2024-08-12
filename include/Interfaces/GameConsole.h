#include "IBaseInterface.h"

class IGameConsole : public IBaseInterface {
public:
    virtual void Activate();
    virtual void Initialize();
    virtual void Hide();
    virtual void Clear();
    virtual void IsConsoleVisible();
    virtual void Printf(const char* format, ...);
    virtual void DPrintf(const char* format, ...);
    virtual void SetParent(struct vgui2::VPANEL* parent);
};

struct CGameConsole : public IGameConsole {
};
