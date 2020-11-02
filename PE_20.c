/*
Factorial digit sum
  
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Answer:
	648
CPU:
    318    microseconds 
MEMORY:
    624    kb
ideone.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

#include <string.h>

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    int factorial = 100;
	int aux = 0;
	int sizeAns = 1;
	int sizeAnsAux = 1;
	int sizeNumC;
	int auxN =0;
	char numC[BUFSIZ];
	char *ans;
	char *ansAux;
	ans = (char *) malloc(sizeAns);
	ansAux = (char *) malloc(sizeAnsAux);
	ans[0] = '1';
	ansAux[0] ='0';
	
	for(int k = 2; k <= factorial; k++)
	{
		snprintf(numC, sizeof(numC), "%d", k);
		sizeNumC = (int) strlen(numC);
		aux=0;
		auxN=0;
		
		sizeAnsAux += sizeNumC -1;
		ansAux = (char*) realloc(ansAux, sizeAnsAux);
		memset(ansAux,'0',sizeAnsAux);
		
		for(int j = auxN;j < sizeNumC; j++)
		{
			for(int l=0; l<sizeAns; l++)
			{
				aux += (numC[sizeNumC-j-1] -48) * (ans[l] -48);
				
				aux+= ansAux[l+auxN] -48;
				ansAux[l+auxN]= (aux%10) +48;
				aux /=10;
				
				if( (l==sizeAns-1) && aux >0)
				{
					if((l+auxN) == sizeAnsAux-1)
					{
						sizeAnsAux++;
						ansAux = (char*) realloc(ansAux, sizeAnsAux);
						ansAux[l+auxN+1]= (aux%10) +48;
					}else{
						ansAux[l+auxN+1]= (aux%10) +48;
					}
					aux/=10;
				}
			}
			auxN ++;
		}
		sizeAns=sizeAnsAux;
		ans =(char *) realloc(ans, sizeAns);
		ans = strdup(ansAux);
	}
	
	/*
	printf("ans: ");
	for(int k = sizeAns; k>=0; k--)
	    printf("%c",ans[k]);
	printf("\n");*/
	
	int sumAns = 0;
	for(int k = 0; k <sizeAns; k++)
	{
		sumAns += ans[k]- 48;
	}
	printf("Sum ans = %d \n",sumAns);//648

	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}

