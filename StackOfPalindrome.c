/****************************************************************************
栈 - 先进后出数据结构
栈限定只能在一段进行插入和删除的操作。

问题：
	判断一个字符串是否为回文字符串，回文字符串即对称的，从前读起或者从后读起
都是一样的
****************************************************************************/
#include <stdio.h>
#include <stdlib.h> 
struct stack
{
	char data[100];
    int top;
};

int main()
{
	struct stack s;
    char a[100];
	int len,mid,next,i;
    
    gets(a);
	len = strlen(a);
    mid = len/2;
    
    s.top = 0; //init stack
    for(i=0; i<mid; i++){
		s.data[s.top] = a[i];
        s.top++;
    }
    //上面的循环回将top指离栈顶
    s.top--;
    
    //判断字符串的长度是奇数还是偶数，以此确定字符比较的初始下标
    if(len%2)
		next = mid+1;
    else
		next = mid;
        
    //开始比较
    for(next; next<len; next++){
		if(a[next] != s.data[s.top])
			break;
        s.top--;
    }
    
    //print result
    if(s.top > 0)
		printf("No\n");
    else
		printf("Yes\n");
    
    
	system("pause");
	return 0;
}
