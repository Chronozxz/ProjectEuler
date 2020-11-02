/*
Longest Collatz sequence
   
Problem 14

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer:
	837799
CPU:
    182506    microseconds 
MEMORY:
    4264    kb
ideone.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    long longest_chain_number=0;
    int starting_number;
    long chain,num;
    
    for(long number = 2; number < 1000000; number++){//2 to one million
        num = number;
        chain = 1;
        while(num >1){//num = 1 break while
            if(!(num%2)){//even
                num >>= 1;//num = num/2
            }else{//odd
                num = (3*num)+1;
            }
            chain++;
        }
        if(chain > longest_chain_number){//new chain is more bigger that last bigger chain?
            longest_chain_number = chain;
            starting_number = number;
        }
    }
    
    printf("%d \n",starting_number);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}
