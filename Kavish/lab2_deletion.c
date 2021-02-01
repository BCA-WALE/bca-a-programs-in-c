#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct details
{
	char name[100];
	int age;
};
void int_deletion(int *ptr, int, int []);
void float_deletion(int *ptr, int, float[]);
int main() 
{
	int arr1[100], choice1, choice2, i, j, k, l1, l2, l3, n, flag = 0;
	float arr2[100], n1;
	struct details d[10];
	do
	{
		printf("\n1.Int array\n");
		printf("2.Float array\n");
		printf("3.Array of structures\n");
		printf("4.Exit\n");
		scanf("%d", &choice1);
		switch(choice1)
		{
			case 1:
				printf("Enter length of array\n");
				scanf("%d", &l1);
				for(i=0; i<l1; i++)
					scanf("%d", &arr1[i]);
				printf("\n1.Delete element at kth position\n");
				printf("2.Delete all the occurences of the element\n");
				printf("3.Delete odd positioned elements\n");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1:
						flag = 0;
						while(flag==0)
						{
							printf("Enter position: ");
							scanf("%d", &k);
							if(k>=1 && k<=l1)
								break;
							else
							{
								printf("Invalid Input\n");
								flag = 0;
							}
						}
						int_deletion(&l1, k, arr1);
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
						break;
					case 2:
						printf("Enter the data item: ");
						scanf("%d", &n);
						for(j = 0; j<2; j++)
						{
							for(i=0; i<l1; i++)
							{
								if(arr1[i]==n)
									int_deletion(&l1, i, arr1);
						    }
						}
						for(i = 0; i<l1; i++)
							printf("%d ", arr1[i]);
						break;
					case 3:
						for(i=0; i<l1; i++)
						{
							if(i%2!=0)
								arr1[i] = 0;
					    }
					    for(i=0; i<l1; i++)
					    {
					    	if(arr1[i]==0)
					    		int_deletion(&l1, i, arr1);
						}
						for(i=0; i<l1; i++)
							printf("%d ", arr1[i]);
						break;
				}
				break;
			case 2:
				printf("Enter length of array\n");
				scanf("%d", &l2);
				for(i=0; i<l2; i++)
					scanf("%f", &arr2[i]);
				printf("\n1.Delete element at kth position\n");
				printf("2.Delete all the occurences of the element\n");
				printf("3.Delete odd positioned elements\n");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1:
						flag = 0;
						while(flag==0)
						{
							printf("\nEnter position: ");
							scanf("%d", &k);
							if(k>=1 && k<=l2)
								break;
							else
							{
								printf("Invalid input\n");
								flag = 0;
							}
						}
						float_deletion(&l2, k, arr2);
						for(i=0;i<l2;i++)
							printf("%.2f  ", arr2[i]);
						break;
					case 2:
						printf("Enter the data item: ");
						scanf("%f", &n1);
						for(j = 0; j<2; j++)
						{
							for(i=0; i<l2; i++)
							{
								if(arr2[i]==n1)
									float_deletion(&l2, i, arr2);
						    }
						}
						for(i=0; i<l2; i++)
							printf("%.2f  ", arr2[i]);
						break;
					case 3:
						for(i=0; i<l2; i++)
						{
							if(i%2!=0)
								arr2[i] = 0;
					    }
					    for(i=0; i<l2; i++)
					    {
					    	if(arr2[i]==0)
					    		float_deletion(&l2, i, arr2);
						}
						for(i=0; i<l2; i++)
							printf("%.2f ", arr2[i]);
						break;
				}
				break;
			case 3:
				printf("Enter no. of candidates: ");
				scanf("%d", &l3);
				for(i=0; i<l3; i++)
				{
					printf("\nName: ");
					scanf("%s", d[i].name);
					printf("Age: ");
					scanf("%d", &d[i].age);
				}
				printf("\nEnter position: ");
				scanf("%d", &k);
				j = k;
				while(j<l3)
				{
					strcpy(d[j].name, d[j+1].name);
					d[j].age = d[j+1].age;
					j++;
				}
				l3--;
				for(i=0; i<l3; i++)
				{
					printf("\nName: %s\n", d[i].name);
					printf("Age: %d\n", d[i].age);
				}
				break;
		}
	}while(choice1!=4);
	return 0;
}
void int_deletion(int *ptr, int position, int arr[])
{
	int j = position;
	while(j<*ptr)
	{
		arr[j] = arr[j+1];
		j++;
	}
	*ptr = *ptr - 1;
}
void float_deletion(int *ptr, int position, float arr[])
{
	int j = position;
	while(j<*ptr)
	{
		arr[j] = arr[j+1];
		j++;
	}
	*ptr = *ptr - 1;
}
