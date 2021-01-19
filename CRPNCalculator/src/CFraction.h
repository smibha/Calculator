/*
 * CFraction.h
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#ifndef CFRACTION_H_
#define CFRACTION_H_

/* Class which stores fraction in a/b format and provides various operation on it like +, -, *, /, ++, -- by overloading binary and unary operators */
class CFraction {

	/* If the operator doesn't take an instance of the class as its left-hand operand, it must be a free function */
	/* Can't be a member function because the int is on the left */

	/*TODO remove friend for following 4 functions as private data access is not required*/
	/* Binary operator + -> int + fraction obj */
	friend CFraction operator+(int lhi, const CFraction& rhf);

	/* Binary operator + -> int - fraction obj */
	friend CFraction operator-(int lhi, const CFraction& rhf);

	/* Binary operator + -> int * fraction obj */
	friend CFraction operator*(int lhi, const CFraction& rhf);

	/* Binary operator + -> int / fraction obj */
	friend CFraction operator/(int lhi, const CFraction& rhf);

	/* overloaded << operator so that cout accepts CFraction class object */
	friend std::ostream& operator<< (std::ostream&, const CFraction&);

public:

	/* Default constructor which provides default values*/
	CFraction(long numerator = 0, long denominator = 1);

	/* Set function checks if denominator = 0, performs sign handling and normalization */
	void set(long numerator, long denominator);

	/* Converts fraction form into decimal form*/
	double toDouble();

	/* Prints the contents of the object */
	void print();

	/* prefix -> ++fraction */
	CFraction& operator++();

	/* postfix -> fraction++ */
	CFraction operator++(int);

	/* prefix -> --fraction */
	CFraction& operator--();

	/* postfix -> fraction-- */
	CFraction operator--(int);

	/* unary minus */
	CFraction operator-();

	/* Binary operator + -> fraction obj + fraction obj*/
	CFraction operator+(const CFraction& rhf) const;

	/* Binary operator + -> fraction obj + int */
	CFraction operator+(const int rhi);

	/* Binary operator - -> fraction obj - fraction obj*/
	CFraction operator-(const CFraction& rhf);

	/* Binary operator - -> fraction obj - int */
	CFraction operator-(const int rhi);

	/* Binary operator * -> fraction obj * fraction obj*/
	CFraction operator*(const CFraction& rhf);

	/* Binary operator * -> fraction obj * int */
	CFraction operator*(const int rhi);

	/* Binary operator / -> fraction obj / fraction obj*/
	CFraction operator/(const CFraction& rfh);

	/* Binary operator / -> fraction obj / int */
	CFraction operator/(const int rhi);

private:

	/* Member variable to store numerator */
	long m_numerator;

	/* Member variable to store denominator */
	long m_denominator;

	/* Member function to normalise the fraction */
	void shorten();

	/* Member function to calculate gcd of numerator and denominator */
	long calculateGCD(long num, long den);

};

#endif /* CFRACTION_H_ */
