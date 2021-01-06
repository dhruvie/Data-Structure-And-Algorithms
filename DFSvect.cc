#include<iostream>
#include<vector>
using namespace std;
void DFS(int start, vector<vector<int>>g,vector<bool> &visited)
{
	visited[start]=true;
	cout<<start<<" ";
	int n=g[start].size();
	for(int i=0; i<n; ++i)
	{
		int d=g[start][i];
		if(!visited[d])
			DFS(d,g,visited);
	}
}
int main()
{
	int V,E,s,d;
	cout<<"Enter the no. of vertices:\n";
	cin>>V;
	cout<<"Enter the no. of edges:\n";
	cin>>E;
	vector<vector<int> >g(V);
	vector<bool> visited(V,false);
    for(int i=0;i<E;i++)
    {
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    for(int i=0; i<V; ++i)
    {
    	if(!visited[i])
    		DFS(i,g,visited);
    }
}