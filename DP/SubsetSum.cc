#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(int arr[], int n, int sum)
{
	if(sum==0)
		return true;
	if(n==0)
		return false;
	if(sum<arr[n-1])
		return SubsetSum(arr,n-1,sum);
	return (SubsetSum(arr,n-1,sum-arr[n-1]) | SubsetSum(arr,n-1,sum));
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
	cout<<SubsetSum(arr,n,Sum)<<endl;
}