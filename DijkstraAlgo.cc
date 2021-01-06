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
bool comp(pair <int, int> a, pair <int, int> b)
{
	return a.second>b.second; 
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
void DFS(Graph *temp,vector <pair<int,int> > &Heap,int parent[], unordered_map <int, int> &distance)
{
	while(temp!=NULL)
	{
		int i=0,n=Heap.size();
		for(i=0; i<n; ++i) 												// This loop is increasing Complexity.
		{
			if(Heap[i].first==temp->destination)
				break;
		}
		if(i!=n)
		{
			if(Heap[i].second>(temp->weight + distance[temp->source]))
			{
				Heap[i].second=temp->weight+distance[temp->source];
				parent[temp->destination]=temp->source;
				make_heap(Heap.begin(),Heap.end(),comp);
			}
		}
		temp=temp->next;
	}
}
void Dijkstra(vector < pair <int, int> > &Heap, unordered_map <int,int> &distance,Graph *Make_Graph[],int parent[], int s, int d)
{
	make_heap(Heap.begin(),Heap.end(),comp);
	while(!Heap.empty())
	{
		int currentMin=Heap.front().first;
		distance[currentMin]=Heap.front().second;
		pop_heap(Heap.begin(),Heap.end());
		Heap.pop_back();
		Graph * temp=Make_Graph[currentMin];
		DFS(temp,Heap,parent,distance);
		/*cout<<"Heap:\n";
		for(int i=0; i<Heap.size(); ++i)
		{
		 	cout<<Heap[i].first<<" "<<Heap[i].second<<endl;
		}
		*/
	}
}
void MakeUndirectedGraph(int s, int d, int w,Graph * Make_Graph[])
{
	Graph *p = new Graph(s,d,w);
	p->next=Make_Graph[s];
	Make_Graph[s]=p;

	p= new Graph(d,s,w);
	p->next=Make_Graph[d];
	Make_Graph[d]=p;
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
	vector < pair <int, int> > Heap(vertices);
	unordered_map < int, int>  distance;
	for(int i=0; i<vertices; ++i)
	{
		Make_Graph[i]=NULL;
		parent[i]=i;
		Heap[i].first=i;
		Heap[i].second=INT_MAX;
	}
	// memset(Make_Graph,0,sizeof(Make_Graph));
	for(int i=0; i<edges; ++i)
	{
		cin>>s>>d>>weight;	
		MakeUndirectedGraph(s,d,weight,Make_Graph);		
	}
	cout<<"Enter Source and Destination\n";
	cin>>s>>d;
	Heap[s].second=0;
	parent[s]=-1;
	Dijkstra(Heap,distance,Make_Graph,parent,s,d);
	Find(parent,s,d);
	cout<<"Minimum Distance is:"<<distance[d]<<endl;
}