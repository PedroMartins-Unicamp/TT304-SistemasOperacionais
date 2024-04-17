#ifndef MATRIX_H
#define MATRIX_H

#define index(I, J, NUM_COLUMNS) (((I) * (NUM_COLUMNS)) + J)

typedef struct matrix {
  int rowsQty;
  int colsQty;
  int *data;
} Matrix;

Matrix *newMatrix(int rows, int cols);
void deallocateMatrix(Matrix *matrix);
void printMatrix(Matrix *matrix);

#endif /* MATRIX_H */
