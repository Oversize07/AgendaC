// TODOOOO: Update function names in the agenda.c file

/***********************************************************************
 *                            DATA DEFINITION                          *
 ***********************************************************************/

// Represent the day dd/mm/yyyy
typedef struct dd *Date;

Task NEWtask(daily_agenda DA);
void TASKdelete(Task t);
Task TASKfind(int id);

// Called after a find in the heap
int TASKupdate(int id); 
void TASKshow(Task t);
int TASKgreater(Task t1, Task t2);
