#include<bits/stdc++.h>
using namespace std;
void Find(vector<int> &parentarr, int s, int d)
{
	if(d==-1)
		return ;
	Find(parentarr,s,parentarr[d]);
	cout<<d<<"->>";
	return;
}
void Dijkstra(vector<vector<pair<int,int>>> &G, int s, int d, vector<int> &parentarr, int vertices)
{
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq; // cost,source
	// Parent arr is only needed when we have to print the path from source to destination
	// queue<pair<int,int>> pq; // using BFS
	pq.push({0,s});
	vector<int> distance(vertices,INT_MAX);
	distance[s]=0;
	parentarr[s]=-1;
	while(!pq.empty())
	{
		int cost=pq.top().first;
		int source=pq.top().second;
		pq.pop();
		for(auto itr: G[source])
		{
			if(distance[itr.first]>(cost+itr.second))
			{
				pq.push({cost+itr.second,itr.first});
				distance[itr.first]=cost+itr.second;
				parentarr[itr.first]=source;
			}
		}
	}
	cout<<"Minimum Cost from source to Destination is:"<<distance[d]<<endl;
	cout<<"Distance From source to All Nodes\n";
	cout<<"Vertices:\t\t\t"<<"Distance\n";
	for(int i=0; i<vertices; ++i)
	{
		cout<<i<<"\t\t\t\t"<<distance[i]<<endl;
	}
}
int main()
{
	int vertices,edges,s,d,weight,minWeight=0;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	vector<vector <pair<int,int>>> G(vertices);
	vector<int> parentarr(vertices,-1); // Is used when we have to print the path from source to destination
	for(int i=0; i<edges; ++i)
	{
		cin>>s>>d>>weight;
		G[s].push_back({d,weight});
		G[d].push_back({s,weight});
	}
	cout<<"Enter Source and Destination\n";
	cin>>s>>d;
	Dijkstra(G,s,d,parentarr,vertices);
	Find(parentarr,s,d);
	cout<<endl;
}