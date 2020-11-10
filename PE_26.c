/*
Reciprocal cycles

Problem 26
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
Answer:
    
CPU:
        microseconds 
MEMORY:
        kb
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int getCycles( int nc )//number current
{
  int a = 1;
  int t = 0;
  do {
  	printf("%d \n",a * 10 % nc);
    a = a * 10 % nc;
    t++;
  } while(a != 1);
  return t;
}

int main(int argc, char **argv)
{
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    int longestCycle = 0, cycle;
	
	for(int numCurrent = 7; numCurrent < 1000; numCurrent+=2)
	{
		printf("%d\n",numCurrent);
		cycle = getCycles( numCurrent );
		if(cycle > longestCycle)
			longestCycle = cycle;
	}
	
	printf("%d \n",longestCycle);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}

