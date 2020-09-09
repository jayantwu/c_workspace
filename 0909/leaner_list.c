#include <stdio.h>

 typedef int Position;
 typedef struct LNode* PtrToLNode;
 
struct LNode{
 	ElementType Data[MAXSIZE];
 	Position Last;
 };

 typedef PtrToLNode List;
 //L ��ָ������ṹ���ָ�룬Ҳ����˵��ָ�������ı�ͷ 
 List L�� 
 
 //˳���ĳ�ʼ��,Last��¼�˱�ĳ��ȣ�L->Last+1Ϊ���� 
 List MakeEmpty()
 {
 	List L;
 	L = (List)malloc(sizeof(struct LNode));
 	L->Last = -1;
 	return L;
 } 
 
 
 //˳���Ĳ���,���� 
 
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
 
 
 //����
 bool Insert(List L, ElementType X, int i)
 {
 	/*��L��ָ��λ��iǰ����һ����Ԫ��X��iԪ�ص������±���i-1*/
 	Position j;
	if (L->Last == MAXSIZE-1)
	{
		printf("����");
		return false; 
	}
	if (i < 1 || i > L->Last+2)
	{
		printf("λ�򲻺Ϸ�")��
		return false; 
	}
	
	for (j = L->Last; j >= i-1; j--)

		L->Data[j+1] = L->Data[j];
	L->Data[i-1] = X;
	L->Last++;
	return true; 
	
 } 
 
 //ɾ��
//ɾ����i��Ԫ�� ���±�Ϊi-1 
bool Delete(List L, int i)  
{
	Position j;
	
	if (i < 1 || i > L->Last)
	{
		printf("λ��%d������Ԫ��", i);
		return false;	
	} 
	for (j = i; j < L->Last; j++)
	
		L->Data[j-1] = L->Data[j];
	L->Last--;
	return true;
		
} 
 
 
 
 
 
  
 