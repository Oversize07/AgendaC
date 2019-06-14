/*
  This file contains the heap that contains the dates 
*/

#include <stdio.h>
#include <stdlib.h>
#include "Task.h"
#include "heap_task.h"

struct heap{
  Date *dte;
  int heapsize;
  int heapsizeMax;
};


// Left child
int LEFT(int i){
  return (i*2 +1);
}

// Right child
int RIGHT(int i){
  return (i*2 + 2);
}

// Father
int PARENT(int i){
  return ((i-1)/2);
}



/* Function name: HEAPinit 
   ---------------------------------------
   Creation of the Heap
   
   Input: 
     - maxN: number of tasks 
   
 */
Heap HEAPinit(int maxN){
  Heap h;
  h = malloc(sizeof *h);
  h->dte = malloc(maxN*sizeof(Task));
  h->heapsize = 0;
  return h;
}




/* Function name: HEAPfill 
   ---------------------------------------
   Insert a new item task in the heap
 */
void HEAPfill(Heap h, Date dte){
  int i;
  i = h->heapsize++;
  h->dte = dte;
  return;
}



/* Function name: HEAPdisplay 
   ---------------------------------------
   Display items in a heap
 */
void HEAPdisplay(Heap h){
  int i;
  for (i = 0; i < h->heapsize; i++)
    TASKshow(h->dte[i]);
}


/* Function name: swap  
   ---------------------------------------
   Swap two items in a heap
 */
void swap(Heap h, int i, int j){
  int t = h->dte[i];
  h->dte[i] = h->dte[j];
  h->dte[j] = t;
  return;
}


/* Function name: HEAPify
   ---------------------------------------
   Modify the position of items in a vector recursively to create a heap 
   (Where by definition the father must be greater than the two sons)
 */

void HEAPify(Heap h, int i){
  int l, r, largest;
  l = LEFT(i);
  r = RIGHT(i);

  if((l < h->heapsize) && (TASKgreater(h->dte[l],)))
     largest = l;
  else
     largest = i;
  if((r<h->heapsize) && (TASKgreater(h->dte[r], h->dte[largest]) ))
       largest = r;
  if(largest != i){
       swap(h,i,largest);
       HEAPify(h, largest);
  }
  return;
}



/* Function name: HEAPsort  
   ---------------------------------------
   
 */
void HEAPbuild(Heap h){
  int i;
  for (i = (h->heapsize)/2-1; i >= 0; i--)
    HEAPify(h,i);
  return;
}

/* Function name: HEAPsort  
   ---------------------------------------
   
 */
void HEAPsort(Heap h){
  int i,j;
  HEAPbuild(h);
  j = h->heapsize;
  for  (i = h->heapsize-1; i > 0; i--){
    Swap(h,0,i);
    HEAPify(h,0);
  }
  h->heapsize = j;
  return;
}




/* Function name: HEAPfind
   ---------------------------------------
   Function that find a item given the date id.
   It scan the elements of the vector that hold the dates 
 */
link HEAPfind(Heap h, int id){
  int i;
  for (i = 0; i < h->heapsize; i++)
    if (h->dte[i].dateId == id)
      return h->dte[i];
  return NULL; // No task found with that id
}




/* Function name: HEAPcheckSize
   ---------------------------------------
   Function that checks the size of the heap. If it is almost full,
   it reallocate to get a new size twice as big 
 */
Heap HEAPcheckSize(Heap HP){
  if (HP->heapsize == HP->heapsize){
    realloc(HP,sizeof(HP->heapsizeMax*2));
    HP->heapsizeMax *=2;
  }
  return HP;
}




/* Function name: HEAPcheckSize
   ---------------------------------------
   Store the Heap in a file
*/
void HEAPstore(FILE *fp, Heap HP){
  if (fp == NULL) {printf("\nOps, could not find the file.\n"); return;}
  int i;
  fprintf(fp,"%d %d\n",HP->heapsize, HP->heapsizeMax); // Writing dimensions

  // Writing elements
  for(i = 0; i<HP->heapsize;i++)
    fp = DATEstore(fp,HP); // Leave the date print with tasks to the Task module

  return;
}
