#define _GNU_SOURCE
#include <unistd.h>
#include <signal.h>
#include "syscall.h"

pid_t vfork(void)
{
	/* vfork syscall cannot be made from C code */
#ifdef SYS_vfork
	return syscall(SYS_vfork);
#else
	return syscall(SYS_clone, SIGCHLD, 0);
#endif
}
