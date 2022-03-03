/*
单链表的基本操作(golang版)
单链表分两种：有头结点和无头结点
插入单链表方式：头部插入和尾部插入，不管是头部插入还是尾部插入，步骤是：
   1) 先把新结点的next指针指向下一个结点
   2）再把前一个结点的next指向新结点
*/
package main

import "fmt"

type LinkedList struct {
	data int
	next *LinkedList
}

//初始化单链表
//从尾部新增结点
//data是一个数组切片，属于引用类型，不同于数组
func LinkedListCreateFromTail(data []int) *LinkedList {
	//首先初始化空链表
	head := new(LinkedList)
	head.next = nil

	var p *LinkedList
	p = head
	for _, v := range data {
		node := new(LinkedList)
		node.data = v
		node.next = nil
		p.next = node
		p = node
	}
	return head
}

//单链表的插入，在链表的第pos个位置插入x的元素
//需要获得新结点位置的前驱指针，所以申请一个pre指针
func LinkedListInsert(head *LinkedList, pos int, x int) *LinkedList {
	//创建一个前驱指针,开始指向head的下一个结点
	pre := head.next
	//通过遍历pos值，获得插入位置的前驱指针
	for i := 1; i < pos; i++ {
		pre = pre.next
	}
	//创建新结点
	node := new(LinkedList)
	node.data = x
	node.next = pre.next
	pre.next = node

	return head
}

//单链表的删除，在链表中删除值为x的元素，每次只能删除一个结点
//需要p指针，获取当前等于x的结点
//还需要pre指针，重新指向后面一个结点
func LinkedListDelete(head *LinkedList, x int) *LinkedList {
	//创建p指针，开始指向头结点的下一结点
	p := head.next
	//创建前驱指针，开始指向头结点
	pre := head
	for {
		//如果找到符合条件的结点或者无法找到数据，终止循环
		if p.data == x || p == nil {
			break
		}
		//将前驱pre指针指向当前结点
		pre = p
		//将p指针移到下一结点处，继续循环
		p = p.next
	}
	//前驱结点的next指针重新指向要删除结点的下一个结点
	pre.next = p.next
	return head
}

//单链表内容的修改，在链表中修改值为x的元素变为为k
//需要p指针，找到需要更新的结点
func LinkedListUpdate(head *LinkedList, x int, k int) *LinkedList {
	p := head.next
	for {
		if p == nil {
			break
		}
		if p.data == x {
			p.data = k
		}
		p = p.next
	}
	return head
}

//打印单链表
func PrintLinkedList(head *LinkedList) {
	p := head.next
	for {
		if p == nil {
			break
		}
		fmt.Println(p.data)
		p = p.next
	}
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	l1 := LinkedListCreateFromTail(arr)
	PrintLinkedList(l1)
	fmt.Printf("\n")

	l2 := LinkedListInsert(l1, 2, 20)
	PrintLinkedList(l2)
	fmt.Printf("\n")

	l3 := LinkedListDelete(l2, 20)
	PrintLinkedList(l3)
	fmt.Printf("\n")

	l4 := LinkedListUpdate(l3, 5, 50)
	PrintLinkedList(l4)
}
