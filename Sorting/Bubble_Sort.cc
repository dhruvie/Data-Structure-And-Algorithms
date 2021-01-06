#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,flag=0;
	cout<<"Enter n:\n";
	cin>>n;
	int arr[n];
	cout<<"Enter Elements:\n";
	for(int i=0; i<n; i++)
			cin>>arr[i];
	for(int i=0; i<n; i++)
	{
		flag=0;
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag=1;
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(!flag)
			break;
	}
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}