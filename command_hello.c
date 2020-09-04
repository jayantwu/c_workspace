 #include <stdio.h>
 int atoi(char *s)
 int main(int argc, char *argv[])
{
	int i, times;
	if (argc < 2 || (times = atoi(argv[1]) < 1))
		printf("usage: %s positive-number\n", argv[0]);
	else
	{
		 for (i=1; i <= times; i++)
	        puts("hello, wujiayng");
	}
	    
     return 0;
}

int atoi(char *s)
{
	int i, n;
	for (i=0, n=0; *(s+i) >= '0' && *(s+i) <= '9'; ++i)
		n = 10*n + (*(s+i) - '0');
	return n;
	
}