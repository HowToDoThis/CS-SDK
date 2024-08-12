struct vector {
    int* first;
    int* last;
    int* end;
};

struct vector_string {
    int* first;
    int* last;
    int* end;
};

struct pair {
    int first;
    int second;
};

struct mapNode {
    pair* _Left;
    pair* _Parent;
    pair* _Right;
    char _Color;
    char _Isnil;
    pair _Myval;
};

// 0x18
struct map {
    mapNode* _Myhead;
    unsigned int _Mysize;
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

struct vector_string {
    string* first;
    string* last;
    string* end;
};

struct list_node_base {
    list_node_base* _next;
    list_node_base* _prev;
    int _val;
};

struct list {
    list_node_base* _head;
    unsigned int _size;
};