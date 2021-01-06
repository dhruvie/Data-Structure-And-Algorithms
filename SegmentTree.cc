#include<bits/stdc++.h>
using namespace std;
int constructSt(vector<int> &arr, vector<int> &st, int si, int l, int r)
{
	if(l==r)
	{
		st[si]=arr[l];
		return arr[l];
	}
	int mid=(l+r)/2;
	st[si]=constructSt(arr,st,2*si+1,l,mid)+constructSt(arr,st,2*si+2,mid+1,r);
	return st[si];
}
int getSum(int si, int sl, int sr,int l, int r,vector<int>&st)
{
	if(l<=sl && r>=sr)
		return st[si];

	if(sr<l || sl>r)
		return 0;

	int mid=(sl+sr)/2;
	return getSum(2*si+1,sl,mid,l,r,st)+getSum(2*si+2,mid+1,sr,l,r,st);
}
void Update(int si,int sl, int sr, int pos, int diff, vector<int>&st)
{
	if(pos<si || pos>sr)
		return ;

	st[si]=st[si]+diff;

	if(sl!=sr)
	{
		int mid=(sl+sr)/2;
		Update(2*si+1,sl,mid,pos,diff,st);
		Update(2*si+2,mid+1,sr,pos,diff,st);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];

	vector<int> st((2*n)-1,0);
	constructSt(arr,st,0,0,n-1);
	int q;
	cin>>q;
	while(q--)
	{
		int x,l,r;
		cin>>x;
		if(x==0)
		{
			cin>>l>>r;
			getSum(0,0,n-1,l,r,st);
		}
		else if(x==1)
		{
			int pos,value;
			cin>>pos>>value;
			int diff=value-arr[pos];
			Update(0,0,n-1,pos,diff,st);
		}
	}
} 