
#include <stdio.h>
#include "Task.h"



/* Function name: NEWtask 
   ---------------------------------------
   Creates a new task
 */

Task NEWtask(int id, char *d){

}



/* Function name: TASKdelete 
   ---------------------------------------
   Deletes a task
 */
int TASKdelete(int id){

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
