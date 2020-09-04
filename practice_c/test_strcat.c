#include <stdio.h>
void strcat(char s[], char t[]);

int main()
 {
	char str1[80], str2[20];
	printf("input str1:");
	gets(str1);
	printf("input str1:");
	gets(str2);
	strcat(str1, str2);
	puts(str1);
	return 0;
 }
 
 void strcat(char s[], char t[])
 {
 	int i=0, j=0;
 	while (s[i] != '\0')
 		i++;
	while (t[j] != '\0')
		s[i++] = t[j++];
 }