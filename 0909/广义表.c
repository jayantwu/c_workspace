
typedef struct GNode* PtrToGNode;
typedef PtrToGNode GList;

struct GNode{
	int tag;
	union{
		ElementType Data;
		GList Sublist;
	}URegion;
	PtrToGNode Next;
} 