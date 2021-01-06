#include<bits/stdc++.h>
using namespace std;
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
	if(i>=j || ispalindrome(s,i,j))
		return 0;
	int ans=INT_MAX;
	for(int k=i; k<=j-1; ++k)
	{
		int temp_ans=MCM(s,i,k)+MCM(s,k+1,j)+1;
		ans=min(ans,temp_ans);
	}
	return ans;
}
int main()
{
	string str;
	cin>>str;
	int n=str.length();
	cout<<MCM(str,0,n-1)<<endl;
}