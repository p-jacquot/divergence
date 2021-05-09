#ifndef __DIVERGENCE_H
#define __DIVERGENCE_H

#include <chrono>
#include <iostream>

#include "typedefs.h"

int main(int argc, char ** argv);

time_point ** setup(const unsigned int num_threads, const unsigned int n);

void diverge(time_point ** time_lists, const unsigned int n);
void do_something();

#endif
