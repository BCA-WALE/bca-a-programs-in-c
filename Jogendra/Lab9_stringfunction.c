//String Functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player{
    char name[100] ;
    char team[100] ;

} Player;

void menu(){
    printf("1. Enter Player 1 and 2 details\n");
    printf("2. Display Players\n");
    printf("3. Copy Player 1 to Player 2\n");
    printf("4. Concatinate Player 1 to Player 2\n");
    printf("5. Compare Players\n");
    printf("6. Length of names\n");
    printf("7. Exit\n");
}

void concat(char *p1,char *p2){
	int len1 = length(p1),len2 = length(p2);
	int i,j=0;
	if(len1+len2<100){
		for(i=len1;i<len1+len2;i++){
			p1[i]=p2[j];
			j++;
		}
		p1[i] = '\0';
	}
}

int length(char *p){
    int i;
    while(p[i]!=NULL){
        i++;
    }
    return i;

}

int cmp(char *p1,char *p2){
    int result = 0;
    int i;
    while(p1[i]!='\0' && p2[i]!='\0'){
    	
    	if(tolower(p1[i])>tolower(p2[i])){
    		return 1;
		}
		else if(tolower(p1[i])<tolower(p2[i])){
			return -1;
		}
		i++;
	}
	
	return 0;

}

void copy(char *p1,char *p2){
    int i,len = length(p1);
    
    for(i=0;i<len;i++){
    	p2[i]=p1[i];
	}
	p2[i] = '\0';

}

int main(){
    Player p1,p2;
    int choice,value;
    char name[100];
    char team[100];

    while(1){
        system("cls");
        menu();
        printf("Enter a choice /n>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("\tPlayer 1\n\n");

                printf("Name : ");
                scanf("%s",p1.name);
        

                printf("Team : ");
                scanf("%s",p1.team);
            

                printf("\tPlayer 2\n\n");

                printf("Name : ");
                scanf("%s",p2.name);
        
        
                printf("Team : ");
                scanf("%s",p2.team);
        
                getch();
                break;
            }
            case 2:{
            	
                printf("\tPlayer 1\n\n");
                printf("Name : %s\n",p1.name);
                
                printf("Team : %s\n",p1.team);
                
                printf("\tPlayer 2\n\n");
                printf("Name : %s\n",p2.name);
                
                printf("Team : %s\n",p2.team);
                getch();
                
                break;
            }
            case 3:{
                copy(p1.name,p2.name);
                copy(p1.team,p2.team);
                printf("Done!!!!!!!!!!!!\n");
                getch();
                break;
            }
            case 4:{
                concat(p1.name,p2.name);
                concat(p1.team,p2.team);
                printf("Done!!!!!!!!!!!\n");
                getch();
                break;
            }
            case 5:{
                value = cmp(p1.name,p2.name);
                if(value==0){
                    printf("Both Equal\n");
                }
                else if(value>0){
                    printf("Player 1\n");
                }
                else{
                    printf("Player 2\n");
                }
                getch();
                break;
            }
            case 6:{
                printf("Length of Player 1 name :%d\n",length(p1.name));
                printf("Length of Player 2 name :%d\n",length(p2.name));
                getch();
                break;
            }
            case 7:{
                exit(0);
            }
            default:{
                printf("Invalid choice...\nTry Again...\n");
                getch();
            }
        }
    }
    return 0;

}
