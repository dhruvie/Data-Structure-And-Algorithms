
// // Problem :
// // Given an array of n elements. We need to answer q 
// // queries telling the sum of elements in range l to 
// // r in the array. Also the array is not static i.e 
// // the values are changed via some point update query.

// // Range Sum Queries are of form : Q l r , 
// // where l is the starting index r is the ending 
// // index

// // Point update Query is of form : U idx val, 
// // where idx is the index to update val is the 
// // updated value



#include<bits/stdc++.h>
using namespace std;
int FindSum(vector<int> &arr,vector<int> &BlockSum,int Block_Size, int l, int r)
{
	int sum=0;
	int start=l/Block_Size;
	int end=r/Block_Size;
	if(start==end)
	{
		for(int i=l; i<=r; ++i)
			sum+=arr[i];
		return sum;
	}
	for(int i=l; i<((start+1)*Block_Size); ++i)
		sum+=arr[i];
	for(int i=(end*Block_Size); i<=r; ++i)
		sum+=arr[i];
	for(int i=start+1; i<end; ++i)
		sum+=BlockSum[i];
	return sum;
}
void Update(vector<int> &arr,vector<int> &BlockSum,int Block_Size, int index, int new_value)
{
	int old_value=arr[index];
	BlockSum[index/Block_Size]+=(new_value-old_value);
	arr[index]=new_value;
}

int main()
{
	int n,q;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	int Block_Size=ceil(sqrt(n));
	vector<int> BlockSum(Block_Size);
	for(int i=0; i<n; ++i)
		BlockSum[i/Block_Size]+=arr[i];
	for(int i=0; i<Block_Size; ++i)
		cout<<BlockSum[i]<<" ";
	cin>>q;
	for(int i=0; i<q; ++i)
	{
		char ch;
		int x,y;
		cin>>ch>>x>>y;
		if(ch=='q' || ch=='Q')
			cout<<FindSum(arr,BlockSum,Block_Size,x,y)<<endl;
		else
			Update(arr,BlockSum,Block_Size,x,y);
	}
}