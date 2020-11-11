#include<stdio.h>

void fun1(int x);
void fun2(int x);
void fun3(int x);
void funcall1(void(*fun)(int), int x);
void funcall2(p, int x;);
typedef void(*)(int) p;


int main()
{
	funcall1(fun1, 1);
	funcall1(fun2, 2);
	funcall1(fun3, 3);
	funcall1(fun1, 1);
	funcall1(fun2, 2);
	funcall1(fun3, 3);
	
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


void funcall2(p fun, int x)
{
	fun(x);
}
	