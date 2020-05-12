.text
.global eStep
.type eStep, "function"

/**
 * w0 - 32 bit register - unsigned int with the N size
 * x1 - 64 bit register - pointer to a single precision floating point vector (32 bit)
 * w2 - 32 bit register - unsigned int with the M size
 * x3 - 64 bit register - pointer to a double precision floating point vector (64 bit)
 * x4 - 64 bit register - pointer to a unsigned int vector (32 bit)
 *
 * w9 - 32 bit register - unsigned int with the M size [BACKUP]
 * x10 - 64 bit register - pointer to a double precision floating point vector (64 bit) [BACKUP]
 *
 * s9 - 32 bit register - the loaded number from the first vector (x1)
 * s10 - 32 bit register - the loaded number from the first vector (x1)
 * d11 - 64 bit register - the loaded number from the second vector (x3)
 * d12 - 64 bit register - the loaded number from the second vector (x3)
 * d13 - 64 bit register - min distance
 */

eStep:

cycle1:
	cbz			w0, end

	ldr			s9, [x1], #4
	ldr			s10, [x1], #4
	sub			w0, w0, #1

	fcvt		d9, s9
	fcvt		d10, s10

	mov			w9, w2
	mov			x10, x3
	mov			x11, #0

	// first
	ldr			d11, [x10], #8
	ldr			d12, [x10], #8

	// calculating the distance, storing in d11
	fsub		d11, d11, d9
	fmul		d11, d11, d11

	fsub		d12, d12, d10
	fmul		d12, d12, d12

	fadd		d11, d11, d12
	fsqrt		d11, d11

	fmov		d13, d11

	sub			w9, w9, #1

cycle2:
	cbz			w9, cycle2_end

	ldr			d11, [x10], #8
	ldr			d12, [x10], #8

	// calculating the distance, storing in d11
	fsub		d11, d11, d9
	fmul		d11, d11, d11

	fsub		d12, d12, d10
	fmul		d12, d12, d12

	fadd		d11, d11, d12
	fsqrt		d11, d11

	fcmp		d11, d13

	b.hs		cycle2_next

	sub			w11, w2, w9
	fmov		d13, d11

cycle2_next:
	sub			w9, w9, #1

	b			cycle2

cycle2_end:
	str			w11, [x4], #4

	b			cycle1

end:
	ret
