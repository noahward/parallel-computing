
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4

#define NRA 20 // number of rows in matrix A
#define NCA 30 // number of columns in matrix A
#define NCB 10 // number of columns in matrix B

int main(void){

    int num_threads, i, j, k;

    double a[NRA][NCA];  // matrix A to be multiplied
    double b[NCA][NCB];  // matrix B to be multiplied
    double c[NRA][NCB];  // result matrix C

    double start = omp_get_wtime();
    #pragma omp parallel num_threads(NUM_THREADS) shared(a,b,c) private(i,j,k)
    {
        #pragma omp for
            for (i=0; i<NRA; i++) {
                for (j=0; j<NCA; j++) {
                    a[i][j]=i+j;
                }
            }

        #pragma omp for
            for (i=0; i<NCA; i++) {
                for (j=0; j<NCB; j++) {
                    b[i][j]=i*j+1;
                }
            }

        #pragma omp for
            for (i=0; i<NRA; i++) {
                for (j=0; j<NCB; j++) {
                    c[i][j] = 0;
                    for (k=0; k<NCA; k++) {
                        c[i][j]+=a[i][k]*b[k][j];
                    }
                }
            }

    }
    double end = omp_get_wtime();

    /*** Print results ***/
    printf("Execution time: %.2f ms\n", (end-start)*1000);
    printf("Result Matrix:\n");
    for (i = 0; i < NRA; i++) {
        for (j = 0; j < NCB; j++)
            printf("%6.2f   ", c[i][j]);
        printf("\n");
    }
return 0;
}
