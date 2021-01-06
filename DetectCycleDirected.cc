#include<bits/stdc++.h>
using namespace std;
bool DFS(int src, vector<vector<int>> &G, vector<string> &color)
{
	color[src]="GRAY";
	for(auto it: G[src])
	{
		if(color[it]=="GRAY")
			return true;
		else if(color[it]=="WHITE")
		{
			if(DFS(it,G,color))
				return true;
		}
	}
	color[src]="BLACK";
	return false;
}
bool checkCycle(vector<vector<int>> &G, int V)
{
	vector<string> color(V,"WHITE");
	for(int i=0; i<V; ++i)
	{
		if(color[i]=="WHITE")
		{
			if(DFS(i,G,color))
				return true;
		}
	}
	return false;
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
		// G[d].push_back(s);
	}
	if(checkCycle(G,V))
		cout<<"Cycle is Detected\n";
	else
		cout<<"Cycle is Not Detected\n";
	return 0;
}