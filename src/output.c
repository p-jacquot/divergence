#include "output.h"

void flush(double ** time_lists, const unsigned int num_threads, const unsigned int n)
{
    FILE * output = fopen("timestamps.csv", "w+");
    writeHeader(output, num_threads);
    writeContent(output, time_lists, num_threads, n);
    fclose(output);
}

void writeHeader(FILE * output, const unsigned int num_threads)
{
    for(unsigned int i = 0; i < num_threads; ++i)
    {
        fputs("Thread ", output);
        char number [12];
        sprintf(number, "%d", i);
        fputs(number, output);
        fputs(";", output);
    }
    fputs("\n", output);
}

void writeContent(
        FILE * output,
        double ** time_lists,
        const unsigned int num_threads,
        const unsigned int n)
{
    for(unsigned int line = 0; line < n; ++line)
       writeLine(output, time_lists, num_threads, line); 
}

void writeLine(
        FILE * output,
        double ** time_lists,
        const unsigned int num_threads,
        const unsigned int line_index)
{
    for(unsigned int thread = 0; thread < num_threads; ++thread)
    {
        const double begin = time_lists[thread][0];
        const double current = time_lists[thread][line_index];
        const double time_span = current - begin;

        char time [50];
        snprintf(time, 50, "%f", time_span);
        fputs(time, output);
        fputs(";", output);
    }
    fputs("\n", output);
}
