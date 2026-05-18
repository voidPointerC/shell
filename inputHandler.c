#include "include/inputHandler.h"
#include "include/parser.h"


void waitForinput(void) {
  readLine();
}

//waits for a string input
void readLine(void){
  int i = 0;
  int size = 128;
  //start with 128 chars
  char *inpString = malloc(sizeof(char) * 128);
  char c;
  while((c = getchar())) {
    if(c == '\n') break;
    inpString[i++] = c;
    void *temp;
    if(i >= size) {
        temp = realloc(inpString, size*2);
    if(temp != NULL) {
        inpString = temp;
        size *= 2;
        printf("Successfully incremented size variable to %i\n", size);
      }
    }
  }
  Tokenize(inpString);
  printf("freeing inpString\n");
  free(inpString);
}
