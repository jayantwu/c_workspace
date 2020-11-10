#define MaxVertexNum 100
typedef int Vertex;   //这里顶点是用数组下标表示，因而时整型
typedef int WeightType;  //边的权值设为整数
typedef char DataType;

/*边的定义:两个顶点决定一条边，当然可能还有权值*/
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	WeightType Weight;  
};
typedef PtrToENode Edge;

/*邻接点的定义*/
typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;//邻接点下标
	WeightType Weight;
	PtrToAdjVNode Next;  //指向下一个邻接点的指针
	
};

typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	DataType Data;
}AdjList[MaxVertexNum];

typedef struct GNode* PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList G;   //邻接表     struct Vnode G[MaxVertexNum];
};
typydef PtrToGNode LGraph;

LGraph CreatGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;
	
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (Graph->G[V]; V < VertexNum; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}


void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	/*插入边<V1, V2>*/
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	
	/*无向图插入边<V2, V1>*/
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
	
}



/*这个函数和邻接矩阵的建立基本是一样的*/
Lgraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;  //申明顶点数
	
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	
		scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	
	/*如果顶点有数据，读入数据*/
	for (V = 0; V < Graph->Nv; V++)
		scanf("%c", &(Graph->G[V].Data));   //邻接表的data在数组中，
	
	return Graph;
}
	

