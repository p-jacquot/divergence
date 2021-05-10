#include "args.h"

#include <omp.h>

using namespace std;

Args::Args(int argc, char ** argv)
: measures(100), num_threads(omp_get_max_threads())
{
   for(unsigned int i = 0; i < argc; ++i)
   {
      string arg(argv[i]);
      if(isParameter(arg))
      {
            ++i;
            string value(argv[i]);
            setValue(arg, value);
      }
   }
}

bool Args::isParameter(const string & arg) const
{
    return (arg[0] == '-');
}

void Args::setValue(const string & param, const string & value)
{
    switch(param[1])
    {
        case 'n':
            measures = stoul(value);
            break;

        case 't':
            num_threads = stoul(value);
            break;

        default:
            break;
    }
}

unsigned int Args::getMeasures() const
{
    return measures;
}

unsigned int Args::getNumThreads() const
{
    return num_threads;
}
