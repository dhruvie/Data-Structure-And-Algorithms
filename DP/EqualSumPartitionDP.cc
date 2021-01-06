#include<bits/stdc++.h>
using namespace std;
bool EqualSum(int arr[], int n, int sum)
{
	bool DP[n+1][sum+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			if(j==0)
			{
				DP[i][j]=true;
				continue;
			}
			else if(i==0)
			{
				DP[i][j]=false;
				continue;
			}
			else if(j<arr[i-1])
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]=DP[i-1][j-arr[i-1]] | DP[i-1][j];
		}
	}
	return DP[n][sum];
}
int main()
{
	int n,sum=0;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum&1)
		cout<<"No\n";
	else
	{
		if(EqualSum(arr,n,sum/2))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}