#include <stdio.h>
#include <stdbool.h>
#define MAXDATA 1000

typedef struct HNode* Heap;
struct HNode{
	ElementType *Data;  //存储元素的数组
	int Size;   //堆中当前元素个数
	int Capacity;   //堆的最大容量
};

typedef Heap MaxHeap;
typedef Heap MinHeap;


MaxHeap CreateHeap(int MaxSize)
{
	/*创建容量为Maxsize的空的最大堆*/
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType)calloc(MaxSize+1, sizeof(ElementType));
	H->Size = 0；
	H->Capacity = MaxSize;
	H->Data[0] = MAXDATA;
	
	return H;
}


//最大堆的插入
bool IsFull(MaxHeap H)
{
	return (H->Size == H->Capacity);
}

bool Insert(MaxHeap H, ElementType X)
{
	int i;
	
	if (IsFull(H))
	{
		printf("最大堆已满");
		return false;
	}
	
	i = ++ H->Size; //i指向插入后堆中的最后一个元素的位置
	
	for (; H->Data[i/2] < X; i /= 2)
		H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
	
	return true;
}



#define ERROR -1
bool IsEmpty(MaxHeap H)
{
	return (H->Size == 0);
}

ElementType DeleteMax(MaxHeap H)
{
	/*从最大堆中取出键值为最大的元素，并删除一个结点（保持完全二叉树的形式）*/
	int parent, child;
	ElementType MaxItem, X;
	if (IsEmpty(H))
	{
		printf("最大堆为空");
		return ERROR;
	}
	
	MaxItem = H->Data[1];
	X = H->Data[H->Size--]   //x为最大堆的最后一个元素
	for (parent = 1; parent * 2 <= H->Size; parent = child)
	{
		child = parent * 2;
		if ((child != H->Size) && (H->Data[child] < H->Data[child+1]))
			child ++;
		if (X > H->Data[child])
			break;  //找到要插入的位置
		else
			H->Data[parent] = H->Data[child];   //将parent下面较大的那个child结点挪到上面来，x要往下面插
	}
	H->Data[parent] = X;    //X是大于parent下面的两个子节点的
	
	return MaxItem;
}



		
//最大堆的建立		
void PercDown(MaxHeap H, int p)
{
	/*将H中以H->Data[p]为根的子堆调整为最大堆*/
	int parent, child;
	ElementType X;
	
	X = H->Data[p];
	for (parent = p; parent * 2 <= H->Size; parent = child)   //从上往下调整，下滤
	{
		child = parent * 2;
		if ((child != H->Size) && (H->Data[child] < H->Data[child+1]))
			child++;
		if (X > H->Data[child])
			break;
		else
			H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = X;
}


void BuildHeap(MaxHeap H)
{
	int i;
	/*从最后一个结点的父节点开始，到根结点1*/
	for (i = H->Size / 2; i > 0, i--)
		PercDown(H, i);
}




	