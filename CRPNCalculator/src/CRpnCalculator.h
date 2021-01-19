/*
 * CRpnCalculator.h
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#ifndef CRPNCALCULATOR_H_
#define CRPNCALCULATOR_H_

#include "CLifoBuffer.h"
#include "CFraction.h"

class CRpnCalculator {

public:

	/* Push fraction object on the stack */
	bool pushValue (const CFraction &data);

	/* Pop fraction object from the stack */
	bool popResult (CFraction &data);

	/* Pop top two values on the stack, add and store the result on top of stack */
	void add();

	/* Pop top two values on the stack, subtract and store the result on top of stack */
	void subtract();

	/* Pop top two values on the stack, multiply and store the result on top of stack */
	void multiply();

	/* Pop top two values on the stack, divide and store the result on top of stack */
	void divide();

	/* Pop top value on the stack, increment value by 1 and store the result on top of stack */
	void increment();

	/* Pop top value on the stack, decrement value by 1 and store the result on top of stack */
	void decrement();

	/* Pop top value on the stack, negate value and store the result on top of stack */
	void negate();

private:

	CLifoBuffer stack;

};

#endif /* CRPNCALCULATOR_H_ */
