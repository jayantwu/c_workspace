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



/* ���Ϊ 2 1
int��Ϊ4�ֽڣ�char����Ϊ1���ֽ� 

������Ϊ  100000010      �ֽ����Ƿ��ģ��� 
+--------+--------+ 
   ch[1]    ch[0] 
*/