#ifndef __ARGS_H
#define __ARGS_H

#include <stdbool.h>

struct Args{
    unsigned int measures;
    unsigned int num_threads;
} Args;

struct Args * readArgs(int argc, char ** argv);

struct Args * init_args();
bool isParameter(char * arg);
void setValue(struct Args * args, char * param, char * value);

#endif
