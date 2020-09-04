int getword(char word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch()))   //������ַ�Ϊ�ո�ʱ���������� 
	     ;
	if (c != EOF)   //������ַ�����EOFʱ�����ַ�����word��ͬʱָ��ָ���һ��λ�� 
		*w++ = c;
	if (!isalpha(c))  //������ַ���Ϊ��ĸʱ����ֱ����ָ����ָ��λ�����'\0' ������ 
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()))  //������ַ��������ֻ���ĸʱ�����ַ��Żص������У�������ѭ�� 
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
		
} 