#include<bits/stdc++.h>
using namespace std;
void Heapify(vector<int> &Heap, int i, int k)
{
	int left=2*i+1,right=2*i+2,max=i;
	if(i<k)
	{
		if(left<k && Heap[max]<Heap[left])
			max=left;
		if(right<k && Heap[max]<Heap[right])
			max=right;
		if(max!=i)
		{
			swap(Heap[i],Heap[max]);
			Heapify(Heap,max,k);
		}
	}

}
int KthSmallestElement(vector<int> &arr, int n, int k)
{
	// vector<int> Heap(k);
	// for(int i=0; i<k; ++i)
	// 	Heap[i]=arr[i];
	for(int i=k/2; i>=0; --i)
		Heapify(arr,i,k);
	for(int i=k; i<n; ++i)
	{
		if(arr[0]>arr[i])
		{
			arr[0]=arr[i];
			Heapify(arr,0,k);
		}
	}
	return arr[0];
}
int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	cout<<KthSmallestElement(arr,n,k)<<endl;
	return 0;
}