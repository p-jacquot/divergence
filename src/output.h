#ifndef __OUTPUT_H
#define __OUTPUT_H

#include <stdlib.h>
#include <stdio.h>

#include "experience.h"

void flush(const Experience_s * exp);
void writeHeader(FILE * output, const Experience_s * exp);
void writeContent(FILE * output,  const Experience_s * exp);
void writeLine(FILE * output, const Experience_s * exp, const unsigned int line_index);

#endif
