#include<iostream>
using namespace std;
int Linear(int A[],int key,int i,int N)
{
	if(A[i]==key)
		return i;
	else if(i==N)
		return -1;
	return Linear(A,key,i+1,N);
}
int main(int argc, char const *argv[])
{
	int n,key,flag=0;
	cout<<"Enter n:";
	cin>>n;
	int arr[n];
	cout<<"\nEnter Array";
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<"Enter Key:";
	cin>>key;
	int pos=Linear(arr,key,0,n);
	if(pos==-1)
		cout<<"Not found!";
	else 
		cout<<"Pos is:"<<pos+1;
	/*
	for(int i=0; i<n; i++)
	{
		if(arr[i]==key)
		{
			cout<<"Pos is:"<<i+1;
			flag=1;
			break;
		}
	}
	if(!flag)
		cout<<"Not found!";
	*/
	return 0;
}