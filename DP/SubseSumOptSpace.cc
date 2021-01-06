// 0/1 Knapsack
// O(sum) Space Complexity
// All we need is to check is (i-1) value
#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(int arr[], int n, int sum)
{
	bool DP[2][sum+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			if(j==0)
			{
				DP[i%2][j]=true;
				continue;
			}
			else if(i==0)
			{
				DP[i%2][j]=false;
				continue;
			}
			else if(j<arr[i-1])
				DP[i%2][j]=DP[(i-1)%2][j];
			else
				DP[i%2][j]= DP[(i-1)%2][j-arr[i-1]] || DP[(i-1)%2][j];
		}
	}
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			cout<<"  "<<DP[i%2][j]<<"   ";
		}
		cout<<endl;
	}
	return DP[n%2][sum];
	
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