#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <string.h>
typedef enum {
  TOKEN_WORD,
  TOKEN_PIPE,
  TOKEN_EOF,
}TokenType;

typedef struct {
  char *token;
  size_t size;
  TokenType type;
} Token;

typedef struct {
  Token *data;
  size_t size;
  size_t capacity;
} TokenArray;

typedef struct Command{
  char **argv;
  int argc;
  char *infile;
  char *outfile;
}command_t;

void Tokenize(char *iString);
//void extractCommandsFromToken(token_t *tokens);
void addToken(TokenArray *arr, Token t);
void initToken(TokenArray *arr);
#endif //PARSER_H
