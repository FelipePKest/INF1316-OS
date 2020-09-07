#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exercise_one(void);
void exercise_two(void);
void ex_two(void) ;

int main(void) {
    ex_two();
    return 0;
}

/*
    Podemos perceber que, durante a execucao do processo filho
    e o processo neto nao ha uma sequencia clara entre os calculos 
    do neto e do filho, ou seja, podemos perceber que existe
    a concorrencia entre osa processos pai/filho/neto.
*/
void exercise_one(void) {
    int sum = 0,pid_1 = fork(),pid_2,status;
    if (pid_1 != 0 ) {
        // father process
        printf("Pai foi criado com processID= %d\n",getpid());
        for (int i = 0;i<200;i++) {
            sum+=i;
            printf("sum = %d pid = %d\n",sum,getpid());
        }
        printf("soma = %d\n",sum);
        printf("Processo pai com process ID = %d vai finalizar \n",getpid());
        waitpid(-1,&status,0);
        printf("Processo pai finalizado \n");
        exit(status);
    } else {
        // other process
        pid_2 = fork();
        if (pid_2 != 0) {
            // son process
            printf("Filho foi criado com pid = %d e pai com pid %d\n",getpid(),getppid());
            for (int i = 1000;i<1200;i++) {
                sum+=i;
                printf("sum = %d pid = %d ppid = %d\n",sum,getpid(),getppid());
            }
            printf("soma = %d\n",sum);
            printf("Filho vai encerrar com pid = %d e pai com pid %d\n",getpid(),getppid());            
            waitpid(-1,&status,0);
            printf("Processo filho finalizado \n");
            exit(status);
        } else {
            // grandson process
            printf("Neto foi criado com pid = %d e pai com pid %d\n",getpid(),getppid());
            for (int i = 2000;i<2200;i++) {
                sum+=i;
                printf("sum = %d pid = %d ppid = %d\n",sum,getpid(),getppid());
            }
            printf("soma = %d\n",sum);
            printf("Neto vai encerrar com pid = %d e pai com pid %d\n",getpid(),getppid());
            printf("Processo neto finalizado \n");
            exit(status);
        }
    }
    printf("soma final = %d\n",sum);
    return;
}

/*
    Nesse caso os processos filho vao executando em
    concorrencia entre si, 
*/
void exercise_two(void) {
    int sum = 0, status, * pids;
    for (int i = 0; i<3; i++) {
        pids[i] = fork();
    }
    
    for (int j = 0; j<3; j++) {
        if (pids[j] != 0) {
            // processo pai
            printf("Pai foi criado com processID= %d\n",getpid());
            waitpid(&status);
            printf("Pai vai finalizar com processID= %d\n",getpid());
            exit(status);
        } else {
            switch (j) {
            case 0:
                /* primeiro filho */
                printf("Filho 1 foi criado com processID= %d e pai = %d\n",getpid(), getppid());
                for (int j_1 = 0;j_1<10;j_1++) {
                    sum+=j_1;
                    printf("sum = %d pid = %d ppid = %d\n",sum,getpid(),getppid());
                }
                waitpid(&status);
                printf("Filho 1 vai finalizar com processID= %d\n",getpid());
                exit(status);
                break;
            case 1:
                /* segundo filho */
                printf("Filho 2 foi criado com processID= %d e pai = %d\n",getpid(), getppid());
                for (int j_2 = 1000;j_2<1010;j_2++) {
                    sum+=j_2;
                    printf("sum = %d pid = %d ppid = %d\n",sum,getpid(),getppid());
                }
                waitpid(&status);
                printf("Filho 2 vai finalizar com processID= %d\n",getpid());
                exit(status);
                break;
            case 2:
                printf("Filho 3 foi criado com processID= %d e pai = %d\n",getpid(), getppid());
                for (int j_3 = 2000;j_3<2010;j_3++) {
                    sum+=j_3;
                    printf("sum = %d pid = %d ppid = %d\n",sum,getpid(),getppid());
                }                            
                waitpid(&status);
                printf("Filho 3 vai finalizar com processID= %d\n",getpid());
                exit(status);
                break;
            default:
                break;
            }
        }
    }
    return;
}

void ex_two(void) {
    int pid_1, pid_2, pid_3; 
  
    // variable pid will store the 
    // value returned from fork() system call 
    pid_1 = fork(); 
  
    // If fork() returns zero then it 
    // means it is child process. 
    if (pid_1 == 0) { 
  
        // First child needs to be printed 
        // later hence this process is made 
        // to sleep for 3 seconds. 
        sleep(500); 
  
        // This is first child process 
        // getpid() gives the process 
        // id and getppid() gives the 
        // parent id of that process. 
        printf("child[1] --> pid = %d and ppid = %d\n", 
               getpid(), getppid()); 
    } else { 
        pid_2 = fork(); 
        if (pid_2 == 0) { 
            sleep(2); 
            printf("child[2] --> pid = %d and ppid = %d\n", 
                   getpid(), getppid()); 
        } else { 
            pid_3 = fork(); 
            if (pid_3 == 0) { 
                // This is third child which is 
                // needed to be printed first. 
                printf("child[3] --> pid = %d and ppid = %d\n", 
                       getpid(), getppid()); 
            } 
  
            // If value returned from fork() 
            // in not zero and >0 that means 
            // this is parent process. 
            else { 
                // This is asked to be printed at last 
                // hence made to sleep for 3 seconds. 
                sleep(2); 
                printf("parent --> pid = %d\n", getpid()); 
            } 
        } 
    }
    return;
}