#define MAXTABELSIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;

/*散列函数状态类型，分别对应 有合法元素，空单元，有已删除元素*/
typedef enum {Legitimate, Empty, Deleted} EntryType;

typedef struct HashEntry Cell;  //散列表单元类型
struct HashEntry {
	ElementType Data;   //存放的元素
	EntryType Info;     //单元的状态，枚举格式，三种状态
};

typedef struct TblNode *HashTable;
struct TblNode {      //散列表结点定义
	int TableSize;    //表的最大长度
	Cell *cells;      //存放散列单元元素的数组
};



int NextPrime(int N)
{
	//返回大于N且不超过MAXTABLESIZE的最小素数
	int i, p = (N % 2) ? N + 2 : N + 1; //从大于N的下一个奇数开始
	while (p < MAXTABELSIZE)
	{
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p % i)) break; 
		if (i == 2)
			break;
		else
			p += 2;
	}
	return p;
}


HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->cells = (Cell*)malloc(H->TableSize*sizeof(Cell));
	/*初始化单元状态为空单元*/
	for (i=0; i < H -> TableSize; i++)
		H -> cells[i].info = Empty;
	return H;
	
}


/*平方探测法的查找函数Find*/
Position Find(HashTable H, ElementType key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; //记录冲突次数
	
	NewPos = CurrentPos = Hash(key, H->TableSize)   /*初始化散列位置*/
    /*当该位置的单元非空，并且不是要找的元素时，发生冲突；如果该位置单元空则说明没找到*/
	while (H->cells[NewPos].info != Empty && H->cells[NewPos].Data != key)
	{
		if (++CNum % 2) 
		{   //奇数次冲突
			NewPos = CurrentPos + (CNum+1) * (CNum+1) /4;
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H -> TableSize;  //调整为合法位置
		}
		else
		{//偶数次冲突
			NewPos = CurrentPos - CNum * CNum / 4;
			while (NewPos < 0)
				NewPos += H->TableSize;   //调整为合法位置
		}
	}
	
	return NewPos;
	
	
bool Insert(HashTable H, ElementType key)
{
	Position Pos = Find(H, Key);  //find返回一个位置，空位置或者key的位置
	if (H->cells[Pos].info != Legitimate)
	{
		H->cells[Pos].Info = Legitimate;
		H->cells[Pos].Data = key;
		return true;
	}
		
	else
	{
		printf("键值已存在");
		return false;
	}
}

			
			

			   

	