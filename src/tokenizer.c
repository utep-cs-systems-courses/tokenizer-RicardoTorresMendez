#include <stdio.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c){
  if( c == ' ' || c == '\t' ){ return 1; }//space and tab
  return 0;
}



/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  if( c == ' ' || c == '\t' ){ return 0; }//space and tab
  return 1;
}



/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */

char *word_start(char *str){
  char *p = str;
  while( space_char( *p ) && *p != '\0' ){
    p = p + 1;
  }
  return p;
}



/* Returns a pointer terminator char following *word */

char *word_terminator(char *word){
  char *p = word;
  while( non_space_char( *p ) && *p != '\0' ){
    p = p + 1;
  }
  return p;
}



/* Counts the number of words in the string argument. */

int count_words(char *str){
  char *p = str;
  short count = 0;

  p = word_start(p);
  for(count = 0; *p != '\0'; count++){
    p = word_start( p );
    if( *p == '\0' ){ return count; }
    p = word_terminator( p );
    
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){

}



/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str){

}



/* Prints all tokens. */

void print_tokens(char **tokens){

}



/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens){

}


