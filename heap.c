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
  
    return pq->heapArray[0];
}



void heap_push(Heap* pq, void* data, int priority){
  pq->heapArray[pq->size + 1].data = data;
  pq->heapArray[pq->size + 1].priority = priority;

  int i = pq->size;
  while (i > 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority){
    heapElem aux = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = pq->heapArray[i];
    pq->heapArray[i] = aux;
    i = (i-1)/2;
  }

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
