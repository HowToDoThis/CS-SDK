struct CPacket_vtables
{
    void (__thiscall* Function1)(struct Packet* ptr); // unk
    void (__thiscall* destcructor)(struct Packet* ptr); // delete
    char (__thiscall* Parse)(struct Packet* ptr, unsigned char* packet, int size);
    void (__thiscall* Function2)(struct Packet* ptr); // mostly null
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION1)(struct Packet* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION2)(struct Packet* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION3)(struct Packet* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION4)(struct Packet* ptr);
};

struct Packet
{
    CPacket_vtables* vfptr;
    int unk1;
    struct vector idk;
    int unk5;
};

struct PacketReader
{
    void* vfptr; // 0 = destructor
    char* data; // a2
    int curLen;
    int pakLen; // a3
};

struct PacketListener_vtable
{
    void (__thiscall* destcructor)(struct PacketListener* ptr); // delete
    char (__thiscall* Parse)(struct PacketListener* ptr, struct Packet* packet);
};

struct PacketListener
{
    PacketListener_vtable* vfptr;
};

struct CPacketSendInternal
{
    int size;
    int unk2;
    int unk3;
};

struct CPacketSend
{
    struct CPacketSendInternal* base;
};

struct Packet_HostServer : Packet
{
    int serverIP;
    int serverPort;
    int hostip;
};