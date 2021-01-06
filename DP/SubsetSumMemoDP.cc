#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
bool SubsetSum(int arr[], int n, int sum)
{
	if(sum==0)
		return true;
	if(n==0)
		return false;
	if(DP[n][sum]!=-1)
		return DP[n][sum];
	if(sum<arr[n-1])
		return DP[n][sum]=SubsetSum(arr,n-1,sum);
	return  DP[n][sum]= (SubsetSum(arr,n-1,sum-arr[n-1]) | SubsetSum(arr,n-1,sum));
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	int Sum;
	cin>>Sum;
	memset(DP,-1,sizeof(DP));
	cout<<SubsetSum(arr,n,Sum)<<endl;
}