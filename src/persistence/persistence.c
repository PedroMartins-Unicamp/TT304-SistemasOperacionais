#include "persistence.h"
#include <stdio.h>
#include <stdlib.h>

FileStream *newFileStream(char *filepath, char *mode) {
  FileStream *fs = (FileStream *)malloc(sizeof(FileStream));

  if (fs == NULL) {
    exit(1); // TODO - implement an adequate error handling or log file
  }

  fs->filepath = filepath;
  fs->mode = mode;
  fs->isFileOpen = 1;

  return fs;
}

void fileStream_close(FileStream *fs) {}
