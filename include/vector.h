typedef float vec_t;
typedef vec_t vec3_t[3];

class Vector {
	vec_t x, y, z;
};

static_assert(sizeof(Vector) == 12, "vector");