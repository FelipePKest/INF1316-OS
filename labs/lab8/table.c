#define VECTOR_SIZE 100
#include <sys/time.h>

struct page {
    char flag_r;
    char flag_w;
    struct timeval time_used;
};
