/*
  Ryan Drazek, ID:123695485
*/

#ifndef _data_structures_h
#define _data_structures_h 1

typedef struct TAG_ELEMENT{
	int index;
	double key;
	int pos;
} ELEMENT;

typedef struct TAG_HEAP{
	int capacity;
	int size;
	int *H;
} HEAP;

#endif
