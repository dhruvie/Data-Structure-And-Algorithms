#include<bits/stdc++.h>
using namespace std;
string LCS(string s1, string s2, int n,int m)
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
	string ans="";
	while(n!=0 && m!=0)
	{
		if(s1[n-1]==s2[m-1])
		{
			ans=s1[n-1]+ans;
			n--;
			m--;
		}
		else if(Dp[n-1][m]>=Dp[n][m-1])
			n--;
		else
			m--;
	}
	return ans;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();
	cout<<LCS(s1,s2,n,m);
}