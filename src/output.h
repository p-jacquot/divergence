#ifndef __OUTPUT_H
#define __OUTPUT_H

#include <iostream>

#include "typedefs.h"

void flush(time_point ** time_lists, const unsigned int num_threads, const unsigned int n);
void writeHeader(std::ostream & output, const unsigned int num_threads);
void writeContent(
        std::ostream & output, 
        time_point ** time_lists, 
        const unsigned int num_threads,
        const unsigned int n);

void writeLine(
        std::ostream & output, 
        time_point ** time_lists, 
        const unsigned int num_threads,
        const unsigned int line_index);

#endif
