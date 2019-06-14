/*
  This is the data structure that holds the tasks.
  It use a vector with the property that the father's keys
  must be greater than the keys of the two sons.
  The use of this structural data is purely didactical, 
  no optimization purposes n'stuf.

*/


#ifndef HEAP
#define HEAP

#include "Task.h"
// TODOOOO: Update function names in the agenda.c file

typedef struct heap *Heap;

Heap HEAPinit(int maxNx);
Heap HEAPcheckSize(Heap HP);
void HEAPfill(Heap HP, link dte);
void HEAPsort(Heap HP);
void HEAPdisplay(Heap HP);
void swap(Heap h, int i, int j);
void HEAPbuild(Heap h);
void HEAPsort(Heap h);
link HEAPfind(Heap h, int id);
void HEAPstore(FILE *fp, Heap HP);
#endif
