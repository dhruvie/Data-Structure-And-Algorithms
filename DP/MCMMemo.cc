#include<bits/stdc++.h>
using namespace std;
int DP[1000][1000];
int MCM(vector<int> &arr, int i, int j)
{
	if(i>=j)
		return 0;
	if(DP[i][j]!=-1)
		return DP[i][j];
	int ans=INT_MAX;
	for(int k=i; k<=j-1; ++k)
	{
		int temp_ans=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		ans=min(temp_ans,ans);
	}
	return DP[i][j]=ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	memset(DP,-1,sizeof(DP));
	cout<<MCM(arr,1,n-1)<<endl;
}