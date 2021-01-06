// Min No of coins Required to make a value S.
//Unbounded Knapsack
// O(sum) Space Complexity 
#include<bits/stdc++.h>
using namespace std;
int SubsetSum(int arr[], int n, int sum)
{
	int DP[2][sum+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=sum; ++j)
		{
			if(i==0)
			{
				DP[i%2][j]=INT_MAX-1;
				continue;
			}
			if(j==0)
			{
				DP[i%2][j]=0;
				continue;
			}
			else if(j<arr[i-1])
				DP[i%2][j]=DP[(i-1)%2][j];
			else
				DP[i%2][j]= min(DP[(i)%2][j-arr[i-1]]+1,DP[(i-1)%2][j]);
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