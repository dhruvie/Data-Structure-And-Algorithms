#include<bits/stdc++.h>
using namespace std;
int LIS(int arr[], int n)
{
	int DP[n],ans=0;
	for(int i=0; i<n; ++i)
	{
		DP[i]=1;
		for(int j=0; j<i; ++j)
		{
			if(arr[j]<arr[i])
				DP[i]=max(DP[j]+1,DP[i]);
		}
	}
	for(int i=0; i<n; ++i)
		ans=max(DP[i],ans);
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	cout<<LIS(arr,n);
	return 0;
}