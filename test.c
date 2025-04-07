#include "c_src/sample_covariance_lapacke.h"
#include <stdio.h>

int main() {

  double data[2][2] = {{1.0, 2.0}, {3.0, 4.0}};

  // rows,colums, data
  SampleCovarResult result = sample_covar(2, 2, (double *)data);

  // Print the result
  printf("Covariance Matrix:\n");
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      printf("%lf ", result.covar_matrix[i * result.columns + j]);
    }
    printf("\n");
  }

  free_sample_covar_result(&result);
  return 0;
}
