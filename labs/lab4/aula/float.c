#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void errorHandler(int sinal);

int main(void) {
  int a,b,c;
  signal(SIGFPE, errorHandler);
  puts("Insira um float"); 
  scanf("%d",&a);
  puts("Insira outro float");
  scanf("%d",&b);
  c = a+b;
  printf("Soma =%d\n",c);
  c = a-b;
  printf("Subtracao =%d\n",c);
  c = a*b;
  printf("Multiplicacao =%d\n",c);
  c = a/b;
  printf("Divisao= %d\n",c);
  return 0;
}

void errorHandler(int sinal) {
  puts("Gerou erro");
  exit(0);
}