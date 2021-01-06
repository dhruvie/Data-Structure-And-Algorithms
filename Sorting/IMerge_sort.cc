#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &arr, int low, int high, int mid)
{
	vector<int> temp;
	int i=low,j=mid+1   ;
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
			temp.push_back(arr[i++]);
		else
			temp.push_back(arr[j++]);
	}
	while(i<=mid)
		temp.push_back(arr[i++]);
	while(j<=high)
		temp.push_back(arr[j++]);
	int n=temp.size();
	for(int i=0; i<n; ++i)
	{
		cout<<temp[i]<<" ";
		arr[low++]=temp[i];
	}
	cout<<endl;
}
void Mergesort(vector<int> &arr, int n)
{
	int p;
	for(p=2; p<=n; p=p*2)
	{
		for(int i=0; i<n; i+=p)
		{
			int low=i,high=min(n-1,i+p-1),mid;
			mid=(low+high)/2;
			Merge(arr,low,high,mid);
		}
	}
	if((p/2)<n)
		Merge(arr,0,n-1,p/2-1);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	Mergesort(arr,n);
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl<<inv;
	return 0;
}