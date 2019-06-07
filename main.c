#include <stdio.h>
#include "agenda.h"
#include "command_parser.c"


int main(int argc, char *argv){
  if(argc > 1) parameter_parser(argv);
  menu();
}

