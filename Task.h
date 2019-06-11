// TODOOOO: Update function names in the agenda.c file

/***********************************************************************
 *                            DATA DEFINITION                          *
 ***********************************************************************/

// Represent the day dd/mm/yyyy
typedef struct dd *DATE;

Task TASKinsert(Date d, int id, char *n, char *d);
void TASKdelete(link t);
link TASKfind(link t,int id);

// Called after a find in the heap
int TASKupdate(int id); 
void TASKshow(Task t);
int TASKgreater(Task t1, Task t2);
