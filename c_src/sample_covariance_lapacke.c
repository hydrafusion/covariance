#include "sample_covariance_lapacke.h"
#include <cblas.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int rows;
  int columns;
  double *data;
} Matrix;

static void center_matrix_inplace(Matrix *mat) {
  for (int j = 0; j < mat->columns; ++j) {
    double sum = 0.0;
    for (int i = 0; i < mat->rows; ++i) {
      sum += mat->data[i * mat->columns + j];
    }
    double mean = sum / mat->rows;
    for (int i = 0; i < mat->rows; ++i) {
      mat->data[i * mat->columns + j] -= mean;
    }
  }
}

static Matrix compute_covariance_matrix(Matrix *X) {
  center_matrix_inplace(X);

  Matrix cov = {
      .rows = X->columns,
      .columns = X->columns,
      .data = (double *)calloc(X->columns * X->columns,
                               sizeof(double)) // output matrix
  };

  cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, X->columns, X->columns,
              X->rows, 1.0 / (X->rows - 1), X->data, X->columns, X->data,
              X->columns, 0.0, cov.data, cov.columns);

  return cov;
}

SampleCovarResult sample_covar(int rows, int columns, double *data) {
  Matrix X = {.rows = rows, .columns = columns, .data = data};

  Matrix cov = compute_covariance_matrix(&X);

  SampleCovarResult result = {
      .rows = cov.rows, .columns = cov.columns, .covar_matrix = cov.data};

  return result;
}

void free_sample_covar_result(SampleCovarResult *result) {
  if (result && result->covar_matrix) {
    free(result->covar_matrix);
    result->covar_matrix = NULL;
  }
}
