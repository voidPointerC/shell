#include "include/inputHandler.h"



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
  char *token = strtok(inpString, " ");
  while(token) {
    puts(token);
    token = strtok(NULL, " ");
  }
  printf("freeing inpString\n");
  free(inpString);
}
