#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *next, *prev;
};

void  print() {
	printf("Choose your option : \n");
	printf("1) add at end\t2) add at specified position\t3) add at beginning of this list\n");
	printf("4) Display\t5) delete by number\t6) delete by position\t7) reverse\n");
	printf("8) Find Minimum\t9) Find Maximum\t10) Exit\n\n");
}
void display(struct node *ll){
	if(ll==NULL) {
		printf("Nothing to print \n");
		return;
	}
	while(ll->next!=NULL) {
		printf("%d ",ll->data);
		printf("=> ");
		ll = ll->next;
	}	printf("%d\n",ll->data);
}
void addlast(struct node **ll, int data) {
	struct node *head = *ll;

	struct node *insert = (struct node*) malloc(sizeof(struct node));
	insert->data = data; insert->next = NULL;
	if(head==NULL) {
		(*ll) = insert;
		return ;
	} else {
		while(head->next!=NULL)
			head = head->next;
		head->next = insert;
		insert->prev = head;
	}
}
void addFirst(struct node **ll, int data) {
	struct node *insert = (struct node*) malloc(sizeof(struct node));
	
	insert->data = data; 
	insert->next = *ll; 
	insert->prev = NULL;

	(*ll)->prev = insert;
	(*ll) = insert;
}
void add(struct node **ll, int data, int pos) {
	if(pos==0) return addFirst(ll, data);

	struct node *head = *ll;
	struct node *insert = (struct node*) malloc(sizeof(struct node));
	insert->data = data;

	for(int ind=1;head;ind++) {
		if(ind==pos) {
			insert->next = head->next;
			insert->prev = head;
			head->next = insert;
			return ;
		}
		head=head->next;
	}
	printf("Given position out of range\n");
}

int max(struct node *ll) {
	int maxNum = ll->data;
	while(ll){
		if(maxNum<ll->data) maxNum = ll->data;
		ll = ll->next;
	}
	return maxNum;
}
int min(struct node *ll) {
	int minNum = ll->data;
	while(ll){
		if(minNum>ll->data) minNum = ll->data;
		ll = ll->next;
	}
	return minNum;
}


int main() {
	struct node *ll = NULL; //(struct node*) malloc(sizeof(struct node));
	
	int choose, data, pos; 

	while(1) {
		print();
		scanf("%d", &choose);

		switch(choose) {
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				addlast(&ll, data);
				break;
			case 2:
				printf("Enter the position : ");
				scanf("%d", &pos);
				printf("Enter the data: ");
				scanf("%d", &data);
				add(&ll, data, pos);
				break;
			case 3:
				printf("Enter the data: ");
				scanf("%d", &data);
				addFirst(&ll, data);
				break;
			case 4:
				display(ll);
				break;
			case 8:
				printf("Minimum : %d\n", min(ll));
				break;
			case 9:
				printf("Maximum : %d\n", max(ll));
				break;
			case 10:
				return 0;
			default :
				printf("Enter correct value\n");
		}
	}

	return 0;
}