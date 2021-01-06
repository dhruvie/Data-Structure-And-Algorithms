#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
vector<vector<int>> ans;
vector<int> subset;
void Backtracking(vector<int>&arr, int i, int n)
{
	ans.push_back(subset);

	for(int start=i; start<n; ++start)
	{
		subset.push_back(arr[start]);
		cout<<"After Pushing--- i:"<<start<<endl;
		for(int j=0; j<subset.size(); ++j)
			cout<<subset[j]<<" ";
		cout<<endl;
		Backtracking(arr,start+1,n);
		subset.pop_back();
		cout<<"After Poping--- i:"<<start<<endl;
		for(int j=0; j<subset.size(); ++j)
			cout<<subset[j]<<" ";
		cout<<endl;
	}
}
signed main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	Backtracking(arr,0,n);
	cout<<"\n\n------------------------------------------\n\n\n";
	for(int i=0; i<ans.size(); ++i)
	{
		for(int j=0; j<ans[i].size(); ++j)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}