.extern cosx

.text
.global func_cosx
.type func_cosx, "function"

.data
pi:				.double 3.14159265359

func_cosx:
    stp				x29, x30, [sp, #-80]!
	mov				x29, sp

	mov				x9, #180
	mov				x10, #100
	mov				x11, #50
	scvtf			d10, x9
	scvtf			d11, x10
	scvtf			d12, x11

	ldr				d9, pi
	fmul			d0,	d9, d0
	fdiv			d0, d0, d10

	stp				d15, d14, [sp, #16]
	stp				d13, d12, [sp, #32]
	stp				d11, d10, [sp, #48]
	str				d9,	[sp, #64]

	b				cosx

	ldp				d15, d14, [sp, #16]
	ldp				d13, d12, [sp, #32]
	ldp				d11, d10, [sp, #48]
	ldr				d9,	[sp, #64]

	fmul			d0, d12, d0
	fadd			d0, d0, d11

	ldp 	x29, x30, [sp], #80

	ret
