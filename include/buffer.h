/*
 * buffer.h
 *
 *  Created on: 2013-6-4
 *      Author: htf
 */

#ifndef SW_BUFFER_H_
#define SW_BUFFER_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _swBuffer_trunk
{
	uint32_t type;
	uint32_t length;
	uint32_t offset;
	union
	{
		void *ptr;
		struct
		{
			uint32_t val1;
			uint32_t val2;
		} data;
	} store;
	uint32_t size;
	struct _swBuffer_trunk *next;
} swBuffer_trunk;

typedef struct _swBuffer
{
	int fd;
	uint8_t trunk_num; //trunk数量
	uint16_t trunk_size;
	uint32_t length;
	swBuffer_trunk *head;
	swBuffer_trunk *tail;
} swBuffer;

#define swBuffer_get_trunk(buffer)   (buffer->head)
#define swBuffer_empty(buffer)       (buffer == NULL || buffer->head == NULL)

swBuffer* swBuffer_new(int trunk_size);
swBuffer_trunk *swBuffer_new_trunk(swBuffer *buffer, uint32_t type, uint32_t size);
void swBuffer_pop_trunk(swBuffer *buffer, swBuffer_trunk *trunk);
int swBuffer_append(swBuffer *buffer, void *data, uint32_t size);

void swBuffer_debug(swBuffer *buffer, int print_data);
int swBuffer_free(swBuffer *buffer);

#ifdef __cplusplus
}
#endif

#endif /* SW_BUFFER_H_ */
