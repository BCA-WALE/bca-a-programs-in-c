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

Node* newnode(int m,int s){
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
		while(temp->data<m){
		    printf("Enter Again >= %d\n",m);
		    scanf("%d",&temp->data);
	    }
	}

	temp->next=NULL;
	return temp;

}

Node* delpos(Node *h,int pos){
	Node *head= h,*pre,*n,*end;
	int i=0;
	if (pos==0){
		head = h->next;
		free(h);
		return head;
	}
	
	else{
		while(head!=NULL){
			
		    if (i==pos-1){
		    	pre=head;
			}
			if(i==pos){
			  n=head;
			  break;
			}
			    
		    head=head->next;
		    i++;
	    }
	    pre->next = n->next;
	    free(n);
		
		return h;
	}	
}

Node *deldata(Node *h,int data){
	Node *head=h,*n=NULL,*d=NULL;
	while(head!=NULL){
		if (head->data==data){
			n = head;
			break;
		}
		d = head;
		head = head->next;
	}
	
	if (n==NULL){
		printf("Data Not found\n");
		
	}
	else if(d==NULL){
	  head= n->next;
	  free(n);
	  return head;
	  
	}
	else{
		
		
		d->next = n->next;
		free(n);
		
	}
	return h;
}

Node *del(Node *h, int s,int num){
  Node *head = h, *n,*prev=NULL;
  int i= 0;

  while(head!= NULL && i<=s){
    if(i==s){
      while(num>0){
    
        n = head;
        head = head->next;
        free(n);
        num--;
      }
      break;
    }
    if(i==s-1){
    	prev = head;
	}
    i++;
    head = head->next;
    
  }

  if(s==0){
    return head;
  }
  prev->next = head;
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
	printf("2. Delete at pos\n");
	printf("3. Delete by data\n");
	printf("4. delete n nodes\n");
	printf("5. Display\n");
	printf("6. Exit\n");
	printf("7. Menu\n\n\n");
	
}

int main(){
	Node *head,*i,*new;
	int number,min ,choice,len,pos,data,l ,x,s;

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
		            new = newnode(min,1);
		            new->next = head;
		            min = new->data;
		            head = new;
		
	            }
	            
	            display(head);
				
				break;
			}
			case 2:{
				printf("Delete by position\n>> ");
				scanf("%d",&pos);
				l = length(head);
				while(pos<0 || pos>l){
					printf("Invalid Position Enter again\n>> ");
					scanf("%d",&pos);
				}
				
				head = delpos(head,pos);
				display(head);
				
				break;
			}
			
			case 3:{
				printf("Enter  data\n>> ");
				scanf("%d",&data);
				head = deldata(head,data);
				display(head);
				break;
			}
			case 4:{
			  l= length(head);
			  printf("Enter starting position\n>> ");
			  scanf("%d",&s);
			  while(s<0 || s>=l){
			    printf("Invalid input range 0-%d",l);
			    scanf("%d",&s);
			  }
			  
			  printf("\nEnter number of nodes to delete\n>>");
			  scanf("%d",&x);
			  while((x+s)>l || x <=0){
			    printf("Invalid input range 1-%d",l-s);
			    scanf("%d",&x);
			  }
			  head = del(head,s,x);
			  display(head);
			  break;
			   
			}
			
			case 5:{
				display(head);
				break;
			}
			
			case 6:{
				exit(0);
				break;
			}
			
			case 7:{
				menu();
				break;
			} 
			
			default:{
				printf("Invalid choice. Press 7 to display menu\n");
				break;
			}
		}
		
	}
	return 0;
}
