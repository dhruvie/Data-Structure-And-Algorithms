#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(int start,vector<vector<int>>g)
{
	vector<bool> visited(g.size(),false);
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		int src=q.front();
		cout<<src<<" ";
		int n=g[src].size();
		for(int i=0; i<n; ++i)
		{
			int d=g[src][i];
			if(!visited[d])
			{
				visited[d]=true;
				q.push(d);
			}
		}
		q.pop();
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
    BFS(0,g);
}