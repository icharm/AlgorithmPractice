/****************************************************************************
快速排序
平均时间复杂度O(NlogN), 最差时间复杂度O(N^2)
二分思想
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
//Global Variable
int arr[100], num;

void swap(int *x, int *y)
{
	int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void quickSort(int i, int j)
{
	if(i > j)
		return;
    int base = arr[i];
	int left = i;
    int right = j;
    int tmp;
    while(i != j){
		//先从右往左<--寻找 
		while(arr[j] >= base && i<j)// >= 为从小到大排序
			j--;
        //-->
		while(arr[i] <= base && i<j)
        	i++;
		if(i<j)
			swap(&arr[i], &arr[j]); 
    }
    
    //交换基准数
    swap(&arr[left], &arr[i]);
    
    quickSort(left, i-1);	//先为左边的排序
    quickSort(i+1, right);	//在为右边的排序
}

int main()
{
    int i;
    scanf("%d", &num);
    
    for(i=0; i<num; i++){
		scanf("%d", &arr[i]);   
    }
        
    //sorting
	quickSort(0, num-1);
    
    //print result after sorted
    for(i=0; i<num; i++){
		printf("%d ", arr[i]);
    }
    
    printf("\r\n");
	system("pause");
	return 0;
}
