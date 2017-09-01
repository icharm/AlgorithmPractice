/*
 *题目描述：
 *    在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 *    请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *思路：
 *    从左下角开始找，小于则上移，大于则右移
 *
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int array[3][6] = {2, 3, 4, 5, 6, 7,
                       8, 9, 10,11,12,11,
                       13,14,15,16,17,18};

    int row = sizeof(array)/sizeof(array[0]);
    int col = sizeof(array[0])/sizeof(int);
    
    int target, i, j;
    
    scanf("%d", &target);
    
    //if target not between min and max of array
    if((target < array[0][0]) || (target > array[row-1][col-1])){ // !important 
        printf("Not Found!\n");
        return 0;
    }

    i = row;
    j = 0;
    //Finding
    do{
        if(target == array[i][j]){
            printf("Found! x=%d y=%d\n", i, j);
            return 0;
        }
        if(target < array[i][j])
            i--;
        else
            j++;
    }while(i >= 0 && j <= col-1);
    
    printf("Not Found!\n");
    getchar();getchar();
    return 0;
}
