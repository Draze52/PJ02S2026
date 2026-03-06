/*
  Ryan Drazek, ID:123695485
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "heap.h"
#include "data_structures.h"

int main(int argc, char **argv){
	ELEMENT **V = NULL;
	HEAP *pHeap = NULL;
	int n = 0;

	char Word[100];
	double key;

	if(argc != 3){
		fprintf(stderr,
		"Usage: ./PJ2 <I-File> <O-File>\n"
		"<I-File> is the input file\n"
		"<O-File> is the output file\n");
		return 0;
	}

	while(1){

		int ret = nextInstruction(Word, &key);

		if(!ret){
			printf("Warning: Invalid instruction\n");
			continue;
		}

		if(strcmp(Word, "Stop") == 0){
			printf("Instruction: Stop\n");
			break;
		}

		if(strcmp(Word, "Read") == 0){
			printf("Instruction: Read\n");

			FILE *fp = fopen(argv[1], "r");

			if(!fp){
				fprintf(stderr, "Cannot open file %s\n", argv[1]);
				continue;
			}

			fscanf(fp, "%d", &n);

			V = (ELEMENT **) malloc((n + 1) * sizeof(ELEMENT *));

			for(int i = 1; i <= n; i++){
				V[i] = (ELEMENT *) malloc(sizeof(ELEMENT));

				V[i]->index = i;
				fscanf(fp, "%lf", &V[i]->key);
				V[i]->pos = 0;
			}

			fclose(fp);

			pHeap = (HEAP *) malloc(sizeof(HEAP));
			pHeap->capacity = n;
			pHeap->size = 0;
			pHeap->H = (int *) malloc((n + 1) * sizeof(int));

			continue;
		}

		if(strcmp(Word, "PrintArray") == 0){
			printf("Instruction: PrintArray\n");

			if(!V){
				fprintf(stderr, "Error: array is NULL\n");
			}
			else{
				PrintArray(V, n);
			}

			continue;
		}

		if(strcmp(Word, "PrintHeap") == 0){
			printf("Instruction: PrintHeap\n");

			if(!pHeap){
				fprintf(stderr, "Error: heap is NULL\n");
			}
			else{
				PrintHeap(pHeap, V);
			}

			continue;
		}

		if(strcmp(Word, "BuildHeap") == 0){
			printf("Instruction: BuildHeap\n");

			if(pHeap && V){

				for(int i = 1; i <= n; i++){
					V[i]->pos = i;
					pHeap->H[i] = i;
				}

				pHeap->size = n;

				BuildHeap(pHeap, V);
			}

			continue;
		}

		if(strcmp(Word, "Insert") == 0){
			int index = (int) key;

			printf("Instruction: Insert %d\n", index);

			if(!V || !pHeap)
				continue;

			if(index < 1 || index > n){
				fprintf(stderr, "Error: index out of bound\n");
				continue;
			}

			if(V[index]->pos != 0){
				fprintf(stderr, "Error: V[%d] already in the heap\n", index);
				continue;
			}

			InsertHeap(pHeap, V, index);

			printf("Element V[%d] inserted into the heap\n", index);

			continue;
		}

		if(strcmp(Word, "ExtractMin") == 0){
			printf("Instruction: ExtractMin\n");

			if(!pHeap){
				fprintf(stderr, "Error: heap is NULL\n");
				continue;
			}

			if(pHeap->size == 0){
				fprintf(stderr, "Error: heap is empty\n");
				continue;
			}

			ExtractMin(pHeap, V);

			continue;
		}

		if(strcmp(Word, "DecreaseKey") == 0){
			int index = (int) key;
			double newKey;

			if(fscanf(stdin, "%lf", &newKey) != 1){
				fprintf(stderr, "Error: invalid DecreaseKey parameters\n");
				continue;
			}

			printf("Instruction: DecreaseKey %d %lf\n", index, newKey);

			if(!V || !pHeap)
				continue;

			DecreaseKey(pHeap, V, index, newKey);

			continue;
		}

		if(strcmp(Word, "Write") == 0){
			printf("Instruction: Write\n");

			FILE *fp = fopen(argv[2], "w");

			if(!fp){
				fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
				continue;
			}

			for(int i = 1; i <= n; i++){
				fprintf(fp, "%d %lf %d\n",
					V[i]->index,
					V[i]->key,
					V[i]->pos);
			}

			fclose(fp);

			continue;
		}
	}

	if(V){
		for(int i = 1; i <= n; i++)
			free(V[i]);
		free(V);
	}

	if(pHeap){
		free(pHeap->H);
		free(pHeap);
	}

	return 0;
}
