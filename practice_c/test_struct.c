#include <stdio.h>

//定义点的结构体 
struct point {
	int x;
	int y;
};
//定义矩形的结构体 
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

//初始化点的结构 
struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;   //返回一个赋完值的结构体变量 
}


//两个点相加
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
} 
//判断一个点是否在矩形内 ，1为在内，0为不在 
int ptinrect(struct point p, struct rect r)
{
	return  p.x > r.p1.x && p.x < r.p2.x 
          && p.y> r.p1.y && p.y < r.p2.y; 
}
