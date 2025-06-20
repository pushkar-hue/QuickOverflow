/****************************************************
 *
 * @headerfile       commands.h
 *
 * @author           Aryan Karamtoth (SpaciousCoder78)
 *
 * @date             Saturday, June 07 2025
 *
 * @brief            QuickOverflow's Command Functions
 *
 ****************************************************/




#ifndef COMMANDS_H
#define COMMANDS_H

#include<stdio.h>
#include<unistd.h>
/*
  Function Declarations for builtin shell commands:
 */
int quickoverflow_search(char **args); //open search
int quickoverflow_help(char **args); //help command
int quickoverflow_quit(char **args); //exit command
int quickoverflow_about(char **args); //about command
int quickoverflow_cd(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "search", //search command
  "help", //help command
  "quit", //exit command
  "about",
  "cd",
};

int (*builtin_func[]) (char **) = {
  &quickoverflow_search, //search directory
  &quickoverflow_help, //help command
  &quickoverflow_quit, //exit command
  &quickoverflow_about, //about
  &quickoverflow_cd, //change dir
};

int quickoverflow_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
***********************************Builtin function implementations*************************************
*/

//Update 2.0.0 - Added cd for directory traversal

//***************************************chdir*********************************************** */
int quickoverflow_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "QuickOverflow : expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("QuickOverflow");
    }
  }
  return 1;
}

//***************************************sofsearch*********************************************** */
//function for calling the python files for searching
int quickoverflow_search(char **args)
{
  
  //Update 3.0.0 - Removed Python API and enabled directly calling from anywhere in the OS
  //Now uses PyInstaller to generate Python Executable to run anywhere
  system("search");
  
  return 1;
}

//***************************************tell*************************************************


//*****************************************sos*********************************************** */
int quickoverflow_help(char **args){
  int i;
  printf("             \n"
" _____       _      _    _____                 __ _               \n"
"|  _  |     (_)    | |  |  _  |               / _| |              \n"
"| | | |_   _ _  ___| | _| | | |_   _____ _ __| |_/| | _____      __\n"
"| | | | | | | |/ __| |/ / | | \\ \\ / / _ \\ '__|  _| |/ _ \\ \\ /\\ / /\n"
"\\ \\/' / |_| | | (__|   <\\ \\_/ /\\ V /  __/ |  | | | | (_) \\ V  V / \n"
" \\_/\\_\\\\__,_|_|\\___|_|\\_\\\\___/  \\_/ \\___|_|  |_| |_|\\___/ \\_/\\_  \n"
"                        \n");
  printf("---------------------------------Version 3.0.0----------------------------\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < quickoverflow_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  return 1;
}


//*****************************************leave*********************************************** */
int quickoverflow_quit(char **args){
  return 0;
}

//**************************************about (ofc credits)************************************* */

int quickoverflow_about(char **args){
    printf("              \n"
" _____       _      _    _____                 __ _               \n"
"|  _  |     (_)    | |  |  _  |               / _| |              \n"
"| | | |_   _ _  ___| | _| | | |_   _____ _ __| |_/| | _____      __\n"
"| | | | | | | |/ __| |/ / | | \\ \\ / / _ \\ '__|  _| |/ _ \\ \\ /\\ / /\n"
"\\ \\/' / |_| | | (__|   <\\ \\_/ /\\ V /  __/ |  | | | | (_) \\ V  V / \n"
" \\_/\\_\\\\__,_|_|\\___|_|\\_\\\\___/  \\_/ \\___|_|  |_| |_|\\___/ \\_/\\_  \n"
"                                                                                                                               \n");
    printf("Version:  3.0.0\n");
    printf("License: GNU GPL-3 License\n");
    printf("Author: Aryan Karamtoth (SpaciousCoder78)\n");
    printf("Author Email: aryankmmiv@outlook.com\n");
    printf("Supported Operating Systems: Linux\n");
    printf("Github Repository: https://github.com/SpaciousCoder78/QuickOverflow\n");
    printf("Github Issues: https://github.com/SpaciousCoder78/QuickOverflow/issues\n");
}


#endif
