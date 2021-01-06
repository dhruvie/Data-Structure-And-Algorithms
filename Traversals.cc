#include<bits/stdc++.h>
using namespace std;
void InorderRec(vector<vector<int>> &Tree, int parent)
{
	int X=Tree[parent].size();
	if(X==0)
	{
		cout<<parent<<" ";
		return;
	}
	InorderRec(Tree,Tree[parent][0]);
	cout<<parent<<" ";
	if(X>1)
		InorderRec(Tree,Tree[parent][1]);
}
void PreOrderRec(vector<vector<int>>& Tree, int parent)
{
	int X=Tree[parent].size();
	if(X==0)
	{
		cout<<parent<<" ";
		return ;
	}
	cout<<parent<<" ";
	PreOrderRec(Tree,Tree[parent][0]);
	if(X>1)
		PreOrderRec(Tree,Tree[parent][1]);
}
void PostOrderRec(vector<vector<int>>& Tree, int parent)
{
	int X=Tree[parent].size();
	if(X==0)
	{
		cout<<parent<<" ";
		return ;
	}
	PostOrderRec(Tree,Tree[parent][0]);
	if(X>1)
		PostOrderRec(Tree,Tree[parent][1]);
	cout<<parent<<" ";
}
int Height(vector<vector<int>>& Tree, int parent)
{
	int X=Tree[parent].size(),l=0,r=0;
	if(X==0)
		return 1;
	l=Height(Tree,Tree[parent][0]);
	if(X>1)
		r=Height(Tree,Tree[parent][1]);
	return 1+max(l,r);
}
int Diameter(vector<vector<int>>& Tree, int parent,int &ans)
{
	int X=Tree[parent].size(),l=0,r=0;
	if(X==0)
		return 1;
	l=Diameter(Tree,Tree[parent][0],ans);
	if(X>1)
		r=Diameter(Tree,Tree[parent][1],ans);
	ans=max(l+r+1,ans);
	return 1+max(l,r);
}
int main()
{
	int N,a,b;
	cout<<"Enter the Number Of Nodes:";
	cin>>N;
	vector<vector<int>> Tree(N);
	for(int i=0; i<N-1; ++i)
	{
		cin>>a>>b;
		Tree[a].push_back(b);
	}
	cout<<"\n***************************************\n";
	if(!Tree.empty())
	{
		cout<<"\nRecursive InOrder:-\n";
		InorderRec(Tree,0);
		cout<<"\nRecursive PreOrder:-\n";
		PreOrderRec(Tree,0);
		cout<<"\nRecursive PostOrder:-\n";
		PostOrderRec(Tree,0);
		cout<<"\nHeight of a Tree:"<<Height(Tree,0);
		int ans=0;
		cout<<"\nDiameter of a Tree:";
		Diameter(Tree,0,ans);
		cout<<ans-1;
		cout<<"\nIterative InOrder:-\n";
		InOrderIt(Tree,0);
	}
}