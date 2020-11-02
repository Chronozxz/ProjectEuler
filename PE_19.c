/*
Counting Sundays
 
Problem 19

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Answer:
	171
CPU:
    46    microseconds 
MEMORY:
    4400    kb
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
    int sundays =0;
    short year = 1901;
    int days = 0;
    //Thirty days*4 month  + thirty-one *7 month
    short month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    for(year; year<= 2000; year++){//1 Jan 1901 to 31 Dec 2000
        for(short numMonth = 0; numMonth<12;numMonth++){
            if( days%7 ==0)
                sundays++;
            if(numMonth == 1){
                if( (( year%4 ==0) && !(year%100 ==0)) || (year%400 ==0)){//Leap year?
                    days +=month[numMonth] +1;
                }else{
                    days +=month[numMonth]; 
                }
            }else{
                days +=month[numMonth];
            }
        }
    }
    
    printf("%d\n",sundays);
	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}