#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
static long num_steps = 100000;
double step;
void main ()
{
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf(" hello(%d) ", ID);
        printf(" world(%d) \n", ID);
    }
}