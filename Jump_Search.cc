#include<iostream>
#include <math.h>
using namespace std;
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
	int block=sqrt(n);
	int i=0,pos;
	while(i<n)
	{
		if(arr[i]==key)
		{
			pos=i;
			flag=1;
			break;
		}
		i=i+block;
		if(arr[i]>key || i>=n)
		{
			pos=i-block;
			break;
		}
	}
	if(!flag)
	{
		while(pos<n && pos<=pos+block)
		{
			if(arr[pos]==key)
			{
				flag=1;
				break;
			}
			pos++;
		}
	}
	if(flag==1)
		cout<<"Pos is:"<<pos;
	else
		cout<<"Not found!";
	return 0;
}