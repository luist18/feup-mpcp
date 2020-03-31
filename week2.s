.text
.global CheckRange
.type CheckRange, "function"

CheckRange:
	eor			w8, w8, w8		// Sets the temporary result to 0
	mov			w9, w0			// Moves to w9 the max limit value
	neg			w10, w0			// Computes the min limit value and moves to w10

cicle:
	cbz			w1, end			// Verifies if the current decreasing index is 0
	ldr			w11, [x2]		// Loads to w11 the current value in the array
	cmp			w11, w10		// Compares the current value with the min limit
	b.lt		exchange_inf	// Stores the min limit if the current value is less than the min limit
	cmp			w11, w9			// Compares the current value with the max limit
	b.gt		exchange_sup	// Stores the max limit if the current value is greater than the max limit
	b			next			// Goes to the next iteration if the value is within the limit [v is the value, min limit <= v <= max limit]

exchange_inf:
	str			w10, [x2]		// Stores the min limit in the current value
	add			w8, w8, #1		// Adds a unit to the temporary result
	b			next			// Goes to the next iteration

exchange_sup:
	str			w9, [x2]		// Stores the max limit in the current value
	add			w8, w8, #1		// Adds a unit to the temporary result
	b			next			// Goes to the next iteration

next:
	sub			w1, w1, #1		// Decreases the size
	add			x2, x2, #4		// Goes to the next element in the array by adding 4 bytes (an integer has 4 bytes)
	b			cicle			// Restarts the cicle

end:
	mov 		w0, w8			// Moves to the return value the temporary result
	ret

