#include <stdio.h> 
#include <stdlib.h>
void floatsplit(float x, int *intpart, float *fracpart);

int main()
{
	float x = 12.33;
	int *intpart;
	float *fracpart;
	intpart = (int *)malloc(sizeof(int));
	fracpart = (float *)malloc(sizeof(float));
	floatsplit(x, intpart, fracpart);
	
} 

void floatsplit(float x, int *intpart, float *fracpart)
{
	*intpart = int(x);
	*fracpart = x - *intpart;
	printf("%d %f\n", *intpart, *fracpart);

}