#include <stdio.h>
#include <stflib.h>
#include "Task.h"
#include "heap_task.h"

struct heap{
  Task *tsk;
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
  h->tsk = malloc(maxN*sizeof(Task));
  h->heapsize = 0;
  return h;
}




/* Function name: HEAPfill 
   ---------------------------------------
   Insert a new item task in the heap
 */
void HEAPfill(Heap h, Task tsk){
  int i;
  i = h->heapsize++;
  h->tsk = tsk;
  return;
}



/* Function name: HEAPdisplay 
   ---------------------------------------
   Display items in a heap
 */
void HEAPdisplay(Heap h){
  int i;
  for (i = 0; i < h->heapsize; i++)
    TASKshow(h->tsk[i]);
}


/* Function name: HEAPify
   ---------------------------------------
   
 */

void HEAPify(Heap h, int i){
  int l, r, largest;
  l = LEFT(i);
  r = RIGHT(i);

  if((l < h->heapsize) && (TASKgreater(h->tsk[l],))
}
