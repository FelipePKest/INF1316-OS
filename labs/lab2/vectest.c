#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int *p = (int *)malloc(sizeof(int)*900);
  for (int i = 0;i<300;i++) {
    p[i] = rand();
    // *(p+(300*sizeof(int))+(sizeof(int)+i)) = rand();
  }
  return 0;
}


