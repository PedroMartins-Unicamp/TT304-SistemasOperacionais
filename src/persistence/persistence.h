#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct filestream {
  char *filepath;
  char *mode;
  int isFileOpen;

  FILE *file;
} FileStream;
FileStream *newFileStream(char *filepath, char *mode);

void fileStream_close(FileStream *fs);

void fileStream_readFile();

#endif
