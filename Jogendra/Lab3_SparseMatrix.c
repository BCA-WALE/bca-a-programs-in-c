/*menu driven program to read a sparse matrix of integer values, search and print the appropriately triple
 < row, column, "value" > that represents the elements in the sparse matrix */
#include <stdio.h>

struct sparse{
    int row;
    int column;
    int value;
};

void menu();
void read(int array[100][100],struct sparse s[100],int lenr,int lenc);
void display(int array[100][100],struct sparse s[100],int lenr,int lenc);
void search(int array[100][100],struct sparse s[100],int num,int lenr,int lenc);
int lenghts(struct sparse s[100]);


int main(){
    int array[100][100],flag=1,choice,number;
    static int lengthr=0,lengthc=0;
    struct sparse sparsemat[100];
    menu();
    while(flag){
        printf("Select an option\n>> " );
        scanf("%d",&choice);

        switch(choice){

            case 1:{
                printf("Enter number of rows\n>> ");
                scanf("%d",&lengthr);
                printf("Enter number of columns\n>> ");
                scanf("%d",&lengthc);
                if(lengthr>0 && lengthc>0){
                    read(array,sparsemat,lengthr,lengthc);
                }
                else{
                    printf("Enter a Non Negative Integer\n");
                }
                break;
            }
            case 2:{

                display(array,sparsemat,lengthr,lengthc);
                break;
            }
            case 3:{
                printf("Enter a Number \n>> ");
                scanf("%d",&number);
                search(array,sparsemat,number,lengthr,lengthc);
                break;

            }

            case 4:{
                flag=0;
                break;
            }

            case 5:{
                menu();
                break;
            }
            default:{
                printf("Invalid Option\n");
            }

        }
        
    }
}

void menu(){
    printf("1. Read matrix \n");
    printf("2. Display matrix\n");
    printf("3. Search Element\n");
    printf("4. Exit\n5. Menu\n");
}

void read(int array[100][100],struct sparse s[100],int lenn,int lenm){
    int i,j,m,n,count=0,counter=0;
    printf("Enter matrix of size %d x %d\n",lenn,lenm);
    for(i=0;i<lenn;i++){
        for(j=0;j<lenm;j++){
            scanf("%d",&array[i][j]);

            }
        }
    
    for(m=0;m<lenn;m++){
        for(n=0;n<lenm;n++){
        	
        	if(array[m][n]==0){
                count++;
            }
            else{
                s[counter].row = m+1;
                s[counter].column = n+1;
                s[counter].value = array[m][n];
                counter++;
            }
        }
    }
    


    if((count/(float)(lenn*lenm))>=0.5){
        printf("Entered matrix is a Sparse matrix\n");
    }

    else{
        printf("Not a sparse Matrix\n");
        s[0].value = '\0';
    }

    printf("Sparsity : %.2f \n",(count/(float)(lenn*lenm))*100);
}

void display(int array[100][100],struct sparse s[100],int lenn,int lenm){
    int i =lenghts(s),j,k;

    if(i>0){
        printf("Row  |  Column  |  Value \n");
        for(j=0;j<i;j++){
            printf(" %d        %d        %d   \n",s[j].row,s[j].column,s[j].value);
        }

    }
    else if(i==0){
        for(j=0;j<lenn;j++){
            for(k=0;k<lenm;k++){
                printf("%d ",array[j][k]);
            }
            printf("\n");
        }
    }
    else{
        printf("Nothing to display\nNumber of  elements = 0\n");
    }
}

int lenghts(struct sparse s[100]){
    int i=0;
    while(s[i].value!='\0'){
        i++;
    }
    return i;
}

void search(int array[100][100],struct sparse s[100],int num,int lenn,int lenm){
    int l = lenghts(s),i,j,k,check=0;
    
    if(l>0){

        for(i=0;i<l;i++){
            if(s[i].value==num){
                printf("row = %d | column = %d | value = %d\n",s[i].row,s[i].column,s[i].value);
                check = 1;

            }

        }

    }
    else{
        for(j=0;j<lenn;j++){
            for(k=0;k<lenm;k++){
                if(array[j][k]==num){
                    printf("row = %d | column = %d | value = %d\n",j,k,array[j][k]);
                    check = 1;

                }
            }
        }

    }
    if(check==0){
        printf("Element not found\n");
    }
}
