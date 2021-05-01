#include <stdio.h>
#include <stdlib.h>


#define max 100

int Queue[max];
int n=0,m=0;
int visited[max];
int front = -1;
int rear = -1;
int adjmat[max][max];

typedef struct edge{
    int s,d;
} Edge;

Edge edges[max];

void adjacencymatrix(Edge e[],int t);
void bfs(int v);
void dfs(int v);
void edges_create();
int maxvertex(int m,int n);
int checkvertex(int v);
void menu();

int main(){
    int vertex, i,j,k,choice, graph, maxv,demo;
    char type = 'd';

    while(1){
        menu();
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                
                printf("Directded or Undirected (d/u) : ");
                fflush(stdin);
                scanf("%c",&type);
                if(type=='d'){
                    graph = 1;

                }
                else{
                    graph = 2;
                }
                
                n = 0;
                m = 0;
                edges_create();
                maxv = 0;
                
                for(j=0;j<m;j++){
                	demo = maxvertex(edges[j].s,edges[j].d);
 
                	if(demo>maxv){
                		maxv = demo;
					}
				
				}
				n = maxv+1;
				printf("N : %d\n",n);
                for(i=0;i<n;i++){
                    visited[i] = 0;
                }
                printf("Enter 1st vertex : ");
                scanf("%d",&vertex);
                while(!checkvertex(vertex)){
                	printf("Enter 1st vertex again : ");
                    scanf("%d",&vertex);
				}
				
                
                front  = rear = 0;
                Queue[rear] = vertex;
                visited[vertex] = 1;
                
                printf("\n");
                
                adjacencymatrix(edges,graph);
                printf("BFS : %d ",vertex);
                
                bfs(vertex);
                for(i=0;i<n;i++){
                    visited[i] = 0;
                }
                visited[vertex] = 1;
                printf("DFS : %d ",vertex);
                dfs(vertex);
            
                break;
            }

            case 2:{
                
                exit(0);
            }
            
            default :{
                printf("Invalid choice\n");
            }

        }
    }

}

void menu(){
    printf("\n");
    printf("\n1. Create Graph\n");
    printf("3. Exit\n");
}

void edges_create(){
    int i=0;
    char yn = 'y';

    while(yn=='y'){
                        
        printf("Enter Source  of edge (0-99): ");
        scanf("%d",&edges[i].s);
        while(edges[i].s>99 || edges[i].s<0){
           printf("Enter Source  of edge Again : ");
           scanf("%d",&edges[i].s);       	
		}
        printf("Enter destination of edge (0-99) : ");
        scanf("%d",&edges[i].d);
        while(edges[i].d>99 || edges[i].d<0 || edges[i].s==edges[i].d){
           printf("Enter destination  of edge Again : ");
           scanf("%d",&edges[i].d);       	
		}

        printf("\n");
        printf("Do you want to add more edges? (y/n) ");
        fflush(stdin);
        scanf("%c",&yn);
        i++;
        m++;

    }

}

void adjacencymatrix(Edge edges[],int t){
    int i,j,x,y;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adjmat[i][j] = 0;
        }
    }

    for(i=0;i<m;i++){
        x = edges[i].s;
        y = edges[i].d;

        adjmat[x][y] = 1;
        if(t==2){
            adjmat[y][x] = 1;
        }
    }

    printf("Adjacency Matrix\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",adjmat[i][j]);
        }
        printf("\n");
    }

}

void bfs(int data){
    int i;
    for(i=0;i<n;i++){
        if(adjmat[data][i]!=0 && visited[i]==0){
            rear++;
            Queue[rear] = i;
            visited[i] = 1;
            printf("%d ",i);
        }
    }
    front++;
    if(front<=rear){
        bfs(Queue[front]);
    }
}

void dfs(int data){
	int j;
	for(j=0;j<n;j++){
		if(adjmat[data][j]!=0 && visited[j]==0){
			visited[j]=1;
			printf("%d ",j);
			dfs(j);
		}
	}
}

int maxvertex(int n,int m){
	if (n>m){
		return n;
	}
		
	else{
		return m;
	}
}

int checkvertex(int v){
	int i=0,flag = 0;
	while(edges[i].d!='\0'){
		if(v==edges[i].s || v==edges[i].d){
			flag = 1;
			return flag;
		}
		i++;
	}
	return flag;
}

