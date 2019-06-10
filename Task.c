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
  Task *tsk;   // List that contains tasks
  int dateId; // Day identifier
  statistical_data std; // Statistical data 
};


// Struct that contains statistical data about tasks in a day
typedef struct{
  int HowManyTasks;
  int HowManyTasksCompleted;
  int HowManyTasksUndone;
}statistical_data;

// Represent a single task
typedef struct{
  int taskId;     // Task identifier, it also identify the priority
  char *taskDescription; // Task description
  int done;    // Flag that checks if the task is complete-
}Task;


/* Function name: NEWtask 
   ---------------------------------------
   Creates a new task
   TODO: this should be a newNode in a list
*/

static Task NEWtask(int id, char *d, int dd, int mm, int yyyy){
  Task x = malloc(sizeof *x);
  if (x == NULL) return NULL;

  x->taskId = id;
  x->taskDescription = strdup(d);
  x->done = 0;
  return x;
}


/* Function name: NEWdate 
   ---------------------------------------
   Creates a new date
 */

static Task NEWdate(int id, char *d, int dd, int mm, int yyyy){
  Date x = malloc(sizeof *x);
  if (x == NULL) return NULL;

  
  x->taskId = id;
  x->taskDescription = strdup(d);
  x->date.day = dd;
  x->data.moth = mm;
  x->data.year = yyyy;

  // Set statistical data
  x->statistical_data.HowManyTasks = 0;
  x->statistical_data.HowManyTasksCompleted = 0;
  x->statistical_data.HowManyTasksUndone = 0;
  x->tsk = NULL;
  return x;
}



/* Function name: TASKdelete 
   ---------------------------------------
   Deletes a task given by input (Find is a HEAP function)
 */
static void TASKdelete(Task t){
  return free(t);
  
}



/* Function name:  
   ---------------------------------------
   
 */
Task FINDtask(int id){

}


/* Function name:  
   ---------------------------------------
   
 */
int TASKupdate(int id); 



/* Function name:  
   ---------------------------------------
   
 */
void TASKshow(Task t);


/* Function name: TASKgreater
   ---------------------------------------
   Return if the task t1 has higher priority
 */
int TASKgreater(Task t1, Task t2){
  return (t1.taskId > t2.taskId);
}



