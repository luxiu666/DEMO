package main

import "fmt"

/*
快速排序算法（从小到大）：
1、设置一个基准数pivot,一般是数组第一个元素
2、设置左右两个指针，left指向数组第一个元素 right指向数组最后一个元素
3、先从右向左遍历，大于等于的跳过直到遇到小于基准数的放到基准数的左边，然后从左向右遍历，小于等于的跳过直到遇到
   大于基准数的，放到基准数的右边，返回中间位置索引值
4、对左右两个子数组按照上面方法继续排序，直到区间只有一个元素即排序完成
*/

//分区函数
func partition(arr []int, left int, right int) int {
	pivot := arr[left]

	for {
		if left < right {
			//从右向左遍历，大于等于的跳过直到遇到小于基准数的放到基准数的左边
			for {
				if left < right && arr[right] >= pivot {
					right--
				}
				arr[left] = arr[right]
				break
			}
			//从左向右遍历，小于等于的跳过直到遇到大于基准数的，放到基准数的右边
			for {
				if left < right && arr[left] <= pivot {
					left++
				}
				arr[right] = arr[left]
				break
			}
		} else {
			break
		}
	}
	arr[left] = pivot
	return left
}

func quick_sort(arr []int, left int, right int) {
	if left < right {
		middle := partition(arr, left, right)
		quick_sort(arr, left, middle-1)
		quick_sort(arr, middle+1, right)
	}

}

func main() {
	arr := []int{5, 1, 2, 9, 8, 4}
	fmt.Println(arr)
	quick_sort(arr, 0, len(arr)-1)
	fmt.Println(arr)
}
