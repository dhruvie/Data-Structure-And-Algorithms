#include<iostream>
using namespace std;
class Graph
{
public:
	int source;
	int destination;
	int weight;
	Graph *next;
	Graph(int source,int destination,int weight)
	{
		this->source=source;
		this->destination=destination;
		this->weight=weight;
		next=NULL;
	}
};
int Find(int a,int b, int checkCycle[])
{
	int x=a;
	while(checkCycle[x]!=x)
		x=checkCycle[x];
	int y=b;
	while(checkCycle[y]!=y)
		y=checkCycle[y];
	if(x!=y)
	{
		checkCycle[x]=y;
		return 1;
	}
	return 0;
}
// void Make_UndirectedGraph(int a,int b, int weight, int source[])
// {
// 	Graph *p=new Graph(b,weight);
// 	p->next=source[a];
// 	source[a]=p;
	
// 	Graph *p=new Graph(a,weight);
// 	p->next=source[b];
// 	source[b]=p;

// }
void Union(int v1,int v2, int weight,int &minWeight,int checkCycle[])
{
	cout<<v1<<"--->"<<v2<<endl;
	minWeight+=weight;
}

void Priority(int s,int d,int weight,Graph **head)
{
	if((*head)==NULL || (*head)->weight>=weight)
	{
		Graph *p = new Graph(s,d,weight);
		p->next=(*head);
		(*head)=p;
		return;
	}else
	{
		Graph *temp=(*head)->next,*tail=(*head);
		Graph *p =new Graph(s,d,weight);
		while(temp!=NULL)
		{
			if(temp->weight>=weight)
				break;
			tail=temp;
			temp=temp->next;
		}
		p->next=tail->next;
		tail->next=p;
		return;
	}
}
int main(int argc, char const *argv[])
{
	Graph *head=NULL;
	int vertices,edges,s,d,weight,minWeight=0;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	int checkCycle[vertices]={};
	for(int i=0; i<vertices; ++i)
		checkCycle[i]=i;
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	for(int i=0; i<edges; ++i)
	{
		cin>>s>>d>>weight;		
		Priority(s,d,weight,&head);
	}	
	Graph *temp=head;
	for(int i=0; i<=(vertices-1); )
	{
		if(temp==NULL)
			break;
		int result=Find(temp->source,temp->destination,checkCycle);
		if(result==1)
		{
			Union(temp->source,temp->destination,temp->weight,minWeight,checkCycle);
			++i;
		}
		temp=temp->next;
	}
	cout<<"Min. Weight  is "<<minWeight<<endl;
	return 0;
}