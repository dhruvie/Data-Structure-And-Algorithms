#include<bits/stdc++.h>
using namespace std;
void LPSTable(string pattern,int m, vector<int> &Table)
{
	int i=1,index=0;
	Table[0]=0;
	while(i<m)
	{
		if(pattern[i]==pattern[index])
		{
			index++;
			Table[i]=index;
			i++;
		}
		else if(index>0)
			index=Table[index-1];
		else
		{
			Table[i]=index;
			i++; 
		}
	}
}
bool KMP(string str, string pattern)
{
	int n=str.length(),m=pattern.length();
	vector<int> Table(m,0);
	LPSTable(pattern,m,Table);
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(str[i]==pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
				i++;
			else
				j=Table[j-1];
		}
		if(j==m)
			return true;
	}
	return false;
}
int main()
{
	string str,pattern;
	cout<<"Enter the String:\n";
	getline(cin,str);
	cout<<"Enter the Pattern:\n";
	getline(cin,pattern);
	if(KMP(str,pattern))
		cout<<"Pattern Found!\n";
	else
		cout<<"Pattern Not Found!\n";
}