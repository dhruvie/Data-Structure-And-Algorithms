#include<bits/stdc++.h>
using namespace std;
int RodCutting(int arr[], int len[],int n,int RodL)
{
	if(n==0 || RodL==0)
		return 0;
	if(RodL<len[n-1])
		return RodCutting(arr,len,n-1,RodL);
	else
		return max(arr[n-1]+ RodCutting(arr,len, n, RodL-len[n-1]) , RodCutting(arr,len,n-1,RodL));
}
int main()
{
	int n;
	cin>>n;
	int arr[n],len[n];
	for(int i=0; i<n; ++i)
	{
		cin>>arr[i];
		len[i]=i+1;
	}
	int RodL;
	cin>>RodL;
	cout<<RodCutting(arr,len,n,RodL);
}


//Buttom Up approach
// int solve(vector<int>& prices, int n) {
        
//         int len[n];
//         for(int i=1; i<=n; ++i)
//             len[i-1]=i;
//         int DP[n+1][n+1];
//         for(int i=0; i<=n; ++i)
//         {
//             for(int j=0; j<=n; ++j)
//             {
//                 if(i==0 || j==0)
//                     DP[i][j]=0;
//                 else if(j<len[i-1])
//                     DP[i][j]=DP[i-1][j];
//                 else
//                     DP[i][j]=max(prices[i-1]+DP[i][j-len[i-1]], DP[i-1][j]);
//             }
//         }
//         return DP[n][n];
//     }