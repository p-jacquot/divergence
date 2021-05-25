#ifndef __DIVERGENCE_H
#define __DIVERGENCE_H

#include "experience.h"

int main(int argc, char ** argv);

void diverge(Experience_s * exp);

double naive_cos(double x, const unsigned int n);
double naive_pow(double x, const unsigned int pow);
unsigned int naive_factorial(const unsigned int x);

#endif
