// 题目：冒泡排序，从小到大,golang实现
package main

import "fmt"

func bubble_sort(arr []int) {
	length := len(arr)
	for i := 0; i < length; i++ {
		flag := false //是否有数据交换
		for j := 0; j < length-1; j++ {
			if arr[j] > arr[j+1] {
				temp := arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
				flag = true
			}
		}
		//如果没有数据交换则跳出
		if !flag {
			break
		}
	}
}

func main() {
	arr := []int{7, 1, 4, 9, 2, 5}
	bubble_sort(arr)
	fmt.Println(arr)
}
