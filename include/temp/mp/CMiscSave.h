// 0xC (12)
class CMiscSave {
public:
    virtual ~CMiscSave();
    virtual void Save();
    virtual void Restore();

public:
    int iTeam;
    int iUserID;
};