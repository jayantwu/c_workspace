#include <stdio.h>
struct node
{
	int num[10];
	char name[10];
};
typedef struct node DATA[10];
typedef struct node* PtrToNode;

int main ()
{
    DATA A;  
	struct node B[10];
	A[0].num[0] = 1;
    B[0].num[0] = 2;
	printf("***%d***\n", A[0].num[0]);
	printf("***%d***\n", B[0].num[0]);
	return 0;
}
