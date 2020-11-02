/*
Largest palindrome product
   
Problem 4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer:
	906609
CPU:
    72014    microseconds
MEMORY:
    4328   kb
ideone.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

int isPalindromic(int k){
    char num[15];
    sprintf(num, "%d", k);
    int tam = strlen(num) - 1;
    for(int l = 0; l <= tam/2; l++)
        if(num[l] != num[tam-l])
            return 0;
    return 1;
}

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
	int palindromic = 0;
    
    for(int k = 999; k > 99; k--)
        for(int j = 999; j > 99; j--)
            if(isPalindromic(k*j) && k*j > palindromic)
                palindromic = k*j;
	printf("%d \n",palindromic);
	
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("Time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}






