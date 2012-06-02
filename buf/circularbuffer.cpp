/*
 * circularbuffer.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <common/ns.h>
#include <common/types.h>
#include "circularbuffer.h"
#include <stdlib.h>

s_namespace_2(synergi,engine)

template<class T>
circularbuffer<T>::circularbuffer(uint32_t rate, uint32_t sz) : sampleRate(rate), size(sz), latestOp(read)
{
	// Allocate memory for the buffer
	base = (T*)calloc(sz,sizeof(T));

	// Check for success
	if (!base) throw allocationfailed();

	// We're good ...
	pNextWriteByte = base;
	pNextReadByte = base;

}

template<class T>
circularbuffer<T>::~circularbuffer()
{
	free(base);
}

template<class T>
circularbuffer<T>& circularbuffer<T>::operator<<(const rawbuffer_t& rawBuffer)
{
	return *this;
}

template<class T>
void circularbuffer<T>::insert(T data)
{
	if (!is_full())
	{
		*(pNextWriteByte++) = data;
		if (pNextWriteByte >= (base+size))
			pNextWriteByte=base;
		latestOp = write;
	}
	else
		throw overrun();
}

template<class T>
T circularbuffer<T>::extract(void)
{
	if (!is_empty())
	{
		T retVal = *(pNextReadByte++);
		if (pNextReadByte >= (base+size))
			pNextReadByte=base;
		latestOp = read;
		return retVal;
	}
	else
		throw underrun();
}

template<class T>
uint32_t circularbuffer<T>::length(void) const
{
	if (is_empty()) return 0;
	if (is_full()) return capacity();

	if (pNextWriteByte>pNextReadByte)
	{
		return pNextWriteByte-pNextReadByte;
	}
	else
	{
		return pNextWriteByte+capacity()-pNextReadByte;
	}
}


template class synergi::engine::circularbuffer<synergi::byte_t>;

s_namespace_end_2
