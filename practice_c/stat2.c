#include <stdio.h>
//统计数字，空格，其他字符的个数 
int main()
{
	 int c, i, nwhite, nother;
	 int ndigit[10];
         int j;
	 nwhite = nother = 0;
	 for (i = 0; i < 10; ++i)
	 	ndigit[i] = 0;
 	
 	while ((c = getchar()) != EOF)
 	{
	     if (c >= '0' && c <='9')
	 	     ++ndigit[c-'0'];
         else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
         else
            ++nother;
             
	 }
	 printf("digits =");
	 for (i = 0; i < 10; ++i)
	     printf(" %d", ndigit[i]);
     printf(", white space = %d, other = %d\n", nwhite, nother);
     
     //打印数字出现的频次直方图
	 for (i = 0; i < 10; ++i)
	 {
 		printf("%d ", i);
		 for (j = 1; j <= ndigit[i]; ++j)
 		    printf("%c", '*');
        printf("\n");
 	} 
      
}


/*
digits = 7 3 5 12 16 18 14 22 13 14, white space = 1, other = 0
0 *******
1 ***
2 *****
3 ************
4 ****************
5 ******************
6 **************
7 **********************
8 *************
9 **************
*/
