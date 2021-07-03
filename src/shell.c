#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){

  printf("%s", "Please enter the string you wish to tokenize");

  // -------------------------------------------------------------- //
  
  printf("%s", "\n>");

  char str[50];

  fgets(str, 50, stdin);
  
  printf("%s", "\n");

  char **tokens = tokenize( str );

  print_tokens(tokens);
  
  // -------------------------------------------------------------- //
  
  return 0; 
  
}
