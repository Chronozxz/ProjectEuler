/*
Power digit sum
  
Problem 16

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?

Answer:
	1366
CPU:
    66    microseconds 
MEMORY:
    4196  kb
ideone.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <math.h>
#include <string.h>

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    int sum = 0;
    long double number = pow(2,1000);
    char arr[2800];//wors case, all number are 9, so 9*exponent of (2^100)
    sprintf(arr,"%Lf",number);//long double to char
    for(int k = 0; k< strlen(arr)-7; k++)// minus seven for .000000
        sum+=arr[k] -48;//character to int
    printf("%d \n",sum);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}
