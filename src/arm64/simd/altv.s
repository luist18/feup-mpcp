.text
.global altv
.type altv, "function"

altv:
	cmp		w1, #0
	b.le	end

	ldr		q9, [x0], #16

	fmul	v9.4s, v9.4s, v0.4s[0]

	str		q9, [x0, #-16]

	sub 	w1, w1, #4

	b		altv

end:
	ret

