#include<bits/stdc++.h>
using namespace std;
void DFS(int src, vector<vector<int>> &G, vector<bool> &visited, vector<int> &ans)
{
	visited[src]=true;
	for(auto d: G[src])
	{
		if(!visited[d])
			DFS(d,G,visited,ans);
	}
	ans.push_back(src);
}
int main()
{
	int vertices,edges,s,d;
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	vector<vector<int>> G(vertices);
	for(int i=0; i<edges; ++i)
	{
		cin>>s>>d;
		G[s].push_back(d);
	}
	vector<int> ans;
	vector<bool> visited(vertices,false);
	for(int i=0; i<vertices; ++i)
	{
		if(!visited[i])
			DFS(i,G,visited,ans);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0; i<vertices; ++i)
		cout<<ans[i]<<" ";
	cout<<endl;
}