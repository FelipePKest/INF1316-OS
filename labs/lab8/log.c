#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char * argv[]) {
    double x, ret;
    x = 10;
    int s = 10;
    int val = atoi(argv[1]);
    while (val != 1) {
        s++;
        val = val>>1;
    }
//    /* finding log(2.7) */
//    ret = log2(x);
   printf("%d\n", s);
   
   return(0);
}