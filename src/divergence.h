#ifndef __DIVERGENCE_H
#define __DIVERGENCE_H


int main(int argc, char ** argv);

double ** setup(const unsigned int num_threads, const unsigned int n);

void diverge(double ** time_lists, const unsigned int n);
void do_something();

#endif
