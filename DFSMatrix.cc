#include<iostream>
#include<stack>
#define C 10
using namespace std;
void DFS(int vertices,int arr[C][C])
{
	stack <int> s;
	int check[vertices]={};
	s.push(0);
	while(!s.empty())
	{
		int i=s.top(),flag=1;
		if(check[i]==0)
		{
			cout<<i;
			check[i]=1;
		}
		for (int j = 0; j < vertices; ++j)
		{
			if(arr[i][j]==1)
			{
				if(check[j]==0)
				{
					s.push(j);
					flag=0;
					break;
				}	
			}
		}
		if(flag==1)
			s.pop();
	}
}
int main(int argc, char const *argv[])
{
	int vertices,edges,a,b,arr[C][C]={};;
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
	DFS(vertices,arr);
	cout<<endl;
	DFS(vertices,arr);
	cout<<endl;
	return 0;
}