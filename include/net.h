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
	unsigned char ipx[12]; // 16
	unsigned short unk3;   // 18
	unsigned short port;   // 20
} netadr_t;

// NET.h
typedef enum netsrc_s {
	NS_CLIENT = 0,
	NS_SERVER,
	NS_MULTICAST,	// xxxMO
	NS_MAX
} netsrc_t;

#define FRAGMENT_MAX_SIZE 1024
#define MAX_MSGLEN 7990

// 0 == regular, 1 == file stream
enum {
	FRAG_NORMAL_STREAM = 0,
	FRAG_FILE_STREAM,

	MAX_STREAMS
};

// Generic fragment structure
typedef struct fragbuf_s {
	// Next buffer in chain
	fragbuf_s *next;
	// Id of this buffer
	int bufferid;
	// Message buffer where raw data is stored
	sizebuf_t frag_message;
	// The actual data sits here
	byte frag_message_buf[FRAGMENT_MAX_SIZE];
	// Is this a file buffer?
	qboolean isfile;
	// Is this file buffer from memory ( custom decal, etc. ).
	qboolean isbuffer;
	qboolean iscompressed;
	// Name of the file to save out on remote host
	char filename[MAX_PATH];
	// Offset in file from which to read data
	int foffset;
	// Size of data to read at that offset
	int size;
} fragbuf_t;

// Waiting list of fragbuf chains
typedef struct fragbufwaiting_s {
	// Next chain in waiting list
	fragbufwaiting_s *next;
	// Number of buffers in this chain
	int fragbufcount;
	// The actual buffers
	fragbuf_t *fragbufs;
} fragbufwaiting_t;

// Message data
typedef struct flowstats_s {
	// Size of message sent/received
	int size;
	// Time that message was sent/received
	double time;
} flowstats_t;

#define MAX_LATENT 32
typedef struct flow_s {
	// Data for last MAX_LATENT messages
	flowstats_t stats[MAX_LATENT];
	// Current message position
	int current;
	// Time when we should recompute k/sec data
	double nextcompute;
	// Average data
	float kbytespersec;
	float avgkbytespersec;
} flow_t;

enum {
	FLOW_OUTGOING = 0,
	FLOW_INCOMING,

	MAX_FLOWS
};

// Network Connection Channel
// REQUESTED 17904 but only has 17504
typedef struct netchan_s {
	// NS_SERVER or NS_CLIENT, depending on channel.
	netsrc_t sock;

	// Address this channel is talking to.
	netadr_t remote_address;

	int player_slot;
	// For timeouts.  Time last message was received.
	float last_received;
	// Time when channel was connected.
	float connect_time;

	// Bandwidth choke
	// Bytes per second
	double rate;
	// If realtime > cleartime, free to send next packet
	double cleartime;

	// Sequencing variables
	//
	// Increasing count of sequence numbers
	int incoming_sequence;
	// # of last outgoing message that has been ack'd.
	int incoming_acknowledged;
	// Toggles T/F as reliable messages are received.
	int incoming_reliable_acknowledged;
	// single bit, maintained local
	int incoming_reliable_sequence;
	// Message we are sending to remote
	int outgoing_sequence;
	// Whether the message contains reliable payload, single bit
	int reliable_sequence;
	// Outgoing sequence number of last send that had reliable data
	int last_reliable_sequence;

	void *connection_status;
	int (*pfnNetchan_Blocksize)(void *);

	// Staging and holding areas
	sizebuf_t message;
	byte message_buf[MAX_MSGLEN];

	// Reliable message buffer. We keep adding to it until reliable is acknowledged. Then we clear it.
	int reliable_length;
	byte reliable_buf[MAX_MSGLEN];

	// Waiting list of buffered fragments to go onto queue. Multiple outgoing buffers can be queued in succession.
	fragbufwaiting_t *waitlist[MAX_STREAMS];

	// Is reliable waiting buf a fragment?
	int reliable_fragment[MAX_STREAMS];
	// Buffer id for each waiting fragment
	unsigned int reliable_fragid[MAX_STREAMS];

	// The current fragment being set
	fragbuf_t *fragbufs[MAX_STREAMS];
	// The total number of fragments in this stream
	int fragbufcount[MAX_STREAMS];

	// Position in outgoing buffer where frag data starts
	short int frag_startpos[MAX_STREAMS];
	// Length of frag data in the buffer
	short int frag_length[MAX_STREAMS];

	// Incoming fragments are stored here
	fragbuf_t *incomingbufs[MAX_STREAMS];
	// Set to true when incoming data is ready
	qboolean incomingready[MAX_STREAMS];

	// Only referenced by the FRAG_FILE_STREAM component
	// Name of file being downloaded
	char incomingfilename[MAX_PATH];

	void *tempbuffer;
	int tempbuffersize;

	// Incoming and outgoing flow metrics
	flow_t flow[MAX_FLOWS];
} netchan_t;

