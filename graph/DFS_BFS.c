//邻接表为例
void Visit(Vertex V)
{
	printf("访问顶点%d\n", V);
}

/*该函数可以访问一个连通分量的所有顶点*/
void DFS(LGraph Graph, Vertex V, void(*Visit)(Vertex))  //入参说明：1、一个图， 2、开始访问的结点，3、visit函数
{
	PtrToAdjVNode W;
	Visit(V);   //访问第V个顶点
	Visited[V] = true;
	
	for (W = Graph->G[V].FirstEdge; W; W = W->next)
		if (!Visited[W->AdjV])   //若W->AdjV未被访问过
			DFS(Graph, W->AdjV, Visit);
}




void ListComponents(LGraph Graph)
{
	Vertex V;
	
	for (V = 0; V < Graph->Nv; V++)   //遍历所有顶点
		if (!Visited[V])
			DFS(Graph, V, Visit);
}

//广度优先搜索  邻接矩阵为例
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true:false;
}


void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	Queue Q;
	PtrToAdjVNode W;
	Q = CreateQueue(MaxSize);
	
	Visit(S);
	Visited[S] = true;
	AddQ(Q, S);
	
	while (!IsEmpty(Q))
	{
		V = DeleteQ(Q);   //出队，扫描新的顶点的这一行
		for (W=0; W < Graph->Nv; W++)   //扫描V的这一行，扫描到邻接点，就入队
			if(!Visited[W] && IsEdge(Graph, V, W))   //W没有被访问过而且是V的邻接点  
			{
				Visit(W);
				Visited[W] = true;
				AddQ(Q, W);  //W入队
			}
	}
}


/*
*如果是邻接矩阵的深度优先搜索
*大概流程：扫描起始顶点的这一行，遇到一个邻接点之后，扫描该邻接点所在的那一行，即再次调用DFS()
*/

void DFS(MGraph Graph, Vertex V, void(*Visit)(Vertex))  //入参说明：1、一个图， 2、开始访问的结点，3、visit函数
{
	Vertex W;
	Visit(V);   //访问第V个顶点
	Visited[V] = true;
	
	for (W = 0; W < Graph->Nv ; W++)
		if (!Visited[W] && IsEdge(Graph, V, W))   //若W未被访问过且是V的邻接点
			DFS(Graph, W, Visit);
}


/*
*如果是邻接表的广度优先搜索
*大概流程：
*/
void BFS(LGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	Queue Q; //用来将邻接点入队  这个队列的ElementType为Vertex    
	PtrToAdjVNode W;
	Q = CreateQueue(MaxSize);
	
	Visit(S);
	Visited[S] = true;
	AddQ(Q, S);
	
	while (!IsEmpty(Q))
	{
		V = DeleteQ(Q);   //出队，扫描新的顶点的这一行
		for (W=Graph->G[V].FirstEdge; W; W = W->next)   //从某个顶点开始，
			if(!Visited[W->AdjV])   //邻接点W没有被访问过 
			{
				Visit(W->AdjV);
				Visited[W->AdjV] = true;
				AddQ(Q, W->AdjV);  //结点W对应的顶点入队
			}
	}
}