#include <stdbool.h>

#include "page.h"
#include "frame.h"

struct page {
    Frame * frame;
    bool inMemory;
};