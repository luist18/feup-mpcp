.text
.global freqchars
.type freqchars, "function"

freqchars:
	eor		w15, w15, w15
	scvtf	s15, w15
	scvtf	s9, w0

	mov		w9, w2		// backup size of letters
	mov		x11, x4		// backup resultado final

clear_vector:
	cbz		w9, cycle1

	str		s15, [x11], #4

	sub		w9, w9, #1
	b 		clear_vector

cycle1:
	cbz		w0, end

	ldr		q10, [x1], #16

	mov		w9, w2		// backup size of letters
	mov		x10, x3		// backup array of letters
	mov		x11, x4		// backup resultado final

cycle2:
	cbz		w9, next

	ldrb	w12, [x10], #1	// lê para w12 a letra
	mov		w14, w12

	dup		v11.16b, w12

	// comparison for lowcase
	cmeq	v12.16b, v10.16b, v11.16b

	sub		w12, w12, #32
	dup		v11.16b, w12

	// comparison for uppercase
	cmeq	v11.16b, v10.16b, v11.16b

	orr		v11.16b, v11.16b, v12.16b

	addv	b11, v11.16b
	smov	w12, v11.b[0]

	// q11 and q12 arent necessary anymore
	neg		w12, w12
	scvtf	s13, w12

	mov		w13, #100
	scvtf	s14, w13
	fdiv	s13, s13, s9
	fmul	s13, s13, s14

	ldr		s14, [x11]
	fadd	s13, s13, s14
	str		s13, [x11], #4

	// compare

	fcmp	s13, s15
	csel	w15, w14, w15, gt
	fcsel	s15, s13, s15, gt

	sub		w9, w9, #1

	b		cycle2

next:
	sub 	w0, w0, #16

	b 	cycle1

end:
	mov		w0, w15
	ret
