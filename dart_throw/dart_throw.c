
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

// Added include for random generator
#include "my_rand.h"

#define NUM_THREADS 10

int main(void){
    
    double pi_estimate;
    long long int number_in_circle = 0;
    int number_of_tosses = 1000000;

    time_t seconds;
    seconds = time(NULL);
    unsigned seed = seconds;
    int toss;
    double x, y, distance_squared;

    #pragma omp parallel shared(number_of_tosses) num_threads(NUM_THREADS) reduction(+ : number_in_circle)
    {
        for (toss = 0; toss < number_of_tosses; toss++) {

            unsigned x_seed = my_rand(&seed);
            x = (my_drand(&x_seed)*2)-1;

            unsigned y_seed = my_rand(&seed);
            y = (my_drand(&y_seed)*2)-1;
            distance_squared = x * x + y * y;
            if (distance_squared <= 1)
                number_in_circle++;
        }
    }

    pi_estimate = 4 * number_in_circle / ((double) number_of_tosses);

    printf("Estimated pi: %e\n", pi_estimate);

    return 0;

}
