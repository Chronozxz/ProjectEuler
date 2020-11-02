/*
Special Pythagorean triplet

Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Answer:
	31875000
CPU:
    24828   microseconds 
MEMORY:
    4380   kb
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
    int Product = 0;
    int a,b,c;
    short Pythagorean_Triplet =1;
    for(int a = 1; a < 1000; a++)
        for(int b = a+1; b < 1000; b++)
            for(int c = b+1; c<1000; c++ ){
                if(a+b+c > 1000)
                        break;
                if(a+b+c == 1000){
                    if((a*a) + (b*b) == (c*c)){
                        Product = a*b*c;
                        printf("%d %d %d \n",a, b, c);
                        break;
                    }
                }
            }
    printf("%d \n", Product);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}
