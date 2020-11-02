/*
10001st prime
   
Problem 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer:
	104743
CPU:
    1752063   microseconds aprox. 1.75 sec.
MEMORY:
    4560   kb
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
    int numPrime = 0;
    int prime = 1;
    short isPrime;
    while(numPrime != 10001){
        prime++;
        isPrime = 1;
        for(int k = 2; k <= prime >> 1; k++)//chech number if is prime
            if(! (prime % k) ){
                isPrime = 0;
                k = prime;
            }
        if(isPrime)//isPrime 1 them st prime number +1
            numPrime++;
    }
    
    printf("%d \n", prime);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}