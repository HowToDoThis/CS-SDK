struct Packet_MileageBingo
{
    struct CPacket base;
    int unk3;
    int unk4;
};

struct CMileageBingoMgr_vtables
{
    void (__thiscall* desctuctor)(struct CMileageBingoMgr* this);
    void (__thiscall* Func1)(struct CMileageBingoMgr* this);
    void (__thiscall* Func2)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType0)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType1)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType2)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType3)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType4)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType6)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType7_0)(struct CMileageBingoMgr* this);
    void (__thiscall* SendType7_1)(struct CMileageBingoMgr* this);
    void (__thiscall* Func3)(struct CMileageBingoMgr* this);
    void (__thiscall* Func4)(struct CMileageBingoMgr* this);
    void (__thiscall* GetCurrentOpen)(struct CMileageBingoMgr* this);
    void (__thiscall* SetCurrentOpen)(struct CMileageBingoMgr* this, int unk);
    void (__thiscall* GetUnk14)(struct CMileageBingoMgr* this);
    void (__thiscall* GetUnk17)(struct CMileageBingoMgr* this);
    void (__thiscall* GetUnk20)(struct CMileageBingoMgr* this);
    void (__thiscall* GetFinalPrize)(struct CMileageBingoMgr* this);
    void (__thiscall* GetUnk26_1)(struct CMileageBingoMgr* this);
    void (__thiscall* SetUnk26_1)(struct CMileageBingoMgr* this, char unk);
    void (__thiscall* GetSpecialReset)(struct CMileageBingoMgr* this, int unk);
    void (__thiscall* SetSpecialReset)(struct CMileageBingoMgr* this, int unk, int value);
    void (__thiscall* GetMileagePoints)(struct CMileageBingoMgr* this);
    void (__thiscall* SetMileagePoints)(struct CMileageBingoMgr* this, int unk);
    void (__thiscall* GetOpenFee)(struct CMileageBingoMgr* this);
    void (__thiscall* SetOpenFee)(struct CMileageBingoMgr* this, int unk);
    void (__thiscall* GetUnk33)(struct CMileageBingoMgr* this);
    void (__thiscall* SetUnk33)(struct CMileageBingoMgr* this, int unk);
    void (__thiscall* GetUnk34)(struct CMileageBingoMgr* this);
};

struct CMileageBingoMgr
{
    CMileageBingoMgr_vtables* vfptr;
    struct PacketListener* vfptr2;
    struct Packet_MileageBingo packet;

    int unk10;
    int unk11;
    int unk12;
    int iCurrentOpen;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int pFinalPrize;
    int unk24;
    char unk25;
    char unk25b[3];
    short unk26; // send Type0
    int bSpecialReset[2]; // special reset
    int iMileagePoints;
    int iOpenFee;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
};
