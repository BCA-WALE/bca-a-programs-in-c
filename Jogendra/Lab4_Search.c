//menu driven program to implement linear search (sentinel) and binary search
#include <stdio.h>
#include <stdlib.h>

struct arrayint{
    int node;
};


struct arraychar{
    char node;
};

void linear(struct arrayint *s);
void linearc(struct arraychar *s);

void sentinel(struct arrayint *s,int num);
void sentinelc(struct arraychar *s,char num);

void binary(struct arrayint *s);
void binaryc(struct arraychar *s);

void bubblesort(struct arrayint *s);
void bubblesortc(struct arraychar *s);

int length(struct arrayint *s);
int lengthc(struct arraychar *s);

void bubblesort(struct arrayint *s);
void bubblesortc(struct arraychar *s);

void menu();
// 1 enter char array 
// 2 enter a int array 
// menu
// exit

// linear sentinel
// binary search
// exit

int main(){
    int flag =1,choice ,numint,numchar,i,j,subchoice,subchoice2,element;
    struct arraychar *chararray = (struct arraychar*)calloc(50,sizeof(struct arraychar));
    struct arrayint *intarray = (struct arrayint*)calloc(50,sizeof(struct arrayint));

    menu();
    while(flag){
        printf("Enter any choice \n>> ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter number of Elements \n>> ");
                scanf("%d",&numint);

                if(numint>0 && numint<=50){
                    for(i=0;i<numint;i++){
                        scanf("%d",&intarray[i].node);
                    }

                    printf("1.Linear Sentinel Search\n");
                    printf("2.Binary Search\n");
                    printf("Enter a choice \n>> ");
                    fflush(stdin);
                    scanf("%d",&subchoice);
                    switch(subchoice){
                        case 1:{
                            linear(intarray);

                            break;
                        }
                        case 2:{
                            binary(intarray);
                            break;

                        }

                        default:{
                            printf("Invalid input\n");
                        }
                        
                        }
                    }
                else{
                    printf("Enter a valid Number 1-50\n");
                }
                break;

                }

            case 2:{
                printf("Enter number of Elements \n>> ");
                scanf("%d",&numchar);

                if(numchar>0 && numchar<=50){
                    for(i=0;i<numchar;i++){
                    	fflush(stdin);
                        scanf("%c",&chararray[i].node);
                    }
                    
                    printf("1.Linear Sentinel Search\n");
                    printf("2.Binary Search\n");
                    printf("Enter a choice \n>> ");
                    fflush(stdin);
                    scanf("%d",&subchoice2);
                    switch(subchoice2){
                        case 1:{
                            
                            linearc(chararray);

                            break;
                        }
                        case 2:{
                            binaryc(chararray);
                            break;

                        }

                        default:{
                            printf("Invalid input\n");
                        }
                        
                        }
                    }
                else{
                    printf("Enter a valid Number 1-50\n");
                }
                break;
        
            }

        case 3:{
            menu();
            break;
        }
        case 4:{
            flag = 0;
            break;
        }
        default :{
            printf("Invalid input\n");
        }
        }

    }
}

void menu(){
    printf("1. Enter a int array \n");
    printf("2. Enter a char array\n");
    printf("3. Menu\n");
    printf("4. Exit\n");

}

int length(struct arrayint *s){
    int i=0;
    while(s[i].node!='\0'){
        i++;
    }
    return i;
}

int lengthc(struct arraychar *s){
    int i=0;
    while(s[i].node!='\0'){
        i++;
    }
    return i;
}

void linear(struct arrayint *s){

    int len = length(s),i,element,found=0;
    
    printf("Enter element \n>> ");
    fflush(stdin);
    scanf("%d",&element);
    printf("\tLinear\n");
    for(i=0;i<len;i++){
        if(s[i].node==element){
            printf("Element Found at %d \nNumber of Comparison %d\n\n",i,(2*(i+1)));
            found=1;
            break;
        }
    }
    if (found==0){
        printf("element not found\n");
    }
    sentinel(s,element);


}

void linearc(struct arraychar *s){

    int len = lengthc(s),i,found=0,l=0;
    char element;

    printf("Enter char  \n>> ");
    fflush(stdin);
    scanf("%c",&element);
    printf("\tLinear\n");
    for(i=0;i<len;i++){
        if(s[i].node==element){
            printf("Element Found at %d \nNumber of Comparison %d\n\n",i,(2*(i+1)));
            found=1;
            break;
        }

    }

    if (found==0){
        printf("element not found\n");
    }
    sentinelc(s,element);
}

void sentinel(struct arrayint *s,int element){
    int len = length(s),i=0,last;
    printf("\tSentinel\n");
    last = s[len-1].node;
    s[len-1].node=element;
    while(s[i].node!=element){
        i++;
    }
    s[len-1].node=last;

    if((i<len-1) || (element==s[len-1].node)){
        printf("Element found at %d\n",i);
        printf("Number of Comparison : %d\n",i+2);
    }
    else{
        printf("Not Found\n");
    }
}

void sentinelc(struct arraychar *s,char element){
    int len = lengthc(s),i=0,last;
    printf("\tSentinel\n");
    last = s[len-1].node;
    s[len-1].node=element;
    while(s[i].node!=element){
        i++;
    }
    s[len-1].node=last;

    if((i<len-1) || (element==s[len-1].node)){
        printf("Element found at %d\n",i);
        printf("Number of Comparison : %d\n",i+3);
        

    }
    else{
        printf("Not Found\n");
    }
}

void binary(struct arrayint *s){
    int low=0, len = length(s),high = len-1,x,element,found = 0;
    printf("Enter a int element\n>> ");
    fflush(stdin);
    scanf("%d",&element);
    bubblesort(s);
    while(low<=high){
        x = (low+high)/2;
        if(element==s[x].node){
            printf("Element found at %d\n",x);
            found = 1;
            break;
        }
        else if(element<s[x].node){
            high = x - 1;
        }
        else{
            low = x + 1;
        }
    }

    if(found==0){
        printf("Element not found\n");
    }

}

void binaryc(struct arraychar *s){
    int low=0, len = lengthc(s),high = len-1,x,found = 0;
    char element;
    printf("Enter a int element\n>> ");
    fflush(stdin);
    scanf("%c",&element);
    bubblesortc(s);
    while(low<=high){
        x = (low+high)/2;
        if(element==s[x].node){
            printf("Element found at %d\n",x);
            found = 1;
            break;
        }
        else if(element<s[x].node){
            high = x - 1;
        }
        else{
            low = x + 1;
        }
    }

    if(found==0){
        printf("Element not found\n");
    }

}

void bubblesort(struct arrayint *s){
    int sort ,len= length(s),i,j,temp;

    for(i=0;i<len-1;i++){
        sort = 1;
        for(j=0;j<len-i-1;j++){
            if(s[j].node>s[j+1].node){
                temp = s[j].node;
                s[j].node = s[j+1].node;
                s[j+1].node = temp;
                sort = 0;
            }

        }

        if(sort==1){
            break;
        }
    }
}
void bubblesortc(struct arraychar *s){
    int sort ,len= lengthc(s),i,j;
    char temp;


    for(i=0;i<len-1;i++){
        sort = 1;
        for(j=0;j<len-i-1;j++){
            if(s[j].node>s[j+1].node){
                temp = s[j].node;
                s[j].node = s[j+1].node;
                s[j+1].node = temp;
                sort = 0;
            }

        }

        if(sort==1){
            break;
        }
    }
}

