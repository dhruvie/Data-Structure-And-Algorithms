//Min Heap
#include<bits/stdc++.h>
using namespace std;
void Heapify(vector<int> &arr, int i,int n)
{
	int leftchild=2*i+1,rightchild=2*i+2,min=i;
	if(i<n)
	{
		if(leftchild<n && arr[leftchild]<arr[min])
			min=leftchild;
		if(rightchild<n && arr[rightchild]<arr[min])
			min=rightchild;
		if(min!=i)
		{
			swap(arr[i],arr[min]);
			Heapify(arr,min,n);
		}
	}
}
void Heap_Sort(vector<int> &arr, int n)
{
	for(int i=n/2; i>=0; --i)
		Heapify(arr,i,n);
	for(int i=n-1; i>=0; --i)
	{
		swap(arr[0],arr[i]);
		Heapify(arr,0,i);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	Heap_Sort(arr,n);
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	return 0;
}











