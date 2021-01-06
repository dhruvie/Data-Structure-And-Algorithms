#include<bits/stdc++.h>
using namespace std;
int Knapsack(int val[],int wt[], int n,int w)
{
	if(n==0 || w==0)
		return 0;
	if(w<wt[n-1])
		return Knapsack(val,wt,n-1,w);
	return max(val[n-1]+Knapsack(val,wt,n-1,w-wt[n-1]),Knapsack(val,wt,n-1,w));
}
int main()
{
	int n,w;
	cin>>n;
	int val[n],wt[n];
	for(int i=0; i<n; ++i)
		cin>>val[i];
	for(int i=0; i<n; ++i)
		cin>>wt[i];
	cin>>w;
	cout<<Knapsack(val,wt,n,w)<<endl;
}