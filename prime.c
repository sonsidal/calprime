#include <stdio.h>
#include <stdlib.h>
#define NUM 100
#define SIZE_OF_TAB 100

int *primeset;
int offset;

int isPrime(int x){
	int i;
	int count=0;
	for(i=0; i<offset; i++){
		if(x%primeset[i] == 0)	count++;
	}
	return 1;
}

void insert_into_tab(int x){

}

int main(){
	int i;

	primeset = (int*)malloc(sizeof(int)*SIZE_OF_TAB);
	primeset[offset++] = 2;

	for(i=3; i<NUM; i++){
		if(isPrime(i) == 1)	insert_into_tab(i);
	}
	
}
