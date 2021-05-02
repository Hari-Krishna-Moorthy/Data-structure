#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next, *prev;
} *head, *tail;

void create() {
    head = tail = (struct Node*) malloc(sizeof(struct Node));
    head->next = head->prev = NULL;
}

void enqueue(int data) {
    if(head == NULL) {
        create();
        head->data = data;
    } else {
        tail->next = (struct Node*) malloc(sizeof(struct Node));
        tail->next->prev = tail;
        tail = tail->next;
        tail->data = data;
        tail->next = NULL;
    }
}

void printQueue() {
    struct Node *temp = head;
    while(temp->next) {
        printf("%d " , temp->data);
    }   printf("\n");
}
int dequeue() {
    if(head == NULL){
        printf("[INFO] NO ELEMENTS \n");
    } else {
        int return_data ;
        if(head == tail) {
            return_data = head->data;
            free(head);
            head = tail = NULL;
        } else {
            return_data = head->data;
            head = head->next;
            free(head->prev);
        }
        return return_data;
    }

}

int main() {
    struct Node *q ;
    enqueue(1);
    enqueue(2);
    printQueue();
    printf("%d \n" , dequeue());
    printf("%d \n" , dequeue());
    
    return 0;
}