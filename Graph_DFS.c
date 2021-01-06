#include<stdio.h>
#include<stdlib.h>
int visited[20]={};
typedef struct Graphtype
{
	int data;
	struct Graph *next;	
}Graph;
void Insert(int a,int b,Graph *source[])
{
	Graph *p=(Graph *)malloc(sizeof(Graph));
	p->data=b;
	p->next=source[a];
	source[a]=p;
	return;
}
void DFS(int x, Graph *source[])
{
	Graph *temp = source[x];
	if(!visited[x])
	{
		visited[x]=1;
		printf("%d\n",x);
		if(temp!=NULL)
		{
			DFS(temp->data,source);
			temp=temp->next;
		}
		if(temp==NULL)
			return;
	}

}
int main(int argc, char const *argv[])
{
	Graph *head=NULL;
	int vertices,edges,a,b;
	printf("Enter the no. of vertices:\n");
	scanf("%d",&vertices);
	Graph *source[vertices];
	for(int i=0; i<vertices; ++i)
		source[i]=NULL;
	printf("Enter the no. of edges:\n");
	scanf("%d",&edges);
	for(int i=0; i<edges; i++)
	{
		scanf("%d %d",&a,&b);		
		Insert(a,b,source);
	}	
	for(int i=0; i<vertices; ++i)
		DFS(i,source);
	return 0;
}