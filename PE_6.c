/*
Sum square difference
   
Problem 6

The sum of the squares of the first ten natural numbers is,
1^2+2^2+...+10^2=385

The square of the sum of the first ten natural numbers is,
(1+2+...+10)^2=55^2=3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025−385=2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Answer:
	25164150
CPU:
    32   microseconds aprox. 
MEMORY:
    4384   kb
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
    long int sum = 0;
    long int sum_of_the_squares = 0;
    long int square_of_the_sum = 0;
    
    for(int k = 1; k <= 100; k++ ){
        sum_of_the_squares += k*k;//k^2
        square_of_the_sum += k;//k 
    }
    sum = (square_of_the_sum * square_of_the_sum ) - sum_of_the_squares;// k*k-> (k^2 + (1^2+2^2+...+100^2))
    
    printf("%ld \n", sum);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}
