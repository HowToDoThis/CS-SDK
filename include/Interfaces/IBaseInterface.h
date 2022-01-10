// EXTRACT FROM IDA, I think its working ?

struct IBaseInterface;
struct IBaseInterface_vtbl
{
  void (__thiscall *~IBaseInterface)(IBaseInterface *this);
};

struct __cppobj IBaseInterface
{
  IBaseInterface_vtbl* __vftable;
};