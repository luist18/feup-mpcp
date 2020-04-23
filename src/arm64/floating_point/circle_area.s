.text
.global circle_area
.type circle_area, "function"

.data
pi:	.double 3.141592653

circle_area:
	fmul		d0, d0, d0
	ldr			d1, pi
	fmul		d0, d0, d1
	ret
