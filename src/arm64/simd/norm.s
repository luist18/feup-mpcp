.text
.global norm
.type norm, "function"

norm:
	mov			x9, #0
	scvtf		d10, x9

cycle:
	cmp			w1, #0
	b.le		end

	ldr			q9, [x0], #16

	fmul		v9.2d, v9.2d, v9.2d

	faddp		d9, v9.2d

	add			d10, d10, d9

	sub			w1, w1, #4

	b			cycle

end:
	fsqrt		d9, d9
	fmov		d0, d9
