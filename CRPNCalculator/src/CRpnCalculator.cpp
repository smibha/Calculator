/*
 * CRpnCalculator.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#include <iostream>

#include "CFraction.h"
#include "CLifoBuffer.h"
#include "CRpnCalculator.h"

bool CRpnCalculator::pushValue (const CFraction &data)
{
	if(stack.push(data))
	{
		std::cout << "Pushing data on the stack is successful" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Pushing data value on the stack failed" << std::endl;
		return false;
	}
}

bool CRpnCalculator::popResult (CFraction &data)
{
	if(stack.pop(data))
	{
		std::cout << "Popping of data from the stack is successful" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Popping of data from the stack failed" << std::endl;
		return false;
	}
}

void CRpnCalculator::add()
{
	std::cout<<"Add the top two values on the stack : "<< std::endl;
	CFraction temp1, temp2, temp3;
	popResult(temp1);
	popResult(temp2);
	temp3 = temp1 + temp2;
	pushValue(temp3);
	std::cout << "The added values are " << std::endl;
	temp3.print();
}

void CRpnCalculator::subtract()
{
	std::cout<<"Subtract the top two values on the stack : "<< std::endl;
	CFraction temp1, temp2, temp3;
	popResult(temp1);
	popResult(temp2);
	temp3 = temp1 - temp2;
	pushValue(temp3);
	std::cout << "The subtracted values are " << std::endl;
	temp3.print();
}

void CRpnCalculator::multiply()
{
	std::cout<<"Multiply the top two values on the stack : "<< std::endl;
	CFraction temp1, temp2, temp3;
	popResult(temp1);
	popResult(temp2);
	temp3 = temp1 * temp2;
	pushValue(temp3);
	std::cout << "The multiplied values are " << std::endl;
	temp3.print();
}

void CRpnCalculator::divide()
{
	std::cout<<"Divide the top two values on the stack : "<< std::endl;
	CFraction temp1, temp2, temp3;
	popResult(temp1);
	popResult(temp2);
	temp3 = temp1/temp2;
	pushValue(temp3);
	std::cout << "The divided values are " << std::endl;
	temp3.print();
}

void CRpnCalculator::increment()
{
	std::cout<<"Increment the top value on the stack : "<< std::endl;
	CFraction temp1;
	popResult(temp1);
	temp1++;
	pushValue(temp1);
	std::cout << "The incremented value is " << std::endl;
	temp1.print();
}

void CRpnCalculator::decrement()
{
	std::cout<<"Decrement the top value on the stack : "<< std::endl;
	CFraction temp1;
	popResult(temp1);
	temp1--;
	pushValue(temp1);
	std::cout << "The decremented value is " << std::endl;
	temp1.print();
}

void CRpnCalculator::negate()
{
	std::cout<<"Negate the top value on the stack : "<< std::endl;
	CFraction temp1;
	popResult(temp1);
	-temp1;
	pushValue(temp1);
	std::cout << "The decremented value is " << std::endl;
	temp1.print();
}
