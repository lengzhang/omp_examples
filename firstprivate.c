#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int i, a = 0;
    printf("----------------------------------\nBefore\ta = %d\n", a);
    printf("----------------------------------\n");
    #pragma omp parallel for firstprivate(a)
    for (i = 0; i < 10; i++)
    {
        printf("thread %d - initial <-\ta = %d\n", omp_get_thread_num(), a);
        a += 20;
        printf("thread %d - result\ta = %d\n", omp_get_thread_num(), a);
    }
    printf("----------------------------------\nAfter\ta = %d\n", a);
    printf("----------------------------------\n");
    
    return 0;
}