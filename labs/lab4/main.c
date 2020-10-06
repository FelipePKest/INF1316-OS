#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
  int pids[] = {};
  for (int i = 0;i<4;i++) {
    if (fork() == 0) {
    // filhos executandos indefinidamente
      sleep(2);
    }
  } 

  for (int i = 0; i<10; i++) {
    // trocar contextos 

  }

  for (int i = 0;i<4;i++) {
    // matar processos
  }

  return 0;
}