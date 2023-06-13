#ifndef AXIS_H
#define AXIS_H
/* Copyright (c) 2023, Julia Desmazes. All rights reserved.
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial
 * 4.0 International License.
 *
 * This code is provided "as is" without any express or implied warranties. */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#ifdef DEBUG
#include <stdio.h>
#endif
uint64_t axis_get_next_64b(const uint8_t *flat, size_t *idx, const size_t len, uint8_t *mask);

void axis_send_64b(const uint64_t payload, const uint8_t mask, 
	uint8_t *tvalid, uint8_t *tkeep, uint8_t *tready, uint64_t*tdata);

static inline bool axis_msg_finished(size_t *idx, const size_t len){
	bool end;
	end = ( *idx > len-1 );
	#ifdef DEBUG
	printf("Axis msg finished %u idx %ld len-1 %ld\n", end, *idx, len);
	#endif
	return end;
}
#endif // AXIS_H
 
