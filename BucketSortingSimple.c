/****************************************************************************
Ͱ����-�򻯰�
�ռ临�ӶȺܴ�ʱ�临�ӶȺ�С
����˼���Ǳ��ÿһ�����ֵ���

���⣺
	��5λͬѧ��Ӣ�����������������Ϊ100��
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[101],i,j,t;
	//init 0 to array 
    for(i=0; i<101; i++){
		a[i] = 0;
    }
    
    //input 10 student's score
    for(i=0; i<5; i++){
		scanf("%d", &t);
        a[t]++;
    }
    
    //print result after sorted
    for(i=0; i<101; i++){
		for(j=0; j<a[i]; j++)
			printf("%d\t", i);
    }
    
	system("pause");
	return 0;
}
