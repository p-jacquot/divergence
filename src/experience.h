#ifndef __EXPERIENCE_H
#define __EXPERIENCE_H

#include "args.h"

struct Experience {
    unsigned int num_threads;
    unsigned int measures;
    unsigned int ncos;
    double ** time_lists;
};

typedef struct Experience Experience_s;

Experience_s * init_exp(const Args_s * args);
double ** alloc_time_lists(const unsigned int num_threads, const unsigned int n);

#endif
