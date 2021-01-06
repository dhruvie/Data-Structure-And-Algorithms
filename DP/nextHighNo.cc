#include<bits/stdc++.h>
using namespace std;
#define int long 
/*
Time_COmplexity:-NLogN
int nextHighNumber(int n)
{
	string str=to_string(n);
	int x=str.length();
	for(int i=x-1; i>0; --i)
	{
		if(str[i]<=str[i-1])
			continue;
		else
		{
			int min=INT_MAX,pos;
			for(int j=i; j<x; ++j)
			{
				int val=(str[j]-str[i-1]);
				if(val>0 && val<min)
				{
					val=min;
					pos=j;
				}
			}
			swap(str[pos],str[i-1]);
			sort(str.begin()+i,str.end());
			break;
		}
	}
	int ans=stol(str);
	if(ans>INT_MAX)
		return -1;
	return (ans==n)?-1:ans;
}
*/

// Time_Complexity:- O(N)
int nextHighNumber(int n)
{
	string str=to_string(n);
	int x=str.length();
	for(int i=x-1; i>0; --i)
	{
		if(str[i]<=str[i-1])
			continue;
		else
		{
			reverse(str.begin()+i, str.end());
			for(int j=i; j<x; ++j)
			{
				if(str[j]>str[i-1])
				{
					swap(str[j],str[i-1]);
					break;
				}
			}
			break;
		}
	}
	int ans=stol(str);
	if(ans>INT_MAX)
		return -1;
	return (ans==n)?-1:ans;
}
signed main()
{
	int n;
	cin>>n;
	cout<<nextHighNumber(n);
}