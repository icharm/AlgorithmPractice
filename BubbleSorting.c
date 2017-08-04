/****************************************************************************
ð������
ʱ�临�ӶȺܸ�O(N^2)
����˼�룺ÿ�αȽ��������ڵ�Ԫ�أ�˳�����ͽ���λ��

���⣺��С��������
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
