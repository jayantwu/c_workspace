/*maze problem*/
#include <stdio.h>
#include <stdbool.h>
#define MAXMATRIXSIZE 100
#define MAXSTACKSIZE 100

struct Offsets{   //ƫ�����ṹ���� 
	short int Vert;   //����ƫ�� 
	short int Horiz;   //����ƫ�� 
};

struct MazePosition{
	short int Row;
	short int Col;
	short int Dir;   //����� 
};

typedef struct MazePosition ElementType;  //��ջ��Ԫ������


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
	
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE];//����߹���λ��
	Stack S;
	struct MazePosition P;
	short int Row, Col, NextRow, NextCol, Dir;
	bool Found = false; 
	
	S = CreateStack(MAXSTACKSIZE);
	
	Mark[EXITROW][EXITCOL] = 1;
	//������λ�ü��¸���������ջ
	P.Row =  EXITROW;
	P.Col = EXITCOL;
	P.Dir = 0;
	Push(S, P);
	
	while (!IsEmpty(S) && !Found)
	{
		P = Pop(S); //ȡ��ջ��Ԫ��Ϊ��ǰ��λ�� �����ڵ�һ��ѭ������ǰλ��Ϊ�������� 
		Row = P.Row; Col = P.Col; Dir = P.Dir;
		while (Dir < 8 && !Found)//�����з����̽��û�ҵ����ʱ 
		{
			/*��������һ������dir�ƶ�*/
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if (NextRow == 1 && NextCol == 1)
				Found = true;   //�ҵ����
			else   //��һ��λ�ò������ 
				//��һ��λ�ÿ�ͨ��û���߹� 
				if (!Maze[NextRow][NextCol] && !Mark[NextRow][NextCol])
				{
					Mark[NextRow][NextCol] = 1;  //����߹�
					/*��ǰλ�ú���һ��������ջ*/
					P.Row = Row;
					P.Col = Col;
					P.Dir = Dir + 1;
					Push(S, P);
					//���µ�ǰλ�ã��ӷ���0��ʼ
					Row = NextRow; Col = NextCol; Dir = 0; 
				} 
				else
					++Dir;
		}
	
	}
	if (Found)
	{
		printf("�ҵ�·������\n");
		printf("�� ��\n");
		printf("1 1\n");
		printf("%d %d\n", Row, Col);
		while(!IsEmpty(S))
		{
			P = Pop(S);
			printf("%d %d\n", P.Row, P.Col);
		}
	}
	else
		printf("�Թ��޽�\n");
} 