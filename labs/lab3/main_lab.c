#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <unistd.h>

#define NUM_THREADS 8
#define VEC_SIZE 1024

int *vec;

void * soma_no_vetor(int pos) {
  int i = pos;
  for (;i<pos+(VEC_SIZE/NUM_THREADS);i++) {
    vec[VEC_SIZE]+=vec[i];
    printf("Somando na thread %d\n",pos);
  }
  pthread_exit(NULL); /*not necessary*/ 
} 
int main(void) {
  int segmento;
  // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
  segmento = shmget(IPC_PRIVATE, sizeof (int)*1025, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  // // associa a memória compartilhada ao processo
  vec = (int *) shmat (segmento, 0, 0); // comparar o retorno com -1
  pthread_t threads[NUM_THREADS];

  srand(time(0));
      
  // // preencher o vetor com numeros aleatorios
  for (int i = 0;i<VEC_SIZE;i++) {
    vec[i] = rand()%256;
  }
  int index;
  for (int j=0;j<NUM_THREADS;j++) {
    index = j*(VEC_SIZE/NUM_THREADS);
    pthread_create(&threads[j],NULL,soma_no_vetor,index);
  }
	for(int k = 0; k < NUM_THREADS; k++) {
		pthread_join(threads[k], NULL);
  }
  printf("sum = %d\n",vec[VEC_SIZE]);
  shmdt(vec);
	shmctl(IPC_RMID,0,0);
  return 0;
}