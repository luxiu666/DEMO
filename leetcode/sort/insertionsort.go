// 题目：插入排序，从小到大 golang版本
package main

import "fmt"

func insert_sort(arr []int) {
	length := len(arr)
	for i := 1; i < length; i++ {
		value := arr[i]
		j := i - 1
		for ; j >= 0; j-- {
			if arr[j] > value {
				arr[j+1] = arr[j]
			} else {
				break
			}
		}
		arr[j+1] = value
	}

}

func main() {
	arr := []int{7, 1, 4, 9, 2, 5}
	insert_sort(arr)
	fmt.Println(arr)
}
