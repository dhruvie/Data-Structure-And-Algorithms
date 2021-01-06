#include<bits/stdc++.h> 
using namespace std; 
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    int set=0,i=0,ans=0;
    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
            set++;
        else
            set=0;
        ans=max(set,ans);
        i++;
    }
    cout<<ans+1;
}

// int dp[100];
// int Knapsack(int arr[],int n)
// {
//     if(n<=0)
//         return 0;
//     if(dp[n]!=-1)
//         return dp[n];
//     return dp[n]=max(Knapsack(arr,n-2)+arr[n-1],Knapsack(arr,n-1));
// }

// int main() {
    
//     int n;
//     cin>>n;
//     int wt[n];
//     for(int i=0; i<n; ++i)
//         cin>>wt[i];
//     memset(dp,-1,sizeof(dp));
//     cout<<Knapsack(wt,n)<<endl;
// }