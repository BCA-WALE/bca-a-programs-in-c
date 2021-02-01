#include <stdio.h>
#include <stdlib.h>

void int_insert(int *ptr1, int, int);
int validation();
void float_insert(int *ptr1, int, float);
struct point
{
	int x;
	int y;
};
int arr1[] = {10, 20, 30, 45, 21, 65, 36, 89, 74, 90};
float arr2[] = {2.5, 4.9, 10.6, 9.4, 15.6, 23.8, 14.5, 96.1, 42.1, 50.3};
struct point p[] = { {10, 12}, {14, 15}, {20, 8}, {14, 20}, {13, 18} };
int main() {
	int n, choice, choice2, k, i, j, flag=0, l1=10, l2=10, l3=5;
	float n2;
	int *ptr1, *ptr2, *ptr3;
   	do
   	{
   		printf("\n1.Int array\n");
   		printf("2.Float array\n");
   		printf("3.Array of structures\n");
   		printf("4.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\n1.To insert elements at kth position\n");
				printf("2.To insert element after a data item\n");
				printf("3.To insert n elements between two positions\n");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1:
						printf("Given array...\n");
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
						k = validation();
						printf("Enter the element: ");
						scanf("%d", &n);
						int_insert(&l1, k, n);
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
						break;
					case 2:
						printf("Given array...\n");
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
					
						while(flag==0)
						{
							printf("\nEnter data item: ");
							scanf("%d", &n);
							for(i=0; i<l1; i++)
							{
								if(arr1[i]==n)
								{
									k = i+1;
									flag = 1;
									break;
								}
								
							}
							if(flag==0)
								printf("Data item not found\n");
						}
						printf("Enter new elememt: ");
						scanf("%d", &n);
						int_insert(&l1, k, n);
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
						break;
					case 3:
						printf("\nGiven array is...\n");
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
				
						while(flag==0)
						{
							printf("\nEnter two positions: ");
							scanf("%d%d", &k, &j);
							if(k>=1 && j>=1 && k<=11 && j<=11 && k<j)
								break;
							else
							{
								printf("Invalid input\n");
								
							}
						}
						for(i = k; i<j; i++)
						{
							printf("Enter new element: ");
							scanf("%d", &n);
							int_insert(&l1, i, n);
						}
						for(i = 0; i<l1; i++)
							printf("%d ", arr1[i]);
						break;
				}
				break;
			case 2:
				printf("\n1.To insert elements at kth position\n");
				printf("2.To insert element after a data item\n");
				printf("3.To insert n elements between two positions\n");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1:
						printf("\nGiven array is...\n");
						for(i=0; i<l2; i++)
							printf("%.2f  ", arr2[i]);
						k = validation();
						printf("Enter new element: ");
						scanf("%f", &n2);
						float_insert(&l2, k, n2);
						for(i=0; i<l2; i++)
							printf("%.2f  ", arr2[i]);
						break;
					case 2:
						printf("\nGiven array is...\n");
						for(i=0; i<l2; i++)
							printf("%.2f  ", arr2[i]);
						flag = 0;
						while(flag==0)
						{
							printf("\nEnter data item: ");
							scanf("%f", &n2);
							for(i=0; i<l1; i++)
							{
								if(arr2[i]==n2)
								{
									k = i+1;
									flag = 1;
									break;
								}
								else
									flag = 0;
							}
							if(flag==0)
								printf("Data item not found\n");
						}
						printf("Enter new element: ");
						scanf("%f", &n2);
						float_insert(&l2, k, n2);
						for(i=0; i<l2; i++)
							printf("%.2f  ", arr2[i]);
						break;
				    case 3:
				    	printf("\nGiven Array...\n");
				    	for(i=0; i<l2; i++)
				    		printf("%.2f  ", arr2[i]);

				    	while(flag==0)
						{
							printf("\nEnter two positions: ");
							scanf("%d %d", &k, &j);
							if(k>=1 && j>=1 && k<=11 && j<=11 && k<j)
								break;
							else
							{
								printf("Invalid input\n");

							}
						}
						for(i=k; i<j; i++)
						{
							printf("Enter new element: ");
							scanf("%f", &n2);
							float_insert(&l2, i, n2);
						}
						for(i=0; i<l2; i++)
							printf("%.2f  ", arr2[i]);
						break;
				}
				break;
			case 3:
				printf("\nGiven co-ordinates...\n");
				for(i=0; i<l3; i++)
					printf("{%d, %d}  ", p[i].x, p[i].y);
				k = validation();
				printf("Enter coordinates: ");
				scanf("%d%d", &n, &i);
				j = l3;
				l3 = l3+1;
				while(j>=k)
				{
					p[j+1].x = p[j].x;
					p[j+1].y = p[j].y;
					j--;
				}
				p[k].x = n;
				p[k].y = i;
				for(i=0; i<l3; i++)
					printf("{%d, %d}  ", p[i].x, p[i].y);
				break;
		}
	}while(choice!=4);
	return 0;
}
void int_insert(int *ptr1, int position, int item)
{
	int j = *ptr1;
	*ptr1 = *ptr1 + 1;
	while(j>=position )
	{
		arr1[j+1] = arr1[j];
		j--;
	}
	arr1[position] = item;
}
int validation()
{
	int k, flag = 0;

	while(flag==0){
			printf("\nEnter position k: ");
	        scanf("%d", &k);
	        if(k>=0 && k<= 11){
			    return k;
	        }

	        else
	        {
	        	printf("Invalid input\n");
		
	     	}
		
	}

	
}
void float_insert(int *ptr1, int position, float item)
{
	int j = *ptr1;
	*ptr1 = *ptr1 + 1;
	while(j>=position)
	{
		arr2[j+1] = arr2[j];
		j--;
	}
	arr2[position] = item;
}
