#include<bits/stdc++.h>
using namespace std;
string SCS(string s1, string s2, int n,int m)
{
	int DP[n+1][m+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=m; ++j)
		{
			if(i==0 || j==0)
				DP[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				DP[i][j]=1+DP[i-1][j-1];
			else
				DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
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
		else if(DP[n-1][m]>=DP[n][m-1])
		{
			ans=s1[n-1]+ans;
			n--;
		}
		else
		{
			ans=s2[m-1]+ans;
			m--;
		}
	}
	while(n!=0)
	{
		ans=ans+s1[n-1];
		n--;
	}
	while(m!=0)
	{
		ans=ans+s2[m-1];
		m--;
	}
	return ans;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();
	cout<<SCS(s1,s2,n,m);
}