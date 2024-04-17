#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *newMatrix(int rowsQty, int colsQty) {
  Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
  if (matrix == NULL) {
    exit(1); // TODO - implement an adequate error handling or log file
  }

  matrix->rowsQty = rowsQty;
  matrix->colsQty = colsQty;

  matrix->data = (int *)malloc(sizeof(int) * rowsQty * colsQty);
  if (matrix == NULL) {
    exit(1); // TODO - implement an adequate error handling or log file
  }

  return matrix;
}

void deallocateMatrix(Matrix *matrix) {
  free(matrix->data);
  free(matrix);
}

void printMatrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rowsQty; i++) {
    for (int j = 0; j < matrix->colsQty; j++) {
      printf("%d ", matrix->data[index(i, j, matrix->colsQty)]);
    }
    printf("\n");
  }
}
