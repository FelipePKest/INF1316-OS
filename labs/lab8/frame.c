#include <sys/time.h>

#include "frame.h"
#include "page.h"

struct tablepage {
    Pagina p;
    char R;
    char F;
<<<<<<< HEAD
} TP;
=======
    struct timeval lastUse; //??
    // Frame frame;
};
>>>>>>> 98b7cb44d7c7e92f729698575c6c184a7917ab67
