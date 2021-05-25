#include "experience.h"

#include <stdlib.h>

Experience_s * init_exp(const Args_s * args)
{
    Experience_s * exp = (struct Experience *) malloc(sizeof(struct Experience));
    exp->num_threads = args->num_threads;
    exp->measures = args->measures;
    exp->ncos = args->ncos;
    exp->time_lists = alloc_time_lists(exp->num_threads, exp->measures);
    return exp;
}

double ** alloc_time_lists(const unsigned int num_threads, const unsigned int n)
{
    double ** time_lists = (double **) malloc(sizeof(double *) * num_threads);
    for (unsigned int i = 0; i < num_threads; ++i)
        time_lists[i] = (double *) malloc(sizeof(double) * n);

    return time_lists;
}

