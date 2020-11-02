/*
Smallest multiple
   
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer:
	232792560
CPU:
    4946246    microseconds aprox. 4.9462 seconds
MEMORY:
    4320    kb
ideone.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    long int number = 20;
    short isdivisible = 1; 
    for(number; isdivisible; number++ ){
        isdivisible = 0;
        for(int k = 1; k <=20 ; k++)// 1 to 20
            if(number%k){    //if % = 0 is divisible and not continue
                isdivisible = 1;
                break;
            }
    }
    printf("%ld \n", number);
	//---------------------------Program2 ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}