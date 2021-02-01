//Lab Program 2
//program to delete element from one dimensional array
#include <stdio.h>
#include <stdlib.h>
#define MIN 10 //Min or default memory for the struct pointer

struct array{
    int node;
};

void insert(struct array *s,int m); //to insert elements into struct varibles in pointer
int length(struct array *s); // to find length of  struct pointer
void deleteall(struct array *s); //to delete all values in struct pointer
void deletepos(struct array *s,int pos); //to delete at a paticular position
void delete(struct array *s); //to delete the last element
void display(struct array *);//to diasplay struct pointer
void delete_ele(struct array *,int );// to delete a specific element
void menu();


int main(){

    int flag=1, pos,ele;
    int len_array=MIN;

    char choice;
    struct array *arr = (struct array*)calloc(len_array,sizeof(struct array));


    menu();
    while(flag){
        printf("Choose a Option from menu \n>> ");
        fflush(stdin);
        scanf("%c",&choice);

        switch(choice){
            case 'r':
            case 'R':{
             	//To reallocate memory , default is MIN 10 (saves memory)
                printf("Enter New length \n>> ");
                fflush(stdin);
                scanf("%d",&len_array);

                arr = (struct array*)realloc(arr,len_array*sizeof(struct array));
                break;
            }
            case 'i':
            case 'I':{

                insert(arr,len_array);
                break;
            }

            case 'a':
            case 'A':{
                deleteall(arr);
                break;
            }

            case 'p':
            case 'P':{

                printf("Enter a Position at which element you want to delete \n>> ");
                scanf("%d",&pos);
                deletepos(arr,pos);
                break;

            }
            case 'e':
            case 'E':{
                printf("Enter a element \n>> ");
                scanf("%d",&ele);
                delete_ele(arr,ele);
                break;
            }

            case 'd':
            case 'D':{
                delete(arr);
                break;
            }

            case 'q':
            case 'Q':{
                flag = 0;
                break;
            }

            case 'l':
            case 'L':{
                display(arr);
                break;
            }
            case 'm':
            case 'M':{
                menu();
                break;
            }

            default:{
                printf("Invalid value choose wisely....\n");
                break;
            }
        }


    }

}

void insert(struct array *s,int m){
    int num,j, input,i=length(s);
    printf("length %d\n",i);
    
    printf("Enter number of input\n");
    scanf("%d",&num);
    if(i+num+1>m){
    	printf("Reallocate memory (max limit reached) type r or R\n");
	}
	 
	else{
		for(j=i;j<num+i;j++){
		   printf("Enter >> ");
		   scanf("%d",&input);
		   s[j].node = input;
	}
	}


}

int length(struct array *s){
    int i = 0;
    while(s[i].node!='\0'){
        i++;
    }

    return i;
}

void menu(){
    printf("1. Insert -> i/I \n");
    printf("2. Delete -> d/D\n");
    printf("3. Delete a element -> e/E\n");
    printf("4. Delete all -> a/A\n");
    printf("5. Delete at a position -> p/P\n");
    printf("6. Display Array -> l/L\n");
    printf("7. Menu -> m/M\n");
    printf("8. Reallocate memory (default 10) -> r/R\n");
    printf("9. Quit -> q/Q\n\n");
}

void deleteall(struct array *s){
	int i,len = length(s);
	for(i=0;i<len;i++){
		s[i].node = '\0';
	}
	
}

void delete_ele(struct array *s,int ele){
    int found = 0,pos;
    int i,j,len = length(s);
    for(i=0;i<len;i++){
        if(s[i].node==ele){
            found = 1;
            pos = i;
            s[i].node = 0;
            break;
        }
    }

    if(found){
        for(j=pos;j<len-1;j++){
            s[j].node = s[j+1].node;
        }
        s[len-1].node = '\0';
    }
    else{
    	printf("Element Not found\n");
	}
}

void deletepos(struct array *s,int pos){

    int i,len = length(s);

    if (pos>len && pos<0){
        printf("Invalid position");
    }
    else{
        s[pos-1].node = 0;
        for(i=pos-1;i<len;i++){
            s[i].node = s[i+1].node;
        }

        s[len].node = '\0';
    }

}

void delete(struct array *s){
    int len = length(s);
    if(len>0){
        s[len-1].node = '\0';
    }

    else{
        printf("Array is Empty\n");
    }
}

void display(struct array *s){
    int i=0,len = length(s);
    printf("length %d\n",len);
    if(len!=0){
    	while(s[i].node!='\0'){
    		printf("%d ",s[i].node);
    		i++;
		}
		printf("\n");
	}
	else{
		printf("No element to display\n");
	}
}
