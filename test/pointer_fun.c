#include<stdio.h>

void fun1(int x);
void fun2(int x);
void fun3(int x);
void funcall(void(*fun)(int), int x);
typedef void(*)(int) p;


int main()
{
	funcall(fun1, 1);
	funcall(fun2, 2);
	funcall(fun3, 3);
	
	return 0;
}


void fun1(int x)
{
	printf("我是函数%d\n", x);
}


void fun2(int x)
{
	printf("我是函数%d\n", x);
}

void fun3(int x)
{
	printf("我是函数%d\n", x);
}



void funcall1(void(*fun)(int), int x)
{
	fun(x);
}
