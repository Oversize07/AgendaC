/*
  This file contains the datastructure for the daily list of tasks.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Task.h"


// Struct that contains statistical data about tasks in a day
typedef struct{
  int HowManyTasks;
  int HowManyTasksCompleted;
  int HowManyTasksUndone;
}statistical_data;

// List info
typedef struct{
  link head;
  link tail;
  statistical_data std; // Statistical data
}lst;

// Struct that contains a day 
struct dd{
  int day;
  int month;
  int year; 
  lst tsk;   // List that contains tasks
  int dateId; // Day identifier
};


// Represent a single node task
struct Task{
  int taskId;  // Task identifier, it also identify the priority
  char *taskName;  // Task name  
  char *taskDescription; // Task description
  int done;    // Flag that checks if the task is complete-
  link next;   // Pointer to the next element of the list
};


/* Function name: NEWtask 
   ---------------------------------------
   Creates a new node task
*/

static link NEWtask(link next, int id, char *n, char *d){
  link x = malloc(sizeof *x);
  if (x == NULL) return NULL;

  x->taskId = id;
  x->taskName = strdup(n);
  x->taskDescription = strdup(d);
  x->done = 0;
  x->next = next;
  return x;
}


/* Function name: NEWdate 
   ---------------------------------------
   Creates a new date
 */

DATE NEWdate(int id, char *d, int dd, int mm, int yyyy){
  DATE x = malloc(sizeof *x);
  if (x == NULL) return NULL;
  
  x->dateId = id;
  x->day = dd;
  x->month = mm;
  x->year = yyyy;
  // Set statistical data
  x->tsk.std.HowManyTasks = 0;
  x->tsk.std.HowManyTasksCompleted = 0;
  x->tsk.std.HowManyTasksUndone = 0;
  x->tsk.head = NULL;
  x->tsk.tail = NULL;
  return x;
}



/* Function name: TASKinsert 
   ---------------------------------------
   Insert a new task in the list
 */
void TASKinsert(DATE dat, int id, char *n, char *d ){
  dat->tsk.tail = NEWtask(NULL, id,n,d); // Insert in head
  // Update statistical data
  dat->tsk.std.HowManyTasks++;
  dat->tsk.std.HowManyTasksUndone++;
  return;
}



/* Function name: DATEdelete 
   ---------------------------------------
   Deletes a task given by input (Find is a HEAP function)
   
*/
void Datedelete(DATE t){
  link j;

  // Delete nodes from list (from head)
  for(j = t->tsk.head; t->tsk.head->next == NULL; j = t->tsk.head){   
    t->tsk.head = t->tsk.head->next;
    TASKdelete(j);
  }
  free(t);
  return;
}


/* Function name: TASKdelete 
   ---------------------------------------
   Deletes a task given by input (Find is a HEAP function)
 */
void TASKdelete(link t){
  free(t->taskName);
  free(t->taskDescription);
  free(t);
  return;
}



/* Function name: FINDtask 
   ---------------------------------------
   Find a task in the list given the id and the list header
 */
link FINDtask(link head, int id){
  link t;
  for(t = head; t->next == NULL;t = t->next )
    if (t->taskId == id)
      return t;
  return NULL;
}


/* Function name: TASKupdate
   ---------------------------------------
   Updates the info of a task like the description or the id
   Note: decide where to do  
   TODO: implement the function that allows to move a task from
   a day to another
 */
int TASKupdate(link head, int id){
  link x = TASKfind(head, id);
  
  return 0;
}



/* Function name: TASKshow
   ---------------------------------------
   Prints the name and the description of a task
 */
 void TASKshow(link head, int id){
   link x = FINDtask(head, id);
   if(x == NULL){
     printf("\nNo task found with that Id..\n");
     return;
   }
   printf("\n------------------------------\n");
   printf("Task Id:%d\n",x->taskId);
   printf("Task name: %s\n",x->taskName);
   printf("Task description:\n%s\n",x->taskDescription);
   printf("Done? %d\n",x->done);
   printf("------------------------------\n\n");
   return;
 }


/* Function name: TASKgreater
   ---------------------------------------
   Return if the task t1 has higher priority
 */
int TASKgreater(link t1, link t2){
  return (t1->taskId > t2->taskId);
}



/* Function name: TASKgreater
   ---------------------------------------
   Store in a file all tasks in a date plus the data info
 */
FILE *DATEstore(FILE *fp, DATE t){
  fprintf(fp,"%d %d %d\n",t->dateId,t->day,t->month,t->year); // Date info in a row
  link j = dte->tsk.head;
  for(; j->next == NULL; j = j->next){   
    fprintf(fp,"%d %s %s %d\n",j->taskId,j->taskName,j->taskDescription,j->done);
  
 
}
