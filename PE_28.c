/*
Number spiral diagonals

Problem 28
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

(21) 22 23 24 (25)
20  (7)  8  (9) 10
19  6  (1)  2 11
18  (5)  4  (3) 12
(17) 16 15 14 (13)

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
Answer:
    669171001
CPU:
    244    microseconds 
MEMORY:
    3244    kb
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    
    int max_jumps = (int)(1001/2);
    int inc=0;//increment of number to the diagonal
    int value = 1;//number in diagonal
    int sum=1;
    short round_matrix = 1;//numbers times of round the matrix
    while(round_matrix <= max_jumps)
    {
    	inc +=2;//increment 
    	for(int times = 0; times < 4; times++)
    	{//always 4 numbers in diagonal
    		value += inc;//new value
    		sum +=value;//sum the number 
    	}
    	round_matrix++;//+1 for square
    }
    
    printf("%d \n",sum);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}

/*

43 44 45 46 47 48 49 50          	1 to 3  inc = 2   
42 21 22 23 24 25 26      			9 to 13  inc = 4
41 20  7  8  9 10 27				25 to 31   inc = 6
40 19  6  1  2 11 28
39 18  5  4  3 12 29 
38 17 16 15 14 13 30 
37 36 35 34 33 32 31 

*/
