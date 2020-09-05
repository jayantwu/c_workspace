#include <string.h>

struct stud_node{
	int num;
	char name[20];
	int score;
	struct stud_node *next;
};



struct stud_node *Creat_Stu_Doc()
{
	int num, score;
	char name[20];
	int size = sizeof(struct stud_node);
	struct stud_node *head, *tail, *p;
	head = tail = NULL;
	printf("input num, name and score: \n");
	scanf("%d %s %d", &num, name, &score);
	while (num != 0)
	{
		p = (struct stud_node *)malloc(size);
		p -> num = num;
		strcpy(p -> name, name);
		p -> score = score;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		scanf("%d %s %d", &num, name, &score);
	}
	return head;
}


