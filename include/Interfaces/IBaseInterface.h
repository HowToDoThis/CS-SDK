class IBaseInterface {
  virtual ~IBaseInterface() {}
};

typedef IBaseInterface *(*CreateInterfaceFn)(const char *pName, int *pReturnCode);