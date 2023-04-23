struct Packet_Hack
{
    void* vfptr;
    struct CPacketBase base;
    int type;
    char unk02; // write something as string
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08; // type 11
    int unk09; // type 11,12 set 0
    int unk10; // type 11,12
    int unk11;
    int unk12;
    int unk13; // type 13 (8b, long long ????)
    int unk14;
    int unk15; // type 13
    int unk16;
    int unk17;
};

struct CHackMgr_tables
{

};

struct CHackMgr
{
    struct CHackMgr_tables* vfptr;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    struct Packet_Hack* packet;
};