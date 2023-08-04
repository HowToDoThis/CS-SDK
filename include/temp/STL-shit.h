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

union _Bxty_wstring {
    wchar_t buf[8];
    wchar_t* ptr;
    wchar_t alias[8];
};

struct wstring {
    _Bxty_wstring bx;
    unsigned int size;
    unsigned int res;
};