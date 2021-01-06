#include<bits/stdc++.h>
using namespace std;
void PanCakeSorting(vector<int>& A,int n) 
{
    for(int i=0; i<n; ++i)
    {
     	int pos=0;
        for(int j=0; j<n-i; ++j)
        {
            if(A[j]>A[pos])
               	pos=j;
        }
        if(pos==(n-i)) // if max element is already at its position.
            continue;
        reverse(A.begin(),A.begin()+pos+1);
        reverse(A.begin(),A.end()-i);
    }
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	PanCakeSorting(arr,n);
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}