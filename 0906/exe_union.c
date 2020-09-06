#include <stdio.h>

int main()
{
	union key{
		int k;
		char ch[2];
	}u;
	
	u.k = 258;
	printf("%d %d\n",u.ch[0], u.ch[1]);
	printf("%d %d", sizeof(int), sizeof(char));
	
	return 0;
} 



/* 输出为 2 1
int型为4字节，char类型为1个字节 

二进制为  100000010      字节序是反的？？ 
+--------+--------+ 
   ch[1]    ch[0] 
*/