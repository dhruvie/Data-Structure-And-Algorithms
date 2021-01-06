#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int> &arr,int low,int high)
{
	int pivot_index=low,pivot=arr[low];
	while(low<=high)
	{
		while(low<=high && pivot>=arr[low])
			low++;
		while(low<=high && pivot<arr[high])
			high--;
		if(low<=high)
			swap(arr[low],arr[high]);
	}
	swap(arr[pivot_index],arr[high]);
	return high;
}
void Quicksort(vector<int> &arr,int low,int high, int n)
{
	if(low<high)
	{
		int pi=Partition(arr,low,high);
		Quicksort(arr,low,pi,n);
		Quicksort(arr,pi+1,high,n);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	Quicksort(arr,0,n-1,n);
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	return 0;
}