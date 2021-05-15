#include "clock.h"

#include <sys/time.h>
#include <time.h>

double get_time()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)(t.tv_sec + t.tv_nsec / 1000000000.0);
}
