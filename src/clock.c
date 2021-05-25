#include "clock.h"

#include <sys/time.h>
#include <time.h>

#ifndef GETTIMEOFDAY

double get_time()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)(t.tv_sec + t.tv_nsec / 1000000000.0);
}

#else

double get_time()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;
}

#endif // ifndef GETTIMEOFDAY
