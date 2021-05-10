#include "divergence.h"

#include <chrono>
#include <omp.h>
#include <fstream>
#include <string>

#include "args.h"
#include "output.h"

using namespace std;

int main(int argc, char ** argv)
{
    Args args(argc, argv);
    unsigned int measures = args.getMeasures();
    unsigned int num_threads = args.getNumThreads();
    time_point ** time_lists = setup(measures, num_threads);

#pragma omp parallel
    diverge(time_lists, measures);

    flush(time_lists, num_threads, measures);
}


time_point ** setup(const unsigned int num_threads, const unsigned int n)
{
    time_point ** time_lists = new time_point * [num_threads];
    for (unsigned int i = 0; i < num_threads; ++i)
        time_lists[i] = new time_point [n];

    return time_lists;
}

void diverge(time_point ** time_lists, const unsigned int n)
{
    unsigned int thread_num = omp_get_thread_num();
    time_point * timestamps = time_lists[thread_num];

#pragma omp barrier
    
    for(unsigned int i = 0; i < n; ++i)
    {
        timestamps[i] = high_resolution_clock::now();
        do_something();
    }
}

void do_something()
{
    for(unsigned int i = 0; i < 1000; ++i);
}


