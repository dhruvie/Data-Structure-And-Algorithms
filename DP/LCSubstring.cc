#include<bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, int n,int m)
{
	int DP[n+1][m+1],max=0;
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=m; ++j)
		{
			if(i==0 || j==0)
				DP[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				DP[i][j]=1+DP[i-1][j-1];
			else
				DP[i][j]=0;
			if(DP[i][j]>max)
				max=DP[i][j];
		}
	}
	return max;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();
	cout<<LCS(s1,s2,n,m);
}