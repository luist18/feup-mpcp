.text
.global CountCommon
.type CountCommon, "function"

/**
 * This assembly function counts how many numbers of an array A are in the array B.
 * The numbers must be an integer and the size unsigned as well as the result.
 *
 * Registers used:
 * w0 - 32 bit register that holds the size of first array as an unsigned integer
 * x1 - 64 bit register of the first array pointer
 * w2 - 32 bit register that holds the size of second array as an unsigned integer
 * x3 - 64 bit register of the second array pointer
 *
 * w9 - 32 bit register that stores the temporary result as an unsiged integer
 * w10 - 32 bit register that stores the current element in the first array as a signed integer
 * w11 - 32 bit register a copy of w2
 * x12 - 64 bit register a copy of x3
 * w13 - 32 bit register that stores the curren element inthe second array as a signed integer
 *
 * Note: in order to use less memory the size of the arrays are also going to be a flag to stop each cicle.
 */
CountCommon:
	eor			w9, w9, w9 		/* Sets the temporary result to 0 */
cicle1:
	cbz 		w0, end			/* Condition to stop the first cicle, that is, size is equal to 0 */
	ldr			w10, [x1], #4	/* Loads the current array element to w10 and goes to the next pointer by adding 4 bytes to it */
	sub 		w0, w0, #1		/* Decrements the size of the array */

	mov 		w11, w2			/* Moves the size of the second array to a temporary register */
	mov 		x12, x3			/* Moves the pointer of the second array to a temporary register */

cicle2:
	cbz 		w11, cicle1		/* Condition to stop the second cicle, that is, the size is equal to 0 */
	ldr			w13, [x12], #4	/* Loads the current array element to w13 and goes to the next pointer by adding 4 bytes to it */
	sub 		w11, w11, #1	/* Decrements the size of the array */
	cmp 		w13, w10		/* Compares the value in the first array with the value in the second array */
	cinc		w9, w9, eq		/* Increments the temporary result if the values in the previous line are equal */
	b 			cicle2			/* Repeats the process from line 33 to this line, if possible*/

end:
	mov 		w0, w9			/* Sets the return register to the temporary result */
	ret
