#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int stdunt[10] = {0};
    float avg = 0;
    
    srand(time(NULL));
    for(int i=0; i<10; i++){
        stdunt[i] = rand() % 101;
    }
    for(int i=0; i<10; i++){
        avg += stdunt[i];
    }
    
    avg = avg/10;
    
    printf("avg = %.1f", avg);
    return 0;
}