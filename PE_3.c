/*
Largest prime factor
   
Problem 3

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer:
	6857
CPU:
    7773 microseconds
MEMORY:
	720 kb
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
	int prime = 1;
    unsigned long int number = 600851475143; //the number to check
    short isPrime;
	do{
	    prime++;
	    isPrime = 1;
	    for (int k = 2; k < prime >> 1; k++)//for see if prime is prime or not
	        if(!(prime % k)){//if prime % k == 0 not is prime
	            isPrime= 0;
	            break;
	        }
	    if(isPrime && !(number%prime))// if isPrime = 1 and !( number%prime == 0)
	        number = number/prime;
	}while(number != 1);
	printf("%d \n",prime);
	
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("Time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}