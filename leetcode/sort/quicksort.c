#include <stdio.h>

int partition(int *arr,int left,int right)
{
    //定义一个基准值pivot,默认第一个元素
    int pivot = arr[left];
    while(left < right)
    {
        while(left < right && arr[right] >= pivot)
        {
            right--;
        }
        arr[left] = arr[right];
        while(left < right && arr[left] <= pivot)
        {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;

}

void qsort(int *arr,int left,int right)
{
    if (left < right)
    {
        int middle = partition(arr,left,right);
        qsort(arr,left,middle-1);
        qsort(arr,middle+1,right);
    }
}


int main(int argc,char *argv[] )
{
    int arr[] = {4,2,8,3,9,10,5};
    int middle = partition(arr,0,sizeof(arr)/sizeof(int)-1);
    printf("middle=%d\n",middle);
    qsort(arr,0,sizeof(arr)/sizeof(int)-1);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
       printf("%d ",arr[i]);
    }
    
}