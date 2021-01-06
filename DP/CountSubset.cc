#include<bits/stdc++.h>
using namespace std;
int CountSubset(int arr[], int n, int target)
{
	if(target==0)
		return 1;
	else if(n==0)
		return 0;
	if(arr[n-1]>target)
		return CountSubset(arr,n-1,target);
	return CountSubset(arr,n-1,target-arr[n-1]) + CountSubset(arr,n-1,target);
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