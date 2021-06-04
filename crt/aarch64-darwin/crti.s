.section __TEXT,.init
.global _init
_init:
	stp x29,x30,[sp,-16]!
	mov x29,sp

.section __TEXT,.fini
.global _fini
_fini:
	stp x29,x30,[sp,-16]!
	mov x29,sp
