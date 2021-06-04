#ifndef __APPLE__
__asm__(
".text \n"
".global " START "\n"
".type " START ",%function\n"
START ":\n"
"	mov x29, #0\n"
"	mov x30, #0\n"
"	mov x0, sp\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n"
"	adrp x1, _DYNAMIC\n"
"	add x1, x1, #:lo12:_DYNAMIC\n"
"	and sp, x0, #-16\n"
"	b " START "_c\n"
);
#else
__asm__(
".text \n"
".global " START "\n"
START ":\n"
"	mov x29, #0\n"
"	mov x30, #0\n"
"	mov x0, sp\n"
"	and sp, x0, #-16\n"
"	b " START "_c\n"
);
#endif
