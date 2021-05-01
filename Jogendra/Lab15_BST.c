#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
} Node;

Node *root = NULL;
Node *create();
int insert(int data);
void inorder(Node *temp);
void preorder(Node *temp);
void postorder(Node *temp);
void search(int data);
void menu();

int main(){
	int choice, number, i, value, check, s;

	while(1){
		menu();
		printf("\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				number = 0;
				while(number<=0){
					printf("Number of Nodes : ");
				    scanf("%d",&number);
				}
                for(i=0;i<number;i++){
					printf("Enter Node data : ");
					scanf("%d",&value);
					check = insert(value);
					while(check==-1){
						printf("Enter Node data again : ");
					    scanf("%d",&value);
					    check = insert(value);
					}
					printf("\n\tINORDERED DISPLAY\n");
					inorder(root);
					printf("\n\tPREORDERED DISPLAY\n");
					preorder(root);
					printf("\n\tPOSTORDERED DISPLAY\n");
					postorder(root);
					printf("\n\n");
				}
				
				
				break;
			}


			case 2:{
				printf("Enter data to be searched : ");
				scanf("%d",&value);
				search(value);
				break;				

			}

			case 4:{
				exit(0);
			}

			default:{
				printf("Invalid Choice try again\n");
			}
		}
	}
}

int insert(int data){
	Node *n = create();
	Node *current, *parent;
	n->data = data;

	if(root==NULL){
		root = n;
		return 0;
	}

	else{
		current = root;
		parent = NULL;

		while(1){
			parent = current;
			if(data<parent->data){
				current =current->left;

				if(current==NULL){
					parent->left = n;
					return 0;
				}

			}
			else if(data>parent->data){
				current = current->right;

				if(current==NULL){
					parent->right = n;
		            return 0;
				}
			}

			else{
				printf("No duplicates\n");
				return -1;
			}
		}
	}
}

Node *create(){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(Node *temp){

	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);

	}

}


void preorder(Node *temp){

	if(temp!=NULL){
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);

	}

}

void postorder(Node *temp){

	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);

	}

}

void menu(){
	printf("\n\n1. Insert Node\n");
	printf("2. Search\n");
	printf("3. Exit\n");

}

void search(int data){
	Node *parent, *current;
	int found = 0, count = 0;

	if(root==NULL){
		printf("Binary Search Tree Empty\n");
		return;
	}

	else{
		current = root;
		parent = NULL;
		while(current!=NULL){
			count++;
			parent = current;

			if(data==parent->data){
				printf("Found at Level %d",count);
				found = 1;
				return;
			}

			else if(data>parent->data){
				current = current->right;
			}
			else{
				current = current->left;
			}
			
		}
	}

	if(!found){
		printf("Node with data %d not found\n",data);
		
	}
}
