typedef struct hash_item_s {
    struct entvars_t *pev;
    struct hash_item_s *next;
    struct hash_item_s *lastHash;
    int pevIndex;
} hash_item_t;

typedef struct GameToAppIDMapItem_s {
    unsigned int iAppID;
    const char *pGameDir;
} GameToAppIDMapItem_t;

// curl (not confirmed struct, but its like working also? du)
struct cso_curl_data {
    int* first;
    int* last;
    int* end;
};