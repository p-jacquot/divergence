#ifndef __OUTPUT_H
#define __OUTPUT_H

#include <stdlib.h>
#include <stdio.h>

void flush(double ** time_lists, const unsigned int num_threads, const unsigned int n);
void writeHeader(FILE * output, const unsigned int num_threads);
void writeContent(
        FILE * output, 
        double ** time_lists, 
        const unsigned int num_threads,
        const unsigned int n);

void writeLine(
        FILE * output, 
        double ** time_lists, 
        const unsigned int num_threads,
        const unsigned int line_index);

#endif
