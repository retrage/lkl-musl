#ifndef ERRNO_H
#define ERRNO_H

#include "../../include/errno.h"

hidden int *___errno_location(void);

#ifdef CONFIG_LKL
int *__errno(void);
#define errno (*__errno())
#else  /* !CONFIG_LKL */
int *__errno_location(void);
#undef errno
#define errno (*___errno_location())
#endif	/* CONFIG_LKL */

#endif
