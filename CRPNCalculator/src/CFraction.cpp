/*
 * CFraction.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#include<iostream>
#include<cmath>

#include "CFraction.h"

CFraction::CFraction(long numerator, long denominator) : m_numerator(0), m_denominator(1)
{
	set (numerator, denominator);
}

void CFraction::set(long numerator, long denominator)
{
	if(denominator == 0)
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	else
	{
		m_numerator = numerator;
		if(denominator  < 0)
		{
			m_numerator *= -1;
			m_denominator = denominator * -1;

		}
		else
		{
			m_denominator = denominator;
		}
		if(m_numerator != 0 && m_numerator != 1 && m_denominator != 1)
		{
			shorten();
		}
	}
}

void CFraction::shorten()
{
	long gcd = calculateGCD(m_numerator, m_denominator);
	m_numerator = m_numerator / gcd;
	m_denominator = m_denominator / gcd;
}

long CFraction::calculateGCD(long num, long den)
{
	num = abs(num);
	den = abs(den);

	if(num == 0)
		return den;
	return calculateGCD(den % num, num);
}

double CFraction::toDouble()
{
	double f = (double)m_numerator/(double)m_denominator;
	std::cout << "The fraction in decimal form = " << f << std::endl;
	return f;
}

void CFraction::print()
{
	std::cout << "[numerator = " << this->m_numerator  <<", m_denominator = " << this->m_denominator << "]"<< std::endl;
}

CFraction& CFraction::operator++()
{
	this->m_numerator += this->m_denominator;
	return *this;
}

CFraction CFraction::operator++(int)
{
	CFraction temp = *this;
	this->m_numerator += this->m_denominator;
	return temp;
}

CFraction& CFraction::operator--()
{
	m_numerator = m_numerator - m_denominator;
	return *this;
}

CFraction CFraction::operator--(int)
{
	CFraction result = *this;
	m_numerator = m_numerator - m_denominator;
	return result;
}

CFraction CFraction::operator -()
{
	CFraction result = *this;
	result.m_numerator *= -1;
	return result;
}

CFraction CFraction::operator+(const CFraction &rhf) const
{
	CFraction result;
	result.m_numerator = (this->m_numerator * rhf.m_denominator) + (rhf.m_numerator * this->m_denominator);
	result.m_denominator = this->m_denominator * rhf.m_denominator;
	result.set(result.m_numerator, result.m_denominator);
	return result;
}

CFraction CFraction::operator+(const int rhi)
{
	return CFraction(*this + CFraction(rhi));
}

CFraction CFraction::operator-(const CFraction &rhf)
{
	CFraction result;
	result.m_numerator = (this->m_numerator * rhf.m_denominator) - (rhf.m_numerator * this->m_denominator);
	result.m_denominator = this->m_denominator * rhf.m_denominator;
	result.set(result.m_numerator, result.m_denominator);
	return result;
}

CFraction CFraction::operator-(const int rhi)
{
	return CFraction(*this - CFraction(rhi));
}

CFraction CFraction::operator*(const CFraction &rhf)
{
	CFraction result;
	result.m_numerator = this->m_numerator * rhf.m_numerator;
	result.m_denominator = this->m_denominator * rhf.m_denominator;
	result.set(result.m_numerator, result.m_denominator);
	return result;
}

CFraction CFraction::operator*(const int rhi)
{
	return CFraction(*this * CFraction(rhi));
}

CFraction CFraction::operator/(const CFraction &rhf)
{
	CFraction result;
	result.m_numerator = this->m_numerator * rhf.m_denominator;
	result.m_denominator = this->m_denominator * rhf.m_numerator;
	result.set(result.m_numerator, result.m_denominator);
	return result;
}

CFraction CFraction::operator/(const int rhi)
{
	return CFraction(*this / CFraction(rhi));
}

CFraction operator+(int lhi, const CFraction& rhf)
{
	return CFraction(CFraction(lhi) + CFraction(rhf));
}

CFraction operator-(int lhi, const CFraction& rhf)
{
	return CFraction(CFraction(lhi) - CFraction(rhf));
}

CFraction operator*(int lhi, const CFraction& rhf)
{
	return CFraction(CFraction(lhi) * CFraction(rhf));
}

CFraction operator/(int lhi, const CFraction& rhf)
{
	return CFraction(CFraction(lhi) / CFraction(rhf));
}

std::ostream& operator << (std::ostream &output, const CFraction &result)
{
	output << result.m_numerator << " / " << result.m_denominator;
	return output;
}
