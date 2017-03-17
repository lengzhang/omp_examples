#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    printf("No Barrier:\n");
    #pragma omp parallel
    {
        printf("%d\ta\n", omp_get_thread_num());
        printf("%d\tb\n", omp_get_thread_num());
    }
    
    printf("With Barrier:\n");
    #pragma omp parallel
    {
        printf("%d\ta\n", omp_get_thread_num());
        #pragma omp barrier
        printf("%d\tb\n", omp_get_thread_num());
    }
    
    return 0;
}