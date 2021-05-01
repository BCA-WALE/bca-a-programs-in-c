#include <stdio.h>
#include <stdlib.h>


// Array
int Queue[100];
int max = 0;
int size = 0;

int front = -1;
int rear = -1;

// Queue
typedef struct q{
    int data;
    struct q *next;
}queue;

int sizell = 0;
queue *frontl = NULL;
queue *rearl  = NULL;

void enqueue();
void dequeue();
void display();
void peek();
int isFull();
int isEmpty();
void menu();

int main(){
    int choice;

    printf("Enter Max Length of Queue : ");
    scanf("%d",&max);

    

    while(1){
        
        menu();
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                enqueue();
                display();
                break;
            }
            case 2:{
                dequeue();
                display();
                break;

            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                if(!isFull()){
                    printf("Queue Not Full\n");
                }
                else{
                    printf("Queue Full\n");
                }
                break;
            }
            case 5:{
                if(!isEmpty()){
                    printf("Not Empty\n");
                }
                else{
                    printf("Empty\n");
                }

                break;
            }

            case 6:{
                exit(0);
            }
            default:{
                printf("invalid Choice\n");
            }
        }
    }

    return 0;

}

int isFull(){
    return rear==max-1 || sizell==max;
}

int isEmpty(){
    return front==-1 || sizell==0 || front>rear;
}
void enqueue(){
    int data;

    if(!isFull()){
        
            printf("Enter Data in Array : ");
            scanf("%d",&data);
            if(front==-1 && rear==-1){
                
                front = 0;
                rear = 0;
            }
            else{
                rear++;
            }

            Queue[rear] = data;
            printf("Enter Data in LinkedList : ");
            scanf("%d",&data);
            queue *n = (queue *)malloc(sizeof(queue));

            n->data = data;
            if(frontl==NULL){
                n->next = NULL;
                frontl = rearl = n;
            }
            else{
                rearl -> next = n;  
                rearl = n;  
                rearl->next = NULL;
            }

            sizell++;
            
    }
    else{
        printf("Overflow\n");
    }
}

void dequeue(){
    if(!isEmpty()){
        queue *temp = frontl;
        printf("Dequeued Data in Array : %d\n",Queue[front]);
        printf("Dequeued data  in LinkedList: %d\n",temp->data);
        if(front==rear || front>rear){
            front = rear = -1;
        }
        else{
            front++;
        }

        
        frontl = frontl->next;
        free(temp);
        sizell--;

    }
    else{
        printf("Underflow\n");
    }
}

void display(){
    int i,j=0;
    queue *h = frontl;
    if(!isEmpty()){
        
        printf("Array : ");
        for(i=front;i<=rear;i++){
            printf("%d ",Queue[i]);
        }

        printf("\n");

        printf("Linedlist : ");
        while(h!=NULL){
            printf("%d ",h->data);
            h = h->next;
        }

        printf("\n");


    }

}

void peek(){
    if(!isEmpty()){
        printf("Array : %d\n",Queue[front]);
        printf("Linked List : %d\n",frontl->data);

    }
    else{
        printf("Underflow\n");
    }
    
}
void menu(){
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. isFull\n");
    printf("5. isEmpty\n");
    printf("6. Exit\n\n");
}
