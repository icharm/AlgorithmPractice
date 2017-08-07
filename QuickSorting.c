/****************************************************************************
��������
ƽ��ʱ�临�Ӷ�O(NlogN), ���ʱ�临�Ӷ�O(N^2)
����˼��
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
		//�ȴ�������<--Ѱ�� 
		while(arr[j] >= base && i<j)// >= Ϊ��С��������
			j--;
        //-->
		while(arr[i] <= base && i<j)
        	i++;
		if(i<j)
			swap(&arr[i], &arr[j]); 
    }
    
    //������׼��
    swap(&arr[left], &arr[i]);
    
    quickSort(left, i-1);	//��Ϊ��ߵ�����
    quickSort(i+1, right);	//��Ϊ�ұߵ�����
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
