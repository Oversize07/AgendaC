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
