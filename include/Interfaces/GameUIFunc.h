#include "IBaseInterface.h"

class IGameUIFunc : public IBaseInterface {
public:
    virtual bool        IsKeyDown(const char* keyname, bool& isdown);
    virtual const char* Key_NameForKey(int keynum);
    virtual const char* Key_BindingForKey(int keynum);
    virtual void        GetVGUI2KeyCodeForBind(const char* bind);
    virtual void        GetVideoModes(struct vmode_s** liststart, int* count);
    virtual void        GetCurrentVideoMode(int* wide, int* tall, int* bpp);
    virtual void        GetCurrentRenderer(char* name, int namelen, int* windowed);
    virtual void        IsConnectedToVACSecureServer();
};

struct CGameUIFunc : public IGameUIFunc {
};
