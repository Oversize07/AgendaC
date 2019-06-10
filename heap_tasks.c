#include <stdio.h>
#include <stflib.h>
#include "Task.h"
#include "heap_task.h"

struct heap{
  Date *dte;
  int heapsize;
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
   Function that find a item given the task id.
   It scan the elements of the vector that hold the tasks
 */
Task HEAPfind(Heap h, int id){
  int i;
  for (i = 0; i < h->heapsize; i++)
    if (h->dte[i].dateId == id)
      return h->dte[i];
  return NULL; // No task found with that id
}
