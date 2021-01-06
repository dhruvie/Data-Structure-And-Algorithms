#include<iostream>
#include<queue>
#define C 10
using namespace std;
void BFS(int vertices,int arr[C][C])
{
	queue <int> q;
	int check[vertices]={};
	q.push(0);
	while(!q.empty())
	{
		int i=q.front();
		for (int j = 0; j < vertices; ++j)
		{
			if(arr[i][j]==1)
			{
				if(check[j]==0)
					q.push(j);
				// arr[i][j]=0;
				// arr[j][i]=0;
			}
		}
		if(check[i]==0)
		{
			cout<<i;
			check[i]=1;
		}
		q.pop();
	}
}
int main(int argc, char const *argv[])
{
	int vertices,edges,a,b,arr[C][C]={};
	cout<<"Enter the no. of vertices:\n";
	cin>>vertices;
	cout<<"Enter the no. of edges:\n";
	cin>>edges;
	for(int i=0; i<edges; i++)
	{
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	BFS(vertices,arr);
	cout<<endl;
	BFS(vertices,arr);
	cout<<endl;
	return 0;
}