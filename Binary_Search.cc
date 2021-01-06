#include<iostream>
using namespace std;
int Binary(int arr[], int key, int lb, int ub)
{
	int mid=(lb+ub)/2;
	if(lb>ub)
		return -1;
	if(arr[mid]==key)
		return mid;
	else if(arr[mid]>key)
		ub=mid-1;
	else
		lb=mid+1;
	Binary(arr,key,lb,ub);
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
	int lb=0,ub=n-1;
	int pos=Binary(arr,key,0,n-1);
	if(pos==-1)
		cout<<"Not found!";
	else
		cout<<"Pos is:"<<pos+1;
	/*while(lb<=ub)
	{
		int mid=(lb+ub)/2;
		if(arr[mid]==key)
		{
			cout<<"Pos is:"<<mid+1;
			flag=1;
			break;
		}else if(arr[mid]>key)
		{
			ub=mid-1;
		}
		else
			lb=mid+1;
	}	
	if(!flag)
			cout<<"Not found!";
	*/
	return 0;
}