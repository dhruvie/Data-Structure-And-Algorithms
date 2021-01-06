// Unbounded Knapsack
#include<bits/stdc++.h>
using namespace std;
int minC=INT_MAX;
vector <int> ans;
bool MinSubset(int arr[],int n, int sum,int count)
{
	if(sum==0)
	{
		int t=ans.size();
		for(int i=0; i<t; ++i)
			cout<<ans[i]<<" ";
		cout<<endl;
		if(count<minC)
			minC=count;
		return true;
	}
	else if(n==0)
		return false;
	else if(sum<arr[n-1])
		return MinSubset(arr,n-1,sum,count);
	ans.push_back(arr[n-1]);
	int x=MinSubset(arr,n,sum-arr[n-1],count+1);
	ans.pop_back();
	int y=MinSubset(arr,n-1,sum,count);
	return x|y;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	int sum;
	cin>>sum;
	minC=INT_MAX;
	if(MinSubset(arr,n,sum,0))
		cout<<minC;
	else
		cout<<-1;
	cout<<endl;
}