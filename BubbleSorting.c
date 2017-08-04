/****************************************************************************
冒泡排序
时间复杂度很高O(N^2)
基本思想：每次比较两个相邻的元素，顺序错误就交换位置

问题：从小到大排序
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
	int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
	int num, *arr ,i,j;
    //input how many numbers to sort
    scanf("%d", &num);
    arr = (int *)malloc(sizeof(int)*num);
	//input these numbers
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
    }
    //sorting
    for(i=0; i<num-1; i++){ //only num-1 times
		for(j=0; j<num-1; j++){ //j+1 can not beyond upper bound of arr
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
        }
    }
    
    //print result after sorted
    for(i=0; i<num; i++){
		printf("%d ", arr[i]);
    }
    //free space of arr
    free(arr);
	printf("\r\n");
	system("pause");
	return 0;
}
