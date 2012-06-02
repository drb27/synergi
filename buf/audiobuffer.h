/*
 * audiobuffer.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef AUDIOBUFFER_H_
#define AUDIOBUFFER_H_

#include <common/types.h>
#include <common/ns.h>
#include <exception>

#define DEFAULT_SAMPLE_RATE 44100
#define DEFAULT_SIZE 1024

s_namespace_2(synergi,engine)

class audiobuffer
{
public:
	class allocationfailed : public std::exception {};
	class underrun : public std::exception {};
	class overrun : public std::exception {};

private:

	enum op
	{
		read,
		write
	};

	const uint32_t sampleRate;

	byte_t* pNextWriteByte;		// Pointer to the most recently added byte in the buffer
	byte_t* pNextReadByte;		// Pointer to the next readable byte in the buffer
	const uint32_t size;		// The total size of the buffer
	byte_t* base;				// Always points to the first byte of the raw buffer
	op latestOp;				// Was the last op a read or a write?

public:
	audiobuffer(uint32_t rate = DEFAULT_SAMPLE_RATE, uint32_t sz = DEFAULT_SIZE);
	virtual ~audiobuffer();

	inline bool is_empty() const { return ((pNextWriteByte==pNextReadByte)&&(latestOp==read)); }
	inline bool is_full() const { return ((pNextWriteByte==pNextReadByte)&&(latestOp==write)); }
	inline uint32_t sample_rate() const { return sampleRate; }
	uint32_t length() const;
	inline uint32_t capacity() const { return size; }
	void insert(byte_t data);
	byte_t extract(void);

	audiobuffer& operator<<(byte_t* rawBuffer);
};

s_namespace_end_2

#endif /* AUDIOBUFFER_H_ */

