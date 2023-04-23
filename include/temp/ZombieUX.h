struct ZombieUX_tables
{
    void (__thiscall* deconstruct)(struct ZombieUX* this);
    void (__thiscall* SendUpdateInfo7_0A)(struct ZombieUX* this);
    void (__thiscall* SendUpdateInfo7_0B)(struct ZombieUX* this);
    void (__thiscall* null1)(struct ZombieUX* this);
    void (__thiscall* null2)(struct ZombieUX* this);
    void (__thiscall* SendUpdateInfo7_1or2)(struct ZombieUX* this);
    void (__thiscall* SetArray)(struct ZombieUX* this);
};

struct ZombieUX
{
    struct ZombieUX_tables* vfptr;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
};