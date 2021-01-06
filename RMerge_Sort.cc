//Inversion in an array using merge sort + Recursive Merge Sort
#include <bits/stdc++.h>
using namespace std;
#define int long long 
void Merge(int low, int high, int mid,vector<int> &arr,int &inv)
{
    vector<int> temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
            inv=inv+(mid-i+1);
            temp.push_back(arr[j++]);
        }
        else
            temp.push_back(arr[i++]);
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=high)
        temp.push_back(arr[j++]);
    int x=temp.size();
    for(int i=0; i<x; ++i)
        arr[low++]=temp[i];
}
void MergeSort(vector<int>&arr,int low, int high,int &inv)
{
    if(low<high)
    {
        int mid=low-(low-high)/2;
        MergeSort(arr,low,mid,inv);
        MergeSort(arr,mid+1,high,inv);
        Merge(low,high,mid,arr,inv);
    }
}
signed main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,inv=0;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0; i<n; ++i)
	        cin>>arr[i];
	    MergeSort(arr,0,n-1,inv);
        for(int i=0; i<n; ++i)
            cout<<arr[i]<<" ";
        cout<<endl;
	    cout<<inv<<endl;
	}
	return 0;
}

