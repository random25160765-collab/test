/*
2026-1-6 带头尾虚节点的双向链表：指针版本
2026-1-8 补充了增删改查的完整功能
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node; 
typedef struct MyLinkedList MyLinkedList;

struct Node {
    unsigned char val;
    Node* prev;
    Node* next;
}; // 这里的结构体内部已经用了Node，所以要先声明

struct MyLinkedList {
    int size;
    Node* head;
    Node* tail;
};

/* 节点在初始化时就创建 */
Node* InitializeNode()
{
    // 绝对不能直接 Node *node——为什么？（自测）
    Node* node = (Node*)malloc(sizeof(Node)); // 注意检查
    if (node == NULL) {
        puts("Memory allocation failed!");
        return NULL; // 注意返回NULL
    }
    node->val = 0;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/* 链表在初始化时就创建 */
MyLinkedList* InitializeLinkedList()
{
    MyLinkedList* linkedlist = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (linkedlist == NULL) {
        puts("Memory allocation failed!");
        return NULL;
    }
    linkedlist->head = InitializeNode();
    linkedlist->tail = InitializeNode();
    linkedlist->head->next = linkedlist->tail;
    linkedlist->tail->prev = linkedlist->head;
    linkedlist->head->val = -1;
    linkedlist->tail->val = -1;
    linkedlist->size = 0;
    return linkedlist;
}

/* index从0开始，一直到size-1 */
static Node* GetNode(MyLinkedList *linkedlist, int index)
{
    Node *objectNode = linkedlist->head->next;
    for (int i = 0; i < index; i++) {
        objectNode = objectNode->next;
    }
    return objectNode;
}

void FreeNode(Node *node)
{
    free(node);
    node = NULL;
}

/* 增 */
void AddAtHead(MyLinkedList *linkedlist, unsigned char val)
{
    Node *newNode = InitializeNode();
    if (!newNode) return; // 每一处有可能返回NULL的地方都要检查
    newNode->val = val;
    Node *temp = linkedlist->head->next;
    linkedlist->head->next = newNode;
    newNode->prev = linkedlist->head;
    temp->prev = newNode;
    newNode->next = temp;
    linkedlist->size++;
}

void AddAtTail(MyLinkedList *linkedlist, unsigned char val)
{
    Node *newNode = InitializeNode();
    if (!newNode) return;
    newNode->val = val;
    Node *temp = linkedlist->tail->prev;
    linkedlist->tail->prev = newNode;
    newNode->next = linkedlist->tail;
    temp->next = newNode;
    newNode->prev = temp;
    linkedlist->size++;
}

void AddAtIndex(MyLinkedList *linkedlist, unsigned char val, int index)
{
    if (index < 0 || index > linkedlist->size) {
        puts("Index error!");
        return;
    }
    if (index == 0) AddAtHead(linkedlist, val);
    else if (index == linkedlist->size) AddAtTail(linkedlist, val);
    else {
        Node *indexNode = GetNode(linkedlist, index);
        if (!indexNode) return; // 小心返回NULL
        Node *newNode = InitializeNode();
        if (!newNode) return;
        newNode->val = val;
        Node *temp = indexNode->prev;
        indexNode->prev = newNode;
        newNode->next = indexNode;
        temp->next = newNode;
        newNode->prev = temp;
        linkedlist->size++;
    }
}

/* 删 */
void DeleteAtHead(MyLinkedList *linkedlist)
{
    if (linkedlist->size == 0) { // 不能删掉不存在的节点
        puts("You cannot delete an empty linkedlist.");
        return;
    }
    Node *to_delete = linkedlist->head->next;
    Node *temp = to_delete->next;
    linkedlist->head->next = temp;
    temp->prev = linkedlist->head;
    FreeNode(to_delete);
    linkedlist->size--;
}

void DeleteAtTail(MyLinkedList *linkedlist)
{
    if (linkedlist->size == 0) {
        puts("You cannot delete an empty linkedlist.");
        return;
    }
    Node *to_delete = linkedlist->tail->prev;
    Node *temp = to_delete->prev;
    linkedlist->tail->prev = temp;
    temp->next = linkedlist->tail;
    FreeNode(to_delete);
    linkedlist->size--;
}

void DeleteAtIndex(MyLinkedList *linkedlist, int index)
{
    if (linkedlist->size == 0) {
        puts("You cannot delete an empty linkedlist.");
        return;
    }
    if (index < 0 || index >= linkedlist->size) {
        puts("Index error!");
        return;
    }
    if (index == 0) DeleteAtHead(linkedlist);
    else if (index == linkedlist->size - 1) DeleteAtTail(linkedlist);
    else {
       Node *to_delete = GetNode(linkedlist, index); 
       if (to_delete == NULL) return;
       Node *to_delete_prev = to_delete->prev;
       Node *to_delete_next = to_delete->next;
       to_delete_prev->next = to_delete_next;
       to_delete_next->prev = to_delete_prev;
       FreeNode(to_delete);
       linkedlist->size--;
    }
}

void DestroyLinkedList(MyLinkedList *linkedlist)
{
    Node *to_delete = linkedlist->head->next;
    for (int i = 0; i < linkedlist->size; i++) {
        to_delete = to_delete->next;
        FreeNode(to_delete->prev);
    }
    FreeNode(linkedlist->head);
    FreeNode(linkedlist->tail);
    free(linkedlist);
    linkedlist = NULL;
}

/* 改 */
void ModifyIndex(MyLinkedList *linkedlist, int val, int index)
{
    Node *indexNode = GetNode(linkedlist, index);
    indexNode->val = val;
}

/* 查 */
int IsEmpty(MyLinkedList *linkedlist)
{
    return linkedlist->size == 0;
}

int GetSize(MyLinkedList *linkedlist)
{
    return linkedlist->size;
}

int GetHead(MyLinkedList *linkedlist)
{
    return linkedlist->head->next->val;
}

int GetTail(MyLinkedList *linkedlist)
{
    return linkedlist->tail->prev->val;
}

int GetIndexVal(MyLinkedList *linkedlist, int index)
{
    Node *indexNode = GetNode(linkedlist, index);
    return indexNode->val;
}

void PrintLinkedList(MyLinkedList *linkedlist)
{
    printf("Linked List (size=%d): ", linkedlist->size);
    Node *current = linkedlist->head->next;
    while (current != linkedlist->tail) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void PrintLinkedListReverse(MyLinkedList *linkedlist)
{
    printf("Linked List Reverse: ");
    Node *current = linkedlist->tail->prev;
    while (current != linkedlist->head) {
        printf("%d ", current->val);
        current = current->prev;
    }
    printf("\n");
}

/* 测试程序(ai写的) */
int main()
{
    printf("=== 测试双向链表 ===\n");
    
    // 创建链表
    MyLinkedList* list = InitializeLinkedList();
    if (list == NULL) {
        printf("创建链表失败！\n");
        return 1;
    }
    
    // 测试1：基本操作
    printf("\n1. 添加元素测试:\n");
    AddAtHead(list, 10);
    AddAtTail(list, 30);
    AddAtIndex(list, 20, 1);
    PrintLinkedList(list);      // 应该输出: 10 20 30
    PrintLinkedListReverse(list); // 应该输出: 30 20 10
    
    // 测试2：边界测试
    printf("\n2. 边界情况测试:\n");
    
    // 测试空链表删除
    MyLinkedList* emptyList = InitializeLinkedList();
    DeleteAtHead(emptyList);    // 应该打印错误信息
    DestroyLinkedList(emptyList);
    
    // 测试无效索引
    AddAtIndex(list, 100, 5);   // 索引5超出范围，size=3
    AddAtIndex(list, 100, -1);  // 负索引
    
    // 测试3：删除操作
    printf("\n3. 删除操作测试:\n");
    DeleteAtIndex(list, 1);     // 删除中间的20
    PrintLinkedList(list);      // 应该输出: 10 30
    
    DeleteAtHead(list);         // 删除10
    PrintLinkedList(list);      // 应该输出: 30
    
    DeleteAtTail(list);         // 删除30
    PrintLinkedList(list);      // 应该输出: (空)
    
    // 测试4：重新填充测试
    printf("\n4. 重新填充测试:\n");
    for (int i = 0; i < 5; i++) {
        AddAtTail(list, i * 10);
    }
    PrintLinkedList(list);      // 应该输出: 0 10 20 30 40
    printf("链表大小: %d\n", GetSize(list));
    printf("头节点值: %d\n", GetHead(list));
    printf("尾节点值: %d\n", GetTail(list));
    
    // 清理
    DestroyLinkedList(list);
    
    printf("\n=== 测试完成 ===\n");
    return 0;
}