#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,flag=0,j;
	cout<<"Enter n:\n";
	cin>>n;
	int arr[n];
	cout<<"Enter Elements:\n";
	for(int i=0; i<n; i++)
			cin>>arr[i];
	for(int i=0; i<n; ++i)
	{
		int temp=arr[i];
		for(j=i-1; j>=0; j--)
		{
			if(arr[j]>temp)
				arr[j+1]=arr[j];
			else
				break;
		}
		arr[j+1]=temp;
	}
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	return 0;
}