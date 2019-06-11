/*

  This file contains the datastructure for the daily list of tasks.
*/
#include <stdio.h>
#include <string.h>
#include "Task.h"

// Struct that contains a day 
struct dd{
  int day;
  int month;
  int year; 
  lst tsk;   // List that contains tasks
  int dateId; // Day identifier
};


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


// Pointer to a task
typedef struct Task *link; 

// Represent a single node task
struct Task{
  int taskId;  // Task identifier, it also identify the priority
  char *TaskName;  // Task name  
  char *taskDescription; // Task description
  int done;    // Flag that checks if the task is complete-
  link next;   // Pointer to the next element of the list
};


/* Function name: NEWtask 
   ---------------------------------------
   Creates a new node task
*/

static Task NEWtask(link next, int id, char *n, char *d){
  link x = malloc(sizeof *x);
  if (x == NULL) return NULL;

  x->taskId = id;
  x->name = strdup(n);
  x->taskDescription = strdup(d);
  x->done = 0;
  x->next = next;
  return x;
}


/* Function name: NEWdate 
   ---------------------------------------
   Creates a new date
 */

static Task NEWdate(int id, char *d, int dd, int mm, int yyyy){
  DATE x = malloc(sizeof *x);
  if (x == NULL) return NULL;
  
  x->dateId = id;
  x->date.day = dd;
  x->data.moth = mm;
  x->data.year = yyyy;
  x->tsk = NULL;
  // Set statistical data
  x->statistical_data.HowManyTasks = 0;
  x->statistical_data.HowManyTasksCompleted = 0;
  x->statistical_data.HowManyTasksUndone = 0;
  x->tsk = NULL;
  return x;
}



/* Function name: TASKinsert 
   ---------------------------------------
   Insert a new task in the list
 */
void TASKinsert(Date d, int id, char *n, char *d ){
  d->tsk.tail = NEWtask(NULL, id,n,d); // Insert in head
  // Update statistical data
  d->tsk.statistical_data.HowManyTasks++;
  d->tsk.statistical_data.HowManyTasksUndone++;
  return;
}



/* Function name: DATEdelete 
   ---------------------------------------
   Deletes a task given by input (Find is a HEAP function)
   
*/
static void Datedelete(DATE t){
  link j;

  // Delete nodes from list (from head)
  for(j = t->tsk; t->tsk->next == NULL; j = t->tsk){   
    t->tsk = t->tsk->next;
    TASKdelete(j);
  }
  free(t);
  return;
}

/* Function name: TASKdelete 
   ---------------------------------------
   Deletes a task given by input (Find is a HEAP function)
 */
static void TASKdelete(link t){
  free(t->TaskName);
  free(t->TaskDescription;
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
int TASKupdate(link t, int id){
  link x = TASKfind(t, id);
  
  return 0;
}



/* Function name: TASKshow
   ---------------------------------------
   Prints the name and the description of a task
 */
void TASKshow(Task t);


/* Function name: TASKgreater
   ---------------------------------------
   Return if the task t1 has higher priority
 */
int TASKgreater(Task t1, Task t2){
  return (t1.taskId > t2.taskId);
}



