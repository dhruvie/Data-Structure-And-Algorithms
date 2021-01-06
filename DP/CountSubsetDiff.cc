#include<bits/stdc++.h>
using namespace std;
int CountSubsetDiff(int arr[], int n,int sum)
{
	int DP[n+1][sum+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
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
	return DP[n][sum];
}
int main()
{
	int n;
	cin>>n;
	int arr[n],diff,range=0;
	for(int i=0; i<n; ++i)
	{
		cin>>arr[i];
		range+=arr[i];
	}
	cin>>diff;
	if(range<S || (range+diff)/2)           // if range is less than S we can't achieve diff by diving into two sets.
		cout<<0;							// if range+diff is an odd. we can't achieve diff.
	else
	{
		int sum=(diff+range)/2;
		cout<<CountSubsetDiff(arr,n,sum)<<endl;
	}
}