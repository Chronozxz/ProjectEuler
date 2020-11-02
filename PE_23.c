/*
Non-abundant sums
Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
Answer:
    4179871
CPU:
    1354438    microseconds 
MEMORY:
    624    kb
onlinegdb.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

int getSumDiv(int num)
{//Get the sum of num
    int sum = 0;
	
	for(int div= num/2; div >0;  div--)
		if(! (num%div))
			sum+=div;
	
	return sum;
}

int isAbundant(int num, int sum)
{//check if the sum of divisors is more that num 
	if(sum > num)
		return 1;
	return 0;
}

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    int max = 28123;
	int sumNoAbundant = 0;
	int *Abundant;
	int index = 0;
	Abundant = (int *) malloc(index*sizeof(int));
	int sumDiv;
	int sumNumAbundant;
	int Abundants[max];
	
	for(int k = 0; k < max; k++)
		Abundants[k]=1;
	
	for(int n = 1; n <= max; n++)//Top 28123
	{//Find the sum of all the positive integers which can be written as the sum of two abundant numbers.
	    sumDiv = getSumDiv(n);
		if( isAbundant(n,sumDiv) )
		{
		    index++;
		    Abundant = realloc(Abundant, index*sizeof(int));
		    Abundant[index -1] = n;
		}
	}

	for(int k = 0; k < index; k++)
	{//if 
		for(int j = k; j < index; j++)
		{
			sumNumAbundant = Abundant[k]+Abundant[j];
			if( sumNumAbundant < max )
				Abundants[sumNumAbundant] = 0;
		}
	}

	for(int k = 1; k<max; k++)
		if(Abundants[k])
			sumNoAbundant +=k;
		
	printf("%d \n",sumNoAbundant);//4179871
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}