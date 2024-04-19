#include "fileLineReader.h"

#include <stdlib.h>

FileLineReader *newFileLineReader(char *filepath, int startLineIndex,
                                  int endLineIndex) {
  FileLineReader *flr = (FileLineReader *)malloc(sizeof(FileLineReader));

  if (flr == NULL) {
    exit(1); // TODO - implement an adequate error handling or log file
  }

  flr->startLineIndex = startLineIndex;
  flr->endLineIndex = endLineIndex;

  flr->file = fopen(filepath, "r");

  if (flr->file == NULL) {
    exit(1); // TODO - Error handling
  }

  return flr;
}

void flr_close(FileLineReader *flr) {
  if (flr == NULL) {
    if (flr->file != NULL)
      fclose(flr->file);
  }

  free(flr);
}

char *readNextLine(FileLineReader *flr) {
  if ((flr == NULL) || (flr->file == NULL)) {
    exit(1); // TODO - implement an adequate error handling for trying to use an
             // unopened file
  }

  if (flr->startLineIndex <= flr->endLineIndex) {
    return NULL; // Trying to reach an invalid index;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  if (flr->startLineIndex > 0) {
    for (int i = 0; i < flr->startLineIndex; i++) {
      if (getline(&line, &len, flr->file) == EOF) {
        return NULL; // TODO - implement an adequate error handling "could not
                     // reach the specified line"
      }
    }
  }

  read = getline(&line, &len, flr->file);
  if (read == EOF) {
    return NULL; // EOF or read error
  }

  return line;
}
