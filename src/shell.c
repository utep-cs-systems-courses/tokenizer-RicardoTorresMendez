
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
#include <string.h>

char *str_cpy(char* inStr);
int string_to_int( char* str );

int main(){

  printf("%s","Entered text to history, $=history, $#=tokenize #th element, $_=free history, q=quit\n");

  // -------------------------------------------------------------- //

  List *history = init_history();

  while( 1 ){

    char str[50];

    printf("%s", ">");
  
    fgets(str, 50, stdin);

    if( str[0] == 'q' && str[1] == '\n' ){ return 0; }//quit
    if( str[0] == '$' ){
      if( str[1] == '#' ){//tokenize #th string
	int id = string_to_int( str );
	char *elem = get_history(history, id );
	char **tokens = tokenize( elem );
	print_tokens( tokens );
	free_tokens( tokens );
      }
      else if( str[1] == '_' ){//free history
	free_history( history );
      }
      else{//print history
	print_history( history );
      }
    }
    else{//add to history
      add_history( history, str_cpy(str) );
    }
  }
  
  // -------------------------------------------------------------- //

  return 0; 
  
}

int string_to_int(char *str){
  int number = 0;
  int i = 2;
  while(str[i] != '\0' && str[i] != '\n' ){
    number = number * 10;
    number = number + (str[i] - '0');
    i++;
  }
  return number;
}

char *str_cpy(char *inStr){

  //we add 1 to account for the escape character

  char *str_copy = (char*) malloc( 50 );

  int i;
  for(i=0; *inStr != '\0' && *inStr != '\t'; i++){

    *str_copy = *inStr;

    str_copy++;

    inStr++;

  }

  *str_copy = '\0';

  return str_copy - i;

}
