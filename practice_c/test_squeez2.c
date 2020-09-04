#include <stdio.h>
void squeeze2(char s[], char t[] ); 

int main()
{
	char str1[80], str2[80];
	
	printf("input a str1:");
	gets(str1);
	printf("input str2:");
	gets(str2);
	//puts(str1);
	//puts(str2);
	squeeze2(str1, str2);
	printf("after del : ");
	puts(str1);
	
	return 0;
	
}

void squeeze2(char s[], char t[])
{
	int i, j, k=0;
	//puts(s);
	for (i = 0; s[i] != '\0'; i++)
	{
		//printf("*********\n");
		for (j = 0; t[j] != '\0'; j++)
		{
			//printf("xxxxxxxx\n");
			if ((s[i] != t[j]) && (t[j+1] == '\0'))
				s[k++] = s[i];
			else if (s[i] == t[j])
				break;
   			else
			   continue;
		}	
	}
	s[k] = '\0';
}
