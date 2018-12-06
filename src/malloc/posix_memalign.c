#include <stdlib.h>
#include <errno.h>
#include "malloc_impl.h"

#ifdef CONFIG_LKL
#define posix_memalign lkl_unused_posix_memalign
#endif

int posix_memalign(void **res, size_t align, size_t len)
{
	if (align < sizeof(void *)) return EINVAL;
	void *mem = __memalign(align, len);
	if (!mem) return errno;
	*res = mem;
	return 0;
}
