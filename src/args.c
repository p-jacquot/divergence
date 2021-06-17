#include "args.h"

#include <stdlib.h>
#include <omp.h>

Args_s * get_args(int argc, char ** argv)
{
    Args_s * args = init_args();
    read_args(args, argc, argv);
    return args;
}

Args_s * init_args()
{
    Args_s * args = malloc(sizeof(Args_s));
    args->measures = 100;
    args->ncos = 100;
#ifdef OMP
    args->num_threads = omp_get_max_threads();
#else
    args->num_threads = 1;
#endif
    return args;
}

void read_args(Args_s * args, const int argc, char ** argv)
{
    for(unsigned int i = 0; i < argc; ++i)
    {
        char * param = argv[i];
        if(is_parameter(param) && i != argc - 1)
            set_value(args, param, argv[++i]);
    }
}

bool is_parameter(char * arg)
{
    return (arg[0] == '-');
}

void set_value(Args_s * args, char * param, char * value)
{
    switch(param[1])
    {
        case 'n':
            args->measures = strtoul(value, NULL, 10);
            break;

        case 'c':
            args->ncos = strtoul(value, NULL, 10);
            break;
            
        case 't':
            args->num_threads = strtoul(value, NULL, 10);
            break;

        default:
            break;
    }
}
