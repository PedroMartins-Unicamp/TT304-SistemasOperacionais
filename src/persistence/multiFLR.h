#ifndef MULTIFLR_H
#define MULTIFLR_H

#include "fileLineReader.h"

typedef struct multiFLR {
  char *filepath;

  int flrQty;
  FileLineReader **flrArray;
} MultiFLR;
MultiFLR *newMultiFLR(char *filepath, int flrQty);

void closeMultiFLR(MultiFLR *multiFlr);

#endif
