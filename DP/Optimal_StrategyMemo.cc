#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int MaxValue(vector<int> &arr, int i, int j)
{
	if(i==j)
		return arr[i];
	if((i+1)==j)
		return max(arr[i],arr[j]);
	if(DP[i][j]!=-1)
		return DP[i][j];
	int case1=arr[i]+min(MaxValue(arr,i+2,j),MaxValue(arr,i+1,j-1));
	int case2=arr[j]+min(MaxValue(arr,i+1,j-1),MaxValue(arr,i,j-2));
	return DP[i][j]=max(case1,case2);
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	memset(DP,-1,sizeof(DP));
	cout<<MaxValue(arr,0,n-1)<<endl;
}