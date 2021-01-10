#include<bits/stdc++.h>
using namespace std;
#define N 1000000
void seive(vector<int> &spf)
{
	for(int i=0; i<N; ++i)
		spf[i]=i;
	for(int i=2; i*i<N; i++)
	{
		if(spf[i]==i)
		{
			for(int j=i*i; j<N; j+=i)
			{
				if(spf[j]==j)
					spf[j]=i;
			}
		}
	}
}
int main()
{
	vector<int> spf(N);
	int t;
	cin>>t;
	vector<int> arr(t);
	for(int i=0; i<t; ++i)
		cin>>arr[i];
	seive(spf);
	for(int i=0; i<t; ++i)
	{
		int X=arr[i],p=spf[X];
		cout<<X<<":prime factors are:-->";
		while(X>1)
		{
			cout<<p<<" ";
			X/=p;
			p=spf[X];
		}
		cout<<endl;
	}
}