#include "output.h"

void flush(const Experience_s * exp)
{
    FILE * output = fopen("timestamps.csv", "w+");
    writeHeader(output, exp);
    writeContent(output, exp);
    fclose(output);
}

void writeHeader(FILE * output, const Experience_s * exp)
{
    for(unsigned int i = 0; i < exp->num_threads; ++i)
    {
        fputs("Thread ", output);
        char number [12];
        sprintf(number, "%d", i);
        fputs(number, output);
        fputs(";", output);
    }
    fputs("\n", output);
}

void writeContent(FILE * output, const Experience_s * exp)
{
    for(unsigned int line = 0; line < exp->measures; ++line)
       writeLine(output, exp, line); 
}

void writeLine(FILE * output, const Experience_s * exp, const unsigned int line_index)
{
    for(unsigned int thread = 0; thread < exp->num_threads; ++thread)
    {
        const unsigned int begin = exp->time_lists[thread][0];
        const unsigned int current = exp->time_lists[thread][line_index];
        const unsigned int time_span = current - begin;

        char time [50];
        snprintf(time, 50, "%u", time_span);
        fputs(time, output);
        fputs(";", output);
    }
    fputs("\n", output);
}
