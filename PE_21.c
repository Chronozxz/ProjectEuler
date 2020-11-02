/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
Answer:
	 31626
CPU:
    106404    microseconds 
MEMORY:
    4412    kb
ideone.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

int amicable(int num)
{
    int sumDiv = 0;
    
    for(int Div = num/2; Div >0; Div--)
        if((num%Div) == 0)
            sumDiv+=Div;
            
    return sumDiv;
}

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    int sumAns = 0;
    int amicableB = 0;
    
    for(int num= 2; num < 10000; num++)
    {
        amicableB = amicable(num);
        if( num != amicableB )
        {
            if( amicable(amicableB) == num )
                sumAns += num;
        }
    }
    
	printf("Sum ans = %d \n",sumAns);//31626

	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}



