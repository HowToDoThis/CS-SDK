#define EVP_MAX_IV_LENGTH		16
#define EVP_MAX_BLOCK_LENGTH	32

#define SHA_DIGEST_LENGTH 20

#define SSL_MAX_SSL_SESSION_ID_LENGTH		32
#define SSL_MAX_SID_CTX_LENGTH			32

#define SSL_MIN_RSA_MODULUS_LENGTH_IN_BYTES	(512/8)
#define SSL_MAX_KEY_ARG_LENGTH			8
#define SSL_MAX_MASTER_KEY_LENGTH		48

#define STACK_OF(type) STACK

typedef struct asn1_string_st ASN1_INTEGER;
typedef struct asn1_string_st ASN1_ENUMERATED;
typedef struct asn1_string_st ASN1_BIT_STRING;
typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct asn1_string_st ASN1_PRINTABLESTRING;
typedef struct asn1_string_st ASN1_T61STRING;
typedef struct asn1_string_st ASN1_IA5STRING;
typedef struct asn1_string_st ASN1_GENERALSTRING;
typedef struct asn1_string_st ASN1_UNIVERSALSTRING;
typedef struct asn1_string_st ASN1_BMPSTRING;
typedef struct asn1_string_st ASN1_UTCTIME;
typedef struct asn1_string_st ASN1_TIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct asn1_string_st ASN1_VISIBLESTRING;
typedef struct asn1_string_st ASN1_UTF8STRING;
typedef int ASN1_BOOLEAN;
typedef int ASN1_NULL;

typedef struct asn1_object_st
{
	const char *sn,*ln;
	int nid;
	int length;
	unsigned char *data;
	int flags;	/* Should we free this one */
} ASN1_OBJECT;

typedef struct asn1_string_st
{
	int length;
	int type;
	unsigned char *data;
	/* The value of the following field depends on the type being
	 * held.  It is mostly being used for BIT_STRING so if the
	 * input data has a non-zero 'unused bits' value, it will be
	 * handled correctly */
	long flags;
} ASN1_STRING;

typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct engine_st ENGINE;
typedef struct evp_pkey_st EVP_PKEY;

typedef struct ASN1_ENCODING_st
{
	unsigned char *enc;	/* DER encoding */
	long len;		/* Length of encoding */
	int modified;		 /* set to 1 if 'enc' is invalid */
} ASN1_ENCODING;

typedef struct asn1_type_st
{
	int type;
	union	{
		char *ptr;
		ASN1_BOOLEAN		boolean;
		ASN1_STRING *		asn1_string;
		ASN1_OBJECT *		object;
		ASN1_INTEGER *		integer;
		ASN1_ENUMERATED *	enumerated;
		ASN1_BIT_STRING *	bit_string;
		ASN1_OCTET_STRING *	octet_string;
		ASN1_PRINTABLESTRING *	printablestring;
		ASN1_T61STRING *	t61string;
		ASN1_IA5STRING *	ia5string;
		ASN1_GENERALSTRING *	generalstring;
		ASN1_BMPSTRING *	bmpstring;
		ASN1_UNIVERSALSTRING *	universalstring;
		ASN1_UTCTIME *		utctime;
		ASN1_GENERALIZEDTIME *	generalizedtime;
		ASN1_VISIBLESTRING *	visiblestring;
		ASN1_UTF8STRING *	utf8string;
		/* set and sequence are left complete and still
		 * contain the set or sequence bytes */
		ASN1_STRING *		set;
		ASN1_STRING *		sequence;
		} value;
} ASN1_TYPE;

typedef struct stack_st
{
	int num;
	char **data;
	int sorted;

	int num_alloc;
	int (*comp)(const char * const *, const char * const *);
} STACK;

struct evp_cipher_st
{
	int nid;
	int block_size;
	int key_len;		/* Default value for variable length ciphers */
	int iv_len;
	unsigned long flags;	/* Various flags */
	int (*init)(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc);	/* init key */
	int (*do_cipher)(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl);/* encrypt/decrypt data */
	int (*cleanup)(EVP_CIPHER_CTX *); /* cleanup ctx */
	int ctx_size;		/* how big ctx->cipher_data needs to be */
	int (*set_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *); /* Populate a ASN1_TYPE with parameters */
	int (*get_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *); /* Get parameters from a ASN1_TYPE */
	int (*ctrl)(EVP_CIPHER_CTX *, int type, int arg, void *ptr); /* Miscellaneous operations */
	void *app_data;		/* Application data */
} /* EVP_CIPHER */;

struct evp_cipher_ctx_st
{
	const EVP_CIPHER *cipher;
	ENGINE *engine;	/* functional reference if 'cipher' is ENGINE-provided */
	int encrypt;		/* encrypt or decrypt */
	int buf_len;		/* number we have left */

	unsigned char  oiv[EVP_MAX_IV_LENGTH];	/* original iv */
	unsigned char  iv[EVP_MAX_IV_LENGTH];	/* working iv */
	unsigned char buf[EVP_MAX_BLOCK_LENGTH];/* saved partial block */
	int num;				/* used by cfb/ofb mode */

	void *app_data;		/* application stuff */
	int key_len;		/* May change for variable length cipher */
	unsigned long flags;	/* Various flags */
	void *cipher_data; /* per EVP data */
	int final_used;
	int block_mask;
	unsigned char final[EVP_MAX_BLOCK_LENGTH];/* possible final block */
} /* EVP_CIPHER_CTX */;

typedef struct evp_cipher_info_st
{
	const EVP_CIPHER *cipher;
	unsigned char iv[EVP_MAX_IV_LENGTH];
} EVP_CIPHER_INFO;

/* a sequence of these are used */
typedef struct x509_attributes_st
{
	ASN1_OBJECT *object;
	int single; /* 0 for a set, 1 for a single item (which is wrong) */
	union	{
		char *ptr;
/* 0 */	STACK_OF(ASN1_TYPE) *set;
/* 1 */	ASN1_TYPE	*single;
		} value;
} X509_ATTRIBUTE;

struct evp_pkey_st
{
	int type;
	int save_type;
	int references;
	union	{
		char *ptr;
		struct rsa_st *rsa;	/* RSA */
		struct dsa_st *dsa;	/* DSA */
		struct dh_st *dh;	/* DH */
		struct ec_key_st *ec;	/* ECC */
		} pkey;
	int save_parameters;
	STACK_OF(X509_ATTRIBUTE) *attributes; /* [ 0 ] */
} /* EVP_PKEY */;

typedef int pem_password_cb(char *buf, int size, int rwflag, void *userdata);

typedef struct x509_st X509;
typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_name_st X509_NAME;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;
typedef struct x509_store_st X509_STORE;
typedef struct x509_store_ctx_st X509_STORE_CTX;
typedef struct X509_crl_st X509_CRL;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;

typedef struct crypto_ex_data_st CRYPTO_EX_DATA;

struct crypto_ex_data_st
{
	STACK *sk;
	int dummy; /* gcc is screwing up this data structure :-( */
};

typedef struct X509_crl_info_st
{
	ASN1_INTEGER *version;
	X509_ALGOR *sig_alg;
	X509_NAME *issuer;
	ASN1_TIME *lastUpdate;
	ASN1_TIME *nextUpdate;
	STACK_OF(X509_REVOKED) *revoked;
	STACK_OF(X509_EXTENSION) /* [0] */ *extensions;
	ASN1_ENCODING enc;
} X509_CRL_INFO;

struct X509_crl_st
{
	/* actual signature */
	X509_CRL_INFO *crl;
	X509_ALGOR *sig_alg;
	ASN1_BIT_STRING *signature;
	int references;
} /* X509_CRL */;

struct X509_algor_st
{
	ASN1_OBJECT *algorithm;
	ASN1_TYPE *parameter;
} /* X509_ALGOR */;

typedef struct X509_name_entry_st
{
	ASN1_OBJECT *object;
	ASN1_STRING *value;
	int set;
	int size; 	/* temp variable */
} X509_NAME_ENTRY;

struct X509_name_st
{
	STACK_OF(X509_NAME_ENTRY) *entries;
	int modified;	/* true if 'bytes' needs to be built */
	char *bytes;
	unsigned long hash; /* Keep the hash around for lookups */
} /* X509_NAME */;

typedef struct X509_val_st
{
	ASN1_TIME *notBefore;
	ASN1_TIME *notAfter;
} X509_VAL;

typedef struct X509_pubkey_st
{
	X509_ALGOR *algor;
	ASN1_BIT_STRING *public_key;
	EVP_PKEY *pkey;
} X509_PUBKEY;

typedef struct x509_cinf_st
{
	ASN1_INTEGER *version;		/* [ 0 ] default of v1 */
	ASN1_INTEGER *serialNumber;
	X509_ALGOR *signature;
	X509_NAME *issuer;
	X509_VAL *validity;
	X509_NAME *subject;
	X509_PUBKEY *key;
	ASN1_BIT_STRING *issuerUID;		/* [ 1 ] optional in v2 */
	ASN1_BIT_STRING *subjectUID;		/* [ 2 ] optional in v2 */
	STACK_OF(X509_EXTENSION) *extensions;	/* [ 3 ] optional in v3 */
} X509_CINF;

typedef struct x509_cert_aux_st
{
	STACK_OF(ASN1_OBJECT) *trust;		/* trusted uses */
	STACK_OF(ASN1_OBJECT) *reject;		/* rejected uses */
	ASN1_UTF8STRING *alias;			/* "friendly name" */
	ASN1_OCTET_STRING *keyid;		/* key id of private key */
	STACK_OF(X509_ALGOR) *other;		/* other unspecified info */
} X509_CERT_AUX;

struct x509_st
{
	X509_CINF *cert_info;
	X509_ALGOR *sig_alg;
	ASN1_BIT_STRING *signature;
	int valid;
	int references;
	char *name;
	CRYPTO_EX_DATA ex_data;
	/* These contain copies of various extension values */
	long ex_pathlen;
	long ex_pcpathlen;
	unsigned long ex_flags;
	unsigned long ex_kusage;
	unsigned long ex_xkusage;
	unsigned long ex_nscert;
	ASN1_OCTET_STRING *skid;
	struct AUTHORITY_KEYID_st *akid;
	X509_POLICY_CACHE *policy_cache;
	unsigned char sha1_hash[SHA_DIGEST_LENGTH];
	X509_CERT_AUX *aux;
} /* X509 */;

typedef struct x509_lookup_st X509_LOOKUP;

typedef struct x509_object_st
{
	/* one of the above types */
	int type;
	union	{
		char *ptr;
		X509 *x509;
		X509_CRL *crl;
		EVP_PKEY *pkey;
		} data;
} X509_OBJECT;

typedef struct x509_lookup_method_st
{
	const char *name;
	int (*new_item)(X509_LOOKUP *ctx);
	void (*free)(X509_LOOKUP *ctx);
	int (*init)(X509_LOOKUP *ctx);
	int (*shutdown)(X509_LOOKUP *ctx);
	int (*ctrl)(X509_LOOKUP *ctx,int cmd,const char *argc,long argl,
			char **ret);
	int (*get_by_subject)(X509_LOOKUP *ctx,int type,X509_NAME *name,
			      X509_OBJECT *ret);
	int (*get_by_issuer_serial)(X509_LOOKUP *ctx,int type,X509_NAME *name,
				    ASN1_INTEGER *serial,X509_OBJECT *ret);
	int (*get_by_fingerprint)(X509_LOOKUP *ctx,int type,
				  unsigned char *bytes,int len,
				  X509_OBJECT *ret);
	int (*get_by_alias)(X509_LOOKUP *ctx,int type,char *str,int len,
			    X509_OBJECT *ret);
} X509_LOOKUP_METHOD;

struct x509_lookup_st
{
	int init;			/* have we been started */
	int skip;			/* don't use us. */
	X509_LOOKUP_METHOD *method;	/* the functions */
	char *method_data;		/* method data */

	X509_STORE *store_ctx;	/* who owns us */
} /* X509_LOOKUP */;

typedef struct private_key_st
{
	int version;
	/* The PKCS#8 data types */
	X509_ALGOR *enc_algor;
	ASN1_OCTET_STRING *enc_pkey;	/* encrypted pub key */

	/* When decrypted, the following will not be NULL */
	EVP_PKEY *dec_pkey;

	/* used to encrypt and decrypt */
	int key_length;
	char *key_data;
	int key_free;	/* true if we should auto free key_data */

	/* expanded version of 'enc_algor' */
	EVP_CIPHER_INFO cipher;

	int references;
} X509_PKEY;

typedef struct X509_info_st
{
	X509 *x509;
	X509_CRL *crl;
	X509_PKEY *x_pkey;

	EVP_CIPHER_INFO enc_cipher;
	int enc_len;
	char *enc_data;

	int references;
} X509_INFO;

typedef struct buf_mem_st BUF_MEM;

struct buf_mem_st
{
	int length;	/* current number of bytes */
	char *data;
	int max;	/* size of buffer */
};

typedef long    __time32_t;
typedef __int64 __time64_t;
typedef __time32_t time_t;
typedef __time64_t time_t;

typedef struct X509_VERIFY_PARAM_st
{
	char *name;
	time_t check_time;	/* Time to use */
	unsigned long inh_flags; /* Inheritance flags */
	unsigned long flags;	/* Various verify flags */
	int purpose;		/* purpose to check untrusted certificates */
	int trust;		/* trust setting to check */
	int depth;		/* Verify depth */
	STACK_OF(ASN1_OBJECT) *policies;	/* Permissible policies */
} X509_VERIFY_PARAM;

struct x509_store_st
{
	/* The following is a cache of trusted certs */
	int cache; 	/* if true, stash any hits */
	STACK_OF(X509_OBJECT) *objs;	/* Cache of all objects */

	/* These are external lookup methods */
	STACK_OF(X509_LOOKUP) *get_cert_methods;

	X509_VERIFY_PARAM *param;

	/* Callbacks for various operations */
	int (*verify)(X509_STORE_CTX *ctx);	/* called to verify a certificate */
	int (*verify_cb)(int ok,X509_STORE_CTX *ctx);	/* error callback */
	int (*get_issuer)(X509 **issuer, X509_STORE_CTX *ctx, X509 *x);	/* get issuers cert from ctx */
	int (*check_issued)(X509_STORE_CTX *ctx, X509 *x, X509 *issuer); /* check issued */
	int (*check_revocation)(X509_STORE_CTX *ctx); /* Check revocation status of chain */
	int (*get_crl)(X509_STORE_CTX *ctx, X509_CRL **crl, X509 *x); /* retrieve CRL */
	int (*check_crl)(X509_STORE_CTX *ctx, X509_CRL *crl); /* Check CRL validity */
	int (*cert_crl)(X509_STORE_CTX *ctx, X509_CRL *crl, X509 *x); /* Check certificate against CRL */
	int (*cleanup)(X509_STORE_CTX *ctx);

	CRYPTO_EX_DATA ex_data;
	int references;
} /* X509_STORE */;

struct x509_store_ctx_st      /* X509_STORE_CTX */
{
	X509_STORE *ctx;
	int current_method;	/* used when looking up certs */

	/* The following are set by the caller */
	X509 *cert;		/* The cert to check */
	STACK_OF(X509) *untrusted;	/* chain of X509s - untrusted - passed in */
	STACK_OF(X509_CRL) *crls;	/* set of CRLs passed in */

	X509_VERIFY_PARAM *param;
	void *other_ctx;	/* Other info for use with get_issuer() */

	/* Callbacks for various operations */
	int (*verify)(X509_STORE_CTX *ctx);	/* called to verify a certificate */
	int (*verify_cb)(int ok,X509_STORE_CTX *ctx);		/* error callback */
	int (*get_issuer)(X509 **issuer, X509_STORE_CTX *ctx, X509 *x);	/* get issuers cert from ctx */
	int (*check_issued)(X509_STORE_CTX *ctx, X509 *x, X509 *issuer); /* check issued */
	int (*check_revocation)(X509_STORE_CTX *ctx); /* Check revocation status of chain */
	int (*get_crl)(X509_STORE_CTX *ctx, X509_CRL **crl, X509 *x); /* retrieve CRL */
	int (*check_crl)(X509_STORE_CTX *ctx, X509_CRL *crl); /* Check CRL validity */
	int (*cert_crl)(X509_STORE_CTX *ctx, X509_CRL *crl, X509 *x); /* Check certificate against CRL */
	int (*check_policy)(X509_STORE_CTX *ctx);
	int (*cleanup)(X509_STORE_CTX *ctx);

	/* The following is built up */
	int valid;		/* if 0, rebuild chain */
	int last_untrusted;	/* index of last untrusted cert */
	STACK_OF(X509) *chain; 		/* chain of X509s - built up and trusted */
	X509_POLICY_TREE *tree;	/* Valid policy tree */

	int explicit_policy;	/* Require explicit policy value */

	/* When something goes wrong, this is why */
	int error_depth;
	int error;
	X509 *current_cert;
	X509 *current_issuer;	/* cert currently being tested as valid issuer */
	X509_CRL *current_crl;	/* current CRL */

	CRYPTO_EX_DATA ex_data;
} /* X509_STORE_CTX */;

typedef struct env_md_st EVP_MD;
typedef struct env_md_ctx_st EVP_MD_CTX;

struct env_md_st
{
	int type;
	int pkey_type;
	int md_size;
	unsigned long flags;
	int (*init)(EVP_MD_CTX *ctx);
	int (*update)(EVP_MD_CTX *ctx,const void *data,size_t count);
	int (*final)(EVP_MD_CTX *ctx,unsigned char *md);
	int (*copy)(EVP_MD_CTX *to,const EVP_MD_CTX *from);
	int (*cleanup)(EVP_MD_CTX *ctx);

	/* FIXME: prototype these some day */
	int (*sign)(int type, const unsigned char *m, unsigned int m_length,
		    unsigned char *sigret, unsigned int *siglen, void *key);
	int (*verify)(int type, const unsigned char *m, unsigned int m_length,
		      const unsigned char *sigbuf, unsigned int siglen,
		      void *key);
	int required_pkey_type[5]; /*EVP_PKEY_xxx */
	int block_size;
	int ctx_size; /* how big does the ctx->md_data need to be */
} /* EVP_MD */;

struct env_md_ctx_st
{
	const EVP_MD *digest;
	ENGINE *engine; /* functional reference if 'digest' is ENGINE-provided */
	unsigned long flags;
	void *md_data;
} /* EVP_MD_CTX */;

typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;

typedef int (*GEN_SESSION_CB)(const SSL *ssl, unsigned char *id, unsigned int *id_len);

typedef struct ssl_cipher_st
{
	int valid;
	const char *name;		/* text name */
	unsigned long id;		/* id, 4 bytes, first is version */
	unsigned long algorithms;	/* what ciphers are used */
	unsigned long algo_strength;	/* strength and export flags */
	unsigned long algorithm2;	/* Extra flags */
	int strength_bits;		/* Number of bits really used */
	int alg_bits;			/* Number of bits for algorithm */
	unsigned long mask;		/* used for matching */
	unsigned long mask_strength;	/* also used for matching */
} SSL_CIPHER;

typedef struct ssl_session_st
{
	int ssl_version;	/* what ssl version session info is
				 * being kept in here? */

	/* only really used in SSLv2 */
	unsigned int key_arg_length;
	unsigned char key_arg[SSL_MAX_KEY_ARG_LENGTH];
	int master_key_length;
	unsigned char master_key[SSL_MAX_MASTER_KEY_LENGTH];
	/* session_id - valid? */
	unsigned int session_id_length;
	unsigned char session_id[SSL_MAX_SSL_SESSION_ID_LENGTH];
	/* this is used to determine whether the session is being reused in
	 * the appropriate context. It is up to the application to set this,
	 * via SSL_new */
	unsigned int sid_ctx_length;
	unsigned char sid_ctx[SSL_MAX_SID_CTX_LENGTH];

	int not_resumable;

	/* The cert is the certificate used to establish this connection */
	struct sess_cert_st /* SESS_CERT */ *sess_cert;

	/* This is the cert for the other end.
	 * On clients, it will be the same as sess_cert->peer_key->x509
	 * (the latter is not enough as sess_cert is not retained
	 * in the external representation of sessions, see ssl_asn1.c). */
	X509 *peer;
	/* when app_verify_callback accepts a session where the peer's certificate
	 * is not ok, we must remember the error for session reuse: */
	long verify_result; /* only for servers */

	int references;
	long timeout;
	long time;

	int compress_meth;		/* Need to lookup the method */

	SSL_CIPHER *cipher;
	unsigned long cipher_id;	/* when ASN.1 loaded, this
					 * needs to be used to load
					 * the 'cipher' structure */

	STACK_OF(SSL_CIPHER) *ciphers; /* shared ciphers? */

	CRYPTO_EX_DATA ex_data; /* application specific data */

	/* These are used to make removal of session-ids more
	 * efficient and to implement a maximum cache size. */
	struct ssl_session_st *prev,*next;
} SSL_SESSION;

/* Used to hold functions for SSLv2 or SSLv3/TLSv1 functions */
typedef struct ssl_method_st
{
	int version;
	int (*ssl_new)(SSL *s);
	void (*ssl_clear)(SSL *s);
	void (*ssl_free)(SSL *s);
	int (*ssl_accept)(SSL *s);
	int (*ssl_connect)(SSL *s);
	int (*ssl_read)(SSL *s,void *buf,int len);
	int (*ssl_peek)(SSL *s,void *buf,int len);
	int (*ssl_write)(SSL *s,const void *buf,int len);
	int (*ssl_shutdown)(SSL *s);
	int (*ssl_renegotiate)(SSL *s);
	int (*ssl_renegotiate_check)(SSL *s);
	long (*ssl_get_message)(SSL *s, int st1, int stn, int mt, long
		max, int *ok);
	int (*ssl_read_bytes)(SSL *s, int type, unsigned char *buf, int len, 
		int peek);
	int (*ssl_write_bytes)(SSL *s, int type, const void *buf_, int len);
	int (*ssl_dispatch_alert)(SSL *s);
	long (*ssl_ctrl)(SSL *s,int cmd,long larg,void *parg);
	long (*ssl_ctx_ctrl)(SSL_CTX *ctx,int cmd,long larg,void *parg);
	SSL_CIPHER *(*get_cipher_by_char)(const unsigned char *ptr);
	int (*put_cipher_by_char)(const SSL_CIPHER *cipher,unsigned char *ptr);
	int (*ssl_pending)(const SSL *s);
	int (*num_ciphers)(void);
	SSL_CIPHER *(*get_cipher)(unsigned ncipher);
	struct ssl_method_st *(*get_ssl_method)(int version);
	long (*get_timeout)(void);
	struct ssl3_enc_method *ssl3_enc; /* Extra SSLv3/TLS stuff */
	int (*ssl_version)(void);
	long (*ssl_callback_ctrl)(SSL *s, int cb_id, void (*fp)(void));
	long (*ssl_ctx_callback_ctrl)(SSL_CTX *s, int cb_id, void (*fp)(void));
} SSL_METHOD;

struct ssl_st
{
	/* protocol version
	 * (one of SSL2_VERSION, SSL3_VERSION, TLS1_VERSION, DTLS1_VERSION)
	 */
	int version;
	int type; /* SSL_ST_CONNECT or SSL_ST_ACCEPT */

	SSL_METHOD *method; /* SSLv3 */

	/* There are 2 BIO's even though they are normally both the
	 * same.  This is so data can be read and written to different
	 * handlers */

	char *rbio; /* used by SSL_read */
	char *wbio; /* used by SSL_write */
	char *bbio;
	/* This holds a variable that indicates what we were doing
	 * when a 0 or -1 is returned.  This is needed for
	 * non-blocking IO so we know what request needs re-doing when
	 * in SSL_accept or SSL_connect */
	int rwstate;

	/* true when we are actually in SSL_accept() or SSL_connect() */
	int in_handshake;
	int (*handshake_func)(SSL *);

	/* Imagine that here's a boolean member "init" that is
	 * switched as soon as SSL_set_{accept/connect}_state
	 * is called for the first time, so that "state" and
	 * "handshake_func" are properly initialized.  But as
	 * handshake_func is == 0 until then, we use this
	 * test instead of an "init" member.
	 */

	int server;	/* are we the server side? - mostly used by SSL_clear*/

	int new_session;/* 1 if we are to use a new session.
	                 * 2 if we are a server and are inside a handshake
	                 *   (i.e. not just sending a HelloRequest)
	                 * NB: For servers, the 'new' session may actually be a previously
	                 * cached session or even the previous session unless
	                 * SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION is set */
	int quiet_shutdown;/* don't send shutdown packets */
	int shutdown;	/* we have shut things down, 0x01 sent, 0x02
			 * for received */
	int state;	/* where we are */
	int rstate;	/* where we are when reading */

	BUF_MEM *init_buf;	/* buffer used during init */
	void *init_msg;   	/* pointer to handshake message body, set by ssl3_get_message() */
	int init_num;		/* amount read/written */
	int init_off;		/* amount read/written */

	/* used internally to point at a raw packet */
	unsigned char *packet;
	unsigned int packet_length;

	struct ssl2_state_st *s2; /* SSLv2 variables */
	struct ssl3_state_st *s3; /* SSLv3 variables */
	struct dtls1_state_st *d1; /* DTLSv1 variables */

	int read_ahead;		/* Read as many input bytes as possible
	               	 	 * (for non-blocking reads) */

	/* callback that allows applications to peek at protocol messages */
	void (*msg_callback)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg);
	void *msg_callback_arg;

	int hit;		/* reusing a previous session */

	X509_VERIFY_PARAM *param;

#if 0
	int purpose;		/* Purpose setting */
	int trust;		/* Trust setting */
#endif

	/* crypto */
	STACK_OF(SSL_CIPHER) *cipher_list;
	STACK_OF(SSL_CIPHER) *cipher_list_by_id;

	/* These are the ones being used, the ones in SSL_SESSION are
	 * the ones to be 'copied' into these ones */

	EVP_CIPHER_CTX *enc_read_ctx;		/* cryptographic state */
	const EVP_MD *read_hash;		/* used for mac generation */
	char *expand;

	EVP_CIPHER_CTX *enc_write_ctx;		/* cryptographic state */
	const EVP_MD *write_hash;		/* used for mac generation */
	char *compress;	

	/* session info */

	/* client cert? */
	/* This is used to hold the server certificate used */
	struct cert_st /* CERT */ *cert;

	/* the session_id_context is used to ensure sessions are only reused
	 * in the appropriate context */
	unsigned int sid_ctx_length;
	unsigned char sid_ctx[SSL_MAX_SID_CTX_LENGTH];

	/* This can also be in the session once a session is established */
	SSL_SESSION *session;

	/* Default generate session ID callback. */
	GEN_SESSION_CB generate_session_id;

	/* Used in SSL2 and SSL3 */
	int verify_mode;	/* 0 don't care about verify failure.
				 * 1 fail if verify fails */
	int (*verify_callback)(int ok, X509_STORE_CTX *ctx); /* fail if callback returns 0 */

	void (*info_callback)(const SSL *ssl,int type,int val); /* optional informational callback */

	int error;		/* error bytes to be written */
	int error_code;		/* actual code */

	SSL_CTX *ctx;
	/* set this flag to 1 and a sleep(1) is put into all SSL_read()
	 * and SSL_write() calls, good for nbio debuging :-) */
	int debug;	

	/* extra application data */
	long verify_result;
	CRYPTO_EX_DATA ex_data;

	/* for server side, keep the list of CA_dn we can use */
	STACK_OF(X509_NAME) *client_CA;

	int references;
	unsigned long options; /* protocol behaviour */
	unsigned long mode; /* API behaviour */
	long max_cert_list;
	int first_packet;
	int client_version;	/* what was passed, used for
				 * SSLv3/TLS rollback check */
};

struct ssl_ctx_st
{
	SSL_METHOD *method;

	STACK_OF(SSL_CIPHER) *cipher_list;
	/* same as above but sorted for lookup */
	STACK_OF(SSL_CIPHER) *cipher_list_by_id;

	struct x509_store_st /* X509_STORE */ *cert_store;
	struct lhash_st /* LHASH */ *sessions;	/* a set of SSL_SESSIONs */
	/* Most session-ids that will be cached, default is
	 * SSL_SESSION_CACHE_MAX_SIZE_DEFAULT. 0 is unlimited. */
	unsigned long session_cache_size;
	struct ssl_session_st *session_cache_head;
	struct ssl_session_st *session_cache_tail;

	/* This can have one of 2 values, ored together,
	 * SSL_SESS_CACHE_CLIENT,
	 * SSL_SESS_CACHE_SERVER,
	 * Default is SSL_SESSION_CACHE_SERVER, which means only
	 * SSL_accept which cache SSL_SESSIONS. */
	int session_cache_mode;

	/* If timeout is not 0, it is the default timeout value set
	 * when SSL_new() is called.  This has been put in to make
	 * life easier to set things up */
	long session_timeout;

	/* If this callback is not null, it will be called each
	 * time a session id is added to the cache.  If this function
	 * returns 1, it means that the callback will do a
	 * SSL_SESSION_free() when it has finished using it.  Otherwise,
	 * on 0, it means the callback has finished with it.
	 * If remove_session_cb is not null, it will be called when
	 * a session-id is removed from the cache.  After the call,
	 * OpenSSL will SSL_SESSION_free() it. */
	int (*new_session_cb)(struct ssl_st *ssl,SSL_SESSION *sess);
	void (*remove_session_cb)(struct ssl_ctx_st *ctx,SSL_SESSION *sess);
	SSL_SESSION *(*get_session_cb)(struct ssl_st *ssl,
		unsigned char *data,int len,int *copy);

	struct
		{
		int sess_connect;	/* SSL new conn - started */
		int sess_connect_renegotiate;/* SSL reneg - requested */
		int sess_connect_good;	/* SSL new conne/reneg - finished */
		int sess_accept;	/* SSL new accept - started */
		int sess_accept_renegotiate;/* SSL reneg - requested */
		int sess_accept_good;	/* SSL accept/reneg - finished */
		int sess_miss;		/* session lookup misses  */
		int sess_timeout;	/* reuse attempt on timeouted session */
		int sess_cache_full;	/* session removed due to full cache */
		int sess_hit;		/* session reuse actually done */
		int sess_cb_hit;	/* session-id that was not
					 * in the cache was
					 * passed back via the callback.  This
					 * indicates that the application is
					 * supplying session-id's from other
					 * processes - spooky :-) */
		} stats;

	int references;

	/* if defined, these override the X509_verify_cert() calls */
	int (*app_verify_callback)(X509_STORE_CTX *, void *);
	void *app_verify_arg;
	/* before OpenSSL 0.9.7, 'app_verify_arg' was ignored
	 * ('app_verify_callback' was called with just one argument) */

	/* Default password callback. */
	pem_password_cb *default_passwd_callback;

	/* Default password callback user data. */
	void *default_passwd_callback_userdata;

	/* get client cert callback */
	int (*client_cert_cb)(SSL *ssl, X509 **x509, EVP_PKEY **pkey);

    /* cookie generate callback */
    int (*app_gen_cookie_cb)(SSL *ssl, unsigned char *cookie, 
        unsigned int *cookie_len);

    /* verify cookie callback */
    int (*app_verify_cookie_cb)(SSL *ssl, unsigned char *cookie, 
        unsigned int cookie_len);

	CRYPTO_EX_DATA ex_data;

	const EVP_MD *rsa_md5;/* For SSLv2 - name is 'ssl2-md5' */
	const EVP_MD *md5;	/* For SSLv3/TLSv1 'ssl3-md5' */
	const EVP_MD *sha1;   /* For SSLv3/TLSv1 'ssl3->sha1' */

	STACK_OF(X509) *extra_certs;
	STACK_OF(SSL_COMP) *comp_methods; /* stack of SSL_COMP, SSLv3/TLSv1 */


	/* Default values used when no per-SSL value is defined follow */

	void (*info_callback)(const SSL *ssl,int type,int val); /* used if SSL's info_callback is NULL */

	/* what we put in client cert requests */
	STACK_OF(X509_NAME) *client_CA;


	/* Default values to use in SSL structures follow (these are copied by SSL_new) */

	unsigned long options;
	unsigned long mode;
	long max_cert_list;

	struct cert_st /* CERT */ *cert;
	int read_ahead;

	/* callback that allows applications to peek at protocol messages */
	void (*msg_callback)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg);
	void *msg_callback_arg;

	int verify_mode;
	unsigned int sid_ctx_length;
	unsigned char sid_ctx[SSL_MAX_SID_CTX_LENGTH];
	int (*default_verify_callback)(int ok,X509_STORE_CTX *ctx); /* called 'verify_callback' in the SSL */

	/* Default generate session ID callback. */
	GEN_SESSION_CB generate_session_id;

	X509_VERIFY_PARAM *param;

	int quiet_shutdown;
};
