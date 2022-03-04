/*
题目：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/
package main

import "fmt"

type ListNode struct {
	val  int
	next *ListNode
}

//初始化单链表
//从尾部新增结点
//data是一个数组切片，属于引用类型，不同于数组
func LinkedListCreateFromTail(data []int) *ListNode {
	//首先初始化空链表
	head := new(ListNode)
	head.next = nil

	var p *ListNode
	p = head
	for _, v := range data {
		node := new(ListNode)
		node.val = v
		node.next = nil
		p.next = node
		p = node
	}
	return head.next
}

//合并两个list
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	head := new(ListNode)
	head.next = nil
	cur := head
	for {
		if list1 == nil || list2 == nil {
			break
		}
		if list1.val < list2.val {
			cur.next = list1
			list1 = list1.next
		} else {
			cur.next = list2
			list2 = list2.next
		}
		cur = cur.next
	}
	if list1 == nil {
		cur.next = list2
	}
	if list2 == nil {
		cur.next = list1
	}

	return head.next

}

//打印单链表
func PrintLinkedList(head *ListNode) {
	p := head
	for {
		if p == nil {
			break
		}
		fmt.Println(p.val)
		p = p.next
	}
}

func main() {
	arr1 := []int{1, 6}
	arr2 := []int{2, 3, 4}
	list1 := LinkedListCreateFromTail(arr1)
	PrintLinkedList(list1)
	list2 := LinkedListCreateFromTail(arr2)
	PrintLinkedList(list2)

	list := mergeTwoLists(list1, list2)
	PrintLinkedList(list)
}
