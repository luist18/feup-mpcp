.text
.global power
.type power, "function"

/*
 * w0: base
 * w1: exp
 */
power:
	stp 	x29, x30, [sp, #-16]!
	mov 	x29, sp
	// set x15 as max int
	mov		x15, #-1
	lsr		x15, x15, #33
	// set x9 as result
	mov		x9, #1

cicle:
	cbz		w1, end
	smull	x9, w9, w0
	// verify overflow
	cmp		x9, #0
	csneg	x10, x9, x9, gt	// absolute value
	cmp		x10, x15			// overflow with max int
	b.gt	overflow
	sub		w1, w1, #1
	b		cicle

overflow:
	ldp 	x29, x30, [sp], #16
	mov		x9, #0

end:
	mov		x0, x9
	ldp 	x29, x30, [sp], #16
	ret
