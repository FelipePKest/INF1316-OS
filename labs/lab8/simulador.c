#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <math.h>

typedef struct frame  {
    int page;
    char M;
    struct timeval lastUse;
} Frame;

typedef struct page {
    int frame;
    char inMemory;
} Page;

struct main {
    /* data */
};


int calculate_shift_value(int size) {
    int s = 10;
    while (size != 1) {
        s++;
        size >>= 1;
    }
    return s;
}

int main(int argc, char * argv[]) {
    // puts("Hello WOrld0");
    // int * page = shmget(5000,,IPC_CREAT);
    if (argc != 5) {
        puts("Argumentos errados");
        exit(-1);
    }

    char * alg = argv[1];
    char * filename = argv[2];
    int tam_pag = atoi(argv[3]);
    int tam_mem = atoi(argv[4]);
    char rw;
    unsigned int addr;


    FILE * file = fopen(filename,"r");

    if (file == NULL) {
        puts("File not found");
        exit(-1);
    }

    while (fscanf(file, "%x %c ", &addr, &rw) == 2) {
        
    }
    // if (fscanf(file, "%x %c ", &addr, &rw) == 2) {
    //     printf("%x %c\n",addr, rw);
    // }
    int s = calculate_shift_value(tam_pag);
  
    return 0;
}