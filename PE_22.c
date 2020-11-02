/*
Names scores

Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
Answer:
    871198282 
CPU:
    847201    microseconds 
MEMORY:
    1652    kb
onlinegdb.com
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

#include <string.h>

struct WordList//struct list
{
    char name[15];
    struct WordList *next;
}WordList;
typedef struct WordList* WLPtr;//typedef

void PrintList(WLPtr ListHead)//printf list
{
    while(ListHead)
    {
        printf("%s \n",ListHead->name);//print name
        ListHead = ListHead->next;
    }
}

int isLess(char auxName[15],char tempName[15])
{
    int sizeName;
    sizeName = (strlen(auxName)> strlen(tempName)) ? strlen(auxName): strlen(tempName);

    for(int index = 0; index < sizeName; index++)
    {
        if(auxName[index] == tempName[index])
        {
            continue;
        }else if(auxName[index] > tempName[index]){
            return 1;
        }else{
            return 0;
        }
    }
    if(strlen(auxName)> strlen(tempName))
        return 1;
    return 0;
}

int saveName(WLPtr* nl, char name[15])
{//save name in list sort
    WLPtr tempWL = (WLPtr) malloc(sizeof(WordList));//New node
    if(! tempWL)//memory is null
    {
        printf("Memory is null\n");
        return 0;
    }
    
    strcat(name,"\0");
    strcpy(tempWL->name,name);
    tempWL->next = NULL;
    
    WLPtr auxWL = *nl;
    if(!auxWL )//if nl Null
    {
       *nl = tempWL;
        return 1;
    }else{//sort name in list
        while(1)
        {
            if( isLess(auxWL->name, tempWL->name) ){
                name = strdup(auxWL->name);
                strcpy(auxWL->name, tempWL->name);
                strcpy(tempWL->name,name);
                
                tempWL->next = auxWL->next;
                auxWL->next = tempWL;
                
                return 1;
            }else{
                if(!auxWL->next)
                {
                    auxWL->next = tempWL;
                    return 1;
                }else{
                    auxWL = auxWL->next;
                }
            }
        }
    }
    return 0;
}

WLPtr getNames(WLPtr nl)
{//get names of file txt
    FILE *fileTXT;
	char fileName[32]="names.txt";
	char strLine[256];
	char name[15];
	short firstQuotations =0;
	short indexName;
	int numName=1;
	
	fileTXT=fopen(fileName, "r");//rename directory for txt ubication
	while( fscanf(fileTXT, "%s ", strLine) == 1)
	{
		for(int k = 0; k < strlen(strLine); k++ )
		{
			if(strLine[k] == '"')
			{
				if(firstQuotations){
					firstQuotations=0;
					//printf("----------------------%d----------------------\n",numName);
					numName++;
					if( !saveName(&nl, name) )
					    printf("Error al guardar");
				}else{
					firstQuotations=1;
					memset(name,'\0',15);
					indexName=0;
				}
			}else if(firstQuotations){
				name[indexName]=strLine[k];
				indexName++;
			}
		}
	}
	fclose(fileTXT);
	return nl;
}

int getScoreName(char name[15])
{
	int nameScore = 0;
	int size = strlen(name);
	
	for(int k=0; k < size; k++)
		nameScore += name[k]-64;
	
	return nameScore;
}

int getScore(WLPtr nl)
{
	int multp=1;
	int score=0;
	
	while(nl)
	{
		score += multp * getScoreName(nl->name);
		nl = nl->next;
		multp++;
	}
	return score;
}

int main(){
    struct timeval t, t2;
    struct rusage use;
    int microseconds;
    gettimeofday(&t, NULL);
    //---------------------------Program v-------------------------------
    WLPtr nameList = NULL;
	int score;

	nameList = getNames(nameList);
	score = getScore(nameList);
	//PrintList(nameList);
	printf("%d \n",score);

	//---------------------------Program ^-------------------------------
	gettimeofday(&t2, NULL);
    microseconds = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("time code: %d microseconds\n",microseconds);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory: %ld KB\n", (long)use.ru_maxrss);
	return 0;
}