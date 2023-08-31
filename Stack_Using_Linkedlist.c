#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int isEmpty(struct Node* ptr) // Checking if stack is Empty or not.
{
    if (ptr == NULL) 
    {
        return 1;
    }
    return 0;
}
int isFull(struct Node* ptr) // Checking if stack is Full or not.
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}
struct Node* push(struct Node* ptr, int data) // Pushing Elements at the stack.
{
    if(isFull(ptr)) // Checking the Overflow Condition.
    {
        printf("Stack Overflow occuring...\n");
        return ptr;
    }
    else{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = data;
    new -> next = ptr;
    ptr = new;
    return ptr;
    }
}
struct Node* pop(struct Node* ptr) // This Function will pop the stack elements. 
{
    if(isEmpty(ptr)) // Checking the underflow condition.
    {
        printf("Stack Underflow Occuring...\n");
        return ptr;
    }
    struct Node* p = ptr;
    int val = ptr -> data;
    ptr = ptr -> next;
    free(p);
    printf("%d popped out from the stack.\n", val);
    return ptr;
}
void peek(struct Node* ptr, int position) // Peeking the top elements of specified postion from top.
{
    struct Node* p = ptr;
    for (int i = 0; i < position -1 && p != NULL; i++)
    {
        p = p -> next;
    }
    if (p == NULL){
        printf("Entered Invalid Position.\n");
        return;
    }
    printf("Element at %d position is: %d\n", position, p -> data);
}
void Traversial(struct Node* ptr) // This Function will display the Stack Elements.
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
        return;
    }
    struct Node* p = ptr;
    while (p != NULL) {
        printf("Element: %d\n", p -> data);
        p = p -> next;
    }
}
int main()
{
    struct Node* top = NULL;
    // Doing the Stack Operations.
    top = pop(top);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 4);
    top = push(top, 9);
    top = push(top, 5);
    Traversial(top);
    top = pop(top);
    top = pop(top);
    Traversial(top);
    peek(top, 3);
    return 0;
}