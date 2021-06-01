#ifndef __CLOCK_H
#define __CLOCK_H

#include <stdint.h>

double get_time();

static inline uint64_t get_rdtsc() 
{
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi) :: "memory");
    return ((uint64_t)hi << 32ULL | (uint64_t)lo);
}

#endif
