#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a=12;
	void *ptr=(int*)&a;
	cout<<(*ptr);
}