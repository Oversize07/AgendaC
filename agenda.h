#ifndef AGENDA
#define AGENDA
#include "agenda.c"

#define WELCOME_MESSAGE "Welcome to the agenda v. 0\n"

//Error costants
#define ERROR_ALLOCATION 1001
#define ERROR_FILE_NOT_FOUND 1002

// Other costants
#define MAX_DESCRIPTION_LENGTH 1024
#define MAX_FILE_NAME 32
/***********************************************************************
 *                            DATA DEFINITION                          *
 ***********************************************************************/

typedef struct daag *daily_agenda;


// Statistical data about the agenda
typedef struct{

}statistical_data;
  


/***********************************************************************
 *                            PROTOTIPES                               *
 ***********************************************************************/
void menu();
void error_handler(int e);
daily_agenda agenda_init();
daily_agenda agenda_init_from_file(FILE *fp);

#endif
