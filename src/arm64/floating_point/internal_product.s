.text
.global internal_product
.type internal_product, "function"

internal_product:
	mov			x9, #0
	scvtf		d0, x9

cycle:
	cbz			w2, end
	ldr			s1, [x0], #4
	ldr			s2, [x1], #4
	fcvt 		d1, s1
	fcvt		d2, s2
	fmadd		d0, d1, d2, d0
	sub			w2, w2, #1
	b			cycle

end:
	ret
