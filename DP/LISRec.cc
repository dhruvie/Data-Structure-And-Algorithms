#include<bits/stdc++.h>
using namespace std;
int LIS(int arr[], int n,int prev)
{
	if(n==0)
		return 0;
	else if(arr[n-1]<prev)
		return max(1+LIS(arr,n-1,arr[n-1]),LIS(arr,n-1,prev));
	else
		return LIS(arr,n-1,prev);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	cout<<LIS(arr,n,INT_MAX);
	return 0;
}