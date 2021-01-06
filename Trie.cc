#include<bits/stdc++.h>
using namespace std;
class Trie
{
	public:
		char ch;
		vector <Trie *> arr;
		bool we;
		Trie()
		{
			arr.resize(26,NULL);
			ch='$';
			we=0;
		}
		Trie(char A,bool X)
		{
			arr.resize(26,NULL);
			ch=A;
			we=X;
		}
};
void Insert(Trie *root,string str)
{
	int n=str.length();
	for(int i=0; i<n; ++i)
	{
		char ch=str[i];
		if(root->arr[ch-'a']==NULL)
		{
			Trie *p=new Trie(ch,0);
			root->arr[ch-'a']=p;
			root=root->arr[ch-'a'];
		}
		else
			root=root->arr[ch-'a'];
	}
	root->we=1;
}
bool Search(Trie *root, string str)
{
	int n=str.length();
	for(int i=0; i<n; ++i)
	{
		char ch=str[i];
		if(root->arr[ch-'a']==NULL)
			return false;
		else
			root=root->arr[ch-'a'];
	}
	return ((root->we)==1)?true:false;
}
bool Check(Trie * root)
{
	for(int j=0; j<26; ++j)
	{
		if((root->we)==1 || root->arr[j]!=NULL)
			return false;
	}
	return true;
}
Trie * Delete(Trie *root, string str,int i)
{
	if(root==NULL)	return NULL;
	if((str.length())==i)
	{
		root->we=0;
		if(Check(root))
			return NULL;
		return root;
	}
	char ch=str[i];
	if(root->arr[ch-'a']!=NULL)
	{
		Trie *p = Delete(root->arr[ch-'a'],str,i+1);
		if(p==NULL)
		{
			delete(root->arr[ch-'a']);
			root->arr[ch-'a']=NULL;
			if(Check(root))
				return NULL;
			return root;
		}
		else
			return root;
	}
	return NULL;
}
int main(int argc, char const *argv[])
{
	Trie *root=new Trie();
	int ch;
	string str;
	do{
		cout<<"Enter Your choice:	1.Insert	2.Search	3.Delete 	0.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cin>>str;
				Insert(root,str);
				break;
			case 2:
				cin>>str;
				if(Search(root,str))
					cout<<"Present!\n";
				else
					cout<<"Not Present!\n";
				break;
			case 3:
				cin>>str;
				cout<<root<<endl;
				Delete(root,str,0);
				cout<<root<<endl;
				break;
			case 0:
				break;
			default:
				cout<<"Wrong Choice:\n";
		}
	}while(ch!=0);
	return 0;
}