#include "libc.h"

#ifdef __APPLE__
struct __libc __libc = {0};
#else
struct __libc __libc;
#endif

size_t __hwcap;
size_t __sysinfo;
#if !defined(CONFIG_LKL) || defined (RUMPRUN)
char *__progname=0;
weak_alias(__progname, program_invocation_short_name);
#endif /* !CONFIG_LKL || RUMPRUN */

char *__progname_full=0;
weak_alias(__progname_full, program_invocation_name);
