#include <lkl/autoconf.h>
#if defined(LKL_CONFIG_64BIT) && !defined(CONFIG_64BIT)
#define CONFIG_64BIT
#endif

#include <asm/bitsperlong.h>
#include <asm/stat.h>
