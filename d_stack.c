/*动态数组*/

/*
**头文件还是用stack.h，改动的并不是很多，增加了stack_size变量取代STACK_SIZE来保存堆栈的长度，数组由一个指针来代替，
**在全局变量下缺省为0。
**create_stack函数首先检查堆栈是否已经创建，然后才分配所需数量的内存并检查分配是否成功。
**destroy_stack函数首先检查堆栈是否存在，已经释放内存之后把长度和指针变量重新设置为零。
**is_empty 和 is_full 函数中添加了一条断言，防止任何堆栈函数在堆栈被创建之前就被调用。
*/

/* 
** 动态分配数组实现的堆栈程序 d_stack.c 
** 堆栈的长度在创建堆栈的函数被调用时候给出，该函数必须在任何其他操作堆栈的函数被调用之前条用。 
*/  
#include"stack.h"  
#include<stdio.h>  
#include<malloc.h>  
#include<assert.h>  
  
/* 
** 用于存储堆栈元素的数组和指向堆栈顶部元素的指针 
*/  
static STACK_TYPE *stack;  
static int        stack_size;  
static int        top_element = -1;  
  
/* create_stack */  
void create_stack(size_t size)  
{  
    assert(stack_size == 0);  
    stack_size = size;  
    stack = (STACK_TYPE *)malloc(stack_size * sizeof(STACK_TYPE));  
    if(stack == NULL)  
        perror("malloc分配失败");  
}  
  
/* destroy */  
void destroy_stack(void)  
{  
    assert(stack_size > 0);  
    stack_size = 0;  
    free(stack);  
    stack = NULL;  
}  
  
/* push */  
void push(STACK_TYPE value)  
{  
    assert(!is_full());  
    top_element += 1;  
    stack[top_element] = value;  
}  
  
/* pop */  
void pop(void)  
{  
    assert(!is_empty());  
    top_element -= 1;  
}  
  
/* top */  
STACK_TYPE top(void)  
{  
    assert(!is_empty());  
    return stack[top_element];  
}  
  
/* is_empty */  
int is_empty(void)  
{  
    assert(stack_size > 0);  
    return top_element == -1;  
}  
  
/* is_full */  
int is_full(void)  
{  
    assert(stack_size > 0);  
    return top_element == stack_size - 1;  
}