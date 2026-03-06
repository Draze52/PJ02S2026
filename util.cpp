/*
  Ryan Drazek, ID:123695485
*/

#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, double *key){
  if(fscanf(stdin, "%s", Word) != 1)
    return 0;

  if(strcmp(Word, "Stop") == 0) return 1;
  if(strcmp(Word, "Read") == 0) return 1;
  if(strcmp(Word, "PrintArray") == 0) return 1;
  if(strcmp(Word, "PrintHeap") == 0) return 1;
  if(strcmp(Word, "BuildHeap") == 0) return 1;
  if(strcmp(Word, "ExtractMin") == 0) return 1;
  if(strcmp(Word, "Write") == 0) return 1;

  if(strcmp(Word, "Insert") == 0){
    if(fscanf(stdin, "%lf", key) != 1)
      return 0;
    return 1;
  }

  if(strcmp(Word, "DecreaseKey") == 0){
    double newKey;
    if(fscanf(stdin, "%lf %lf", key, &newKey) != 2)
      return 0;
    key[1] = newKey;
    return 1;
  }
  
  return 0;
}
