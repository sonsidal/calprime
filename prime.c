#include <stdio.h>
#include <stdlib.h>
#define NUM 100
#define SIZE_OF_TAB 100
#define RANGE 0
#define POINT 1

int *primeset;
int offset;

int isPrime(int x){
	int i;
	int count=0;
	for(i=0; i<offset; i++){
		if(x%primeset[i] == 0){
			return 0;
		}
	}
	
	return 1;
}

//for now, write from first of the file
void writePrime(){
	int i;
	FILE *fp = fopen("primes.txt", "w");
	fprintf(fp, "%d\n", offset);
	
	for(i=0; i<offset; i++){
		fprintf(fp, "%d ", primeset[i]);
	}

	fclose(fp);
}

void readPrime(){
	int i;
	FILE *fp = fopen("primes.txt", "r");
	fscanf(fp, "%d\n", &offset);
	for(i=0; i<offset; i++){
		fscanf(fp, "%d", &primeset[i]);
	}
}

int main(){
	int i;
	char c;
	int num;	//To store the number to check

	primeset = (int*)malloc(sizeof(int)*SIZE_OF_TAB);
	primeset[offset++] = 2;
	
	while(1){
		printf("Enter the number to check if it is prime.\n");
		scanf("%d", &num);
		if(num > 3)	break;
		printf("please enter the number greater than 2\n");
	}
	
	for(i=3; i<num; i++){
		if(isPrime(i) == 1)	primeset[offset++] = i;
	}
	
	for(i=0; i<offset; i++){
		printf("%d\n", primeset[i]);
	}

	writePrime();

}
