#include <stdio.h>

 typedef int Position;
 typedef struct LNode* PtrToLNode;
 
struct LNode{
 	ElementType Data[MAXSIZE];
 	Position Last;
 };

 typedef PtrToLNode List;
 //L 是指向这个结构体的指针，也可以说是指向这个表的表头 
 List L； 
 
 //顺序表的初始化,Last记录了表的长度，L->Last+1为长度 
 List MakeEmpty()
 {
 	List L;
 	L = (List)malloc(sizeof(struct LNode));
 	L->Last = -1;
 	return L;
 } 
 
 
 //顺序表的查找,遍历 
 
 #define ERROR -1
 Position Find(List L, ElementType X)
 {
 	Position i = 0;
 	while (i < L->Last && L->Data[i] != X)
	 	i++;
	if (i > L->Last)
		return ERROR;
	else
		return i;
		
 } 
 
 
 //插入
 bool Insert(List L, ElementType X, int i)
 {
 	/*在L的指定位置i前插入一个新元素X，i元素的数组下标是i-1*/
 	Position j;
	if (L->Last == MAXSIZE-1)
	{
		printf("表满");
		return false; 
	}
	if (i < 1 || i > L->Last+2)
	{
		printf("位序不合法")；
		return false; 
	}
	
	for (j = L->Last; j >= i-1; j--)

		L->Data[j+1] = L->Data[j];
	L->Data[i-1] = X;
	L->Last++;
	return true; 
	
 } 
 
 //删除
//删除第i个元素 ，下标为i-1 
bool Delete(List L, int i)  
{
	Position j;
	
	if (i < 1 || i > L->Last)
	{
		printf("位序%d不存在元素", i);
		return false;	
	} 
	for (j = i; j < L->Last; j++)
	
		L->Data[j-1] = L->Data[j];
	L->Last--;
	return true;
		
} 
 
 
 
 
 
  
 