.text
.global prodintv
.type prodintv, "function"

prodintv:
	eor		x9, x9, x9

cycle:
	cmp		w2, #0
	b.le	end

	ldr		q9, [x0], #16
	ldr		q10, [x1], #16

	mul 	v9.4s, v9.4s, v10.4s

	addv	s9, v9.4s

	smov	x10, v9.s[0]

	add		x9, x9, x10

	sub 	w2, w2, #4

	b 		cycle

end:
	mov 	x0, x9
	ret
