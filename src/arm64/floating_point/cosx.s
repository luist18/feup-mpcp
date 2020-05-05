.text
.global cosx
.type cosx, "function"

.data
firstfatorial:	.double 0.50000000000
secondfatorial:	.double 0.04166666666
thirdfatorial:	.double 0.00138888888
fourthfatorial:	.double 0.00002480158
fifthfatorial:	.double 0.00000027557

/*
 * d0 - 64 bit register - is the radian value
 */
cosx:
	stp			x29, x30, [sp, #-16]!
	mov			x29, sp

	mov			x9, #0
	scvtf		d9, x9

	fmul		d0, d0, d0

	//
	ldr			d10, fifthfatorial
	ldr			d11, fourthfatorial

	fmsub		d12, d10, d0, d11

	fadd		d9, d9, d12

	//
	ldr			d10, thirdfatorial

	fmsub		d12, d0, d12, d10
	fadd		d9, d9, d12

	//
	ldr			d10, secondfatorial

	fmsub		d12, d0, d12, d10
	fadd		d9, d9, d12

	//
	ldr			d10, firstfatorial

	fmsub		d12, d0, d12, d10
	fadd		d9, d9, d12

	fmov		d0, d9

	ldp			x29, x30, [sp], #16
	ret


