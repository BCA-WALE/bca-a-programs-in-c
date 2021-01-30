/*
a program to insert character element(s) in one dimensional array. 
*/


#include <stdio.h>
#include <stdlib.h>


// function declaration
void menu(void);


// main function
int main()
{
	// declaration of variables
	int i, limit, option, _exit, position;
	char element, array[25];
	

	// initialisation of variables
	i = limit = option = _exit = position =0;
	element = 't';
	
	
	
	do
	{
		system("clear");

		menu();

		printf("\n\n\tEnter your option: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1: {
				 printf("\n\tEnter number of elements in array: ");
				 scanf("%d", &limit);
				 
				 printf("\n\tEnter %d elements\n", limit);
				 fflush(stdin);
				 
				 for (i = 0; i < limit; i++)
				 {
					 printf("\n\tElement %d: ", (i + 1));
					 fflush(stdin);  // find out the header file for linux - bad practice - https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
					 scanf(" %c", &array[i]);  // shortcut - "%c"
				 }
				
				}
				break;
				
			case 2: {
				
				if(limit == 0)
				{
					printf("\n\n\n\tFirst enter elements of array!");
					printf("\n\tPress option 1 in the menu.\n\n");
					getchar();
					
					menu();
					option = 0;
					
				}
				else
				{
					printf("\n\tThe %d elements are -\n\n", limit);
					
					   for (i = 0; i < limit; i++)
					   {
						   printf("\n\tAt position %d: %c\n", (i + 1), array[i]);
					   }
					
					}
				}
				break;
				
			case 3: {
				if(limit == 0)
				{
					printf("\n\n\n\tFirst enter elements of array!");
					printf("\n\tPress option 1 in the menu.\n\n");
					getchar();
					
					menu();
					option = 0;
					
				}
				printf("\n\tEnter position where you want to insert an element: ");
				scanf("%d", &position);
			 
				printf("\n\tEnter element to insert: ");
				scanf("%c", &element);
			 
				for (i = (limit - 1); i >= (position - 1); i--)
				{
					array[i+1] = array[i];
				}
							 
				array[position-1] = element;
				limit++;
			 
				printf("\n\tResultant array is -\n");
			 
				for (i = 0; i < limit; i++)
				{
					printf("\n\tAt position %d: %c\n", (i + 1), array[i]);
				}
				
				}
				break;			
				
			case 4: exit(0);
					break;

			default: printf("\n\tKindly input the correct given options. Thank you.");
					

		}

		printf("\n\n\n\tDo you want to run the program again? (enter any number for yes, '0' for no): ");
		scanf("%d", &_exit);

        }while(_exit != 0);


	return 0;
}


// funtion definitons

// menu		
void menu(void)
{
	printf("\n\tLAB 1 INSERTION PROGRAM!");
	printf("\n\t________________________________\n\n");
	
	printf("\n\n\t\t\tMENU");
	
	printf("\n\n\t1. Enter character elements in the array.");
	printf("\n\n\t2. Display the array elements");
	printf("\n\n\t3. Insert an element.");
	printf("\n\n\t4. Exit.\n");
	
}




 
   
