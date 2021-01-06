#include<bits/stdc++.h>
using namespace std;
int MinSubSumDiff(int arr[], int n,int sum,int range)
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
				DP[i][j]=DP[i-1][j-arr[i-1]] || DP[i-1][j];
		}
	}
	int min=INT_MAX;
	for(int i=0; i<=sum; ++i)
	{
		if(DP[n][i]==true)
		{
			if((range-(i*2))<min)
				min=(range-(i*2));
		}
	}
	return min;
}
int main()
{
	int n;
	cin>>n;
	int arr[n],range=0;
	for(int i=0; i<n; ++i)
	{
		cin>>arr[i];
		range+=arr[i];
	}
	cout<<MinSubSumDiff(arr,n,range/2,range)<<endl;
}