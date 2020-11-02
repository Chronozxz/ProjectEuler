/*
1000-digit Fibonacci number
Problem 25
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
Answer:
    4782
CPU:
    152717    microseconds 
MEMORY:
    608    kb
onlinegdb.com
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short GetFibonacci(char *F, short ix_F, char *FO, short ix_FO,  char *FT, short ix_FT)//Fibonacci, FnOne, FnTwo
{
	short sum=0, index, numFO, numFT;
	
	for(index = 0; index < ix_FO; index++)
	{
	    numFO = FO[index] -48;//digit of F(n-1)
	    
	    if(index < ix_FT)//if ix_FO > ix_FT, not count the numbers of F(n-2) if strlen(f(n-2)) < strlen(f(n-1))
	    {
            numFT = FT[index] -48;//digit of F(n-2)
	    }else{
            numFT = 0;
	    }
	    
	    sum += numFO + numFT;
	    //printf("S=%d,O=%d,T=%d ---",sum,numFO,numFT);
        if(sum <10)
        {
           //printf("if - ");
           F[index] = sum +48;
           sum=0;
        }else{
           //printf("else - ");
           F[index] = (sum%10)+48;
           sum/=10;
        }
	    
	}
	
	if(sum>0){//the sum is more bigger than 0, next index of fibonacci
	    ix_F++;
		F[index] = sum +48;
	}
    
    return ix_F;//return the new index for fibonacci
}

int main(int argc, char **argv)
{
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    
	char *FnOne;//fibonacci -1 
	char *FnTwo;//fibonacci -2
	char *Fibonacci;
	int numTerm = 2;
	
	Fibonacci = (char *) malloc(sizeof(char)* 1000);
	FnOne = (char *) malloc(sizeof(char)* 999);
	FnTwo = (char *) malloc(sizeof(char)* 999);
	FnOne[0]= '1';
	FnTwo[0]= '1';
	Fibonacci[0]= '0';
	short idx_FO=1, idx_FT=1, idx_F=1;
	
while(idx_F != 1000 )//the chain is more great that 1000 digits
	{
	    numTerm++;//the th number of fibonacci
	    
		idx_F = GetFibonacci(Fibonacci, idx_F, FnOne, idx_FO,  FnTwo, idx_FT);//F = FO + FT 

		strcpy(FnTwo,FnOne);// of F(n-1) to F(n-2)
		strcpy(FnOne,Fibonacci);//of fibonacci(n) to F(n-1)
		idx_FT = idx_FO;//update indexs
		idx_FO = idx_F;

	}
	
	printf("%d \n",numTerm);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}





