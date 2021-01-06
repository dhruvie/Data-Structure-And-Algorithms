#include<bits/stdc++.h>
using namespace std;
int DP[1000][1000];
bool ispalindrome(string s, int i, int j)
{
	while(i<=j)
	{
		if(s[i++]!=s[j--])
			return false;
	}
	return true;
}
int MCM(string s, int i, int j)
{
	if(DP[i][j]!=-1)	return DP[i][j];
	if(i>=j || ispalindrome(s,i,j))
		return 0;
	int ans=INT_MAX;
	for(int k=i; k<=j-1; ++k)
	{
		int temp_ans=MCM(s,i,k)+MCM(s,k+1,j)+1;
		ans=min(ans,temp_ans);
	}
	return DP[i][j]=ans;
}
int main()
{
	string str;
	cin>>str;
	int n=str.length();
	memset(DP,-1,sizeof(DP));
	cout<<MCM(str,0,n-1)<<endl;
}