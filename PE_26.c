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
    983
CPU:
    898    microseconds 
MEMORY:
    2668    kb
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int getCycles( int nc )//number current
{
  int a = 1;
  int t = 0;
  do {
  	//printf("%d \n",a * 10 % nc);
    a = (a * 10) % nc;
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
    short longestCycle = 0, cycle, number;
    short numPrimes = 165;//165
	int Primes[165] ={ 7,  11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,
							 67,  71,  73,  79,  83,  89,  97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 
							157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
							257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 
							367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 
							467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 
							599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 
							709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 
							829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 
							967, 971, 977, 983, 991, 997};
	for(int numCurrent = 0; numCurrent < numPrimes; numCurrent++)//numCurrent+=2 )
	{
		//printf("%d\n",Primes[numCurrent]);//number current
		cycle = getCycles( Primes[numCurrent] );
		if(cycle > longestCycle)
		{
			longestCycle = cycle;
			number = Primes[numCurrent];
		}
	}
	
	printf("%d => %d \n",number,longestCycle);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}

