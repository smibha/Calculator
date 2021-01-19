/*
 * CLifoBuffer.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#include <iostream>

#include "CFraction.h"
#include "CLifoBuffer.h"

CLifoBuffer::CLifoBuffer (int size) :
m_size(size),
m_tos(-1)
{
	m_pBuffer = new CFraction [size];
}

CLifoBuffer::~CLifoBuffer ()
{
	delete [] m_pBuffer;
}

bool CLifoBuffer::push (const CFraction &data)
{
	if (m_tos+1 < m_size)
	{
		m_tos++;
		m_pBuffer[m_tos] = data;
		return true;
	}
	else
	{
		std::cout << "Stack is full" << std::endl;
		return false;
	}
}

bool CLifoBuffer::pop (CFraction &data)
{
	if (m_tos < 0)
	{
		std::cout << "Stack is empty" << std::endl;
		return false;
	}
	else
	{
		data = m_pBuffer[m_tos];
		m_tos = m_tos-1;
		return true;
	}
}

void CLifoBuffer::print()
{
	std::cout << "The fractions entered are: " << std::endl;
	std::cout << "---------------------------" << std::endl;
	for (int i=0; i<(m_tos+1); i++)
	{
		m_pBuffer[i].print();
	}
}

