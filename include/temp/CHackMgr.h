struct Packet_Hack : Packet
{
    int type;
    string szUnknownString;
    int unk08; // type 11
    int unk09; // type 11, set 0 | type 12, write to vector
    vector vUnknownData; // type 11, initialize
    int unk13; // type 13 (8b, long long ????)
    int unk14;
    vector vUnknownData2;
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