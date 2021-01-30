// Read and display n numbers using pointers and functions - 1D array
// display odd numbered position elements

#include <stdio.h>
#include <stdlib.h>  // for exit(0)

void write(int [], int);
void read(int [], int);

int main()
{
	int limit, i, num[20];
	
	limit = i = 0;
	
	printf("Enter the total numbers (max 19): ");
	scanf("%d", &limit);
	
	if(limit > 19)
	{
		printf("Max is 19!! Enter a number less than 19!! Aborting!");
		exit(0);
	}
	
	printf("Enter the numbers - \n");

	write(num, limit);
	
	
	printf("Displaying the odd positioned number elements - \n");
	
	read(num, limit);
	
	
	return 0;
}



void write(int num[], int limit)
{
	int *ptr = NULL;
	
	ptr = num;
	int i = 0;
	
	for(i = 0; i < limit; i++)
	{
		scanf("%d", (ptr + i));
	}
}



void read(int num[], int limit)
{
	int *ptr, i;
	ptr = num;
	i = 0;
	
	for(i = 0; i < limit; i+= 2)
	{
		printf("%d\n", *(ptr + i));
	}
}
