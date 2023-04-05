#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000 // size of array

int main() {
    int i;
    double sum = 0.0;
    double *array = (double*) malloc(N * sizeof(double)); // allocate array
    
    // initialize array with random values
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        array[i] = rand() / (double) RAND_MAX;
    }
    
    // compute sum of array using multiple threads
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < N; i++) {
        sum += array[i];
    }
    
    printf("Sum of array: %f\n", sum);
    
    free(array); // free array memory
    
    return 0;
}
