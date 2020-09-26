#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <unistd.h>

#define NUM_THREADS 8

typedef struct args {
  int * vec;
  int index;
} Args;

void soma_no_vetor(Args * args) {
  int i = args->index;
  for (;i<(args->index+1024/NUM_THREADS);i++) {
    args->vec[1024]+=args->vec[i];
  }
}
int main(void) {
  int segmento, *p;
  // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
  segmento = shmget(IPC_PRIVATE, sizeof (int)*1025, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  // // associa a memória compartilhada ao processo
  p = (int *) shmat (segmento, 0, 0); // comparar o retorno com -1
  pthread_t threads[NUM_THREADS];

  // // srand(time(0));
      
  // // preencher o vetor com numeros aleatorios
  for (int i = 0;i<1024;i++) {
    p[i] = rand()%256;
  }
  Args * a = (Args *)malloc(sizeof(Args));
  a->vec = p;
  a->index = 0;
  for (int j=0;j<NUM_THREADS;j++) {
    a->index = j*(1024/NUM_THREADS);
    pthread_create(&threads[j],NULL,soma_no_vetor,a);
  }
	for(int k = 0; k < NUM_THREADS; k++) {
		pthread_join(threads[k], NULL);
  }
  free(a);
  shmdt(p);
	shmctl(IPC_RMID,0,0);
  return 0;
}