// TODOOOO: Update function names in the agenda.c file

/***********************************************************************
 *                            DATA DEFINITION                          *
 ***********************************************************************/

// Represent the day dd/mm/yyyy
typedef struct dd *DATE;
typedef struct Task *link;
void TASKinsert(DATE dat, int id, char *n, char *d);
void TASKdelete(link t);
link TASKfind(link head,int id);

// Called after a find in the heap
int TASKupdate(link head, int id); 
void TASKshow(link head, int id);
int TASKgreater(link t1, link t2);

DATE NEWdate(int id, char *d, int dd, int mm, int yyyy);
FILE *DATEstore(FILE fp,DATE dte);
void Datedelete(DATE t);
