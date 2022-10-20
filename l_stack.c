/*链式结构*/

/*由于只有堆栈顶部元素才可以被访问，因此适用单链表可以很好实现链式堆栈，而且无长度限制。
把一个元素压入堆栈是通过在链表头部添加一个元素实现。弹出一个元素是通过删除链表头部第一个元素实现。
由于没有长度限制，故不需要create_stack函数，需要destroy_stack进行释放内存以避免内存泄漏。
*/


/* 
** 单链表实现堆栈，没有长度限制 
*/  
#include"stack.h"  
#include<stdio.h>  
#include<malloc.h>  
#include<assert.h>  
  
#define FALSE 0  
 
/* 
** 定义一个结构以存储堆栈元素。 
*/  
typedef struct STACK_NODE  
{  
    STACK_TYPE value;  
    struct STACK_NODE *next;  
} StackNode;  
  
/* 指向堆栈中第一个节点的指针 */  
static StackNode *stack;  
  
/* create_stack */  
void create_stack(size_t size)  
{}  
  
/* destroy_stack */  
void destroy_stack(void)  
{  
    while(!is_empty())  
        pop();  /* 逐个弹出元素，逐个释放节点内存 */  
}  
  
/* push */  
void push(STACK_TYPE value)  
{  
    StackNode *new_node;  
    new_node = (StackNode *)malloc(sizeof(StackNode));  
    if(new_node == NULL)  
        perror("malloc fail");  
    new_node->value = value;  
    new_node->next = stack;  /* 新元素插入链表头部 */  
    stack = new_node;       /* stack 重新指向链表头部 */  
}  
  
/* pop */  
void pop(void)  
{  
    StackNode *first_node;  
      
    assert(!is_empty());  
    first_node = stack;  
    stack = first_node->next;  
    free(first_node);  
}  
  
/* top */  
STACK_TYPE top(void)  
{  
    assert(!is_empty());  
    return stack->value;  
}  
  
/* is_empty */  
int is_empty(void)  
{  
    return stack == NULL;  
}  
  
/* is_full */  
int is_full(void)  
{  
    return FALSE;  
}  