#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char * defangIPaddr(char * address);

int main()
{
	char* address = "1.1.1.1";
	puts(defangIPaddr(address));
	
}

char * defangIPaddr(char * address){

    char * temp = (char *)malloc((strlen(address)+7)*sizeof(char));
	char * result = temp;
    while(*address != '\0')
    {
        if (*address == '.')
        {
            *temp = '[';
            *(++temp) = '.';
            *(++temp) = ']';
            address++;
			temp++;
        }
        else
		{
			*temp++ = *address++;
		}
		
    }
    *temp = '\0';
	return result;
}