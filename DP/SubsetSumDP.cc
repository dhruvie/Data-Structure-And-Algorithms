#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(int arr[], int n, int sum)
{
	bool DP[n+1][sum+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			if(j==0)
			{
				DP[i][j]=true;
				continue;
			}
			else if(i==0)
			{
				DP[i][j]=false;
				continue;
			}
			else if(j<arr[i-1])
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]= DP[i-1][j-arr[i-1]] | DP[i-1][j];
		}
	}
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			cout<<"  "<<DP[i][j]<<"   ";
		}
		cout<<endl;
	}
	return DP[n][sum];
	
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