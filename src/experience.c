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

uint64_t ** alloc_time_lists(const unsigned int num_threads, const unsigned int n)
{
    uint64_t ** time_lists = (uint64_t **) malloc(sizeof(uint64_t *) * num_threads);
    for (uint64_t i = 0; i < num_threads; ++i)
        time_lists[i] = (uint64_t *) malloc(sizeof(uint64_t) * n);

    return time_lists;
}

