#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int i;
    #pragma omp parallel for
    for (i = 0; i < 10; i++)
    {
        printf("i = %d\tthread id = %d\n", i, omp_get_thread_num());
    }
    
    return 0;
}