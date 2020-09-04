#include <stdio.h>
#define SIZE 10
int sump(int * start, int *end);
int main()
{
	int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long answer;
	
	answer = sump(marbles, marbles+SIZE);
	
	printf("the total number of marbles is %d.\n", answer);
	
	return 0;
	
}


int  sump(int *start, int *end)
{
	int total = 0;
	while (start < end)
	{
		total += *start++; 
	}
	return total;
}