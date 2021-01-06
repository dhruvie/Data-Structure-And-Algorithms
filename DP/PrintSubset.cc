#include<bits/stdc++.h>
using namespace std;
void PrintSubset(int arr[], int n, int target, vector <int> ans)
{
	if(target==0)
	{
		int len=ans.size();
		for(int i=0; i<len; ++i)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	if(n==0)
		return;
	if(target<arr[n-1])
		PrintSubset(arr,n-1,target,ans);
	else
	{
		ans.push_back(arr[n-1]);
		PrintSubset(arr,n-1,target-arr[n-1],ans);
		ans.pop_back();
		PrintSubset(arr,n-1,target,ans);
	}
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
	vector <int> v;
	PrintSubset(arr,n,target,v);
}