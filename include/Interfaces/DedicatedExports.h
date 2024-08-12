#include "IBaseInterface.h"

class IDedicatedExports : public IBaseInterface {
public:
    virtual void Sys_Printf(const char* text);
};
