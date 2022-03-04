/*
题目：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/
package main

import (
	"fmt"
)

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

// 反转单链表
func reverseList(head *ListNode) *ListNode {
	prev := new(ListNode)
	prev = nil
	curr := head
	for {
		if curr == nil {
			break
		}
		next := curr.next
		curr.next = prev
		prev = curr
		curr = next
	}
	return prev
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
	arr := []int{1, 6}
	list := LinkedListCreateFromTail(arr)
	PrintLinkedList(list)

	list1 := reverseList(list)
	PrintLinkedList(list1)
}
