/***************************************************************************
Kitten fishing 小猫钓鱼 - 纸牌游戏

游戏规则：
	将一副扑克平均分成两份，没人拿一份。a先拿出手中的第一张扑克牌放在桌上，
然后b也拿出手中的第一张扑克牌，并放在a刚打出的扑克牌上面，就像这样两人交替
出牌。出牌时，如果某人打出的牌与桌上某张牌的牌面相同，即可将两张相同的牌及
其中所夹的牌全部拿走，并依次放到自己手中牌的末尾。当任意一人手中的牌全部出
完时，游戏结束，对手胜利。

假设:
	1.扑克牌的牌面只有1~9。
    2.每个人的手中初始6张牌
    3.每次赢牌之后由对手出牌

解析：
	出牌类似与队列的先进先出，桌面上的牌类似于栈先进后出

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
    
    //输入两个人手中的牌
    printf("请依次输入A手中的牌：\n");
    for(i=0; i<6; i++){
		scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    
    printf("请依次输入B手中的牌: \n");
    for(i=0; i<6; i++){
		scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    
    //依次出牌
    do
    {
		//q1出牌
        tmp = s.data[s.top] = q1.data[q1.head];
        mark[tmp]+=1; //标记桌面上的牌
        //判断桌面上是否有相同的牌面
        if(mark[tmp] == 2){
			//有相同的牌面
            //收牌
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
        
        //q2出牌
        tmp = s.data[s.top] = q2.data[q2.head];
        mark[tmp]++;
        //判断桌面上是否有相同的牌
        if(mark[tmp] == 2){
			//有，收牌
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
        if(s.top > 0){ //输出桌面上的牌
			printf("Table: ");
            s.top--;//上面出牌的循环，会将s.top指向栈顶的空白位置
			while(s.top >= 0){
				printf("%d ", s.data[s.top]); //上面出牌的循环，会将s.top指向栈顶的空白位置
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
        if(s.top > 0){ //输出桌面上的牌
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
