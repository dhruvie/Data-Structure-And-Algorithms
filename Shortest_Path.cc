#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Graph
{
public:
	int data;
	Graph *next;
	Graph(int data)
	{
		this->data=data;
		next=NULL;
	}
};
void MakeUndirectedGraph(int s, int d, Graph * source[])
{
	Graph *p = new Graph(d);
	p->next=source[s];
	source[s]=p;

	p= new Graph(s);
	p->next=source[d];
	source[d]=p;
}
void BFS(int start,bool visited[],Graph * source[],int parent[])
{
	queue <int> q;
	q.push(start);
	visited[start]=1;
	parent[start]=-1;
	cout<<start<<" ";
	while(!q.empty())
	{
		Graph *temp= source[q.front()];
		while(temp!=NULL)
		{
			if(!visited[temp->data])
			{
				visited[temp->data]=1;
				cout<<temp->data<<" ";
				q.push(temp->data);
				parent[temp->data]=q.front();
			}
			temp=temp->next;
		}
		q.pop();
	}
}
void Find(int parent[],int source,int destination)
{
	vector <int> v;
	while(destination!=source || parent[destination]!=-1)
	{
		cout<<destination<<"->"<<parent[destination]<<endl;
		v.push_back(destination);
		destination=parent[destination];
	}
	v.push_back(source);
	int length=v.size();
	for(int i=length-1; i>=0; --i)
		cout<<v[i]<<"->";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	Graph *head=NULL;
	int vertices,edges,s,d;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	Graph * source[vertices];
	int parent[vertices]={};
	for(int i=0; i<vertices; ++i)
	{
		source[i]=NULL;
		parent[i]=i;
	}
	bool visited[vertices]={};
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	for(int i=0; i<edges; ++i)
	{
		cin>>s>>d;
		MakeUndirectedGraph(s,d,source);
	}
	cout<<"Enter Source and Destination\n";
	cin>>s>>d;
	BFS(s,visited,source,parent);
	Find(parent,s,d);
	return 0;
}