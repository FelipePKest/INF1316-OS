#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char prog[] = "/bin/cat";
  execv(prog,argv);
  return 0;
}