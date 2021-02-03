#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int matrix[100][100], r, c, i, j, zero_count, flag=0, sparse[50][50], m, choice;
	while(flag==0)
	{
		printf("No. of rows and columns: ");
		scanf("%d%d", &r, &c);
		printf("Enter elements...\n");
		for(i=0; i<r; i++){
			for(j=0; j<c; j++)
				scanf("%d", &matrix[i][j]);
		}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(matrix[i][j]==0)
					zero_count++;
			}
		}
		if((float)(zero_count)/(r*c)*100 > 50){
			printf("It is a sparse matrix\n");
			break;
		}
		else{
			printf("It is a dense matrix\n");
			flag = 0;
		}
	}
	printf("\nGiven Matrix...\n");
	for(i=0; i<r; i++){
		for(j=0; j<c; j++)
			printf("%d  ", matrix[i][j]);
		printf("\n");
	}
	m=0;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(matrix[i][j]!=0){
				sparse[0][m] = i;
				sparse[1][m] = j;
				sparse[2][m] = matrix[i][j];
				m++;
			}
		}
	}
	do{
		printf("\n1.Display sparse matrix\n2.Search element in sparse matrix\n3.Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nDisplaying sparse matrix...\n\n");
				for(i=0; i<3; i++){
					for(j=0; j<(r*c)-zero_count; j++)
						printf("%d  ", sparse[i][j]);
					printf("\n");
				}
				break;
			case 2:
				printf("\nEnter element: ");
				scanf("%d", &m);
				for(j=0; j<(r*c)-zero_count; j++){
					if(sparse[2][j]==m){
						printf("Row:    %d\n", sparse[0][j]+1);
						printf("Column: %d\n", sparse[1][j]+1);
						printf("Value:  %d\n", sparse[2][j]);
						flag = 1;
						break;
					}
				}
				if(flag==0)
					printf("Element not found\n");
				break;
		}
	}while(choice!=3);
}
