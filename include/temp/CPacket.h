struct CPacket_vtables
{
    void (__thiscall* descructor)(struct CPacket* ptr);
    void (__thiscall* Function1)(struct CPacket* ptr);
    char (__thiscall* Parse)(struct CPacket* ptr, unsigned char* packet, int size);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION1)(struct CPacket* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION2)(struct CPacket* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION3)(struct CPacket* ptr);
    void (__thiscall* FIND_FROM_YOUR_OWN_PACKET_FUNCTION4)(struct CPacket* ptr);
};

struct CPacket
{
    CPacket_vtables* vfptr;
    int unk1;
    struct vector idk;
    int unk5;
};

struct CPacketReader
{
    void* vfptr;
    char* data; // a2
    int curLen;
    int pakLen; // a3
};

struct CPacketListener_vtable
{
};

struct CPacketListener
{
    CPacketListener_vtable* vfptr;
    // idk there is PacketListener stuffs or not
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

struct Packet_HostServer : CPacket
{
    int serverIP;
    int serverPort;
    int hostip;
};