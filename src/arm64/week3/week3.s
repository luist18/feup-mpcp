.extern power
.text
.global Calculator
.type Calculator, "function"

Calculator:
    stp				x29, x30, [sp, #-96]!
	mov				x29, sp
    eor             w9, w9, w9
    mov				x14, #-1
	lsr				x14, x14, #33

cycle:
    cbz             w0, end
    ldrb            w10, [x1], #1
    ldr             w11, [x3], #4
    ldr             w12, [x2], #4
    sub             w0, w0, #1
    add             w9, w9, #1

    cmp             w10, #0x2b
    b.eq            op_addition

    cmp             w10, #0x2d
    b.eq            op_subtraction

    cmp             w10, #0x2a
    b.eq            op_product

    cmp             w10, #0x50
    b.eq            op_power

    b				cycle

end:
    mov             w0, #0
    ldp				x29, x30, [sp], #96
    ret

overflow:
    mov             w0, w9
    ldp				x29, x30, [sp], #96
    ret

op_addition:
    adds            w13, w11, w12
    b.vs            overflow
    str             w13, [x3, #-4]
    b               cycle

op_subtraction:
    subs            w13, w11, w12
    b.vs            overflow
    str             w13, [x3, #-4]
    b               cycle

op_product:
    smull           x13, w11, w12
	cmp				x13, x14
    b.gt			overflow
    str             w13, [x3, #-4]
    b               cycle

/*
 * Power operation. x9-15 need to be stored in the stack as well as the x0 and x1
 */
op_power:
	stp				d15, d14, [sp, #16]
	stp				d13, d12, [sp, #32]
	stp				d11, d10, [sp, #48]
	str				d9,	[sp, #80]

	mov				x0, x11
	mov				x1, x12
    bl              power

    ldp				x15, x14, [sp, #16]
	ldp				x13, x12, [sp, #32]
	ldp				x11, x10, [sp, #48]
	ldp				x9, x1, [sp, #64]

    cbz             w0, overflow
    str             w0, [x3, #-4]

	ldr				x0,	[sp, #80]

    b               cycle
