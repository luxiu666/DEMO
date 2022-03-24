// 题目：冒泡排序，从小到大
#include <stdio.h>
#include <stdbool.h>

// 冒泡排序算法
void bubble_sort(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        //设置标志，表示这一趟没有数据交换
        bool flag = false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;//如果发生交换了，设置true
            }
        }
        //如果某一趟没有发生数据交换，表示已经排好序了
        if(!flag)
        {
            break;
        }
    }
}




int main(int argc,char *argv[])
{
    int arr[] = {2,4,5,1,29,10};
    int size = sizeof(arr)/sizeof(int);
    bubble_sort(arr,size);
    printf("the sorted arr is: ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}