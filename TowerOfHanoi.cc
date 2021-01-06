#include<iostream>
using namespace std;
void Hanoi(char A,char B, char C, int n)
{
	if(n==0)
		return;
	Hanoi(A,C,B,n-1);
	cout<<A<<"->"<<B<<endl;
	// cout<<A<<"->"<<C<<endl;
	// Hanoi(A,C,B,n-1);
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter no. of Disks:";
	cin>>n;
	Hanoi('A','B','C',n);
	return 0;
}