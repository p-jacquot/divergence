#include "output.h"

#include <fstream>

using namespace std;

void flush(time_point ** time_lists, const unsigned int num_threads, const unsigned int n)
{
    ofstream output("timestamps.csv");
    writeHeader(output, num_threads);
    writeContent(output, time_lists, num_threads, n);
}

void writeHeader(ostream & output, const unsigned int num_threads)
{
    string header;
    for(unsigned int i = 0; i < num_threads; ++i)
        header += "Thread " + to_string(i) + ";";
    output << header << endl;
}

void writeContent(
        ostream & output,
        time_point ** time_lists,
        const unsigned int num_threads,
        const unsigned int n)
{
    for(unsigned int line = 0; line < n; ++line)
       writeLine(output, time_lists, num_threads, line); 
}

void writeLine(
        ostream & output,
        time_point ** time_lists,
        const unsigned int num_threads,
        const unsigned int line_index)
{
    string line;
    for(unsigned int thread = 0; thread < num_threads; ++thread)
    {
        const time_point & begin = time_lists[thread][0];
        const time_point & current = time_lists[thread][line_index];
        duration time_span = chrono::duration_cast<duration>(current - begin);
        line += to_string(time_span.count()) + ";";
    }
    output << line << endl;
}
