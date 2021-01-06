#include<bits/stdc++.h>
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
void MakeUndirectedGraph(int s, int d, int w,Graph * Make_Graph[])
{
	Graph *p = new Graph(s,d,w);
	p->next=Make_Graph[s];
	Make_Graph[s]=p;

	p= new Graph(d,s,w);
	p->next=Make_Graph[d];
	Make_Graph[d]=p;
}
void Find(int parent[],int source,int destination)
{
	vector <int> v;
	while(destination!=source || parent[destination]!=-1)
	{
		// cout<<destination<<"->"<<parent[destination]<<endl;
		v.push_back(destination);
		destination=parent[destination];
	}
	v.push_back(source);
	int length=v.size();
	for(int i=length-1; i>=0; --i)
		cout<<v[i]<<"->";
	cout<<endl;
}
void Dijkstra(Graph *Make_Graph[],int s, int d,int parent[],int vertices)
{
	vector <int> distance(vertices,-1);
	priority_queue< int, vector < pair<pair<int, int>,int> > ,greater <void> > pq;
	pq.push({{0,s},-1});
	while(!pq.empty())
	{
		int currentMin=pq.top().first.second;
		int currentMinW=pq.top().first.first;
		int currentParent=pq.top().second;
		pq.pop();
		Graph *temp = Make_Graph[currentMin];
		if(distance[currentMin]!=-1) continue;
		distance[currentMin]=currentMinW;
		parent[currentMin]=currentParent;
		while(temp!=NULL)
		{
			int w1=temp->weight;
			int d1=temp->destination;
			if(distance[d1]==-1)
				pq.push({{w1+distance[currentMin],d1},currentMin});
			temp=temp->next;
		}
	}
	cout<<"Minimum Distance is:"<<distance[d]<<endl;
}
int main()
{
	int vertices,edges,s,d,weight,minWeight=0;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	Graph *Make_Graph[vertices];
	int parent[vertices]={};
	for(int i=0; i<vertices; ++i)
	{
		Make_Graph[i]=NULL;
		parent[i]=i;
	}
	for(int i=0; i<edges; ++i)
	{
		cin>>s>>d>>weight;	
		MakeUndirectedGraph(s,d,weight,Make_Graph);		
	}
	cout<<"Enter Source and Destination\n";
	cin>>s>>d;
	Dijkstra(Make_Graph,s,d,parent,vertices);
	Find(parent,s,d);
}