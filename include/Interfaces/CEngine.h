#include "IBaseInterface.h"

class CEngine : public IBaseInterface {
public:
    virtual BOOL Load(BOOL dedicated, char* basedir, char* cmdline);
    virtual void Unload();
    virtual void SetState(int state);
    virtual void GetState();
    virtual void SetSubState();
    virtual void GetSubState();
    virtual void Frame();
    virtual void GetFrameTime();
    virtual void GetCurTime();
    virtual void TrapKey_Event(int key, bool down);
    virtual void TrapMouse_Event();
    virtual void StartTrapMode();
    virtual bool IsTrapping();
    virtual void CheckDoneTrapping();
    virtual int  GetQuitting();
    virtual void SetQuitting(int quitType);

public:
    int m_nQuitting;
    int m_nDLLState;
    int m_nSubState;
    double m_fCurTime;
    double m_fFrameTime;
    double m_fOldTime;
    char m_bTrapMode;
    char m_bDoneTrapping;
    short unk5;
    int m_nTrapKey;
    int m_nTrapButtons;
    int undef3;
};