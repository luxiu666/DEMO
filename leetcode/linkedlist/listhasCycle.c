/* 
题目： 给你一个链表的头节点 head ，判断链表中是否有环。
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
}ListNode;

//初始化一个单链表
ListNode * link_list_create_from_tail(int *data,int length)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    if(head == NULL){
        printf("申请空间失败");
        return NULL;
    }
    //初始化链表为空
    head->next = NULL;

    //必须申明一个指向新插入结点的指针，用来标识插入新结点位置
    //开始时候p指向head结点
    ListNode *p = head;

    for(int i=0;i<length;i++){
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->val = data[i];
        //由于每次插入都是最后一个，所以结点的next指针始终指向NULL
        node->next = NULL;
        //前一个结点指针就是p的next指向新结点
        p->next = node;

        //然后把指针指向新结点
        p = node;
    }
    return head->next;
}

// 检测是否有环
bool hasCycle(struct ListNode *head) {
    
   struct ListNode *fast = head;
    struct ListNode *slow = head;

    while(fast != NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }

    return false;
}

//遍历单向链表
//head: 传入头结点
void print_linkedlist(ListNode * head)
{   
    if(head == NULL)
    {
        printf("单链表为空");
    }
    //由于头结点不存储数据，故从下一个结点遍历数据
    //申明指针p，指向头结点的下一结点
    ListNode *p = head;
    //循环链表，直到指针p为空
    while(p)
    {
        printf("%d ",p->val);
        //指针p循环指向下一结点
        p = p->next;
    }
}

int main(int argc,char *argv[])
{
    int data1[2] = {1,6};
    ListNode *tail1 = link_list_create_from_tail(data1,2);
    print_linkedlist(tail1);
    printf("\n");
   
    ListNode *head = reverseList(tail1);
    print_linkedlist(head);

    
    return 0;
}