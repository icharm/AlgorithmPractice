/***************************************************************************
Kitten fishing Сè���� - ֽ����Ϸ

��Ϸ����
	��һ���˿�ƽ���ֳ����ݣ�û����һ�ݡ�a���ó����еĵ�һ���˿��Ʒ������ϣ�
Ȼ��bҲ�ó����еĵ�һ���˿��ƣ�������a�մ�����˿������棬�����������˽���
���ơ�����ʱ�����ĳ�˴������������ĳ���Ƶ�������ͬ�����ɽ�������ͬ���Ƽ�
�������е���ȫ�����ߣ������ηŵ��Լ������Ƶ�ĩβ��������һ�����е���ȫ����
��ʱ����Ϸ����������ʤ����

����:
	1.�˿��Ƶ�����ֻ��1~9��
    2.ÿ���˵����г�ʼ6����
    3.ÿ��Ӯ��֮���ɶ��ֳ���

������
	������������е��Ƚ��ȳ��������ϵ���������ջ�Ƚ����

****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct queue
{
	int data[100];
    int head;
    int tail;
};

struct stack
{
	int data[100];
    int top;
};

int main()
{
	struct queue q1,q2;
    struct stack s;
    int i,tmp;
    int mark[10]={0};
    
    //init queue and stack
    q1.head = 0;
    q1.tail = 0;
    q2.head = 0;
    q2.tail = 0;
    s.top = 0;
    
    //�������������е���
    printf("����������A���е��ƣ�\n");
    for(i=0; i<6; i++){
		scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    
    printf("����������B���е���: \n");
    for(i=0; i<6; i++){
		scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    
    //���γ���
    do
    {
		//q1����
        tmp = s.data[s.top] = q1.data[q1.head];
        mark[tmp]+=1; //��������ϵ���
        //�ж��������Ƿ�����ͬ������
        if(mark[tmp] == 2){
			//����ͬ������
            //����
            do{
				q1.data[q1.tail] = s.data[s.top];
                mark[s.data[s.top]]--;
                printf("%d ", tmp);
                //if(tmp == s.data[s.top])
				//	mark[tmp]--;
                s.top--;
                q1.tail++;
            }while(mark[tmp] > 0);
        }
        q1.head++;
        s.top++;
        
        //q2����
        tmp = s.data[s.top] = q2.data[q2.head];
        mark[tmp]++;
        //�ж��������Ƿ�����ͬ����
        if(mark[tmp] == 2){
			//�У�����
            do{
				q2.data[q2.tail] = s.data[s.top];
                mark[s.data[s.top]]--;
                //printf("%d ", tmp);
                //if(tmp == s.data[s.top])
				//	mark[tmp]--;
                s.top--;
                q2.tail++;
            }while(mark[tmp] > 0);
        }
        q2.head++;
        s.top++;
        
    }while((q2.head < q2.tail) && (q1.head < q1.tail));
    
	//print result
	if(q1.head == q1.tail){
		printf("B Win!\n B: ");
        //print 
        while(q2.head < q2.tail){
			printf("%d ", q2.data[q2.head]);
            q2.head++;
        }
        printf("\n");
        if(s.top > 0){ //��������ϵ���
			printf("Table: ");
            s.top--;//������Ƶ�ѭ�����Ὣs.topָ��ջ���Ŀհ�λ��
			while(s.top >= 0){
				printf("%d ", s.data[s.top]); //������Ƶ�ѭ�����Ὣs.topָ��ջ���Ŀհ�λ��
                s.top--;
            }
        }
        printf("\n");
    }else{
		printf("A Win!\n A:");
        //print 
        while(q1.head < q1.tail){
			printf("%d ", q1.data[q1.head]);
            q1.head++;
        }
        printf("\n");
        if(s.top > 0){ //��������ϵ���
			printf("Table: ");
            s.top--;
			while(s.top >= 0){
				printf("%d ", s.data[--s.top]);
                s.top--;
            }
        }
        printf("\n");
    }
    
	system("pause");
	return 0;
}
