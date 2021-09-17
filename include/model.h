// COM_MODELS.h
typedef struct cache_user_s
{
	void	*data;
} cache_user_t;

// MODEL.h

#define MAX_MODEL_NAME		64
#define MIPLEVELS			4
#define MAXLIGHTMAPS		4

typedef enum modtype_e
{
	mod_bad = -1,
	mod_brush,
	mod_sprite,
	mod_alias,
	mod_studio,
} modtype_t;

typedef enum synctype_e
{
	ST_SYNC = 0,
	ST_RAND = 1,
} synctype_t;

typedef struct mplane_s
{
	vec3_t			normal;			// surface normal
	float			dist;			// closest appoach to origin
	byte			type;			// for texture axis selection and fast side tests
	byte			signbits;		// signx + signy<<1 + signz<<1
	byte			pad[2];
} mplane_t;

typedef struct mvertex_s
{
	vec3_t			position;
} mvertex_t;

typedef struct medge_s
{
	unsigned short	v[2];
	unsigned int	cachededgeoffset;
} medge_t;

typedef struct mnode_s
{
	// common with leaf
	int				contgents;		// 0, to differentiate from leafs
	int				visframe;		// node needs to be traversed if current

	short			minmaxs[6];		// for bounding box culling

	struct mnode_s	*parent;

	// node specific
	mplane_t		*plane;
	struct mnode_s	*children[2];

	unsigned short	firstsurface;
	unsigned short	numsurfaces;
} mnode_t;

typedef struct hull_s
{
	dclipnode_t		*clipnodes;
	mplane_t		*planes;
	int				firstclipnode;
	int				lastclipnode;
	vec3_t			clip_mins, clip_maxs;
} hull_t;

typedef struct msurface_s msurface_t;
typedef struct decal_s decal_t;

typedef struct decal_s
{
	decal_t			*pnext;			// linked list for each surface
	msurface_t		*psurface;		// Surface id for persistence / unlinking
	short			dx;				// Offsets into surface texture (in texture coordinates, so we don't need floats)
	short			dy;
	short			texture;		// Decal texture
	byte			scale;			// Pixel scale
	byte			flags;			// Decal flags

	short			entityIndex;	// Entity this is attached to
} decal_t;

typedef struct mtexinfo_s
{
	float			vecs[2][4];		// [s/t] unit vectors in world space.
									// [i][3] is the s/t offset relative to the origin.
									// s or t = dot(3Dpoint,vecs[i])+vecs[i][3]
	float			mipadjust;		// ?? mipmap limits for very small surfaces
	texture_t		*texture;
	int				flags;			// sky or slime, no lightmap or 256 subdivision
} mtexinfo_t;

typedef struct msurface_s
{
	int				visframe;		// should be drawn when node is crossed

	int				dlightframe;	// last frame the surface was checked by an animated light
	int				dlightbits;		// dynamically generated. Indicates if the surface illumination
									// is modified by an animated light.

	mplane_t		*plane;			// pointer to shared plane
	int				flags;			// see SURF_ #defines

	int				firstedge;	// look up in model->surfedges[], negative numbers
	int				numedges;	// are backwards edges

	// surface generation data
	struct surfcache_s *cachespots[MIPLEVELS];

	short			texturemins[2]; // smallest s/t position on the surface.
	short			extents[2];		// ?? s/t texture size, 1..256 for all non-sky surfaces

	mtexinfo_t		*texinfo;

	// lighting info
	byte			styles[MAXLIGHTMAPS];	// index into d_lightstylevalue[] for animated lights
											// no one surface can be effected by more than 4
											// animated lights.
	color24			*samples;

	decal_t			*pdecals;
} msurface_t;

typedef struct texture_s
{
	char			name[16];
	unsigned		width, height;

	int			gl_texturenum;
	struct msurface_s *	texturechain;

	int				anim_total;			// total tenths in sequence ( 0 = no)
	int				anim_min, anim_max;	// time for this frame min <=time< max
	struct texture_s *anim_next;		// in the animation sequence
	struct texture_s *alternate_anims;	// bmodels in frame 1 use these
	unsigned		offsets[MIPLEVELS];	// four mip maps stored

	byte *pPal;
} texture_t;

typedef struct model_s
{
	char			name[MAX_MODEL_NAME];

	int		needload;		// bmodels and sprites don't cache normally

	modtype_t		type;
	int				numframes;
	synctype_t		synctype;

	int				flags;

	//
	// volume occupied by the model
	//
	vec3_t			mins, maxs;
	float			radius;

	//
	// brush model
	//
	int				firstmodelsurface, nummodelsurfaces;

	int				numsubmodels;
	dmodel_t		*submodels;

	int				numplanes;
	mplane_t		*planes;

	int				numleafs;		// number of visible leafs, not counting 0
	struct mleaf_s	*leafs;

	int				numvertexes;
	mvertex_t		*vertexes;

	int				numedges;
	medge_t			*edges;

	int				numnodes;
	mnode_t			*nodes;

	int				numtexinfo;
	mtexinfo_t		*texinfo;

	int				numsurfaces;
	msurface_t		*surfaces;

	int				numsurfedges;
	int				*surfedges;

	int				numclipnodes;
	dclipnode_t		*clipnodes;

	int				nummarksurfaces;
	msurface_t		**marksurfaces;

	hull_t			hulls[MAX_MAP_HULLS];

	int				numtextures;
	texture_t		**textures;

	byte			*visdata;

	color24			*lightdata;

	char			*entities;

	//
	// additional model data
	//
	cache_user_t	cache;			// only access through Mod_Extradata
} model_t;
