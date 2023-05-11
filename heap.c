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
  if (pq->size == 0) return NULL;
  else return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority) {
  if (pq->size == pq->capac) {
    pq->capac = (pq->capac * 2) + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }

  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;

  int i = pq->size;
  while (i > 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority) {
    heapElem aux = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = pq->heapArray[i];
    pq->heapArray[i] = aux;
    i = (i-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){
  if (pq->size == 0) return;
  pq->heapArray[0] = pq->heapArray[pq->size-1];
  pq->size--;

  int i = 0;
  while (2*i + 1 < pq->size) {
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;
    int largest_child = left_child;

    if (right_child < pq->size && pq->heapArray[right_child].priority > pq->heapArray[left_child].priority) {
      largest_child = right_child;
    }

    if (pq->heapArray[largest_child].priority > pq->heapArray[i].priority) {
      heapElem temp = pq->heapArray[largest_child];
      pq->heapArray[largest_child] = pq->heapArray[i];
      pq->heapArray[i] = temp;
      i = largest_child;
    } else {
      break;
    }
  }
  

}

Heap* createHeap(){
  Heap *h = malloc (sizeof(Heap));
  h->heapArray = malloc (3 * sizeof(heapElem));
  h->capac = 3;
  h->size = 0;
   return h;
}
