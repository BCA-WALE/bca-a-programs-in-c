#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
} Node;

int length(Node *h){
	int i = 0;
	Node *head = h;
	while(head!=NULL){
		i++;
		head = head->next;
	}
	return i;
}

Node* newnode(int m,int s,Node *j){
	Node * temp;
	temp = (Node*)malloc(sizeof(Node));
	printf("Enter Data\n>> ");
	scanf("%d",&temp->data);
    if (s==1){
	    while(temp->data>m){
		    printf("Enter Again <= %d\n",m);
		    scanf("%d",&temp->data);
	    }
	}
	else{
		
		if(j==NULL){
			while(temp->data<m ){
		        printf("Enter Again >= %d\n",m);
		        scanf("%d",&temp->data);
	        }	
		}
		else{
			while(temp->data<m || temp->data>j->data){
		        printf("Enter Again >= %d, <=%d\n",m,j->data);
		        scanf("%d",&temp->data);
	        }
			
		}

	    
	}

	temp->next=NULL;
	return temp;

}

Node* ipos(Node *h,int pos,int last){
	Node *head=h,*pre,*n,*end;
	int i=0;
	if (pos==0){
		n = newnode(head->data,1,NULL);
		n->next=head;
		head = n;
		return head;
	}
	
	else{
		while(head!=NULL){
			end = head;
		    if (i==pos-1){
		    	pre=head;
			}
			    
		    head=head->next;
		    i++;
	    }
	    if(pos==last){
	    	n = newnode(end->data,-1,NULL);
	    	end->next = n;
		}
		else{
			n = newnode(pre->data,-1,pre->next);
			n->next=pre->next;
			pre->next = n;
		}
		
		return h;
	}	
}

Node *idata(Node *h,int data){
	Node *head=h,*n=NULL,*d;
	while(head!=NULL){
		if (head->data==data){
			n = head;
			break;
		}
		head = head->next;
	}
	
	if (n==NULL){
		printf("Data Not found\n");
		
	}
	else{
		
		d = newnode(n->data,-1,n->next);
		d->next = n->next;
		n->next = d;
		
	}
	return h;
}


void display(Node *h){
	Node *i;
    for(i=h;i!=NULL;i=i->next){
		printf("%d ", i->data);
	}
	printf("\n\n");
}

void menu(){
	printf("1. Enter n Nodes\n");
	printf("2. Insert at pos\n");
	printf("3. Insert after data\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("6. Menu\n\n\n");
	
}

int main(){
	Node *head,*i,*new;
	int number,min ,choice,len,pos,data,l ;

	head = (Node *)malloc(sizeof(Node));
	printf("Enter Last Node Data\n>> ");
	scanf("%d",&head->data);
	head->next = NULL;
	min = head->data;
	menu();
	while(1){
		printf("Enter your choice\n>> ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("Number of Nodes\n>> ");
				scanf("%d",&len);
				for(number=0;number<len;number++){
		            new = newnode(min,1,NULL);
		            new->next = head;
		            min = new->data;
		            head = new;
		
	            }
	            
	            display(head);
				
				break;
			}
			case 2:{
				printf("Insert by position\n>> ");
				scanf("%d",&pos);
				l = length(head);
				while(pos<0 || pos>l){
					printf("Invalid Position Enter again (0 - %d)\n>> ",l);
					scanf("%d",&pos);
				}
				
				head = ipos(head,pos,l);
				display(head);
				
				break;
			}
			
			case 3:{
				printf("Enter after data\n>> ");
				scanf("%d",&data);
				head = idata(head,data);
				display(head);
				break;
			}
			
			case 4:{
				display(head);
				break;
			}
			
			case 5:{
				exit(0);
				break;
			}
			
			case 6:{
				menu();
				break;
			} 
			
			default:{
				printf("Invalid choice. Press 6 to display menu\n");
				break;
			}
		}
		
	}

	return 0;
}
