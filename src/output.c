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
        const uint64_t time_span = exp->time_lists[thread][line_index];

        char time [50];
        snprintf(time, 50, "%lu", time_span);
        fputs(time, output);
        fputs(";", output);
    }
    fputs("\n", output);
}
