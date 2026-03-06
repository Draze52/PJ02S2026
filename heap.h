/*
  Ryan Drazek, ID:123695485
*/

#ifndef _heap_h
#define _heap_h 1

#include "data_structures.h"

void Heapify(HEAP *pHeap, ELEMENT **V, int i);
void BuildHeap(HEAP *pHeap, ELEMENT **V);
ELEMENT* ExtractMin(HEAP *pHeap, ELEMENT **V);
void DecreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey);
void InsertHeap(HEAP *pHeap, ELEMENT **V, int index);

void PrintArray(ELEMENT **V, int n);
void PrintHeap(HEAP *pHeap, ELEMENT **V);

#endif
