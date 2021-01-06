#include<iostream>
#include<stack>
#define C 20
using namespace std;
class node
{
public:
	int data;
	node *down;
	node *next;
	node(int data)
	{
		this->data=data;
		down=NULL;
		next=NULL;
	}
};
void Add(int vertices,node *arr[])
{
	for(int i=0; i<vertices; i++)
	{
		node *p=new node(i);
		arr[i]=p;
	}
}
void Insert(int a,int b,node *arr[])
{
	node *temp=arr[a];
	while(temp->next!=NULL)
		temp=temp->next;
	node *p=new node(b);
	temp->next=p;
	temp=arr[b];
	while(temp->next!=NULL)
		temp=temp->next;
	p=new node(a);
	temp->next=p;
}
void DFS(int start, node *arr[])
{
	int check[C]={};
	stack <int> s;
	node *temp=arr[start];
	s.push(temp->data);
	while(!s.empty())
	{
		int flag=1;
		if(check[s.top()]==0)
		{
			cout<<s.top();
			check[s.top()]=1;
		}
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(check[temp->data]==0)
			{
				s.push(temp->data);
				flag=0;
				break;
			}
		}
		if(flag==1)
			s.pop();
		if(!s.empty())
			temp=arr[s.top()];
	}
}
int main(int argc, char const *argv[])
{
	node *head=NULL;
	int vertices,edges,a,b;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	node *arr[vertices];
	Add(vertices,arr);
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	for(int i=0; i<edges; i++)
	{
		cin>>a>>b;		
		Insert(a,b,arr);
	}
	DFS(0,arr);
	cout<<endl;
	DFS(2,arr);
	cout<<endl;
	return 0;
}