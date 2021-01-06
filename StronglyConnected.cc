#include<bits/stdc++.h>
using namespace std;
void DFS(int src, vector<int> &disc, vector<int> &low, vector<vector<int>> &G, vector<bool>&Instack, stack<int>&myStack)
{
	static int timer=0;
	low[src]=timer;
	disc[src]=timer;
	Instack[src]=true;
	myStack.push(src);
	timer++;
	int n=G[src].size();
	for(int i=0; i<n; ++i)
	{
		int d=G[src][i];
		if(disc[d]==-1)
		{
			DFS(d,disc,low,G,Instack,myStack);

			low[src]=min(low[src],low[d]);
		}
		else if(Instack[d]) //Backedge
			low[src]=min(low[src],disc[d]);
	}
	if(low[src]==disc[src])
	{
		cout<<"SCC is:-\n";
		while(myStack.top()!=src)
		{
			cout<<myStack.top()<<" ";
			Instack[myStack.top()]=false;
			myStack.pop();
		}
		cout<<myStack.top()<<"\n";
		Instack[myStack.top()]=false;
		myStack.pop();

	}
	
}
void TarjanAlgorithm(vector<vector<int>> &G, int V)
{
	vector<int> disc(V,-1),low(V,-1);
	// disc :- discovery time
	// low :- lowest discovery time accessible
	stack<int> myStack;
	vector<bool> Instack(V,false);
	for(int i=0; i<V; ++i)
	{
		if(disc[i]==-1)
			DFS(i,disc,low,G,Instack,myStack);
	}
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
	}
	TarjanAlgorithm(G,V);
	return 0;
}