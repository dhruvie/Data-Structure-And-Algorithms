#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void Backtrack(string str, int i,int n)
{
	ans.push_back(str);
	for(int start=i; i<n-1; ++i)
	{
		swap(str[start],str[start+1]);
		Backtrack(str,i+1,n);
	}
}
int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int n=str.length();
	Backtrack(str,0,n);
	for(int i=0; i<ans.size(); ++i)
		cout<<ans[i]<<" ";
	return 0;
}