.text
.global fourxintab
.type fourxintab, "function"

fourxintab:
	eor		w8, w8, w8

cicle:
	cbz		w1, end
	ldr		w9, [x0]
	lsl		w10, w9, #2
	cmp		w10, w2
	b.lo	next
	cmp		w10, w3
	b.hi	next
	add		w8, w8, #1
	b		next

next:
	sub		w1, w1, #1
	add		x0, x0, #4
	b		cicle

end:
	mov		w0, w8
	ret

