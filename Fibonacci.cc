#include<iostream>
using namespace std;
void fibonacci(int a, int b,int n)
{
	if(n==0)
		return;
	cout<<a+b<<" ";
	fibonacci(b,a+b,n-1);
}
int main(int argc, char const *argv[])
{
	int a=0,b=1;
	cout<<a<<" "<<b<<" ";
	fibonacci(a,b,10);
	// for(int i=0; i<10; i++)
	// {
	// 	int temp=b;
	// 	b=a+b;
	// 	a=temp;
	// 	cout<<b<<" ";
	// }
	cout<<endl;
	return 0;
}