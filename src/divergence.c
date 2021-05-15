#include "divergence.h"

#include <omp.h>

#include "args.h"
#include "clock.h"
#include "experience.h"
#include "output.h"


int main(int argc, char ** argv)
{
    struct Args * args = readArgs(argc, argv);
    Experience_s * exp = init_exp(args->num_threads, args->measures);
    omp_set_num_threads(args->num_threads);

#pragma omp parallel
    diverge(exp->time_lists, exp->measures);

    flush(exp);
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

void do_something()
{
    for(unsigned int i = 0; i < 1000; ++i);
}

