#include <stdio.h>
#include <stdlib.h>

char* replaceSpace(char* s){
    int space_num = 0;
    int len = 0;
    char *temp = s;
    while (*temp)
    {
        len++;
        if (*temp == ' ')
            space_num++;
        temp++;
    }
	len++;
	//len的长度不包含'\0'
	printf("%d %d\n", space_num, len);
    //temp此时指向原字符串的'\0'
    int newLength = len + 2*space_num;
	//char *p = (char*)realloc(s, newLength*sizeof(char));
    //char *p = s;  //p指向新的字符串的'\0'位置
	char *p = (char*)malloc(newLength*sizeof(char));
	p = p + newLength;
    while (len--)
    {
        if (*temp == ' ')
        {
            *p-- = '0';
            *p-- = '2';
            *p-- = '%';
			//printf("****");
        }
        else
            *p-- = *temp;
        temp--;
		//printf("%c", *temp);
		//printf("%c", *(p+1));
    }
	return p+1;
    
}


int main()
{
	char *s = "We are happy, and what about you?";
	char *p = replaceSpace(s);
	puts(p);
	return 0;
}
