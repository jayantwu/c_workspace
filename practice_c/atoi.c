 #include <stdio.h>
 int atoi(char *s);
 
 int main()
 {
 	 int n=2;
     char s[10];
     printf("input a num: ");
	 gets(s);
	 printf("%d", n * atoi(s));
	 return 0;
	 
 }


int atoi(char *s)
{
	int i, n;
	for (i=0, n=0; *(s+i) >= '0' && *(s+i) <= '9'; ++i)
		n = 10*n + (*(s+i) - '0');
	return n;
	
}
