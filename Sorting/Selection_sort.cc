#include<bits/stdc++.h>
using namespace std;
void Selectionsort(vector<int> &arr, int n)
{
	for(int i=0; i<n; ++i)
	{
		int pos=i,min=arr[i];
		for(int j=i+1; j<n; ++j)
		{
			if(arr[j]<min)
			{
				pos=j;
				min=arr[j];
			}
		}
		if(pos!=i)
			swap(arr[i],arr[pos]);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	Selectionsort(arr,n);
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	return 0;
}