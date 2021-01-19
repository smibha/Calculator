/*
 * CLifoBuffer.h
 *
 *  Created on: Nov 20, 2013
 *      Author: smi u
 */

#ifndef CLIFOBUFFER_H_
#define CLIFOBUFFER_H_

#include "CFraction.h"

/* Class provides memory and implements stack to push and pop fraction objects */
class CLifoBuffer {

public:

	/* Constructor with default size of buffer size of 10*/
	CLifoBuffer (int size=10);

	/* Destructor */
	~CLifoBuffer ();

	/* Print the contents of the buffer */
	void print();

	/* Push fraction object on stack if space is available */
	bool push (const CFraction &data);

	/* Pop fraction object from stack */
	bool pop (CFraction &data);

private:

	/* Indicates the size of buffer */
	int m_size;

	/* Indicates the current size of the buffer*/
	int m_tos;

	/* Pointer to the fraction object - to provide dynamic memory for fraction objects */
	CFraction *m_pBuffer;

};

#endif /* CLIFOBUFFER_H_ */
