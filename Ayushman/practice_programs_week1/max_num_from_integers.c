// Read and display n numbers using pointers and functions - 1D array
// Display maximum number from the set of integers

#include <stdio.h>
#include <stdlib.h>  // for exit(0)
#include <limits.h>  // for macros

void write(int [], int);
int search_max(int [], int);

int main()
{
	int limit, i, num[20], max_num;
	
	limit = max_num = i = 0;
	
	printf("Enter the total numbers (max 19): ");
	scanf("%d", &limit);
	
	if(limit > 19)
	{
		printf("Max is 19!! Enter a number less than 19!! Aborting!");
		exit(0);
	}
	
	printf("Enter the numbers - \n");

	write(num, limit);
	
	
	printf("Displaying maximum number from the set of integers: ");
	
	max_num = search_max(num, limit);
	
	printf("%d", max_num);
	
	
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



int search_max(int num[], int limit)
{
	int *ptr, i;
	ptr = num;
	i = 0;
	
	int min = INT_MIN;
	
	for(i = 0; i < limit; i++)
	{
		if(min < *(ptr + i))
		{
			min = *(ptr + i);
		}
	}
	return min;
}
