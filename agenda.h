#ifndef AGENDA
#define AGENDA
#include "agenda.c"


/***********************************************************************
 *                            PROTOTIPES                               *
 ***********************************************************************/
void menu();
void error_handler(int e);
daily_agenda agenda_init();
Task NEWtask(int id, char *d);
int DELtask(int id);
Task FINDtask(int id);
int print_today_list();

#endif
