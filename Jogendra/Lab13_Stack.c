#include <stdio.h>
#include <stdlib.h>

// Stack using array
int stack[100],top_a = -1;


//Stack using Linkedlist
typedef struct node{
	int data;
	struct node *next;
} Node;

Node *top = NULL;
int max = 0;
int len = 0;

// Stack Operations 

void push();
void pop();
int overflow();
int underflow();
void display();
void menu();
void peek();
Node *createNode();

int main(){
	int choice;

    printf("Enter a Max capacity\n");
	scanf("%d",&max);
	while(max<1 || max>100){
		printf("Enter a Max capacity\n");
	    scanf("%d",&max);	
	}

	menu();

	while(1){
		printf("Enter a choice : ");
		scanf("%d",&choice);
		switch(choice){

		case 1:{
			push();
			break;
		}

		case 2:{
			pop();
			break;

		}

		case 3:{
			peek();
			break;
		}

		case 4:{
			display();
			break;
		}
		case 5:{
			menu();
			break;
		}

		case 6:{
			exit(0);
		}

		default:{
			printf("Invalid Input\n");

		}
		}
	}
	return 0;

}

int overflow(){
	return len==max || top_a == max-1;
}

int underflow(){
	return top==NULL || top_a == -1;
}

void peek(){
	if(!underflow()){
		printf("Linked List : %d\n",top->data);
		printf("Array : %d\n\n",stack[top_a]); 
	}
	else{
		printf("Underflow\n");
	}
}
void push(){
	Node *n;
	int data;
	if(!overflow()){
		n = createNode();

		n->next = top;
		top = n;
		printf("Enter Data for array stack : ");
		scanf("%d",&data);
		top_a++;
		stack[top_a] = data;
		len++;
	}
	else{
		printf("Overflow\n");
	}
}

void pop(){
	Node *n;
	if(!underflow()){
		n = top;
		top = n->next;
		printf("Deleted in LinkedList : %d\n",n->data);
		printf("Deleted in Array : %d\n\n",stack[top_a]);
		free(n);
		top_a--;
		len--;
	}
	else{
		printf("Underflow\n");
	}
	
}

void display(){
	Node *n = top;
	int  i =top_a;
	if(underflow()){
		printf("Nothing to display\n");
	}
	else{
		printf("Linked List : ");
		while(n!=NULL){
			printf("%d ",n->data);
			n = n->next;
		}
		printf("\n");
		printf("Array : ");
		while(i>=0){
			printf("%d ",stack[i]);
			i--;
		}

		printf("\n\n");
	}
}

Node *createNode(){
	Node *p = (Node *)malloc(sizeof(Node));
	printf("Enter Data for LinkedList : ");
    scanf("%d",&p->data);
	p->next = NULL;
	return p;

}

void menu(){
	printf("\tSTACK\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Display\n");
	printf("5. Menu\n");
	printf("6. Exit\n\n");

}
