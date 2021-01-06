#include<bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, int n,int m)
{
	int Dp[n+1][m+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=m; ++j)
		{
			if(i==0 || j==0)
				Dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				Dp[i][j]=1+Dp[i-1][j-1];
			else
				Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
		}
	}
	return Dp[n][m];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();
	cout<<LCS(s1,s2,n,m);
}