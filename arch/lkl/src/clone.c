#include "pthread_impl.h"

void *rumprun_thread_create_withtls(int (*)(void *), void *,
				    void *, int, void *);

int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
{
	void *tid;
	struct pthread *self = arg;

	tid = rumprun_thread_create_withtls(func, arg,
					    (char *)stack - self->stack_size,
					    self->stack_size, self);

	self->unused1 = tid;
	return tid ? 0 : -1;
}
