// 题目：插入排序，从小到大
#include <stdio.h>

void insertion_sort(int * arr,int lenght)
{
    for(int i=1;i<lenght;i++)
    {
        int value = arr[i];
        int j = i - 1;
        for(;j>=0;j--){
            if(arr[j] > value){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = value;
    }
}


int main(int argc,char *argv[])
{
    int arr[] = {2,20,8,5,11,3};
    int lenght = sizeof(arr)/sizeof(int);
    insertion_sort(arr,lenght);
    printf("the sorted arr is: ");
    for (int i=0;i<lenght;i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

