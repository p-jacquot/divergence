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

#ifdef OMP
    Experience_s * exp = init_exp(args);
    omp_set_num_threads(exp->num_threads);

#pragma omp parallel
    diverge(exp);
#else
    Experience_s * exp = init_exp(args);
    diverge(exp);
#endif

    flush(exp);
}

void diverge(Experience_s * exp)
{
#ifdef OMP
    unsigned int thread_num = omp_get_thread_num();
#else
    unsigned int thread_num = 0;
#endif
    size_t length = sizeof(uint64_t) * exp->measures;
    uint64_t * timestamps = (uint64_t *) malloc(length);
#ifdef OMP
#pragma omp barrier
#endif
    for(unsigned int i = 0; i < exp->measures; ++i)
    {
        uint64_t begin = get_rdtsc();
#ifdef COMPUTE_COS
        naive_cos(0.00001, exp->ncos);
#else
        simple_for(exp->ncos);
#endif
        uint64_t end = get_rdtsc();
        timestamps[i] = end - begin;
    }
    memcpy(exp->time_lists[thread_num], timestamps, length);
    free(timestamps);
}

unsigned int simple_for(const unsigned int n)
{
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; ++i)
        sum += i;
    return sum;
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

