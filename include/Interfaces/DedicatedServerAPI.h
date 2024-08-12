#include "IBaseInterface.h"

class IDedicatedServerAPI : public IBaseInterface {
public:
    virtual bool Init(const char *, const char *, IBaseInterface *(__cdecl *)(const char *, int *), IBaseInterface *(__cdecl *)(const char *, int *));
    virtual int Shutdown();
    virtual bool RunFrame();
    virtual void AddConsoleText(char *);
    virtual void UpdateStatus(float *, int *, int *, char *);
};

class CDedicatedServerAPI : public IDedicatedServerAPI {
public:
    char m_OrigCmd[1024];
};