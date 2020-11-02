/*
Summation of primes
 
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Answer:
	142913828922
CPU:
    5290   microseconds 
MEMORY:
    4392   kb
ideone.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <math.h>
#include <stdlib.h>

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    long sum = 2;
    int limit = 2000000;//limit
    int sieveBound = (limit -1)/2;
    short primes[limit];
    int crosslimit = sqrt(limit);
    
    for(int k = 1; k< crosslimit; k++)//for k to sqrt(limit)
        if(!primes[k])
            for(int l = 2*k*(k+1); l < sieveBound; l=l+ 2*k+1 )//step odd multiples
                primes[l] = 1;
    
    for(int k = 1; k<sieveBound; k++)//sum the primes[k] = 0, they are primes
        if(!primes[k])
            sum += 2*k+1;
    
    printf("%ld \n", sum);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}

