#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pattern{
	char string[100] ;
}Pattern;

typedef struct String{
	char string[1000];
}String;

void menu(){
	printf("1. Enter Strings\n");
	printf("2. Enter Pattern\n");
	printf("3. Find Pattern\n");
	printf("4. Find Substring\n");
	printf("5. Exit\n");
}
void naivepm(Pattern p,String s){
    int lenp = strlen(p.string);
	int lens = strlen(s.string);
//	printf("%d %d\n",lens,lenp);
	int i,j,flag;
	for(i=0;i<lens-lenp+1;i++){
	
		for(j=0;j<lenp;j++){
			if(s.string[i+j]!=p.string[j]){
				break;
			}
		
		}
		if(j==lenp){
			printf("Found at : %d\n",i);
			flag=1;
	    }
    }
	if(!flag){
		printf("Not Found \n");
	}
    
}	


int main(){
	Pattern pat ;
	String str;
	strcpy(pat.string,"") ;
	strcpy(str.string,"");
    char demo[1000];
	int choice,slen=0,plen=0,i,j,first,last;
	while(1){
		system("cls");
		menu();
		printf("\nCurrent String : %s\n",str.string);
		printf("Current Pattern : %s\n",pat.string);
		printf("Enter a valid Choice\n>> ");
		scanf("%d",&choice);

		
		switch(choice){
			case 1:{       
				       printf("Enter String \n>> ");
				       scanf("%s",str.string);
				       slen = strlen(str.string);
				       printf("Enter pattern\n>> ");
				       scanf("%s",pat.string);
				       while(strlen(pat.string)>slen){
					       printf("\tError\n");
					       printf("Enter Pattern Again\n>> ");
					       scanf("%s",pat.string);
                        }
				       plen = strlen(pat.string);

				       getch();
				       break;
		        }
		    case 2:{
				       printf("Enter pattern\n>> ");
				       scanf("%s",pat.string);
				        while(strlen(pat.string)>slen){
					       printf("\tError\n");
					       printf("Enter Pattern Again\n>> ");
					       scanf("%s",pat.string);
                        }
				        plen = strlen(pat.string);
				break;
			}
		        
		    case 3:{
		    	    if(slen!=0 && plen!=0){
				       naivepm(pat,str);
				       getch();
				       break;
		    	    	
					}
					else{
						printf("Enter value for Strings, you nerd...\n");
					}
               
		        getch();	
				break;
			}
			case 4:{
				    if(slen>0){
				        printf("Enter starting index\n>> ");
				        scanf("%d",&first);
				        while(first<0 || first>slen-2){
					       printf("\tError\n");
					       printf("Enter Starting index again\n>> ");
					       scanf("%d",&first);
				       }
				        printf("Enter Ending index\n>> ");
				        scanf("%d",&last);
				        while(last<1 || last>slen-1){
					       printf("\tError\n");
					       printf("Enter Ending index again\n>> ");
					       scanf("%d",&last);
       				}
				        j=0;
				        for(i=first;i<=last;i++){
					       demo[j]=str.string[i];
					       j++;
					}
					printf("Substring : %s\n",demo);
				    }
				    else{
				    	printf("Enter value for Strings, you nerd...\n");
			     	}

                       getch();
				       break;
	                }
			case 5:{
				       exit(0);
                        }

			default:{
					printf("Invalid Option\nTry Again...\n");
					getch();
			    }
		}
   }
		return 0;
}
