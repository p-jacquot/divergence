#ifndef __EXPERIENCE_H
#define __EXPERIENCE_H

#include "args.h"

#include "stdint.h"

struct Experience {
    unsigned int num_threads;
    unsigned int measures;
    unsigned int ncos;
    uint64_t ** time_lists;
};

typedef struct Experience Experience_s;

Experience_s * init_exp(const Args_s * args);
uint64_t ** alloc_time_lists(const unsigned int num_threads, const unsigned int n);

#endif
