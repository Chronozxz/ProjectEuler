/*
Number letter counts
  
Problem 17

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 
115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Answer:
	21124
CPU:
    44    microseconds 
MEMORY:
    4380    kb
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
                //  1 2 3 4 5 6 7 8 9
    short units[9]={3,3,5,4,4,3,5,5,4};//1 to 9
                //  10 11 12 13 14 15 16 17 18 19
    short teens[10]={3, 6, 6, 8, 8, 7, 7, 9, 8, 8};//10 to 19; teen
                //  20 30 40 50 60 70 80 90
    short tys [8]={  6, 6, 5, 5, 5, 7, 6, 6};//20 to 90; ty
    short hundreds = 7;//units + hundred 
    short one_thousand= 11;
    
    int sum = 0;
    int aux_num;
    for(int num = 1; num<1000; num++){//one to one thousand
        aux_num=num;
        if(aux_num >= 100){
            sum += hundreds;
            sum += units[(aux_num/100) -1];
            aux_num%=100;
            if(aux_num != 0)
                sum+=3;//and
        }
        if(aux_num>=20){
            sum += tys[(aux_num/10)-2];
            aux_num%=10;
        }
        if(aux_num>9){
            sum += teens[aux_num-10];
            aux_num=0;
        }else if(aux_num > 0){
            sum += units[aux_num-1];
        }
    }
    sum += one_thousand;
    
    printf("%d \n",sum);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}