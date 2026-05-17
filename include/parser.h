#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>

typedef enum {
  TOKEN_WORD,
  TOKEN_PIPE,
  TOKEN_EOF,
}TokenType;


typedef struct Token{
  char *token;
  size_t size;
  TokenType type;
}token_t;

void Tokenize();


#endif //PARSER_H
