struct Packet_MiniGame : Packet {
    int type;
    int unk1;
};

struct CMiniGameMgr {
    void* vfptr1;
    void* vfptr2;

    Packet_MiniGame packet;

    int unk1;
    int unk2;
};