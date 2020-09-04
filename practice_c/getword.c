int getword(char word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch()))   //输入的字符为空格时，不做处理 
	     ;
	if (c != EOF)   //输入的字符不是EOF时，将字符存入word，同时指针指向后一个位置 
		*w++ = c;
	if (!isalpha(c))  //输入的字符不为字母时，在直接在指针所指的位置添加'\0' 并返回 
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()))  //输入的字符不是数字或字母时，将字符放回到输入中，并结束循环 
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
		
} 