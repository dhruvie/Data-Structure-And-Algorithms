#include<bits/stdc++.h>
using namespace std;
int Knapsack(int val[],int wt[], int n, int w)
{
	int DP[n+1][w+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=w; ++j)
		{
			if(i==0 || j==0)
			{
				DP[i][j]=0;
				continue;
			}
			else if(j<wt[i-1])
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]=max(val[i-1]+DP[i-1][j-wt[i-1]],DP[i-1][j]);
		}
	}
	return DP[n][w];
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
	cout<<Knapsack(val,wt,n,w)<<endl;
}