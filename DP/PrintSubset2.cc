// Unbounded Knapsack
#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
void PrintSubset(int arr[],int n, int sum,vector <int> ans)
{
	if(sum==0)
	{
		int s=ans.size();
		for(int i=0; i<s; ++i)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	if(n==0)
		return;
	if(arr[n-1]>sum)
		PrintSubset(arr,n-1,sum,ans);
	else
	{
		ans.push_back(arr[n-1]);
		PrintSubset(arr,n,sum-arr[n-1],ans);
		ans.pop_back();
		PrintSubset(arr,n-1,sum,ans);
	} 
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
	memset(DP,-1,sizeof(DP));
	vector <int> ans;
	PrintSubset(arr,n,sum,ans);
}