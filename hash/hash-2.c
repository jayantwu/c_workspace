#define KEYLENGTH 15
typedef char ElementType[KEYLENGTH+1];
typedef int Index;

typedef struct LNode *PtrToLNode;
struct LNode{
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToNode List;


typedef struct TblNode* HashTable;
struct TblNode{      //散列表结点定义
	int TableSize;  //表的最大长度
	List Heads;     //指向链表头结点的数组
};


HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;
	
	H = (HashTable)malloc(sizeof(struct TblNode));
	
	H->TableSize = NextPrime(Tablesize); 
	
	/*分配链表头结点数组*/
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	/*初始化表头结点*/
	for (i = 0; i < H->TableSize; i++)
	{
		H->Heads[i].Data = '\0';
		H->Heads[i].Next = NULL;
	}
	
	return H;
}

Position Find(HashTable H, ElementType key)
{
	Position P;
	Index Pos;
	
	Pos = Hash(key, H->TableSize);  //初始散列位置
	P = H->Heads[Pos].Next;
	while(P && strcmp(P->Data, key))  //当未到表尾，并且key未找到时
		P = P->Next;
	return P;  //此时p为找到的结点或者null（没找到）
}



bool Insert(HashTable H, ElementType key)
{
	Position P, NewCell;
	Index Pos;
	
	P = Find(H, key);
	if (!P) //未找到时
	{
		NewCell = (Position)malloc(sizeof(struct LNode));
		
		strcpy(NewCell->Data, key);
		Pos = Hash(key, H->TableSize);
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else
	{   //关键字存在
		printf("键值已存在");
		return false;
	}
}

void DestroyTable(HashTable H)
{
	int i;
	Position P, Tmp;
	
	/*释放每个链表的结点*/
	for (i = 0; i < H->TableSize; i++)
	{
		P = H->Heads[i].Next;
		while(P)
		{
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
		
	}
	
	free(H->Heads); //释放头节点数组
	free(H); //释放散列表结点
}




	

	
	
	
	





