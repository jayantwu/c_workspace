/*maze problem*/
#include <stdio.h>
#include <stdbool.h>
#define MAXMATRIXSIZE 100
#define MAXSTACKSIZE 100

struct Offsets{   //偏移量结构定义 
	short int Vert;   //纵向偏移 
	short int Horiz;   //横向偏移 
};

struct MazePosition{
	short int Row;
	short int Col;
	short int Dir;   //方向号 
};

typedef struct MazePosition ElementType;  //堆栈的元素类型


Void Path(int Maze[][MAXMATRIXSIZE], int EXITROW, int EXITCOL)
{
	struct Offset Move[8] = {
		{-1, 0},
		{-1, 1},
		{0, 1},
		{1, 1},
		{1, 0},
		{1, -1},
		{0, -1},
		{-1, -1},
	};
	
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE];//标记走过的位置
	Stack S;
	struct MazePosition P;
	short int Row, Col, NextRow, NextCol, Dir;
	bool Found = false; 
	
	S = CreateStack(MAXSTACKSIZE);
	
	Mark[EXITROW][EXITCOL] = 1;
	//将出口位置及下个方向放入堆栈
	P.Row =  EXITROW;
	P.Col = EXITCOL;
	P.Dir = 0;
	Push(S, P);
	
	while (!IsEmpty(S) && !Found)
	{
		P = Pop(S); //取出栈顶元素为当前的位置 ，对于第一次循环，当前位置为出口坐标 
		Row = P.Row; Col = P.Col; Dir = P.Dir;
		while (Dir < 8 && !Found)//当还有方向可探且没找到入口时 
		{
			/*尝试往下一个方向dir移动*/
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if (NextRow == 1 && NextCol == 1)
				Found = true;   //找到入口
			else   //下一个位置不是入口 
				//下一个位置可通且没有走过 
				if (!Maze[NextRow][NextCol] && !Mark[NextRow][NextCol])
				{
					Mark[NextRow][NextCol] = 1;  //标记走过
					/*当前位置和下一个方向入栈*/
					P.Row = Row;
					P.Col = Col;
					P.Dir = Dir + 1;
					Push(S, P);
					//更新当前位置，从方向0开始
					Row = NextRow; Col = NextCol; Dir = 0; 
				} 
				else
					++Dir;
		}
	
	}
	if (Found)
	{
		printf("找到路径如下\n");
		printf("行 列\n");
		printf("1 1\n");
		printf("%d %d\n", Row, Col);
		while(!IsEmpty(S))
		{
			P = Pop(S);
			printf("%d %d\n", P.Row, P.Col);
		}
	}
	else
		printf("迷宫无解\n");
} 