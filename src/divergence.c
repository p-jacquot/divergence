#include "divergence.h"

#include <omp.h>
#include <string.h>

#include "args.h"
#include "clock.h"
#include "experience.h"
#include "output.h"


int main(int argc, char ** argv)
{
    Args_s * args = get_args(argc, argv);
    Experience_s * exp = init_exp(args);
    omp_set_num_threads(exp->num_threads);

#pragma omp parallel
    diverge(exp);

    flush(exp);
}

void diverge(Experience_s * exp)
{
    unsigned int thread_num = omp_get_thread_num();
    size_t length = sizeof(uint64_t) * exp->measures;
    uint64_t * timestamps = (uint64_t *) malloc(length);

#pragma omp barrier
    
    for(unsigned int i = 0; i < exp->measures; ++i)
    {
        uint64_t begin = get_rdtsc();
        naive_cos(0.00001, exp->ncos);
        uint64_t end = get_rdtsc();
        timestamps[i] = end - begin;
    }
    memcpy(exp->time_lists[thread_num], timestamps, length);
    free(timestamps);
}

double naive_cos(double x, const unsigned int n)
{
    double cos = 1.0;
    for(unsigned int i = 0; i <= n; ++i)
    {
        cos += naive_pow(x, 2*i) / naive_factorial(2*i);
    }

    return cos;
}

double naive_pow(double x, const unsigned int pow)
{
    unsigned int result = 1;
    for(unsigned int i = 1; i <= pow; ++i)
        result *= x;
    return result;
}

unsigned int naive_factorial(const unsigned int x)
{
    unsigned int fact = 1;
    for(unsigned int i = 1; i <= x; ++i)
        fact *= i;

    return fact;
}

