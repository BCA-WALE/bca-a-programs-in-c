#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10 
#define VAL 5

struct empl{

    char name[100];
	int id;

};

void quicksort(struct empl *s,char sortby,int order,int first,int last);
void menu();
void display(struct empl *s);
int length(struct empl *s);
void generate(struct empl *s,int n);

int main(){
    
    struct empl *employee = (struct empl*)calloc(MAX,sizeof(struct empl));
    int flag=1,choice,len,order=0,check;
    char c,sby='q';

    generate(employee,VAL);
    while(flag){
        system("cls");
        menu();
        printf("Choose an Option \n>> ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter Length\n");
                scanf("%d",&len);
                generate(employee,len);
                c=getch();
                break;
            }

            case 2:{
                display(employee);
                c=getch();
                break;
            }

            case 3:{
                check = 0;
                order = 0;
                sby = 'q';
                while( (sby!='i' && sby!='n' ) || order==0  ){

                    if(check==1){
                        printf("Enter Valid Values\n\n");
                    }
                    printf("Enter the Order \n");
                    printf("0 > Ascending , 0 < Desending \n>> ");
                    scanf("%d",&order);
                    printf("Sort By (i,n) >>\n");
                    fflush(stdin);
                    scanf("%c",&sby);
                    check = 1;

                }

                printf("Before : \n");
                display(employee);

                quicksort(employee,sby,order,0,length(employee)-1);
                printf("After :\n");
                display(employee);
                c=getch();
                break;

            }

            case 4:{
                exit(0);
                break;
            }

            default:{
                printf("Invalid value\n");
                c=getch();
                break;
            }
        }
    }

}

void menu(){
    printf("1. Generate New data\n");
    printf("2. Display\n");
    printf("3. Selection Sort\n");
    printf("4. Exit\n\n");
}

void generate(struct empl *s,int n){
    
    char alph[27] = "abcdefghijklmnopqrstuvwxyz";
    int i,low=5,upper = 12,j,num;

    if(n>MAX){
        
        s = (struct empl*)realloc(s,(n+2)*sizeof(struct empl));
    }

    
    srand(time(0));
    for(i=0;i<n;i++){
        num = (rand()%(upper-low))+low;
        s[i].id = rand()%100;
        for(j=0;j<num;j++){
            s[i].name[j] = alph[rand()%26];
        }
    }
    s[i].id = '\0';
}

void quicksort(struct empl *s,char sortby,int order,int first,int last){
    int i,j,pivot;

    struct empl temp;
 
    if(sortby=='i'){
        if(order>0){
            if(first<last){
                pivot = first;
                i = first;
                j = last;
                while(i<j){
                    while(s[i].id<=s[pivot].id && i<last){
                        i++;
                    }
                    while(s[j].id>s[pivot].id){
                        j--;
                    }
                    if(i<j){
                        temp = s[j];
                        s[j] = s[i];
                        s[i] = temp;
                    }
                }
                temp = s[pivot];
                s[pivot] = s[j];
                s[j] = temp;
                quicksort(s,sortby,order,first,j-1);
                quicksort(s,sortby,order,j+1,last);

            }



        }
        else{
            if(first<last){
                pivot = first;
                i = first;
                j = last;
                while(i<j){
                    while(s[i].id>=s[pivot].id && i<last){
                        i++;
                    }
                    while(s[j].id<s[pivot].id){
                        j--;
                    }
                    if(i<j){
                        temp = s[j];
                        s[j] = s[i];
                        s[i] = temp;
                    }
                }
                temp = s[pivot];
                s[pivot] = s[j];
                s[j] = temp;
                quicksort(s,sortby,order,first,j-1);
                quicksort(s,sortby,order,j+1,last);

            }

    }
}
    else if(sortby=='n'){
        if(order>0){
            if(first<last){
                pivot = first;
                i = first;
                j = last;
                while(i<j){
                    while(strcmp(s[i].name,s[pivot].name)<=0 && i<last){
                        i++;
                    }
                    while(strcmp(s[j].name,s[pivot].name)>0){
                        j--;
                    }
                    if(i<j){
                        temp = s[j];
                        s[j] = s[i];
                        s[i] = temp;
                    }
                }
                temp = s[pivot];
                s[pivot] = s[j];
                s[j] = temp;
                quicksort(s,sortby,order,first,j-1);
                quicksort(s,sortby,order,j+1,last);

            }

        }

        else{
            if(first<last){
                pivot = first;
                i = first;
                j = last;
                while(i<j){
                    while(strcmp(s[i].name,s[pivot].name)>=0 && i<last){
                        i++;
                    }
                    while(strcmp(s[j].name,s[pivot].name)<0){
                        j--;
                    }
                    if(i<j){
                        temp = s[j];
                        s[j] = s[i];
                        s[i] = temp;
                    }
                }
                temp = s[pivot];
                s[pivot] = s[j];
                s[j] = temp;
                quicksort(s,sortby,order,first,j-1);
                quicksort(s,sortby,order,j+1,last);

            }



        }

    }
    

}

int length(struct empl *s){
    int i=0;
    while(s[i].id!='\0'){
        i++;
    }
    return i;
}

void display(struct empl *s){
    int i,len = length(s);
    for(i=0;i<len;i++){
        printf("ID : %d  NAME : %s\n",s[i].id,s[i].name);
    }
}
