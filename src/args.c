#include "args.h"

#include <stdlib.h>
#include <omp.h>

struct Args * readArgs(int argc, char ** argv)
{
    struct Args * args = init_args();
    for(unsigned int i = 0; i < argc; ++i)
    {
        char * param = argv[i];
        if(isParameter(param))
            setValue(args, param, argv[++i]);
    }
    return args;
}

struct Args * init_args()
{
    struct Args * args = malloc(sizeof(struct Args));
    args->measures = 100;
    args->num_threads = omp_get_max_threads();
    return args;
}

bool isParameter(char * arg)
{
    return (arg[0] == '-');
}

void setValue(struct Args * args, char * param, char * value)
{
    switch(param[1])
    {
        case 'n':
            args->measures = strtoul(value, NULL, 10);
            break;
            
        case 't':
            args->num_threads = strtoul(value, NULL, 10);
            break;

        default:
            break;
    }
}
