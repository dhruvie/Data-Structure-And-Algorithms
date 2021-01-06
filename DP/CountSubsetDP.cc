#include<bits/stdc++.h>
using namespace std;
int CountSubset(int arr[], int n, int target)
{
	int DP[n+1][target+1]={};
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=target; ++j)
		{
			if(j==0)
			{
				DP[i][j]=1;
				continue;
			}
			else if(i==0)
			{
				DP[i][j]=0;
				continue;
			}
			else if(j<arr[i-1])
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]=DP[i-1][j-arr[i-1]] + DP[i-1][j];
		}
	}
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=target; ++j)
		{
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}
	return DP[n][target];
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	int target;
	cin>>target;
	cout<<CountSubset(arr,n,target);
}