#include <sys/time.h>

#include "frame.h"
#include "page.h"

struct tablepage {
    Pagina p;
    char R;
    char F;
    struct timeval lastUse; //??
    // Frame frame;
};