/*
  Ryan Drazek, ID:123695485
*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

static void exchange(HEAP *pHeap, ELEMENT **V, int a, int b){
	int temp = pHeap->H[a];
	pHeap->H[a] = pHeap->H[b];
	pHeap->H[b] = temp;

	V[pHeap->H[a]]->pos = a;
	V[pHeap->H[b]]->pos = b;
}

void Heapify(HEAP *pHeap, ELEMENT **V, int i){
	while(1){
		int left = 2 * i;
		int right = left + 1;
		int smallest = i;

		if (left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key)
			smallest = left;

		if (right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key)
			smallest = right;

		if (smallest == i)
			break;

		exchange(pHeap, V, i, smallest);
		i = smallest;
	}
}

void BuildHeap(HEAP *pHeap, ELEMENT **V){
	for (int i = pHeap->size / 2; i >= 1; i--)
		Heapify(pHeap, V, i);
}

ELEMENT* ExtractMin(HEAP *pHeap, ELEMENT **V){
	if (pHeap->size == 0)
		return NULL;

	int rootindex = pHeap->H[1];
	ELEMENT *minElement = V[rootindex];

	exchange(pHeap, V, 1, pHeap->size);

	minElement->pos = 0;
	pHeap->size--;

	if(pHeap->size > 0)
		Heapify(pHeap, V, 1);

	return minElement;
}

void DecreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey){
	if (index < 1 || index > pHeap->capacity)
		return;

	if (V[index]->pos == 0)
		return;

	if(newKey >= V[index]->key)
		return;

	V[index]->key = newKey;

	int pos = V[index]->pos;

	while(pos > 1){
		int par = pos / 2;

		if(V[pHeap->H[par]]->key <= V[pHeap->H[pos]]->key)
			break;

		exchange(pHeap, V, pos, par);
		pos = par;
	}
}

void InsertHeap(HEAP *pHeap, ELEMENT **V, int index){
	if (index < 1 || index > pHeap->capacity)
		return;

	if (V[index]->pos != 0)
		return;

	pHeap->size++;
	int current = pHeap->size;

	pHeap->H[current] = index;
	V[index]->pos = current;

	while(current > 1){
		int par = current / 2;

		if(V[pHeap->H[par]]->key <= V[pHeap->H[current]]->key)
			break;

		exchange(pHeap, V, current, par);
		current = par;
	}
}

void PrintArray(ELEMENT **V, int n){
	for(int i = 1; i <= n; i++)
		printf("%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
}

void PrintHeap(HEAP *pHeap, ELEMENT **V){
	printf("Capacity = %d, size = %d\n", pHeap->capacity, pHeap->size);

	for (int i = 1; i <= pHeap->size; i++)
		printf("H[%d] = %d\n", i, pHeap->H[i]);
}
