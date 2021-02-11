#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Linear_Sentinel_Search(int [], int, int);
void sort(int [], int);
void string_sort(char arr[100][100], int);
int int_binary_search(int [], int, int);
int string_binary_search(char arr[100][100], char [], int);

int main() {
	int choice, choice2, n, *ptr, i, target, a;
	char arr[100][100], n1[100];
	do
	{
		printf("\n1.Linear(Sentinel) search\n2.Binary Search\n3.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter n: ");
				scanf("%d", &n);
				ptr = (int *)malloc(n*sizeof(int));
				for(i=0; i<n; i++)
					scanf("%d", &ptr[i]);
				printf("Enter element to search: ");
				scanf("%d", &target);
				Linear_Sentinel_Search(ptr, n, target);
				break;
			case 2:
				printf("\n1.Int array\n2.String array\n");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1:
						printf("\nEnter n: ");
						scanf("%d", &n);
						ptr = (int *)malloc(n*sizeof(int));
						for(i=0; i<n; i++)
							scanf("%d", &ptr[i]);
						sort(ptr, n);
						printf("Enter element to search: ");
						scanf("%d", &target);
						a = int_binary_search(ptr, n, target);
						if(a==-1)
							printf("%d not found", target);
						break;
					case 2:
						printf("Enter n: ");
						scanf("%d", &n);
						for(i=0; i<n; i++)
							scanf("%s", arr[i]);
						string_sort(arr, n);
						printf("Enter string to search: ");
						scanf("%s", n1);
						a = string_binary_search(arr, n1, n);
						if(a==-1)
							printf("%s not found\n", n1);
						break;
				}
				break;
		}
	}while(choice!=3);
	return 0;
}
void Linear_Sentinel_Search(int ptr[], int n, int target)
{
	int last = ptr[n-1], i=0, sentinel_comparisons=1;
	ptr[n-1] = target;
	while(ptr[i]!=target){
		i++;
		sentinel_comparisons++;
	}
	ptr[n-1] = last;
	if((i<n-1) || target==ptr[n-1]){
		printf("\n%d is found at index %d\n", target, i);
		sentinel_comparisons++;	
	}
	else{
		printf("\n%d was not found\n", target);
		sentinel_comparisons++;
	}
	printf("It took %d comparisons in sentinel search\n", sentinel_comparisons);
}
void sort(int arr[], int n)
{
	int i, j, temp;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int int_binary_search(int arr[], int n, int target)
{
	int low=0, high = n-1, index;
	while(low<=high){
		index = (low + high)/2;
		if(target==arr[index]){
			printf("\n%d found at index %d\n", target, index);
			return 1;
		}
		else if(target<arr[index])
			high = index-1;
		else
			low = index + 1;
	}
	return -1;
}
void string_sort(char arr[100][100], int n)
{
	int i, j;
	char temp[100][10];
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], temp);
			}
		}
	}
}
int string_binary_search(char arr[100][100], char target[], int n)
{
	int low = 0, high = n-1, index;
	while(low<=high){
		index = (low + high)/2;
		if(strcmp(target, arr[index])==0){
			printf("%s found at index %d", target, index);
			return 1;
		}
		else if(strcmp(target, arr[index])<0)
			high = index -1;
		else
			low = index + 1;
	}
	return -1;
}
