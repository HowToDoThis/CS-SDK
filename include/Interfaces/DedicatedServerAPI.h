struct IDedicatedServerAPI;
struct IDedicatedServerAPI_vtbl
{
  void (__thiscall *~IBaseInterface)(IBaseInterface *this);
  bool (__thiscall *Init)(IDedicatedServerAPI *this, const char *, const char *, IBaseInterface *(__cdecl *)(const char *, int *), IBaseInterface *(__cdecl *)(const char *, int *));
  int (__thiscall *Shutdown)(IDedicatedServerAPI *this);
  bool (__thiscall *RunFrame)(IDedicatedServerAPI *this);
  void (__thiscall *AddConsoleText)(IDedicatedServerAPI *this, char *);
  void (__thiscall *UpdateStatus)(IDedicatedServerAPI *this, float *, int *, int *, char *);
};

struct __cppobj IDedicatedServerAPI : IBaseInterface
{
  IDedicatedServerAPI_vtbl* vtbl;
};

struct CDedicatedServerAPI;
struct /*VFT*/ CDedicatedServerAPI_vtbl
{
  void (__thiscall *~IBaseInterface)(IBaseInterface *this);
  bool (__thiscall *Init)(CDedicatedServerAPI *this, const char *, const char *, IBaseInterface *(__cdecl *)(const char *, int *), IBaseInterface *(__cdecl *)(const char *, int *));
  int (__thiscall *Shutdown)(CDedicatedServerAPI *this);
  bool (__thiscall *RunFrame)(CDedicatedServerAPI *this);
  void (__thiscall *AddConsoleText)(CDedicatedServerAPI *this, char *);
  void (__thiscall *UpdateStatus)(CDedicatedServerAPI *this, float *, int *, int *, char *);
};

struct __cppobj CDedicatedServerAPI : IDedicatedServerAPI
{
  CDedicatedServerAPI_vtbl* vtbl;
  char m_OrigCmd[1024];
};
