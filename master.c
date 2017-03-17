#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int i, a = 0;
    printf("----------------------------------\nBefore\ta = %d\n", a);
    printf("----------------------------------\n");
    #pragma omp parallel private(a)
    {
        printf("thread %d - first\t1\ta = %d\n", omp_get_thread_num(), a);
        a += 20;
        printf("thread %d - second\t2\ta = %d\n", omp_get_thread_num(), a);
        #pragma omp master
        {
            printf("thread %d - master first\t\ta = %d\n", omp_get_thread_num(), a);
            a += 50;
            printf("thread %d - master second\ta = %d\n", omp_get_thread_num(), a);
        }
        #pragma omp barrier
        printf("thread %d - third\t3\ta = %d\n", omp_get_thread_num(), a);
        a += 20;
        printf("thread %d - fourth\t4\ta = %d\n", omp_get_thread_num(), a);
    }
    printf("----------------------------------\nAfter\ta = %d\n", a);
    printf("----------------------------------\n");
    
    return 0;
}