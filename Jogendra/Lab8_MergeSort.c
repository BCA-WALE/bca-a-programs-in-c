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

void mergesort(struct empl *s,char sortby,int order,int low,int high);
void merge(struct empl *s,char sortby,int order,int low,int mid,int high);
void menu();
void display(struct empl *s);
int length(struct empl *s);
void generate(struct empl *s,int n);

int main(){
    
    struct empl *employee = (struct empl*)calloc(MAX,sizeof(struct empl));
    int flag=1,choice,len,order=0,check,highi,lowi;
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
                len = length(employee);
                lowi = 0;
                highi = len - 1;
                mergesort(employee,sby,order,lowi,highi);
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
    printf("3. mergesort Sort\n");
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

void mergesort(struct empl *s,char sortby,int order,int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;

        mergesort(s,sortby,order,low,mid);
        mergesort(s,sortby,order,mid+1,high);
        merge(s,sortby,order,low,mid,high);

    }
}
void merge(struct empl *s,char sortby,int order,int low,int mid,int high){
   


    int l=0,r=0,a=low ,nl = mid-low+1,nr = high-mid,i,j;
    struct empl leftarray[nl],rightarray[nr];


    for(i=0;i<nl;i++){
        leftarray[i] = s[low+i];
    }
    for(j=0;j<nr;j++){
        rightarray[j] = s[mid+1+j];
    }

 
    if(sortby=='i'){

        if(order>0){
            while(l<nl && r<nr){
                if(leftarray[l].id<=rightarray[r].id){
                    s[a] = leftarray[l];
                    l++;
                }
                else{
                    s[a]= rightarray[r];
                    r++;
                }
                a++;
            }
    }

        else{
            while(l<nl && r<nr){
                if(leftarray[l].id>=rightarray[r].id){
                    s[a] = leftarray[l];
                    l++;
                }
                else{
                    s[a]= rightarray[r];
                    r++;
                }
                a++;
            }

    }
}
    else if(sortby=='n'){
        if(order>0){
            while(l<nl && r<nr){
                if(strcmp(leftarray[l].name,rightarray[r].name)<=0){
                    s[a] = leftarray[l];
                    l++;
                }
                else{
                    s[a]= rightarray[r];
                    r++;
                }
                a++;
            }


        }

        else{
            while(l<nl && r<nr){
                if(strcmp(leftarray[l].name,rightarray[r].name)<=0){
                    s[a] = leftarray[l];
                    l++;
                }
                else{
                    s[a]= rightarray[r];
                    r++;
                }
                a++;
            }
        }

    }
    while(l<nl){
        s[a] = leftarray[l];
        l++;
        a++;}
    while(r<nr){
        s[a] = rightarray[r];
        r++;
        a++;
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
