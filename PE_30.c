/*
Digit fifth powers

Problem 30
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
Answer:
    443839
CPU:
    189105    microseconds 
MEMORY:
    3236    kb
*/
//Compile with -lm  for pow
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <math.h>

int getSumPow(int n)
{
	int sum=0;
	while(n != 0)
	{
		sum += (int) pow((double)(n%10), (double)5);//get pow digit x ^5
		n/=10;
	}
	return sum;
}

int main(int argc, char **argv)
{
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    int sum = 0;
    int sumAll = 0;//The sum of the numbers
    for(int number = 2; number < 1000000; number++)
    {
    	sum = getSumPow(number);
    	if(sum == number)
    		sumAll += sum;
    }
    printf("%d \n",sumAll);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}
