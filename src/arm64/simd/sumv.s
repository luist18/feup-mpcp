.text
.global sumv
.type sumv, "function"

sumv:
	cmp		w3, #0
	b.le	end

	ldr		q0, [x0], #16
	ldr		q1, [x1], #16
	fadd	v0.4s, v0.4s, v1.4s

	str		q0, [x2], #16

	sub 	w3, w3, #4

	b		sumv

end:
	ret
