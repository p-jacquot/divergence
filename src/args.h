#ifndef __ARGS_H
#define __ARGS_H

#include <stdbool.h>

struct Args{
    unsigned int measures;
    unsigned int num_threads;
} Args;

typedef struct Args Args_s;

Args_s * get_args(int argc, char ** argv);

Args_s * init_args();

void read_args(Args_s * args, const int argc, char ** argv);
bool is_parameter(char * arg);
void set_value(Args_s * args, char * param, char * value);

#endif
