#include "IBaseInterface.h"

typedef unsigned long HScheme;
typedef unsigned long HTexture;
typedef unsigned long HFont;

class Color {
private:
    unsigned char _color[4];
};

class IScheme : public IBaseInterface {
public:
    virtual const char* GetResourceString(const char* stringName);
    virtual void*       GetBorder(const char* borderName);
    virtual HFont       GetFont(const char* fontName, bool proportional);
    virtual Color       GetColor(const char* colorName, Color defaultColor);
};

class IImage;
class ISchemeManager : public IBaseInterface {
public:
    virtual HScheme  LoadSchemeFromFile(const char*, const char*);
    virtual void     ReloadSchemes();
    virtual HScheme  GetDefaultScheme();
    virtual HScheme  GetScheme(const char*);
    virtual IImage*  GetImage(const char*, bool, bool);
    virtual HTexture GetImageID(const char*, bool);
    virtual IScheme* GetIScheme(HScheme);
    virtual void     Shutdown(bool);
    virtual int      GetProportionalScaledValue(int);
    virtual int      GetProportionalNormalizedValue(int);
    virtual int      Func01(int);
};

struct CUtlMemory {
    void* vfptr;
    CUtlMemory* m_pMemory;
    int m_nAllocationCount;
    int m_nGrowSize;
};

struct CUtlVector {
    void* vfptr;
    CUtlMemory* m_memory;
    int m_Size;
    CUtlVector *m_pElements;
};

class CSchemeManager : ISchemeManager {
public:
    CUtlVector m_Scheme;
};