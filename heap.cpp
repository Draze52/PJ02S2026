/*
  Ryan Drazek, ID:123695485
*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

static void exchange(HEAP *heap, ELEMENT **array, int a, int b){
  int temp = heap->H[a];
  heap->H[a] = heap->H[b];
  heap->H[b] = temp;

  array[heap->[a]]->pos = a;
  array[heap->[b]]->pos = b;
}

void Heapify(HEAP *heap, ELEMENT **array, int i){
  while(1){
    int left = 2 * i;
    int right = left + 1;
    int smallest = i;

    if (left <= heap->size && array[heap->H[left]]->key < array[heap->H[smallest]]->key)
      smallest = left;

    if (right <= heap->size && array[heap->H[right]]->key < array[heap->H[smallest]]->key)
      smallest = right;

    if (smallest = i)
      break;

    exhange(heap, array, i, smallest);
    i = smallest;
  }

void BuildHeap(HEAP *heap, ELEMENT **array){
  for (int i = heap->size / 2; i >= 1, i--)
    Heapify(heap, array, i);
}

ELEMENT* ExtractMin(HEAP *heap, ELEMENT **array){
  if (heap->size == 0)
    return NULL;

  int rootindex = heap->H[i];
  ELEMENT *minElement = array[rootindex];

  exchange(heap, array, i, heap->size);

  minElement->pos = 0;
  heap->size--;

  if(heap->size > 0)
    Heapify(heap, array, 1);

  return minElement;
}

void DecreaseKey(HEAP *heap, ELEMENT **array, int index, double newKey){
  if (index < 1 || index > heap->capacity)
    return;

  if (array[index]->pos == 0)
    return;

  if(newKey >= array[index]->key)
    return;

  array[index]->key = newKey;

  int pos = array[index]->pos;

  while(pos > 1){
    int par = pos / 2;

    if(array[heap->H[par]]->key <= array[heap->H[pos]]->key)
      break;

    exchange(heap, array, pos, par);
    pos = par;
  }
}

void InsertHeap(HEAP *heap, ELEMENT **array, int index){
  if (index < 1 || index > heap->capacity)
    return;

  if (array[index]->pos != 0)
    return;

  heap->size++;
  int current = heap->size;

  heap->H[current] = index;
  array[index]->pos = current;

  while(current > 1){
    int par = current / 2;

    if(array[heap->H[parent]]->key <= array[heap->H[current]]->key)
      break;

    exchange(heap, array, current, par);
    current = par;
  }
}

void PrintArray(ELEMENT **array, int n){
  for(int i = 1; i <= n; i++)
    printf("%d %lf %d\n", array[i]->index, array[i]->key, array[i]->pos);
}

void PrintHeap(HEAP *heap, ELEMENT **array){
  printf("Capacity = %d, size = %d\n", heap->capacity, heap->size;

  for (int i = 1; i <= heap->size, i++)
    printf("H[%d] = %d\n", i, heap->H[i]);
}
