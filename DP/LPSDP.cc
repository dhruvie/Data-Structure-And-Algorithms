#include<bits/stdc++.h>
using namespace std;
int LPS(string s1, string s2, int n,int m)
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
	return DP[n][m];
}
int main()
{
	string s1,s2;
	cin>>s1;
	s2=s1;
	reverse(s2.begin(),s2.end());
	int n=s1.length(),m=s2.length();
	cout<<LPS(s1,s2,n,m);
}