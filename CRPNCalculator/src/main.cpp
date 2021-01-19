/*
 *  main.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#include <iostream>
#include <string>

#include "CFraction.h"
#include "CLifoBuffer.h"
#include "CRpnCalculator.h"

//#define TESTING_CFRACTION;
//#define TESTING_CLIFOBUFFER;

int main (void)
{
	std::cout << "=========================================================================================================" << std::endl;
	std::cout << "=========================================     RPN_CALCULATOR    =========================================" << std::endl;
	std::cout << "=========================================================================================================" << std::endl << std::endl;

	std::cout << "The input for RPN Calculator can be fractions and operators. " << std::endl;
	std::cout << "The input should be made in postfix notation. " << std::endl;
	std::cout << "The operators supported by this calculator are : " << std::endl;
	std::cout << "Increment(++) and decrement(--) operator, binary oprators -> +, -, *, /" << std::endl << std::endl;

	CRpnCalculator myCal;

	bool var = true;
	do
	{
		char input;
		std::cout << "Enter letter N to enter operand, letter O to enter operator and letter X to exit :" << std::endl;
		std::cin >> input;

		if(input == 'N')
		{
			long numerator, denominator;
			std::cout << "Enter numerator :" << std::endl;
			std::cin >> numerator;
			std::cout << "Enter denominator :" << std::endl;
			std::cin >> denominator;
			if(!myCal.pushValue(CFraction(numerator, denominator)))
				var = false;
		}
		else if(input == 'O')
		{
			std::string op;
			std::cout << "Enter operator :" << std::endl;
			std::cin >> op;
			if(op.compare("++") == 0)
			{
				myCal.increment();
			}
			else if(op.compare("--") == 0)
			{
				myCal.decrement();
			}
			else if(op.compare("+") == 0)
			{
				myCal.add();
			}
			else if(op.compare("-") == 0)
			{
				myCal.subtract();
			}
			else if(op.compare("*") == 0)
			{
				myCal.multiply();
			}
			else if(op.compare("/") == 0)
			{
				myCal.divide();
			}
			else
			{
				std::cout << "Operator not supported." << std::endl;
			}
		}
		else if(input == 'X')
		{
			std::cout << "EXIT RPN_CALCULATOR" << std::endl;
			var = false;
		}
		else
		{
			std::cout << "Character not supported." << std::endl;
		}
	} while(var);

	CFraction endResult;
	myCal.popResult(endResult);
	std::cout << "The result of the expression entered = " << endResult << std::endl;


#ifdef TESTING_CFRACTION

	std::cout << "-------------------------------- TESTING CFRACTION CLASS -------------------------------------" << std::endl << std::endl;

	std::cout << "Creating a fraction with numerator = 100 and denominator = 125" << std::endl;
	CFraction fract_1(100, 125);
	fract_1.print();
	std::cout << std::endl;

	std::cout << "Creating a fraction with numerator = -100 and denominator = -125" << std::endl;
	CFraction fract_2(-100, -125);
	fract_2.print();
	std::cout << std::endl;

	std::cout << "Creating a fraction with numerator = -100 and denominator = 125" << std::endl;
	CFraction fract_3(-100, 125);
	fract_3.print();
	std::cout << std::endl;

	std::cout << "Creating a fraction with numerator = 100 and denominator = -125" << std::endl;
	CFraction fract_4(100, -125);
	fract_4.print();
	std::cout << std::endl;

	std::cout << "------------------------- TESTING OVERLOADED OPERATORS ON FRACTIONS --------------------------" << std::endl << std::endl;

	std::cout << "Binary + operator:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "10/20    +    30/8   =  " << CFraction(10, 20) + CFraction(30, 8) << std::endl;
	std::cout << "5        +    56/22  =  " << 5 + CFraction(56, 22) << std::endl;
	std::cout << "4/8      +     6     =  " << CFraction(4, 8) + 6 << std::endl << std::endl;

	std::cout << "Binary - operator:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "10/20    -    30/8   =  " << CFraction(10, 20) - CFraction(30, 8) << std::endl;
	std::cout << "5        -    56/22  =  " << 5 - CFraction(56, 22) << std::endl;
	std::cout << "4/8      -     6     =  " << CFraction(4, 8) - 6 << std::endl << std::endl;

	std::cout << "Binary * operator:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "10/20    *    30/8   =  " << CFraction(10, 20) * CFraction(30, 8) << std::endl;
	std::cout << "5        *    56/22  =  " << 5 * CFraction(56, 22) << std::endl;
	std::cout << "4/8      *     6     =  " << CFraction(4, 8) * 6 << std::endl << std::endl;

	std::cout << "Binary / operator:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "10/20    /    30/8   =  " << CFraction(10, 20) / CFraction(30, 8) << std::endl;
	std::cout << "5        /    56/22  =  " << 5 / CFraction(56, 22) << std::endl;
	std::cout << "4/8      /     6     =  " << CFraction(4, 8) / 6 << std::endl << std::endl;

	std::cout << "Unary - operator:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "-(10/20)  =  " << -CFraction(10, 20) << std::endl << std::endl;

	std::cout << "Prefix ++ operator:" << std::endl;
	std::cout << "-------------------" << std::endl;
	CFraction f(4, 7);
	CFraction g;
	g = ++f;
	std::cout << "g and f are fraction objects. f = 4/7" << std::endl;
	std::cout << "After operation g = ++ f " << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "f = " << f << std::endl << std::endl;

	std::cout << "Postfix ++ operator:" << std::endl;
	std::cout << "-------------------" << std::endl;
	CFraction y(4, 7);
	CFraction x;
	x = y++;
	std::cout << "x and y are fraction objects. y = 4/7" << std::endl;
	std::cout << "After operation x = y++ " << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl << std::endl;

	std::cout << "Prefix -- operator:" << std::endl;
	std::cout << "-------------------" << std::endl;
	CFraction b(4, 7);
	CFraction a;
	a = --b;
	std::cout << "a and b are fraction objects. b = 4/7" << std::endl;
	std::cout << "After operation a = -- b " << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl << std::endl;

	std::cout << "Postfix -- operator:" << std::endl;
	std::cout << "-------------------" << std::endl;
	CFraction d(4, 7);
	CFraction c;
	c = d--;
	std::cout << "c and d are fraction objects. c = 4/7" << std::endl;
	std::cout << "After operation d = c++ " << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl << std::endl;

#endif

#ifdef TESTING_CLIFOBUFFER

	std::cout << "-------------------------------- TESTING CLIFOBUFFER CLASS -------------------------------------" << std::endl << std::endl;

	CLifoBuffer stack;

	CFraction fract_1(100, 125);
	CFraction fract_2(-5, 125);
	CFraction fract_3(-7, 8);
	CFraction fract_4(9, -10);
	CFraction fract_5(65, 125);

	stack.push(fract_1);
	stack.push(fract_2);
	stack.push(fract_3);
	stack.push(fract_4);
	stack.push(fract_5);

	std::std::cout << "Add 5 fraction objects on to stack and print it : " << std::std::endl;
	stack.print();
	std::std::cout << std::std::endl;

	std::std::cout << "Pop 6 fraction objects : " << std::std::endl;
	stack.pop(fract_1);
	stack.pop(fract_2);
	stack.pop(fract_3);
	stack.pop(fract_4);
	stack.pop(fract_5);
	stack.pop(fract_1);

#endif

	return 0;
}
