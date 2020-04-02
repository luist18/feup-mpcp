.text
.global example
.type example, "function"

/*
 * This function is going to sum every value from 1 to 'n' and return the value.
 * The 'n' value is the first argument (x0).
 */

example:
	eor		x8, x8, x8

cicle:
	cbz		x0, end
	add		x8, x8, x0
	sub		x0, x0, #1
	b		cicle

end:
	mov		x0, x8
	ret
