#ifndef READER_H
#define READER_H

#include <stdio.h>

typedef struct fileLineReader {
  FILE *file;
  int startLineIndex;
  int endLineIndex;

} FileLineReader;
FileLineReader *newFileLineReader(char *filepath, int startLineIndex,
                                  int endLineIndex);

void flr_close(FileLineReader *flr);
char *readNextLine(FileLineReader *flr);

#endif
