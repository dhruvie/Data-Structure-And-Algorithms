#include<bits/stdc++.h>
using namespace std;
void DFS(int src, vector<int> &disc, vector<int> &low, vector<int>&parent, vector<vector<int>> &G, vector<pair<int,int>> &bridge)
{
	static int timer=0;
	low[src]=timer;
	disc[src]=timer;
	timer++;
	int n=G[src].size();
	for(int i=0; i<n; ++i)
	{
		int d=G[src][i];
		if(disc[d]==-1)
		{
			parent[d]=src;
			DFS(d,disc,low,parent,G,bridge);

			low[src]=min(low[src],low[d]);

			if(low[d]>disc[src])  // Therefore, there is no backedge, and this edge will be a bridge.
				bridge.push_back({src,d});
		}
		else if(d!=parent[src]) // Ignore parent to child edge && if there is a backedge update low array value.
			low[src]=min(low[src],disc[d]);
	}
}
void TarjanAlgorithm(vector<vector<int>> &G, int V)
{
	vector<int> disc(V,-1),low(V,-1),parent(V,-1);
	// disc :- discovery time
	// low :- lowest discovery time accessible


	vector<pair<int,int>> bridge;
	for(int i=0; i<V; ++i)
	{
		if(disc[i]==-1)
			DFS(i,disc,low,parent,G,bridge);
	}

	int l=bridge.size();
	cout<<"Bridges Are:-";
	for(int i=0; i<l; ++i)
		cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
}
int main(int argc, char const *argv[])
{
	int V,E,s,d;
	cout<<"Enter Vertices and Edges:\n";
	cin>>V>>E;
	vector<vector<int>> G(V);
	for(int i=0; i<E; ++i)
	{
		cin>>s>>d;
		G[s].push_back(d);
		G[d].push_back(s);
	}
	TarjanAlgorithm(G,V);
	return 0;
}