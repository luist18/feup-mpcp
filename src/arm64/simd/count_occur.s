.text
.global count_occur
.type count_occur, "function"


/*
 * x0: arr
 * x1: size
 * w2: value to compare to
 */
conta_ocorr:
	eor			x10, x10, x10

cycle:
	cbz			x1, end

	ldr			q9, [x0], #16
	sub			x1, x1, #16

	dup			v10.16b, w2
	cmeq		v11.16b, v9.16b, v10.16b
	abs			v11.16b, v11.16b

	addv		b12, v11.16b
	smov		x11, v12.b[0]
	add			x10, x11, x10

	b			cycle

end:
	mov			x0, x10
	ret
