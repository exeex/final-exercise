#include<stdio.h>
#include<string.h>

typedef struct{
char str[20];
long profitA;
long profitB;

}Factory;

Factory FA[100000];



int compare(const void* a, const void* b)
{

    Factory * A = (Factory*)a;
    Factory * B = (Factory*)b;



    return -(A->profitA-A->profitB) + (B->profitA-B->profitB);

}

int compare_str(const void* a, const void* b)
{

    Factory * A = (Factory*)a;
    Factory * B = (Factory*)b;

	return	strcmp(A->str, B->str);


}


void main(){

	int n , x , y;
	scanf("%d %d %d", &n,&x,&y);

	int i;
	for(i=0; i<n; i++){
	scanf("%s %ld %ld", &(FA[i].str),&(FA[i].profitA),&(FA[i].profitB));
	}


	qsort(FA, n, sizeof(Factory),compare);

//	printf("\n");
//	for(i=0; i<n; i++){
//	printf("%s %d %d\n", (FA[i].str),(FA[i].profitA),(FA[i].profitB));
//	}


	int eCount =0;
	for(i=x+1; i<n; i++){
		if(FA[i].profitA==FA[i].profitB){
			eCount++;
		}
		else break;
	}


	qsort(FA, x+eCount, sizeof(Factory),compare_str);

//	printf("\n");
	for(i=0; i<x; i++){
	printf("%s\n", (FA[i].str), FA[i].profitA-FA[i].profitB);
	}


}


