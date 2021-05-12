#include "divergence.h"

#include <omp.h>
#include <sys/time.h>
#include <time.h>

#include "args.h"
#include "output.h"


int main(int argc, char ** argv)
{
    struct Args * args = readArgs(argc, argv);
    unsigned int measures = args->measures;
    unsigned int num_threads = args->num_threads;
    double ** time_lists = setup(num_threads, measures);

#pragma omp parallel
    diverge(time_lists, measures);

    flush(time_lists, num_threads, measures);
}


double ** setup(const unsigned int num_threads, const unsigned int n)
{
    double ** time_lists = malloc(sizeof(double *) * num_threads);
    for (unsigned int i = 0; i < num_threads; ++i)
        time_lists[i] = malloc(sizeof(double) * n);

    return time_lists;
}

void diverge(double ** time_lists, const unsigned int n)
{
    unsigned int thread_num = omp_get_thread_num();
    double * timestamps = time_lists[thread_num];

#pragma omp barrier
    
    for(unsigned int i = 0; i < n; ++i)
    {
        timestamps[i] = get_time();
        do_something();
    }
}

double get_time()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)(t.tv_sec + t.tv_nsec / 1000000000.0);   
}

void do_something()
{
    for(unsigned int i = 0; i < 1000; ++i);
}

