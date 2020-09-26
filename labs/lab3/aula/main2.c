#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 2

int global_variable = 0;

void * cont_crescente(void * thread_id) {
    printf("%d: Crescente!\n", thread_id);
    /* do other things */
    for (int i = 0; i<20; i++) {
        printf("%d GLOBAL = %d\n",i,global_variable++);
        sleep(1);
    }
    pthread_exit(NULL); /*not necessary*/ 
}

void * cont_decrescente(void * thread_id) {
    printf("%d: Hello Decrescente!\n", thread_id);
    /* do other things */
    for (int i = 30; i>0; i--) {
        printf("%d GLOBAL = %d\n",i,global_variable--);
        sleep(2);
    }
    pthread_exit(NULL); /*not necessary*/ 
}
 
int main(void) {
    pthread_t threads[NUM_THREADS];
    int t;
    for(t=0;t < NUM_THREADS;t++) {
        printf("Creating thread %d\n", t);
        switch (t) {
        case (0):
            pthread_create(&threads[t], NULL, cont_crescente,(void *) t);
        case (1):
            pthread_create(&threads[t], NULL, cont_decrescente, (void *) t);
        }
    }
    for(t=0; t < NUM_THREADS; t++)
    pthread_join(threads[t],NULL); /* wait for all the threads to terminate*/
    return 0;
} 