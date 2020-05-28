.text
.global sat_add
.type sat_add, "function"

sat_add:
	dup			v1.4s, w2

cycle:
	cmp			w1, #0
	b.le		end

	ldr			q0, [x0]

	sqadd		v0.4s, v0.4s, v1.4s

	str			q0, [x0], #16

	sub			w1, w1, #4

	b			cycle

end:
	ret
