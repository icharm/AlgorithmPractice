/**********************************************************************
链表
单向链表、单向循环链表、双向链表

单向链表可以用来实现队列数据结构

下面实现单向链表的插入，删除、逆置操作

链表的两个结点的交换比较麻烦

*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//结点结构体
struct node
{
	int data;
	struct node * next;
};

//打印链表中的数据
void printList(struct node * head)
{
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\r\n");
}

//释放链表申请的内存空间
void freeList(struct node * head)
{
	struct node * p = head->next;
	while(p != NULL){
		free(head);
		head = p;
		p = p->next;
	}
	free(head); //释放最后一个节点
}

//插入，在第num个节点之后插入新的数据
void insertAfterNum(struct node * head, int num, int data)
{
	int i=0;
	struct node * p = head, *t;
	//寻找第num个节点,并用p指向这个节点
	for(i=0; i<num-1; i++){	//这里是num-1, 而不是num !important
		p = p->next;
	}
	t = (struct node *)malloc(sizeof(struct node));
	t->data = data;
	t->next = p->next; //新节点next指向下一个p的下一个节点
	p->next = t;	//p节点的next指向新节点
	
}

//删除第num个节点
void deleteNodeNum(struct node * head, int num)
{
	int i;
	struct node *mid = head, *left, *right;
	for(i=0; i<num-2; i++){ //寻找第num个节点的前一个节点
		mid = mid->next;
	}
	left = mid;
	mid = mid->next;
	right = mid->next;
	free(mid); //释放第num个节点
	left->next = right; //连接断掉的链表
}

//逆置一个链表, 返回链表新的头
struct node * inverse(struct node * head){
	struct node * left=head, *mid=left->next, *right=mid->next;
	while(right != NULL){
		if(left == head)
			left->next = NULL; //将新的尾结点指向空，不然会出现链表无法结束的情况 !important
		mid->next = left; //将中间的结点指向左边的结点
		left = mid; 
		mid = right;
		right = right->next;
	}
	mid->next = left;
	return mid;
}

int main()
{
	struct node * head;	//表头结点
	//临时指针
	struct node *p, *q, *t;
	int i,v;
	//结点数量
	int n;
	scanf("%d", &n);
	

	//初始化表头结点
	head = NULL;

	//循环读入n个数
	for(i=0; i<n; i++){
		scanf("%d", &v);
		p = (struct node *)malloc(sizeof(struct node)); //动态申请一个结点
		p->data = v;
		p->next = NULL;
		if(head == NULL)	//判断是否为表头结点
			head = p;
		else
			q->next = p;
		q = p;
	}

	//输出链表中的所有数
	printList(head);
	
	insertAfterNum(head, 3, 10);

	printList(head);

	deleteNodeNum(head, 2);

	printList(head);

	head = inverse(head);

	printList(head);
	
	freeList(head);
	getchar();
	getchar();
	return 0;
}
