#ifndef __EXPERIENCE_H
#define __EXPERIENCE_H

struct Experience {
    unsigned int num_threads;
    unsigned int measures;
    double ** time_lists;
};

typedef struct Experience Experience_s;

Experience_s * init_exp(const unsigned int num_threads, const unsigned int measures);
double ** alloc_time_lists(const unsigned int num_threads, const unsigned int n);

#endif
