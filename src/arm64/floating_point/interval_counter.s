.text
.global interval_counter
.type interval_counter, "function"

/**
 * x0 - 64 bit register - is the pointer to the float vector
 * x1 - 32 bit register - size of the array as a long
 * s0 - 32 bit register - min value
 * s1 - 32 bit register - max value
 */

interval_counter:
	eor		x9, x9, x9

cycle:
	cbz		x1, end
	ldr		s9, [x0]

	fcmp	s9, s0
	b.lt	next
	fcmp	s9, s1
	b.gt	next

	add		x9, x9, #1

next:
	sub		x1, x1, #1
	add		x0, x0, #4
	b		cycle

end:
	mov		x0, x9
	ret
