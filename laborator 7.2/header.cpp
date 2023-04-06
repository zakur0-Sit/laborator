#include "header.h"

int compare_ints(const int& x, const int& y)
{
    if (x < y) {
        return -1;
    }
    else if (x > y) {
        return 1;
    }
    else {
        return 0;
    }
}
