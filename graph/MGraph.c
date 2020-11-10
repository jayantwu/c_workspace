#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;   //这里顶点是用数组下标表示，因而时整型
typedef int WeightType;  //边的权值设为整数
typedef char DataType;


/*图结点的定义*/
typedef  struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];   //邻接矩阵
	DataType Data[MaxVertexNum];  //存顶点数据
};

typedef PtrToGNode MGraph;



/*边的定义:两个顶点决定一条边，当然可能还有权值*/
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	WeightType Weight;  
};
typedef PtrToENode Edge;



MGraph CreateGraph(int VertexNum)
{
	/*初始化一个右VertexNumge 顶点但没有边的图*/
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < VertexNum; V++)
		for (W = 0; W < VertexNum; W++)
			Graph->G[V][W] = INFINITY;
		
	return Graph;
}


void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	/*若是无向图，还需插入边<V2, V1>*/
	Graph->G[E->V2][E->V1] = E->Weight;
}



MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;  //这里只申明了一个顶点变量，因为有了顶点之后可以创建一个图，边可以再插入，直接有结构体中的变量来scanf获取
	
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
		scanf("%c", &(Graph->Data[V]));
	
	return Graph;
}


		
	




