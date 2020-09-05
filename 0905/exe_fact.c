#include <stdio.h>
#include <time.h>
double fact(int);
int main()
{
	int n = 1;
	clock_t start, end;
	start = clock();
	printf("%.0f\n", fact(n));
	end = clock();
	printf("%f\n", double(end - start)/CLOCKS_PER_SEC);

} 

double fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n-1); 
}
