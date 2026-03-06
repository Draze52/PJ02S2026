/*
  Ryan Drazek, ID:123695485
*/

#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

void Heapify(HEAP *heap, ELEMENT **array, int i);
void BuildHeap(HEAP *heap, ELEMENT **array);
ELEMENT* ExtractMin(HEAP *heap, ELEMENT **array);
void DecreaseKey(HEAP *heap, ELEMENT **array, int index, double newKey);
void InsertHeap(HEAP *heap, ELEMENT **array, int index);

void PrintArray(ELEMENT **array, int n);
void PrintHeap(HEAP *heap, ELEMENT **array);

#endif
