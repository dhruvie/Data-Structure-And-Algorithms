// Unbounded Knapsack
// Coin Change:- Minimum Count of Subset sum which is equal to given sum.
#include<bits/stdc++.h>
using namespace std;
int MinSubset(int arr[],int n, int sum)
{
	int DP[n+1][sum+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			if(i==0)
			{
				DP[i][j]=INT_MAX-1;
				continue;
			}
			else if(j==0)
				DP[i][j]=0;
			else if(j<arr[i-1])
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]=min(1+DP[i][j-arr[i-1]],DP[i-1][j]);
		}
	}
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return DP[n][sum];
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	int sum;
	cin>>sum;
	cout<<MinSubset(arr,n,sum);
}