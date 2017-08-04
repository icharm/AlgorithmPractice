/****************************************************************************
快速排序
时间复杂度O(NlogN)
二分思想
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

void quickSort(int *arr, int i, int j)
{
	if(i == j)
		return;
	int base = i;
    int end = j;
    while(i != j){
		for(i; i<j; i++){
			if(arr[i] > arr[base])
				break;
		}
		for(j; j>=i; j--){
			if(arr[j] < arr[base])
				break;
		}
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[base], &arr[i]);
    quickSort(&arr, 0, i-1);
    quickSort(&arr, i+1, end);
}

int main()
{
	int num, *arr, i;
    scanf("%d", &num);
    arr = (int *)malloc(sizeof(int)*num);
    
    for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
    }
    
    //sorting
	quickSort(&arr, 0, num-1);
    
    //print result after sorted
    for(i=0; i<num; i++){
		printf("%d ", arr[i]);
    }
    
    free(arr);
    printf("\r\n");
	system("pause");
	return 0;
}
