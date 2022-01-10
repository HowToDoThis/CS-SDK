// TIME_T?
typedef __int64 __time64_t;
typedef __time64_t time_t;

// OPENSSL (0.9.8.1 or 0.9.8a)
#include "openssl/ssl.h"
#include "openssl/err.h"

#define MAX_PATH 260

#include "enums.h"

// Shared Interfaces
#include "Interfaces/IBaseInterface.h"
#include "Interfaces/DedicatedServerAPI.h"

// Main Defines / Headers
#include "mathlib.h"

#include "types.h"
#include "bspfile.h"
#include "common.h"
#include "net.h"
#include "studio.h"
#include "model.h"

#include "engine.h"

// CLASSES

// NETADR_T has 28 but Windows defined has 14