#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  //int maxPriority = pq->heapArray[0].priority;
  
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){
  pq->heapArray[pq->size + 1].data = data;
  pq->heapArray[pq->size + 1].priority = priority;
  for (int i = 0 ; i < pq->capac ; i++)

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *h = malloc (sizeof(Heap));
  h->heapArray = (heapElem *) malloc (sizeof(heapElem *));
  h->capac = 3;
  h->size = 0;
   return h;
}
