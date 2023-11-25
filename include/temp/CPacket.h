struct Packet_vtables
{
    void (__thiscall* Function1)(struct Packet* ptr); // unk
    void (__thiscall* dtor)(struct Packet* ptr); // delete
    char (__thiscall* Parse)(struct Packet* ptr, unsigned char* packet, int size);
    void (__thiscall* Function2)(struct Packet* ptr); // mostly null
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION1)(struct Packet* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION2)(struct Packet* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION3)(struct Packet* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION4)(struct Packet* ptr);
};

struct Packet
{
    Packet_vtables* vfptr;
    struct vector idk;
    int unk1;
    int unk2;
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
    void (__thiscall* dtor)(struct PacketListener* ptr); // delete
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