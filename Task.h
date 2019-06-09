// TODOOOO: Update function names in the agenda.c file

/***********************************************************************
 *                            DATA DEFINITION                          *
 ***********************************************************************/

// Represent the day dd/mm/yyyy
typedef struct{
  int day;
  int month;
  int year;  
}Date;

// Represent a single task
typedef struct{
  Date date;
  int taskId;     // Task identifier, it also identify the priority
  char *taskDescription; // Task description
  int done;    // Flag that checks if the task is complete-
}Task;

Task NEWtask(daily_agenda DA);
int TASKdelete(int id);
Task TASKfind(int id);

// Called after a find in the heap
int TASKupdate(int id); 
void TASKshow(Task t);
int TASKgreater(Task t1, Task t2);
