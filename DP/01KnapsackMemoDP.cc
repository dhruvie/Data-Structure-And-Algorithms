#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int Knapsack(int val[],int wt[], int n, int w)
{
	if(n==0 || w==0)
		return DP[n][w]=0;
	if(DP[n][w]!=-1)
		return DP[n][w];
	if(w<wt[n-1])
		return DP[n][w]=Knapsack(val,wt,n-1,w);
	return max(val[n-1]+Knapsack(val,wt,n-1,w-wt[n-1]),Knapsack(val,wt,n-1,w));
}
int main()
{
	int n,w;
	cin>>n;
	int val[n],wt[n];
	for(int i=0; i<n; ++i)
		cin>>val[i];
	for(int i=0; i<n; ++i)
		cin>>wt[i];
	cin>>w;
	memset(DP,-1,sizeof(DP));
	cout<<Knapsack(val,wt,n,w)<<endl;
}