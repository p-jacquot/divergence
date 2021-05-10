#ifndef __ARGS_H
#define __ARGS_H

#include <string>

class Args
{
public:
    Args(int argc, char ** argv);

    unsigned int getMeasures() const;
    unsigned int getNumThreads() const;

private:

    bool isParameter(const std::string & arg) const;
    void setValue(const std::string & param, const std::string & value);
    unsigned int measures;
    unsigned int num_threads;
};

#endif
