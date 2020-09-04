#include <stdio.h>

int main()
{
	float n1 = 3.0;
	double n2 = 4.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
	printf("%f %f %ld %ld\n", n1, n2, n3, n4);
	printf("%p %p %p %p\n", &n1, &n2, &n3, &n4);
	printf("%d %d %d %d\n", sizeof(float), sizeof(double), sizeof(long), sizeof(long));
}


//0 1074266112 0 1074790400
//3.000000 4.000000 2000000000 1234567890
//0060FF24 0060FF18 0060FF14 0060FF10
