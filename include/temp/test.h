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

struct UserStartUnk {
    int unk1;
    string str;
};

struct Dummy30 {
    int u00;
    int u01;
    int u02;
    int u03;
    int u04;
    int u05;
    int u06;
    int u07;
    int u08;
    int u09;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int u23;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
};