/*
This parser allows a user to insert parameters to launch the program directly as a command.
However, this will be the last part of the project.
*/

#ifndef CMDP
#define CMDP

// Function that parse given parameters for the agenda program
int parameter_parser(char *cm){
  switch(cm){
  case 'p':
    print_today_list();
    break

  default:
      break;
}

#endif
