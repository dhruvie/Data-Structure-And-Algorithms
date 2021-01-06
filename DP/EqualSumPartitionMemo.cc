#include<bits/stdc++.h>
using namespace std;
bool DP[100][100];
bool EqualSum(int arr[], int n, int sum)
{
	if(sum==0)
		return DP[n][sum]=true;
	else if(n==0)
		return DP[n][sum]=false;
	if(DP[n][sum]!=-1)
		return DP[n][sum];
	if(sum<arr[n-1])
		return DP[n][sum]=EqualSum(arr,n-1,sum);
	return DP[n][sum]=EqualSum(arr,n-1,sum-arr[n-1]) | EqualSum(arr,n-1,sum);
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
		memset(DP,-1,sizeof(DP));
		if(EqualSum(arr,n,sum/2))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}