#include <stdlib.h>
#include <string.h>

#include "fileLineReader.h"
#include "multiFLR.h"

MultiFLR *newMultiFLR(char *filepath, int flrQty) {
  MultiFLR *mflr = (MultiFLR *)malloc(sizeof(MultiFLR));
  if (mflr == NULL) {
    exit(1); // TODO - Error handling
  }

  mflr->flrQty = flrQty;
  mflr->filepath = strdup(filepath);

  mflr->flrArray =
      (FileLineReader **)malloc(mflr->flrQty * sizeof(FileLineReader *));
  if (mflr->flrArray == NULL) {
    exit(1); // TODO - Error handling
  }

  for (int i = 0; i < mflr->flrQty; i++) {
    mflr->flrArray[i] = newFileLineReader(
        mflr->filepath, 0, 0); // TODO - Adequate start line and endline
    if (mflr->flrArray[i] == NULL) {
      exit(1); // TODO - Error handling
    }
  }

  return mflr;
}

void closeMultiFLR(MultiFLR *multiFlr) {
  if (multiFlr == NULL) {
    exit(1); // TODO - Error Handling
  }

  if (multiFlr->filepath != NULL) {
    free(multiFlr->filepath);
  }

  if (multiFlr->flrArray != NULL) {
    for (int i = 0; i < multiFlr->flrQty; i++) {
      flr_close(multiFlr->flrArray[i]);
    }
  }

  free(multiFlr);
}
