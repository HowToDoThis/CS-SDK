typedef struct hash_item_s
{
	struct entvars_t *pev;
	struct hash_item_s *next;
	struct hash_item_s *lastHash;
	int pevIndex;
} hash_item_t;