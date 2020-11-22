/*剑指offer  17题 打印1到最大的n位数*/

bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	
	for (int i = nLength-1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength -1)
			nSum++;
		
		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
			
		else
		{
			number[i] = '0' + nSum；
			break;
		}
	}
	return isOverflow;
}


void PrintNumber(number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; ++i)
	{
		if(isBeginning0 && number[i]!='0') //第一次遇到不等于‘0’的字符时，才会赋值false；
			isBeginning0 = false;
		if(!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}



void PrintToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	
	char *number = (char*)calloc(n+1, sizeof(char));
	numnber[n] = '\0';
	
	while (!Increment(number))
		PrintNumber(number);
	
	free(number);
}




	