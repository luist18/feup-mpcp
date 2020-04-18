.text
.global reverse_string
.type reverse_string, "function"

reverse_string:
	mov				x9, x0
	mov				x11, sp

reverse:
	ldrb			w10, [x9], #1
	cbz				w10, store
	str				w10, [sp, #-16]!
	b				reverse

store:
	ldr				w10, [sp], #16
	strb			w10, [x0], #1
	cmp				sp, x11
	b.eq			end
	b				store

end:
	ret

