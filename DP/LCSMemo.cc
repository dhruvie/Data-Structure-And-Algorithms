#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int LCS(string s1, string s2, int n,int m)
{
	if(n==0 || m==0)
		return DP[n][m]=0;
	if(DP[n][m]!=-1)
		return DP[n][m];
	else if(s1[n-1]==s2[m-1])
		return DP[n][m]=1+LCS(s1,s2,n-1,m-1);
	return DP[n][m]=max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();
	memset(DP,-1,sizeof(DP));
	cout<<LCS(s1,s2,n,m);
}