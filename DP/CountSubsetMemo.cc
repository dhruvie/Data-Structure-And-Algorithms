#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int CountSubset(int arr[], int n, int target)
{
	if(target==0)
		return 1;
	else if(n==0)
		return 0;
	if(DP[n-1][target]!=-1)
		return DP[n-1][target];
	if(arr[n-1]>target)
		return DP[n-1][target]=CountSubset(arr,n-1,target);
	return DP[n-1][target]=CountSubset(arr,n-1,target-arr[n-1]) + CountSubset(arr,n-1,target);
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
	memset(DP,-1,sizeof(DP));
	cout<<CountSubset(arr,n,target);
}