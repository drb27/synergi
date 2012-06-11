/*
 * circularbuffer.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <common/types.h>
#include <common/ns.h>
#include "basic.h"
#include <exception>

#define DEFAULT_SAMPLE_RATE 44100
#define DEFAULT_SIZE 1024


s_namespace_2(synergi,engine)

template<class T>
class circularbuffer
{
public:
	class allocationfailed : public std::exception {};
	class underrun : public std::exception {};
	class overrun : public std::exception {};

	enum ChannelConfig
	{
		mono,
		stereo
	};

private:

	enum op
	{
		read,
		write
	};

	const uint32_t sampleRate;

	T* pNextWriteByte;			// Pointer to the most recently added byte in the buffer
	T* pNextReadByte;			// Pointer to the next readable byte in the buffer
	const uint32_t size;		// The total size of the buffer
	T* base;					// Always points to the first byte of the raw buffer
	op latestOp;				// Was the last op a read or a write?
	ChannelConfig chnConfig;	// Channel configuration

public:
	circularbuffer(uint32_t rate = DEFAULT_SAMPLE_RATE, uint32_t sz = DEFAULT_SIZE, ChannelConfig cc = mono);
	virtual ~circularbuffer();

	inline bool is_empty() const { return ((pNextWriteByte==pNextReadByte)&&(latestOp==read)); }
	inline bool is_full() const { return ((pNextWriteByte==pNextReadByte)&&(latestOp==write)); }
	inline void reset() { pNextWriteByte = pNextReadByte = base; latestOp==read; }
	inline uint32_t sample_rate() const { return sampleRate; }
	uint32_t length() const;
	inline uint32_t capacity() const { return size; }
	void insert(T data);
	T extract(void);

	circularbuffer<T>& operator<<(const rawbuffer_t& rawBuffer);
	circularbuffer<T>& operator>>(rawbuffer_t& rawBuffer);
};

s_namespace_end_2

#endif /* CIRCULARBUFFER_H_ */

