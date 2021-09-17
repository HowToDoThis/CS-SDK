#define MAX_MAP_HULLS 4

typedef struct lump_s
{
	int				fileofs;
	int				filelen;
} lump_t;

typedef struct dmodel_s
{
	float			mins[3], maxs[3];
	float			origin[3];
	int				headnode[MAX_MAP_HULLS];
	int				visleafs;		// not including the solid leaf 0
	int				firstface, numfaces;
} dmodel_t;

typedef struct dheader_s
{
	int				version;
	lump_t			lumps[15];
} dheader_t;

typedef struct dmiptexlump_s
{
	int				_nummiptex;
	int				dataofs[4];
} dmiptexlump_t;

typedef struct miptex_s
{
	char			name[16];
	unsigned		width;
	unsigned		height;
	unsigned		offsets[4];
} miptex_t;

typedef struct dvertex_s
{
	float			point[3];
} dvertex_t;

typedef struct dplane_s
{
	float			normal[3];
	float			dist;
	int				type;
} dplane_t;

typedef struct dnode_s
{
	int				planenum;
	short			children[2];
	short			mins[3];
	short			maxs[3];
	unsigned short	firstface;
	unsigned short	numfaces;
} dnode_t;

typedef struct dclipnode_s
{
	int				planenum;
	short			children[2];	// negative numbers are contents
} dclipnode_t;

typedef struct texinfo_s
{
	float			vecs[2][4];
	int				_miptex;
	int				flags;
} texinfo_t;

typedef struct dedge_s
{
	unsigned short	v[2];
} dedge_t;

typedef struct dface_s
{
	short			planenum;
	short			side;
	int				firstedge;
	short			numedges;
	short			texinfo;
	byte			styles[4];
	int				lightofs;
} dface_t;

typedef struct dleaf_s
{
	int				contents;
	int				visofs;
	short			mins[3];
	short			maxs[3];
	unsigned short	firstmarksurface;
	unsigned short	nummarksurfaces;
	byte			ambient_level[4];
} dleaf_t;
