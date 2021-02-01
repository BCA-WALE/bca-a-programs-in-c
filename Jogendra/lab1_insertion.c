//Lab Program 1
//program to insert element(s) in one dimensional array. 
#include <stdio.h>
#include <stdlib.h>


struct array{
    int node;
};

void menu(void); //to display menu
void display(struct array *); //to display elements in struct pointer
void insert(struct array *,int n,int m); //to insert element at last tag variable in struct pointer
void insertpos(struct array *,int n,int pos,int m); //to insert at a particular position
int length(struct array *);// to calculate length of struct pointer

int main(){
    int flag=1,number,pos;
    static int len_a=5;
    char choice;
    struct array *userarray = (struct array*)calloc(len_a,sizeof(struct array));
    menu();
    while(flag){

        printf("Enter You Choice \n>> ");
        fflush(stdin);
        scanf("%c",&choice);

        switch(choice){
            case 'r':
            case 'R':{
            	//To reallocate memory , default is 5 (saves memory)
                printf("Enter a length \n>> ");
                scanf("%d",&len_a);
                userarray = (struct array*)realloc(userarray,sizeof(struct array)*len_a);
                break;
            }

            case 'i':
            case 'I':{
                printf("Enter a number \n>> ");
                scanf("%d",&number);
                insert(userarray,number,len_a);
                break;
            }
            case 'p':
            case 'P':{
                printf("Enter a number \n>> ");
                scanf("%d",&number);
                printf("Enter a Position 1-%d \n>> ",length(userarray));
                scanf("%d",&pos);
                insertpos(userarray,number,pos,len_a);
                break;
            }

            case 'd':
            case 'D':{
                display(userarray);
                break;
            }

            case 'm':
            case 'M':{
                menu();
                break;
            }
            case 'q':
            case 'Q':{
                flag=0;
                break;
            }

            default:{
                printf("Invalid Input Choose wisely....\nType m or M to check Menu\n");
                break;
            }
        }

    }
}

void menu(void){
    printf("\tMenu\n");
    printf("\n1. Insert Element -> (i/I)\n");
    printf("2. Insert Element at Position -> (p/P)\n");
    printf("3. Reallocate Memory (default 5) -> (r/R)\n");
    printf("4. Display Array -> (d/D)\n");
    printf("5. Check Menu -> (m/M)\n");
    printf("6. Quit -> (q/Q)\n");
}

int length(struct array *s){
    int i=0;
    while(s[i].node!='\0'){
        i++;
    }
    return i;
}

void insert(struct array *s,int n,int m){
    int len = length(s);
    if(len<m){
        s[len].node = n;
        printf("Inserted at %d\n",len+1);
    }
    else{
        printf("Length exceeded type r or R to reallocate memory\n");
    }
    
}

void insertpos(struct array *s,int n,int pos,int m){
    int  len = length(s);
    if(pos<=len && pos>=1 && len+1<m){
    len-=1;

    while(1){
        s[len+1].node=s[len].node;
        if(len==pos-1){
            s[len].node=n;
            break;
        }
        len--;
    }
    }
    else if(len+1>=m){
        printf("Reallocte Memory type r or R\n");
    }
    else{
        printf("Enter a valid position between 1 - %d\n",len);
        
    }

}

void display(struct array *s){
    int i,len = length(s);
    if(len>0){
    for(i=0;i<len;i++){
        printf("%d ",s[i].node);
    }
    printf("\n");

    }
    else{
        printf("Array is empty type i or I to Insert\n");
    }

}

