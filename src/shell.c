#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){

  printf("%s", "Please enter the string you wish to tokenize");

  // -------------------------------------------------------------- //
  
  printf("%s", "\n>");

  char str[50];

  fgets(str, 50, stdin);
  
  printf("%s", str);

  short count = count_words( str );

  printf("%d", count);
  
  
  // -------------------------------------------------------------- //
  
  return 0; 
  
}
