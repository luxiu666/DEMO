/* 单链表的基本操作(c语言版)
单链表分两种：有头结点和无头结点
插入单链表方式：头部插入和尾部插入，不管是头部插入还是尾部插入，步骤是：
   1) 先把新结点的next指针指向下一个结点
   2）再把前一个结点的next指向新结点
*/
#include <stdio.h>
#include <stdlib.h>

//单向链表数据结构
typedef struct LinkedList {
    int data;
    struct LinkedList *next; 
} LinkedList;

//初始化一个单链表
//头部插入结点
LinkedList * link_list_create_from_head(int * data,int length)
{
    //创建头结点(相当于哨兵结点，不存储数据)并分配空间
    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
    if(head == NULL)
    {
        printf("申请空间失败");
        return NULL;
    }
    //初始化链表为空链表
    head->next = NULL;

    for(int i = 0;i < length;i++)
    {
        //创建结点，并分配内存空间
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        //为结点数据域赋值
        node->data = data[i];
        //先将当前插入结点next指针指向下一个结点，即之前的head指针所指向的结点
        node->next = head->next;
        //然后再将头结点的next指向当前插入结点
        head->next = node;
    }
    
    return head;
}

//初始化一个单链表
//尾部插入结点
LinkedList * link_list_create_from_tail(int *data,int length)
{
    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
    if(head == NULL){
        printf("申请空间失败");
        return NULL;
    }
    //初始化链表为空
    head->next = NULL;

    //必须申明一个指向新插入结点的指针，用来标识插入新结点位置
    //开始时候p指向head结点
    LinkedList *p = head;

    for(int i=0;i<length;i++){
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->data = data[i];
        //由于每次插入都是最后一个，所以结点的next指针始终指向NULL
        node->next = NULL;
        //前一个结点指针就是p的next指向新结点
        p->next = node;

        //然后把指针指向新结点
        p = node;
    }
    return head;
}

//遍历单向链表
//head: 传入头结点
void print_linkedlist(LinkedList * head)
{   
    if(head == NULL)
    {
        printf("单链表为空");
    }
    //由于头结点不存储数据，故从下一个结点遍历数据
    //申明指针p，指向头结点的下一结点
    LinkedList *p = head->next;
    //循环链表，直到指针p为空
    while(p)
    {
        printf("%d ",p->data);
        //指针p循环指向下一结点
        p = p->next;
    }
}

//单链表的插入，在链表的第i个位置插入x的元素
LinkedList * link_list_insert(LinkedList *head,int pos,int x){
    LinkedList *p = head;
    //0位置是头结点，忽略
    //找到需要插入位置的前驱结点p
    for(int i=1;i<pos;i++){
        p = p->next;
    }
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = x;
    //新结点的next指向下一个结点，也就是前驱结点p指向的结点
    node->next = p->next;
    //想前驱结点重新指向新结点
    p->next = node;
    return head;
}

//单链表的删除，在链表中删除值为x的元素，每次只能删除一个结点
LinkedList * link_list_delete(LinkedList *head,int x){
    LinkedList *p = head->next;//p指针找值为x结点
    LinkedList *pre = head;//pre指针作为x节点的前驱结点
    //while主要遍历链表，找到数据为x结点的前驱结点pre
    while(p){   
        if(p->data == x){
           break; 
        }
        pre = p;
        p = p->next;
    }
    //前驱结点的next指针重新指向要删除结点的下一个结点
    pre->next = p->next;
    //释放p结点
    free(p);
    
    return head;
}

//单链表内容的修改，在链表中修改值为x的元素变为为k
LinkedList * link_list_update(LinkedList *head,int x,int k){
    LinkedList *p = head->next;//p指针找值为x结点
    //while主要遍历链表，找到数据为x结点
    while(p){ 
        if(p->data == x){
            p->data = k;
        }
        p = p->next;
    }
    return head;
}


int main(int argc,char *argv[])
{
    int data[6] = {1,2,3,4,5,6};
    LinkedList *head = link_list_create_from_head(data,6);
    print_linkedlist(head);
    printf("\n");
    LinkedList *tail = link_list_create_from_tail(data,6);
    print_linkedlist(tail);
    printf("\n");
    //在第2个位置上插入10
    // LinkedList *L = link_list_insert(tail,2,10);
    // print_linkedlist(L);
    // printf("\n");
    //删除data=10的结点
    LinkedList *L1 = link_list_delete(tail,6);
    print_linkedlist(L1);
    printf("\n");
    //更新data=10的结点
    // LinkedList *L2 = link_list_update(tail,4,44);
    // print_linkedlist(L2);
    return 0;
}