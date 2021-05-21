#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *leftchild, *rightchild;
}  ;

void insert(struct node **root, int data) {

	struct node *temp = (struct node*) malloc(sizeof(struct node));
	struct node *current;
	struct node *parent;

	temp->data = data;
	temp->leftchild = temp->rightchild = NULL;

	if(*root==NULL) {
		*root = temp;
		return ;
	}
	else {
		current = *root;
		parent = NULL;

		while(1) {
			parent = current;

			if(data < parent->data) { 			 	//go to left of the tree
				current = current->leftchild;
				if(current == NULL) {				//insert to the left
					parent->leftchild = temp;
					return;
				}
			}
			else {									//go to right of the tree
				current = current->rightchild;
				if(current == NULL) {				//insert to the right
					parent->rightchild = temp;
					return;
				}
			}
		}
	}
}

void search(struct node *head, int data) {
	if(head==NULL) {
		printf("No elements\n");
		return ;
	}
	printf("%d " , head->data);
	if(head->data == data){
		printf("Match Found \n");
		return ;
	}
	if(head->data > data) {						//go to left tree
	 	search(head->leftchild, data);
    }
    else { 										//go to right tree                
         search(head->rightchild, data);
      }
}

void pre_order(struct node *root) {
	if(!root) return;

	printf("%d ",root->data);
	pre_order(root->leftchild);
	pre_order(root->rightchild);
}


void post_order(struct node *root) {
	if(!root) return;

	pre_order(root->leftchild);
	pre_order(root->rightchild);
	printf("%d ",root->data);
}


void in_order(struct node *root) {
	if(!root) return;

	pre_order(root->leftchild);
	printf("%d ",root->data);
	pre_order(root->rightchild);
}

int main() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
   struct node *tree = NULL;
   for(i = 0; i < 7; i++)
      insert(&tree, array[i]);

   i = 31;
   search(tree, i);
   i = 15;
   search(tree, i);

   printf("\nPreorder traversal: ");
   pre_order(tree);

   printf("\nInorder traversal: ");
   in_order(tree);

   printf("\nPost order traversal: ");
   post_order(tree); 

       
   return 0;
 }