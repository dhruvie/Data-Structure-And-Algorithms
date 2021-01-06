#include<iostream>
#include<queue>
#define C 10
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
void BFS(int start,node *a[])
{
	int check[C]={};
	node *temp=a[start];
	queue <int> q;
	q.push(temp->data);
	check[temp->data]=1;
	while(!q.empty())
	{
		while(temp->next!=NULL)
		{	
			temp=temp->next;
			if(check[temp->data]==0)
			{
				q.push(temp->data);
				check[temp->data]=1;
			}
		}
		cout<<q.front()<<"->";
		q.pop();
		temp=a[q.front()];
	}
}
/*void Add(node **head,int vertices)        // // This Function is for Adjencency List Without the help of an Array.
{
	if((*head)==NULL)
	{
		node *p=new node(0);
		(*head)=p;	
	}
	node *temp=(*head);
	for(int i=1; i<vertices; i++)
	{
		node *p=new node(i);
		temp->down=p;
		temp=p;
	}
}*/
 /* void Insert(node **head,int a,int b)       // This Function is for Adjencency List Without the help of an Array.
{
	// Undirected Graph
	{
		node *temp=(*head);
		while(temp->data!=a)
			temp=temp->down;
		while(temp->next!=NULL)
			temp=temp->next;
		node *p=new node(b);
		temp->next=p;
		node *ptr=(*head);
		while(p->data!=ptr->data)
			ptr=ptr->down;
		p->down=ptr;
	}
	{
		node *temp=(*head);
		while(temp->data!=b)
			temp=temp->down;
		while(temp->next!=NULL)
			temp=temp->next;
		node *p=new node(a);
		temp->next=p;
		node *ptr=(*head);
		while(p->data!=ptr->data)
			ptr=ptr->down;
		p->down=ptr;	
	}
}*/
/*void BFS(node *head,int start)
{
	int check[C]={};
	node *temp=head;
	while(temp->data!=start)
		temp=temp->down;
	queue <node *> q;
	q.push(temp);
	check[temp->data]=1;
	while(!q.empty())
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(check[temp->data]==0)
			{
				q.push(temp);
				check[temp->data]=1;
			}
		}
		node *p=q.front();
		cout<<p->data<<"->";
		q.pop();
		if(!q.empty())
		{
			temp=q.front();
			temp=temp->down;
		}
	}
}*/
int main(int argc, char const *argv[])
{
	node *head=NULL;
	int vertices,edges,a,b;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	node *arr[vertices];
	// Add(&head,vertices);
	Add(vertices,arr);
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	for(int i=0; i<edges; i++)
	{
		cin>>a>>b;		
		Insert(a,b,arr);
		// Insert(&head,a,b);
	}
	BFS(7,arr);
	// BFS(head,7);
	cout<<endl;
	// BFS(head,2);
	BFS(0,arr);
	cout<<endl;
	return 0;
}