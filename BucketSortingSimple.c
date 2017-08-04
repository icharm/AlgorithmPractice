/****************************************************************************
桶排序-简化版
空间复杂度很大，时间复杂度很小
核心思想是标记每一个出现的数

问题：
	对5位同学的英语分数进行排序（满分为100）
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
