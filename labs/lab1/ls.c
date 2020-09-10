#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char* arr[] = {"ls",NULL};
  execv("/bin/ls", arr);
  return 0;
}