#include <stdio.h>

//�����Ľṹ�� 
struct point {
	int x;
	int y;
};
//������εĽṹ�� 
struct rect {
	struct point p1;
	struct point p2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);


int main()
{
	struct point p1, p2;
	p1.x = 2;
	p1.y = 3;
	
	struct rect screen;
	
	screen.p1.x = 1;
	screen.p1.y = 2;
	screen.p2.x = 3;
	screen.p2.y = 4;
	
	screen.p1 = makepoint(5, 6);
	screen.p2 = makepoint(7, 8);
	
	struct point *pp;
	pp = &p1;
	printf("%d\n", pp->x);
	
	struct rect *scr_p;
	scr_p = &screen;
	printf("%d\n", scr_p->p1.x);
	 
	
} 

//��ʼ����Ľṹ 
struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;   //����һ������ֵ�Ľṹ����� 
}


//���������
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
} 
//�ж�һ�����Ƿ��ھ����� ��1Ϊ���ڣ�0Ϊ���� 
int ptinrect(struct point p, struct rect r)
{
	return  p.x > r.p1.x && p.x < r.p2.x 
          && p.y> r.p1.y && p.y < r.p2.y; 
}
