#include <stdio.h>
#include <stdlib.h>

 
struct stack {
    int data;
    struct stack* link;
};
 
struct stack* top;
 
void push(int data) {
     
    struct stack* temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
 
    if (!temp)  {
    	printf("Heap Overflow\n");
        exit(1);
    }
 
	temp->data = data;
 
	temp->link = top;
 
    top = temp;
}
int isEmpty() {
    return top == NULL;
}
 int peek() {
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}
void pop() {
    struct stack* temp;
     if (top == NULL)  {
     	printf("Stack Underflow \n" );
        exit(1);
    }
    else {
         
        temp = top;
 		top = top->link;
 
        temp->link = NULL;
 		free(temp);
    }
}
 
void display() {
    struct stack* temp;
     if (top == NULL)  {
     	printf("Stack Underflow\n");
        exit(1);
    }
    else {
        temp = top;
        while (temp != NULL) {
        	printf("%d -> ",temp->data);
            temp = temp->link;
        }
    }
}
 
int main() {
    push(11);
    push(22);
    push(33);
    push(44);
 
    display();
 	
 	printf("Top element is %d\n", peek());
 
    pop();
    pop();
 
    display();

 	printf("Top element is %d\n", peek());
 	pop();
	printf("Top element is %d\n", peek());
 	pop();
 	printf("Top element is %d\n", peek());
 	return 0;
}
 