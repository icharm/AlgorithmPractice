/****************************************************************************
ջ - �Ƚ�������ݽṹ
ջ�޶�ֻ����һ�ν��в����ɾ���Ĳ�����

���⣺
	�ж�һ���ַ����Ƿ�Ϊ�����ַ����������ַ������ԳƵģ���ǰ������ߴӺ����
����һ����
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
    //�����ѭ���ؽ�topָ��ջ��
    s.top--;
    
    //�ж��ַ����ĳ�������������ż�����Դ�ȷ���ַ��Ƚϵĳ�ʼ�±�
    if(len%2)
		next = mid+1;
    else
		next = mid;
        
    //��ʼ�Ƚ�
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
