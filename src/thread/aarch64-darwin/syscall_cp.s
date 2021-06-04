// __syscall_cp_asm(&self->cancel, nr, u, v, w, x, y, z)
//                  x0             x1  x2 x3 x4 x5 x6 x7

// syscall(nr, u, v, w, x, y, z)
//         x8  x0 x1 x2 x3 x4 x5

.global ___cp_begin
	.align 4
.global ___cp_end
	.align 4
.global ___cp_cancel
	.align 4
.global ___syscall_cp_asm
	.align 4
___syscall_cp_asm:
___cp_begin:
	ldr w0,[x0]
	cbnz w0,___cp_cancel
	mov x8,x1
	mov x0,x2
	mov x1,x3
	mov x2,x4
	mov x3,x5
	mov x4,x6
	mov x5,x7
	svc 0
___cp_end:
	ret
___cp_cancel:
	b ___cancel
