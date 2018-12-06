#ifndef FEATURES_H
#define FEATURES_H

#include "../../include/features.h"

#ifndef __APPLE__
#define weak __attribute__((__weak__))
#else
#define weak
#endif
#define hidden __attribute__((__visibility__("hidden")))

#undef weak_alias
#ifndef __APPLE__
#define weak_alias(old, new) \
	extern __typeof(old) new __attribute__((__weak__, alias(#old)))
#define weak_alias0(old, new) weak_alias(old,new)

#else
#define weak_alias(old, new) \
        __asm__(".globl _" #new); \
        __asm__("_" #new " = _" #old); \
        extern __typeof(old) new  __attribute__((weak_import))

#define weak_alias0(old, new) \
        extern __typeof(old) new

//__asm("_" __STRING(sym) __DARWIN_SUF_NON_CANCELABLE __DARWIN_SUF_UNIX03)
#endif

#endif
