class Packet
{
public:
    virtual wchar_t* Unknown1();
    virtual ~Packet();
    virtual bool Parse(unsigned char* buf, int bufLen);
    virtual void Unknown2(); // lots of null...

    // others shits
    virtual void PACKETFUNC1();
    virtual void PACKETFUNC2();
    virtual void PACKETFUNC3();
    virtual void PACKETFUNC4();
    virtual void PACKETFUNC5();

public:
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
};

struct PacketReader
{
    void* vfptr; // 0 = destructor
    char* data; // a2
    int curLen;
    int pakLen; // a3
};

class PacketListener
{
public:
    virtual ~PacketListener();
    virtual bool Parse(PacketListener, Packet*);

public:
};

struct PacketFinder {
    PacketFinder* next;
    PacketFinder* prev;
    void* parser;
};

struct Packet_HostServer : Packet
{
    int serverIP;
    int serverPort;
    int hostip;
};

class Buffer {
public:
    int size;
    int unk2;
    int unk3;
};