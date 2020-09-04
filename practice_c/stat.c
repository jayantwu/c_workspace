#include <stdio.h>
#define IN  0
#define OUT 1 
/*统计 输入的行数，单词数和字符数 */ 

int main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
		    ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
        	state = IN;
        	++nw;
        }
	}
	printf("%d %d %d\n", nl, nw, nc);
}