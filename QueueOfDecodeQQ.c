/****************************************************************************
����-������������ݽṹ
�Ƚ��ȳ���ֻ�����ڶ��е��ײ�����ɾ�����������ӣ����ڶ��е�β�����в������
����ӣ�

���⣺����QQ��
	����һ�����ܵ����֣����Ƚ���һ����ɾ���������Ž��ڶ������ŵ��⴮����ĩβ
�ٽ���������ɾ���������ĸ����ŵ��⴮����ĩβ...ֱ��ʣ�����һ�����������һ
����Ҳɾ��,������qq��������Щɾ���������
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
    //��ʼ������
    que.head = 0;
    que.tail = 0;
	//������ܵ�qq��
    scanf("%d", &num);
    for(que.tail; que.tail<num; que.tail++){
		scanf("%d", &que.data[que.tail]);
    }
    //que.tail++;
    
    //decode
    while(que.tail != que.head){
		//ɾ�������
		qq[i] = que.data[que.head];
        i++;
        que.head++;
        //����һ����������β
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
