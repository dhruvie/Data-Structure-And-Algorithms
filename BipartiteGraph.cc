// Given an undirected graph, return whether the graph is bipartite.
#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<int>> &G, vector<bool>&visited, vector<int> &color,int src)
{
	visited[src]=true;
    int n=G[src].size();
    bool flag=false;
    for(int i=0; i<n; ++i)
    {
        int dest=G[src][i];
        if(!visited[dest])
        {
            if(color[src]==1) 
                color[dest]=2;
            else 
                color[dest]=1;
            flag=DFS(G,visited,color,dest);
            if(flag)
                return true;
        }
        else
        {
            if(color[src]==color[dest])
                return true;
        }
    }
    return flag;            
}
bool checkBipartite(vector<vector<int>>& arr, int V) 
{
    vector<bool> visited(V,false);
    vector<int> color(V,0);
    for(int i=0; i<V; ++i)
    {
        if(!visited[i])
        {
            color[i]=1;
            if(DFS(arr,visited,color,i))
                return false;
        }
    }
    return true;
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
	if(checkBipartite(G,V))
		cout<<"Graph is Bipartite\n";
	else
		cout<<"Graph is Not Bipartite\n";
	return 0;
}