#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <chrono>

typedef std::chrono::high_resolution_clock high_resolution_clock;
typedef high_resolution_clock::time_point time_point;
typedef std::chrono::duration<double> duration;

#endif
