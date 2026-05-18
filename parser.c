#include "include/parser.h"
#include <stdio.h>

void addToken(TokenArray *arr, Token t) {
  if(arr->size >= arr->capacity) {
    size_t tempCapacity = 2 * arr->capacity;
    arr->data = realloc(arr->data, tempCapacity * sizeof(Token));
    if(arr->data) /*if successfull*/ {
      arr->capacity = tempCapacity;
    } else {
      fprintf(stderr, "Failed to reallocate memory\n");
      exit(0);
    }
  }
  arr->data[arr->size++] = t;
}

void initToken(TokenArray *arr) {
  arr->data = malloc(sizeof(Token) * 4);
  if(!arr->data) /*if unsuccessful*/ {
      fprintf(stderr, "Failed to allocate memory\n");
      exit(0);
  }
  arr->size = 0;
  arr->capacity = 4;
}

//must receive a string containing user's commands or tokens themselves
void Tokenize(char *iString) {
 //assuming we get user string itself
  TokenArray tokens;
  initToken(&tokens);

  char *buffer = strtok(iString, " ");

  for(int i = 0; buffer; i++) {
    char *temp = malloc(strlen(buffer) +1);
    strcpy(temp, buffer);
    addToken(&tokens, (Token){.token = temp, .size = strlen(buffer),.type = TOKEN_WORD});
      printf("Token Added Details:\n\tToken = %s\n\tsize = %lu\n\tType = %s\n", buffer, strlen(buffer), "TOKEN_WORD");
    buffer = strtok(NULL, " ");
  }
  //freeup tokens
  for(int i = 0; i < tokens.size; i++){
      free(tokens.data[i].token);
  }
  free(tokens.data);
}

