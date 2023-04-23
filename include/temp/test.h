// NETADR.h
typedef enum {
    NA_UNUSED,
    NA_LOOPBACK,
    NA_BROADCAST,
    NA_IP,
    NA_IPX,
    NA_BROADCAST_IPX,
} netadrtype_t;

typedef struct netadr_s {
    netadrtype_t type;     // 4
    unsigned char ipx[14]; // 16
    //unsigned short unk3;   // 18
    unsigned short port;   // 20
    int localIP;
    int unk5;
} netadr_t;

struct Dummy10
{
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
};