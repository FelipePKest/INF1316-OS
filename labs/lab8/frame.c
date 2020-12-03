#include <sys/time.h>

#include "frame.h"
#include "page.h"

struct tablepage{
    Pagina page;
    char R;
    char F;
} TP;