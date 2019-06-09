#ifndef HEAP
#define HEAP

// TODOOOO: Update function names in the agenda.c file

typedef struct heap *Heap;

Heap HEAPinit(int maxNx);
void HEAPfill(Heap HP, Task tsk);
void HEAPsort(Heap HP);
void HEAPdisplay(Heap HP);

#endif
