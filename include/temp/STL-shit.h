struct vector
{
    int* first;
    int* last;
    int* end;
};

struct pair
{
    int first;
    int second;
};

struct mapNode
{
    pair* left;
    pair* parent;
    pair* right;
    char color;
    char isnil;
    pair myval;
};

struct map
{
    mapNode* head;
    int size;
};

union _Bxty {
    char buf[16];
    char* ptr;
    char alias[16];
};

struct string {
    _Bxty bx;
    unsigned int size;
    unsigned int res;
};