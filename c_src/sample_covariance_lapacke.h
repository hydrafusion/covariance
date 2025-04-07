#ifndef SAMPLE_COVARIANCE_LAPACKE_H 
#define SAMPLE_COVARIANCE_LAPACKE_H

typedef struct {
    int rows;
    int columns;
    double *covar_matrix;

} SampleCovarResult;

// Expose the function to create covariance matrix 
SampleCovarResult sample_covar(int rows, int columns, double *data);

// Expose function to free allocated memory 
void free_sample_covar_result(SampleCovarResult* result);

#endif
