/****************************************************************************
队列-特殊的线性数据结构
先进先出，只允许在队列的首部进行删除操作（出队），在队列的尾部进行插入操作
（入队）

问题：解密QQ号
	输入一串加密的数字，首先将第一个数删除，紧接着将第二个数放到这串数的末尾
再将第三个数删除，将第四个数放到这串数的末尾...直到剩下最后一个数，将最后一
个数也删除,真正的qq号则由这些删除的数组成
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct queue
{
	int data[100];
    int head;
    int tail;
};

int main()
{
	struct queue que;
    int num, i=0;
    int qq[20];
    //初始化队列
    que.head = 0;
    que.tail = 0;
	//输入加密的qq号
    scanf("%d", &num);
    for(que.tail; que.tail<num; que.tail++){
		scanf("%d", &que.data[que.tail]);
    }
    //que.tail++;
    
    //decode
    while(que.tail != que.head){
		//删除这个数
		qq[i] = que.data[que.head];
        i++;
        que.head++;
        //将下一个数移至队尾
        que.data[que.tail] = que.data[que.head];
        que.head++;
        que.tail++;
    }
    qq[i] = que.data[que.head]; 
    //print result
    for(i=0; i<num; i++){
		printf("%d ", qq[i]);
     }
    
    printf("\n");
	system("pause");
	return 0;
}
